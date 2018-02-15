#include <iostream.h>
#include<fstream.h>
#include <math.h>
#include <bios.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
// float score=0;
 class game
	    {
	    char name[10];

	    public:
	    float score;
	    game()
	     {
	     score=0;
	     }
	    void getscore();
	    void putscore();
	   }o;

void add()
{  fstream fio;
   fio.open("h612.txt",ios::app);
   o.getscore();
   fio.write((char*)&o,sizeof(o));
   fio.close();
}

void game::getscore()
{
   {textcolor(2+BLINK);
  gotoxy(135,155);
  cprintf("Last 10 Scores\n");
  }
  cout<<"\nEnter name :";
  cin>>name;
 // cout<<"\nEnter score :";
  }
void game::putscore()
{
cout<<name<<"\t"<<score<<"\n"; }

void display()
{
fstream fin;
 fin.open("h612.txt",ios::in);
      fin.seekg(0,ios::beg);//set file pointer to the beginning
      fin.read((char*)&o,sizeof(o));//read first record
	while(!fin.eof())//search whole file
	{
	  o.putscore();

	fin.read((char*)&o,sizeof(o));//read next record
      }
       fin.close();


	 }


void credits()
{
 setcolor(getmaxcolor());
  // xmax = getmaxx();
  // ymax = getmaxy();
   setcolor(4);
   settextstyle(1,0,6);
   outtextxy(200,90,"CREDITS");
   setcolor(7);
   settextstyle(3,0,4);
   outtextxy(150,180,"a) Saurav Varshney");
   outtextxy(150,230,"b) Rishav Raj Prasad");
  // outtextxy(150,280,"c) Rishavraj Prasad");
   }


void instructions()
{
   setcolor(getmaxcolor());
   //xmax = getmaxx();
  // ymax = getmaxy();
   setcolor(3);
   settextstyle(1,0,5);
   outtextxy(159,50,"INSTRUCTIONS");
   setcolor(15);
   settextstyle(3,0,2);
   outtextxy(10,130,"a) The objective of this game is to make the ball reach");
   outtextxy(10,155,"            in the hole.");
   outtextxy(10,185,"b) Stick rolls in clockwise by pressing LEFT button and");
   outtextxy(10,210,"    anticlockwise by pressing RIGHT button.");
   outtextxy(10,245,"c) Then press ENTER to shoot. ");

   outtextxy(10,280,"d) If a coloured ball goes into the hole then score increases ");
   outtextxy(10,315,"    by one. And if skew ball goes into the hole then the score");
   outtextxy(10,350,"    decreases by one.!!!!Beat the highscore!!!! .");
   setcolor(3);
   settextstyle(1,0,2);
   outtextxy(10,380,"   For return to menu press: ESC");
   setcolor(14);
   settextstyle(3,0,4);
   outtextxy(225,410,"HAVE FUN!!!");
    line(155,100,440,100);
    line(155,105,440,105);
}

