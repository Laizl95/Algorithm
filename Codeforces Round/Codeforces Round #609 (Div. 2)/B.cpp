#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int a[N],b[N],c[N];
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    rep(i,0,n) scanf("%d",&b[i]);
    rep(i,0,n) scanf("%d",&a[i]);
    sort(a,a+n);sort(b,b+n);
    int ans=-1;
    rep(j,0,n){
        int x;
       if(a[j]>=b[0]){
          x=a[j]-b[0];
       }else{
            x=a[j]+m-b[0];
       }
       // cout<<x<<endl;
        rep(i,0,n) c[i]=(b[i]+x)%m;
          sort(c,c+n);
         // rep(i,0,n) printf("%d ",c[i]);puts("");
          int ok=1;
          rep(i,0,n) if(c[i]!=a[i]){ok=0;break;}
          if(ok) {if(ans==-1) ans=x;else ans=min(ans,x);}
    }
    cout<<ans<<endl;
return 0;
}
