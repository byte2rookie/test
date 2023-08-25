/**
  ******************************************************************************
  * @file    main.c
  * 
  * 
  *     
  *   
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-ָ���� STM32 ������ 
  * 
  * 
  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
//#include "bsp_usart.h"
//#include "bsp_led.h"
//#include "orderlist.h"
//#include "bsp_pwm_led.h"
#include "bsp_ili9341_lcd.h"
#include "fonts.h"
#include "my_lcd.h"
//#include "delay.h"




/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
#if 1
int main(void)
{	
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  USART_Config();
	led_config();
  TIM_COM_config();
  TIM_COM2_config();
  start_LCD();//��Һ��
  LED_B(ON);//��Ʊ�ʾ�Ѿ���ʼ����(������չ�ɺ�����֮��ģ�)
  
  //�ϻ�����ͨ������һֱ����λ��������Ϣ��ֱ����λ����Ӧ
  //��������ȴ�ʱ����Զ��ر�
 extern uint32_t respon;
  uint8_t data_start;
  
  data_start=COMMUNICATION_REQUEST; //����һ�������ź�
  
  while(1)
  {
    Usart_SendByte(DEBUG_USARTx,data_start);
    respon=USART_ReceiveData(DEBUG_USARTx);   
  if(respon==SUCCESS_COMMUNICATION)
  {   
    LED_B(OFF)
    //����λ��ͨ�ųɹ�������Ƶ�
    LED_R(ON);
    delay_ms(100);
    LED_G(ON);
    break;
  }
  delay_ms(1000);
}      
   
while(1)
{
  	
    recongization_LCD();
    //respon = USART_ReceiveData(DEBUG_USARTx);  //�����������ظ����жϣ�
   
  
    //LCDչʾ���
    result_LCD(respon); 
                
  if(respon==SUCCESS_recognization)
    {  
      led_reset();
        openbox(GREENBOX);
        LED_G(ON);
      delay_ms(1000);      
      closebox(GREENBOX);
    }
  else if (respon==FALSE_recognization)
    { 
      led_reset();
      openbox(REDBOX);      
      LED_R(ON);
      delay_ms(1000);     
      closebox(REDBOX);
      }
  else if(respon==RESET_RECOGNIZATION)
    {                
      led_reset();      
      LED_G(ON);      
      LED_R(ON);
      LED_B(ON);
      delay_ms(100);      
    }	
  else if(respon==TURNOFF)
    {
      led_reset();
      openbox(GREENBOX);
      openbox(REDBOX);
      delay_ms(1000);
      closebox(REDBOX);
      closebox(GREENBOX);
      break;
    }
    respon=PAUSE;
}  
      
}
/*********************************************END OF FILE**********************/


#elif 0
int main(void)
{
led_config();
breathLED_B_config();
int i;
while(1)
{
for(;i<100;i++)
{
  pwm_set_compare(i);
    delay_ms(10);
}
for(i=100;i>0;i--)
{
  pwm_set_compare(i);
    delay_ms(10);
}}
}

#elif 0//�������������
int main(void)
{
TIM_COM_config();
TIM_COM2_config();
while(1)
  {
// SetRedbox(500);
//  delay_ms(1000);
// SetRedbox(2500);
//  delay_ms(1000);
// SetGreenbox(500);
//  delay_ms(1000);
// SetGreenbox(2500);
//  delay_ms(1000);   
    delay_ms(1000);   
    openbox(REDBOX);
    openbox(GREENBOX);
}
  //SetDJ3(1500);//ֹͣ��
 // SetDJ3(2500);
}

