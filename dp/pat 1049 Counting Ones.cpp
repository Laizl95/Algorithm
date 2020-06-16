#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<long long,long long>
#define fi first
#define se second
using namespace std;
const int N=1e3+5,inf=1e6+5,mod=1000000007;
typedef long long LL;
LL dp[15][15][2];
vector<int> v;
pii solve(int limit,int pre,int p){
    if(p<=0) return mp(pre==1,1);
    if(!limit && dp[p][pre][0]) return pii(dp[p][pre][0],dp[p][pre][1]);
    int k=limit?v[p-1]:9;
    LL cnt=0,num=0;
    rep(i,0,k+1){
         pii a=solve(limit&(i==k),i,p-1);
         cnt+=a.fi;
         num+=a.se;
    }
   // cout<<cnt<<" "<<num<<endl;
    if(pre==1) cnt+=num;
    if(!limit) {
        dp[p][pre][0]=cnt;
        dp[p][pre][1]=num;
    }
    return mp(cnt,num);
}
int main(){
    int n;
    scanf("%d",&n);
    int x=n;
    while(x){
        v.pb(x%10);
        x/=10;
    }
    rep(i,v.size(),10) v.pb(0);
    //for(auto x:v) printf("%d ",x);puts("");
    pii ans=solve(1,11,10);
    cout<<ans.fi<<endl;
return 0;
}
