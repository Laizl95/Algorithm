#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
typedef long long LL;
using namespace std;
int vis[10];
int n;
int judge(int x){
    int t=-1,d=0;
    int num[10];ms(num,0);
    while(d++<=4){
        if(vis[x%10] || (++num[x%10])>1) return 0;
        x/=10;
    }
    if(x) return 0;
    return 1;
}
int dfs(int d,int x){
 if(d==5){
    if(judge(x*n)){
        printf("%05d / %05d = %d\n",x*n,x,n);
        return 1;
    }
    return 0;
 }
 int ok=0;
 rep(i,0,9){
  if(vis[i]) continue;
  vis[i]=1;
  ok|=dfs(d+1,x*10+i);
  vis[i]=0;
 }
 return ok;
}
int main(){
int t=0;
while(scanf("%d",&n)!=EOF && n){
        if(t++) puts("");
        int flag=0;
        flag|=dfs(0,0);
        if(!flag) printf("There are no solutions for %d.\n",n);
}
return 0;
}
