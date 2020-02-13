#pragma GCC optimize(2)
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
int a[N],b[N];
int main(){
    scanf("%d",&n);
    rep(i,0,n) scanf("%d %d",&a[i],&b[i]);
    set<pii> s;
    rep(i,0,n){
        int dx=a[(i+1)%n]-a[i],dy=b[(i+1)%n]-b[i];
        if(s.count(mp(-dx,-dy))) s.erase(mp(-dx,-dy));
        else s.insert(mp(dx,dy));
    }
    if(s.size()==0) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
return 0;
}
