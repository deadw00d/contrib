/*
    (C) 1995-98 AROS - The Amiga Research OS
    $Id$

    Desc: Mine Game
    Lang: german
*/

/*****************************************************************************

    NAME

	Mine

    SYNOPSIS

    LOCATION

	Workbench:Games

    BUGS

    SEE ALSO

	Jump JumpEd Quad Wumpus

    INTERNALS

    HISTORY

	24-Aug-1997	hkiel	  Initial inclusion into the AROS tree
	16-Sep-1997	hkiel	  Fixed all casts
	03-Oct-1998	hkiel	  Added Counter task and fixed random()
	04-Jun-1999	hkiel	  Wait() for IDCMP_CHANGEWINDOW after WinSize()

******************************************************************************/

static const char version[] = "$VER: Mine 0.4 (04.06.1999)\n";

#include "MineIncl.h"

#define maxwidth 30
#define maxheight 20
#define box_width 18
#define left 30
#define oben 50
#define right 40
#define unten 40

#define MARKE -2
#define GESCHLOSSEN -1

#define EIGENDEF 0
#define ANFAENGER 1
#define FORTGESCHRITTENE 2
#define PROFIS 3

#define random(min,max) (((int)((float)(((float)(rand()))/((float)(RAND_MAX))*(max-min+1))))+min)


/* ---------------------------------- Gadgets ------------------------------- */

WORD SharedBordersPairs0[] = {
  -2,-1,-2,17,-1,17,-1,-1,195,-1 };
WORD SharedBordersPairs1[] = {
  -1,17,195,17,195,0,196,-1,196,17 };

struct Border SharedBorders[] = {
  {0,0,2,0,JAM1,5,&SharedBordersPairs0[0],&SharedBorders[1]},
  {0,0,1,0,JAM1,5,&SharedBordersPairs1[0],NULL},
  {0,0,1,0,JAM1,5,&SharedBordersPairs0[0],&SharedBorders[3]},
  {0,0,2,0,JAM1,5,&SharedBordersPairs1[0],NULL} };

UBYTE Name_Gad_buf[21];

struct StringInfo Name_Gad_info = {
  (UBYTE *)&Name_Gad_buf[0],NULL,0,21,0,0,0,0,0,0,NULL,0L,NULL };

struct IntuiText Name_Gad_text = {
  1,0,JAM1,80,-10,NULL,(UBYTE *)"Name:",NULL };

#define Name_Gad_ID	0

struct Gadget Name_Gad = {
  NULL,5,30,195,17,
  GFLG_GADGHIMAGE,
  GACT_RELVERIFY+GACT_IMMEDIATE+GACT_STRINGCENTER,
  GTYP_STRGADGET,
  (APTR)&SharedBorders[0],(APTR)&SharedBorders[2],
  &Name_Gad_text,0L,(APTR)&Name_Gad_info,Name_Gad_ID,NULL };

struct NewWindow NeuesWindow =
{
  10,10,350,200,
  -1,-1,
  IDCMP_CLOSEWINDOW|IDCMP_MOUSEBUTTONS|IDCMP_GADGETUP|IDCMP_RAWKEY|IDCMP_CHANGEWINDOW,
  WFLG_CLOSEGADGET|WFLG_DRAGBAR|WFLG_DEPTHGADGET|WFLG_ACTIVATE|WFLG_GIMMEZEROZERO,
  NULL,
  NULL,
  (UBYTE *)"MineSweeper by Henning Kiel",
  NULL,
  NULL,
  150,170,620,460,
  WBENCHSCREEN
};

BYTE Spielfeld[maxwidth+1][maxheight+1],Feldx,Feldy,width,height,Spielart;
BOOL Karte[maxwidth+2][maxheight+2],ende,Fehler,menuean,SpielAbbr,WEnde;
ULONG class;
UWORD code;
int Rest,Anzahl,AnzMarken,maxx,maxy,mausx,mausy,Zeiten[4];
time_t tstart,tend;
char names[4][21];

#include "MineFile.h"

/* Timer-Task */
#define NEWLIST(l)                          \
((l)->lh_Head=(struct Node *)&(l)->lh_Tail, \
 (l)->lh_Tail=NULL,                         \
 (l)->lh_TailPred=(struct Node *)(l))

struct Task *t=NULL;
UBYTE *s=NULL;

/* shared */
int finish = FALSE, killme = FALSE;
int sigbit1, sigbit2;
struct Task *parent;

#define STACKSIZE 4096

static void entry(void)
{
char outtext[4];

  sigbit2=AllocSignal(-1);
  Signal(parent,1<<sigbit1); /* Tell creator that we are ready */
  if( sigbit2!=0 )
  {
    for(;;)
    {
      Wait(1<<sigbit2); /* Wait for being restarted or killed */
      if( killme == TRUE )
      {
        FreeSignal(sigbit2);
        Signal(parent,1<<sigbit1); /* We have freed our resources */
        Wait(0);
      }
      finish = FALSE;
      Signal(parent,1<<sigbit1); /* We are ready for counting */
      while(!finish)
      {
        time(&tend);
        sprintf(outtext,"%3d",Anzahl-AnzMarken);
        write_text(left+box_width*width/2-55,25,outtext,1);
        sprintf(outtext,"%3d",(int)(tend-tstart));
        write_text(left+box_width*width/2+35,25,outtext,1);
        Delay(40);
      }
      Signal(parent,1<<sigbit1); /* We stopped counting */
    }
  }
}


