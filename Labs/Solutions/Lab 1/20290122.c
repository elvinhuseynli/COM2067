#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

//The function to print matrix or 2D array

void print_array(int arr[10][10], int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

//The function to find minimum ditance between two cities

int min_dist(int dist[], int sep[])
{
    int min = MAX, min_index;
   
    for (int v = 0; v < 10; v++)
        if (sep[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
   
    return min_index;
}

//The function returning path

void return_path(int path[], int j, int arr[10], int k)
{   
    if (path[j] == - 1)
    {
        arr[0] = k;
        return;
    }
    arr[k] = j;
    k++;
    return_path(path, path[j], arr, k);
}

//Needed function prototype
int* functionFindMin(int* array, int row, int cols, char source, char destination)
{
    int arr[10][10], k=1, counter=0, dep, des, dist[10], path[10], temp[10], cntr=2, total[10];
    dep = source - 'A';
    des = destination - 'A';
    int sep[10];

    //Converting the pointer with counter to a 2D array
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            arr[i][j] = *(array+counter);
            counter++;
        }
    }
    //print_array(arr, row, cols);

    for (int i = 0; i < 10; i++)
    {
        path[i] = -1;
        dist[i] = MAX;
        sep[i] = 0;
    }
   
    dist[dep] = 0;
   
    for (int count = 0; count < 9; count++)
    {
        int u = min_dist(dist, sep);
   
        sep[u] = 1;
   
        for (int v = 0; v < 10; v++)
        {
            if (!sep[v] && arr[u][v] && dist[u] + arr[u][v] < dist[v])
            {
                path[v] = u;
                dist[v] = dist[u] + arr[u][v];
            } 
        }
    }
    
    return_path(path, des, temp, k);
   
    k = temp[0];
    total[1] = dep;
    for (int i = k-1; i > 0; --i)
    {
        total[cntr] = temp[i];
        cntr++;
    }

    total[cntr] = dist[des];
    total[0] = cntr;

    int *new = &total[0];

    return new;
}

// Main Function

int main()
{
	int arr[10][10];
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			int n;
			scanf("%d", &n);
			if (n<=0)
				arr[i][j] = 0;
			else
				arr[i][j] = n;
		}
	}
    char src, dest;
	scanf(" %c %c", &src, &dest);
    //print_array(arr, 10, 10);
    //Calling the function needed
    int *res = functionFindMin(&arr[0][0], 10, 10, src, dest);
    int n = (*res);
    int dist = *(res+n);
    if (n<=2) printf("You cannot travel between two cities\n");
    else{
        for (int i = 1; i < n-1; ++i)
        {
            printf("%c-", *(res+i)+'A');
        }
        printf("%c %d\n", *(res+n-1)+'A', dist);
    }
	return 0;
}
