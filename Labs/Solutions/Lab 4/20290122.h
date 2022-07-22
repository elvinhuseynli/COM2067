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

nS *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

//The function to sort and insert nodeStudent for STUDENTS
void StudentSorting(nS **n, int id, int mt)
{
	nS *ptr = (*n); 
	nS *new_node = (nS*) malloc(sizeof(nS));
	//printf("hello anan\n");
	new_node->studentID = id;
	new_node->midterm = mt;
	if (*n == NULL || (*n)->midterm < new_node->midterm)
	{
        new_node->next = *n;
        *n = new_node;
    }
    else
    {
    	while (ptr->next != NULL && (ptr->next->midterm > new_node->midterm || (ptr->next->midterm == new_node->midterm && ptr->next->studentID<new_node->studentID)))
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
	//printf("hello\n");
	switch(ca)
	{
		case 66:
			//printf("hello1\n");
			StudentSorting(&r1, id, mt);
			new_node->classID = 1;
			new_node->next = NULL;
			new_node->studentPtr = r1;
			if (*n == NULL)
			{
				*n = new_node;
			}
			else
			{
				while(1)
				{
					if (ptr->classID!=new_node->classID && (ptr->next==NULL) && (ptr->studentPtr!=NULL)){
						ptr->next = new_node;
						break;
					}
					else if(ptr->classID == new_node->classID && (ptr->studentPtr!=NULL))
					{
						break;
					}
					else
					{
						ptr = ptr->next;
					}
				}
			}
			break;
		case 77:
			//printf("hello2\n");
			StudentSorting(&r2, id, mt);
			new_node->classID = 2;
			new_node->next = NULL;
			new_node->studentPtr = r2;
			if (*n == NULL)
			{
				*n = new_node;
			}
			else
			{
				while(1)
				{
					if (ptr->classID!=new_node->classID && (ptr->next==NULL) && (ptr->studentPtr!=NULL)){
						ptr->next = new_node;
						break;
					}
					else if(ptr->classID == new_node->classID && (ptr->studentPtr!=NULL))
					{
						break;
					}
					else
					{
						ptr = ptr->next;
					}
				}
			}
			break;
		case 88:
			//printf("hello3\n");
			StudentSorting(&r3, id, mt);
			new_node->classID = 3;
			new_node->next = NULL;
			new_node->studentPtr = r3;
			if (*n == NULL)
			{
				*n = new_node;
			}
			else
			{
				while(1)
				{
					if (ptr->classID!=new_node->classID && (ptr->next==NULL) && (ptr->studentPtr!=NULL)){
						ptr->next = new_node;
						break;
					}
					else if(ptr->classID == new_node->classID && (ptr->studentPtr!=NULL))
					{
						break;
					}
					else
					{
						ptr = ptr->next;
					}
				}
			}
			break;
		case 99:
			//printf("hello4\n");
			StudentSorting(&r4, id, mt);
			new_node->classID = 4;
			new_node->next = NULL;
			new_node->studentPtr = r4;
			if (*n == NULL)
			{
				*n = new_node;
			}
			else
			{
				while(1)
				{
					if (ptr->classID!=new_node->classID && (ptr->next==NULL) && (ptr->studentPtr!=NULL)){
						ptr->next = new_node;
						break;
					}
					else if(ptr->classID == new_node->classID && (ptr->studentPtr!=NULL))
					{
						break;
					}
					else
					{
						ptr = ptr->next;
					}
				}
			}
			break;
	}
}
void computeClassAverage(nC *n)
{
	nC *ptr2 = n;
	for (int i = 0; i < 4; ++i)
	{
		double aver = 0.0;
		int cnt = 0;
		if(i==0) 
		{
			if (r1 == NULL)
				continue;
			nS *ptr = r1;
			while(ptr!=NULL)
			{
				aver+=ptr->midterm;
				cnt++;
				ptr = ptr->next;
			}
			aver = aver/cnt;
			ptr2->classMidtermAverage = aver;
		}
		else if(i==1) 
		{
			if (r2 == NULL)
				continue;
			nS *ptr = r2;
			while(ptr!=NULL)
			{
				aver+=ptr->midterm;
				cnt++;
				ptr = ptr->next;
			}
			aver = aver/cnt;
			ptr2->classMidtermAverage = aver;
		}
		else if(i==2) 
		{
			if (r3 == NULL)
				continue;
			nS *ptr = r3;
			while(ptr!=NULL)
			{
				aver+=ptr->midterm;
				cnt++;
				ptr = ptr->next;
			}
			aver = aver/cnt;
			ptr2->classMidtermAverage = aver;
		}
		else if(i==3) 
		{
			if (r4 == NULL)
				continue;
			nS *ptr = r4;
			while(ptr!=NULL)
			{
				aver+=ptr->midterm;
				cnt++;
				ptr = ptr->next;
			}
			aver = aver/cnt;
			ptr2->classMidtermAverage = aver;
		}
		ptr2 = ptr2->next;
	}
}
void printAll(nC *n)
{
	nC *ptr2 = n;
	for (int i = 0; i < 4; ++i)
	{
		if(i==0) 
		{
			if (r1 == NULL)
				continue;
			nS *ptr = r1;
			printf("%d %.2lf\n", 1, ptr2->classMidtermAverage);
			while(ptr!=NULL)
			{
				printf("%d %d\n", ptr->studentID, ptr->midterm);
				ptr = ptr->next;
			}
		}
		else if(i==1) 
		{
			if (r2 == NULL)
				continue;
			nS *ptr = r2;
			printf("%d %.2lf\n", 2, ptr2->classMidtermAverage);
			while(ptr!=NULL)
			{
				printf("%d %d\n", ptr->studentID, ptr->midterm);
				ptr = ptr->next;
			}
		}
		else if(i==2) 
		{
			if (r3 == NULL)
				continue;
			nS *ptr = r3;
			printf("%d %.2lf\n", 3, ptr2->classMidtermAverage);
			while(ptr!=NULL)
			{
				printf("%d %d\n", ptr->studentID, ptr->midterm);
				ptr = ptr->next;
			}
		}
		else if(i==3) 
		{
			if (r4 == NULL)
				continue;
			nS *ptr = r4;
			printf("%d %.2lf\n", 4, ptr2->classMidtermAverage);
			while(ptr!=NULL)
			{
				printf("%d %d\n", ptr->studentID, ptr->midterm);
				ptr = ptr->next;
			}
		}
		ptr2 = ptr2->next;
	}
}


