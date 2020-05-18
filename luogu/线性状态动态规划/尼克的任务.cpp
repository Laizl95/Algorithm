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
const int N=1e4+5,inf=1e6+5,mod=998244353;
typedef long long LL;
int dp[N];
pii a[N];
vector<int> v[N];
int main(){
    int n,k;

    scanf("%d %d",&n,&k);
    rep(i,0,k){
        scanf("%d %d",&a[i].fi,&a[i].se);
        v[a[i].fi].pb(i);
    }
    sort(a,a+k);
    per(i,1,n+1){
        if(v[i].size()==0) dp[i]=dp[i+1]+1;
        else{
            for(auto &x:v[i]){
                if(dp[i+a[x].se]>dp[i]) dp[i]=dp[i+a[x].se];
            }
        }
    }
    cout<<dp[1]<<endl;
return 0;
}
