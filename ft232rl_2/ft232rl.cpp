#include "ft232rl.h"
#include <windows.h>
#include "ftd2xx.h"

#define LED 0
#define BUT 3
#define MODE 0x04

void ft232rl::maininmainwindow()
{
   unsigned char port = 0;
    unsigned char statePort = 0;
    unsigned int count = 0;
    char buf = 0;
    DWORD numBytes = 0;
    FT_HANDLE handle;

    emit refresh("FTDI Bit Bang mode\n");

    if(FT_Open(0, &handle) != FT_OK) {
      emit refresh("Can't open device\n");

    }
    else{
       emit refresh("Device is open\n");

       //установить направление выводов и режим бит банга
       FT_SetBitMode(handle, ((1<<LED)|(0<<BUT)), MODE);

       //запись и чтение ft232rl
       for(;;) {

          FT_Write(handle, &port, 1, &numBytes);
          FT_Read(handle, &statePort,1, &numBytes);

          if (statePort & (1<<BUT)){
             port &= ~(1<<LED);
             count = 0;
          }
          else{
                port |= (1<<LED);
                count++;

                //если кнопка удерживается долго,
                //выходим из цикла
                if (count > 200){
                   FT_Close (&handle);
                   emit refresh("Device is close.\n");
                   break;
               }

            }

        }
    }/*
    QEventLoop loop;
    int ab=0;
    for(;;){cout(QString::number(ab)); loop.exit();ab++;}*/
}


ft232rl::ft232rl()
{
    maininmainwindow();
}
