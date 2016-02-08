#include "Vertex.h"
#include "Edge.h"
#include "Triangle.h"
#include "FileReader.h"
#include <iostream>

/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main.c for mesh-simplifier
 *
 *        Version:  1.0
 *        Created:  01/30/2016 12:04:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

// main.cpp

#include <QApplication>
#include <QDesktopWidget>
#include "Graphicobject.h"
#include "window.h"

int main(int argc, char *argv[])
{
    //Read in a File
    FileReader fileReader;
    fileReader.readFile("test.obj");


    QApplication app(argc, argv);
    Graphicobject foo;
    Window window;
    window.resize(window.sizeHint());
        
    Vertex p1(-1,-1,0);
       	Vertex p2(1,-1,0);
        Vertex p3(0,0,1.2);
	Edge e1(&p1,&p2);
	Edge e2(&p2,&p3);
	Edge e3(&p3,&p1);
	Triangle tri1(&e1, &e2, &e3, &p1, &p2, &p3);
	tri1.setNormal(0, -1, 0.707);
        
	//glNormal3f(1,0, 0.707);
        //p2: Vertex p4(1,-1,0);
        Vertex p4(1,1,0);
        //p3: glVertex3f(0,0,1.2);
	Edge e4(&p4, &p2);
	Edge e5(&p4, &p3);
	Triangle tri2(&e2, &e4, &e5, &p2, &p3, &p4);
	tri2.setNormal(1,0,0.707);
    /*glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(0,1,0.707);
        glVertex3f(1,1,0);
        glVertex3f(-1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(-1,0,0.707);
        glVertex3f(-1,1,0);
        glVertex3f(-1,-1,0);
        glVertex3f(0,0,1.2);
    */
	foo.addTriangle(&tri1);
	foo.addTriangle(&tri2);
    int desktopArea = QApplication::desktop()->width() *
                     QApplication::desktop()->height();
    int widgetArea = window.width() * window.height();
    window.setGraphic(&foo);
    window.setWindowTitle("OpenGL with Qt");

    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        window.show();
    else
        window.showMaximized();
    return app.exec();
}

