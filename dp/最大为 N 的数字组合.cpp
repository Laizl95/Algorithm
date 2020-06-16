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
const int N=1e3+5,inf=1e6+5,mod=1000000007;
typedef long long LL;
int a[N];
LL dp[32][32];
vector<int> v;
int n,k;
int dfs(int limit,int pre,int p){

    if(!limit && dp[p][pre]!=0) return dp[p][pre];
    if(p<=0) return 1;
    LL cnt=0;
    rep(i,0,n+1){
        if(limit && a[i]>v[p-1]) continue;
        if(pre==11 && v[p-1]==0){
            cnt+=dfs(limit,pre,p-1);
            return cnt;
        }
       if(pre>0 && pre<10 && a[i]==0) continue;
        cnt+=dfs(limit&(a[i]==v[p-1]),a[i],p-1);
    }
    if(!limit) dp[p][pre]=cnt;
    return cnt;
}
int main(){
    n=1;
    a[0]=0;
    rep(i,1,n+1) scanf("%d",&a[i]);
    scanf("%d",&k);
    int x=k;
    while(x){
        v.pb(x%10);
        x/=10;
    }
    rep(j,v.size(),10) v.pb(0);
    //reverse(v.begin(),v.end());
    //for(auto x:v) printf("%d ",x);
    cout<<dfs(1,11,10)-1<<endl;
return 0;
}
