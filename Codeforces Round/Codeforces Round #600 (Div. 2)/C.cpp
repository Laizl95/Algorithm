#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int a[N];
LL sum[2],x[N];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    rep(i,1,n+1) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    LL ans=0;
    rep(i,1,n+1){
        x[i]=a[i];
        if(i>m) x[i]+=x[i-m];
        sum[i&1]=sum[1^(i&1)]+x[i];
        printf("%lld ",sum[i&1]);
    }
    cout<<endl;
return 0;
}
