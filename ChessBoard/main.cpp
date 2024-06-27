#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void){
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,8.0,0.0,8.0);
}


void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);

    bool color = false;

    for(int x=0; x<=8; x++){
        for(int y=0; y<=8; y++){
            if(color) {
                glColor3f(1.0, 1.0, 1.0);
                color = !color;
            }

            else {
                glColor3f(0.0, 0.0, 0.0);
                color = !color;
            }

            glBegin(GL_QUADS);
            glVertex2i(x, y);
            glVertex2i(x, y + 1);
            glVertex2i(x + 1, y + 1);
            glVertex2i(x + 1, y);

            glEnd();

            glFlush();
        }
    }
}


int main(int argc,char **argv){


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_SINGLE );
    glutInitWindowPosition(600,200);
    glutInitWindowSize(600,600);
    glutCreateWindow("AK Chess Board");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
