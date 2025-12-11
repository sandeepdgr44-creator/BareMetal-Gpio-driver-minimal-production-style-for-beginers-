#ifndef GPIO_H
#define GPIO_H


/******************************************
 * CLK ENABLE API (Optimized)
 ******************************************/
static inline void Enable_clk(uint32_t port)
{
    switch (port)
    {
        case GPIOA_BASE: SET_BIT(RCC_AHB1ENR, 0); break;
        case GPIOB_BASE: SET_BIT(RCC_AHB1ENR, 1); break;
        case GPIOC_BASE: SET_BIT(RCC_AHB1ENR, 2); break;
        case GPIOD_BASE: SET_BIT(RCC_AHB1ENR, 3); break;
        case GPIOE_BASE: SET_BIT(RCC_AHB1ENR, 4); break;
        case GPIOH_BASE: SET_BIT(RCC_AHB1ENR, 7); break;
        default: break;
    }
}

/******************************************
 * GPIO LOW-LEVEL INIT
 ******************************************/
static inline void gpio_ll_init(uint32_t port,
                           uint8_t pin,
                           uint8_t mode,
                           uint8_t speed,
                           uint8_t otype,
                           uint8_t pupd)
{
    Enable_clk(port);

    /* MODE */
    SET_2BIT_FIELD(GPIO_MODER(port), pin, mode);

    /* OUTPUT TYPE */
    if (otype)
        SET_BIT(GPIO_OTYPER(port), pin);
    else
        CLR_BIT(GPIO_OTYPER(port), pin);

    /* SPEED */
    SET_2BIT_FIELD(GPIO_OSPEEDR(port), pin, speed);

    /* PULL-UP/DOWN */
    SET_2BIT_FIELD(GPIO_PUPDR(port), pin, pupd);
}

/******************************************
 * GPIO WRITE (simple)
 ******************************************/
static inline void gpio_write(uint32_t port, uint8_t pin, uint8_t value)
{
    if (value)
        SET_BIT(GPIO_ODR(port), pin);
    else
        CLR_BIT(GPIO_ODR(port), pin);
}

/******************************************
 * ATOMIC WRITE VIA BSRR
 ******************************************/
static inline void gpio_write_atomic(uint32_t port, uint8_t pin, uint8_t value)
{
    GPIO_BSRR(port) = (value) ? (1UL << pin) : (1UL << (pin + 16));
}

/******************************************
 * GPIO READ
 ******************************************/
static inline uint8_t gpio_read(uint32_t port, uint8_t pin)
{
    return READ_BIT(GPIO_IDR(port), pin);
}

/******************************************
 * GPIO TOGGLE
 ******************************************/
static inline void gpio_toggle(uint32_t port, uint8_t pin)
{
    TOGGLE_BIT(GPIO_ODR(port), pin);
}

/******************************************
 * GPIO SET ALTERNATE FUNCTION (Optimized)
 ******************************************/
static inline void gpio_setAF(uint32_t port, uint8_t pin, uint8_t af)
{
    if (pin < 8)
    {
        SET_4BIT_FIELD(GPIO_AFRL(port), pin, af);
    }
    else
    {
        SET_4BIT_FIELD(GPIO_AFRH(port), (pin - 8), af);
    }
}

#endif 
