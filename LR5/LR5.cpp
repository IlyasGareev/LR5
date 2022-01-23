#include <iostream>
#include <ctime>

using namespace std;

class Animal {
public:
    virtual void sound() {

    }
    void foo1() {                              //метод, который будет переопределяться 
        printf("Animal foo1\n");
    }
    void foo2() {                             //метод, который будет наследоваться 
        printf("Animal foo2\n");
    }
    virtual void foo3() {                     //виртуальный метод
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
