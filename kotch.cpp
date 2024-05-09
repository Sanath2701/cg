#include <GL/glut.h>
#include <math.h>

GLfloat oldx=-0.7,oldy=0,5;
void drawkotch(GLfloat dir,Glfloat len, GLINT iter)
{
 GLdouble dirRad= 0.0174533*dir;
 Glfloat newx= oldx+ len*cos(diRad);
 Glfloat newy= oldy+ len*sin(diRad);
 if(iter==0)
 {
  glVertex2f(oldx,oldy);
  glVertex2f(newx,newy);
  oldx=newx;
  oldy=newy;
  
 else
 { 
  iter--;
  drawkotch(dir,len,iter);
   dir+=60;
    drawkotch(dir,len,iter);
   dir-=120;
    drawkotch(dir,len,iter);
   dir+=60;
    drawkotch(dir,len,iter);
 }
 }
 void myDisplay()
 { 
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_LINES);
 glColor3f(1,0,0);
 
 drawkotch(0.0.015.4);
 
 drawkotch(-120.0.015.4);
 
 drawkotch(120.0.015.4);
 glEnd();
 glFlush();
 }
 }
 int main( int argc , char** argv)
 {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("OPENGL");
  glutDisplayFunc(myDisplay);
  glutMainLoop();
  return 0;
  }
 
