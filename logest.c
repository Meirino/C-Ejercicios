#include <stdin.h>
#include <string.h>
#include <stdlib.h>

int main() {
	longest(4);
	return 0;
}

void longest(int n) {
	char **lista;
	char buff[1024];
	int longitud;
	
	lista = (char **) malloc(n*sizeof(char *));
	
	while(fgets(stdin, buff, 1024) != NULL) {
		/* Leer linea
		 *
		 * Si la lista es vacía, primera posición
		 * Si no, comparar la longitud del primero, segundo... 
		 */
	}
}
