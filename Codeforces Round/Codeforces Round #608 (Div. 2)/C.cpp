#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n;
struct node{
    int x,y;
}a[N];
int main(){
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    int l1=-1,l2=-1,r1=-1,r2=-1,tot1=0,tot2=0,tot3=0,tot4=0;
    rep(i,0,n){
        scanf("%d %d",&a[i].x,&a[i].y);
        if(a[i].x<x){
           tot1+=1;
           if(l1==-1 || l1<a[i].x) l1=a[i].x;
        }
        if(a[i].x>x){
            tot2+=1;
            if(r1==-1 || r1>a[i].x) r1=a[i].x;
        }
        if(a[i].y<y){
            tot3+=1;
            if(l2==-1 || l2<a[i].y) l2=a[i].y;
        }
         if(a[i].y>y){
            tot4+=1;
            if(r2==-1 || r2>a[i].y) r2=a[i].y;
        }
    }
    if(max(tot1,tot2)>=max(tot3,tot4)){
        if(tot1>=tot2){
            cout<<tot1<<endl;
            cout<<l1<<" "<<y<<endl;
        }else{
             cout<<tot2<<endl;
            cout<<r1<<" "<<y<<endl;
        }
    }else{
         if(tot3>=tot4){
            cout<<tot3<<endl;
            cout<<x<<" "<<l2<<endl;
        }else{
             cout<<tot4<<endl;
            cout<<x<<" "<<r2<<endl;
        }
    }
return 0;
}
