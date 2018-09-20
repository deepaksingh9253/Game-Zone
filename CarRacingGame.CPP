#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13



/******* first car detailed disciption*********/
//global variable
int num=0;
int life=5;
int axi=0;
int pos=300,top=400,init=1;

void score() //socre(num) & life prinnting part
{
num=num+5;
setcolor(RED);
setfillstyle(SOLID_FILL,BLUE);
bar(510,1,635,30);
bar(510,40,635,70);
gotoxy(75,1);
printf("%d",num);
gotoxy(65,1);
printf("SCORE-:");
gotoxy(75,4);
printf("%d",life);
gotoxy(65,4);
printf("LIFE-:");


}
void out_area()
{
setfillstyle(SOLID_FILL,GREEN);
bar(1,1,200,500);
bar(450,1,650,500);
setfillstyle(SOLID_FILL,BLUE); //loss box
bar(480,210,620,260);
}

void loss()
{
for(int j=1;j<=280;j++)
{
cleardevice();     //300-Y
settextstyle(4,HORIZ_DIR,8);
setcolor(j);
outtextxy(110,j,"GAME OVER");
delay(30);
}
getch();
getch();
exit(0);
}


void road()
{
setfillstyle(SOLID_FILL,8);
bar(250,1,400,500);

for(int i=init;i<60;i=i+5)
{
setfillstyle(2,i);
bar(210,i*8,240,(i+2)*8);
bar(410,i*8,440,(i+2)*8);
setfillstyle(1,WHITE);
bar(320,i*8,330,(i+2)*8);
}


if(init>5)
{
init=1;
}
init++;

return;
}

	void my_car()
	{
	 setcolor(WHITE);
	setfillstyle(SOLID_FILL,RED);
	sector(pos+25,top,0,180,25,25);
	setfillstyle(SOLID_FILL,YELLOW);
	bar3d(pos,top,pos+50,top+50,0,0);
	sector(pos+25,top+50,180,360,25,10);
	return;
	}

void enemy_car1(int x1,int y1)
{
 setcolor(WHITE);

if(y1<500)
{
setfillstyle(SOLID_FILL,LIGHTBLUE);
sector(x1+25,y1,0,180,25,10);
setfillstyle(SOLID_FILL,BLUE);
bar(x1,y1,x1+50,y1+50);
setfillstyle(SOLID_FILL,LIGHTBLUE);
sector(x1+25,y1+50,180,360,25,25);

}

else
y1=1;

return;
}
	void enemy_car2(int x2,int y2)
	{
	 setcolor(WHITE);
	if(y2<500)
	{
	setfillstyle(SOLID_FILL,LIGHTRED);
	sector(x2+25,y2,0,180,25,10);
	setfillstyle(SOLID_FILL,RED);
	bar(x2,y2,x2+50,y2+50);
	setfillstyle(SOLID_FILL,LIGHTRED);
	sector(x2+25,y2+50,180,360,25,25);
	}
       else
       y2=1;
       return;
	}

void next()
{
int m;

for(m=0;m<=650;m++)
{
cleardevice();
setcolor(GREEN);
settextstyle(10,HORIZ_DIR,3);
outtextxy(100,100,"\"CONGRATULATION\"");
setcolor(LIGHTBLUE);
settextstyle(1,HORIZ_DIR,3);
outtextxy(m,300,"YOU HAVE COMPLETE FIRST LEVEL");
setfillstyle(SOLID_FILL,GREEN);
bar3d(m+200,220,m+250,270,4,6);
setfillstyle(SOLID_FILL,RED);
bar3d(m+250,240,m+280,270,4,6);
setcolor(WHITE);
circle(m+210,280,8);
circle(m+250,280,8);
delay(20);
 }
num=0;
return;
//return;
//carexe(); //calling to another car programs

}

