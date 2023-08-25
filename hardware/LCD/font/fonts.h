#ifndef __FONTS_H
#define __FONTS_H       



#define LINE(x) ((x) * (((sFONT *)LCD_GetFont())->Height))
#define LINEY(x) ((x) * (((sFONT *)LCD_GetFont())->Width))
#include "stm32f10x.h"

typedef struct _tFont
{    
const uint8_t *table;
uint16_t Width;
uint16_t Height;  
}sFONT;


/** @defgroup FONTS_Exported_Types
  * @{
  */ 





extern sFONT Font24x32;
extern sFONT Font16x24;
extern sFONT Font8x16;

//Ҫ֧��������Ҫʵ�ֱ��������ɲο���Һ����ʾ��Ӣ�ģ��ֿ����ⲿFLASH��������
#define      GetGBKCode( ucBuffer, usChar ) 


#endif /*end of __FONT_H    */
