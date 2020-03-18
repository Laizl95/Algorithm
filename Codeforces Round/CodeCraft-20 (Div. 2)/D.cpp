#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e3+5,inf=1e9+5;
typedef long long LL;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int vis[N][N],op[N][N],num[N][N],n;
pii mat[N][N];
char ans[N][N];
void get(int i){
    char s[5]={'D','U','R','L','X'};
    printf("%c",s[i]);
}
int dfs(int x,int y,pii fa){

    vis[x][y]=1;
    int cnt=1;
    rep(i,0,4){
        int dx=x+dir[i][0],dy=y+dir[i][1];
        if(dx<0 || dx>=n || dy<0 || dy>=n) continue;
        if(mat[dx][dy]!=fa || vis[dx][dy]) continue;
        if(i&1) op[dx][dy]=i-1;//ans[dx][dy]=get(i-1);
        else op[dx][dy]=i+1;//ans[dx][dy]=get(i+1);
        cnt+=dfs(dx,dy,fa);
    }
    return cnt;
}
int solve(int x,int y,pii fa,int pre_x,int pre_y){
    vis[x][y]=1;
    rep(i,0,4){
        int dx=x+dir[i][0],dy=y+dir[i][1];
        if(dx<0 || dx>=n || dy<0 || dy>=n) continue;
        if(mat[dx][dy]!=fa) continue;
        if(vis[dx][dy]){
            //ans[dx][dy]=get(i);
            op[x][y]=i;
            return 1;
        }
         if(solve(dx,dy,fa,x,y)){
            //ans[x][y]=get(i);
            op[x][y]=i;
            return 1;
         }
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    int x,y;
    set<pii> s;
    rep(i,0,n) rep(j,0,n){
        op[i][j]=-1;
        scanf("%d %d",&x,&y);
        if(x!=-1){--x;--y;}
        mat[i][j]=mp(x,y);
        if(x!=-1) num[x][y]+=1;
        if(x==i && y==j) s.insert(mp(x,y));
    }

    for(auto it:s){
            op[it.fi][it.se]=4;
        int cnt=dfs(it.fi,it.se,it);
        if(cnt!=num[it.fi][it.se]){puts("INVALID");return 0;}
    }
    rep(i,0,n) rep(j,0,n){
        if(!vis[i][j] && mat[i][j]==mp(-1,-1)){
            solve(i,j,mp(-1,-1),-1,-1);
        }
    }
    //rep(i,0,n) {rep(j,0,n) cout<<op[i][j]<<" ";puts("");}
    rep(i,0,n) rep(j,0,n) if(op[i][j]==-1){puts("INVALID");return 0;}
    puts("VALID");
    rep(i,0,n){
       rep(j,0,n) get(op[i][j]);
       puts("");
    }
return 0;
}
