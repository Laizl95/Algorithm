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
int n,m,k;
int num[26],ans[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        rep(i,0,26) num[i]=0;
        int x=0,tot=0;
        rep(i,1,m+1){
           if(x<k){
             ans[i]=tot;
             num[tot]+=1;
             ++tot;
             ++x;
           }else{
             ans[i]=ans[i-1];
           }
        }
        rep(i,m+1,n+1){
            num[ans[i-m]]-=1;
            if(num[ans[i-m]]==0){
                ans[i]=ans[i-m];
                ++num[ans[i]];
            }

        }
        rep(i,1,n+1) printf("%c",ans[i]+'a');puts("");

    }
return 0;
}
