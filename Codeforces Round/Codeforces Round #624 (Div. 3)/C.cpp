#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int n,m;
char s[N];
int num[30],vis[N];
int main(){
    int t,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        ms(num,0);
        scanf("%s",s);
        rep(i,0,n) vis[i]=0;
        int x;
        rep(i,0,m) scanf("%d",&x),vis[x-1]+=1;
        int tot=0;
        per(i,0,n){
            int x=s[i]-'a';
            tot+=vis[i];
            //cout<<tot<<endl;
            num[x]+=tot;
            num[x]+=1;
        }

        rep(i,0,26) printf("%d ",num[i]);
    }
return 0;
}
