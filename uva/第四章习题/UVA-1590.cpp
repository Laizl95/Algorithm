#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long LL;
const int N=1005;
int n;
int ip[N][5],binary[N][10];
void solve(int j){
  int pos;
  rep(i,1,n){
     int x=ip[i][j];pos=-1;
     while(x){
        binary[i][++pos]=x&1;
        x>>=1;
     }
     while(pos<7) binary[i][++pos]=0;
  }
  rep(j,0,pos) binary[0][j]=1;
  rep(i,1,n)rep(j,0,pos) binary[0][j]&=binary[i][j];
  //rep(i,0,n){per(k,0,pos)printf("%d",binary[i][k]);puts("");}puts("");
  rep(i,1,j-1) printf("%d.",ip[1][i]);
  int x=0;
  rep(i,0,pos) x+=binary[0][i]<<i;
  printf("%d",x);
  rep(i,j+1,4) printf(".%d",0); puts("");
  //per(k,0,pos)printf("%d",binary[0][k]);puts("");
  //rep(j,1,n){per(i,0,pos)  printf("%d",binary[j][i]);puts("");}
   x=-1;
  per(i,0,pos){
      rep(j,1,n)
      if(binary[j][i]!=binary[1][i]) {x=i+1;break;}
      if(x!=-1) break;
  }
  rep(i,1,j-1) printf("255.");
  int ans=0;
  rep(i,x,pos) ans+=1<<i;
  printf("%d",ans);
  rep(i,j+1,4) printf(".%d",0); puts("");
}
int main(){
    //freopen("d://input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        rep(i,1,n) scanf("%d.%d.%d.%d",&ip[i][1],&ip[i][2],&ip[i][3],&ip[i][4]);
        //rep(i,1,n) printf("%d %d %d %d\n",ip[i][1],ip[i][2],ip[i][3],ip[i][4]);
           int p=0;
           rep(j,1,4){
               int flag=ip[1][j];
           rep(i,1,n){
               if(ip[i][j]!=flag){
               solve(j);
               flag=ip[i][j];
               break;
               }
           }
             if(flag!=ip[1][j]) {p=1;break;}
          }
          if(!p){
             printf("%d.%d.%d.%d\n",ip[1][1],ip[1][2],ip[1][3],ip[1][4]);
             printf("255.255.255.255\n");
          }
    }
return 0;
}