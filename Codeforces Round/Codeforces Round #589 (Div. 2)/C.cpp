#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5,mod=1e9+7;
typedef long long LL;
//定义g(x,p)的值是p^k.求最大的k,使得x能整除p^k
//f(x,y)=g(y,p1)*g(y,p2)*...*g(y,pn)  p1,p2..pn是x的质因子
//输入x和n，求f(x,1)*f(x,2)*..f(x,n)  2<=x<=1e9,1<=n<=1e18
LL n,m,ans;
LL Pow(LL x,LL k){
     LL ans=1;
     while(k){
        if(k&1) ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
     }
     return ans;
}
LL get(LL p){
    LL x=p;
    while(p<=m){
        ans=ans*Pow(x,m/p)%mod;
        if(m/p<x) break;
        p=p*x;
    }
}
int main(){

    while(scanf("%lld %lld",&n,&m)!=EOF){
            ans=1;
          for(int i=2;i*i<=n;i+=1){
                if(n%i==0){
                    get(i*1LL);
                    while(n%i==0) n/=i;
                }
          }
          if(n!=1) get(n);
          printf("%lld\n",ans);
    }
return 0;
}
