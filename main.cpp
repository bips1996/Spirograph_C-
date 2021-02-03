//An openGl program to implement a Spirograph toy both in Anticlockwise and Clockwise direction
//18MCMC05 BIPLABA SAMANTARAY

#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<GL/glut.h>
float R , r , p;
void init(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,800.0,0.0,500.0);
}

//Function to draw line between two given vertex
void Drawline(float x,float y, float x1,float y1,float t)
{

    if(t<3 || (t> 12 && t<15) || (t> 21 && t<24)|| (t> 30 && t<33) )
    {
        glColor3f(1.0,0.0,0.0);
    }
    else if(t<6 || (t>= 15 && t<18) || (t>= 24 && t<27)|| (t>= 33 && t<36) )
    {
        glColor3f(0.0,1.0,0.0);
    }
    else if(t<9 || (t>= 18 && t<21) || (t>= 27 && t<30)|| (t>= 36 && t<39) )
    {
        glColor3f(0.0,0.0,1.0);
    }
    else
    {
        glColor3f(1.0,0.0,0.0);
    }

    glBegin(GL_LINES);
    glVertex2f(x,y);
    glVertex2f(x1,y1);
    glEnd();
    glutSwapBuffers();

}

void spirograph(void)
{

    //INITIALISATION FOR BOTH CLOCK WISE AND ANTICLOCKWISE

        float t = 0.0, t2=200;
        float x = 0.0f, y = 0.0f , x1 = 0.0f, y1 = 0.0f,xa=0.0f,ya=0.0f,x1a=0.0f,y1a=0.0f, s= 0.0001 * r;
        x1 = (R - r)*cos(t) + p*cos(((R - r) / r)*t);
        y1 = (R - r)*sin(t) - p*sin(((R - r) / r)*t);

        x1a = (R - r)*cos(t2) + p*cos(((R - r) / r)*t2);
        y1a = (R - r)*sin(t2) - p*sin(((R - r) / r)*t2);


    for (t = 0.00 ; t<200; t+=s)
    {
        //CLOCK WISE SPIROGRAPH LEFT SIDE
            x = (R - r)*cos(t) + p*cos(((R - r) / r)*t);
            y = (R - r)*sin(t) - p*sin(((R - r) / r)*t);
            Drawline(200+x,250+y,200+x1,250+y1,t);
            x1 = x;
            y1 = y;

        //ANTICLOCK WISE SPIROGRAPH RIGHT SIDE
            xa=(R - r)*cos(t2) + p*cos(((R - r) / r)*t2);
            ya = (R - r)*sin(t2) - p*sin(((R - r) / r)*t2);
            Drawline(600+xa,250+ya,600+x1a,250+y1a,t);
            x1a=xa ;
            y1a=ya ;
            t2=t2-s ;
    }
    glFlush();
}

int main(int argc,char **argv)
{
    std::cout<<"\n\n\t\t\t\t+++++++++++++++++++++++++++++++";
    std::cout<<"\n\t\t\t\t\tSpirograph Design\n";
    std::cout<<"\t\t\t\t+++++++++++++++++++++++++++++++\n";

    std::cout<<"\n\t\tEnter the radius of ring(R):";
    std::cin>>R;

    std::cout<<"\n\t\tEnter the radius of wheel(r):";
    std::cin>>r;

    std::cout<<"\n\t\tEnter the distance of a point from the radius of the wheel(p):";
    std::cin>>p;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,500);
    glutCreateWindow("Spirograph");
    init();
    glutDisplayFunc(spirograph);
    glutMainLoop();
    return 0;
}


