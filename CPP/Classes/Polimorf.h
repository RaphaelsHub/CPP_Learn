#pragma once

#include <iostream>

using namespace std;

class Weapon
{
public:
    Weapon() = default;
    virtual ~Weapon() = 0;
    virtual void Shoot() = 0;
};
Weapon::~Weapon(){};

class Gun:public Weapon
{
public:
    Gun() = default;
    ~Gun() override = default;
    void Shoot() override
    {
        cout << "Bum Bum Bum" << endl;
    }
};

class SubMachineGun : public Gun
{
public:
    SubMachineGun() = default;
    ~SubMachineGun()override = default;
    virtual void Shoot() override
    {
        cout << "PUK PUK PUK" << endl;
    }
};

class Bazuka:public Weapon
{
public:
    Bazuka() = default;
    ~Bazuka()override = default;
    void Shoot()override
    {
        cout << "BUM BUM BUM" << endl;
    }
};

class Knife : public Weapon
{
public:
    Knife() = default;
    ~Knife()override = default;
    void Shoot()override
    {
        cout << "VJUH VJUH VJUH" << endl;
    }
};

class KitchenKnife :public Knife
{
public:
    KitchenKnife () = default;
    ~KitchenKnife ()override =default;
    void Shoot()override
    {
        cout << "VJUH VJUH VJUH - Tirkak" << endl;
        Knife::Shoot();
    }
};

class Player
{
public:
    Player() = default;
    ~Player() = default;
    void Shoot(Weapon *weapon)
    {
        weapon->Shoot();
    }
};


inline void Polimorphism()
{
    Player player;

    Gun gun;
    SubMachineGun subMachineGun;
    Bazuka bazuka;
    Knife knife;
    KitchenKnife kitchenKnife;

    player.Shoot(&subMachineGun);
    player.Shoot(&gun);
    player.Shoot(&bazuka);
    player.Shoot(&knife);
    player.Shoot(&kitchenKnife);

}