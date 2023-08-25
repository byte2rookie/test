#include "bsp_pwm_led.h"


//��ѧϰ��ô�ó�ʼ���ļ�ʱ��(1s��)
void TIM_basic_config(void)
{
  //�ȴ�ʱ��
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
  //���û�����Ԫ����
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);//������ṹ���ʼ���������Ͳ�������Щ�����ò��ϵĲ�����
  TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV2;//36MHz
  TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
  TIM_TimeBaseInitStruct.TIM_Period=1000-1;//ÿ�������ж϶���1000������
  TIM_TimeBaseInitStruct.TIM_Prescaler=36000-1;//��ƵΪ36000-1=1000Hz,���ھ���1ms
  //TIM_TimeBaseInitStruct.TIM_RepetitionCounter=;//ֻ�и߼���ʱ������Ҫд
  TIM_TimeBaseInit(TIM_BASIC,&TIM_TimeBaseInitStruct);
  //�����ͳ�ʼ�����˻�����ʱ��
  //����һ���жϣ���������
  
  NVIC_InitTypeDef NVIC_InitStructure;
  NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;  //TIM6�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���

  
  TIM_Cmd(TIM_BASIC,ENABLE);//��TIM6  
}

//ѧϰʹ��ͨ�ü�ʱ��
void TIM_COM_config(void)
{     
  //�ȴ�ʱ��
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
  TIM_InternalClockConfig(TIM2);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
  //���û�����Ԫ����
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);//������ṹ���ʼ���������Ͳ�������Щ�����ò��ϵĲ�����
  TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//72MHz
  TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
  TIM_TimeBaseInitStruct.TIM_Period=20000-1;//20000�μ�������            ARR
  TIM_TimeBaseInitStruct.TIM_Prescaler=72-1;//��ƵΪ72-1=1MHz,���ھ���10^-6 s         PSC
  TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
  //PWMƵ��Ϊ 72M/72/0.02M=50Hz,����Ϊ0.02sҲ����20ms,����Ҫ�������һ��
  //�鿴�˿������ԭ��ͼ������PA0��KEY1ռ���ˣ����Ծ�����PA2��Ҳ����OC3Ƶ��
  //��������ʼ������Ƚϵ�Ԫ�����úû�����Ԫ��Ϳ��Կ�ʼ��������Ƚϣ�
  TIM_OCInitTypeDef TIM_OCInitStruct;
  TIM_OCStructInit(&TIM_OCInitStruct);
  TIM_OCInitStruct.TIM_OCMode=TIM_OCMode_PWM1;//����PWM1ģʽ
  TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_High;//ѡȡ��Ч��ƽ
  TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;//���������
  TIM_OCInitStruct.TIM_Pulse=0;//      CCR:��Ӧ500~2500,��ӦҲ���Ƕ�Ӧ0.5ms~2.5ms(-90~+90)
  TIM_OC3Init(TIM2,&TIM_OCInitStruct);
  TIM_Cmd(TIM2,ENABLE);
  
    //PWMҲ��ͨ��GPIO������ģ�����Ҫ�Ѷ�ӦPWM��GPIO����ʼ����
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//PA2,��ӦTIM2_OC3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//���츴��MODE
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);    
}

void TIM_COM2_config(void)
{     
  //�ȴ�ʱ��
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
  TIM_InternalClockConfig(TIM4);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  //���û�����Ԫ����
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);//������ṹ���ʼ���������Ͳ�������Щ�����ò��ϵĲ�����
  TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//72MHz
  TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
  TIM_TimeBaseInitStruct.TIM_Period=20000-1;//20000�μ�������            ARR
  TIM_TimeBaseInitStruct.TIM_Prescaler=72-1;//��ƵΪ72-1=1MHz,���ھ���10^-6 s         PSC
  TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStruct);
  //PWMƵ��Ϊ 72M/72/0.02M=50Hz,����Ϊ0.02sҲ����20ms,����Ҫ�������һ��
  //�鿴�˿������ԭ��ͼ������PA0��KEY1ռ���ˣ����Ծ�����PA2��Ҳ����OC3Ƶ��
  //��������ʼ������Ƚϵ�Ԫ�����úû�����Ԫ��Ϳ��Կ�ʼ��������Ƚϣ�
  TIM_OCInitTypeDef TIM_OCInitStruct;
  TIM_OCStructInit(&TIM_OCInitStruct);
  TIM_OCInitStruct.TIM_OCMode=TIM_OCMode_PWM1;//����PWM1ģʽ
  TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_High;//ѡȡ��Ч��ƽ
  TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;//���������
  TIM_OCInitStruct.TIM_Pulse=0;//      CCR:��Ӧ500~2500,��ӦҲ���Ƕ�Ӧ0.5ms~2.5ms(-90~+90)
  TIM_OC3Init(TIM4,&TIM_OCInitStruct);
  TIM_Cmd(TIM4,ENABLE);
  
    //PWMҲ��ͨ��GPIO������ģ�����Ҫ�Ѷ�ӦPWM��GPIO����ʼ����
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;//PA2,��ӦTIM4_OC3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//���츴��MODE
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);    
}



