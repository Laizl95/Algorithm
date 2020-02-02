#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
vector<int> edge[N];
pair<int,int> sum1[N];
pair<int,pair<int,int> > sum2[N];
int sum,ans[3];
void dfs(int u,int p){
    //cout<<u<<" "<<p<<endl;
    sum1[u]=mp(0,u);
    sum2[u]=mp(-1,mp(-1,-1));
    rep(i,0,edge[u].size()){
        int v=edge[u][i];
        if(v==p) continue;
        dfs(v,u);
        if(sum2[u].first>0){
            int dis=sum2[u].first+sum1[v].first+1;
            if(dis>sum){
                sum=dis;
                ans[0]=sum1[v].second;
                ans[1]=sum2[u].second.first;
                ans[2]=sum2[u].second.second;
            }
        }
        if(sum2[v].first>0){
            int dis=sum2[v].first+sum1[u].first+1;
            if(dis>sum){
                sum=dis;
                ans[0]=sum1[u].second;
                ans[1]=sum2[v].second.first;
                ans[2]=sum2[v].second.second;
            }
            if(sum2[v].first+1>sum2[u].first){
                sum2[u].first=sum2[v].first+1;
                sum2[u].second=sum2[v].second;
            }
        }
        int dis=sum1[v].first+sum1[u].first+1;

        if(dis>sum2[u].first){
            sum2[u].first=dis;
            sum2[u].second.first=sum1[u].second;
            sum2[u].second.second=sum1[v].second;
        }
        if(sum1[v].first+1>sum1[u].first)
            sum1[u]=mp(sum1[v].first+1,sum1[v].second);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int u,v;
    rep(i,0,n-1){
        scanf("%d %d",&u,&v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    dfs(1,-1);
    printf("%d\n",sum);
    rep(i,0,3) printf("%d ",ans[i]);puts("");
return 0;
}
