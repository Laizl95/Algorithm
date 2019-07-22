#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long LL;
const int N=15;
int vis_row[N][N],vis_column[N][N];
int n,t;
int judge(int x,int y,int d){
    rep(j,y,y+d-1) if(!vis_row[x][j] || !vis_row[x+d][j]) return 0;
      //if(j>n-1) return 0;
    rep(i,x,x+d-1) if(!vis_column[i][y] || !vis_column[i][y+d]) return 0;
      //if(i>n-1) return 0;
     return 1;
}
int main(){
    //freopen("d://input.txt","r",stdin);
    int tot=0,x,y;char c;
    while(scanf("%d %d",&n,&t)!=EOF){
        ms(vis_row,0);ms(vis_column,0);
        rep(i,1,t){
          scanf(" %c %d %d",&c,&x,&y);
          if(c=='H') vis_row[x][y]=1;
          else vis_column[y][x]=1;
        }
        //rep(i,1,n){ rep(j,1,n) printf("%d",vis_row[i][j]);puts("");}
        //puts("");rep(i,1,n){ rep(j,1,n) printf("%d",vis_column[i][j]);puts("");}
        if(tot) printf("\n**********************************\n\n");
        printf("Problem #%d\n\n",++tot);
        int flag=0;
      rep(d,1,n-1){
          int ans=0;
        rep(i,1,n) rep(j,1,n){
         if(judge(i,j,d)) ans+=1;
        }
        if(ans) flag=1,printf("%d square (s) of size %d\n",ans,d);
      }
      if(!flag) puts("No completed squares can be found.");
    }
return 0;
}