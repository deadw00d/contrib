/*
    (C) 1995-97 AROS - The Amiga Replacement OS
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

        24-Aug-1997     hkiel     Initial inclusion into the AROS tree

******************************************************************************/

static const char version[] = "$VER: Mine 0.1 (29.08.1997)\n";

#include "Mineincl.h"

#define maxbreite 30
#define maxhoehe 20
#define feldbreite 18
#define links 30
#define oben 50
#define rechts 40
#define unten 40

#define MARKE -2
#define GESCHLOSSEN -1

#define EIGENDEF 0
#define ANFAENGER 1
#define FORTGESCHRITTENE 2
#define PROFIS 3

#define random(min,max) ((rand() % (int)(((max)+1)-(min)))+(min))


/* ---------------------------------- Gadgets ------------------------------- */

SHORT SharedBordersPairs0[] = {
  -2,-1,-2,17,-1,17,-1,-1,195,-1 };
SHORT SharedBordersPairs1[] = {
  -1,17,195,17,195,0,196,-1,196,17 };

struct Border SharedBorders[] = {
  0,0,2,0,JAM1,5,(SHORT *)&SharedBordersPairs0[0],&SharedBorders[1],
  0,0,1,0,JAM1,5,(SHORT *)&SharedBordersPairs1[0],NULL,
  0,0,1,0,JAM1,5,(SHORT *)&SharedBordersPairs0[0],&SharedBorders[3],
  0,0,2,0,JAM1,5,(SHORT *)&SharedBordersPairs1[0],NULL };

UBYTE Name_Gad_buf[21];

struct StringInfo Name_Gad_info = {
  (UBYTE *)&Name_Gad_buf[0],NULL,0,21,0,0,0,0,0,0,NULL,NULL,NULL };

struct IntuiText Name_Gad_text = {
  1,0,JAM1,80,-10,NULL,(UBYTE *)"Name:",NULL };

#define Name_Gad_ID    0

struct Gadget Name_Gad = {
  NULL,5,30,195,17,
  GFLG_GADGHIMAGE,
  GACT_RELVERIFY+GACT_IMMEDIATE+GACT_STRINGCENTER,
  GTYP_STRGADGET,
  (APTR)&SharedBorders[0],(APTR)&SharedBorders[2],
  &Name_Gad_text,NULL,(APTR)&Name_Gad_info,Name_Gad_ID,NULL };



struct NewWindow NeuesWindow =
{
  10,10,350,200,
  -1,-1,
  IDCMP_CLOSEWINDOW|IDCMP_MOUSEBUTTONS|IDCMP_GADGETUP|IDCMP_RAWKEY,
  WFLG_CLOSEGADGET|WFLG_DRAGBAR|WFLG_DEPTHGADGET|WFLG_GIMMEZEROZERO,
  NULL,
  NULL,
  (UBYTE *)"MineSweeper by Henning Kiel",
  NULL,
  NULL,
  150,170,620,460,
  WBENCHSCREEN
};

SHORT Spielfeld[maxbreite+1][maxhoehe+1],Feldx,Feldy,breite,hoehe,Spielart;
BOOL Karte[maxbreite+2][maxhoehe+2],ende,Fehler,menuean,SpielAbbr,WEnde;
ULONG class,filehandle;
USHORT code;
int Rest,Anzahl,AnzMarken,maxx,maxy,mausx,mausy,Zeiten[4];
time_t tstart,tende;
char Namen[4][21];

#include "MineDatei.h"

globalInit()
{
SHORT i;
  oeffnelib();
  oeffnewindow(NeuesWindow);
  time( &tstart );
  srand(tstart);
  breite=22;
  hoehe=12;
  Anzahl=30;
  menuean=TRUE;
  Spielart=EIGENDEF;
  for(i=1;i<4;i++)
  {
    Zeiten[i]=999;
    strcpy(Namen[i],"Keiner");
  }
  oeffnedatei();
}

#include "MineSpiel.h"

