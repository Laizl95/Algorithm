#include<bits/stdc++.h>
using namespace std;
const int N = 210;
const int INF = 0x7FFFFFFF;
int n,m,maps[N][N],path[N],flow[N],start,end;
queue<int> q;
 int bfs(){
     int i,t;
     while(!q.empty()) q.pop();
     memset(path,-1,sizeof(path));
     path[start]=0,flow[start]=INF;
     q.push(start);
     while(!q.empty()){
         t=q.front();
         q.pop();
         if(t==end) break;
         for(i=1;i<=m;i++){
             if(i!=start && path[i]==-1 && maps[t][i]){
                 flow[i]=flow[t]<maps[t][i]?flow[t]:maps[t][i];
                 q.push(i);
                 path[i]=t;
             }
         }
     }
     if(path[end]==-1) return -1;
     return flow[m];                   //一次遍历之后的流量增量
 }
 int Edmonds_Karp(){
     int max_flow=0,step,now,pre;
     while((step=bfs())!=-1){          //找不到增路径时退出
         max_flow+=step;
         now=end;
         while(now!=start){
             pre=path[now];
             maps[pre][now]-=step;      //更新正向边的实际容量
             maps[now][pre]+=step;      //添加反向边
             now=pre;
         }
     }
     return max_flow;
 }
 int main(){
     int i,u,v,cost;
     while(scanf("%d %d",&n,&m)!=EOF){
         memset(maps,0,sizeof(maps));
         for(i=0;i<n;i++){
             scanf("%d %d %d",&u,&v,&cost);
             maps[u][v]+=cost;           //not just only one input
         }
         start=1,end=m;
         printf("%d\n",Edmonds_Karp());
     }
     return 0;
 }
