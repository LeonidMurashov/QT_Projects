#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace sf;

const int DW = 1080;
const int DH = 720;
const int MAXINT = 9999999999999;
const float G = 980;

int ground[DW];

Image img2;

struct Circle
{
    float x, y, r, dx, dy, Stofally, Stofallx, Stofall;
    POINT fp1, fp2;
    bool nopushes;
    CircleShape circle;

    bool tick(float time)
    {

        float dxy = sqrt(dx*dx + dy*dy);
        findfallpoints();
        if(Stofall>dxy*time - (G*time*time)/2)
        {
            x+=dx*time;
            y+=dy*time - (G*time*time)/2;
            if(dy == 0)nopushes = false;
            dy-=G*time;
            circle.setPosition(x,DH-y);
            return true;
        }
        else
        {
            float dtime = max((-dxy + sqrt(dxy*dxy + 2*G*Stofall))/G,(-dxy - sqrt(dxy*dxy + 2*G*Stofall))/G);
            x+=dx*dtime;
            y+=dy*dtime;
            dy-=G*dtime;

            float bb = sqrt((-fp1.x)*(-fp1.x) + (fp1.y-2*fp2.y)*(fp1.y-2*fp2.y))/sqrt((fp1.x-fp2.x)*(fp1.x-fp2.x) + (fp1.y-fp2.y)*(fp1.y-fp2.y));
            float alfa = 90 - acos(bb) - acos(dy/dxy);
            dx = dx*cos(180-2*alfa) - dy*sin(180-2*alfa);
            dy = dx*sin(180-2*alfa) + dy*cos(180-2*alfa);

            nopushes = false;

            return false;
        }
    }

    void findfallpoints()
    {
        int min = MAXINT, min2 = MAXINT, maxh2 = -MAXINT, maxh = -MAXINT, i;
        int from=0, to=DW;
        float alfa = 90 + atan(dy/dx);
        float xsh = cos(alfa-90)*r+x+r;//, ysh = sin(alfa-90)*r+y-r;
        float xsh2 = xsh + 2*(x+r-xsh);//, ysh2 = ysh + 2*(y+r-ysh);
        if(xsh != xsh || xsh2 != xsh2){Stofall = MAXINT; circle.setFillColor(Color(rand(), rand(), rand())); return;}
        for(i = xsh; i<DW; i++)
        {
            int chek = ceil((-1*(i-xsh) * cos(alfa-90))/sin(alfa-90));
            if(ground[i]==chek || ground[i]==chek-1)
            {
                from = i;
                break;
            }
        }

        for(i;i<DW; i++)
        {
            int chek = ceil((-1*(i-xsh2) * cos(alfa-90))/sin(alfa-90));
            if(ground[i]==chek || ground[i]==chek-1)
            {
                to = i;
                break;
            }
        }
       // float sinalfa = sin(atan(dx/dy)), cosalfa = cos(atan(dx/dy));
         float sinalfa = sin(alfa), cosalfa = cos(alfa);
        for(int j = from; j<to; j++)
        {
            float y1 = j*sinalfa-ground[j]*cosalfa; //вокруг чего вращается - вокруг 0;0

            if(maxh2<y1)
            {
                if(maxh<y1){maxh = y1; min = j;}
                else
                {
                    maxh2 = y1;
                    min2 = j;
                }
            }
        }

        //float x1 = min2*cosalfa - ground[min2]*sinalfa;//, polxc = (x+r)*cosalfa - (y-r)*sinalfa, polyc = (x+r)*sinalfa + (y-r)*cosalfa;
        //float poly=; // получаю полярный y
        ///пробное
        ///

        if(min2>DW-1 || min2<0){Stofall = MAXINT; circle.setFillColor(Color(rand(), rand(), rand())); return;}
        Stofallx = min2-x+r;
        Stofally = ground[min2]-r;



        Stofall = sqrt(Stofallx*Stofallx + Stofally*Stofally);
        ///--
        if(min2 != MAXINT && min>=0 && min<DW && min2>=0 && min2<DW)
        {
            //fp1 = {min, ground[min]};

            img2.setPixel(fp1.x, DH-fp1.y, Color(0,0,0,0));
            img2.setPixel(fp2.x, DH-fp2.y, Color(0,0,0,0));


            fp1.x = min;  fp1.y = ground[min];
            fp2.x = min2; fp2.y = ground[min2];

            img2.setPixel(fp1.x, DH-fp1.y, Color::Red);
            img2.setPixel(fp2.x, DH-fp2.y, Color::Blue);

            //fp2 = {min2, ground[min2]};
        }
        nopushes = true;

    }

    Circle(float _x, float _y, float _r)
    {
        x = _x;
        y = _y;
        r = _r;
        circle.setRadius(r);
        circle.setPosition(x,y);
        circle.setFillColor(Color::Green);
        dx = dy = 0.000000001;
        nopushes = false;
        fp1.x = 0; fp1.y = 0;
        fp2.x = 0; fp2.y = 0;
    }
};

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(DW, DH), "My Minecraft with QT"); // , Style::Fullscreen);

    start:
    vector <Circle*> balls;


    Image im;  im.loadFromFile("D:\\QT_projects\\myMinecraftQT\\myMinecraftQT\\resources\\heightmap2.png");

     int r = rand()%2048, r2 = rand()%(2048-DW);
     for(int i=0;i<DW;i++)
     {
         int c = im.getPixel(i+r2,r).r;
          ground[i]=c+10;
     }

    img2.create(DW,DH,Color(0,0,0,0));
    Image img;
    img.create(DW, DH,Color::White);
    for(int i =0; i<DW; i++)
        img.setPixel(i,(ground[i]-DH)*-1,Color::Black);
    Texture t;
    t.loadFromImage(img);
    Sprite background;
    background.setTexture(t);



    Clock clock, clock2;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        time = 0.001;///1000;

        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed) window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();
        if (Keyboard::isKeyPressed(Keyboard::P))
            time = 0;
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            while(!balls.empty()){delete balls[balls.size()-1];balls.pop_back();}
            goto start;
        }
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if(clock2.getElapsedTime().asMilliseconds()>100)
            {
                float rad = rand()%70;
                balls.push_back(new Circle(Mouse::getPosition().x - window.getPosition().x-rad, DH-(Mouse::getPosition().y - window.getPosition().y-rad), rad));
              // balls.push_back(new Circle(Mouse::getPosition().x-window.getPosition().x-rad, 100, rad));
                // balls.push_back(new Circle(Mouse::getPosition().x - window.getPosition().x - rad*6, Mouse::getPosition().y - window.getPosition().y-rad/2, rad*2));
               // balls[balls.size()-1]->dy=10000;
                clock2.restart();
            }
        }

        for(unsigned int i = 0; i<balls.size(); i++)balls[i]->tick(time);
        window.clear(Color(255,255,255,0));
        window.draw(background);
        for(unsigned int i = 0; i<balls.size(); i++)window.draw(balls[i]->circle);
        window.display();
    }
    return 0;
}

