/** C implementation for
	Red-Black Tree Insertion
	This code is provided by
	costheta_z **/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent each
// node in a red-black tree
typedef struct node {
	int d; // data
	char c; // 1-red, 0-black
	struct node* p; // parent
	struct node* r; // right-child
	struct node* l; // left child
}node;

// global root for the entire tree
struct node* root = NULL;

// function to perform BST insertion of a node
struct node* bst(struct node* trav,
					struct node* temp)
{
	// If the tree is empty,
	// return a new node
	if (trav == NULL)
		return temp;

	// Otherwise recur down the tree
	if (temp->d < trav->d)
	{
		trav->l = bst(trav->l, temp);
		trav->l->p = trav;
	}
	else if (temp->d > trav->d)
	{
		trav->r = bst(trav->r, temp);
		trav->r->p = trav;
	}

	// Return the (unchanged) node pointer
	return trav;
}

// Function performing right rotation
// of the passed node
void rightrotate(struct node* temp)
{
	struct node* left = temp->l;
	temp->l = left->r;
	if (temp->l)
		temp->l->p = temp;
	left->p = temp->p;
	if (!temp->p)
		root = left;
	else if (temp == temp->p->l)
		temp->p->l = left;
	else
		temp->p->r = left;
	left->r = temp;
	temp->p = left;
}

// Function performing left rotation
// of the passed node
void leftrotate(struct node* temp)
{
	struct node* right = temp->r;
	temp->r = right->l;
	if (temp->r)
		temp->r->p = temp;
	right->p = temp->p;
	if (!temp->p)
		root = right;
	else if (temp == temp->p->l)
		temp->p->l = right;
	else
		temp->p->r = right;
	right->l = temp;
	temp->p = right;
}

// This function fixes violations
// caused by BST insertion
void fixup(struct node* root, struct node* pt)
{
	struct node* parent_pt = NULL;
	struct node* grand_parent_pt = NULL;

	while ((pt != root) && (pt->c != 'B')
		&& (pt->p->c == 'R'))
	{
		parent_pt = pt->p;
		grand_parent_pt = pt->p->p;

		/* Case : A
			Parent of pt is left child
			of Grand-parent of
		pt */
		if (parent_pt == grand_parent_pt->l)
		{

			struct node* uncle_pt = grand_parent_pt->r;

			/* Case : 1
				The uncle of pt is also red
				Only Recoloring required */
			if (uncle_pt != NULL && uncle_pt->c == 'R')
			{
				grand_parent_pt->c = 'R';
				parent_pt->c = 'B';
				uncle_pt->c = 'B';
			}

			else {

				/* Case : 2
					pt is right child of its parent
					Left-rotation required */
				if (pt == parent_pt->r) {
					leftrotate(parent_pt);
					rightrotate(grand_parent_pt);
					char t = parent_pt->c;
					parent_pt->c = grand_parent_pt->c;
					grand_parent_pt->c = t;
				}

				/* Case : 3
					pt is left child of its parent
					Right-rotation required */
				else{
					rightrotate(grand_parent_pt);
					char t = parent_pt->c;
					parent_pt->c = grand_parent_pt->c;
					grand_parent_pt->c = t;
				}
			}
		}

		/* Case : B
			Parent of pt is right
			child of Grand-parent of
		pt */
		else {
			struct node* uncle_pt = grand_parent_pt->l;

			/* Case : 1
				The uncle of pt is also red
				Only Recoloring required */
			if ((uncle_pt != NULL) && (uncle_pt->c == 'R'))
			{
				grand_parent_pt->c = 'R';
				parent_pt->c = 'B';
				uncle_pt->c = 'B';
			}
			else {
				/* Case : 2
				pt is left child of its parent
				Right-rotation required */
				if (pt == parent_pt->l) {
					rightrotate(parent_pt);
					leftrotate(grand_parent_pt);
					char t = parent_pt->c;
					parent_pt->c = grand_parent_pt->c;
					grand_parent_pt->c = t;
				}

				/* Case : 3
					pt is right child of its parent
					Left-rotation required */
				else{
					leftrotate(grand_parent_pt);
					char t = parent_pt->c;
					parent_pt->c = grand_parent_pt->c;
					grand_parent_pt->c = t;
				}
			}
		}
	}

	root->c = 'B';
}

// Function to print inorder traversal
// of the fixated tree
void inorder(struct node* trav)
{
	if (trav == NULL)
		return;
	inorder(trav->l);
	printf("%d ", trav->d);
	inorder(trav->r);
}

//The function to print nodes according to depth-level
void print_nodes(node *n, int lvl, char a){
	if (n==NULL)
		return;
	if (lvl == 1){
		printf("%d %c (%d %c) ", n->d, n->c, n->p->d, a);
	}
	else if (lvl>1){
		print_nodes(n->l, lvl-1, 'L');
		print_nodes(n->r, lvl-1, 'R');
	}
}

//The function to find the height of tree
int height(node *n){
	if (n == NULL)
		return 0;
	else{
		int l = height(n->l);
		int r = height(n->r);
		if (l>r)
			return (l+1);
		else
			return (r+1);
	}
}

 //The function to print levels
void level(node *n){
	int lev = height(n);
	for (int i = 2; i <= lev; ++i){
		print_nodes(n, i, 'S');
		printf("\n");
	}
}

// driver code
int main()
{
	int n = 0, j=0, a[100];
	scanf("%d", &n);
	a[0] = n;
	while(n!=-1){
		scanf("%d", &n);
		a[++j] = n;
	}
	for (int i = 0; i < 9; i++) {

		// allocating memory to the node and initializing:
		// 1. color as red
		// 2. parent, left and right pointers as NULL
		// 3. data as i-th value in the array
		struct node* temp
			= (struct node*)malloc(sizeof(struct node));
		temp->r = NULL;
		temp->l = NULL;
		temp->p = NULL;
		temp->d = a[i];
		temp->c = 'R';

		// calling function that performs bst insertion of
		// this newly created node
		root = bst(root, temp);

		// calling function to preserve properties of rb
		// tree
		fixup(root, temp);
	}

	printf("Inorder Traversal of Created Tree\n");
	inorder(root);
	printf("\n%d %c\n", root->d, root->c);
	level(root);

	return 0;
}
