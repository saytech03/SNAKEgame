#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int width=20,height=20;
int x,y,fruitX,fruitY,score,gameover,flag,m,n;
// Function to generate the fruit within the boundary
void setup()
{
gameover=0;
x=width/2;
y=height/2;
label1:
fruitX=rand()%20;
if(fruitX==0)
goto label1;

label2:
fruitY=rand()%20;
if(fruitY==0)
goto label2;
score=0;
}
//function to generate the boundary
void draw()
{
int i,j;
system ("cls");
printf("\t**Welcome to the mini Snake game**\n\n");
printf("Game instructions:\n");
printf("\n Press the key \n'w' to move the snake upward \n's' to move the snake downward \n'a' to move the snake leftward \n'd' to move the snake rightward.\n");
printf("\n");
for(i=0;i<width;i++)
{
for(j=0;j<height;j++)
{
if(i==0||i==height-1||j==0||j==width-1)

{
printf("#");
}
else
{
if(i==x && j==y)
printf("O");
else if(i==fruitX && j==fruitY)
printf("*");
else
printf(" ");
}
}
printf("\n");
}
// Print the score after the game end
printf("score = %d", score);
printf("\n");
printf("press X to quit the game\n");
}
//function to take input from the user

void input()
{
if(kbhit())
{
switch(getch())
{
case 'a':
flag=1;
break;
case 'd':
flag=2;
break;
case 'w':
flag=3;
break;
case 's':
flag=4;
break;
case 'x':
gameover=1;
break;
}
}

}
//function for movement of snake
void logic()
{
switch(flag)
{
case 1:
y--;
break;
case 2:
y++;
break;
case 3:
x--;
break;
case 4:
x++;
break;
default:
break;
}
// if the game over

if(x<0||x>width||y<0||y>height)
gameover=1;
// If snake reaches the fruit then update the score after eating the fruit
//generate the new fruit
if(x==fruitX && y==fruitY)
{
label3:
fruitX=rand()%20;
if(fruitX==0)
goto label3;
label4:
fruitY=rand()%20;
if(fruitY==0)
goto label4;
score+=10;
}
}
int main()
{

 setup();
 while(1)
{
draw();
input();
logic();
if(gameover==1)
break;
//to decerase the speed of snake
for(m=0;m<10000;m++)
{
for(n=0;n<100000;n++)
{
}
}
}
printf("GAME OVER");
return 0;
}
