#ifndef TASK_3_H
#define TASK_3_H

#include <string>

class Weapon;

class Characteristic;

class Weapon {
private:
    std::string name;
    int damage;
    float weight;

public:
    Weapon(const std::string& weaponName, int weaponDamage, float weaponWeight);
    Weapon();
    ~Weapon();

    void show() const;
    bool isHeavy(float maxWeight) const;
    float totalWeight(const Weapon& otherWeapon) const;
    float totalWeight(float plusWeight) const;

    std::string getName() const;
    int getDamage() const;
    float getWeight() const;

    void setDamage(int newDamage);
};

class Characteristic {
private:
    int strength;

public:
    Characteristic(int str);

    int getStrength() const;
    int getDamage(const Weapon& weapon) const;
};

class MyMath {
private:
    static int callCount;

public:
    static int Add(int a, int b);
    static int Sub(int a, int b);
    static int Mult(int a, int b);
    static float Div(float a, float b);

    static int getCallCount();
};

#endif // TASK_3_H
