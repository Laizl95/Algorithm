#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> fact,ans;
        int v[3];
        int buf=n;
        for(int i=2;i*i<=n;++i){
            if(n%i==0){
                int tot=1;
                fact.pb(i);
                while(n%i==0){
                    tot*=i;
                    n/=i;
                }
                ans.pb(tot);
            }
        }
        if(n>1) ans.pb(n),fact.pb(n);
        int tot=0;
        rep(i,0,ans.size()){
            int now=ans[i],f=fact[i];
            while(now%f==0){
                now/=f;
                v[tot]=f;
                tot+=1;
                f*=f;
                if(tot==2) break;
            }
            if(tot==2) break;
        }
        if(tot<2) printf("NO\n");
        else{
            int l=buf/(v[0]*v[1]);
            if(l!=v[0] && v[1]!=l && l>1){
                puts("YES");
                printf("%d %d %d\n",l,v[1],v[0]);
            }
            else printf("NO\n");
        }

    }
return 0;
}