void globalInit()
{
BYTE i;
  open_lib();
  open_window(&NeuesWindow);

  time( &tstart );
  srand(tstart);
  width=22;
  height=12;
  Anzahl=30;
  menuean=TRUE;
  Spielart=EIGENDEF;
  for(i=1;i<4;i++)
  {
    Zeiten[i]=999;
    strcpy(names[i],"Keiner");
  }
  open_hsfile();
  killme = FALSE;
  parent=SysBase->ThisTask;
  sigbit1=AllocSignal(-1);
  if(sigbit1!=0)
  {
    t=(struct Task *)AllocMem(sizeof(struct Task), MEMF_PUBLIC|MEMF_CLEAR);
    if(t!=NULL)
    {
      s=(UBYTE *)AllocMem(STACKSIZE, MEMF_PUBLIC|MEMF_CLEAR);
      if(s!=NULL)
      {
        t->tc_Node.ln_Type=NT_TASK;
        t->tc_Node.ln_Pri=1;
        t->tc_Node.ln_Name="counter";
        t->tc_SPLower=s;
        t->tc_SPUpper=s+STACKSIZE;
#if AROS_STACK_GROWS_DOWNWARDS
        t->tc_SPReg=(UBYTE *)t->tc_SPUpper-SP_OFFSET;
#else
        t->tc_SPReg=(UBYTE *)t->tc_SPLower-SP_OFFSET;
#endif
        NEWLIST(&t->tc_MemEntry);
        AddTask(t,&entry,NULL);
        Wait(1<<sigbit1); /* Wait for child to init */
      }
    }
  }
}

#include "MineGame.h"

BOOL Frage()
{
BOOL weiter=FALSE,ret=FALSE;

  MaleSpielfeld();
  write_text(left+box_width*width/2-19,25,"Start",2);

  EraseRect(rp,left+box_width*width/2-30,oben+box_width*height/2-30,left+box_width*width/2+30,oben+box_width*height/2+30);
  drawfield(left+box_width*width/2-30,oben+box_width*height/2-30,left+box_width*width/2+30,oben+box_width*height/2+30);
  drawfield(left+box_width*width/2-29,oben+box_width*height/2-29,left+box_width*width/2+29,oben+box_width*height/2+29);
  drawfield(left+box_width*width/2-28,oben+box_width*height/2-28,left+box_width*width/2+28,oben+box_width*height/2+28);
  write_text(left+box_width*width/2-20,oben+box_width*height/2+5,"Menue",2);

  while(!weiter)
  {
    WaitPort(Window->UserPort);
    msg=(struct IntuiMessage *)GetMsg(Window->UserPort);
    class=msg->Class;
    code=msg->Code;
    mausx=msg->MouseX-Window->BorderLeft;
    mausy=msg->MouseY-Window->BorderTop;
    ReplyMsg((struct Message *)msg);
    switch(class)
    {
      case IDCMP_RAWKEY :
      case IDCMP_CLOSEWINDOW  : ret=TRUE;
                    		weiter=TRUE;
                    		break;
      case IDCMP_MOUSEBUTTONS : if(code==SELECTUP)
                          {
                            if((mausx>left+box_width*width/2-25)&&(mausy>5)&&(mausx<left+box_width*width/2+25)&&(mausy<35))
                            {
                              menuean=FALSE;
                              weiter=TRUE;
  			    }
                            if((mausx>left+box_width*width/2-30)&&(mausy>oben+box_width*height/2-30)&&(mausx<left+box_width*width/2+30)&&(mausy<oben+box_width*height/2+30))
                            {
                              menuean=TRUE;
                              weiter=TRUE;
                            }
                          }
                          break;
      default           : break;
    }
  }
  return(ret);
}

BOOL endreq()
{
BOOL weiter=FALSE,ret=FALSE;
  if(WinSize(Window,200,100)==FALSE)
    fprintf(stderr,"Could not resize Window!\n");
  clearwin();

  write_text(20,13,"Wirklich beenden???",2);
  drawfield(50,25,100,75);
  write_text(60,55,"Ja.",1);
  drawfield(110,25,160,75);
  write_text(115,55,"Nein.",1);
  while(!weiter)
  {
    WaitPort(Window->UserPort);
    msg=(struct IntuiMessage *)GetMsg(Window->UserPort);
    class=msg->Class;
    code=msg->Code;
    mausx=msg->MouseX-Window->BorderLeft;
    mausy=msg->MouseY-Window->BorderTop;
    ReplyMsg((struct Message *)msg);
    switch(class)
    {
      case IDCMP_MOUSEBUTTONS : if(code==SELECTUP)
                          {
                            if((mausx>50)&&(mausy>25)&&(mausx<100)&&(mausy<75))
                            {
                              weiter=TRUE;
                              ret=TRUE;
  			    }
                            if((mausx>110)&&(mausy>25)&&(mausx<160)&&(mausy<75))
                              weiter=TRUE;
                          }
                          break;
      default           : break;
    }
  }
  return(ret);
}


void CleanUp()
{
  /* stop timer task */
  if(sigbit1!=0)
  {
    if(t!=NULL)
    {
      if(s!=NULL)
      {
        killme = TRUE; /* tell child to go to sleep */
        Signal(t,1<<sigbit2); /* Tell child to react */
        Wait(1<<sigbit1); /* He's gone asleep, but wait a moment */
        Delay(5);
        RemTask(t);
        FreeMem(s,STACKSIZE);
      }
      FreeMem(t,sizeof(struct Task));
    }
    FreeSignal(sigbit1);
  }

  close_hsfile();
  close_window();
  close_lib();
}

/* ---------------------------	  main programm    -------------------------- */

int main()
{
  WEnde=FALSE;
  globalInit();
  while(!WEnde)
  {
    ende=FALSE;
    while(!ende)
    {
      GameInit();
      if(!ende)
      {
        Spiel();
      }
      if(!ende)
      {
	Auswertung();
	ende=Frage();
      }
    }
    WEnde=endreq();
  }
  CleanUp();
  return(0);
}

