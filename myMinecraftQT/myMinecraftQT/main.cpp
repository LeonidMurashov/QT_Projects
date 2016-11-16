
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include<math.h>
#include "helpfile.cpp"

using namespace sf;
using namespace std;

#define DW 1920
#define DH 1080

bool earth[1000][1000][1000];


struct human
{

    float x,y,z;
    void phisics()
    {

    }
    human()
    {
        x = 0;
        y = size*4;
        z = 0;
    }

};

bool check(int i, int j, int o)
{
    if(i>-1 && i<1000 && j>-1 && j<1000 && o>-1 && o<1000) return true;
    else return false;
}

int main()
{

    RenderWindow window(VideoMode(DW, DH), "My Minecraft with QT");

    Texture background;
    background.loadFromFile("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\background.jpg");

    GLuint blocktexture[6];
    blocktexture[0] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\side.jpg");
    blocktexture[1] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\side.jpg");
    blocktexture[2] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\side.jpg");
    blocktexture[3] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\side.jpg");
    blocktexture[4] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\bottom.jpg");
    blocktexture[5] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\top.jpg");

   /* GLuint skybox[6];
    skybox[0] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\side.jpg");
    skybox[1] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\side.jpg");
    skybox[2] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\side.jpg");
    skybox[3] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\side.jpg");
    skybox[4] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\bottom.jpg");
    skybox[5] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\grassbox\\top.jpg");

   */
    /*GLuint skybox[6];
    /*  skybox[0] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_front.bmp");//front
    skybox[1] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_back.bmp");//back
    skybox[2] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_left.bmp");//left
    skybox[3] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_right.bmp");//right
    skybox[4] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_bottom.bmp");//bottom
    skybox[5] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_top.bmp");//top*/

    /**/ GLuint skybox[6];

    skybox[1] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_back.bmp");
    skybox[0] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_front.bmp");
    skybox[2] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_left.bmp");
    skybox[3] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_right.bmp");
    skybox[4] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_bottom.bmp");
    skybox[5] = loadtexture("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\skybox3\\skybox_top.bmp");
/**/

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClearDepth(1.f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 2000.f);
    glEnable(GL_TEXTURE_2D);

   /* for(int i = 0; i<1000; i++)
        for(int j = 0; j<1000; j++)
            for(int o = 0; o<1000; o++)
                earth[i][o][j] = 1;
*/
    Clock clock;
    human p;
    SetCursorPos(window.getPosition().x+DW/2,window.getPosition().y+DH/2);
    while(window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds() * 100;
        window.clear();


        ///////////обработка событий/////////////////////////////////
        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed) window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();

        keyboardtrack();

        ///////////обработка событий/////////////////////////////////


        p.x+=dx;
        p.y+=dy;
        p.z+=dz;

     //-----------------------
        POINT mousexy;
        GetCursorPos(&mousexy);
        int xt = window.getPosition().x+DW/2;
        int yt = window.getPosition().y+DH/2;

        ax += (xt - mousexy.x)/4;
        ay += (yt - mousexy.y)/4;

        if(ay<-89.0)ay = -89.0;
        if(ay> 89.0)ay =  89.0;

        SetCursorPos(xt,yt);

      //----------------------

        //window.pushGLStates();
        //window.draw(Sprite(background));
        //window.popGLStates();

        glClear(GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(p.x,p.y,p.z,p.x-sin(ax*PI/180), p.y+tan(ay*PI/180), p.z-cos(ax*PI/180),0,1,0);


       // glRotatef(time, 50, 50, 0);

       /* for(int i = p.x-10; i<p.x+10; i++)
            for(int j = p.z-10; j<p.z+10; j++)
                for(int o = p.y-50; o<p.y+50; o++)
                    if(check(i,o,j) && earth[i][o][j])
                    {
                        glTranslatef(p.x,p.y,p.z);glTranslatef(p.x,p.y,p.z);//glTranslatef(i*size*2,o*size*2, j*size*2);
                        drawcube(blocktexture, size);
                        glTranslatef(-p.x,-p.y,-p.z);//glTranslatef(-1*i*size*2,-1*o*size*2, -1*j*size*2);
                    }
*/


        glTranslatef(100,100,0);
        drawcube(blocktexture, size);
        glTranslatef(-100,-100,0);

        glTranslatef(p.x,p.y,p.z);        
        drawcube(skybox, 1000);
        glTranslatef(-p.x,-p.y,-p.z);

        window.display();
    }



    return 0;
}

