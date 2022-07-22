typedef struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
}FB;

typedef struct nodeGS
{
	int id;
	struct nodeGS *next;
}GS;

typedef struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
}nFB;

typedef struct newNodeGS
{
	int id;
	struct newNodeFB *next;
}nGS;

//The function that creates the linked list with given values for FB
void insertFB(FB **n, int ID, int AGE)
{
	FB *new_node = (FB*) malloc(sizeof(FB));
	FB *ptr = (*n);
	new_node->id = ID;
	new_node->age = AGE;
	if (*n == NULL || (*n)->id>= new_node->id) 
	{
        new_node->next = *n;
        *n = new_node;
    }
    else
    {
    	while (ptr->next != NULL && ptr->next->id < new_node->id) 
    	{
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

//The function that creates the linked list with given values for GS
void insertGS(GS **n, int ID)
{
	GS *new_node = (GS*) malloc(sizeof(GS));
	GS *ptr = (*n);
	new_node->id = ID;
	if (*n == NULL || (*n)->id <= new_node->id) 
	{
        new_node->next = *n;
        *n = new_node;
    }
    else
    {
    	while (ptr->next != NULL && ptr->next->id > new_node->id) 
    	{
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}
//The funtion printing linked list of FB
void printFB(FB *ll)
{
	FB *ptr = ll;
	while(ptr!=NULL)
	{
		printf("%d %d\n", ptr->id, ptr->age);
		ptr = ptr->next;
	}
	printf("\n");
}

//The funtion printing linked list of GS
void printGS(GS *ll)
{
	GS *ptr = ll;
	while(ptr!=NULL)
	{
		printf("%d\n", ptr->id);
		ptr = ptr->next;
	}
	printf("\n");
}

//The function that concatenates two linked lists
void createFinalList(nFB **n, FB *k, GS *m)
{
	FB *ptr1 = k;
	GS *ptr2 = m;
	(*n) = (nFB*) malloc(sizeof(nFB));
	nFB *new_node1 = (*n);
	nGS *new_node2 = (nGS*) malloc(sizeof(nGS));
	while(ptr1!=NULL)
	{
		new_node1->id = ptr1->id;
		new_node1->age = ptr1->age;
		ptr1 = ptr1->next;
		new_node2 = (nGS*) malloc(sizeof(nGS));
		new_node1->next = new_node2;
		new_node2->id = ptr2->id;
		new_node1 = (nFB*) malloc(sizeof(nFB));
		if (ptr2->next!=NULL) new_node2->next = new_node1;
		else new_node2->next = NULL;
		ptr2 = ptr2->next;
	}
}

void printAll(nFB *ll)
{
	while(ll!=NULL)
	{
		printf("%d %d\n%d\n", ll->id, ll->age, ll->next->id);
		ll = ll->next->next;
	}

}