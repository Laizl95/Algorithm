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
int n;
int a[N],ans[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",&a[i]),ans[i]=0;

        map<int,int> mp;
        int tot=1;
        rep(i,0,n){
            int x=a[i];
            for(int j=2;j*j<=x;++j){
                if(x%j==0){
                    if(!mp.count(j)) mp[j]=tot++;
                    if(!ans[i]) ans[i]=mp[j];
                    while(x%j==0) x/=j;
                }
            }

            if(x>1){
                if(!mp.count(x)) mp[x]=tot++;
                    if(!ans[i]) ans[i]=mp[x];
            }
        }
        map<int,int> mp2;
        tot=1;
        rep(i,0,n){
            if(!mp2.count(ans[i])) mp2[ans[i]]=tot++;
            ans[i]=mp2[ans[i]];
        }
        cout<<tot-1<<endl;
        rep(i,0,n) printf("%d ",ans[i]);puts("");
    }
return 0;
}
