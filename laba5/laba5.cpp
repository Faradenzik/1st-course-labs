#include <iostream>
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
			cout << "Введите число.\n";
		}
	}
	return input;
}

int main()
{
	int *arr, n, i, s, m;
	bool c = false;

	setlocale(0, "");
	
	s = 0;
	
	cout << "Введите размер массива: ";
	
	while (true)
	{
		n = inNum();
		if (n < 0)
		{
			cout << "Размер должен быть больше 0.\n";
		}
		else
		{
			break;
		}
	}

	arr = new int[n];
	
	cout << "Как заполнить массив?" << endl;
	
	do
	{

		cout << "1) Ввод значений вручную" << endl;
		cout << "2) Случайные числа в диапазоне [a,b]" << endl;
		m = inNum();
		
		switch (m)
		{
		case 1:
			for (i = 0; i < n; ++i)
			{
				cout << " a[" << i << "] =  ";
				arr[i] = inNum();
			}
			break;
		case 2:
			int a, b;

			cout << endl;
			cout << "Введите а: ";
			a= inNum();
			cout << "Введите b: ";
			b = inNum();

			if (a > b)
			{
				double swap;
				cout << "Поскольку a бoльше b, мы поменяли их местами" << endl;
				swap = a;
				a = b;
				b = swap;
			}

			srand(time(0));
			
			int num;
			
			for (int i = 0; i < n; i++)
			{
				num = rand() % (b - a + 1) + a;
				arr[i] = num;
			}
			
			cout << endl;
			cout << "Итоговый массив: " << endl;
			
			for (int i = 0; i < n; i++)
				cout << arr[i] << " ";
			
			cout << endl;
			break;
		default: cout << "Выберите из списка: " << endl;
		}
	}
	while (m != 1 && m != 2);

	if (arr[n - 1] == 0) // проверяет является ли последнее число нулём
	{
		cout << endl;
		cout << "Чисел после последнего нуля нет" << endl;

		system("pause");
		return(0);
	}
	else // проверка на наличие нулей в массиве
	{
		for (i = 0; i < n; i++)
		{
			if (arr[i] == 0)
			{
				c = true;
			}
		}
		if (c == false)
		{
			cout << "Нулей нет" << endl;

			system("pause");
			return(0);
		}
	}

	for (i = n - 2; i > 0; --i) // начиная с конца, ищет элемент равный нулю
	{
		if (arr[i] == 0)
			break;
	}

	for (i = i + 1; i < n; ++i) // начиная со следующего элемента, после нулевого, и до конца высчитывает сумму
	{
		s = s + arr[i];
	}
	cout << endl;
	cout << "Сумма чисел стоящих после 0: ";
	cout << s << endl;
	
	delete []arr;

	system("pause");
	return(0);
}
