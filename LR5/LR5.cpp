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
void func1(Base obj) {
    printf("func1(Base obj)\n");
}

void func2(Base* obj) {
    printf("func2(Base* obj)\n");
}

void func3(Base& obj) {
    printf("func3(Base& obj)\n");
}

Base func_1(Base obj) {
    printf("Base func_1(Base obj)\n");
    return obj;
}

Base* func_2(Base* obj) {
    printf("Base* func_2(Base* obj)\n");
    return obj;
}

Base& func_3(Base& obj) {
    printf("Base& func_3(Base& obj)\n");
    return obj;
}
int main()
{
    srand(time(NULL));

    Dog* l = new Dog();             //объект класса наследника
    l->foo1();                      //вызов перекрываемого метода у объекта класса наследника 
    l->foo2();                      //вызов наследуемого метода у объкта класса наследника 
    delete l;


    Animal* m = new Animal();          //объект базового класса
    m->foo3();                       //вызов виртуального метода у объекта базового класса
    delete m;

    Animal* n = new Dog();              //объект класса наследника, помещенного в переменную базового класса
    n->foo3();                          //вызов наследуемого виртуального метода
    delete n;

    printf("\n\n");

    Animal* a = new Dog();
    if (a->classname() == "Dog") {
        ((Dog*)a)->run();
    }
    delete a;

    Animal* b = new Dog();
    if (b->isA("Dog")) {
        ((Dog*)b)->run();
    }
    delete b;

    Animal* c = new Dog();
    ((Dog*)c)->run();                      //опасное приведение типов
    delete c;

    Animal* d = new Dog();
    if (dynamic_cast<Dog*>(d)) {             //безопасное приведение типов
        ((Dog*)d)->run();
    }
    delete d;

    printf("\n\n");

    Base* w = new Base();
    func1(w);
    func2(w);
    func3(*w);

    printf("\n\n");

    Desc* x = new Desc();
    func1(x);
    func2(x);
    func3(*x);
    delete x;

    printf("\n\n");

    func_1(*w);
    func_2(w);
    func_3(*w);
    delete w;

    printf("\n\n");

    {
        unique_ptr<Base> unq(new Desc());
    }

    printf("\n\n");

    Base* z = new Desc();
    shared_ptr<Base> ptr1(z);
    {
        shared_ptr<Base> ptr2(ptr1);
    }
}
