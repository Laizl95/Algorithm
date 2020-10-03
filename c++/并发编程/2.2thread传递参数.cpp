#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;
/*thread的构造函数并不知晓；
构造函数无视函数期待的参数类型,并盲目的拷贝已提供的变量*/
class X{
public:
    void do_work(int){

    }
};
X my_x;
int num(0);
thread t(&X::do_work,&my_x);

/*thread提供的参数可以移动，但不能拷贝*/
void process_big_object(std::unique_ptr<big_object>);
std::unique_ptr<big_object> p(new big_object);
p->prepare_data(42);
std::thread t(process_big_object,std::move(p));

/*thread 实例不像 unique_ptr 那样能占有一
个动态对象的所有权，但是它能占有其他资源：每个实例都负责管理一个执行线程。
执行线程的所有权可以在多个thread 实例中互相转移，这是依赖于thread 实例的
可移动且不可复制性。不可复制保性证了在同一时间点，一个thread 实例只能关联
一个执行线程 */

