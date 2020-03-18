#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5,mod=998244353;
typedef long long LL;

int n,m;
LL e[N],sum[N];
int a[N];
void exgcd(int a,int b,int &x,int &y){
  if(b==0){
    x=1,y=0;
    return;
  }
  exgcd(b,a%b,y,x);
  y-=a/b*x;
}
int inv(int x){
    int inv_x=0,y=0;
    exgcd(x,mod,inv_x,y);
    return (inv_x%mod+mod)%mod;
}
/*int inv(int a){
    int r=1,t=a,k=MOD-2;
    while(k){
        if(k&1) r=(long long)r*t%MOD;
        t=(long long)t*t%MOD;
        k>>=1;
    }
    return r;
}*/
int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    rep(i,1,n+1){
        e[i]=(1+(100-a[i])*(1+sum[i-1])%mod*1LL*inv(a[i])%mod)%mod;
        sum[i]=(e[i]+sum[i-1])%mod;
    }
    LL ans=0;
    rep(i,1,n+1) ans=(ans+e[i])%mod;
    cout<<ans<<endl;

return 0;
}
