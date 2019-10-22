#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
int n,m;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
      scanf("%d",&n);
      int x,tot1=0,tot2=0;
      rep(i,0,n){
        scanf("%d",&x);
        if(x&1) tot1+=1;
        else tot2+=1;
      }scanf("%d",&m);
      LL ans=0;
      rep(i,0,m){
        scanf("%d",&x);
        if(x&1) ans+=tot1;
        else ans+=tot2;
      }
      cout<<ans<<endl;
    }
return 0;
}
