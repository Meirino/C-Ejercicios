#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int childpid;
	int status = 0;
	/*char **argv2;
	int i;*/

	if(argc >= 2) {
		/*argv2 = (char**) malloc((argc-1)*sizeof(char*));
		for(i = 0; i < argc-1; i++) {
			argv2[i] = argv[i+1];
		}*/

		childpid = fork();
		if(childpid > 0) { /* Padre */
			wait(NULL);
			if(WIFEXITED(0)) {
				printf("Proceso hijo terminado con salida %d\n", WEXITSTATUS(status));
			}
			exit(0);
		} else if(childpid == 0) { /* Hijo */
			execvp(argv[1], argv+1);
			exit(1);
		} else { /* Error */
			fprintf(stderr, "Fork ha fallado");
			exit(1);
		}
	} else {
		fprintf(stderr, "No se ha reconocido comandos");
	}
}
