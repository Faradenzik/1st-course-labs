#include <iostream>
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

double val_S(double a, double b, double h, double n)
{
	double S = 0, r;
	r = a;
	for (int k = 1; k <= n; k++)
	{
		r *= a * a;
		S = S + ((pow(-1, k + 1) * r / (4 * pow(k, 2) - 1)));
	}
	return S;
}

double val_Y(double a)
{
	double Y;
	Y = (((1 + pow(a, 2)) / 2) * atan(a)) - (a / 2);
	return Y;
}

void out_rez(double a, double b, double h, double n)
{
	cout << endl << "Выберите функцию для вывода" << endl;
	cout << "1) S(x)" << endl;
	cout << "2) Y(x)" << endl;
	cout << "3) |Y(x) - S(x)|" << endl;
	cout << "4) Все функции" << endl;
	
	int ch;

	while (true)
	{
		cin >> ch;
		cout << endl;
		if (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Недопустимое значение.\n";

			cout << endl << "Выберите функцию для вывода" << endl;
			cout << "1) S(x)" << endl;
			cout << "2) Y(x)" << endl;
			cout << "3) |Y(x) - S(x)|" << endl;
			cout << "4) Все функции" << endl;
		}
		else if (ch < 1 || ch > 4)
		{
			cout << "Недопустимое значение.\n";
			
			cout << endl << "Выберите функцию для вывода" << endl;
			cout << "1) S(x)" << endl;
			cout << "2) Y(x)" << endl;
			cout << "3) |Y(x) - S(x)|" << endl;
			cout << "4) Все функции" << endl;
		}
		else
		{
			break;
		}
	}

	switch (ch)
	{
	case 1:
		cout << "x\t\tS(x)" << endl;
		for (a; a <= b; a += h)
		{
			cout << a << "\t\t" << val_S(a, b, h, n) << endl;
		}
		break;
	case 2:
		cout << "x\t\tY(x)" << endl;
		for (a; a <= b; a += h)
		{
			cout << a << "\t\t" << val_Y(a) << endl;
		}
		break;
	case 3:
		cout << "x\t\t|Y(x) - S(x)|" << endl;
		for (a; a <= b; a += h)
		{
			cout << a << "\t\t" << fabs(val_Y(a) - val_S(a, b, h, n)) << endl;
		}
		break;
	case 4:
		cout << "x\t\tY(x)\t\t" << "S(x)\t\t" << "|Y(x) - S(x)|\t" << endl;
		for (a; a <= b; a += h)
		{
			cout << a << "\t\t" << val_Y(a) << "\t" << val_S(a, b, h, n) << "\t" << fabs(val_Y(a) - val_S(a, b, h, n)) << "\t" << endl;
		}
		break;
	}
}

int main()
{
	setlocale(0, "");
	
	double a, b, h, n;

	cout << "Введите a: ";
	a = inNum();
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

	while (true)
	{
		cout <<  "Введите h: ";
		h = inNum();
		if (h > 0)
		{
			break;
		}
		else
		{
			cout << "Недопустимое значение.\n" << endl;
		}
	}

	cout << "Введите n: ";
	n = inNum();

	out_rez(a, b, h, n);

	cout << endl;

	system("pause");
}