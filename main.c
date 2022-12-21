/*
 * File:   main.c
 * Author: Phil Glazzard
 * MPLABX IDE v6.00
 * XC8 v2.36
 * Optimisations 0
 *
 * Created on 11 December 2022, 18:23
 * 
 * * *                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
    DOWN BUTTON  2 |RA5   RA0| 19   
 *    UP BUTTON  3 |RA4   RA1| 18   
      MCLR       4 |RA3      | 17  
 *               5 |RC5   RC0| 16 
 *               6 |RC4   RC1| 15  
 *               7 |RC3   RC2| 14  
 *               8 |RC6   RB4| 13  SDA
  DIAGNOSTIC LED 9 |RC7   RB5| 12  ENT BUTTON
 *    TX        10 |RB7   RB6| 11  SCL
 *                  ---------
 * 
 */


#include <xc.h>
#include "config.h"
#include "constants.h"
#include "configOsc.h"
#include "configPins.h"
#include "configSPI.h"
#include "configEUSART.h"
#include "configBaud.h"
#include "configPCD8544.h"
#include "clearPCD8544.h"
#include "setAddress.h"
#include "writeCommand.h"
#include "writeData.h"
#include "select0To47.h"
#include <math.h>
void main(void) 
{
    float gradient;
    uint8_t sl;
    uint8_t col = 0;
    uint8_t row = 0;
    pageToRow ypixel;
    uint8_t sum = 0;
    float radius;
    float theta = 0.707107;
    configOsc();
    configPins();
    configSPI();
    configEUSART();
    configBaud();
    printf("hello Phil\n");
    configPCD8544();
    __delay_ms(1000);
   clearPCD8544();

   /*  setAddress(0,0);    // col, page
     writeCommand(0x20); //horizontal addressing
     for(row = 0; row <8; row++)
     {
            writeData(0x01<<row);
     }*/
  /* for(row = 0; row < 48; row++)  //draws a straight line from col =0 row = 0 to col = 47 row = 47
   {
       
        select0To47(row, &ypixel);  // gets value of page (0 - 5) and position of vertical pixel(0x01 - 0x80)
        writeCommand(0x22); //horizontal addressing
        setAddress(col,ypixel.page);
      //  sum = ypixel.byte | sum;
        //writeData(sum);
        writeData(ypixel.byte);
        col = col + 1;
   }*/
  // for(theta = 2.0; theta < 4.25; theta = theta + 0.01)
  /* for(theta = 0; theta < 6.5; theta = theta + 0.01)
   {
    col = 42 + ((float)radius * sin(theta));
    row = 26 + ((float)radius * cos(theta));
       
       
       //col = col*cos(theta) - row*sin(theta);
       //row = col*cos(theta) + row*sin(theta);
    select0To47(row, &ypixel);
    writeCommand(0x22); //horizontal addressing
    setAddress(col,ypixel.page);
    writeData(ypixel.byte);
   }*/
   
   for(radius = 0; radius <50; radius = radius + 1)
   {
    col = 42 + ((float)radius * sin(theta));
    row = 0 + ((float)radius * cos(theta));
       
       
       //col = col*cos(theta) - row*sin(theta);
       //row = col*cos(theta) + row*sin(theta);
    select0To47(row, &ypixel);
    writeCommand(0x22); //horizontal addressing
    setAddress(col,ypixel.page);
    writeData(ypixel.byte);
   }
   
    while(1)
    {
        /*LATCbits.LATC4 = HI;
        __delay_ms(50);
        LATCbits.LATC4 = LO;
        __delay_ms(50);*/
        
    }
    
}
