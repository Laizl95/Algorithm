#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=5e2+5,inf=1e9+5;
typedef long long LL;
LL n,k;
int get(LL x){
    int cnt=0;
    while(x){
        x/=2;
        ++cnt;
    }
    return cnt;
}
LL solve(LL x){
    if(x>n) return 0;
    int bit=get(n)-get(x);
    LL ans=(1LL<<bit)-1,y=n;
    y=y>>bit;
    if(x==y){
        ans+=n-(x<<bit)+1;
    }else if(y>x){
        ans+=1LL<<bit;
    }
    return ans;
}
int main(){
   scanf("%lld %lld",&n,&k);
   LL l=1,r=n/2;
   while(l<=r){
        LL mid=l+r>>1;
        //cout<<mid<<" "<<solve(mid*2)<<endl;
        if(solve(mid*2+1)+solve(mid*2)>=k) l=mid+1;
        else r=mid-1;
   }
  // cout<<"1:"<<r<<endl;
   LL ans=r*2;
   l=0;
   if(n&1) r=n/2;
   else r=(n-1)/2;
   while(l<=r){
        LL mid=l+r>>1;
        if(solve(mid*2+1)>=k) l=mid+1;
        else r=mid-1;
   }
   ans=max(r*2+1,ans);
   cout<<ans<<endl;
return 0;
}
