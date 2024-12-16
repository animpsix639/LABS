#include <iostream>
#include "task_3.h"

using namespace std;

int main() {
    Weapon gwynbleiid("Меч", 70, 2.8f);
    gwynbleiid.show();

    gwynbleiid.setDamage(99);
    cout << "Новый урон: " << gwynbleiid.getDamage() << endl;

    Characteristic character(44);
    cout << "Общий урон (Урон + Сила): " 
         << character.getDamage(gwynbleiid) << endl;

    cout << "6 + 4 = " << MyMath::Add(6, 4) << endl;
    cout << "7 - 2 = " << MyMath::Sub(7, 2) << endl;
    cout << "12 * 9 = " << MyMath::Mult(12, 9) << endl;
    cout << "28 / 7 = " << MyMath::Div(28, 7) << endl;

    cout << "Методы MyMath были вызваны " << MyMath::getCallCount() << " раз." << endl;

    return 0;
}
