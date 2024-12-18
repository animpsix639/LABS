#include <iostream>
#include <string>
using namespace std;

enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

class Weapon {
private:
    string name;
    WeaponType type;
    int baseDamage;

public:
    Weapon(const string &name, WeaponType type, int baseDamage) : name(name), type(type), baseDamage(baseDamage) {}

    WeaponType getType() const {
        return type;
    }

    string getName() const {
        return name;
    }

    virtual int getDamage() const {
        return baseDamage;
    }

    virtual void Attack() const = 0;

    bool operator>(const Weapon &other) const {
        return this->getDamage() > other.getDamage();
    }

    bool operator<(const Weapon &other) const {
        return this->getDamage() < other.getDamage();
    }
};

class MagicWeapon : public Weapon {
private:
    int extraDamage;

public:
    MagicWeapon() : Weapon("Волшебная палочка", ONEHANDED, 0), extraDamage(0) {}

    MagicWeapon(const string &name, WeaponType type, int baseDamage, int extraDamage)
        : Weapon(name, type, baseDamage), extraDamage(extraDamage) {}

    int getExtraDamage() const {
        return extraDamage;
    }

    int getDamage() const override {
        return Weapon::getDamage() + extraDamage;
    }

    void Attack() const override {
        cout << "Атакуем магическим оружием" << endl;
    }
};

class DisposableWeapon : public Weapon {
private:
    bool used;

public:
    DisposableWeapon(const string &name, WeaponType type, int baseDamage)
        : Weapon(name, type, baseDamage), used(false) {}

    void Attack() const override {
        if (used) {
            cout << "Оружие уже было использовано" << endl;
        } else {
            cout << "Атакуем одноразовым оружием" << endl;
            const_cast<DisposableWeapon *>(this)->used = true;
        }
    }

    bool isUsed() const {
        return used;
    }
};

template <typename LeftHand, typename RightHand>
class WeaponHolder {
private:
    LeftHand left;
    RightHand right;

public:
    WeaponHolder(const LeftHand &left, const RightHand &right) : left(left), right(right) {}

    LeftHand getLeft() const {
        return left;
    }

    RightHand getRight() const {
        return right;
    }

    void setLeft(const LeftHand &newLeft) {
        left = newLeft;
    }

    void setRight(const RightHand &newRight) {
        right = newRight;
    }
};

int main() {
    MagicWeapon fireSword("Меч Квилег", ONEHANDED, 30, 50);
    fireSword.Attack();

    DisposableWeapon bomb("Граната", ONEHANDED, 100);
    bomb.Attack();
    bomb.Attack();

    WeaponHolder<MagicWeapon, int> holder(fireSword, 42);
    cout << holder.getLeft().getName() << " в левой руке, id - " << holder.getRight() << " в правой руке" << endl;

    return 0;
}
