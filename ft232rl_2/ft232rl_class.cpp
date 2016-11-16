#include "ft232rl_class.h"
#include <windows.h>
#include "ftd2xx.h"
#include<QThread>
#include<QDebug>
#include <bitset>

//#define LED 0
//#define BUT 3
#define MODE 0x04
#define LED0 0x00
#define LED1 0x01

QString ft232rl_class::maininmainwindow()
{


    port = 0;
    statePort = 0;
    count = 0;
    buf = 0;
    numBytes = 0;
    LED = 0;
    BUT = 3;

    refresh("FTDI Bit Bang mode-----\n");

    if(FT_Open(0, &handle) != FT_OK) {
       refresh("Can't open device\n");

    }
    else{
        refresh("Device is open\n");

       //установить направление выводов и режим бит банга
       //FT_SetBitMode(handle, ((1<<LED)|(0<<BUT)), 0x04);


        /* FT_SetBitMode(handle, ((1<<LED0)|(1<<LED1)|(0<<BUT)), 0x04);*/
       FT_SetBitMode(handle, (1023), 0x04);


       //запись и чтение ft232rl

          //if(stopbit==1){stopbit=0;FT_Close (&handle);break;}
          //FT_Read(handle, &statePort,1, &numBytes);
          //FT_SetBitMode(handle, ((1<<LED0)|(0<<BUT)), 0x04);

       while (1){

     /*      FT_Write(handle, &port, 1, &numBytes);
           port = (1<<LED0);

           this->thread()->usleep(TIME);

           FT_Write(handle, &port, 1, &numBytes);
           port = (1<<LED1);

           this->thread()->usleep(TIME);//22000);//TIME);*/
           //TIME = rand()%10;
          std::bitset<8> bits(TIME);
          std::bitset<8> bits2;
           bits2[3]=bits[0];
           bits2[6]=bits[1];
           bits2[5]=bits[2];
           bits2[7]=bits[3];
           bits2[1]=bits[4];/// у FT непоследовательная распиновка
           bits2[2]=bits[5];
           bits2[4]=bits[6];
           bits2[0]=bits[7];


           port = bits2.to_ulong();//bits.to_ulong();
           FT_Write(handle, &port, 1, &numBytes);



          // this->thread()->usleep(TIME);
          // port = TIME;
           //  FT_Write(handle, &port, 1, &numBytes);


        }
       return "77";
    }
    refresh("Function end.----\n");
}

void ft232rl_class::maininmainwindow_control()
{
    refresh(maininmainwindow());
}




//void QThread::usleep ( unsigned long usecs );
//usleep(10);

// Sleep();
/* if (statePort & (1<<BUT)){
   port &= ~(1<<LED);
   count = 0;
}
else{
      port |= (1<<LED);
      count++;

      //если кнопка удерживается долго,
      //выходим из цикла
      if (count > 2000){
         FT_Close (&handle);
         refresh("Device is close.\n");
         break;
     }

  }*/
void ft232rl_class::swich_of()
{
    stopbit=1;
}

void ft232rl_class::TIME_changed()
{
    port = TIME;
    FT_Write(handle, &port, 1, &numBytes);
}


void ft232rl_class::setupthread(QThread &thread)
{
    connect(&thread,SIGNAL(started()),this,SLOT(maininmainwindow_control()));
}

ft232rl_class::~ft232rl_class()
{

    FT_SetBitMode(handle, ((1023)), 0x04);
    port =0;
    FT_Write(handle, &port, 1, &numBytes);
    //FT_Read(handle, &statePort,1, &numBytes);

    //port |= (1<<LED0);

    FT_Close (&handle);
}

ft232rl_class::ft232rl_class(QObject *parent) : QObject(parent)
{
    stopbit = 0;
    TIME = 255;
   // maininmainwindow();
}

/*    unsigned char port = 0;
     unsigned char statePort = 0;
     unsigned int count = 0;
     char buf = 0;
     DWORD numBytes = 0;
     FT_HANDLE handle;*/
