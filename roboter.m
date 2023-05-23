all: roboter.o helper.o roboter
roboter.o: roboter.c
    cc -c roboter.c
helper.o: helper.c
    cc -c helper.c
roboter: roboter.o helper.o
    cc -o roboter roboter.o helper.o
