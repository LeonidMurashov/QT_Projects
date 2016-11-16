#include <SDL.h>

#undef main

#include <QtCore/QDebug>

QT_USE_NAMESPACE

int main(int argc, char *argv[])
{
    // Переменная для нашего джойстика
    SDL_Joystick *joy;
    SDL_Event event;

    // Инициализация SDL для использования джойстика
    SDL_Init(SDL_INIT_JOYSTICK);
    // Включаем
    SDL_JoystickEventState(SDL_ENABLE);
    // Открываем ;)
    joy = SDL_JoystickOpen(0);

    while(1)
    {
        // Примитивнейшая задержка
        unsigned int j = 0;
        for (j = 0; j < 60000; j++);

        SDL_PollEvent(&event);

        // Получаем значения, соответствующие смещению джойстика
        // по оси Х
        int xAxis = SDL_JoystickGetAxis(joy, 0);
        // по оси Y
        int yAxis = SDL_JoystickGetAxis(joy, 1);

        // Выводим
        qDebug() << xAxis << yAxis;
    }
}

/*
#include <iostream>
#include <SDL_/include/SDL.h>
using namespace std;

#undef main

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface* screen;
    screen = SDL_SetVideoMode(600,600,32,SDL_SWSURFACE);
    SDL_Delay(3000);
    SDL_FreeSurface(screen);
    SDL_Quit();
    cout << "Hello World!" << endl;
    return 0;
}*/
/*#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
*/
