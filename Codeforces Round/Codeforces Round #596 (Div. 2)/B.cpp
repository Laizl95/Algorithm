#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;

int a[N],vis[1000005];

int main(){
    int t,n,k,d;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d %d",&n,&k,&d);
        rep(i,1,n+1) scanf("%d",&a[i]);
        rep(i,1,k+1) vis[i]=0;
        int i=1,tot=0;
        int ans=-1;
        vector<int> v;
        while(i<=n){
            v.pb(a[i]);
            if(!vis[a[i]]) tot+=1;
            vis[a[i]]+=1;
             if(v.size()%d==0){
                   // cout<<tot<<endl;
                if(ans==-1 || ans>tot) ans=tot;
                vis[v[0]]-=1;
                if(vis[v[0]]==0) tot-=1;
                v.erase(v.begin());
             }
             i+=1;
        }
        cout<<ans<<endl;
    }
return 0;
}