void exit();
void table();
void cal_collision(float ax,float ay,float bx,float by,float &length);
    //8=white;
    //1=blue;
    //2=red;
    //3=green;
    //4=brown;
    //5=grey;
    //6=yellow;
    int balloutx=100,ballouty=100;

    int flagcoll=0;
    int neras=0,neray=0,nerar=0,nerag=0;
    int ts=0,ty=0,tr=0,tg=0;
    int g=0,tsy=0,tsr=0,tsg=0,tyr=0,tgr=0,tgy=0;
    float nr=1,ny=1,ng=1;
    float lengthsy=0,lengthsr=0,lengthsg=0,lengthyr=0,lengthgr=0,lengthgy=0;
    float v1,w1,di,dicy=0,dicr=0,dicg=0;
    int k=0;

   void ballout(float ballx,float bally,int &t)
	{
	     if(ballx<107)
	       {t=10;
	       }
	     if(ballx>532)
	       {t=10;
	       }
	     if(bally<130)
	       {t=10;
	       }
	     if(bally>347)
	       {t=10;
	       }
	 }

    void ball(int &ball1z,int &ball1w,int &ball2z,int &ball2w,float &ballz1,float &dic,int &ballx,int &bally,int &t)
	 {
	      int dk=0;
	      ballz1=dic;
	   if(ball1z==0 && ball1w==0)
	     {
	       ball1z=ball2z;
	       ball1w=ball2w;
	       dk=1;
	     }
	   if(ball1z==1 && ball1w==1 && t==1)
	     {
	      if(dic>1)
		      {
		       if(dk==0)
			 ball1z=2;
		       if(dk==1)
			 ball2z=2;
		      }
	      if(dic<1)
		      {
		       if(dk==0)
			 ball1w=2;
		       if(dk==1)
			 ball2w=2;
		      }
	      if(dic==1)
		       {
			if(dk==0)
			  {
			   ball1z=2;
			   ball1w=2;
			   }
			if(dk==1)
			  {
			   ball2z=2;
			   ball2w=2;
			   }
		       }
	      if(dk==0)
		      {
		      ball2z=1;
		      ball2w=1;
		      }

		 t=1;
		 }

	   if(ball1z==1 && ball1w==2 && t==1)
	     {
	      if(dic>1)
		{
		 if(dk==0)
		    ball1w=1;
		 if(dk==1)
		    ball2w=1;
		 }
	      if(dic<1)
		{
		 if(dk==0)
		    ball1z=2;
		 if(dk==1)
		    ball2z=2;
		 }
	      if(dic==1)
		{
		 if(dk==0)
		   {
		    ball1z=2;
		    ball1w=1;
		    }
		 if(dk==1)
		    {
		    ball2z=2;
		    ball2w=1;
		    }
		}
	      if(dk==0)
		  {
		   ball2z=1;
		   ball2w=2;
		   }
		 t=1;
		 }
	   if(ball1z==2 && ball1w==1 && t==1)
	     {
	      if(dic>1)
		{
		 if(dk==0)
		    ball1w=2;
		 if(dk==1)
		    ball2w=2;
		 }
	      if(dic<1)
		{
		 if(dk==0)
		    ball1z=1;
		 if(dk==1)
		    ball2z=1 ;
		 }
	      if(dic==1)
		{
		 if(dk==0)
		   {
		    ball1z=1;
		    ball1w=2;
		    }
		 if(dk==1)
		   {
		    ball2z=1;
		    ball2w=2;
		    }
		}
		if(dk==0)
		  {
		   ball2z=2;
		   ball2w=1;
		   }
		 t=1;
		 }
	   if(ball1z==2 && ball1w==2 && t==1)
	     {
	     if(dic>1)
	       {
		if(dk==0)
		  ball1w=1;
		if(dk==1)
		  ball2w=1;
		}
	     if(dic<1)
	       {
		if(dk==0)
		   ball1z=1;
		if(dk==1)
		   ball2z=1;
		}
	     if(dic==1)
	       {
		if(dk==0)
		  {
		   ball1z=1;
		   ball1w=1;
		   }
		if(dk==1)
		  {
		   ball2z=1;
		   ball2w=1;
		   }
		}
		    if(dk==0)
		      {
		       ball2z=2;
		       ball2w=2;
		       }
		t=1;
		 }

		 flagcoll=0;

	 }

   void boundery(int ballx,int bally,int &ww,int &zz)
		{
		 if(ballx>337 && ballx<517 && bally<141)  //check
		   {
		    ww=1;
		    setcolor(15);
		    table();
		    setcolor(0);
		    circle(ballx,bally,10);
		    setfillstyle(1, 0);
		    floodfill(ballx,bally, 0);
		    g=1;
		   }
		 if(bally>149 && bally<325 && ballx>522)     //check
		   {
		    zz=2;
		    setcolor(15);
		    table();
		    setcolor(0);
		    circle(ballx,bally,10);
		    setfillstyle(1, 0);
		    floodfill(ballx,bally, 0);
		    g=1;
		   }
		 if(bally>149 && bally<325 && ballx<117)       //check
		   {
		    zz=1;
		    setcolor(15);
		    table();
		    setcolor(0);
		    circle(ballx,bally,10);
		    setfillstyle(1, 0);
		    floodfill(ballx,bally, 0);
		    g=1;
		   }
		 if(ballx>337 && ballx<517 && bally>337)    //check
		   {
		    ww=2;
		    setcolor(15);
		    table();
		    setcolor(0);
		    circle(ballx,bally,10);
		    setfillstyle(1, 0);
		    floodfill(ballx,bally, 0);
		    g=1;
		   }
		 if(ballx>120 && ballx<307 && bally<140) //check
		   {
		    ww=1;
		    setcolor(15);
		    table();
		    setcolor(0);
		    circle(ballx,bally,10);
		    setfillstyle(1, 0);
		    floodfill(ballx,bally, 0);
		    g=1;
		   }
		 if(ballx>120 && ballx<307 && bally>337) //check
		   {
		    ww=2;
		    setcolor(15);
		    table();
		    setcolor(0);
		    circle(ballx,bally,10);
		    setfillstyle(1, 0);
		    floodfill(ballx,bally, 0);
		    g=1;
		   }
		}

  void table()
	    {

	   int left, top, right, bottom;
	   left = getmaxx() / 2 - 225;
	   top = getmaxy() / 2 - 125;
	   right = getmaxx() / 2 + 225;
	   bottom = getmaxy() / 2 + 124;
	   rectangle(left,top,right,bottom);


   line(110,114,120,130);
   line(120,130,307,130);
   line(307,130,314,114);
   line(330,114,337,130);
   line(337,130,517,130);
   line(517,130,527,114);

   line(110,362,120,347);
   line(120,347,307,347);
   line(307,347,314,362);
   line(330,362,337,347);
   line(337,347,517,347);
   line(517,347,527,362);

   line(95,138,107,149);
   line(107,149,107,325);
   line(107,325,95,340);

   line(542,138,532,149);
   line(532,149,532,325);
   line(532,325,542,340);
	    }

 int main(void)
	 {
	 float n0=0;
	 int zy=0,wy=0,zr=0,wr=0,zg=0,wg=0;
	 int sx=210,sy=240;//co ordinates  of striker
	 float R=0,r2=0.04,k=0,b=0;
	 float z1,dx,dy;
	 int x1,y1;
	 int xx=207,yy=443;
	 int px=0,pm=0;
	 int x11=0,y11=0;
	 int c1=0;
	 float xblue=400,yblue=240,xred=419,yred=229,xgreen=419,ygreen=251,xbrown=438,ybrown=240,xgrey=438,ygrey=218,xyellow=438,yyellow=262;
	 float midx, midy,n;
	 int radius = 10;
	 int x,y,k1,z,c,w,r=0;
	 int col=0;


   /* request auto detection */
   int gdriver= DETECT, gmode, errorcode;
   //int left, top, right, bottom;

	   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c://turboc3//bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");


      getch();
      exit(1); /* terminate with an error code */
   }

