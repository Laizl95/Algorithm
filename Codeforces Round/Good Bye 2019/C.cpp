#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e5+5,inf=1e9+5,mod=1e9+7;
typedef long long LL;
int a[N];
int main(){
    int n,t;
    scanf("%d",&t);
    while(t--){
    scanf("%d",&n);
    LL ans=0,xors=0,x;
    rep(i,0,n){
        scanf("%lld",&x);
        ans+=x;
        xors^=x;
    }
    if(ans==xors*2) puts("0\n");
    else{
      if(xors!=0){
            printf("2\n");
            printf("%lld %lld\n",xors,xors+ans);
      }else{
            printf("3\n");
            printf("1 1 %lld\n",ans+2);
      }
    }
    }
return 0;
}
