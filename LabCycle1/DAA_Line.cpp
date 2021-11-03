#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
using namespace std;
int main(void) {
  /* request auto detection */
  int gdriver = DETECT, gmode, errorcode;
 
  /* initialize graphics and local variables */
  initgraph( & gdriver, & gmode, "C:\\tc\\bgi");
 
  cout << "\n Enter X1,Y1,X2,Y2";
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
 
  int dx = x2 - x1;
  int dy = y2 - y1;
  int length;
  if (dx >= dy)
    length = dx;
  else
    length = dy;
  dx = dx / length;
  dy = dy / length;
  int sx;
  if (dx >= 0)
    sx = 1;
  else
    sx = -1;
  int sy;
  if (dy >= 0)
    sy = 1;
  else
    sy = -1;
  float x = x1 + 0.5 * (sx);
  float y = y1 + 0.5 * (sy);
  int i = 0;
  while (i <= length) {
    putpixel(int(x), int(y), 15);
    x = x + dx;
    y = y + dy;
    i = i + 1;
  }
 
  /* clean up */
  getch();
  closegraph();
  return 0;
}