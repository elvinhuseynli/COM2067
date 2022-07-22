#include <stdio.h>
#include <stdlib.h>

//The struct that defines Red-Black Tree
typedef struct RedBlackTree{
	int data;
	char color;
	struct RedBlackTree *parent;
	struct RedBlackTree *right;
	struct RedBlackTree *left;
}rbt;

rbt *root = NULL;

void case1(rbt *n);

//The function to return grandparent
rbt *grandpa(rbt *n){
	if (n!=NULL && n->parent!=NULL)
		return n->parent->parent;
	return NULL;
}

//The function to return uncle
rbt *uncle(rbt *n){
	rbt *g = grandpa(n);
	if (g == NULL)
		return NULL;
	if (n->parent == g->left)
		return g->right;
	return g->left;
}

//The function to create a new node
rbt *new_node(int data, rbt *n){
	rbt *new = (rbt*) malloc(sizeof(rbt));
	new->data = data;
	new->right = NULL;
	new->left = NULL;
	new->parent = n;
	new->color = 'R';
	return new;
}

//The function to rotate the function right
rbt *right(rbt *temp){
	rbt* left = temp->left;
	temp->left = left->right;
	if (temp->left)
		temp->left->parent = temp;
	left->parent = temp->parent;
	if (!temp->parent)
		root = left;
	else if (temp == temp->parent->left)
		temp->parent->left = left;
	else
		temp->parent->right = left;
	left->right = temp;
	temp->parent = left;
}

//The function to rotate the function left
rbt *left(rbt *temp){
	rbt *right = temp->right;
	temp->right = right->left;
	if (temp->right)
		temp->right->parent = temp;
	right->parent = temp->parent;
	if (!temp->parent)
		root = right;
	else if (temp == temp->parent->left)
		temp->parent->left = right;
	else
		temp->parent->right = right;
	right->left = temp;
	temp->parent = right;
}

//The function to evaluate 5th case
void case5(rbt *n){
	rbt *g = grandpa(n);
	//LL case
	if (n->parent == g->left && n == n->parent->left){
		left(g);
		n->parent->color = 'B';
		g->color = 'R';
	}
	//RR case
	else if (n->parent == g->right && n == n->parent->right){
		right(g);
		n->parent->color = 'B';
		g->color = 'R';	
	}
}

//The function to evaluate the 4th case
void case4(rbt *n){	
	rbt *g = grandpa(n);

	//LR case
	if (n->parent == g->left && n == n->parent->right){
		left(n->parent);
		right(g);
	}
	//RL case
	else if (n->parent == g->right && n == n->parent->left){
		right(n->parent);
		left(g);
	}
	else
		case5(n);
}

//The function to evaluate the 3rd case
void case3(rbt *n){
	rbt *u, *g;
	u = uncle(n);
	g = grandpa(n);

	if (u!=NULL && u->color == 'R'){
		u->color = 'B';
		n->parent->color = 'B';
		g->color = 'R';
		case1(g);
	}
	else
		case4(n);
}
//The function to evaluate the 2nd case
void case2(rbt *n){
	if (n->parent->color == 'B')
		return;
	else
		case3(n);
}

//The function to evaluate the 1st case
void case1(rbt *n){
	if (n->parent == NULL)
		n->color = 'B';
	else
		case2(n);
}

//The function that inserts elements to the Red-Black Tree
rbt *insert_nodes(rbt *n, int data, rbt *k){
	if (n == NULL){
		return new_node(data, k);
	}
	if (data < n->data){
		n->left = insert_nodes(n->left, data, n);
	}
	else{
		n->right = insert_nodes(n->right, data, n);
	}

	case1(n);
	return n;
}

//The function to print the RBT and its nodes
void print_tree(rbt *n){
	if (n != NULL){
		print_tree(n->left);
		printf("%d\n", n->data);
		print_tree(n->right);
	}
}

//The function to print nodes according to depth-level
void print_nodes(rbt *n, int lvl, char a, rbt *k){
	if (n==NULL)
		return;
	if (lvl == 1){
		printf("%d %c (%d %c) ", n->data, n->color, k->data, a);
	}
	else if (lvl>1){
		print_nodes(n->left, lvl-1, 'L', n);
		print_nodes(n->right, lvl-1, 'R', n);
	}
}

//The function to find the height of tree
int height(rbt *n){
	if (n == NULL)
		return 0;
	else{
		int l = height(n->left);
		int r = height(n->right);
		if (l>r)
			return (l+1);
		else
			return (r+1);
	}
}

 //The function to print levels
void level(rbt *n){
	int lev = height(n);
	for (int i = 2; i <= lev; ++i){
		print_nodes(n, i, 'S',n);
		printf("\n");
	}
}

//The driver function
int main(){
	int data;
	scanf("%d", &data);
	root = insert_nodes(root, data, NULL);
	scanf("%d", &data);
	while(data!=-1){
		root = insert_nodes(root, data, root);
		scanf("%d", &data);
	}

	print_tree(root);
	printf("\n%d B\n", root->data);
	// printf("%d %d", root->left->data, root->right->data);
	level(root);
}