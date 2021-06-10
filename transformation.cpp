#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926
using namespace std;

void square(float side){
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-side, side);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-side,-side);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(side,-side);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(side,side);
    glEnd();
}

void circle(float r, int quantity){
    glBegin(GL_POLYGON);
    float cx = -12.0, cy = 0.0; // posições x e y
    
    for( int i = 0; i < quantity; i++){
        float theta = (2.0f * PI * float(i)) / (float(100));
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        if(i < 150){
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(x + cx, y + cy);
        }
        else{
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(x + cx, y + cy);
        }
        
    }
    glEnd();
}

void triangle(float side){
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    // quarto parâmetro da função acima modifica a transparência
    glVertex2f(3*side, side);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(2*side, 0.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(4*side, 0.0);
    
    glEnd();
}

void drawFiguresWithEqualArea(){
    circle(2.2567583342, 300);    // raio equivalente da mesma area das outras figuras raizQuadrada(16/pi)
    square(2.0); //lado do quadrado
    triangle(4.0);
}


void display () {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    // glTranslatef(8, 8, 0); // tranlada
    // glScalef(1.5,3,0); // aumenta escala em x,y,z
    // glRotatef(60,0,0,1); // rotação de 60 graus em relação ao eixo Z
    
    glScalef(1, -1, 1); // Reflexão no eixo Y
    drawFiguresWithEqualArea();

    glFlush();
}

void backgroundDisplay(){
    glClearColor(0.0f,0.0f,0.0f,1.0f);
}

void reshapeFigure(int width, int height){
    glViewport(0,0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-25, 25, -25, 25);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Transformation");

    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFigure);
    backgroundDisplay();
    glutMainLoop();
    return 0;
}

