#include <iostream>
#include "math.h"
#include <conio.h>

using namespace std;

int main()
{
    setlocale(0, "");
    
    double a, b, z, x, y, f;
    char n;

    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите z: ";
    cin >> z;

    if (z <= 0)
    {
        x = pow(z, 2) / 2;
    }
    else
    {
        x = pow(z, 0.5);
    }

    cout << "Выберите значение функции: " << endl;
    
    do
    {
        cout << "1)f(x)=2x  ";
        cout << "2)f(x)=x*x  ";
        cout << "3)f(x)=x/3  " << endl;
        cin >> n;
        switch (n)
        {
        case '1':
            f = 2 * x; cout << "1)f(x)=2x" << endl;
            break;
        case '2':
            f = pow(x, 2); cout << "2)f(x)=x*x" << endl;
            break;
        case '3':
            f = x / 3.; cout << "3)f(x)=x/3" << endl;
            break;
        default: cout << "Недопустимое значение" << endl;
        }
    } while (n != '1' && n != '2' && n != '3');
    y = b * (f / cos(x)) + a * log(fabs(tan(x / 2)));
    cout << "Результат: " << y << endl;
    
    system("pause");
}