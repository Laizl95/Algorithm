#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5;
typedef long long LL;

int main(){
    int n;
    scanf("%d",&n);
    LL x,cnt=-1;
    rep(i,0,n){
        scanf("%lld",&x);
        if(cnt==-1) cnt=x;
        cnt=__gcd(cnt,x);
    }

    LL ans=1;
    for(int i=2;i*1LL*i<=cnt;i+=1){
        if(cnt%i==0){
            int tot=0;
            while(cnt%i==0) cnt/=i,++tot;
            ans*=(tot+1);
        }
    }
    if(cnt>1) ans*=2;
    printf("%lld\n",ans);
return 0;
}
