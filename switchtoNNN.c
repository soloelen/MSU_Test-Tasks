#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int f = 0, swflag = 0, rdflag = 0;


void ala(int sig)
{
	//printf("signal came\n");
	rdflag = 1;
	alarm(1);
}


void hdl(int sig)
{
	swflag = 1;
	alarm(1);
}



int main(int argc, char *argv[])
{
	char buff[10];
	int i = 1, all = argc - 1, sw = 0, valR = 0, valW = 0, current = 0;
	int file[argc - 1];
	
	signal(SIGALRM, ala);
	signal(SIGINT, hdl);
	alarm(3);
	if (argv[1] == NULL) {
		printf("Wrong amount of arguments\n");
		exit(1);
	}
	while (i != argc) {
		//printf("file[%d]=%s\n", i-1, argv[i]);
		file[i - 1] = open(argv[i], O_RDONLY);
		i++;
	}

	i = 0;
	// all = argc - 1 (!)
	while (all != 0) {
		if (rdflag == 1) {
			printf("WE ARE IN IF\n");
			if (file[current] != -1) {
				printf("curr = %d\n", current);
				printf("file[curr] = %d\n", file[current]);
				valR = read(file[current], &buff, 10);
				printf("\nvalR = %d\n", valR);
				if (valR < 10) {
					buff[valR] = '\0';
					printf("\n--%s--\n", buff);
					i = 0;
					while (i != 9) {
						buff[i] = '\0';
						i++;
					}
					all--;
					printf("all = %d\n", all);
					printf("file[curr] = %d\n", file[current]);
					close(file[current]);
					file[current] = -1;
					sw = 0;
					if (all != 0) {
					//printf("cur1 = %d\n", current);
						while (sw != 1){
							current++;
							if (current == argc - 1)
								current =  0;
							if (file[current] != -1) {
								sw = 1;
							}
						}
					}
					//printf("cur2 = %d\n", current);
					sw = 0;

				} else {
					printf("\n+-%s-+\n", buff);
					//valW = write(1, &buff, 10);
					//printf("\nvalW = %d\n", valW);
					i = 0;
					while (i != 9) {
						buff[i] = '\0';
						i++;
					}
				}
				i = 0;
			}
			rdflag = 0;
		}
		
		if (swflag == 1) {
			while (sw != 1){
				//printf("OK\n");
				current++;
				if (current == argc - 1)
					current =  0;
				if (file[current] != -1) {
					sw = 1;
				}
				
			}
			sw = 0;
			swflag = 0;
		}
	}
	
	
	return 0;
}



