void play()
{
setbkcolor(BLACK);
int x1=250,x2=300,move;
int y1=1,y2=1 ;
int i=10;


flag:
while(1)
{

if(y1>500)
{
y1=1;
x1=250+((rand()%3)*50);
}
y1=y1+10;

if(y2>500)
{
y2=1;
x2=250+((rand()%3)*50);
}
y2=y2+10;
out_area();
road();
enemy_car1(x1,y1);
enemy_car2(x2,y2);
setfillstyle(2,WHITE);
my_car();   //my car
score();
if(kbhit())
{
move=getch();
	switch(move)
	{

	case LEFT:
	{
	if(pos>250)
	 pos=pos-50;

	if((x1==pos)||(x2==pos))

	if((((top-y1)<50)&&((top-y1)>0))||(((top-y2)<50)&&((top-y2)>0)))
	 {

	 life--;

	settextstyle(7,HORIZ_DIR,6);
	setcolor(WHITE);
	outtextxy(480,200,"LOSS");

	getch();
	cleardevice();
	}


	 break;
	}

	case RIGHT:
	{
	if(pos<350)
	pos=pos+50;

	if((x1==pos)||(x2==pos))
	if((((top-y1)<50)&&((top-y1)>0))||(((top-y2)<50)&&((top-y2)>0)))
	{
       life--;

	settextstyle(7,HORIZ_DIR,6);
	setcolor(WHITE);
	outtextxy(480,200,"LOSS");


	getch();
	cleardevice();
	}


	break;
	}

	case UP:
	{
	if(top>1)
	 top=top-10;
	 break;
	 }

	case DOWN:
	{
	if(top<430)
	top=top+10;
	break;
	}

	case ESC:
	exit(0);
	delay(500);

}//switch close



}//if close

else

delay(100);
//cleardevice();

if((x1==pos)||(x2==pos))

	if((((top-y1)<50)&&((top-y1)>0))||(((top-y2)<50)&&((top-y2)>0)))
	{

	life--;
	//setbkcolor(BLACK);

	settextstyle(7,HORIZ_DIR,6);
	setcolor(WHITE);
	outtextxy(480,200,"LOSS");

	getch();
	cleardevice();
	}

if(life<=0)
loss();
else if(life>0&&num>=2000)
next();
setbkcolor(BLACK);

}//while close


goto flag;
//return(0);
exit(0);
}//close play();



void startup()  //starting interface of game
{
setbkcolor(BLUE);
rectangle(1,1,635,470);

setcolor(YELLOW);
settextstyle(4,HORIZ_DIR,6);
outtextxy(90,50,"CAR RACING");
setfillstyle(SOLID_FILL,YELLOW);
bar3d(50,120,550,140,6,8);
gotoxy(15,9);
printf("omkarananda institute of management& technology");
settextstyle(3,HORIZ_DIR,3);
outtextxy(10,400,"LOADING..");

setfillstyle(SOLID_FILL,YELLOW);
setcolor(GREEN);
//circle(100,200,10);
pieslice(300,300,0,360,40);

setfillstyle(SOLID_FILL,BLACK);
pieslice(280,290,0,360,10);
pieslice(320,290,0,360,10);

setcolor(GREEN);
bar(277,320,325,322);

setfillstyle(SOLID_FILL,GREEN);
pieslice(280,290,0,360,5);
pieslice(320,290,0,360,5);


for(int i=115;i<=550;i++)
{
setcolor(WHITE);
rectangle(115,410,550,430);

setfillstyle(SOLID_FILL,RED);
bar(i,410,i,430);
delay(30);
}
setfillstyle(SOLID_FILL,RED);
pieslice(300,320,180,360,15);
delay(1500);
return;
}


