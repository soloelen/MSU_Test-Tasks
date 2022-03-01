#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	int fd[2];
	int i = 1, val = -1, bufflen = 0, k = 0;
	char chr;
	char *buf = NULL, *word1 = NULL, *word2 = NULL;
	char **mass;
	pipe(fd);
	
	//mass = (char **)malloc(3 * sizeof(char *));
	//word1 = (char *)malloc(3 * sizeof(char));
	//word1 = "ls";
	//word2 = (char *)malloc(3 * sizeof(char));
	//word2 = "-F";
	//mass[0] = word1;
	//mass[1] = word2;
	//mass[2] = NULL;
	//word1 = NULL;
	//word2 = NULL;
	if (fork() == 0) {
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execlp("ls", "ls", "-F", NULL);
		printf("FAIL\n");
		//perror(mass[0]);
		exit(1);
	} else {
		close(fd[1]);
		val = read(fd[0], &chr, sizeof(char));
		//printf("%c", chr);
		if (val == 0) {
			printf("val = 0\n");
			//if (buf) {free(buf);}
			//if (mass[0]) free(mass[0]);
			//if (mass[1]) free(mass[1]);
			//if (mass) free(mass); 
			exit(0);
		}
		while (val != 0) {
			while ((chr != '\n') && (val != 0)) {
				bufflen++;
				buf = (char *)realloc(buf, bufflen *(sizeof(char)));
				buf[bufflen - 1] = chr;
				val = read(fd[0], &chr, sizeof(char));
				//printf()
				/*if (val == 0) {
					exit(0);
				}*/
			}
			if (buf[bufflen - 1] == '/') {
				while (buf[k] != '/') {
					printf("%c", buf[k]);
					k++;
				}
				
				printf("\n");
			}
			val = read(fd[0], &chr, sizeof(char));
			/*if (val == 0) {
				exit(0);
			}*/
			if (buf != NULL) {
				free(buf);
			}
			buf = NULL;
			bufflen = 0;
			k = 0;
		}
		if (buf) {free(buf);}
		//if (mass[0]) free(mass[0]);
		//if (mass[1]) free(mass[1]);
		//if (mass) free(mass); 
		close(fd[0]);
	}
	return 0;
}
