#include<bits/stdc++.h>

using namespace std;

//new int[10] delete[] p，[]表示回收对象空间
//先得到空间,然后对象初始化
//先析构,然后回收空间
/*本地变量
malloc动态地得到一块内存
C++用新了两个新的运算符来动态分配内存
new Stash
new 类的时候，会分配空间并且调用构造函数
new int;
new Stash;
new int[10];
运算符必然有返回值。
delete
delete p;
delete[] p;
先调用析构函数，再释放空间。
int* psome = new int[10];返回块的第一元素的地址。
delete [] psome;会调用所有的对象的析构函数。
int *p=new int; // 到堆栈里面寻找一块合适的空间，然后P指向这个空间，然后会有一张表记录存地址和字节大小，比如 p 和 4BYTE，然后会依次记录动态分配的东西。
内部数据表！
int *a=new int[10];
Student *q=new Student();
Student *r=new Student[10];
delete p;// 会先在记录表中查找p，取得地址知道有多大，然后去删除空间。
如果 a++; delete[] a;那么系统在表里面找不到这个搜地址
delete q; //先析构，然后回收空间
delete r; // 因为没有方括号，那么空间照样收回，但析构函数只会调用一个啊。
this是指向对象的指针
TIPS for new and delete
。不要用delete去释放new没有分配的空间
。不要释放两次同一空间
。释放NULL指针指向的空间是安全的，它不做任何事情，留着这个口子是为了让你的代码好些
。方括号要成对出现
内存泄漏是不能存在的*/

class A{
private:
    int i;
    int *p;
public:
    A(){i=0;cout<<"A::A()"<<endl;}
    ~A(){if(p) delete p;cout<<"A::~A(),i="<<i<<endl;}
    void set(int _i){i=_i;}
    void f(){p= new int;cout<<"hello";}
};

int main(){

    A* p=new A[10];
    for(int i=0;i<10;++i) p[i].set(i);
    delete[] p;
return 0;

}
