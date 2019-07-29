#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=10005;
struct customer{
    int h,m,s,v,t;
    customer(){}
    customer(int _h,int _m,int _s,int _v){h=_h;m=_m;s=_s;v=_v;t=h*60*60+m*60+s;}
    bool operator < (const customer &a) const{
       if(a.h!=h) return h<a.h;
       if(a.m!=m) return m<a.m;
       return s<a.s;
    }
}s[N];
int w[105];
int main(){
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF){
            int h,m,ss,v;
        rep(i,0,n){
          scanf("%d:%d:%d %d",&h,&m,&ss,&v);
          v*=60;
          s[i]=customer(h,m,ss,v);
        }
       sort(s,s+n);
       int c_id=0,s_time=8*3600,e_time=17*3600+1;
       rep(i,0,k) w[i]=s_time;
       double ans=0;int num=0,id=0;
       while(id<n){
         if(s[id].t>=e_time) break;
         int win_t=w[0],win_id=0;
         rep(i,0,k) if(w[i]<win_t) win_id=i,win_t=w[i];
         //cout<<" "<<win_id<<" "<<win_t/3600<<":"<<(win_t%3600)/60<<":"<<(win_t%3600)%60<<" ";
         //if(w[win_id]>e_time) break;
         if(s[id].t<w[win_id]) ans+=w[win_id]-s[id].t,w[win_id]+=s[id].v;
         else w[win_id]=s[id].t+s[id].v;
        // cout<<w[win_id]/3600<<":"<<(w[win_id]%3600)/60<<":"<<(w[win_id]%3600)%60<<endl;
         num+=1;
         id+=1;
       }
       printf("%.1lf\n",ans*1.0/60/num);
    }
return 0;
}