BOOL Frage()
{
BOOL weiter=FALSE;
  MaleSpielfeld();
  schreibe(links+feldbreite*breite/2-19,25,"Start",2);

SetAPen(rp,0);
  RectFill(rp,links+feldbreite*breite/2-30,oben+feldbreite*hoehe/2-30,links+feldbreite*breite/2+30,oben+feldbreite*hoehe/2+30);
  maleFeld(links+feldbreite*breite/2-30,oben+feldbreite*hoehe/2-30,links+feldbreite*breite/2+30,oben+feldbreite*hoehe/2+30);
  maleFeld(links+feldbreite*breite/2-29,oben+feldbreite*hoehe/2-29,links+feldbreite*breite/2+29,oben+feldbreite*hoehe/2+29);
  maleFeld(links+feldbreite*breite/2-28,oben+feldbreite*hoehe/2-28,links+feldbreite*breite/2+28,oben+feldbreite*hoehe/2+28);
  schreibe(links+feldbreite*breite/2-20,oben+feldbreite*hoehe/2+5,"Menue",2);

  while(!weiter)
  {
    Wait(1L<<Window->UserPort->mp_SigBit);
    msg=(struct IntuiMessage *)GetMsg(Window->UserPort);
    class=msg->Class;
    code=msg->Code;
    mausx=msg->MouseX;/* -3; AROS*/
    mausy=msg->MouseY;/* -13; AROS*/
    ReplyMsg((struct Message *)msg);
    switch(class)
    {
      case IDCMP_RAWKEY :
      case IDCMP_CLOSEWINDOW  : return(TRUE);
                          weiter=TRUE;
                          break;
      case IDCMP_MOUSEBUTTONS : if(code==SELECTUP)
                          {
                            if((mausx>links+feldbreite*breite/2-25)&&(mausy>5)&&(mausx<links+feldbreite*breite/2+25)&&(mausy<35))
                            {
                              menuean=FALSE;
                              weiter=TRUE;
                              return(FALSE);
  			    }
                            if((mausx>links+feldbreite*breite/2-30)&&(mausy>oben+feldbreite*hoehe/2-30)&&(mausx<links+feldbreite*breite/2+30)&&(mausy<oben+feldbreite*hoehe/2+30))
                            {
                              menuean=TRUE;
                              weiter=TRUE;
                              return(FALSE);
                            }
                          }
                          break;
      default           : break;
    }
  }
}

BOOL endreq()
{
BOOL weiter=FALSE;
  WinSize(Window,200,100);
  LoescheWin();
 Delay(5);
  schreibe(20,13,"Wirklich beenden???",2);
  maleFeld(50,25,100,75);
  schreibe(60,55,"Ja.",1);
  maleFeld(110,25,160,75);
  schreibe(115,55,"Nein.",1);
  while(!weiter)
  {
    Wait(1L<<Window->UserPort->mp_SigBit);
    msg=(struct IntuiMessage *)GetMsg(Window->UserPort);
    class=msg->Class;
    code=msg->Code;
    mausx=msg->MouseX;/* -3; */
    mausy=msg->MouseY;/* -13; */
    ReplyMsg((struct Message *)msg);
    switch(class)
    {
      case IDCMP_MOUSEBUTTONS : if(code==SELECTUP)
                          {
                            if((mausx>50)&&(mausy>25)&&(mausx<100)&&(mausy<75))
                            {
                              weiter=TRUE;
                              return(TRUE);
  			    }
                            if((mausx>110)&&(mausy>25)&&(mausx<160)&&(mausy<75))
                            {
                              weiter=TRUE;
                              return(FALSE);
                            }
                          }
                          break;
      default           : break;
    }
  }
}


CleanUp()
{
  schliessedatei();
  schliessewindow();
  schliesselib();
}

/* ---------------------------    HauptProgramm    -------------------------- */

wbmain()
{
 main();
}

main()
{
  WEnde=FALSE;
  globalInit();
  while(!WEnde)
  {
    ende=FALSE;
    while(!ende)
    {
      GameInit();
      Spiel();
      if(!ende)
      {
        Auswertung();
        ende=Frage();
      }
    }
    WEnde=endreq();
  }
  CleanUp();
}
