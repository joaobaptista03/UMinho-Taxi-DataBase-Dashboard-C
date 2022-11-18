CFlags = -Wall -o

programa-principal: src/main.o src/query1.o src/query2.o src/query3.o src/randomfuncs.o src/age_time.o src/catalog.o src/inputs.o src/outputs.o
	gcc src/main.o src/query1.o src/query2.o src/query3.o src/randomfuncs.o src/age_time.o src/catalog.o src/inputs.o src/outputs.o $(CFlags) programa-principal

src/main.o : src/main.c
src/query1.o : src/query1.c
src/query2.o : src/query2.c
src/query3.o : src/query3.c
src/randomfuncs.o : src/randomfuncs.c
src/age_time.o : src/age_time.c
src/catalog.o : src/catalog.c
src/inputs.o : src/inputs.c
src/outputs.o : src/outputs.c

clean:
	rm -f programa-principal src/*.o