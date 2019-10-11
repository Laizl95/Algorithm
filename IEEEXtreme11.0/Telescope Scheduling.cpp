#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define mc(x,y) memcpy(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e4+5,MAXN=3,l=2,mod=10;
typedef long long LL;
struct node{
    int l,r,v;
    node(){}
    node(int _l,int _r,int _v):l(_l),r(_r),v(_v){}
     bool operator < (const node &a) const{
        return r<a.r || (r==a.r && l<a.l);
    }
}a[N];
int dp[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
            int l,r,v,max_t=0;
        rep(i,0,n){
            scanf("%d %d %d",&l,&r,&v);
            a[i]=node(l,r,v);
            max_t=max(max_t,r);
        }
        sort(a,a+n);
        dp[0]=0;
        rep(i,1,max_t+1){
          dp[i]=dp[i-1];
          rep(j,0,n){
            if(a[j].r==i) dp[i]=max(dp[i],dp[a[j].l-1]+a[j].v);
          }
        }
        cout<<dp[max_t]<<endl;
    }
return 0;
}
