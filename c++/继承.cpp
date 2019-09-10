#include<bits/stdc++.h>

using namespace std;
//子类可以用父类的公共方法，成员变量，但私有变量不能直接访问
//protected 只能在子类里面访问
class A{
public:
    A():i(0){cout<<"A::A()"<<endl;}
    ~A(){cout<<"A::~A()"<<endl;}
    void print(){cout<<"A::f()"<<i<<endl;}
    //void sets(int ii){i=ii;}
protected:
    void sets(int ii){i=ii;}
private:
    int i;
    //void sets(int ii){i=ii;}
};

class B : public A{
public:
    void f(){
        sets(20);
        print();
        //i=30;
    }
};
int main(){
    B b;
    b.sets(10);
    b.print();
    b.f();
    return 0;
}
