#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
struct node{
    int id,v;
    node(){}
    node(int _v,int _id){v=_v;id=_id;}
    bool operator < (const node &a) const{
        return v>a.v || (v==a.v && id<a.id);
    }
}s[N];
int a[N];
int main(){

    int n,q,m,k;
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",&a[i]);
        s[i]=node(a[i],i);
    }
    sort(s,s+n);
    //rep(i,0,n) cout<<s[i].v<<" ";
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&m,&k);
        vector<node> ans;
        rep(i,0,m) ans.pb(s[i]);
        sort(ans.begin(),ans.end(),cmp);
        printf("%d\n",ans[k-1].v);
    }
return 0;
}
