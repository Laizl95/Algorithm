#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;

LL solve(LL x){
    if(x%4==0) return x;
    if(x%4==1) return 1;
    if(x%4==2) return x+1;
    return 0;
}
int main(){
   int t;
   LL l,h,n,d1,d2;
   scanf("%d",&t);
   while(t--){
        scanf("%lld %lld %lld %lld %lld",&l,&h,&n,&d1,&d2);
        LL r=l*1LL*h+n-1;
        LL y1=(d1-n)/l,x1=(d1-n)%l,y2=(d2-n)/l,x2=(d2-n)%l;
        //cout<<y1<<" "<<y2<<endl;
        LL ans=solve(r)^solve(n-1);
        LL vl=y1*l+min(x1,x2)+n;
        LL vr=vl+abs(x1-x2);
        //cout<<vl<<" "<<vr<<endl;
        rep(i,y1,y2+1){
          ans=ans^solve(vl-1)^solve(vr);
          vl+=l;vr+=l;
        }
        printf("%lld\n",ans);
   }
return 0;
}
