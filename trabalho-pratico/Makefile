CC = gcc
CFLAGS= -Wall -Iincludes -Ipath/to/glib/include `pkg-config --cflags glib-2.0`
LDFLAGS= `pkg-config --libs glib-2.0` -lm

all: main

main: src/main.o src/query1.o src/query2.o src/query3.o src/query4.o src/query5.o src/query6.o src/randomfuncs.o src/age_time.o src/catalog.o src/inputs.o src/outputs.o
	$(CC) $^ $(LDFLAGS) $(CFLAGS) -o programa-principal

src/main.o : src/main.c
src/query1.o : src/query1.c
src/query2.o : src/query2.c
src/query3.o : src/query3.c
src/query4.o : src/query4.c
src/query5.o : src/query5.c
src/query6.o : src/query6.c
src/randomfuncs.o : src/randomfuncs.c
src/age_time.o : src/age_time.c
src/catalog.o : src/catalog.c
src/inputs.o : src/inputs.c
src/outputs.o : src/outputs.c

clean:
	rm -f programa-principal src/*.o