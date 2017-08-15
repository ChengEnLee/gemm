CUDALNC :=-lcublas -lcusparse -lcudart -lcusolver -lmagma_sparse -lmagma

all: CPU GPU
	g++ main.o -o test.run -L $(CUDALNC)
CPU:
	g++ main.c -c
GPU:
	nvcc

clean:
	rm *.o
