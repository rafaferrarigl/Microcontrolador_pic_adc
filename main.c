#include <16f877a.h>
#device ADC = 10
#FUSES XT, NOWDT
#use delay(clock=2M)
#use standard_io(D)

#define LCD_DB4   PIN_D4         // Pines de la pantalla LCD
#define LCD_DB5   PIN_D5
#define LCD_DB6   PIN_D6
#define LCD_DB7   PIN_D7
#define LCD_RS    PIN_D2
#define LCD_E     PIN_D3

#include <lcd.c>            // Libreria para el manejo de la pantalla LCD
#include "map_function.c" 


float valor_adc;
float valor_res;

void main()
{
   lcd_init();
   setup_adc_ports(AN0);
   setup_adc(adc_clock_internal);
   while(TRUE)
   {
      set_adc_channel(0);
      
      valor_adc = read_adc();
      valor_res = 5* valor_adc/1024;
      
      //printf(lcd_putc, "\fADC = %4ld",valor_adc);
      lcd_gotoxy(1,1);
      printf(lcd_putc,"PWM: %f ",valor_adc);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Tension: %01.2fV ",valor_res);
      
   }

}
