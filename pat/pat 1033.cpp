#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=505;
struct node{
 double v;
 int d;
 node(){}
 node(double _v,int _d){v=_v;d=_d;}
 bool operator < (const node &a) const{
    return (v==a.v && d<a.d) || (d<a.d);
 }
}a[N];
int main(){
    int v_max,d,per_d,n;
    while(scanf("%d %d %d %d",&v_max,&d,&per_d,&n)!=EOF){
        rep(i,0,n) scanf("%lf %d",&a[i].v,&a[i].d);
        sort(a,a+n);
        int p=0,v_now=0;
        while(p<=n){
           if(a[p].v>a[p+1].v)
        }
    }
return 0;
}
