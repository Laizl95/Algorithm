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
pii a[N];

int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i].first);
    rep(i,1,n+1) scanf("%d",&a[i].second);
    sort(a+1,a+1+n);
    LL ans=0,cnt=0;
    priority_queue<int> q;
    rep(i,1,n+1){
        int t=a[i].first-a[i-1].first;
        rep(j,1,t+1){
            if(q.empty()) break;
            int t=q.top();
            q.pop();
            cnt-=t;
            ans+=cnt;
        }
        q.push(a[i].second);
        cnt+=a[i].second;
    }
    while(!q.empty()){
        int t=q.top();
            q.pop();
            cnt-=t;
            ans+=cnt;
    }
    cout<<ans<<endl;
return 0;
}
