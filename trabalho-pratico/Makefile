programa-principal: src/main.c
	gcc src/main.c src/query1.c src/randomfuncs.c src/age_time.c src/catalog.c src/inputs.c src/outputs.c -Wall -o programa-principal `pkg-config --cflags --libs glib-2.0`

clean:
	rm -f programa-principal src/*.o