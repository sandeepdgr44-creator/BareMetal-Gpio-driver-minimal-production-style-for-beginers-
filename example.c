#include "public-gpio.h"

int main(void)
{
    HAL_GPIO_Init(GPIOA_BASE, 5,
                  HAL_GPIO_MODE_OUTPUT,
                  HAL_GPIO_SPEED_LOW,
                  HAL_GPIO_OT_PP,
                  HAL_GPIO_PUPD_NONE);

    while(1)
    {
        HAL_GPIO_Toggle(GPIOA_BASE, 5);

        for (volatile uint32_t i = 0; i < 500000; i++)
        {
            __asm("NOP");
        }
    }
}
