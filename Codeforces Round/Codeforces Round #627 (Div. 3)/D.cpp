#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
#define lson l,mid,i<<1
#define rson mid+1,r,i<<1|1
#define ls i<<1
#define rs i<<1|1
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m,k;
int a[N],b[N],v[N],c[N];
int main(){
    int t;
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",&a[i+1]);
    rep(i,0,n) scanf("%d",&b[i+1]);
    rep(i,1,n+1) c[i]=b[i]-a[i];
    sort(c+1,c+n+1);
    LL ans=0;
    rep(i,1,n+1){
        int num=lower_bound(c+i+1,c+n+1,-c[i])-c;
        ans+=num-i-1;
    }
    cout<<ans<<endl;

return 0;
}
