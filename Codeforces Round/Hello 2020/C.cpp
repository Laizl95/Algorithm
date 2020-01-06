#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    LL n,m;
    scanf("%lld %lld",&n,&m);
    LL ans=0,sum=1,sum2=1;
    rep(k,1,n+1){
        sum=sum*k%m;
        //cout<<((n-k+1)*(n-k+1)%m)*sum%m<<endl;
        ans+=(sum2*(n-k+1)%m)*sum%m;
       // cout<<ans<<endl;
         ans=ans*(n-k+1)%m; cout<<ans<<endl;
    }

    cout<<ans<<endl;
return 0;
}
