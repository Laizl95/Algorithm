#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
struct node{
int s_time,e_time;
queue<int> q;
node(){}
node(int _s,int _e,queue<int> _q):s_time(_s),e_time(_e),q(_q){}
}v[N];
int times[N],ans[N],vis[N];
int main(){
    int n,m,k,t;
    while(scanf("%d %d %d %d",&n,&m,&k,&t)!=EOF){
        rep(i,0,k) scanf("%d",&times[i]);
        rep(i,0,n){
            queue<int> q;
          node window=node(0,0,q);
          v[i]=window;
        }
        int id=0;
        rep(i,0,m){ //第i个客户
          rep(j,0,n){ //第j个窗口
            if(id<k){
             if(i==0) v[j].s_time=times[id];
             if(v[j].e_time>=540) vis[id]=1;
             v[j].e_time+=times[id];
             v[j].q.push(id);
             ans[id]=v[j].e_time;
             //cout<<id<<" "<<ans[id]<<endl;
             id+=1;
             }
         }
        }

        while(id<k){
           int min_time=-1,window_id;
           rep(i,0,n)
             if(min_time==-1) min_time=v[i].s_time,window_id=i;
             else if(min_time>v[i].s_time) min_time=v[i].s_time,window_id=i;
           v[window_id].q.pop();
           int customer_id=v[window_id].q.front();
           v[window_id].s_time+=times[customer_id];
           if(v[window_id].e_time>=540) vis[id]=1;
           v[window_id].e_time+=times[id];
           ans[id]=v[window_id].e_time;
           v[window_id].q.push(id);
           id+=1;
        }
        rep(i,0,t){
          scanf("%d",&id);
          id-=1;
          if(vis[id]) puts("Sorry");
          else printf("%02d:%02d\n",8+ans[id]/60,ans[id]%60);
        }
    }
return 0;
}