void about()
{
	cleardevice();
	setcolor(YELLOW);
	settextstyle(1,HORIZ_DIR,6);
	outtextxy(230,30,"ABOUT");
	setcolor(RED);
	setfillstyle(SOLID_FILL,CYAN);
	bar3d(140,100,460,108,6,8);

	settextstyle(2,HORIZ_DIR,6);
	setcolor(LIGHTBLUE);
	outtextxy(1,150,"i have completed our work as a part of computer science student.");
	outtextxy(1,170,"i have tried to reduce the maximum problem in our game program.");
	outtextxy(1,190,"eventhough it can occure several TECHNICAL & LOGICAL problem.");
	//NAMENING DISCRIPTION
	  settextstyle(2,HORIZ_DIR,6);
	  setcolor(RED);
	 outtextxy(150,250,"GAME DEVELOPER- DEEPAK SINGH");
	 settextstyle(2,HORIZ_DIR,6);
	  setcolor(YELLOW);
	 outtextxy(150,270,"COLLEGE- OIMT(omkarananda institute");
	 settextstyle(2,HORIZ_DIR,6);
	  setcolor(YELLOW);
	 outtextxy(150,290,"         of management and technology).");
	  settextstyle(2,HORIZ_DIR,6);
	  setcolor(BROWN);
	 outtextxy(150,310,"CLASS-  BCA 3SEM");
	  settextstyle(2,HORIZ_DIR,6);
	  setcolor(WHITE);
	 outtextxy(150,330,"YEAR -  2017-2018");
	 delay(50);
	getch();
	return;
	}


void help()
{
	cleardevice();
	setcolor(LIGHTRED);
	settextstyle(1,HORIZ_DIR,6);
	outtextxy(230,30,"HELP");
	setfillstyle(SOLID_FILL,GREEN);
	bar3d(140,100,460,108,6,8);  //iske age kar bhai
	gotoxy(15,9);
	cout<<"\n\t\tthe deangereous road racing is very simple game\n\t\tyou need only understand the movement keys\n\t\tthen you can easly play it\n\t\tkeys are given below the statement\n\n\n\n\t\tLEFT arrow ->     for left movement of car\n\t\tRIGHT arrow ->    for right movement of car \n\t\tUP arrow ->       forword car";
	getch();
	return;
}


	void disp_score()
	{
	cleardevice();
	setcolor(GREEN);
	settextstyle(4,HORIZ_DIR,2);
	outtextxy(100,100,"your score=in prograsion");
	getch();
	return;
	}



void menu()
{

setbkcolor(BLACK);
int p=150,a,s=1,t=0;
do
{
cleardevice();
do
{
cleardevice();
setcolor(YELLOW);
settextstyle(10,HORIZ_DIR,4);
outtextxy(250,50,"MENU");
setfillstyle(SOLID_FILL,GREEN);
//bar(150,120,480,128);
bar3d(150,120,480,128,6,8);
setcolor(GREEN);
settextstyle(1,HORIZ_DIR,2);
outtextxy(250,150,"PLAY GAME");
outtextxy(250,180,"SCORES");
outtextxy(250,210,"HELP");
outtextxy(250,240,"ABOUT");
outtextxy(250,270,"EXIT");
setcolor(RED);
rectangle(210,p,400,p+30);
//rectangle(210,270,400,295);
a=getch();
	switch(a)
	{
	case UP: //72 ascii value
	{
	if(p>150 )
	p=p-30;
	s--;
	}
	break;

	case DOWN: //80 ascii value
	{
	if(p<270)
	p=p+30;
	s++;
	}
	break;

	case ENTER: //13 ascii value
	a=1;
	break;
	}}
	 while(a!=1);

		switch(s)
		{

		case 1:
		cleardevice();
		play();
		break;

		case 2:
		disp_score();
		break;

		case 3:
		help();
		break;

		case 4:
		about();
		break;

		case 5:
		exit(0);

		default:
		cprintf("invelid choice");
		break;
		}}while(t==0);
		getch();

}



void main()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
//out_area();
startup();
cleardevice();
menu();
play();
cleardevice();
closegraph();
//getch();
}
/******** ending of first car boundary ***********/