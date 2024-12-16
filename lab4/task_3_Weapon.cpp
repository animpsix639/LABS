#include "task_3.h"
#include <iostream>

using namespace std;

Weapon::Weapon(const string& weaponName, int weaponDamage, float weaponWeight)
    : name(weaponName), damage(weaponDamage), weight(weaponWeight) {}

Weapon::Weapon() : Weapon("Glock", 7, 0.7f) {}

Weapon::~Weapon() {
    cout << "Удаление оружия" << endl;
    cout << "Имя: " << name << endl 
         << "Урон: " << damage << endl 
         << "Вес: " << weight << " кг \n"
         << "Оружие удалено." << "\n\n"; 
}

void Weapon::show() const {
    cout << "Имя: " << name << endl 
         << "Урон: " << damage << endl 
         << "Вес: " << weight << " кг \n\n";
}

bool Weapon::isHeavy(float maxWeight) const {
    return weight > maxWeight;
}

float Weapon::totalWeight(const Weapon& otherWeapon) const {
    return totalWeight(otherWeapon.weight); 
}

float Weapon::totalWeight(float plusWeight) const {
    return weight + plusWeight;
}

std::string Weapon::getName() const {
    return name;
}

int Weapon::getDamage() const {
    return damage;
}

float Weapon::getWeight() const {
    return weight;
}

void Weapon::setDamage(int newDamage) {
    damage = newDamage;
}

Characteristic::Characteristic(int str) : strength(str) {}

int Characteristic::getStrength() const {
    return strength;
}

int Characteristic::getDamage(const Weapon& weapon) const {
    return strength + weapon.getDamage();
}

int MyMath::callCount = 0;

int MyMath::Add(int a, int b) {
    callCount++;
    return a + b;
}

int MyMath::Sub(int a, int b) {
    callCount++;
    return a - b;
}

int MyMath::Mult(int a, int b) {
    callCount++;
    return a * b;
}

float MyMath::Div(float a, float b) {
    callCount++;
    return (b != 0) ? a / b : 0;
}

int MyMath::getCallCount() {
    return callCount;
}
