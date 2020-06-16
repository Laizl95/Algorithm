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
//求至少有 1 位重复的数字,转换为求不重复得数字有几位
int vis[10],dp[15][1024*2];
vector<int> v;
int solve(int limit,int pre,int p,int sum){
    if(p<=0) return 1;
    if(!limit && dp[p][sum]!=0) return dp[p][sum];
    int x=limit?v[p-1]:9,cnt=0;
    rep(i,0,x+1){
        //if(p==1){cout<<"pre="<<pre<<" "<<"i="<<i<<" "<<vis[i]<<endl;}
        if(vis[i]) continue;
        if(i==0 && pre==11){
            cnt+=solve(limit&(i==x),pre,p-1,0);
        }else{
            vis[i]=1;
            cnt+=solve(limit&(i==x),i,p-1,sum+(1<<i));
            vis[i]=0;
        }
    }
    if(!limit && sum) dp[p][sum]=cnt;
    return cnt;
}
int main(){
    int n,x;
    scanf("%d",&n);
    x=n;
    while(x){
       v.pb(x%10);
       x/=10;
    }
    rep(i,v.size(),10) v.pb(0);
    //for(auto &x:v) printf("%d ",x);puts("");
    cout<<n-solve(1,11,10,0)+1<<endl;
return 0;
}

