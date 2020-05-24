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
const int N=35,inf=1e6+5;
typedef long long LL;
LL dp[N][N][N],a[N];
LL solve(int l,int r,int p_root){
    if(dp[l][r][p_root]!=-1) return dp[l][r][p_root];
    if(l==r) return a[l]*1LL;
    LL l_sum=1,r_sum=1;
    rep(i,l,p_root){
        dp[l][p_root-1][i]=max(dp[l][p_root-1][i],solve(l,p_root-1,i));
        l_sum=max(l_sum,dp[l][p_root-1][i]);
    }
    rep(i,p_root+1,r+1){
        dp[p_root+1][r][i]=max(dp[p_root+1][r][i],solve(p_root+1,r,i));
        r_sum=max(r_sum,dp[p_root+1][r][i]);
    }

    return dp[l][r][p_root]=max(l_sum*r_sum+a[p_root],dp[l][r][p_root]);
}
void print(int l,int r){
    if(l>r) return;
    if(l==r){
        printf("%d ",l);
        return;
    }
    LL sum=0;int id;
    rep(i,l,r+1)
        if(dp[l][r][i]>sum){
            sum=dp[l][r][i];
            id=i;
        }
    printf("%d ",id);
    print(l,id-1);
    print(id+1,r);
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    ms(dp,-1);
    rep(i,1,n+1) scanf("%d",&a[i]);
    LL ans=0;
    rep(i,1,n+1){
        ans=max(ans,solve(1,n,i));
    }
    cout<<ans<<endl;
    print(1,n);
    puts("");
return 0;
}
