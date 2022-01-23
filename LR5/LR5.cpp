#include <iostream>
#include <ctime>

using namespace std;

class Animal {
public:
    virtual void sound() {

    }
    void foo1() {                               //метод, который будет переопределяться 
        printf("Animal foo1\n");
    }
    void foo2() {                               //метод, который будет наследоваться 
        printf("Animal foo2\n");
    }
    virtual void foo3() {                       //виртуальный метод
        printf("Animal foo3\n");
    }
    virtual string classname() {
        return "Animal";
    }
    virtual bool isA(string who) {              //возвращает true, если вызван у объекта класса Animal
        return (who == "Animal");
    }
    virtual ~Animal() {
        printf("~Animal\n");
    }
};
class Dog : public Animal {
public:
    Dog() {

    }
    void sound() {
        printf("wow\n");
    }
    void foo1() {
        printf("Dog foo1\n");
    }
    void foo3() {
        printf("Dog foo3\n");
    }
    string classname() {
        return "Dog";
    }
    bool isA(string who) {
        return(who == "Dog");
    }
    void run() {
        printf("Dog run\n");
    }
    ~Dog() {
        printf("~Dog\n");
    }
};
class Base {
public:
    Base() {
        printf("Base()\n");
    }
    Base(Base* obj) {
        printf("Base(Base* obj)\n");
    }
    Base(Base& obj) {
        printf("Base(Base& obj)\n");
    }
    ~Base() {
        printf("~Base()\n");
    }
};

class Desc : public Base {
public:
    Desc() {
        printf("Desc()\n");
    }
    Desc(Desc* obj) {
        printf("Desc(Desc* obj)\n");
    }
    Desc(Desc& obj) {
        printf("Desc(Desc& obj)\n");
    }
    ~Desc() {
        printf("~Desc()\n");
    }
};
