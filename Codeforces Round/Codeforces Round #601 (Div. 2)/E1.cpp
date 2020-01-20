#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e5+5;
typedef long long LL;
LL inf=0x3fffffffffffffff;
int a[N];
void solve(int k,vector<int> &v,LL &ans){

    int t=v.size();LL cnt=0;
    for(int i=0;i<t;i+=k){
        int mid=v[(i+i+k-1)/2];
        rep(j,0,k){
            cnt+=abs(mid-v[i+j]);
        }
    }
    ans=min(ans,cnt);
}
int main(){

    int n;
    vector<int> v;
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",&a[i]);
        if(a[i]) v.pb(i);
    }
    int t=v.size();LL ans=inf;
    for(int i=2;i*i<=t;++i){
        if(t%i==0){
            solve(i,v,ans);
            while(t%i==0) t/=i;
        }
    }
    if(t>1) solve(t,v,ans);

    printf("%lld\n",ans==inf?-1:ans);
return 0;
}
