#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void getHOME() {
	char * buf;
	long size;
	chdir(getenv("HOME"));
	printf("Directorio cambiado a %s\n", getcwd(buf,(size_t) size));
}

void changePath(char * path) {
	chdir(path);
	char * buf;
	long size;
	printf("Directorio cambiado a %s\n", getcwd(buf,(size_t) size));
}

int main(int argc, char * argv[]) {
	
	// Comprobar argumentos
	
	switch(argc) {
		case 1 : getHOME(); break;
		case 2 : changePath(argv[1]); break;
		default : printf("Este comando debe recibir ningún argumento o solo uno, en vez de %d\n", argc); break;
	}
}
