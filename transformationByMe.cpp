/*
UEA - Universidade do Estado do Amazonas
EST - Escola Superior de Tecnologia
Computação Gráfica e Processamento Digital de Imagens
E-mail: ldsllm.eng@uea.edu.br
*/
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926
using namespace std;

float convertDeg(float degrees){
    return (2.0f * degrees * PI)/(360);
}


float * rotate_Z_plane(float degrees = 0, float x = 0, float y = 0, float z = 0){
    float * result = new float(3);
    for(int i = 0; i < 3; i++){
        result[i] = 0.0;
    }
    if(degrees == 0) {
        return result;
    }
    result[0] = (x*cos(convertDeg(degrees))) - (y*sin(convertDeg(degrees)));
    result[1] = (x*sin(convertDeg(degrees))) + (y*cos(convertDeg(degrees)));
    result[2] = z;
    return result;
}


void squareTranslated(float distance_to_origin_x, float distance_to_origin_y, float translation_x, float translation_y, float degrees = 0){
    float * resultPointSquare1 = rotate_Z_plane(degrees, -distance_to_origin_x, distance_to_origin_y);
    float * resultPointSquare2 = rotate_Z_plane(degrees, -distance_to_origin_x, -distance_to_origin_y);
    float * resultPointSquare3 = rotate_Z_plane(degrees, distance_to_origin_x, -distance_to_origin_y);
    float * resultPointSquare4 = rotate_Z_plane(degrees, distance_to_origin_x, distance_to_origin_y);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-distance_to_origin_x+(translation_x)+(resultPointSquare1[0]), distance_to_origin_y+(translation_y)+resultPointSquare1[1]);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-distance_to_origin_x+(translation_x)+(resultPointSquare2[0]),-distance_to_origin_y+(translation_y)+resultPointSquare2[1]);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(distance_to_origin_x+(translation_x)+(resultPointSquare3[0]),-distance_to_origin_y+(translation_y)+resultPointSquare3[1]);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(distance_to_origin_x+(translation_x)+(resultPointSquare4[0]),distance_to_origin_y+(translation_y)+resultPointSquare4[1]);
    glEnd();
}

void squareScaled(float distance_to_origin_x, float distance_to_origin_y, float distance_to_origin_z, float scale_x, float scale_y, float scale_z){
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-distance_to_origin_x*(scale_x), distance_to_origin_y*(scale_y), distance_to_origin_z*(scale_z));
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-distance_to_origin_x*(scale_x),-distance_to_origin_y*(scale_y), distance_to_origin_z*(scale_z));
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(distance_to_origin_x*(scale_x),-distance_to_origin_y*(scale_y), distance_to_origin_z*(scale_z));
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(distance_to_origin_x*(scale_x),distance_to_origin_y*(scale_y), distance_to_origin_z*(scale_z));
    glEnd();
}


void circleTranslated(float r, int quantity, float centerX, float centerY, float translation_x, float translation_y, float degrees = 0){
    glBegin(GL_POLYGON);
    for( int i = 0; i < quantity; i++){
        float theta = (2.0f * PI * float(i)) / (float(100));
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        if(i < 150){
            glColor3f(0.0f, 1.0f, 0.0f);
            float * resultRotateCircle1 = rotate_Z_plane(degrees, x+centerX, y+centerY);
            glVertex2f(x + centerX+(translation_x)+(resultRotateCircle1[0]), y + centerY+(translation_y)+(resultRotateCircle1[1]));
            resultRotateCircle1 = rotate_Z_plane(0, 0 ,0);
        }
        else{
            float * resultRotateCircle2 = rotate_Z_plane(degrees, x+centerX, y+centerY);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(x + centerX+(translation_x)+(resultRotateCircle2[0]), y + centerY+(translation_y)+(resultRotateCircle2[1]));
            resultRotateCircle2 = rotate_Z_plane(0, 0, 0);
        }
        
    }
    glEnd();
}

void circleScaled(float r, int quantity, float centerX, float centerY, float centerZ, float scale_x, float scale_y, float scale_z){
    glBegin(GL_POLYGON);
    for( int i = 0; i < quantity; i++){
        float theta = (2.0f * PI * float(i)) / (float(100));
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        if(i < 150){
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f((x + centerX)*(scale_x), (y + centerY)*(scale_y), (0.0+centerZ)*(scale_z));
        }
        else{
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f((x + centerX)*(scale_x), (y + centerY)*(scale_y),(0.0+centerZ)*(scale_z));
        }    
    }
    glEnd();
}
    

void triangleTranslated(float distance_to_origin_x, float distance_to_origin_y, float translation_x, float translation_y, float degrees = 0){
    float * resultPointTriangle1 = rotate_Z_plane(degrees, 3*distance_to_origin_x, distance_to_origin_x + distance_to_origin_y);
    float * resultPointTriangle2 = rotate_Z_plane(degrees, 2*distance_to_origin_x, distance_to_origin_y);
    float * resultPointTriangle3 = rotate_Z_plane(degrees, 4*distance_to_origin_x, distance_to_origin_y);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    // quarto parâmetro da função acima modifica a transparência
    glVertex2f(3*(distance_to_origin_x)+(translation_x)+(resultPointTriangle1[0]), distance_to_origin_x + distance_to_origin_y+(translation_y)+(resultPointTriangle1[1]));
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(2*distance_to_origin_x+(translation_x)+(resultPointTriangle2[0]), distance_to_origin_y+(translation_y)+(resultPointTriangle2[1]));
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(4*distance_to_origin_x+(translation_x)+(resultPointTriangle3[0]), distance_to_origin_y+(translation_y)+(resultPointTriangle3[1]));    
    glEnd();
}


void triangleScaled(float distance_to_origin_x, float distance_to_origin_y, float distance_to_origin_z, float scale_x, float scale_y, float scale_z){
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    // quarto parâmetro da função acima modifica a transparência
    glVertex3f(3*distance_to_origin_x*(scale_x), (distance_to_origin_x + distance_to_origin_y)*(scale_y), (distance_to_origin_z)*(scale_z));
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(2*distance_to_origin_x*(scale_x), (0.0+distance_to_origin_y)*(scale_y), (distance_to_origin_z)*(scale_z));
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(4*distance_to_origin_x*(scale_x), (0.0+distance_to_origin_y)*(scale_y), (distance_to_origin_z)*(scale_z));    
    glEnd();
}


void translation(float x, float y){ // translação somente no plano x, y
    circleTranslated(2.2567583342, 300, -12.0,0.0, x, y);
    squareTranslated(2.0,2.0, x, y);
    triangleTranslated(4.0, 0.0, x, y);
}

void scale(float x, float y, float z){
    circleScaled(2.2567583342, 300, -12.0,0.0,0.0, x, y, z);
    squareScaled(2.0,2.0,0.0, x, y, z);
    triangleScaled(4.0, 0.0,0.0, x, y, z);
}

void rotation(float degrees, float x, float y){
    circleTranslated(2.2567583342, 300, -12.0,0.0, x, y, degrees);
    squareTranslated(2.0,2.0, x, y, degrees);
    triangleTranslated(4.0, 0.0, x, y, degrees);
}


void display () {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    translation(5.0, 5.0);
    // scale(1.5, 3, 0.0);
    // scale(1, -1, 1); // reflexão
    // rotation(60, 0, 0); // rotação de 60 no eixo Z.

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

