  typedef struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
}nC;

//Struct for Student child linked lists
typedef struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
}nS;


//The function to sort and insert nodeStudent for Class 1
void class1(nC **n, int id, int mt)
{
	nS *ptr = (*n)->studentPtr;
	nS *new_node = (nS*) malloc(sizeof(nS));
	new_node->studentID = id;
	new_node->midterm = mt;
	if ((*n)->studentPtr == NULL || (*n)->studentPtr->midterm <= new_node->midterm) 
	{
        new_node->next = (*n)->studentPtr;
        (*n)->studentPtr = new_node;
    }
    else
    {
    	while (ptr->next != NULL && ptr->next->midterm > new_node->midterm) 
    	{
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

//The function to sort and insert nodeStudent for Class 2
void class2(nC **n, int id, int mt)
{
	nS *ptr = (*n)->studentPtr;
	nS *new_node = (nS*) malloc(sizeof(nS));
	new_node->studentID = id;
	new_node->midterm = mt;
	if ((*n)->studentPtr == NULL || (*n)->studentPtr->midterm <= new_node->midterm) 
	{
        new_node->next = (*n)->studentPtr;
        (*n)->studentPtr = new_node;
    }
    else
    {
    	while (ptr->next != NULL && ptr->next->midterm > new_node->midterm) 
    	{
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }	
}

//The function to sort and insert nodeStudent for Class 3
void class3(nC **n, int id, int mt)
{
	nS *ptr = (*n)->studentPtr;
	nS *new_node = (nS*) malloc(sizeof(nS));
	new_node->studentID = id;
	new_node->midterm = mt;
	if ((*n)->studentPtr == NULL || (*n)->studentPtr->midterm <= new_node->midterm) 
	{
        new_node->next = (*n)->studentPtr;
        (*n)->studentPtr = new_node;
    }
    else
    {
    	while (ptr->next != NULL && ptr->next->midterm > new_node->midterm) 
    	{
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }	
}

//The function to sort and insert nodeStudent for Class 4
void class4(nC **n, int id, int mt)
{
	nS *ptr = (*n)->studentPtr;
	nS *new_node = (nS*) malloc(sizeof(nS));
	new_node->studentID = id;
	new_node->midterm = mt;
	if ((*n)->studentPtr == NULL || (*n)->studentPtr->midterm <= new_node->midterm) 
	{
        new_node->next = (*n)->studentPtr;
        (*n)->studentPtr = new_node;
    }
    else
    {
    	while (ptr->next != NULL && ptr->next->midterm > new_node->midterm) 
    	{
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }	
}

//The function to seperate classes into different functions
void insert(nC **n, int id, int mt)
{
	int ca = id / 1000;
	nC *ptr = (*n), *new_node = (nC*) malloc(sizeof(nC));
	switch(ca)
	{
		case 66:
			new_node->classID = 1;
			new_node->next = NULL;
			new_node->studentPtr = NULL;
			if (*n == NULL)
			{
				*n = new_node;
				return;
			}
			else
			{
				ptr = new_node;
			}
			class1(&ptr, id, mt);
			break;
		case 77:
			new_node->classID = 1;
			new_node->next = NULL;
			new_node->studentPtr = NULL;
			if (*n == NULL)
			{
				*n = new_node;
				return;
			}
			else
			{
				while(ptr->next!=NULL)
					ptr = ptr->next;
				ptr = new_node;
			}
			class1(&ptr, id, mt);
			break;
		case 88:
			new_node->classID = 1;
			new_node->next = NULL;
			new_node->studentPtr = NULL;
			if (*n == NULL)
			{
				*n = new_node;
				return;
			}
			else
			{
				while(ptr->next!=NULL)
					ptr = ptr->next;
				ptr = new_node;
			}
			class3(&ptr, id, mt);
			break;
		case 99:
			new_node->classID = 1;
			new_node->next = NULL;
			new_node->studentPtr = NULL;
			if (*n == NULL)
			{
				*n = new_node;
				return;
			}
			else
			{
				while(ptr->next!=NULL)
					ptr = ptr->next;
				ptr = new_node;
			}
			class4(&ptr, id, mt);
			break;
	}
}

void print(nC **n)
{
	nC *ptr = (*n);
	while(ptr->next!=NULL)
	{
		nS *ptr1 = ptr->studentPtr;
		double aver = 0;
		int cntr =0;
		printf("%d\n", ptr->classID);
		while(ptr1->next!=NULL)
		{
			aver += ptr1->midterm;
			cntr++;
			printf("%d %d\n", ptr1->studentID, ptr1->midterm);
			ptr1 = ptr1->next;
		}
		ptr->classMidtermAverage = aver/cntr;
		printf("%d\n", ptr->classMidtermAverage);
		ptr = ptr->next;
	}
}


 