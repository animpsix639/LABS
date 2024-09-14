#include <iostream>
using namespace std;

int main()
{
    int a = -1;
    while (a < 0)
    {
        cout << "Введите челое положительное число: ";
        cin >> a;
    }
    int sm = a;
    for (int i = 1; i < a; i++)
        sm += i;
    cout << "Сумма от 1 до N: " << sm << endl;
    
    int x[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    
    for (int i = 0; i < 10; i++)
        cout << x[i] << ' ';
    cout << endl;
    for (int i = 0; i < 10; i++)
        if (i % 2 == 0)
            cout << x[i] << ' ';
    cout << endl;
    int _ = 0;
    for (int i = 0; i < 10; i++)
        if (i % 2 != 0)
            _ += x[i];
    cout << "Сумма элементов на нечетных позициях: " << _ << endl;
    
    return 0;
}