#include <stdio.h>
#include <stdlib.h>


struct list
{
	char *data;
	int len;
	struct list *next;
};


struct list *AddToL(struct list *first, char *mass, int masslen)
{
	struct list *tmp = NULL, *last = NULL;
	if (first == NULL) {
		first = (struct list *)malloc(sizeof(struct list));
		first->data = mass;
		first->len = masslen;
		first->next = NULL;
		//printf("first data = %s\nfirst len  = %d\n", first->data, first->len);
		last = first;
	} else {
		last = first;
		while (last->next != NULL) {
			last = last->next;
		}
		tmp = (struct list *)malloc(sizeof(struct list));
		tmp->data = mass;
		tmp->len = masslen;
		tmp->next = NULL;
		//printf("tmp data = %s\ntmp len  = %d\n", tmp->data, tmp->len);
		last->next = tmp;
		last = tmp;
	}
	
	return first;
}



int main()
{
	char c;
	int maxlen = 0, masslen = 0;
	char *mass = NULL;
	struct list *first = NULL, *last = NULL;
	c = getchar();
	while (c != EOF) {
		if (((c >=48) && (c <= 57)) ||
				((c >= 65) && (c <= 90)) ||
				((c >= 97) && (c <= 122)))
		{
			masslen++;
			mass = (char *)realloc(mass, masslen*sizeof(char));
			mass[masslen - 1] = c;
			//printf("mass[%d-1] = %c\n", masslen, mass[masslen-1]);
		} else {
			if (mass != NULL) {
				first = AddToL(first, mass, masslen);
				//printf("AddToL OK!!\n");
			}
			masslen = 0;
			mass = NULL;
		}
		c = getchar();
	}
	last = first;
	while (last != NULL) {
		if (last->len > maxlen) {
			maxlen = last->len;
			//printf("maxlen = %d\n", maxlen);
		}
		last = last->next;
	}
	last = first;
	while (last != NULL){
		if (last->len == maxlen) {
			printf("FINAL WORD = %s\n", last->data);
		}
		last = last->next;
	}
	free(mass);
	last = first;
	while (last->next != NULL) {
		first = first->next;
		free(last->data);
		free(last);
		last = first;
	}
	free(first->data);
	free(first);

	return 0;
}
