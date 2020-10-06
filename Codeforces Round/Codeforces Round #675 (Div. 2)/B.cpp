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
const int N=1e2+5,mod=1e9+7;
typedef long long LL;
int n,m;
int a[N][N];
LL cal(int x1,int x2,int x3,int x4){
     LL t1=x1*1LL,t2=x2*1LL,t3=x3*1LL,t4=x4*1LL;
     return abs(t2-t1)+abs(t3-t1)+abs(t4-t1);
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&n,&m);
    rep(i,0,n) rep(j,0,m) scanf("%d",&a[i][j]);
    LL ans=0;
    rep(i,0,n/2) rep(j,0,m/2){
        int x1=a[i][j],x2=a[i][m-j-1],x3=a[n-i-1][j],x4=a[n-i-1][m-j-1];
        LL t1=cal(x1,x2,x3,x4);
        LL t2=cal(x2,x1,x3,x4);
        LL t3=cal(x3,x1,x2,x4);
        LL t4=cal(x4,x1,x2,x3);
        ans+=min(min(t1,t2),min(t3,t4));
    }
    if(n&1){
        int p=n/2;
        rep(j,0,m/2){
            ans+=abs(a[p][j]-a[p][m-j-1]);
        }
    }
    if(m&1){
        int p=m/2;
        rep(i,0,n/2) ans+=abs(a[i][p]-a[n-i-1][p]);
    }
    cout<<ans<<endl;
  }
return 0;
}
