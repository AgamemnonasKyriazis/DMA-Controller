#ifndef __AXI_DMA__
#define __AXI_DMA__

#include <stddef.h>
#include <stdint.h>

#define MM2S_DMACR  0x00 // MM2S_DMACR MM2S DMA Control register
#define MM2S_DMASR  0x04 // MM2S_DMASR MM2S DMA Status register
// 0x08 – 0x14 Reserved N/A
#define MM2S_SA     0x18 // MM2S_SA MM2S Source Address. Lower 32 bits of address.
#define MM2S_SA_MSB 0x1C // MM2S_SA_MSB MM2S Source Address. Upper 32 bits of address.
#define MM2S_LENGTH 0x28 // MM2S_LENGTH MM2S Transfer Length (Bytes)

#define S2MM_DMACR  0x30 // S2MM_DMACR S2MM DMA Control register
#define S2MM_DMASR  0x34 // S2MM_DMASR S2MM DMA Status register
// 0x38 – 0x44 Reserved N/A
#define S2MM_DA     0x48 // S2MM_DA S2MM Destination Address. Lower 32 bit address.
#define S2MM_DA_MSB 0x4C // S2MM_DA_MSB S2MM Destination Address. Upper 32 bit address.
#define S2MM_LENGTH 0x58 // S2MM_LENGTH S2MM Buffer Length (Bytes)

int transfer_from_memory(uint64_t * src, size_t size);

int transfer_to_memory(uint64_t * dst, size_t size);

#endif /* __AXI_DMA__ */