#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a = 150;
    float b = 15.933;
    unsigned char c = 250;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << static_cast<int>(c) << endl;

    int day = 31;
    string month = "Май";
    int year = 2005;

    cout << "Моя дата рождения: " << day << ' ' << month << ' ' << year << " года" << endl;

    const float number = 2.3;
    const string os = "WINDOWS";

    cout << number << ' ' << os << endl;
    return 0;
}