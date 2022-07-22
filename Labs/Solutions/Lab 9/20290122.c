#include <stdio.h>
#include <stdlib.h>

int max = 4, min = 2;

//The structure to initialize B tree
typedef struct B_Tree
{
	int data[max];
	int count;
	int isleaf;
	struct B_Tree *child[max+1];
}bt;

//The function to operate insertion operation
void insert(bt *n, int data){
	
}	


int main(){
	bt *root = NULL;
	int data=0;
	scanf("%d", &data);
	root = insert(root, data, NULL);
	scanf("%d", &data);
	while(data != -1){
		root = insert(root, data, root);
		scanf("%d", &data);
	}


	return 0;
}