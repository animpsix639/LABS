#include <iostream>
using namespace std;

int main()
{
    float a, b, c;
    char ch;
    cout << "Введите два числа: " << endl;
    cin >> a >> b;
    c = (a + b) / 2;
    cout << "Среднее арифмитическое: " << c << endl;
    cout << "Введите знак операции (+, -, * или /): ";
    cin >> ch;
    // if (ch == '+')
    //     cout << a + b;
    // else if (ch == '-')
    //     cout << a - b;
    // else if (ch == '*')
    //     cout << a * b;
    // else if (ch == '/')
    //     cout << a / b;
    // else
    // {
    //     cout << "Введен неправильный знак" << endl;
    //     return 0;
    // }
    switch (ch)
    {
        case '+':
            cout << a + b;
            break;
        case '-':
            cout << a - b;
            break;
        case '*':
            cout << a * b;
            break;
        case '/':
            cout << a / b;
            break;
        default:
            cout << "Введен неправильный знак" << endl;
            break;
    }
    return 0;
}