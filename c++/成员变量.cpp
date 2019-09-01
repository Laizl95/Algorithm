#include<bits/stdc++.h>
using namespace std;

//void A::f() can be regarded as void A::f(A *p)
//a.f() cab be regarded as A::f(&a)
class A{
public:
    int i,j;
    void f();
};
void A::f(){
    i=20;
    printf("A::f()--&i=%p\n",&i);
    printf("this %p",this);
}
struct B{
    int i;
};
void f(struct B* p){
    p->i=20;
}
int main(){
    A a;
    A aa;
    B b;
    a.i=10;
    printf("&a=%p\n",&a);
    printf("&a.i=%p\n",&(a.i));
    printf("&a.i=%p\n",&(a.j));
    a.f();
return 0;
}
