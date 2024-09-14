#include <iostream>
#include <random>
using namespace std;

int func1(int a = 1)
{
    if (a <= 0)
        return 0;
    else
        {
            int sm = a;
            for (int i = 1; i < a; i++)
                sm += i;
            return sm;
        }
}


void func2(int a, int b, int &t1, int &t2)
{
    t1 = a + b;
    t2 = a * b;
}


int main()
{
    int A[2][3]{{1, 2, 3}, {4, 5, 6}};
    int sm = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            sm += A[i][j];
    cout << "Сумма элементов массива: " << sm << endl;
    
    int B[3];
    for (int j = 0; j < 3; j++)
        B[j] = A[0][j] + A[1][j];
    cout << B[0] << ' ' << B[1] << ' ' << B[2];
    
    cout << endl;
    
    float z = 20.84;
    cout << "Изначальная переменная: " << z << endl;
    float &s1 = z, &s2 = z;
    s1 = 639;
    cout << "После изменения значения на 639: " << z << " " << s1 << " " << s2 << endl;
    
    cout << "Вызов функции 1 без аргумента:" << func1() << endl;
    int a = 2, b = 3, c = 4, d = 5;
    func2(a, b, c, d);
    cout << "Значения после вызова функции 2: " << c << " " << d << endl;
    
    double temp = 63963;
    cout << "Вывод 'любой' перменной: " << temp << endl;
    for (int z = 0; z < 3; z++)
    {
        int k = 66;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                cout << A[i][j];
        cout << ' ' << k << endl;
    }
    // cout << k; ОШИБКА КОМПИЛЯТОРА
    return 0;
}