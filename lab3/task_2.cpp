#include <iostream>
using namespace std;

int sumArr(int* start, int* end){
    int sum = 0;
    for(int* ptr = start; ptr != end; ++ ptr)
        sum += *ptr;
    return sum;
}

int sum(int a, int b){
    return a + b;
}

int diff(int a, int b){
    return a - b;
}

int (*tempFunc(char sign))(int, int){
    if (sign == '+'){
        return &sum;
    }
    else if (sign == '-'){
        return &diff;
    }
    return 0;
}

int main(){
    int arr[]{1, 2, 3, 4, 5};
    int* start = arr;
    int* end = arr + 5;

    int total = sumArr(start, end);
    cout << "Сумма массива: " << total << endl;

    char sign;
    cout << "Введите знак (+/-): ";
    cin >> sign;
    cout << endl;

    int (*ptrFunc)(int, int) = tempFunc(sign);
    if (ptrFunc){
        int res = ptrFunc(10, 5);
        cout << "Результат: " << res << endl; 
    } else { 
        cout << "Неверный знак" << endl;
    }

    float* dynamic = new float(2.28f);
    cout << "Значение динамической переменной: " << *dynamic << endl;

    delete dynamic;
    
    return 0;
}