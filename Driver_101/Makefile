obj-m += ldd.o

all:
	make -C /lib/modules/5.4.0-214-generic/build M=$(PWD) modules

clean:
	make -C /lib/modules/5.4.0-214-generic/build M=$(PWD) clean