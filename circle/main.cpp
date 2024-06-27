#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,500.0,0.0,500.0);
}


void Draw()
{
   float theta;
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f( 1 ,0, 0);
   glBegin(GL_POLYGON);

   for(int i = 0; i<360; i++){
    theta = i*3.1416/180;
    glVertex2f(150+100*cos(theta),150+100*sin(theta));
   }
   glEnd();

   float theta2;
   glColor3f( 1 ,1, 0);
   glBegin(GL_POLYGON);

   for(int j = 0; j<360; j++){
    theta2 = j*3.1416/180;
    glVertex2f(300+100*cos(theta2),300+100*sin(theta2));
   }
   glEnd();

glutSwapBuffers();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
