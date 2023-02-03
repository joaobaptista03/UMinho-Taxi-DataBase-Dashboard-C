CC = gcc
CFLAGS= -Wall -Iincludes -g -Ipath/to/glib/include `pkg-config --cflags glib-2.0`
LDFLAGS= `pkg-config --libs glib-2.0` -lm

all: main test

main: src/main.o src/batch.o src/stats.o src/interactive.o src/files.o src/query1.o src/query1_driver.o src/query1_user.o src/query2.o src/query3.o src/query4.o src/query5.o src/query6.o src/query7.o src/query8.o src/query9.o src/randomfuncs.o src/age_time.o src/cat_drivers.o src/cat_users.o src/cat_rides.o src/inputs_batch.o src/inputs_interactive.o src/outputs.o
	$(CC) $^ $(LDFLAGS) $(CFLAGS) -o programa-principal

test: src/stats.o src/query1.o src/query1_driver.o src/query1_user.o src/query2.o src/query3.o src/query4.o src/query5.o src/query6.o src/query7.o src/query8.o src/query9.o src/randomfuncs.o src/age_time.o src/cat_drivers.o src/cat_users.o src/cat_rides.o src/outputs.o src/tests.o
	$(CC) $^ $(LDFLAGS) $(CFLAGS) -o programa-testes

src/main.o : src/main.c
src/batch.o : src/batch.c
src/stats.o : src/stats.c
src/interactive.o : src/interactive.c
src/files.o : src/files.c
src/query1_driver.o : src/query1_driver.c
src/query1_user.o : src/query1_user.c
src/query1.o : src/query1.c
src/query2.o : src/query2.c
src/query3.o : src/query3.c
src/query4.o : src/query4.c
src/query5.o : src/query5.c
src/query6.o : src/query6.c
src/query7.o : src/query7.c
src/query8.o : src/query8.c
src/query9.o : src/query9.c
src/randomfuncs.o : src/randomfuncs.c
src/age_time.o : src/age_time.c
src/cat_drivers.o : src/cat_drivers.c
src/cat_users.o : src/cat_users.c
src/cat_rides.o : src/cat_rides.c
src/inputs_batch.o : src/inputs_batch.c
src/inputs_interactive.o : src/inputs_interactive.c
src/outputs.o : src/outputs.c
src/tests.o : src/tests.c

clean:
	rm -f programa-principal programa-testes src/*.o