#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;
int a[2*N];
LL sum[2*N],sum2[2*N];
int solve(int l,int r,LL x){
    while(l<=r){
        int mid=l+r>>1;
        if(sum[mid]>=x) r=mid-1;
        else l=mid+1;
    }
    return r;
}
int main(){
    //cout<<(1LL<<62)<<endl;
    int n;
    LL m;
    scanf("%d %lld",&n,&m);
    rep(i,0,n){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
        if(i){
            sum[i]=sum[i-1];
            sum2[i]=sum2[i-1];
        }
        sum[i]+=a[i];
        sum2[i]+=a[i]*1LL*(1+a[i])/2;
    }
    rep(i,n,2*n) sum[i]+=sum[i-1]+a[i],sum2[i]+=sum2[i-1]+a[i]*1LL*(1+a[i])/2;
    //rep(i,0,2*n) printf("%lld ",sum[i]);cout<<endl;
   // rep(i,0,2*n) printf("%lld ",sum2[i]);cout<<endl;
    LL ans=0;
    rep(i,0,n){
        LL x=m;
        if(i) x+=sum[i-1];
        int p=solve(i,i+n-1,x);
        if(p<i){
            int y=a[i]-m;
            ans=max(ans,(1+a[i])*1LL*a[i]/2-(1+y)*1LL*y/2);
            continue;
        }
        x-=sum[p];
        if(a[p+1]-x>=a[i]-1){
            LL y=(1+x+a[i]-1)*1LL*(x+a[i]-1)/2;
            ans=max(ans,sum2[p]-sum2[i]+y+a[i]);
        }else{
            int left=a[p+1]-x;
            ans=max(ans,(1+a[i])*1LL*a[i]/2-(left+1)*1LL*left/2+sum2[p+1]-sum2[i]);
        }
    }
    cout<<ans<<endl;
return 0;
}
