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
			cout << "������� �����.\n";
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
	
	cout << "������� ������ �������: ";
	
	while (true)
	{
		n = inNum();
		if (n < 0)
		{
			cout << "������ ������ ���� ������ 0.\n";
		}
		else
		{
			break;
		}
	}

	arr = new int[n];
	
	cout << "��� ��������� ������?" << endl;
	
	do
	{

		cout << "1) ���� �������� �������" << endl;
		cout << "2) ��������� ����� � ��������� [a,b]" << endl;
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
			cout << "������� �: ";
			a= inNum();
			cout << "������� b: ";
			b = inNum();

			if (a > b)
			{
				double swap;
				cout << "��������� a �o���� b, �� �������� �� �������" << endl;
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
			cout << "�������� ������: " << endl;
			
			for (int i = 0; i < n; i++)
				cout << arr[i] << " ";
			
			cout << endl;
			break;
		default: cout << "�������� �� ������: " << endl;
		}
	}
	while (m != 1 && m != 2);

	if (arr[n - 1] == 0)
	{
		cout << endl;
		cout << "����� ����� ���������� ���� ���" << endl;

		system("pause");
		return(0);
	}
	else
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
			cout << "����� ���" << endl;

			system("pause");
			return(0);
		}
	}

	for (i = n - 2; i > 0; --i)
	{
		if (arr[i] == 0)
			break;
	}

	for (i = i + 1; i < n; ++i)
	{
		s = s + arr[i];
	}

	cout << endl;
	cout << "����� ����� ������� ����� 0: ";
	cout << s << endl;
	
	delete []arr;

	system("pause");
	return(0);
}