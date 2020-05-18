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
bool cmp(const pii &a,const pii &b){
    return a.se*1.0/a.fi>b.se*1.0/b.fi;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    rep(i,0,n) scanf("%d %d",&a[i].fi,&a[i].se);
    sort(a,a+n,cmp);
    double ans=0;
    rep(i,0,n){
        if(a[i].fi<m){
            m-=a[i].fi;
            ans+=a[i].se;
        }else{
            ans+=m*(a[i].se*1.0/a[i].fi);
            break;
        }
    }
   printf("%.2f\n",ans);
return 0;
}
