#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;

int main(){
    int t,a,b,c,d,k;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
       int x1=a/c+(a%c!=0),x2=b/d+(b%d!=0);
       if(x1+x2>k) puts("-1");
       else printf("%d %d\n",x1,x2);
    }
return 0;
}
