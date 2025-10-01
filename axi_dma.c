#include "axi_dma.h"
#include "xdma.h"

int transfer_from_memory(uint64_t * src, size_t size) {
    uint32_t src_addr_l, src_addr_u;
    uint32_t length;
    uint32_t ctrl;

    if (!xdma_init_done) {
        return -1;
    }
    src_addr_l = ((uint64_t)src) & ((uint64_t)0x0ffffffff);
    src_addr_u = ((uint64_t)src) >> (uint64_t)32;
    length     = (size);
    xdma_write_reg(src_addr_l, MM2S_SA);
    xdma_write_reg(src_addr_u, MM2S_SA_MSB);
    xdma_write_reg(length, MM2S_LENGTH);
    
    xdma_read_reg(&ctrl, MM2S_DMACR);
    ctrl |= 1ULL;
    xdma_write_reg(ctrl, MM2S_DMACR);

    return 0;
}

int transfer_to_memory(uint64_t * dst, size_t size) {
    uint32_t dst_addr_l, dst_addr_u;
    uint32_t length;
    uint32_t ctrl;
    
    if (!xdma_init_done) {
        return -1;
    }
    dst_addr_l = ((uint64_t)dst) & ((uint64_t)0x0ffffffff);
    dst_addr_u = ((uint64_t)dst) >> (uint64_t)32;
    length     = (size);
    xdma_write_reg(dst_addr_l, S2MM_DA);
    xdma_write_reg(dst_addr_u, S2MM_DA_MSB);
    xdma_write_reg(length, S2MM_LENGTH);

    xdma_read_reg(&ctrl, S2MM_DMACR);
    ctrl |= 1ULL;
    xdma_write_reg(ctrl, S2MM_DMACR);

    return 0;
}
