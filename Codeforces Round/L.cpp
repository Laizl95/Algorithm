#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    int t,a,b,c;

    scanf("%d",&t);
    while(t--){
      scanf("%d %d %d",&a,&b,&c);
      int ans;
      if(a>c) swap(a,c);
     rep(i,0,1000){
        if(a>i+1) continue;
        if(a+b>=i+1 && c<=2*(i+1)-(a+b-i-1)){ans=i+1;break;}
        if(a+b<i+1 && b+c>i+1 && c<=2*(i+1)){ans=i+1;break;}
      }
      printf("%d\n",ans);
    }
return 0;
}
