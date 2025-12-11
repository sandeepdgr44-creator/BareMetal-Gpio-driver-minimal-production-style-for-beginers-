#ifndef PUBLIC_GPIO_H
#define PUBLIC_GPIO_H

#include <stdint.h>
#include "regdef.h"

/************************************************************
 * PUBLIC MACROS (Mode / Speed / Type / Pull)
 ************************************************************/
#define HAL_GPIO_MODE_INPUT     (0U)
#define HAL_GPIO_MODE_OUTPUT    (1U)
#define HAL_GPIO_MODE_AF        (2U)
#define HAL_GPIO_MODE_ANALOG    (3U)

#define HAL_GPIO_OT_PP          (0U)
#define HAL_GPIO_OT_OD          (1U)

#define HAL_GPIO_PUPD_NONE      (0U)
#define HAL_GPIO_PUPD_PU        (1U)
#define HAL_GPIO_PUPD_PD        (2U)

#define HAL_GPIO_SPEED_LOW      (0U)
#define HAL_GPIO_SPEED_MED      (1U)
#define HAL_GPIO_SPEED_FAST     (2U)
#define HAL_GPIO_SPEED_HIGH     (3U)

#define HAL_GPIO_LOW            (0U)
#define HAL_GPIO_HIGH           (1U)

/************************************************************
 * PUBLIC HAL MACROS (DIRECT WRAPPERS AROUND LL)
 ************************************************************/

/* HAL INIT */
#define HAL_GPIO_Init(PORT, PIN, MODE, SPEED, OTYPE, PUPD)   \
        gpio_ll_init((PORT), (PIN),                           \
                     (MODE), (SPEED),                         \
                     (OTYPE), (PUPD))

/* HAL WRITE */
#define HAL_GPIO_Write(PORT, PIN, VALUE) \
        gpio_write((PORT), (PIN), (VALUE))

/* HAL ATOMIC WRITE */
#define HAL_GPIO_WriteAtomic(PORT, PIN, VALUE) \
        gpio_write_atomic((PORT), (PIN), (VALUE))

/* HAL READ */
#define HAL_GPIO_Read(PORT, PIN) \
        gpio_read((PORT), (PIN))

/* HAL TOGGLE */
#define HAL_GPIO_Toggle(PORT, PIN) \
        gpio_toggle((PORT), (PIN))

/* HAL SET AF */
#define HAL_GPIO_SetAF(PORT, PIN, AF) \
        gpio_setAF((PORT), (PIN), (AF))

#endif /* PUBLIC_GPIO_H */
