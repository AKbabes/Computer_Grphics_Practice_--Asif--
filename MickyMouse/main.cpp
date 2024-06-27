#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>
void init(void)
{
    glClearColor(0.671, 0.851, 0.663, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,50.0,0.0,70.0);
}
void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0; i<=100; i++)
    {
        float angle = 2 * 3.1416 * i/100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f(x+cx,y+cy);
    }
    glEnd();
}
void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslated(2,0,0);
    glColor3f( 0.188, 0.188, 0.173); //leg
    glBegin(GL_POLYGON);
    glVertex2i(18,20);
    glVertex2i(21,20);
    glVertex2i(17,10);
    glVertex2i(14,10);
    glEnd();
    glColor3f( 1, 0.984, 0); //foot
    circle(3.6,3,14,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2,0,0);
    glColor3f( 0.188, 0.188, 0.173);//leg2
    glBegin(GL_POLYGON);
    glVertex2i(26,20);
    glVertex2i(29,20);
    glVertex2i(32,10);
    glVertex2i(29,10);
    glEnd();
    glColor3f(1, 0.984, 0);//foot2
    circle(3.6,3,32,10);
    glPopMatrix();


    glColor3f( 0.188, 0.188, 0.173);//hand
    glBegin(GL_POLYGON);
    glVertex2i(14,27);
    glVertex2i(20,31);
    glVertex2i(20,28);
    glVertex2i(15,25);
    glEnd();

    glPushMatrix();
    glTranslated(-12,0,0);
    glColor3f( 0.188, 0.188, 0.173);//hand2
    glBegin(GL_POLYGON);
    glVertex2i(38,31);
    glVertex2i(44,27);
    glVertex2i(43,25);
    glVertex2i(38,28);
    glEnd();
    glPopMatrix();



    glColor3f( 0.859, 0.114, 0.102);//pet
    circle(5,9,23,25);

    glColor3f( 1 ,1, 1);//matha
    circle(8.5,10,23,40);


    glColor3f( 0.188, 0.188, 0.173);
    circle(4,3,23,35);
    glColor3f( 1 ,1, 1);
    circle(4,3,23,35.7);


    glColor3f(0.188, 0.188, 0.173);//kan
    circle(3,4,16,51);

    glColor3f( 0.188, 0.188, 0.173);//kan
    circle(3,4,30,51);

    glColor3f( 0.188, 0.188, 0.173);
    circle(2,1.7,23,37);

    glColor3f( 0.188, 0.188, 0.173);
    circle(1,2,20,42);

    glColor3f( 0.188, 0.188, 0.173);
    circle(1,2,26,42);


    glColor3f( 1, 0.984, 0); //pocket
    circle(1.7,2,21,22);

    glColor3f( 1, 0.984, 0); //pocket2
    circle(1.7,2,25,22);


    glColor3f( 1, 1, 1); //finger
    circle(2,3,14,25.7);

    glColor3f( 1, 1, 1); //finger
    circle(2,3,32,26);









    glutSwapBuffers();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Micky Mouse");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