//������Ч��
void breathLED_B_config(void)
{
//�ȴ�ʱ��
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
  TIM_InternalClockConfig(TIM3);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  
  //���û�����Ԫ����
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);//������ṹ���ʼ���������Ͳ�������Щ�����ò��ϵĲ�����
  TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//72MHz
  TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
  TIM_TimeBaseInitStruct.TIM_Period=100-1;//10000�μ�������            ARR
  TIM_TimeBaseInitStruct.TIM_Prescaler=720-1;//��ƵΪ720-1=0.1MHz,���ھ���10^-5 s         PSC
  TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);
  //PWMƵ��Ϊ 72M/720/0.01M=10Hz,����Ϊ0.1sҲ����100ms
  //��������ʼ������Ƚϵ�Ԫ�����úû�����Ԫ��Ϳ��Կ�ʼ��������Ƚϣ�
  TIM_OCInitTypeDef TIM_OCInitStruct;
  TIM_OCStructInit(&TIM_OCInitStruct);
  TIM_OCInitStruct.TIM_OCMode=TIM_OCMode_PWM1;//����PWM1ģʽ
  TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_Low;//ѡȡ��Ч��ƽ
  TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;//���������
  TIM_OCInitStruct.TIM_Pulse=0;//      CCR
  TIM_OC4Init(TIM3,&TIM_OCInitStruct);
  
  //PWMҲ��ͨ��GPIO������ģ�����Ҫ�Ѷ�ӦPWM��GPIO����ʼ����
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//PB1,��ӦTIM3_CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//���츴��MODE
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  
  TIM_Cmd(TIM3,ENABLE);
  
  
}

void pwm_set_compare(uint32_t compare)
{
  TIM_SetCompare4(TIM3,compare);
}





void SetRedbox(uint32_t compare)
{
  
  TIM_SetCompare3(TIM2,compare);//compare��500~2500֮��
}
void SetGreenbox(uint32_t compare)
{
  
  TIM_SetCompare3(TIM4,compare);//compare��500~2500֮��
}





void openbox(uint32_t box)
{
  switch(box)
{
    case GREENBOX:
  {   for(int i=2500;i>500;i-=60)//���ƿ����ӵ��ٶȣ�������
    {
      delay_ms(20);
      SetGreenbox(i);
    }
    //delay_ms(1000);    
      break;
  }
    case REDBOX:
  {    
      for(int i=2500;i>500;i-=60)//���ƿ����ӵ��ٶȣ�������
    {
      delay_ms(20);
      SetRedbox(i);
    }
    //delay_ms(1000);
      break;
  }
}
}

void closebox(uint32_t box)
{
  switch(box)
{
  case GREENBOX:
  {
  for(int i=500;i<2500;i+=50)//���ƹظ��ӵ��ٶȣ����أ�
    {
      SetGreenbox(i);
      delay_ms(20);
    }
    break;
  }
  case REDBOX:
  {
      for(int i=500;i<2500;i+=200)//���ƹظ��ӵ��ٶȣ���أ�
    {
      SetRedbox(i);
      delay_ms(10);
    }
    break;
  }  
}
}


//NMD�������ֶ�����һ��5v��Դ
//void VCC_set(void)
//{
//  //����PB9��������Űɣ�
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
//  GPIO_InitTypeDef GPIO_InitStructure;
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//PB9
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;//��©���MODE
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//  GPIO_SetBits(GPIOB,GPIO_Pin_9);//���Կ��أ�
//}
