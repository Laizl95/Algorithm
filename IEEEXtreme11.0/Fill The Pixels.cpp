#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005,inf=1e8;
typedef long long LL;
//w-b 1-0  w:1 b:0
int mat[N][N],vis[N][N];
int dir[4][2]={-1,0,1,0,0,-1,0,1};
int dir2[4][2]={-1,-1,-1,1,1,-1,1,1};
int n,m;
void dfs(int x,int y,int id){

   if(id==1 || id==3){
    rep(k,0,4){
         int tx=x+dir[k][0],ty=y+dir[k][1];
    if(tx<0 || tx>n-1 || ty<0 || ty>m-1 || vis[tx][ty] || mat[tx][ty]==0) continue;
     vis[tx][ty]=1;
     dfs(tx,ty,id);
    }
   }
   if(id==2 || id==3){
    rep(k,0,4){
        int tx=x+dir2[k][0],ty=y+dir2[k][1];
        if(tx<0 || tx>n-1 || ty<0 || ty>m-1 || vis[tx][ty] || mat[tx][ty]==0) continue;
        vis[tx][ty]=1;
        dfs(tx,ty,id);
    }
   }
}
int solve(int id){
    rep(i,0,n) rep(j,0,m) vis[i][j]=0;
    int ans=0;
    rep(i,0,n) rep(j,0,m)
         if(mat[i][j]==1 && !vis[i][j]){
            vis[i][j]=1;
            ans+=1;
            dfs(i,j,id);
         }
    return ans;
}
int main(){
    char s[N];
    int t;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d",&m,&n);
       rep(i,0,n){
            scanf("%s",s);
            rep(j,0,m) mat[i][j]=s[j]-'0';
       }
       //rep(i,0,n){rep(j,0,m) printf("%d",mat[i][j]);puts("");}
       int ans=solve(1);
       printf("%d ",ans);
       ans=solve(2);
       printf("%d ",ans);
       ans=solve(3);
       printf("%d \n",ans);
    }
return 0;
}
