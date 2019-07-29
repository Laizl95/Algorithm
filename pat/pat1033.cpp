#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=505;
//按照距离排序,选择比当前位置价格低的位置即为最优
int d,per_d,n;
int v_max;
struct node{
 double v;
 int d;
 node(){}
 node(double _v,int _d){v=_v;d=_d;}
 bool operator < (const node &a) const{
    return d<a.d;
 }
}a[N];
struct site{
    double v;int d,id;
    site(){}
    site(double _v,int _d,int _id){v=_v;d=_d;id=_id;}
    bool operator < (const site &a) const{
      return v>a.v;
    }
};
double dfs(int u,double cost,double v_now){
   // printf("u=%d cost=%.2lf\n",u,cost);
    if(u==n) return cost;
   int dis=v_max*per_d;
   int zd=u+1;double ans=-1;
   vector<site> v;
   while(zd<=n && a[zd].d-a[u].d<=v_max*per_d)
    v.pb(site(a[zd].v,a[zd].d,zd)),++zd;
    if(v.size()==0){
        printf("The maximum travel distance = %.2lf\n",a[u].d*1.0+v_max*per_d);
        return -1;
    }
    int ok=0,id=zd-1;
    rep(j,0,v.size()) if(v[j].v<a[u].v){ok=1;id=v[j].id;break;}
    if(ok) ans=dfs(id,cost+((a[id].d-a[u].d)*1.0/per_d-v_now)*a[u].v,0);
    else ans=dfs(id,cost+(v_max-v_now)*a[u].v,v_max-(a[id].d-a[u].d)*1.0/per_d);

   return ans;
}
int main(){

    while(scanf("%d %d %d %d",&v_max,&d,&per_d,&n)!=EOF){
        rep(i,0,n) scanf("%lf %d",&a[i].v,&a[i].d);
        a[n]=node(0,d);
        sort(a,a+n);
        //rep(i,0,n+1) printf("%lf %d\n",a[i].v,a[i].d);
        if(a[0].d!=0){printf("The maximum travel distance = %.2lf\n",0);continue;}
        double cost=dfs(0,0,0);
        if(cost!=-1){
            printf("%.2lf\n",cost);
        }
    }
return 0;
}
