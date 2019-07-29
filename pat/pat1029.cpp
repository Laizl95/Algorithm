//寻找两个有序序列的中位数
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e5*2+5;


int main(){
    priority_queue<int,vector<int>,greater<int> > q;
    //q.push(3);q.push(2);cout<<q.top()<<endl;
    int n1,n2,goal;
    scanf("%d",&n1);
    int x;
    rep(i,0,n1) scanf("%d",&x),q.push(x);
    scanf("%d",&n2);
    goal=(n1+n2)/2+1-n1;
    rep(i,0,n2){
        scanf("%d",&x);
        if(i+1<=goal) q.push(x);
        else if(x>q.top()) q.pop(),q.push(x);
    }
    while(goal<0) goal+=1,q.pop();
    printf("%d\n",q.top());
return 0;
}
