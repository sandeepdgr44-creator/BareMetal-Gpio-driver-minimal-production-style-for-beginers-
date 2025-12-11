#ifndef REG_DEF_H
#define REG_DEF_H

/* ============================================================
 *  Compiler & CMSIS Compatibility
 * ============================================================ */

#if defined(__CC_ARM)          /* ARM Compiler 5 (Keil) */
    #define __I     volatile const
    #define __O     volatile
    #define __IO    volatile
#elif defined(__ARMCC_VERSION) /* ARM Compiler 6 */
    #define __I     volatile const
    #define __O     volatile
    #define __IO    volatile
#elif defined(__GNUC__)        /* GCC / ARM-GCC */
    #define __I     volatile const
    #define __O     volatile
    #define __IO    volatile
#elif defined(__ICCARM__)      /* IAR */
    #define __I     __readonly
    #define __O     __writeonly
    #define __IO    __readwrite
#else
    #define __I     volatile const
    #define __O     volatile
    #define __IO    volatile
#endif


/* ============================================================
 *  Cortex-M4 (STM32F4 Series) Base Definitions
 *  Target Board Example: NUCLEO-F411RE
 * ============================================================ */

#define PERIPH_BASE                (0x40000000UL)
#define AHB1_OFFSET                (0x00020000UL)
#define AHB1_BASE                  (PERIPH_BASE + AHB1_OFFSET)

/* RCC */
#define RCC_OFFSET                 (0x00003800UL)
#define RCC_BASE                   (AHB1_BASE + RCC_OFFSET)

#define RCC_AHB1ENR                (*(__IO uint32_t *)(RCC_BASE + 0x30UL))


/* ============================================================
 *  GPIO Register Offsets (Cortex-M4 STM32F4)
 * ============================================================ */

#define GPIO_MODER_OFFSET          (0x00UL)
#define GPIO_OTYPER_OFFSET         (0x04UL)
#define GPIO_OSPEEDR_OFFSET        (0x08UL)
#define GPIO_PUPDR_OFFSET          (0x0CUL)
#define GPIO_IDR_OFFSET            (0x10UL)
#define GPIO_ODR_OFFSET            (0x14UL)
#define GPIO_BSRR_OFFSET           (0x18UL)
#define GPIO_AFRL_OFFSET           (0x20UL)
#define GPIO_AFRH_OFFSET           (0x24UL)


/* ============================================================
 *  GPIO Port Addresses (STM32F411xx)
 * ============================================================ */

#define GPIOA_BASE                 (AHB1_BASE + 0x0000UL)
#define GPIOB_BASE                 (AHB1_BASE + 0x0400UL)
#define GPIOC_BASE                 (AHB1_BASE + 0x0800UL)
#define GPIOD_BASE                 (AHB1_BASE + 0x0C00UL)
#define GPIOE_BASE                 (AHB1_BASE + 0x1000UL)
#define GPIOH_BASE                 (AHB1_BASE + 0x1C00UL)


/* ============================================================
 *  Safe Register Access
 * ============================================================ */

#define REG32(addr)                (*(__IO uint32_t *)(addr))


/* ============================================================
 *  Bit Manipulation (MISRA-Safe)
 * ============================================================ */

#define SET_BIT(reg, bit)          ((reg) |=  (1UL << (bit)))
#define CLR_BIT(reg, bit)          ((reg) &= ~(1UL << (bit)))
#define READ_BIT(reg, bit)         (((reg) >> (bit)) & 1UL)

#define TOGGLE_BIT(reg, bit)       ((reg) ^=  (1UL << (bit)))


/* ------------------ 2-bit Field Double bit set ,reset and read ke liye----------------------------- */

#define CLR_2BIT_FIELD(reg, bit) \
    ((reg) &= ~(3UL << (2U * (bit))))

#define SET_2BIT_FIELD(reg, bit, val) \
    do { \
        CLR_2BIT_FIELD((reg), (bit)); \
        (reg) |= ((uint32_t)(val) << (2U * (bit))); \
    } while (0)


/* ------------------ 4-bit AFR Field  ------------------------- */

#define CLR_4BIT_FIELD(reg, bit) \
    ((reg) &= ~(0xFUL << (4U * (bit))))

#define SET_4BIT_FIELD(reg, bit, val) \
    do { \
        CLR_4BIT_FIELD((reg), (bit)); \
        (reg) |= ((uint32_t)(val) << (4U * (bit))); \
    } while (0)

/******************************************
 * GPIO REGISTER ACCESS MACROS 
 ******************************************/
#define GPIO_MODER(port)         REG32((port) + GPIO_MODER_OFFSET)
#define GPIO_OTYPER(port)        REG32((port) + GPIO_OTYPER_OFFSET)
#define GPIO_OSPEEDR(port)       REG32((port) + GPIO_OSPEEDR_OFFSET)
#define GPIO_PUPDR(port)         REG32((port) + GPIO_PUPDR_OFFSET)
#define GPIO_IDR(port)           REG32((port) + GPIO_IDR_OFFSET)
#define GPIO_ODR(port)           REG32((port) + GPIO_ODR_OFFSET)   
#define GPIO_BSRR(port)          REG32((port) + GPIO_BSRR_OFFSET)
#define GPIO_AFRL(port)          REG32((port) + GPIO_AFRL_OFFSET)
#define GPIO_AFRH(port)          REG32((port) + GPIO_AFRH_OFFSET)


#endif /* REG_DEF_H */
