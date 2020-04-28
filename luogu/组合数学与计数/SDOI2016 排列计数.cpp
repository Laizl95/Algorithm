#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+5,inf=1e9+5,mod=1e9+7;
typedef long long LL;
int n,m;
LL f[N],jc[N];
//a模mod下的逆元
LL inv(LL a){
    LL r=1,t=a;int k=mod-2;
    while(k){
        if(k&1) r=(LL)r*t%mod;
        t=(LL)t*t%mod;
        k>>=1;
    }
    return r;
}

int main(){
    f[0]=1LL;f[1]=0;f[2]=1LL;
    rep(i,3,1e6+1){
        f[i]=((i-1)*f[i-1]%mod+(i-1)*f[i-2]%mod)%mod;
    }
    jc[0]=1LL;jc[1]=1LL;
    rep(i,2,1e6+1) jc[i]=i*jc[i-1]%mod;

    int t;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d",&n,&m);
       if(n<m){puts("0");continue;}
       //cout<<(jc[n-m]*jc[m]%mod)<<endl;
       LL ans=jc[n]*inv(jc[n-m]*jc[m]%mod)%mod*f[n-m]%mod;

       cout<<ans<<endl;
    }
return 0;
}
