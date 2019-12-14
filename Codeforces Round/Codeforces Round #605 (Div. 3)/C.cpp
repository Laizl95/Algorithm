#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
char s[N];
int vis[35];
int main(){
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF){
        ms(vis,0);
        scanf("%s",s);
        char c;
        rep(i,0,k){
            scanf(" %c",&c);
            vis[c-'a']=1;
        }
        LL ans=0;
        int tot=0;
        rep(i,0,n){
            if(vis[s[i]-'a']) tot+=1;
            else{
                ans+=tot*1LL*(tot+1)/2;
                tot=0;
            }
        }
        if(tot)ans+=tot*1LL*(tot+1)/2;
        printf("%lld\n",ans);
    }
return 0;
}
