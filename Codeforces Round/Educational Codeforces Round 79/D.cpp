#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e6+5,inf=1e9+5;
typedef long long LL;
vector<int> v[N];
int num[N];
void exgcd(LL a, LL b, LL &x, LL &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
int main(){
    cout<<(-19%4)<<endl;
    int n,m,k;
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",&m);
        rep(j,0,m){
            scanf("%d",&k);
            v[i].pb(k);
            num[k]+=1;
        }
    }
     LL a=n*1LL,b=998244353*1LL,x=1LL,y=1LL;
     exgcd(a,b,x,y);
     LL inv_n=((x%b)+b)%b,ans=0;
    rep(i,0,n){
        int tot=0,t=v[i].size();
        rep(j,0,v[i].size()) tot+=num[v[i][j]];
        a=t*1LL,x=1LL,y=1LL;
        exgcd(a,b,x,y);
        x=((x%b)+b)%b;
        ans=(ans+inv_n*x%b*inv_n%b*tot%b)%b;

    }
    printf("%lld\n",ans);
return 0;
}
