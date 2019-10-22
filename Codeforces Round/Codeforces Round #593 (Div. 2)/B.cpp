#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5,mod=1000000007;
typedef long long LL;
LL Pow(LL x,LL k){
     LL ans=1;
     while(k){
        if(k&1) ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
     }
     return ans;
}

int main(){
    LL n,m;
    while(scanf("%lld %lld",&n,&m)!=EOF){
          LL p=Pow(2*1LL,m)-1;
          LL x=Pow(p,n);
          printf("%lld\n",x);

    }
return 0;
}
