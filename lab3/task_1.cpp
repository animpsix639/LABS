#include <iostream>
using namespace std;

int main()
{
    int a = 17;
    int* ptr = &a;

    cout << "Адрес указателя: " << ptr << endl;
    cout << "Значение указателя: " << ptr << endl;

    *ptr = 14;

    cout << "Новое значеине указателя: " << ptr << endl;

    cout << endl;

    int arr[]{1, 2, 3, 4, 5};
    int* arrPtr = arr;

    for(int i = 0; i < 5; ++i)
        cout << *(arrPtr + i) << endl;

    cout << endl;

    int constA = 5;
    int* const constPtr = &constA;

    // constPtr = &a; Ошибка
    *constPtr = 10;
    cout << "Новое значение переменной: " << constA << endl;

    return 0;
}