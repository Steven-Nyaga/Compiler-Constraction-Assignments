#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<iostream.h>
#include<stdlib.h>


int isoperator(char ch)
  {
    if(ch=='+')
        return 1;
    elseif(ch=='-')
        return 2;
    elseif(ch=='*')
        return 3;
    elseif(ch=='/')
        return 4;
    elseif(ch=='=')
        return 5;
    elsereturn 0;
  }

/*int issymbol(int symcounter,char symbol[][10],char currstr[])
  {
    for(int i=0;i<symcounter;i++)
      {
        if(strcmp(symbol[i],currstr)==0)
            return i;
      }
    return -1;
  }*/
void main()
{
    char instr[50];
    char currstr[50];
    char symbol[10][10];
    int scantab[6][5]={ 1, 2, 3,-1,-1,
               -1,-1,-1,-1,-1,
               -1, 2, 2, 2,-1,
               -1,-1, 3,-1, 4,
               -1,-1, 5,-1,-1,
               -1,-1, 5,-1,-1 };
    int counter=0,j;
    int currstate=0,symcounter=0;
    char currsym;
    int i=0;
    int count=0;
    clrscr();

    printf("ENTER THE STRING : ");
    scanf("%[^\n]",&instr);

    while(instr[counter]!='\0')
      {
        count=0;
        while(instr[counter++]==' ') {}

        counter--;

        while(instr[counter]!=' ' && instr[counter]!='\0')
            currstr[count++]=instr[counter++];
//        printf("%d",count);
        currstr[count]='\0';
//        printf("%s",currstr);
        currstate=0;
        int i=0;

        while(i<strlen(currstr))
          {

            if(isoperator(currstr[i])>0)
                j=0;
            elseif(isalpha(currstr[i]))
                j=1;
            elseif(isdigit(currstr[i]))
                j=2;
            elseif(currstr[i]=='_')
                j=3;
            elseif(currstr[i]=='.')
                j=4;

            else
              {
                printf("ERROR IN INPUT ! PLEASE TRY AGAIN WITH SUITABLE STRING :");
                getch();
                exit(0);
              }

            currstate=scantab[currstate][j];
            i++;
          }

        if(currstate==1)
            //printf(" <op,%d>",isoperator(currstr[--i]));
            printf(" <op> ");
        elseif(currstate==2)
          {
               /*    int temp;
            temp=issymbol(symcounter,symbol,currstr);
            if(temp>=0)
                printf(" <id#%d>",temp+1);
            else
              {
                strcpy(symbol[symcounter],currstr);
                symcounter++;
                printf(" <id#%d>",symcounter);
              }*/

              printf(" <id> ");
          }
        elseif(currstate==3)
            printf(" <int>");
        elseif(currstate==5)
            printf(" <real>");
        elseif(currstate==-1)
            printf(" error ..");
      }
    getch();
}