float key=0;
   ///////////////////////////////////////////////////////////////
j:
    do
      {
	settextstyle(4,0,4);
		       if(n0==0)
			       {
				setcolor(6) ;
				rectangle(195,167,410,210);
				outtextxy(200,170,"1. New Game");
			       }
		       else
			       {
				setcolor(4) ;
				outtextxy(200,170,"1. New Game");
				setcolor(0) ;
				rectangle(195,167,410,210);
			       }

		       if(n0==1)
			       {
				setcolor(6) ;
				outtextxy(200,220,"2. Instructions");
				rectangle(195,215,410,260);
			       }
		       else
			       {
				setcolor(4) ;
				outtextxy(200,220,"2. Instructions");
				setcolor(0) ;
				rectangle(195,215,410,260);
			       }

		       if(n0==2)
			       {
				setcolor(6) ;
				outtextxy(200,270,"3. Credits");
				rectangle(195,265,410,310);
			       }
		       else
			       {
				setcolor(4) ;
				outtextxy(200,270,"3. Credits");
				setcolor(0) ;
				rectangle(195,265,410,310);
			       }

		       if(n0==3)
			       {
				setcolor(6) ;
				rectangle(195,315,410,360);
				outtextxy(200,320,"4. Exit");
			       }
		       else
			       {
				setcolor(4) ;
				outtextxy(200,320,"4. Exit");
				setcolor(0) ;
				rectangle(195,315,410,360);
			       }

   key=bioskey(0) ;
   if(key==18432)
		  {n0-- ;}
   if(key==20480)
		  {n0++ ;}
   if(n0==4)
		  {n0=0 ;}
   if(n0==-1)
		  {n0=3 ;}
}
while(key!=7181);





  if(n0==0)
      {
	do
	  {
	   cleardevice();
	 //  setcolor(BLUE);
	   key=bioskey(0);
	  }
	while(key!=283);
      }
  if(n0==1)
      {
	do
	  {
	   cleardevice();
instructions();

	 //  setcolor(BLUE);
	   key=bioskey(0);
	  }
	while(key!=283);
	cleardevice();
	goto j;
      }
  if(n0==2)
      {
	do
	  {
	   cleardevice();
	   credits();
	   key=bioskey(0);
	  }
	while(key!=283);
	cleardevice();
	goto j;
      }
  if(n0==3)
      {
	do
	  {
	   cleardevice();
	   settextstyle(4,0,3);
	   setcolor(4);
	   delay(100);
			  outtextxy(200,80,"DO    YOU   WANT");
			  outtextxy(200,120,"TO    EXIT  ??????");

		    float key=0 , n1=0 ;
	     do
	       {

	    settextstyle(4,0,4);
		       if(n1==0)
			   {
			    setcolor(6) ;
			    rectangle(255,167,350,212);
			    outtextxy(250,170,"  Yes");
			   }
			else
			   {
			    setcolor(4) ;
			    outtextxy(250,170,"  Yes");
			    setcolor(0) ;
			    rectangle(255,167,350,212);
			   }

			if(n1==1)
			   {
			    setcolor(6) ;
			    outtextxy(250,220,"  No");
			    rectangle(255,215,350,260);
			   }
			else
			   {
			    setcolor(4) ;
			    outtextxy(250,220,"  No");
			    setcolor(0) ;
			    rectangle(255,215,350,260);
			   }
    key=bioskey(0) ;
    if(key==18432)
      {n1-- ;}
    if(key==20480)
      {n1++ ;}
    if(n1==2)
      {n1=0 ;}
    if(n1==-1)
      {n1=1;}
	       }
   while(key!=7181);

      if(n1==0)
	{exit(0);}
      if(n1==1)
	{
	 cleardevice();
	 goto j;
	}

   key=bioskey(0);
	  }
	while(key!=283);
	cleardevice();
	goto j;

      }


