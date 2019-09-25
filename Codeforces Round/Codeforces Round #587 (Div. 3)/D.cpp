#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
int a[N],b[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        rep(i,0,n) scanf("%d",&a[i]);
        sort(a,a+n);
        rep(i,0,n-1) b[i]=a[i+1]-a[i];

        int ans=b[0];
        rep(i,0,n-1) ans=__gcd(b[i],ans);
        LL ans2=0;
        rep(i,0,n) ans2+=1LL*(a[n-1]-a[i])/ans;
        printf("%I64d %d\n",ans2,ans);
    }
return 0;
}

