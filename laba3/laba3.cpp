#include <iostream>
#include "math.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, k;
	double x, S, Y, a, b, h, R, r;
	
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	cout << "Введите h: ";
	cin >> h;
	cout << "Введите n: ";
	cin >> n;

	cout << endl << "x " << "\t\t" << "Y(x)\t\t\t" << "S(x)\t\t\t" << "|Y(x) - S(x)|" << endl;

	for (x = a; x <= b; x += h)
	{
		S = 0;
		Y = 0;
		r = x;
		for (k = 1; k <= n; k++)
		{
			r *= x * x;
			S = S + ((pow(-1, k + 1) * r / (4 * pow(k, 2) - 1)));
		}
		Y = (((1 + pow(x, 2)) / 2) * atan(x)) - (x / 2);
		R = fabs(Y - S);
		cout << x << "\t\t" << Y << "\t\t" << S << "\t\t" << R << endl;
	}

	cout << endl;
	system("pause");
}