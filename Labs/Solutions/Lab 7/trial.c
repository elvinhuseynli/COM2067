#include <stdio.h>
#include <stdlib.h>

typedef struct AvlTree{
	int data;
	int balance;
	int height;
	struct AvlTree *root;
	struct AvlTree *right;
	struct AvlTree *left;
}avl;

//The function to get the height of the tree
int height(avl *n)
{
	if (n == NULL)
		return 0;
	return n->height;
}

//The function to find the maximum of two values
int max(int a, int b){
	if (a>b)
		return a;
	return b;
}

//The function to rotate the function right
avl *right(avl *n){
	avl *a = n->left;
	avl *b = a->right;
	a->right = n;
	n->left = b;
	n->height = max(height(n->left), height(n->right))+1;
	a->height = max(height(a->left), height(a->right))+1;

	return a;
}

//The function to rotate the function left
avl *left(avl *n){
	avl *a = n->right;
	avl *b = a->left;
	a->left = n;
	n->right = b;
	n->height = max(height(n->left), height(n->right))+1;
	a->height = max(height(a->left), height(a->right))+1;

	return a;
}

//The function to get the balance of the nodes
int node_balance(avl *n){
	if (n == NULL)
		return 0;
	return height(n->left) - height(n->right);
}

//Creating a new node
avl *new_node(int data, avl *n){
	avl *new = (avl*) malloc(sizeof(avl));
	new->data = data;
	new->balance = 0;
	new->right = NULL;
	new->left = NULL;
	new->height = 1;
	new->root = n;
	return new;
}

//The function to create AVL tree and its nodes
avl *insert_nodes(avl *n, int data, avl *k){
	if (n == NULL){
		return new_node(data, k);
	}
	if (data < n->data){
		n->left = insert_nodes(n->left, data, n);
	}
	else{
		n->right = insert_nodes(n->right, data, n);
	}

	n->height = 1 + max(height(n->left), height(n->right));

	int balance = node_balance(n);

	// Left Left Case
	if (balance > 1 && data < n->left->data)
		return right(n);

	// Right Right Case
	if (balance < -1 && data > n->right->data)
		return left(n);

	// Left Right Case
	if (balance > 1 && data > n->left->data){
		n->left = left(n->left);
		return right(n);
	}

	// Right Left Case
	if (balance < -1 && data < n->right->data){
		n->right = right(n->right);
		return left(n);
	}

	return n;
}

//The function to print the AVL and its nodes
void print_tree(avl *n){
	if (n != NULL){
		print_tree(n->left);
		printf("%d %d\n", n->data, n->height);
		print_tree(n->right);
	}
}

//The function to find the height of tree
int height1(avl *n){
	if (n == NULL)
		return 0;
	else{
		int l = height1(n->left);
		int r = height1(n->right);
		if (l>r)
			return (l+1);
		else
			return (r+1);
	}
}

//The function to print nodes according to depth-level
void print_nodes(avl *n, int lvl, char a, avl *k){
	if (n==NULL)
		return;
	if (lvl == 1){
		printf("%d (%d %c) (%d B) ", n->data, k->data, a, n->balance);
	}
	else if (lvl>1){
		print_nodes(n->left, lvl-1, 'L', n);
		print_nodes(n->right, lvl-1, 'R', n);
	}
}

//The function to get the balance values of each node
void balance1(avl *n, int lvl){
	if (n->left==NULL || n->right==NULL){
		return;
	}
	if (lvl == 1){
		if (n->left == NULL && n->right != NULL)
			n->balance = -1;
		else if (n->right == NULL && n->left != NULL)
			n->balance = 1;
		else if (n->right == NULL && n->left == NULL)
			n->balance = 0;
		else
		n->balance = n->left->height - n->right->height;
		// printf("%d %d\n", n->data, n->balance);
	}
	else if(lvl>1){
		balance1(n->left, lvl-1);
		balance1(n->right, lvl-1);
	}
}

//The function to print levels
void level(avl *n){
	int lev = height1(n);
	for (int i = 1; i < lev; ++i)
	{
		balance1(n, i);
	}
	for (int i = 2; i <= lev; ++i){
		print_nodes(n, i, 'S',n);
		printf("\n");
	}
}

//Driver function
int main(){
	avl *root = NULL;
	int data;
	scanf("%d", &data);
	root = insert_nodes(root, data, NULL);
	scanf("%d", &data);
	while(data!=-1){
		root = insert_nodes(root, data, root);
		scanf("%d", &data);
	}

	print_tree(root);
	printf("\n%d (%d B)\n", root->data, root->left->height-root->right->height);
	level(root);

	return 0;
}