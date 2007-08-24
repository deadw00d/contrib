/*

    This program is used to create classes makefile and Project.h

    Version, Revision and Date are read  from  the  "Project.c"  file.  The
    directory  name  is  used  as class name. This informations are used to
    define the values VER, REV, DATE and NAME of  the  makefile.  The  file
    "Feelin:Sources/_template/makefile",  which  define  actions, is append
    then.

$VER: 02.00 (2005/08/10)

    The program does now create an additionnal "Project.h"  file  which  is
    used to create a header file for <feelin/class_startup.c>

*/

#include <string.h>

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/utility.h>
 
#include <dos/dosextens.h>

#define BUF_SIZE                                1024
#define SOURCE                                  "Feelin:Sources/_template/makefile"

#define SKIP_WHITE(cur)                         while (*cur && *cur == ' ') cur++;

struct MyData
{
   UBYTE                            Project[BUF_SIZE];
   UBYTE                            Path[BUF_SIZE];
   UBYTE                            Make[BUF_SIZE];
};

int main(void)
{
    struct Library *UtilityBase = OpenLibrary("utility.library",36);
    
    if (UtilityBase)
    {
        struct Process *proc = (struct Process *) FindTask(NULL);
        struct MyData *data = AllocMem(sizeof (struct MyData),MEMF_CLEAR);
         
        if (data)
        {
            ULONG read;
            BPTR project;
            
            if (project = Open("Project.c",MODE_OLDFILE))
            {
                BOOL ok = FALSE;
    
                while (FGets(project,(STRPTR)(&data -> Project),BUF_SIZE))
                {
                    if (Strnicmp("$VER: ",data->Project,6) == 0)
                    {
                        ok = TRUE; break;
                    }
                }

                if (ok)
                {
                    BPTR make = Open(SOURCE,MODE_OLDFILE);
                  
                    NameFromLock(proc -> pr_CurrentDir,(STRPTR)(&data -> Path),BUF_SIZE);

                    if (make)
                    {
                        BPTR make_out = Open("makefile",MODE_NEWFILE);
                        BPTR head_out = Open("Project.h",MODE_NEWFILE);

                        if (make_out && head_out)
                        {
                            BPTR lock;
                            STRPTR cur = data->Project + 5;
                            STRPTR bgn;
                            LONG ver=0,rev=0,len;
                            
                            FPrintf(make_out,"#\n# This file was automatically generated by F_Make from \"Project.c\"\n#\n\n");
                            FPrintf(head_out,"/*\n**\n**  This file was automatically generated by F_Make from \"Project.c\"\n**\n*/\n\n");
 
                            SKIP_WHITE(cur)
                            
                            if (*cur >= '0' && *cur <= '9')
                            {
                                FPrintf(make_out,"NAME = %s\n",FilePart((STRPTR) &data->Path));
                                FPrintf(head_out,"#define F_CLASS_NAME                            \"%s\"\n",FilePart((STRPTR) &data->Path));
                                
                                Printf("F_Make: %s",FilePart((STRPTR) &data->Path));
                            }
                            else
                            {
                                bgn = cur;
                               
                                while (*cur && *cur != ' ') cur++;
                                   
                                *cur++ = 0;
                               
                                FPrintf(make_out,"NAME = %s\n",bgn);
                                FPrintf(head_out,"#define F_CLASS_NAME                            \"%s\"\n",bgn);
                                   
                                Printf("F_Make: %s",bgn);
                               
                                SKIP_WHITE(cur);
                            }
                            
                            len = stcd_l(cur,&ver); cur += len;
                            
                            FPrintf(make_out,"VER = %02ld\n",ver);
                            FPrintf(head_out,"#define F_CLASS_VERSION                         %ld\n",ver);
                            
                            Printf(" %02ld",ver);
                                    
                            if (*cur == '.')
                            {
                                cur++;
 
                                len = stcd_l(cur,&rev); cur += len;
                                    
                                FPrintf(make_out,"REV = %02ld\n",rev);
                                FPrintf(head_out,"#define F_CLASS_REVISION                        %ld\n",rev);
                                
                                Printf(".%02ld",rev);
                            }
                        
                            SKIP_WHITE(cur);

                            if (*cur == '(')
                            {
                                cur++;
                                
                                bgn = cur;
                                
                                while (*cur && *cur != ')') cur++;
                                    
                                if (*cur == ')')
                                {
                                    *cur = 0;
                                    
                                    FPrintf(make_out,"DATE = %s\n",bgn);
                                    FPrintf(head_out,"#define F_CLASS_VERSION_STRING                  \"%02ld.%02ld (%s)\"\n",ver,rev,bgn);
                                    
                                    Printf(" (%s)",bgn);
                                }
                            }
                            else
                            {
                                Printf("Unable to locate version date\n");
                            }
                        
                            FPrintf(make_out,"\n");
                            FPrintf(head_out,"\n#include <feelin/class_startup.c>\n");
                            
                            lock = Lock("Private.h",ACCESS_READ);
                            
                            if (lock)
                            {
                                FPrintf(head_out,"\n#include \"Private.h\"");
                                
                                UnLock(lock);
                            }
                            
                            Printf("\n");
                            
                            FPrintf(make_out,"#\n# The following lines were copied from \"%s\"\n#\n\n",SOURCE);
                            
                            Flush(make_out);
                            Flush(head_out);
    
                            if (read = Read(make,(STRPTR)(&data -> Make),BUF_SIZE))
                            {
                                Write(make_out,(STRPTR)(&data -> Make),read);
                            }
                        }
                        
                        if (make_out)
                        {
                            Close(make_out);
                        }
                        else
                        {
                            Printf("Unable to create \"makefile\"\n");
                        }

                        if (head_out)
                        {
                            Close(head_out);
                        }
                        else
                        {
                            Printf("Unable to create \"Projet.h\"\n");
                        }
                        
                        Close(make);
                    }
                    else
                    {
                        Printf("Unable to open %s\n",SOURCE);
                    }
                }
                else
                {
                    Printf("Unable to locale version information\n");
                }

                Close(project);
            }
            else
            {
                Printf("Unable to open %s\n","Project.c");
            }
            FreeMem(data,sizeof (struct MyData));
        }
        CloseLibrary(UtilityBase);
    }
 
    return 0;
}
