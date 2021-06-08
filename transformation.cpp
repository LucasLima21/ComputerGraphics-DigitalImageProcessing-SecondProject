#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void display () {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_POLYGON);
    float cx = -12.0, cy = 0.0; // posições x e y
    float r = 2.2567583342;    // raio equivalente da mesma area das outras figuras raizQuadrada(16/pi)
    for( int i = 0; i < 300; i++){
        float theta = (2.0f * 3.1415926 * float(i)) / (float(100));
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-2.0, 2.0);
    glVertex2f(-2.0,-2.0);
    glVertex2f(2.0,-2.0);
    glVertex2f(2.0,2.0);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    // quarto parâmetro da função acima modifica a transparência
    glVertex2f(12.0, 4.0);
    glVertex2f(8.0, 0.0);
    glVertex2f(16.0, 0.0);
    
    glEnd();



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

