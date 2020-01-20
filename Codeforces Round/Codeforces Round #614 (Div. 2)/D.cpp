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
        LL sum=t,dis=cal_dis(v[i],mp(xs,ys));
        int cnt=0;
        if(sum>=dis){
            sum-=dis;LL buf=sum;
            ans=max(ans,1);
            rep(j,0,i){
                dis=cal_dis(v[i],v[j]);
                cnt=1;
                if(sum>=dis){
                    LL d=sum-dis;
                    cnt+=i-j;
                    ans=max(ans,cnt);
                    rep(k,i+1,v.size()){
                        dis=cal_dis(v[k],v[j]);
                        if(d>=dis){
                            ans=max(ans,cnt+k-i);
                        }else break;
                    }
                }
            }
                rep(k,i+1,v.size()){
                        dis=cal_dis(v[k],v[i]);
                        if(sum>=dis){
                            ans=max(ans,cnt+k-i);
                        }else break;
                }
                //cout<<ans<<endl;
            sum=buf;
            rep(j,i+1,v.size()){
                dis=cal_dis(v[i],v[j]);
                cnt=1;
                if(sum>=dis){
                    LL d=sum-dis;
                    cnt+=j-i;
                    ans=max(ans,cnt);
                    per(k,0,i){
                        dis=cal_dis(v[k],v[j]);
                        if(d>=dis){
                            ans=max(ans,cnt+i-k);
                        }else break;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
return 0;
}
