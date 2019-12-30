#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,mod=1e9+7;
typedef long long LL;
//14:40
int n,m;
int a[N];
struct node{
    int p,d;
    node(){}
    node(int _p,int _d){p=_p;d=_d;}
    bool operator < (const node &a) const{
        return d>a.d || (d==a.d && p>a.p);
    }
};
int main(){
    scanf("%d %d",&n,&m);
    priority_queue<node> q;
    map<int,int> mp;
    rep(i,0,n){
        scanf("%d",&a[i]);
        mp[a[i]]=1;
    }
    rep(i,0,n){
        if(!mp.count(a[i]-1)){
            mp[a[i]-1]=1;
            q.push(node(a[i]-1,1));
        }
         if(!mp.count(a[i]+1)){
            mp[a[i]+1]=1;
            q.push(node(a[i]+1,1));
        }
    }
    int cnt=0;vector<int> ans;LL dis=0;
    while(!q.empty()){
        node now=q.top();
        q.pop();
        ans.pb(now.p);
        dis+=now.d;
        if(++cnt==m) break;
        if(!mp.count(now.p-1)){
             mp[now.p-1]=1;
            q.push(node(now.p-1,now.d+1));
        }
        if(!mp.count(now.p+1)){
             mp[now.p+1]=1;
            q.push(node(now.p+1,now.d+1));
        }
    }
    printf("%lld\n",dis);
    rep(i,0,ans.size()) printf("%d ",ans[i]);puts("");
return 0;
}
