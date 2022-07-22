#include <stdio.h>
#include <stdlib.h>

typedef struct Employee{

	int emp_nm;
	int busy;
	int total_dur;
	int end_time;
	struct Employee *next;
}ep;

typedef struct Customers{

	int cstmr_nm;
	int start;
	int duration;
	struct Customers *next;
}cst;

int min(int a, int b){
	if (a>b)
		return b;
	return a;
}

void create_stack(ep **n, int i){
	ep *ptr = (*n),*new_node = (ep*) malloc(sizeof(ep));
	new_node->emp_nm = 6-i;
	new_node->busy = 0;
	new_node->total_dur = 0;
	new_node->end_time = 1;
	new_node->next = NULL;

	if (*n == NULL){
		(*n) = new_node;
		return;
	}
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	ptr->next = new_node;
}


void push(cst **n, int cst_nm, int str, int dur){
	cst *ptr = (*n), *new_node = (cst*) malloc(sizeof(cst));
	new_node->cstmr_nm = cst_nm;
	new_node->start = str;
	new_node->duration = dur;
	new_node->next = NULL;
	if (*n == NULL){
		(*n) = new_node;
		return;
	}

	while(ptr->next !=NULL){
		ptr = ptr->next;
	}
	ptr->next = new_node;
}

void check_match(ep **n, int start, int dur, int cst){
	ep *ptr = (*n);
	int delay = 999999999, ls[6] = {0,0,0,0,0,0}, cnt = 0;
	while(ptr!=NULL){
		if (ptr->end_time == start){
			ptr->end_time = start+dur;
			ptr->busy = 1;
			ptr->total_dur = ptr->total_dur + dur;
			printf("%d %d %d %d %d\n", cst, ptr->emp_nm, start, ptr->end_time, 0);
			return;
		}
		else if(ptr->end_time<start && ptr->busy == 0){
			ptr->end_time = start+dur;
			ptr->busy = 1;
			ptr->total_dur = ptr->total_dur+dur;
			printf("%d %d %d %d %d\n", cst, ptr->emp_nm, start, ptr->end_time, 0);
			return;	
		}
		else if(ptr->end_time>start){
			int del = abs(ptr->end_time - start);
			ls[cnt] = del;
			delay = min(del, delay);
		}
		cnt++;
		ptr = ptr->next;
	}
	ptr = (*n);
	for (int i = 0; i < cnt; ++i){
		// printf("%d %d\n", ptr->end_time, ls[i]);
		if (ls[i]==delay){
			ptr->end_time = start+dur+delay;
			ptr->busy = 1;
			ptr->total_dur = ptr->total_dur+dur;
			printf("%d %d %d %d %d\n", cst, ptr->emp_nm, start+delay, ptr->end_time, delay);
			return;
		}
		ptr = ptr->next;
	}
}

void match_cst_emp(cst **n, ep **k){
	cst *ptr = (*n);

	while(ptr!=NULL){
		int st = ptr->start, dur = ptr->duration, cst = ptr->cstmr_nm;
		check_match(k, st, dur, cst);
		ptr = ptr->next;
	}
	printf("\n");

	ep *pptr = (*k);
	while(pptr!=NULL){
		printf("%d %d\n", pptr->emp_nm, pptr->total_dur);
		pptr= pptr->next;
	}
}

int main(){

	ep *top = NULL;
	cst *head = NULL;
	int cst, st, dur;
	scanf("%d", &cst);
	while(cst!=-1){
		scanf("%d %d", &st, &dur);
		push(&head, cst, st, dur);
		scanf("%d", &cst);
	}
	for (int i = 0; i < 6; ++i){
		create_stack(&top, i);
	}
	match_cst_emp(&head, &top);

}