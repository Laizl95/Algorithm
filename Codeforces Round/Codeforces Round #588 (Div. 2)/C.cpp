#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=25+5,inf=1e9+5;
typedef long long LL;

int n,m;
int edge[N][N],num[N];
int main(){
    scanf("%d %d",&n,&m);
    int u,v;
    rep(i,0,m){
        scanf("%d %d",&u,&v);
        if(u>v) swap(u,v);
        edge[u][v]=1;edge[v][u]=1;
        num[u]+=1;
        num[v]+=1;
    }
    if(n<=6) cout<<m<<endl;
    else{
        int ans=22;
        rep(i,1,8)
         rep(j,1,8){
             if(i==j) continue;
             int num=0;
             for(int k=1;k<=7;k++)
                 if(edge[i][k]&&edge[j][k]) num++;
            ans=min(ans,num);
         }
         cout<<m-ans<<endl;
    }
return 0;
}
