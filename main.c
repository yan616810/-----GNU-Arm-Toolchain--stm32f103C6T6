#include "stm32f10x.h"
uint32_t i = 1000000;
int main(void)
{
      // 配置GPIO
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    {
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_13;
        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
    for(;;)
    {
          // 切换LED状态
        GPIOC->ODR ^= GPIO_Pin_13;
        for (uint32_t delay = 0; delay < i; delay++);
    }
}