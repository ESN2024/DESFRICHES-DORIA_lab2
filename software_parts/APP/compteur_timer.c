#include "system.h"
#include "sys/alt_stdio.h"
#include "alt_types.h"
#include "io.h"
#include <stdlib.h>
#include <unistd.h>
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_timer.h"


volatile __uint8_t val;
volatile __uint8_t unite, dizaine, centaine; 

static void irqhandler_timer(void * context, alt_u32 id)
{
    if(val<1000)
    {
        centaine = val/100;
        dizaine = (val%100)/10;
        unite = ((val%100)%10);

        IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, unite);

        IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE, dizaine);

        IOWR_ALTERA_AVALON_PIO_DATA(PIO_2_BASE, centaine);

        val++;
    }
    else
    {
        val = 0;
    }

    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0x1); //clear
}

int main()
{
    alt_printf("main() started\n");
    alt_irq_register(TIMER_0_IRQ, NULL, (void *)irqhandler_timer);
    val = 0;
    while(1)
    {}
    return 0;
}
