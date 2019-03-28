#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
typedef long long LL;
using namespace std;
const int N=20;
int n;
int a[N],vis[N];
int judge(int x){
    int a=sqrt(x);
    //if(x==9)cout<<x<<" "<<a<<endl;
    rep(i,2,a) if(x%i==0) return 0;
    return 1;
}
void dfs(int pre,int d,vector<int> &ans){

  if(d==n){
    int m=ans.size()-1;
    if(judge(ans[m]+ans[0])){
        rep(i,0,m) printf("%d%c",ans[i],i==m?'\n':' ');
    }
    return;
  }
  rep(i,1,n){
   if(vis[i] || !judge(pre+i)) continue;
   vis[i]=1;
   ans.push_back(i);
   dfs(i,d+1,ans);
   ans.pop_back();
   vis[i]=0;
  }
}
int main(){
 int cas=0;
 while(scanf("%d",&n)!=EOF){
    if(cas) puts("");
    vector<int> ans;
    ms(vis,0);
    printf("Case %d:\n",++cas);
    ans.push_back(1);
    vis[1]=1;
    dfs(1,1,ans);
 }
return 0;
}
