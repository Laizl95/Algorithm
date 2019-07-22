#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long LL;
const int N=15;
//G 将军 R 车 H 马 C 炮
int t,n,m;
int vis[N][N],maps[N][N];
struct node{
 int x,y;
 char c;
 node(){}
 node(int _x,int _y,char _c){
   x=_x;
   y=_y;
   c=_c;
 }
}s[N];
void work_chariot(int x,int y){
  rep(i,y+1,9){
      if(maps[x][i]) break;
      vis[x][i]=1;
  }
  per(i,1,y-1){
      if(maps[x][i]) break;
      vis[x][i]=1;
  }
  rep(i,x+1,10){
      if(maps[i][y]) break;
      vis[i][y]=1;
  }
   per(i,1,x-1){
      if(maps[i][y]) break;
      vis[i][y]=1;
  }
}
int judge(int x,int y){
  if(x>=1 && x<=10 && y<=9 && y>=1 && !maps[x][y]) return 1;
  return 0;
}
void work_horse(int x,int y){
  if(x-1>=1 && !maps[x-1][y]){
    if(judge(x-2,y-1)) vis[x-2][y-1]=1;
    if(judge(x-2,y+1)) vis[x-2][y+1]=1;
  }
  if(x+1<=10 && !maps[x+1][y]){
    if(judge(x+2,y+1)) vis[x+2][y+1]=1;
    if(judge(x+2,y-1)) vis[x+2][y-1]=1;
  }
  if(y+1<=9 && !maps[x][y+1]){
    if(judge(x+1,y+2)) vis[x+1][y+2]=1;
    if(judge(x-1,y+2)) vis[x-1][y+2]=1;
  }
  if(y-1>=1 && !maps[x][y-1]){
    if(judge(x+1,y-2)) vis[x+1][y-2]=1;
    if(judge(x-1,y-2)) vis[x-1][y-2]=1;
  }
}
void work_cannon(int x,int y){
  per(i,1,x-1) if(maps[i][y]){
    int t=i-1;
    while(t>=1 && !maps[t][y])
      vis[t--][y]=1;
      break;
  }
  rep(i,x+1,10) if(maps[i][y]){
     int t=i+1;
    while(t<=10 && !maps[t][y])
      vis[t++][y]=1;
      break;
  }
  per(i,1,y-1) if(maps[x][i]){
     int t=i-1;
     while(t>=1 && !maps[x][t])
        vis[x][t--]=1;
     break;
  }

  rep(i,y+1,9) if(maps[x][i]){
     int t=i+1;
     while(t<=9 && !maps[x][t])
        vis[x][t++]=1;
     break;
  }
}
void work_boss(int x,int y){
    int flag=1;
   rep(i,1,10) if(x!=i && maps[i][y]) flag=0;
   if(flag) rep(i,1,10) vis[i][y]=1;
}
void work(int i){
    if(s[i].c=='R') work_chariot(s[i].x,s[i].y);
    else if(s[i].c=='H') work_horse(s[i].x,s[i].y);
    else if(s[i].c=='C') work_cannon(s[i].x,s[i].y);
    else if(s[i].c=='G') work_boss(s[i].x,s[i].y);
}
int solve(int x,int y){
  if(x>=1 && x<=3 && y>=4 && y<=6)
    if(!vis[x][y]){
            if(!maps[x][y]) return 0;
            int copy_vis[N][N];
            rep(i,1,10) rep(j,1,9) copy_vis[i][j]=vis[i][j];
            maps[x][y]=0;
            rep(i,1,t) work(i);
            //rep(i,1,10){ rep(j,1,9) printf("%d",vis[i][j]); puts("");}
            if(vis[x][y]){rep(i,1,10)rep(j,1,9)vis[i][j]=copy_vis[i][j];maps[x][y]=1;return 1;}
            else {rep(i,1,10)rep(j,1,9)vis[i][j]=copy_vis[i][j];maps[x][y]=1;return 0;}

    }
  return 1;
}
int main(){
    int x,y;char c;
    while(scanf("%d %d %d",&t,&n,&m)!=EOF){
       if(!t || !n || !m) break;
       ms(vis,0);ms(maps,0);
       rep(i,1,t){
         scanf(" %c %d %d",&c,&x,&y);
         s[i]=node(x,y,c);
         maps[x][y]=1;
       }
       rep(i,1,t) work(i);
      // rep(i,1,10){ rep(j,1,9) printf("%d",vis[i][j]); puts("");}
       if(solve(n+1,m) && solve(n-1,m) && solve(n,m+1) && solve(n,m-1))
          puts("YES");
       else puts("NO");
    }
return 0;
}