///////////////////////////////////////////////
       setcolor(15);

	x=200*sin(R);
	y=200*cos(R);
	line(sx,sy,x+sx,sy-y);
	x1=200*sin(r2);
	y1=200*cos(r2);
	line(sx,sy,x1+sx,sy-y1);


m:
  /* draw a rectangle */
  // rectangle(left,top,right,bottom);
       table();
   //white
   circle(210,240,10);
   setfillstyle(1, 15);//white
   floodfill(210,240,15);
   //blue
   circle (400,240,10);
   setfillstyle(1, 1);//blue
   floodfill(400,240,15);
   //red
   circle(xred,yred,10);
   setfillstyle(1, 4);//red
   floodfill(xred,yred,15);
   //green
   circle(xgreen,ygreen,10);
   setfillstyle(1, 2);//green
   floodfill(xgreen,ygreen, 15);
   //brown
   circle(xbrown,ybrown,10);
   setfillstyle(1, 6);//brown
   floodfill(xbrown,ybrown, 15);
   //grey
   circle(xgrey,ygrey,10);
   setfillstyle(1, 8);//grey
   floodfill(xgrey,ygrey, 15);
   //yellow
   circle(xyellow,yyellow,10);
   setfillstyle(1, 14);//yellow
   floodfill(xyellow,yyellow, 15);
   /*
   //power meter.

   rectangle(100,400,354,450);
   rectangle(105,405,307,445);
   rectangle(314,405,349,445);

   setcolor(4);
   rectangle(107,407,xx+px,yy);
   setfillstyle(1, 4);
   floodfill(108,408, 4);       */

n:
   setcolor(15);
   //stick
   sx=210;
   sy=240;


