#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e5+5,inf=1e9+5,mod=1e9+7;
typedef long long LL;
char s[1005];
//16:50
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
            vector<int> v;
        scanf("%d %s",&n,s+1);
        int len=strlen(s+1);
        rep(i,1,len+1) v.pb(s[i]-'0');
        int p=1;
        while(1){
            int x=v.size();
            rep(j,0,v[p-1]-1){
                rep(i,p,x){
                    v.pb(v[i]);
                    if(v.size()>=n) break;
                }
                if(v.size()>=n) break;
            }
                p+=1;
                if(v.size()>=n) break;
        }
        //rep(i,0,v.size()) printf("%d ",v[i]);
        LL ans=len*1LL;
        rep(i,1,n+1){
           LL now=0;
           rep(j,0,v[i-1]) now=(now+ans-i+mod)%mod;
           ans=(now+i)%mod;
           //ans=((ans-i)*v[i-1]%mod+i)%mod;
        }
        cout<<ans<<endl;
    }
return 0;
}
