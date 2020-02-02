#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=3e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL a,m;
        scanf("%lld %lld",&a,&m);
        m/=__gcd(a,m);
        LL ans=m;
        for(int i=2;1LL*i*i<=m;++i){
            if(m%i==0){
                ans=ans/i*(i-1);
                while(m%i==0) m/=i;
            }
        }
        if(m>1) ans=ans/m*(m-1);
        printf("%lld\n",ans);
    }
return 0;
}
