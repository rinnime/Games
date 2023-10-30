#pragma once

#include <vector>

using namespace std;

//Locomotion Class
class Locomotion 
{
public:
    virtual void move() = 0;
};

class Swim : Locomotion 
{
public:
    void move() override;
};

class MakeAnimalNoises : Locomotion 
{
public:
    void move() override;
};

class LieDown : Locomotion
{
public:
    void move() override;
};

class Run : Locomotion
{
public:
    void move() override;
};

class Walk : Locomotion
{
public:
    void move() override;
};

class Jump : Locomotion
{
public:
    void move() override;
};

class Stationary : Locomotion 
{
public:
    void move() override;
};


//Action Classes
class Action 
{
public:
    virtual void act() = 0;
};

class EatFood : Action 
{
public:
    void act() override;
};

class PlayWithOtherAnimals : Action 
{
public:
    void act() override;
};

class InteractWithPeople : Action 
{
public:
    void act() override;
};

class FightZooKeeper : Action
{
public:
    void act() override;
};

//Resource Class
class Resource 
{
public:
    virtual void collect() = 0;
};

class AnimalCaretakerBadges : Resource 
{
public:
    void collect() override;
};

class AnimalTeeth : Resource 
{
public:
    void collect() override;
};

class AnimalHair : Resource 
{
public:
    void collect() override;
};


class ZooAnimals 
{
private:
    vector<Locomotion> locomotion;
    vector<Action> actions;
    vector<Resource> contained_resources;
public:
    void move();

    void act();

    void collect_resources();
};