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
const int N=2e5+5,inf=1e9+5,mod=998244353;
typedef long long LL;
int n,m,k;
int a[N],b[N];
int main(){

    scanf("%d %d",&n,&k);
    int x;
    LL ans=1,sum=0;
    vector<int> v1;
    rep(i,0,n){
        scanf("%d",&x);
        if(x>n-k) v1.pb(i),sum+=x;
    }
     int pre=-1;
    for(auto it:v1){
        if(pre==-1) pre=it;
        else ans=ans*(it-pre)%mod,pre=it;
    }
    cout<<sum<<" "<<ans<<endl;

return 0;
}
