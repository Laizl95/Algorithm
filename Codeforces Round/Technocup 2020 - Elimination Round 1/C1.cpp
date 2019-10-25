#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
//15:17
int c[N];
bool cmp(int &a,int &b){
    return a>b;
}
int main(){

    int t,n,x,a,y,b;LL k;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,1,n+1) scanf("%d",&c[i]);
        scanf("%d %d %d %d %lld",&x,&a,&y,&b,&k);
        sort(c+1,c+1+n,cmp);
        int l=1,r=n;
        while(l<=r){
            int mid=l+r>>1;
            LL ans=0,temp1=0,temp2=0;int id=1;
            int t1=mid/a,t2=mid/b;
            int t3=mid/(1LL*a/__gcd(a,b)*b);
            rep(i,0,t1) temp1+=1LL*x*c[id++]/100;
            rep(i,0,t2-t3) temp1+=1LL*y*c[id++]/100;
            rep(i,0,t3) {
                temp1+=1LL*y*c[i+1]/100;
            }
            id=1;
            rep(i,0,t2) temp2+=1LL*y*c[id++]/100;
            rep(i,0,t1-t3) temp2+=1LL*x*c[id++]/100;
            rep(i,0,t3) {
                temp2+=1LL*x*c[i+1]/100;
            }
            ans=max(temp1,temp2);
           // cout<<ans<<endl;
            if(ans>=k) r=mid-1;
            else l=mid+1;
        }
        if(l>n) cout<<"-1"<<endl;
        else cout<<l<<endl;
    }
return 0;
}
