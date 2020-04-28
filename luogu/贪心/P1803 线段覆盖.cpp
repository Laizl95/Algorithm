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
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
pii a[N];
bool cmp(pii &a,pii &b){
    return a.se<b.se || (a.se==b.se && a.fi<b.fi);
}
int main(){
    int n;
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d %d",&a[i].fi,&a[i].se);
    }
    sort(a,a+n,cmp);
    int ans=0,pre=-1;
    rep(i,0,n){
        if(a[i].fi>=pre) ++ans,pre=a[i].se;
    }
    cout<<ans<<endl;
return 0;
}
