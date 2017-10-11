#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a;
	if(argc == 2) {
		int final = atoi(argv[1]);
		for(a = 1; a <= final; ++a) {
			printf("%d\n",a);
		}
	} else if (argc == 3) {
		int final = atoi(argv[2]);
		for(a = atoi(argv[1]); a <= final; ++a) {
			printf("%d\n", a);
		}
	} else {
		int final = atoi(argv[3]);
		int incr = atoi(argv[2]);
		for(a = atoi(argv[1]); a <= final; a += incr) {
			printf("%d\n", a);
		}
	}
	return 0;	
}
