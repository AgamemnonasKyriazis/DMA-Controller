all:
	gcc main.c axi_dma.c xdma.c -Wall -o main

clean:
	rm main
