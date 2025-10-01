#include "xdma.h"
#include "axi_dma.h"
#include <stdio.h>
#include <unistd.h>

#define N 16

uint64_t wbuf[N];
uint64_t rbuf[N];

int main (void) {
    xdma_init();
    for (int i = 0; i < N; i+=1) {
	wbuf[i] = ((uint64_t)i<<28) | (i<<24) | (i<<20) | (i<<16) | (i<<12) | (i<<8) | (i<<4) | i;
        rbuf[i] = 0;
    }
    xdma_write_mem((uint64_t*)wbuf, N*sizeof(uint64_t), (uint64_t*)0x2000ULL);
    xdma_write_mem((uint64_t*)rbuf, N*sizeof(uint64_t), (uint64_t*)0x2200ULL);

    transfer_from_memory((uint64_t*)0x2000ULL, N*sizeof(uint64_t));
    transfer_to_memory((uint64_t*)0x2200ULL, N*sizeof(uint64_t));
/*
    volatile uint32_t status = 0;
    while (1) {
        status = xdma_read_reg((uint32_t*)&status, S2MM_DMASR);
        printf("0x%x\n", status);
    	if (status & 0b11)
            break;
    }
*/  sleep(2);
    xdma_read_mem((uint64_t*)rbuf, N*sizeof(uint64_t), (uint64_t*)0x2200ULL);
    for (int i = 0; i < N; i+=1)
	printf("[%d] 0x%016lx\n", i, rbuf[i]);

    return 0;
}
