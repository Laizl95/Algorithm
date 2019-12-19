#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e3+5,inf=1e9+5;
typedef long long LL;
struct node{
    int need,add,v;
}a[N];
vector<int> edge;
int main(){
   int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    rep(i,0,n){
        scanf("%d %d %d",&a[i].need,&a[i].add,&a[i].v);
    }
    b[n]=a[i].need;
    per(i,0,n) b[i]=max(b[i+1]-a[i].add,a[i].need);
    rep(i,0,m){
        scanf("%d %d",&u,&v);
        if(u<v) swap(u,v);
        edge[u].pb(v);
        ll[u].pb(a[v-1].v);
    }
    rep(i,0,n) sort(ll[u].begin(),ll[u].end());
    int ans=0;
    rep(i,0,n){
        if(k>=a[i].need){
            k+=a[i].add;

            if(k>=b[i]){
                int t=min(k-b[i],ll[i].size());
                rep(i,0,t){

                }
            }
        }
    }
return 0;
}
