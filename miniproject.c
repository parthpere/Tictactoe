#include<stdio.h>
int displaygame(char a[3][3])
{
    printf("\n\tTIC TAC TOE GAME\n");
    printf("\t----------------\n");
    printf("\t  %c |  %c |  %c\n ",a[0][0],a[0][1],a[0][2]);
    printf("\t----------------\n");
    printf("\t  %c |  %c |  %c\n ",a[1][0],a[1][1],a[1][2]);
    printf("\t----------------\n");
    printf("\t  %c |  %c |  %c\n ",a[2][0],a[2][1],a[2][2]);
    return 0;
}
int playercommand(char a[3][3],char b,int c,int d)
{
    int i,j;
    for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(((i+1)==(c))&&((j+1)==d))
                {
                    if(a[i][j]==' ')
                        a[i][j]=b;
                    else
                    {
                        printf("\n\tINVALID INPUT");
                        return 1;
                    }
                }
            }
        }
    return 0;
}
int check(char a[3][3])
{
    int i=0,j=0;
        if((a[i][j]==a[i+1][j+1])&&(a[i+1][j+1]==a[i+2][j+2])&&(a[i][j]!=' '))
        {
           printf("\tCONGRATULATIONS,PLAYER %c WINS THE GAME",a[i][j]);
           return 1;
        }
        if((a[i][j+2]==a[i+1][j+1])&&(a[i+1][j+1]==a[i+2][j])&&(a[i][j]!=' '))
        {
            printf("\tCONGRATULATIONS,PLAYER %c WINS THE GAME",a[i][j+2]);
            return 1;
        }
    for(i=0;i<3;i++)
    {
        if(((a[i][j])==a[i][j+1])&&(a[i][j+1]==(a[i][j+2]))&&(a[i][j]!=' '))
        {
            printf("\tCONGRATULATIONS,PLAYER %c WINS THE GAME",a[i][j]);
            return 1;
        }
        if((a[j][i]==a[j+1][i])&&(a[j+1][i]==a[j+2][i])&&(a[j][i]!=' '))
        {
            printf("\tCONGRATULATIONS,PLAYER %c WINS THE GAME",a[j][i]);
            return 1;
        }
    }
    return 0;
}
int main()
{
    char a[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '},b,c;
    int i,j=2,k=1,m,n,o,p,result;
    printf("\tIT IS A TWO PLAYER GAME OF \n\tPLAYER 'X' AND PLAYER 'O'");
    displaygame(a);
    printf("\tENTER YOUR CHOICE PLAYER 1 'X' OR '0'\n");
    scanf("%c",&b);
    if(b=='X')
    c='O';
    else if(b=='O')
    c='X';
    else
    {
        printf("\n\tINVALID INPUT\n");
        printf("\n\t------GAME OVER-------");
        return 0;
    }


    printf("\n\tPLAYER 1 IS %c AND PLAYER 2 IS %c \n",b,c);
    for(i=1;i<10;i++)
    {
        if(i%2==0)
        {
            printf("\n\tENTER ROW AND COLUMN PLAYER %d ",j);
            scanf("%d %d",&m,&n);
            if(playercommand(a,c,m,n))
                break;
        }
        else
        {
            printf("\n\tENTER ROW AND COLUMN PLAYER %d ",k);
            scanf("%d %d",&m,&n);
            if(playercommand(a,b,m,n))
                break;
        }

        displaygame(a);
        if(i>4)
        {
        if(check(a))
        {
            break;
        }
        }
        if(i==9)
    {
        printf("\n\t    GAME DRAW ");
    }
    }

    printf("\n\t------GAME OVER-------");
    return 0;

}

