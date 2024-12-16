#include "task_3.h"
#include <iostream>

int main() {
    Weapon gwynbleidd("Gwynbleidd", 70, 2.8f);
    Weapon defaultWeapon;

    std::cout << "Меч:\n";
    gwynbleidd.show();

    std::cout << "Обычное оружие:\n";
    defaultWeapon.show();

    Weapon* newWeapon = new Weapon("Rocket Launcher", 500, 6.7f);
    std::cout << "Новое оружие:\n";
    newWeapon->show();

    float maxWeight = 4.5f;
    std::cout << "Новое оружие слишком тяжелое?\n"
              << (newWeapon->isHeavy(maxWeight) ? "Да\n" : "Нет\n")
              << std::endl;

    std::cout << "Общий вес оружия: " << newWeapon->totalWeight(*newWeapon) << " кг\n\n";

    std::cout << "Общий вес оружия + 4.2 кг: " << newWeapon->totalWeight(4.2f) << "кг\n\n";

    delete newWeapon;

    return 0;
}