#elif 0
int main(void)//����һ��LCD��ʾ
{
  //1.LCD ��ʼ��
  ILI9341_Init ();
  //2.����Һ����Ԫָ���ɨ��ģʽ
  ILI9341_GramScan(LCD_SCAN_MODE);//Ĭ������Ҳ��6��ģʽ����һ������ʡ��
  //3.������ʾ����
  LCD_SetBackColor(GBLUE);
  ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* ��������ʾȫ�� */
  //�ȴ�������ʾ�����Կ���
  LCD_SetColors(BLACK,YELLOW);//��һ����ɫ
  LCD_SetFont(&Font8x16);//��һ���ֺ�  
  ILI9341_DispStringLine_EN(LINE(0),"hello!my deer friend!");
  delay_ms(500);
  ILI9341_DispStringLine_EN(LINE(1),"HERE IS .......");
  LCD_SetColors(WHITE,GREY);
  LCD_SetFont(&Font24x32);
  delay_ms(500);
  ILI9341_DispStringLine_EN(LINE(1),"   ZZY   ");
  LCD_SetFont(&Font8x16);
  LCD_SetColors(RED,GREEN);
  ILI9341_DispStringLine_EN(LINE(4),"   from UESTC   ");
  delay_ms(500);
  int flag=0;
  while(1)
  {
  ILI9341_DispStringLine_EN(LINE(5),"let's start the program!");
  delay_ms(1000);
    ILI9341_DispStringLine_EN(LINE(6),"the result of recognization:");
  delay_ms(1000);  
  if(flag)
  {
    LCD_SetColors(RED,GREEN);
     LCD_SetFont(&Font24x32);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* ��������ʾȫ�� */
    delay_ms(2000);
  ILI9341_DispStringLine_EN(LINE(4),"  PASS!   ");
  }
  else
  {
    LCD_SetColors(RED,GREEN);
     LCD_SetFont(&Font24x32);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* ��������ʾȫ�� */
    delay_ms(2000);
  ILI9341_DispStringLine_EN(LINE(4),"  DENIED!   ");
  }
   delay_ms(2000);
  LCD_SetFont(&Font8x16);
  LCD_SetColors(RED,GREEN);
  ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* ��������ʾȫ�� */
  
}
}


#endif
#if 0
void start_LCD(void)
{
  //1.LCD ��ʼ��
  ILI9341_Init ();
  //2.����Һ����Ԫָ���ɨ��ģʽ
  ILI9341_GramScan(LCD_SCAN_MODE);//Ĭ������Ҳ��6��ģʽ����һ������ʡ��
  //3.������ʾ����
  LCD_SetBackColor(GBLUE);
  ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* ��������ʾȫ�� */
  //�ȴ�������ʾ�����Կ���
  LCD_SetColors(BLACK,YELLOW);//��һ����ɫ
  LCD_SetFont(&Font8x16);//��һ���ֺ�  
  ILI9341_DispStringLine_EN(LINE(0),"hello!my deer friend!");
  delay_ms(500);
  ILI9341_DispStringLine_EN(LINE(1),"HERE IS .......");
  LCD_SetColors(WHITE,GREY);
  LCD_SetFont(&Font24x32);
  delay_ms(500);
  ILI9341_DispStringLine_EN(LINE(1),"   ZZY   ");
  LCD_SetFont(&Font8x16);
  LCD_SetColors(RED,GREEN);
  ILI9341_DispStringLine_EN(LINE(4),"   from UESTC   ");
  delay_ms(500);
  int flag=0;
  
}

void recongization_LCD(void)
{
ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);
  ILI9341_DispStringLine_EN(LINE(5),"let's start the program!");
  delay_ms(1000);
  ILI9341_DispStringLine_EN(LINE(6),"the result of recognization:");
  delay_ms(1000);  
}


void result_LCD(int flag)
{

    
  if(flag==SUCCESS_recognization)
  {
    LCD_SetColors(RED,GREEN);
     LCD_SetFont(&Font24x32);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* ����*/
    delay_ms(2000);
  ILI9341_DispStringLine_EN(LINE(4),"  PASS!   ");
  }
  else if(flag==FALSE_recognization)
  {
    LCD_SetColors(RED,GREEN);
     LCD_SetFont(&Font24x32);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* ���� */
    delay_ms(2000);
  ILI9341_DispStringLine_EN(LINE(4),"  DENIED!   ");
  }
  else if(flag==TURNOFF)
  {
    
    LCD_SetColors(WHITE,BLACK);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);
    LCD_SetFont(&Font24x32);
    ILI9341_DispStringLine_EN(LINE(4),"  BYE!   ");
    return;
  }
   delay_ms(2000);
  LCD_SetFont(&Font8x16);
  LCD_SetColors(RED,GREEN);
  ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* ��������ʾ��ɫ����*/
}

#endif