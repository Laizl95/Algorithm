#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
int a[N],sum[N],b[N];
LL cal1(LL x){
        LL ans=0;
    for(LL i=1,l=1;;i++,l*=10){
        LL r=l*10-1;if(r>x) r=x;
        LL n=x-l+1,m=max(x-r+1,1LL);
        ans+=i*(n+m)*(n-m+1)/2;
        if(r==x) break;
    }
    return ans;
}
LL cal2(LL x){
        LL ans=0;
    for(LL i=1,l=1;;i++,l*=10){
        LL r=l*10-1;if(r>x) r=x;
        LL n=x-l+1,m=max(x-r+1,1LL);
        ans+=i*(n-m+1);
        if(r==x) break;
    }
    return ans;
}
LL solve(int l,int r,LL x){
        while(l<=r){
            int mid=(l+r)/2;
            if(cal1(mid*1LL)<x) l=mid+1;
            else r=mid-1;
        }
        return l;
}
LL solve2(int l,int r,LL x){

        while(l<=r){
            int mid=l+r>>1;
            if(cal2(mid*1LL)<x) l=mid+1;
            else r=mid-1;
        }
        return l;
}
int main(){
    int t,p=1e9+1;
    scanf("%d",&t);
    while(t--){
         LL x;
         scanf("%lld",&x);
         LL l=solve(1,p-1,x);//在第几组里面
         //printf("%d ",x-sum[l-1]);
         LL r=solve2(1,p-1,x-cal1(l-1));//在该组哪个数字
         //printf("%d\n",x-sum[l-1]-a[r-1]);这个数字第几个
         LL goal=x-cal1(l-1)-cal2(r-1);
         vector<int> ans;
         while(r){
           ans.pb(r%10);
           r/=10;
         }
         reverse(ans.begin(),ans.end());
         rep(i,0,ans.size()) if((i+1)*1LL==goal) printf("%d\n",ans[i]);
    }
return 0;
}
