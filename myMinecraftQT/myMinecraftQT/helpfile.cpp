
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

using namespace sf;
using namespace std;

float size = 20.f;
float ax = 0, ay = 0;
float speed = 1;
float dx,dy,dz;
float PI = 3.14159265;

#define GL_CLAMP_TO_EDGE 0x812F

GLuint loadtexture(string str)
{
    GLuint texture = 0;
    {
        Image img;
        img.loadFromFile(str);
        img.flipVertically();
        //img.flipHorizontally();

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA,img.getSize().x, img.getSize().y,GL_RGBA, GL_UNSIGNED_BYTE, img.getPixelsPtr());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    return texture;
}

void drawcube(GLuint textures[], int size)
{
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glBegin(GL_QUADS);

    //back
    glTexCoord2f(0,0); glVertex3f(-size, -size, -size);
    glTexCoord2f(1,0); glVertex3f( size, -size, -size);
    glTexCoord2f(1,1); glVertex3f( size,  size, -size);
    glTexCoord2f(0,1); glVertex3f(-size,  size, -size);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glBegin(GL_QUADS);

    //front
    glTexCoord2f(0,0); glVertex3f( size, -size,  size);
    glTexCoord2f(1,0); glVertex3f(-size, -size,  size);
    glTexCoord2f(1,1); glVertex3f(-size,  size,  size);
    glTexCoord2f(0,1); glVertex3f( size,  size,  size);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glBegin(GL_QUADS);

    //left
    glTexCoord2f(0,0); glVertex3f(-size, -size,  size);
    glTexCoord2f(1,0); glVertex3f(-size, -size, -size);
    glTexCoord2f(1,1); glVertex3f(-size,  size, -size);
    glTexCoord2f(0,1); glVertex3f(-size,  size,  size);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glBegin(GL_QUADS);

    //right
    glTexCoord2f(0,0); glVertex3f( size, -size, -size);
    glTexCoord2f(1,0); glVertex3f( size, -size,  size);
    glTexCoord2f(1,1); glVertex3f( size,  size,  size);
    glTexCoord2f(0,1); glVertex3f( size,  size, -size);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glBegin(GL_QUADS);

    //bottom
    glTexCoord2f(0,0); glVertex3f(-size, -size,  size);
    glTexCoord2f(1,0); glVertex3f( size, -size,  size);
    glTexCoord2f(1,1); glVertex3f( size, -size, -size);
    glTexCoord2f(0,1); glVertex3f(-size, -size, -size);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glBegin(GL_QUADS);

    //top
    glTexCoord2f(0,0); glVertex3f(-size,  size, -size);
    glTexCoord2f(1,0); glVertex3f( size,  size, -size);
    glTexCoord2f(1,1); glVertex3f( size,  size,  size);
    glTexCoord2f(0,1); glVertex3f(-size,  size,  size);
    glEnd();


}

void keyboardtrack()
{
    if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::A))
    {
        dx = -sin(ax/180*PI) * speed;
        dz = -cos(ax/180*PI) * speed;

        dx = (dx + sin((ax-90)/180*PI) * speed)/2;
        dz = (dz + cos((ax-90)/180*PI) * speed)/2;
    }
    else if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::D))
    {
        dx = -sin(ax/180*PI) * speed;
        dz = -cos(ax/180*PI) * speed;

        dx = (dx + sin((ax+90)/180*PI) * speed)/2;
        dz = (dz + cos((ax+90)/180*PI) * speed)/2;

    }
    else if (Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::A))
    {
        dx =  sin(ax/180*PI) * speed;
        dz =  cos(ax/180*PI) * speed;

        dx = (dx + sin((ax-90)/180*PI) * speed)/2;
        dz = (dz + cos((ax-90)/180*PI) * speed)/2;
    }
    else if (Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::D))
    {
        dx =  sin(ax/180*PI) * speed;
        dz =  cos(ax/180*PI) * speed;

        dx = (dx + sin((ax+90)/180*PI) * speed)/2;
        dz = (dz + cos((ax+90)/180*PI) * speed)/2;
    }
    else if (Keyboard::isKeyPressed(Keyboard::W))
    {
        dx = -sin(ax/180*PI) * speed;
        //dy =  tan(ay/180*PI) * speed;
        dz = -cos(ax/180*PI) * speed;
    }
    else if (Keyboard::isKeyPressed(Keyboard::S))
    {
        dx =  sin(ax/180*PI) * speed;
       // dy = -tan(ay/180*PI) * speed;
        dz =  cos(ax/180*PI) * speed;
    }
    else if (Keyboard::isKeyPressed(Keyboard::A))
    {
        dx = sin((ax-90)/180*PI) * speed;
        dz = cos((ax-90)/180*PI) * speed;
    }
    else if (Keyboard::isKeyPressed(Keyboard::D))
    {
        dx = sin((ax+90)/180*PI) * speed;
        dz = cos((ax+90)/180*PI) * speed;
    }
    else
    {
        dx = 0;
        dz = 0;
    }
    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
      //  dy = speed * 2;
    }
}
