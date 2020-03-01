#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

LL n,m;
int main(){
    int t;LL a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld",&n,&a,&b);
        LL need=(n+1)/2;
        LL k=need/a;
        if(k==0){cout<<n<<endl;continue;}
        LL ans=n;
        if(need%a==0){
                k-=1;
            if((a+b)*k+a>n)
                ans=(a+b)*k+a;
            else ans=n;
        }else{
            if((a+b)*k+need%a>n){
                ans=(a+b)*k+need%a;
            }else ans=n;
        }
        cout<<ans<<endl;
    }
return 0;
}
