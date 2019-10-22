#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
int n;
int a[N];
int main(){
    while(scanf("%d",&n)!=EOF){
       rep(i,0,n){
            scanf("%d",&a[i]);
       }
        sort(a,a+n);
        int tot=n/2;
        LL y=0,x=0;
        rep(i,0,tot) x+=a[i];
        rep(i,tot,n) y+=a[i];
        printf("%lld\n",y*y+x*x);
    }
return 0;
}
