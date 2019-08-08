#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=100005;
int a[N],vis[N/10];
int main(){
int n;
while(scanf("%d",&n)!=EOF){
        rep(i,1,10001) vis[i]=0;
    rep(i,0,n) scanf("%d",&a[i]),vis[a[i]]+=1;
    int flag=0;
    rep(i,0,n) if(vis[a[i]]==1){
      flag=1;
      printf("%d\n",a[i]);
      break;
    }
    if(!flag) printf("None\n");
}
return 0;
}
