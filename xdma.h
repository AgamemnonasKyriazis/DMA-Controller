#ifndef __XDMA__
#define __XDMA__

#include <stddef.h>
#include <stdint.h>

extern int xdma_init_done;

int xdma_init ();

int xdma_write_mem (void * hptr, size_t nbytes, void * dptr);

int xdma_read_mem (void * hptr, size_t nbytes, void * dptr);

int xdma_write_reg (uint64_t value, uint64_t reg_addr);

int xdma_read_reg (uint64_t * buf, uint64_t reg_addr);

#endif /* __XDMA__ */