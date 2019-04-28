#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<graphics.h>
#include<time.h>
#include<dos.h>

void minSecPos(int xrad, int midx, int midy, int x[60], int y[60])
{
 int i, j=45;
 for (i=360; i>=0; i=i-6)
 {
  x[j] = midx-(xrad*cos((i*3.14)/180));
  y[j--] = midy-(xrad*sin((i*3.14)/180));
  j = (j==-1)?59:j;
 }
 return;
}
void calcPoints(int radius, int midx, int midy, int x[12], int y[12])
{
 int x1, y1;
 x[0] = midx, y[0] = midy-radius;
 x[6] = midx, y[6] = midy+radius;
 x[3] = midx+radius, y[3] = midy;
 x[9] = midx-radius, y[9] = midy;

 x1 = (int) ((radius/2)*sqrt(3));
 y1 = (radius/2);
 x[2] = midx+x1, y[2] = midy-y1;
 x[4] = midx+x1, y[4] = midy+y1;
 x[8] = midx-x1, y[8] = midy+y1;
 x[10] = midx-x1, y[10] = midy-y1;

 x1 = radius/2;
 y1 = (int) ((radius/2)*sqrt(3));
 x[1] = midx+x1, y[1] = midy-y1;
 x[5] = midx+x1, y[5] = midy+y1;
 x[7] = midx-x1, y[7] = midy+y1;
 x[11] = midx-x1, y[11] = midy-y1;
 return;
}

int main() {
  int gd=DETECT, gm, tmp;
  int i, j, midx, midy, radius, hr, min, sec;
  int x[12], y[12], minx[60], miny[60];
  int hrx[12], hry[12], secx[60], secy[60];
  int secx1, secy1;
  char str[256];
  time_t t1;
  struct tm*data;
  char randstring[10];
  char intro[]="Welcome!This project is created by the work of:\nAkash Singh\nEjaaz Sayyed\nSiddharth Raja";
  int length=strlen(intro);
  for(i=0;i<length;i++)
  {
  printf("%c",intro[i]);
  delay(100);
  }
  getch();
  initgraph(&gd, &gm, "C:\\Turboc3\\Bgi");


  midx = getmaxx()/2;
  midy = getmaxy()/2;

  radius = 200;

  calcPoints(radius-30, midx, midy, x, y);
  calcPoints(radius-90, midx, midy, hrx, hry);

  minSecPos(radius-50, midx, midy, minx, miny);
  minSecPos(radius-70, midx, midy, secx, secy);

while (!kbhit())
{
  setlinestyle(SOLID_LINE, 1, 3);
  settextstyle(GOTHIC_FONT, 0, 3);
   setfillstyle(HATCH_FILL,RED);
   circle(midx, midy, radius);
   floodfill(midx,midy,WHITE);
   rectangle(midx-110,midy+50,midx+110,midy+100);

   for (j=0; j<12; j++)
  {
   if (j==0)
    {
     sprintf(str, "%d", 12);
      } else {
    sprintf(str, "%d", j);
    }
  settextjustify(CENTER_TEXT, CENTER_TEXT);
  moveto(x[j], y[j]);
  outtext(str);
  }

 t1 = time(NULL);
 data = localtime(&t1);

 sec = data->tm_sec % 60;
 line(midx, midy,secx[sec], secy[sec]);

  min = data->tm_min % 60;
 line(midx, midy, minx[min], miny[min]);

  hr = data->tm_hour % 12;
//  window(midx-110,midy+50,midx+110,midy+100);
if(sec<10 || min<10 || hr<10){
  if(sec<10){sprintf(randstring,"%d::%d::0%d",hr,min,sec);}
  if(min<10){sprintf(randstring,"%d::0%d::%d",hr,min,sec);}
  if(hr<10){sprintf(randstring,"0%d::%d::%d",hr,min,sec);}
  if(sec<10&&min<10){sprintf(randstring,"%d::0%d::0%d",hr,min,sec);}
  if(sec<10&&hr<10){sprintf(randstring,"0%d::%d::0%d",hr,min,sec);}
  if(min<10&&hr<10){sprintf(randstring,"0%d::0%d::%d",hr,min,sec);}
  if(sec<10&&hr<10&&min<10){sprintf(randstring,"0%d::0%d::0%d",hr,min,sec);}}
else{  sprintf(randstring,"%d::%d::%d",hr,min,sec);}
  outtextxy(midx,midy+70,randstring);
 line(midx, midy, hrx[hr], hry[hr]);
 delay(1000);


 cleardevice();
 }

     getch();
     closegraph();
     return 0;
  }
