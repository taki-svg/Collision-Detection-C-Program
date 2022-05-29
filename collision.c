#include<stdio.h>
#include<unistd.h>
#include<conio.h>

int vel_x,vel_y ;
void Collision_detection(int xx, int yy);


int main()
{
    int x,y,z,r,xx,yy,y_bar;
    char row1 [130][30];
    char a,b,c,inp;

    vel_x=1;
    vel_y=1;

    y_bar=15;

    xx=1; // starting position
    yy=1;

    while (1)
    {
       printf("\e[1;1H\e[2J");
       Collision_detection(xx,yy);

        xx = xx+vel_y;
        yy = yy+vel_x;
      
      // system("cls");
     for(x=0;x<30;x++)
     {
        for(y=0;y<100;y++)
        {
            a=' ';
            if(x==0 || x==29 || y==0 ||  y ==99) // top buttom left right
            a='*';

            b='O';
            c='|';

            row1[y][x]= a ; // board creator
            row1[yy][xx]=b; // ball creator

            row1[15][y_bar]=c;  // creation of player bar
            row1[15][y_bar+1]=c;
            row1[15][y_bar-1]=c;
            row1[15][y_bar+2]=c;
            row1[15][y_bar-2]=c;
        }    
     }
     for(x=0;x<30;x++)
     {
        for(y=0;y<100;y++)
        {  
           printf("%c",row1[y][x]);  
           if(y==99)
           printf("\n"); 
        }   
     }
     
     usleep(80000); // 30 frames per second.   
    }
}

void Collision_detection(int xx, int yy)
{
   int loc_y,loc_x;

   if(yy>=99)
   {
      vel_x=-2;
      
      
   }
   if(yy<=1)
   {
      vel_x=2;
      // left collision
   }
   if(xx>=29)
   {
     vel_y=-2; //bottom collision
   }
   if(xx<=1)
   {
      vel_y=2; // top collision
   }

}

