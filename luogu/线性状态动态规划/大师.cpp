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
const int N=1e3+5,inf=1e6+5,mod=998244353;
typedef long long LL;
int dp[40005],a[N];
vector<int> v[20005];
int main(){
    int n,d=0;
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",&a[i]);
        d=max(d,a[i]);
        v[a[i]].pb(i);
    }
    LL ans=0;
    rep(i,0,2*d+1){
        int p=i-d;
        //if(p==0) continue;
        rep(j,0,n) dp[j]=0;
        rep(j,0,n){
            int x=a[j]-p;
            if(x<=0 || x>20000) continue;
            for(auto &k:v[x]){
                if(k>=j) break;
                dp[j]=(dp[j]+dp[k]+1)%mod;
            }
        }

        rep(j,0,n) ans=(ans+dp[j])%mod;
       // cout<<p<<endl;
        //rep(i,0,n) printf("%d ",dp[i]); puts("");
    }
    cout<<(ans+n)%mod<<endl;
return 0;
}
