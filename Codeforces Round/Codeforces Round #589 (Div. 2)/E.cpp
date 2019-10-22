#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e5+5;
typedef long long LL;
LL a[N];

int main(){
    LL ans=1;
   // rep(i,1,12) ans*=i;
    //cout<<ans<<endl;
    int n;LL k;
    while(scanf("%d %lld",&n,&k)!=EOF){
        rep(i,0,n) scanf("%lld",&a[i+1]);
        sort(a+1,a+n+1);
        //rep(i,0,n) printf("%lld ",a[i+1]);puts("");
        LL ans=a[n]-a[1];int l=1,r=n;
        while(l<r){
                if(k==0) break;
             LL l_goal=min(a[l]+k/l,a[l+1]),r_goal=max(a[r]-k/(n-r+1),a[r-1]);
             if(l<=n-r+1){
                k-=(l_goal-a[l])*l;
                l+=1;
                //printf("a[r]:%lld l_goal:%lld\n",a[r],l_goal);
                ans=min(ans,a[r]-l_goal);
                 if(l_goal!=a[l]) break;
             }else{
                k-=(a[r]-r_goal)*(n-r+1);
                r-=1;
                //printf("r_goal:%lld a[l]:%lld\n",r_goal,a[l]);
                ans=min(ans,r_goal-a[l]);
                 if(r_goal!=a[r]) break;
             }

        }
        cout<<ans<<endl;
 }
return 0;
}

//虽然当某个点到达下一个点时的花费小于另一个点到达其下一个点的花费，也还是有可能选花费大的
//有虽然花费少但最优值大的情况出现
//收益最大的情况是把值给左右两边个数最小的时候
