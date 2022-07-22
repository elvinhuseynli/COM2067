#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[8] = {1,-1,-1,1,1,0,-1,0};
int y[8] = {1,-1,1,-1,0,1,0,-1};

void print_no_matrix()
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}

void print_array(char arr[15][15])
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

void encode_matrix(int dir, char word[15], int u, int v, int size)
{
	char new_arr[15][15];
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			new_arr[i][j] = '*';
		}
	}
	new_arr[u][v] = word[0];
	for (int i = 1; i < size; ++i)
	{
		u += x[dir];
		v += y[dir];
		new_arr[u][v] = word[i];
	}
	print_array(new_arr);
}

int check_endurance(char arr[15][15], char word[15], int dir, int size, int r, int c)
{
	for (int i = 2; i < size; ++i)
	{
		r += x[dir];
		c += y[dir];
		if (arr[r][c] != word[i])
			return 0;		
	}
	return 1;
}

int check_sides(char arr[15][15], char word[15], int i, int j, int size)
{
	for (int k = 0; k < 8; ++k)
	{
		int r = i + x[k], c = j + y[k];
		if (arr[r][c] == word[1])
		{
			//printf("%d %d %d\n", r, c, k);
			if(check_endurance(arr, word, k, size, r, c))
				return k;
		}
	}
	return -1;
}

void searching_word(char arr[15][15], char word[15], int size)
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			if (arr[i][j] == word[0])
			{
				//printf("%d %d\n", i, j);
				int t = check_sides(arr, word, i, j, size);
				if (t!=-1)
				{
					encode_matrix(t, word, i, j, size);
					return;
				}
			}
		}
	}
	print_no_matrix();
}

int main()
{
	char arr[15][15], word[15];
	int size=0;
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			scanf("%c ", &arr[i][j]);
		}
	}

	scanf("%s", word);
	int cntr= 0;
	while(1)
	{
		if (word[cntr] != '\0')
		{	
			size++;
			cntr++;
		}
		else
			break;
	}

	searching_word(arr, word, size);
}