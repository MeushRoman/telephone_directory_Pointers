// ConsoleApplication29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

//добавление номера
void add(int **&a, int &n)
{

	int **tmp;
	int cod, numb;
	int x = 2;
	tmp = new int*[x];
	tmp[0] = new int[n + 1];
	tmp[1] = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		tmp[0][i] = a[0][i];
		tmp[1][i] = a[1][i];
	}


	cin >> cod >> numb;

	tmp[0][n] = cod;
	tmp[1][n] = numb;

	if (n != 0) {
		for (int i = 0; i < x; i++)
		{
			delete[] a[i];
		}

		delete[] a;

	}
	a = tmp;
	n++;
}
//распечатка номеров
void print(int **a, int size) {

	for (int i = 0; i < size; i++)
	{
		cout << i << ". = " << a[0][i] << " " << a[1][i] << endl;
	}
}

//Поиск номера
void search(int **a, int size) {
	int se, c = 0;

	cout << "vvedite nomer dlya poiska: ";
	cin >> se;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (se == a[i][j]) {
				c = 1;
				break;
			}
		}
	}
	if (c == 1) cout << "Nomer naiden!" << endl; else cout << "Nomer ne naiden!" << endl;
}
// сортировка номера
void sort(int **&a, int size, int type) {
	for (int pass = 0; pass < size - 1; pass++)
	{
		for (int i = 0; i < size-1; i++)
		{
			switch (type)
			{
			case 0:
				if (a[0][i]>a[0][i + 1]) {
					swap(a[1][i], a[1][i + 1]);
					swap(a[0][i], a[0][i + 1]);
				}
				break;
			case 1:

				if (a[1][i]>a[1][i + 1]) {
					swap(a[1][i], a[1][i + 1]);
					swap(a[0][i], a[0][i + 1]);
				}
				break;
			
			}
		}
	}
}


int main()
{

	int **a;
	int n = 2, m = 0;
	int type;

	a = new int *[n];

	int rr = 1;
	do
	{
		cout << "1. add; 2. sort; 3. search; 4.print; 5. delete number; 0. exit; = ";
		cin >> rr;
		switch (rr)
		{
		case 1: add(a, m);
			break;
		case 2:
		{
			cout << "0. sortirovat' po kody goroda; 1. sortirovat' po nomery telefona;" << endl;
			cin >> type;
			sort(a, m, type);
			
		}
			break;
		case 3: search(a, m);
			break;
		case 4: print(a, m);
			break;
		case 5: // delete
			break;
		case 0: //Exit(a, n, m);
			break;
		}

	} while (true);

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}

	delete[] a;

	return 0;
}

