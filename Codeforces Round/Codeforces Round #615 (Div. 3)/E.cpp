#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
vector<int> v[N];
int num[N];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int cnt=0,x;
    rep(i,0,n)
        rep(j,0,m){
            scanf("%d",&x);
            --x;
            if(x%m==j%m && x/m<n) v[j].pb(x);
            else cnt+=1,v[j].pb(-1);
        }
    rep(j,0,m){
        x=-1;int tot=0;
        int t=v[j].size();
        rep(k,0,t){
           if(v[j][k]!=-1){
                num[(k-v[j][k]/m+t)%t]+=1;
           }
           else ++tot;
        }
        rep(i,0,t){
            if(x==-1 || x>i+n-num[i]-tot)
                x=i+n-num[i]-tot;
        }
        rep(i,0,t) num[i]=0;
        cnt+=x;
    }
    printf("%d\n",cnt);

return 0;
}
