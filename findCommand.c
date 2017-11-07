#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	if(argc == 2) {
		printf("Comando a buscar: %s \n", argv[1]);
		printf("PATH: %s \n", getenv("PATH"));
		// Divido PATH por :
		//
	} else {
		printf("Número incorrecto de argumentos.\n findCommand [comando]\n");
	}
}
