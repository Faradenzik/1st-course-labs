#include <iostream>
#include <conio.h>
using namespace std;

char Input(char* s)
{
    int i = 0;
    while (1) {
        s[i] = _getch();
        if (s[i] == 13) break;
        if (!(s[i] >= '0' && s[i] <= '9' || s[i] == ' '))   continue;
        cout << s[i];
        i++;
    }
    s[i] = '\0';
    return *s;
}

int main()
{
    setlocale(0, "");

    char s[151], st[40][10]; 
    cout << "Введите строку: ";
    Input(s);

    cout << endl;
    int i = 0, j = 0, k = 0;
    int arr[40];
    int size = strlen(s);

    if (s[i] == ' ') 
    {
        while (s[i] == ' ')
        {
            i++;
        }
    }

    if (s[size-1] == ' ') 
    {
        while (s[size-1] == ' ')
        {
            size -= 1;
        }
    }

    for (i; i < size; i++)
    {
        if (s[i] != ' ')
        {
            st[k][j] = s[i];
            j++;
        }
        else
        {
            while (s[i] == ' ') 
            {
                i++;
            }
            i--;
            k++; 
            j = 0;
        }
    }
    
    for (j = 0; j <= k; j++)
    {
        arr[j] = atoi(st[j]);
    }

    int temp;
    for (i = 0; i <= k - 1; i++)
    {
        for (j = i + 1; j <= k; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "Отсортированная строка: ";
    for (j = 0; j <= k; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl << endl;

    system("pause");
}