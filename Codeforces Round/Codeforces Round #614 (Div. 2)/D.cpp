#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5;
typedef long long LL;//128
LL inf=1e16;
LL x_0,y_0,k1,k2,b1,b2,xs,ys,t;
LL cal_dis(pair<LL,LL> p1,pair<LL,LL> p2){
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}
int main(){
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&x_0,&y_0,
          &k1,&k2,&b1,&b2,&xs,&ys,&t);
    LL x=x_0,y=y_0,sum=0;
    vector<pair<LL,LL> > v;
    v.pb(mp(x,y));
    while(1){
        LL x_now=k1*x+b1,y_now=k2*y+b2;
        LL dis=cal_dis(mp(x_now,y_now),mp(x,y));
        v.pb(mp(x_now,y_now));
        x=x_now;y=y_now;
        if(dis>inf) break;
    }
    //rep(i,0,10) cout<<v[i].first<<" "<<v[i].second<<endl;
    int ans=0;
    rep(i,0,v.size()){
       rep(j,i,v.size()){
            LL dis=cal_dis(v[i],v[j]),dis_l=cal_dis(mp(xs,ys),v[i]),
            dis_r=cal_dis(mp(xs,ys),v[j]);
            if(dis_l+dis<=t || dis_r+dis<=t)
                ans=max(ans,j-i+1);
       }
    }
    printf("%d\n",ans);
return 0;
}
