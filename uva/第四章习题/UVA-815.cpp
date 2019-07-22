#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long LL;
const int N=35;
int n,m,v;
int maps[N*N];
int solve(int k){
    int d=0;
    per(i,1,k) d+=maps[k]-maps[i];
    if(d*100<v) return 1;
    if(d*100>v) return 0;
    return -1;
}
int main(){
    int t=0;
 while(scanf("%d %d",&n,&m)!=EOF){
        if(!n && !m) break;
        int sum=0;
    rep(i,1,n) rep(j,1,m) scanf("%d",&maps[(i-1)*m+j]),sum+=maps[(i-1)*m+j];
    sort(maps+1,maps+1+n*m);
    scanf("%d",&v);
    double ans=0;
    printf("Region %d\n",++t);
    per(i,1,n*m){
      //(y*v-sum(maps[j]))*100=v;
      int op=solve(i);
      if(op){
        per(j,i+1,n*m) sum-=maps[j];
        printf("Water level is %.2lf meters.\n",(v*1.0/100+sum)/i);
        if(op==1)printf("%.2lf percent of the region is under water.\n",i*100.0/(n*m));
        else printf("%.2lf percent of the region is under water.\n",(i-1)*100.0/(n*m));
        puts("");
        break;
      }
    }
 }
return 0;
}