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
const int N=3e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
LL a[N],b[N],cost[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n) scanf("%lld %lld",&a[i],&b[i]);
        a[n]=a[0];b[n]=b[0];
        LL sum=0;
        rep(i,0,n){
            cost[i]=max(a[i+1]-b[i],0LL);
            sum+=cost[i];
        }
        LL ans=sum+a[0]-cost[n-1];
        rep(i,1,n){
            ans=min(ans,sum-cost[i-1]+a[i]);
        }
        cout<<ans<<endl;
    }
return 0;
}
