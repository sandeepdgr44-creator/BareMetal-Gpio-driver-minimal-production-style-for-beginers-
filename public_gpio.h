
#ifndef PUBLIC_GPIO_H
#define PUBLIC_GPIO_H

#include <stdint.h>
#include "regdef.h"
#include "gpio.h"

/************************************************************
 * PUBLIC MACROS (Mode / Speed / Type / Pull)
 ************************************************************/
#define GPIO_MODE_INPUT     (0U)
#define GPIO_MODE_OUTPUT    (1U)
#define GPIO_MODE_AF        (2U)
#define GPIO_MODE_ANALOG    (3U)

#define GPIO_OT_PP          (0U)
#define GPIO_OT_OD          (1U)

#define GPIO_PUPD_NONE      (0U)
#define GPIO_PUPD_PU        (1U)
#define GPIO_PUPD_PD        (2U)

#define GPIO_SPEED_LOW      (0U)
#define GPIO_SPEED_MED      (1U)
#define GPIO_SPEED_FAST     (2U)
#define GPIO_SPEED_HIGH     (3U)

#define GPIO_LOW            (0U)
#define GPIO_HIGH           (1U)

/************************************************************
 * PUBLIC HAL MACROS (DIRECT WRAPPERS AROUND LL)
 ************************************************************/

/* HAL INIT */
#define GPIO_Init(PORT, PIN, MODE, SPEED, OTYPE, PUPD)   \
        gpio_ll_init((PORT), (PIN),                           \
                     (MODE), (SPEED),                         \
                     (OTYPE), (PUPD))

/* HAL WRITE */
#define GPIO_Write(PORT, PIN, VALUE) \
        gpio_write((PORT), (PIN), (VALUE))

/* HAL ATOMIC WRITE */
#define GPIO_WriteAtomic(PORT, PIN, VALUE) \
        gpio_write_atomic((PORT), (PIN), (VALUE))

/* HAL READ */
#define GPIO_Read(PORT, PIN) \
        gpio_read((PORT), (PIN))

/* HAL TOGGLE */
#define GPIO_Toggle(PORT, PIN) \
        gpio_toggle((PORT), (PIN))

/* HAL SET AF */
#define GPIO_SetAF(PORT, PIN, AF) \
        gpio_setAF((PORT), (PIN), (AF))

#endif /* PUBLIC_GPIO_H */
