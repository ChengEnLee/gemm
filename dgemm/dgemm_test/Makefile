MKLLNC := -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_gnu_thread.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lgomp -lpthread -lm -ldl
MKLOPT := -m64 -I${MKLROOT}/include

all: CPU
	g++ main.o -o test.run $(MKLLNC)
CPU:
	g++ $(MKLOPT) main.c -c 
clean:
	rm *.o
