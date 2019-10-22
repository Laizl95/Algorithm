#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=20;
typedef long long LL;
int dp[1<<N],a[105],w[105];
char str[10005];
map<string,int> mp;
int main(){
   // freopen("d://input.txt","r",stdin);
    int n,id=0,i=0;
    while(scanf("%d",&n)!=EOF){
        scanf(" %[^\n]",str);
        int len=strlen(str);
        string s;int p=0;
        rep(i,0,len){
            if(str[i]!=' ') {s+=str[i];continue;}
            if(!mp.count(s)) mp[s]=++id;
            p|=(1<<(mp[s]-1));
            s="";
        }
         if(!mp.count(s)) mp[s]=++id;
         p|=(1<<(mp[s]-1));
         w[i]=n;
         a[i++]=p;
       // printf("%s %d\n",str,p);
    }
   //rep(j,0,i) printf("%d %d\n",w[j],a[j]);
    int up=1<<id;
    rep(S,0,up) dp[S]=-1; dp[0]=0;
    rep(S,0,up){
        rep(j,0,i){
             if(dp[S]==-1) continue;
             if(dp[S|a[j]]==-1 || dp[S|a[j]]>dp[S]+w[j]){
                dp[S|a[j]]=dp[S]+w[j];
             }
        }
    }
    cout<<dp[up-1]<<endl;
return 0;
}
