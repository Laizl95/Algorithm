#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=10005;
int a[N],b[205];
int dp[N];//长度为i+1的不降子序列最后一位的大小
int b_search(int num,int l,int r){
    while(l<=r){
        int mid=l+r>>1;
        if(num<a[mid]) r-=1;
        else l+=1;
    }
    return l;
}
int main(){
  int k,n,m;
  while(scanf("%d",&k)!=EOF){
    rep(i,1,k+1) b[i]=k+1;
    int x;
    scanf("%d",&m);
    rep(i,0,m) scanf("%d",&x),b[x]=i+1;
    scanf("%d",&n);
    int p=0;
    rep(i,0,n){
        scanf("%d",&x);
        if(b[x]<=m) a[p++]=b[x];
    }
    //rep(i,0,p) printf("%d ",a[i]);puts("");
    dp[0]=a[0];int r=0;
    rep(i,1,p){
        int pos=b_search(a[i],0,r);
        //rep(j,0,r+1) printf("%d ",dp[j]);puts("");
        //printf("pos:%d\n",pos);
        if(pos<=r) dp[pos]=a[i];
        else r+=1,dp[pos]=a[i];
    }
    printf("%d\n",r+1);
  }
return 0;
}
