#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double x, y, z, s1, s2, rez;
	cout << setprecision(4) << fixed;
	setlocale(0, "");
	cout << "Введите х: ";
	cin >> x;
	cout << "Введите y: ";
	cin >> y;
	cout << "Введите z: ";
	cin >> z;
	s1 = abs(pow(x, y / x) - pow(y / x, 1. / 3.));
	s2 = (cos(y) - (z / (y - x))) / (1 + pow((y - x), 2));
	rez = s1 + (s2 * (y - x));
	cout << "Результат: " << rez << endl;
	system("pause");
}
