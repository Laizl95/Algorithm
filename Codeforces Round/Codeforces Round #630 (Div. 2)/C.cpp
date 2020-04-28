#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
char s[N];
int n,k;
int fa[N],num[N][27];
int find_fa(int x){
    return fa[x]==x?x:fa[x]=find_fa(fa[x]);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d %s",&n,&k,s+1);
       rep(i,1,n+1) fa[i]=i;
       rep(i,1,n+1){
            int x=find_fa(i),y=find_fa(n+1-i);
            if(x!=y) fa[x]=y;
            if(i+k<=n){
                x=find_fa(i+k);
                if(x!=y) fa[x]=y;
            }
       }
       int tot=0;
       map<int,int> mp;
       rep(i,1,n+1){
            int x=find_fa(i);//cout<<x<<endl;
            if(!mp.count(x)) mp[x]=++tot;
            num[mp[x]][s[i]-'a']+=1;
       }
       int ans=0;
       rep(i,1,tot+1){
            int mx=-1,cnt=0;
            rep(j,0,26){
                if(num[i][j]>mx) mx=num[i][j];
                cnt+=num[i][j];
                num[i][j]=0;
            }
            ans+=cnt-mx;
       }
       cout<<ans<<endl;
    }
return 0;
}
