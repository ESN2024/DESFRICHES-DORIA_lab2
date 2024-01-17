#include "system.h"
#include "sys/alt_stdio.h"
#include "alt_types.h"
#include "io.h"
#include <stdlib.h>
#include <unistd.h>
#include "altera_avalon_pio_regs.h"

#define DELAI 10000

int main()
{
    __uint8_t val;
    __uint8_t unite = 0x00;
    __uint8_t dizaine = 0x00;
    __uint8_t centaine = 0x00;
    while(1)
    {
        for(val = 0; val<=253; val++)
        {
            centaine = val/100;
            dizaine = (val%100)/10;
            unite = ((val%100)%10);
            IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, unite);
            IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE, dizaine);
            IOWR_ALTERA_AVALON_PIO_DATA(PIO_2_BASE, centaine);
            usleep(DELAI);
        }
    }
}
