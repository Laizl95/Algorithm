#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=1005;
int vis[N];
double d[N];
int main(){
 int l1,l2;
 while(scanf("%d",&l1)!=EOF){
    int x;
    rep(i,0,l1){
        scanf("%d",&x);
        scanf("%lf",&d[x]);
        vis[x]=1;
    }
    scanf("%d",&l2);
    double num;
    rep(i,0,l2){
     scanf("%d %lf",&x,&num);
      d[x]+=num;
      vis[x]=1;
    }
    int cnt=0;
    rep(i,0,1001) if(d[i]!=0) ++cnt;
    printf("%d",cnt);
    per(i,0,1001) if(d[i]){
        vis[i]=0;
      printf(" %d %.1lf",i,d[i]);
    }
    puts("");
 }
return 0;
}