//   pm=xx+px;

  do
    {
     key=bioskey(0);
     if(key==19712)
       {
	 {
    //	 circle(400,240,10);
    //	 setfillstyle(1, 1);//blue
   //	 floodfill(400,240, 15);
   //
   //	 for(int i=9;i>=0;i--)
   //	   {
   //	    setcolor(1);
   //	    circle(xblue,yblue,i);
   //	    setfillstyle(1, 1);//blue
   //	    floodfill(xblue,yblue, 1);
   //	   }
   //	for(int j=0;j<=18;j++)
   //	  {
  //	  setcolor(4);
  //	  rectangle(107+j,407+j,pm-j,yy-j);
  //	  setfillstyle(1, 4);
   //	  floodfill(108,408, 4);
   //	  }

	setcolor(0);
	x=200*sin(R);
	y=200*cos(R);
	line(sx,sy,x+sx,sy-y);
	R=R+0.057;
	setcolor(15);
	x=200*sin(R);
	y=200*cos(R);
	line(sx,sy,x+sx,sy-y);

	setcolor(0);
	x1=200*sin(r2);
	y1=200*cos(r2);
	line(sx,sy,x1+sx,sy-y1);
	r2=r2+0.057;
	setcolor(15);
	x1=200*sin(r2);
	y1=200*cos(r2);
	line(sx,sy,x1+sx,sy-y1);

	goto m;
	  }
       }

   if(key==19200)
     {
	{
       //	 circle(400,240,10);
       //	 setfillstyle(1, 1);//blue
       //	 floodfill(400,240, 15);

       //	for(int i=9;i>=0;i--)
 //  {
  // setcolor(1);
  // circle(400,240,i);
  // setfillstyle(1, 1);//blue
  // floodfill(400,240, 1);
  // }

     //	 for(int j=0;j<=18;j++)
     //	    { setcolor(4);
     //	      rectangle(107+j,407+j,pm-j,yy-j);
     //	      setfillstyle(1, 4);
     //	      floodfill(108,408, 4);
     //	    }

	setcolor(0);
	x=200*sin(R);
	y=200*cos(R);
	line(sx,sy,x+sx,sy-y);
	R=R-0.057;
	setcolor(15);
	x=200*sin(R);
	y=200*cos(R);
	line(sx,sy,x+sx,sy-y);

	setcolor(0);
	x1=200*sin(r2);
	y1=200*cos(r2);
	line(sx,sy,x1+sx,sy-y1);
	r2=r2-0.057;
	setcolor(15);
	x1=200*sin(r2);
	y1=200*cos(r2);
	line(sx,sy,x1+sx,sy-y1);
	goto m;
	 }
       }
/*   if(key==18432)
     {
      px+=2;
      if(px==100)
	{
	 px=px-198;
	 }
	 setcolor(0);
   rectangle(107,407,xx,yy);
   setfillstyle(1, 0);
   floodfill(108,408, 15);
    goto n;
	}

	if(key==20480)
     {
      px-=2;
      if(px==(-98))
	{
	 px=px+196;
	 }
	 setcolor(0);
   rectangle(107,407,xx,yy);
   setfillstyle(1, 0);
   floodfill(108,408, 15);
	 goto n;
	}
	     */
}while(key!=7181);


k=r2-R;

	setcolor(0);
	x=200*sin(R);
	y=200*cos(R);
	line(sx,sy,x+sx,sy-y);
	setcolor(0);
	x1=200*sin(r2);
	y1=200*cos(r2);
	line(sx,sy,x1+sx,sy-y1);
b=k+R;

	x11=sx+200*sin(b);
	y11=sy-200*cos(b);

	 midx = sx;
	 midy = sy;

   x=x11;
   y=y11;

   if(midx>x)
       {dx=midx-x;
       z=1;
       }
   if(midx<x)
       {dx=x-midx;
       z=2;
       }
   if(midy>y)
       {dy=midy-y;
       w=1;
       }
   if(midy<y)
       {dy=y-midy;
       w=2;
       }
   /* draw the circle */
  z1=(dy/dx);
  n=1;
    if(z1>1)
      {n=(1/z1);
       z1=1;}

   circle(midx, midy, radius);
