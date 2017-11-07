#include <stdio.h>
#include <stdlib.h>

void random_handler(int signal);
void exit_handler(int signal);

int main() {
	char buff[1024];
	int child_pid;
	int pipe_random[2]; /* Escritura en el hijo, lectura en el padre */
	int exit_trigger = 0;

	signal(10, random_handler);
	signal(15, exit_handler);

	child_pid = fork();

	if(child_pid == 0) { /* Soy el hijo  */
		/*Cierro pipes*/
		close(pipe_random[0]);
		while(exit_trigger == 0) {
			/*Espera señales*/
		}
		exit(0);
	} else if (child_pid > 0) { /* Soy el padre  */
		/*Cierro pipes*/
		close(pipe_random[1]);
		/*Leo input de usuario*/
		while(fgets(buff, 1024, stdin) != NULL) {
			printf("%s", buff);
			/*Mando señal al hijo*/
			kill(child_pid, 10);
		}
		/*Mando señal de finalización*/
		kill(child_pid, 15);
		exit(0);
	} else {
		printf("Error\n");
		exit(1);
	}
}

void random_handler(int signal) {
	/*Genero número al azar*/
	printf("Genero numero al azar!\n");
}

void exit_handler(int signal) {
	printf("Recibida señal %d, terminando el proceso hijo\n", signal);
};
