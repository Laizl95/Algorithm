#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e3+5,inf=1e9+5;
typedef long long LL;
int dp[N][15];
vector<int> v;
void solve(int n){
    v.clear();
    while(n){
        v.pb(n%10);
        n/=10;
    }
}
int dfs(int p,int pre,int op){

    if(p<0) return 1;
    if(!op && dp[p][pre]!=0) return dp[p][pre];
    int lim=op?v[p]:9,cnt=0;
    rep(i,0,lim+1){
        if(abs(i-pre)<2) continue;
        if(pre==11 && i==0)
            cnt+=dfs(p-1,11,op&(i==lim));
        else
            cnt+=dfs(p-1,i,op&(i==lim));
    }
    if(!op) dp[p][pre]=cnt;
    return cnt;
}
int main(){
    int l,r;
    scanf("%d %d",&l,&r);
    solve(r);
    int numr=dfs(v.size()-1,11,1);
    solve(l-1);
    int numl=dfs(v.size()-1,11,1);
    //cout<<numr<<" "<<numl<<endl;
    printf("%d\n",numr-numl);
return 0;
}
