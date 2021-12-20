#include <iostream>
#include "algorithm"
#include <ctime>
#include <cstdlib>
using namespace std;

double inNum()
{
	double input;
	while (true)
	{
		cin >> input;
		if (cin.get() == '\n')
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Недопустимое значение.\n";
		}
	}
	return input;
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int n, m;
	int **matr;

	cout << "Сортировка по возрастанию" << endl;
	cout << endl;
	cout << "Введите кол-во строк(n): ";
	while (true)
	{
		n = inNum();
		if (n<1)
		{
			cout << endl << "Недопустимое значение." << endl;
		}
		else
		{
			break;
		}
	}

	cout << "Введите кол-во столбцов(m): ";

	while (true)
	{
		m = inNum();
		if (m < 1)
		{
			cout << endl << "Недопустимое значение." << endl;
		}
		else
		{
			break;
		}
	}
	
	matr = new int *[n];
	
	for (int i = 0; i < n; i++)
		matr[i] = new int[m];
	
	int ch;
	do
	{
		cout << "Выберите способ заполнения" << endl;
		cout << "1) Случайными числами" << endl;
		cout << "2) Вручную" << endl;
		ch = inNum();
		switch (ch)
		{
		case 1:
			int a, b;

			cout << "Введите промежуток: " << endl;
			cout << "a = ";
			a = inNum();
			cout << "b = ";
			b = inNum();

			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					matr[i][j] = rand() % (b-a+1) + a;
			break;
		case 2:
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					cout << "a[" << i << "][" << j << "] = ";
					matr[i][j] = inNum();
				}
			break;
		default: cout << "Выберите из списка: " << endl;
		}
	}while (ch != 1 && ch != 2);

	cout << endl;
	cout << "Исходная матрица" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << "\t";
		cout << endl;
	}

	cout << endl;

	int* max_index = new int[n];
	for (int i = 0; i < n; i++)
	{
		int mi = matr[i][0];
		for (int r = 1; r < m; r++)
			if (mi < matr[i][r])
				mi = matr[i][r];

		max_index[i] = mi;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j+1 < n; j++)
			if (max_index[j] > max_index[j + 1])
			{
				swap(max_index[j], max_index[j + 1]);
				swap(matr[j], matr[j + 1]);
			}
	}

	cout << "Итоговая матрица" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << "\t";
		cout << endl;
	}

	delete []max_index;

	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;

	system("pause");
}