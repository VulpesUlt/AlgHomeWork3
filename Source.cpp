#include <stdio.h>
#include <iostream>
#include <time.h>

//Task 1
const int TASKONENUM = 1236;

//Task 2
const int TASKTWOA = 5;
const int TASKTWOB = 9;

//Task 3
const int FIELDSIZE = 8;

// Task 1
long long int decToBin (int num)
{
	long long int sum = 0;
	if (num > 1)
	{
		sum += decToBin(num / 2);
		sum *= 10;
		return sum += num % 2;
	}
	else
	{
		return 1;
	}
}

// Task 2
int exponVar1(int num, int deg)
{
	if (deg >= 1)
		return num *= exponVar1(num, deg - 1);
	else
		return 1;
}

int exponVar2(int num, int deg)
{
	if (deg % 2 == 0 && deg >= 1)
		return num = exponVar2(num, deg / 2) * exponVar2(num, deg / 2);
	else if (deg % 2 == 1 && deg >= 1)
		num *= exponVar1(num, deg - 1);
	else
		return 1;
}
//Task 3
void initField(int (*arrPtr)[FIELDSIZE], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arrPtr[i][j] = 0;

	srand(time(NULL));
	for (int i = 0; i < size / 2; i++)
		arrPtr[rand() % size][rand() % size] = 1;
}

void printField(int(*arrPtr)[FIELDSIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d %c", arrPtr[i][j], ' ');
		printf("\n");
	}
}

int uniqPath(int(*arrPtr)[FIELDSIZE], int x, int y)
{
	if ((x == 0 && y == 0) || arrPtr[x][y] == 1)
		return 0;
	else if (x == 0 && arrPtr[x - 1][y] == 1)
		return uniqPath(arrPtr, x, y + 1);
	else if (y == 0 && arrPtr[x][y - 1] == 1)
		return uniqPath(arrPtr, x + 1, y);
	else if (x == 0 || y == 0)
		return 1;
	else
		return uniqPath(arrPtr, x - 1, y) + uniqPath(arrPtr, x, y - 1);
}

int main ()
{
	// Task 1
	printf("%s%lld%s","Task1:\n", decToBin(TASKONENUM), "\n \n");
	
	//Task 2
	printf("%s%d%s", "Task2:\n", exponVar1(TASKTWOA, TASKTWOB), "\n");
	printf("%d%s", exponVar2(TASKTWOA, TASKTWOB), "\n \n");

	//Task 3
	int field[FIELDSIZE][FIELDSIZE];
	
	printf("Task3: \n");
	initField(field, FIELDSIZE);
	printField(field, FIELDSIZE);
	
	for (int i = 0; i < FIELDSIZE; i++)
	{
		for (int j = 0; j < FIELDSIZE; j++)
			printf("%3d %c", uniqPath(field, i, j), ' ');
		printf("\n");
	}
	
	return 0;
}