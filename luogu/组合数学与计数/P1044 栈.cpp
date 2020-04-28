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
int f[20][20];//没进栈的x个 栈中y个
int dfs(int x,int y){
    if(f[x][y]) return f[x][y];
    if(x==0) return 1;
    if(y>0) f[x][y]+=dfs(x,y-1);
    f[x][y]+=dfs(x-1,y+1);
    return f[x][y];
}
int main(){
    int n;
    scanf("%d",&n);
    dfs(n,0);
    cout<<f[n][0]<<endl;
return 0;
}
