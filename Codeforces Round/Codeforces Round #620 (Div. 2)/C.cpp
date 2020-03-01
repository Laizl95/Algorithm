#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int n,m;
struct node{
    int t; LL l,r;
}a[N];
int b[N],c[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        rep(i,1,n+1) scanf("%d %lld %lld",&a[i].t,&a[i].l,&a[i].r);
        a[0].l=m;a[0].r=m;a[0].t=0;
        b[0]=m*1LL;c[0]=m*1LL;
        int ok=1;
        rep(i,1,n+1){
            LL t1=a[i].t-a[i-1].t;
            LL rr=t1+b[i-1],ll=b[i-1]-t1,r1=c[i-1]+t1,l1=c[i-1]-t1;
             b[i]=min(min(rr,ll),min(r1,l1));
             c[i]=max(max(rr,ll),max(r1,l1));
             if(b[i]>a[i].r || c[i]<a[i].l){ok=0;break;}
             else{
                if(b[i]<a[i].l) b[i]=a[i].l;
                if(c[i]>a[i].r) c[i]=a[i].r;
             }
        }
        puts(ok?"YES":"NO");
    }
return 0;
}
