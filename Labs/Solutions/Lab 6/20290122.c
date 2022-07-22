#include <stdio.h>
#include <stdlib.h>

//Tree representation in Linked list form
typedef struct StudentTree{
	int grade;
	int studentId;
	struct StudentTree *root;
	struct StudentTree *right;
	struct StudentTree *left;	
}st;

//Creating a new node
st *new_node(int id, int grade, st *n){
	st *new = (st*) malloc(sizeof(st));
	new->grade = grade;
	new->studentId = id;
	new->right = NULL;
	new->left = NULL;
	new->root = n;
	return new;
}

//The function to create BST tree and its nodes
st *insert_nodes(st *n, int id, int gr, st *k){
	if (n == NULL){
		return new_node(id, gr, k);
	}
	if (gr < n->grade){
		n->left = insert_nodes(n->left, id, gr, n);
	}
	else{
		n->right = insert_nodes(n->right, id, gr, n);
	}

	return n;
}

//The function to find the height of tree
int height(st *n){
	if (n == NULL){
		return 0;
	}
	else{
		int l = height(n->left);
		int r = height(n->right);
		if (l>r)
			return (l+1);
		else
			return (r+1);
	}
}

//The function to print the BST and its nodes
void print_tree(st *n){
	if (n != NULL){
		print_tree(n->left);
		printf("%d %d\n", n->studentId, n->grade);
		print_tree(n->right);
	}
}

int u = 0;

//The function to print nodes according to depth-level
void print_nodes(st *n, int lvl, char a){
	if (n==NULL){
		return;
	}
	if (lvl == 1){
		printf("%d %d (%d", n->studentId, n->grade, n->root->grade);
		printf(" %c) ", a);
	}
	else if (lvl>1){
		print_nodes(n->left, lvl-1, 'L');
		print_nodes(n->right, lvl-1, 'R');
	}
}

//The function to print levels
void level(st *n){
	int lev = height(n);
	for (int i = 2; i <= lev; ++i)
	{
		u = 0;
		print_nodes(n, i, 'S');
		printf("\n");
	}
}

//Driver function
int main(){
	st *root = NULL;
	int gr, id;
	scanf("%d %d", &id, &gr);
	root = insert_nodes(root, id, gr, NULL);
	scanf("%d", &id);
	while(id!=-1){
		scanf("%d", &gr);
		root = insert_nodes(root, id, gr, root);
		scanf("%d", &id);
	}
	print_tree(root);
	printf("\n%d %d\n", root->studentId, root->grade);
	level(root);

	return 0;
}