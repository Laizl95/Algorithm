#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=3505,inf=1e9+5;
typedef long long LL;
int n,m,k;
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        int num=min(k,m-1);
        rep(i,1,n+1) scanf("%d",&a[i]);
        int ans=-1,tot=m-1-num;

        rep(i,0,num+1){
           int l=i+1,r=n-(num-i);
           int g=1e9+5;
           rep(i,0,tot+1){
                int ll=l+i,rr=r-(tot-i);
                g=min(g,max(a[ll],a[rr]));
           }
           ans=max(ans,g);
        }
        printf("%d\n",ans);
    }
return 0;
}
