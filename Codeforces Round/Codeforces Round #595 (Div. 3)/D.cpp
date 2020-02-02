#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define lson l,mid,i<<1
#define rson mid+1,r,i<<1|1
#define ls i<<1
#define rs i<<1|1
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
vector<pair<int,int> > v[N];
struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.first<b.first;
    }
};
int main(){

    int n,m;
    scanf("%d %d",&n,&m);
    int x,y;
    rep(i,0,n){
        scanf("%d %d",&x,&y);
        v[x].pb(mp(y,i+1));
    }
    vector<int> ans;
    multiset<pair<int,int> >::iterator it;
    multiset<pair<int,int>,cmp> s;
    rep(i,0,2e5+1){
        rep(j,0,v[i].size()) s.insert(v[i][j]);
        while(s.size()>m){
            ans.pb((*s.rbegin()).second);
            s.erase(prev(s.end()));
        }
        for(it=s.begin();it!=s.end();){
            if((*it).first==i){s.erase(it++);}
            else break;
        }
    }
    int t=ans.size();
    printf("%d\n",t);
    rep(i,0,t) printf("%d ",ans[i]);puts("");
return 0;
}
