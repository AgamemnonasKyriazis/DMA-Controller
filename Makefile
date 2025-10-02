all:
	gcc main.c axi_dma.c xdma.c -Wall -o main -O0

clean:
	rm main