//the lloooopppp
   for(int d=0;d<1000;d++)
	  {
		setcolor(0);
		circle(midx,midy,10);
		setcolor(15);
		table();


  b:


 boundery(xyellow,yyellow,wy,zy);
	   if(flagcoll==68)
	   {
	    ball(z,w,zy,wy,z1,dicy,xyellow,yyellow,tsy);

	    if(k==1)
	      {
	       ny=(1/dicy);
	       dicy=1;
	       z1=1;
	       n=ny;
	      }
	       k=0;
	   }
 boundery(xred,yred,wr,zr);
	   if(flagcoll==28)
	   {
	    ball(z,w,zr,wr,z1,dicr,xred,yred,tsr);

	    if(k==1)
	      {
	       nr=(1/dicr);
	       dicr=1;
	       z1=1;
	       n=nr;
	      }
	      k=0;
	   }
 boundery(xgreen,ygreen,wg,zg);
	   if(flagcoll==38)
	   {
	    ball(z,w,zg,wg,z1,dicg,xgreen,ygreen,tsg);

	    if(k==1)
	      {
	       ng=(1/dicg);
	       dicg=1;
	       z1=1;
	       n=ng;
	       }
	   k=0;
	   }
 boundery(xyellow,yyellow,wy,zy);
 boundery(xred,yred,wr,zr);

	 if(flagcoll==62)
	   {
	    ball(zy,wy,zr,wr,dicy,dicr,xred,yred,tyr);
		if(k==1)
		  {
		   nr=(1/dicr);
		   dicr=1;
		   ny=nr;
		   dicy=1;
		  }
	      k=0;
	   }
 boundery(xgreen,ygreen,wg,zg);
 boundery(xred,yred,wr,zr);

	 if(flagcoll==32)
	   {
	    ball(zg,wg,zr,wr,dicg,dicr,xred,yred,tgr);
		if(k==1)
		  {
		   nr=(1/dicr);
		   dicr=1;
		   ng=nr;
		   dicg=1;
		  }
		k=0;
	    }
 boundery(xgreen,ygreen,wg,zg);
 boundery(xyellow,yyellow,wy,zy);

	 if(flagcoll==36)
	   {
	    ball(zg,wg,zy,wy,dicg,dicy,xyellow,yyellow,tgy);
		if(k==1)
		  {
		   ny=(1/dicy);
		   dicy=1;
		   ng=ny;
		   dicg=1;
		  }
	      k=0;
	   }

	      if(zy==1 && wy==1 && ty!=10)
	       {  circle(xyellow,yyellow,10);
		  setcolor(0);
		  setfillstyle(1, 0);//yellow
		  floodfill(xyellow,yyellow, 0);

		 xyellow=xyellow+ny;
		 yyellow=yyellow+dicy;
	       }
	      if(zy==1 && wy==2 && ty!=10)
		{  circle(xyellow,yyellow,10);
		   setcolor(0);
		   setfillstyle(1, 0);//yellow
		   floodfill(xyellow,yyellow, 0);

		 xyellow=xyellow+ny;
		 yyellow=yyellow-dicy;
		}
	      if(zy==2 && wy==1 && ty!=10)
		{
		  setcolor(0);
		  circle(xyellow,yyellow,10);
		  setfillstyle(1, 0);//yellow
		  floodfill(xyellow,yyellow, 0);

		 xyellow=xyellow-ny;
		 yyellow=yyellow+dicy;
	       }
		if(zy==2 && wy==2 && ty!=10)
	       {  setcolor(0);
		  circle(xyellow,yyellow,10);
		  setfillstyle(1, 0);//yellow
		  floodfill(xyellow,yyellow, 0);

		 xyellow=xyellow-ny;
		 yyellow=yyellow-dicy;
	       }
		if(zr==1 && wr==1 && tr!=10)
	       {  setcolor(0);
		  circle(xred,yred,10);
		  setfillstyle(1, 0);//yellow
		  floodfill(xred,yred, 0);

		 xred=xred+nr;
		 yred=yred+dicr;

	       }
	       if(zr==1 && wr==2 && tr!=10)
	       {  setcolor(0);
		  circle(xred,yred,10);
		  setfillstyle(1, 0);//yellow
		  floodfill(xred,yred, 0);

		 xred=xred+nr;
		 yred=yred-dicr;
	       }
	       if(zr==2 && wr==1 && tr!=10)
	       {  setcolor(0);
		  circle(xred,yred,10);
		  setfillstyle(1, 0);//yellow
		  floodfill(xred,yred, 0);

		 xred=xred-nr;
		 yred=yred+dicr;
	       }
		if(zr==2 && wr==2 && tr!=10)
	       {  setcolor(0);
		  circle(xred,yred,10);
		  setfillstyle(1, 0);//yellow
		  floodfill(xred,yred, 0);

		 xred=xred-nr;
		 yred=yred-dicr;
	       }
		if(zg==1 && wg==1 && tg!=10)
		  {
		   setcolor(0);
		   circle(xgreen,ygreen,10);
		   setfillstyle(1, 0);//yellow
		   floodfill(xgreen,ygreen, 0);

		 xgreen=xgreen+ng;
		 ygreen=ygreen+dicg;
		   }
	       if(zg==1 && wg==2 && tg!=10)
		 { setcolor(0);
		   circle(xgreen,ygreen,10);
		   setfillstyle(1, 0);//yellow
		   floodfill(xgreen,ygreen, 0);

		 xgreen=xgreen+ng;
		 ygreen=ygreen-dicg;
		 }

	       if(zg==2 && wg==1 && tg!=10)
	       {
		 setcolor(0);
		 circle(xgreen,ygreen,10);
		 setfillstyle(1, 0);//yellow
		 floodfill(xgreen,ygreen, 0);

		 xgreen=xgreen-ng;
		 ygreen=ygreen+dicg;
	       }
	       if(zg==2 && wg==2 && tg!=10)
	       {  setcolor(0);
		  circle(xgreen,ygreen,10);
		  setfillstyle(1, 0);//yellow
		  floodfill(xgreen,ygreen, 0);

		 xgreen=xgreen-ng;
		 ygreen=ygreen-dicg;
	       }
		setcolor(15);

    o:      boundery(midx,midy,w,z);

	       if(z==1 && w==1 && ts!=10)
		 {
		 midx=midx+n;
		 midy=midy+z1;
		 }
	       if(z==1 && w==2 && ts!=10)
		 {
		 midx=midx+n;
		 midy=midy-z1;
		 }
	       if(z==2 && w==1 && ts!=10)
		 {
		 midx=midx-n;
		 midy=midy+z1;
		 }
	       if(z==2 && w==2 && ts!=10)
		 {
		 midx=midx-n;
		 midy=midy-z1;
		 }

       g=0;
	 cal_collision(midx,midy,xyellow,yyellow,lengthsy);
	   setcolor(15);

	   if(lengthsy<=20 && tsy!=2 && ty!=10 && ts!=10)
			{
		     col=1;

		     flagcoll=68;


			dicy=di;
			ny=1;



			setcolor(0);
			circle(midx,midy,10);
			circle(xyellow,yyellow,10);
			  setfillstyle(1, 0);//yellow
			  floodfill(xyellow,yyellow, 0);

			tsy++;
			goto b;
			 }
		      tsy=0;
    cal_collision(midx,midy,xred,yred,lengthsr);


	 if(lengthsr<=20 && tsr!=2 && tr!=10 && ts!=10)
			{

			col=1;

			flagcoll=28;

			dicr=di;
			nr=1;

			setcolor(0);
		circle(midx,midy,10);
			circle(xred,yred,10);
		  setfillstyle(1, 0);//yellow
		  floodfill(xred,yred, 0);
			tsr++;
			goto b;
			 }
		      tsr=0;
    cal_collision(midx,midy,xgreen,ygreen,lengthsg);


	 if(lengthsg<=20 && tsg!=2 && tg!=10 && ts!=10)
		{
			col=1;

			flagcoll=38;

			dicg=di;
			nr=1;
			setcolor(0);
			circle(midx,midy,10);
			circle(xgreen,ygreen,10);
			setfillstyle(1, 0);//yellow
			floodfill(xgreen,ygreen, 0);
			tsg++;
			goto b;
			 }
		      tsg=0;

       cal_collision(xyellow,yyellow,xred,yred,lengthyr);

	 if(lengthyr<=20 && tyr!=2 && ty!=10 && tr!=10)
			{
			col=1;

			flagcoll=62;

			dicr=di;

			circle(xyellow,yyellow,10);
			setcolor(0);
			setfillstyle(1, 0);//yellow
			floodfill(xyellow,yyellow, 0);

			circle(xred,yred,10);
			setfillstyle(1, 0);//yellow
			floodfill(xred,yred, 0);
			tyr++;
			goto b;
			 }
		      tyr=0;
     cal_collision(xgreen,ygreen,xred,yred,lengthgr);


	 if(lengthgr<=20 && tgr!=2 && tg!=10 && tr!=10)
			{
			col=1;

			flagcoll=32;

			dicr=di;
			setcolor(0);
			circle(xgreen,ygreen,10);
			setfillstyle(1, 0);//yellow
			floodfill(xgreen,ygreen, 0);

			setcolor(0);
			circle(xred,yred,10);
			setfillstyle(1, 0);//yellow
			floodfill(xred,yred, 0);
			tgr++;
			goto b;
			 }
		      tgr=0;
	 cal_collision(xgreen,ygreen,xyellow,yyellow,lengthgy);


	 if(lengthgy<=20 && tgy!=2 && tg!=10 && ty!=10)
			{
			col=1;

			flagcoll=36;

			dicy=di;
			setcolor(0);

			circle(xgreen,ygreen,10);
			setfillstyle(1, 0);//yellow
			floodfill(xgreen,ygreen, 0);
			circle(xyellow,yyellow,10);
		     setfillstyle(1, 0);//yellow
		     floodfill(xyellow,yyellow, 0);

			tgy++;
			goto b;
			 }
	 tgy=0;
	   if(ts!=10)
	 {  setcolor(15);
	   circle(midx,midy,10);
	   }
	   if(ty!=10)
	 {  circle(xyellow,yyellow,10);
	    setfillstyle(1, 14);//yellow
	    floodfill(xyellow,yyellow, 15);
	   }
	   if(tr!=10)   //
	 {  circle(xred,yred,10);
	    setfillstyle(1, 4);//yellow
	    floodfill(xred,yred, 15);
	   }
	   if(tg!=10)
	 {  circle(xgreen,ygreen,10);
	    setfillstyle(1, 2);//yellow
	    floodfill(xgreen,ygreen, 15);
	   }

	  ballout(midx,midy,ts);
	  ballout(xyellow,yyellow,ty);
	  ballout(xred,yred,tr);
	  ballout(xgreen,ygreen,tg);

	   if(ts==10 && neras!=1)
	 {  setcolor(0);
	   circle(midx,midy,10);
	   neras=1;
	  o.score-=1;
	   }
	   if(ty==10 && neray!=1)
	 {
	   circle(balloutx,ballouty,10);
	  //  setcolor(14);
	   setfillstyle(1, 14);//yellow
	   floodfill(balloutx,ballouty, 15);
	   balloutx+=25;
	   circle(xyellow,yyellow,10);
	   setcolor(0);
	   setfillstyle(1, 0);//yellow
	   floodfill(xyellow,yyellow, 0);
	   neray=1;
	   o.score+=1;
	   }
	   if(tr==10 && nerar!=1)   //
	 { circle(balloutx,ballouty,10);
	  //  setcolor(14);
	   setfillstyle(1, 4);//yellow
	   floodfill(balloutx,ballouty, 15);
	   balloutx+=25;
	   circle(xred,yred,10);
	   setcolor(0);
	   setfillstyle(1, 0);//yellow
	   floodfill(xred,yred, 0);
	   nerar=1;
	   o.score+=1;
	   }
	   if(tg==10 && nerag!=1)
	{   circle(balloutx,ballouty,10);
	  //  setcolor(14);
	    setfillstyle(1, 2);//yellow
	    floodfill(balloutx,ballouty, 15);
	    balloutx+=25;
	    circle(xgreen,ygreen,10);
	    setcolor(0);
	    setfillstyle(1, 0);//yellow
	    floodfill(xgreen,ygreen, 0);
	    nerag=1;
	    o.score+=1;
	  }

	   delay(5);


    }
 //clrscr();

setcolor(0);
add();
display();
   /* clean up */
   getch();
   closegraph();
   return 0;
}

  void cal_collision(float ax,float ay,float bx,float by,float &length)
		     {
		     // cout<<'b';
		      float z;
		      if(bx>ax)
		      v1=bx-ax;
		      if(bx<ax)
		      v1=ax-bx;
		      if(by>ay)
		      w1=by-ay;
		      if(by<ay)
		      w1=ay-by;
		      di=(w1/v1);
		      if(di>1)
			{k=1;}
		     // cout<<v1<<w1;
		      z=(v1*v1)+(w1*w1);
		      length=pow(z,0.5);

		      }
