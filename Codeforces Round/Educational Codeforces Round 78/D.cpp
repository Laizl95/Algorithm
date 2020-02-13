#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=5e5+5,inf=1e9+5;
typedef long long LL;
int a[N],b[N];
struct cmp{
    bool operator()(const pii &a,const pii &b){
        return a.first>b.first;
    }
};
bool cmp1(const pii &a,const pii &b){
    return a.first>b.first;
}
set<pii> s;
int fa[N];
pii c[2*N];
int find_fa(int x){
    return fa[x]==x?x:fa[x]=find_fa(fa[x]);
}
int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n+1){
        fa[i]=i;
        scanf("%d %d",&a[i],&b[i]);
        c[i*2-1]=mp(a[i],-i);
        c[i*2]=mp(b[i],i);
    }
    sort(c+1,c+2*n+1,cmp1);
    rep(i,1,2*n+1){
        if(c[i].second>0) s.insert(c[i]);
        else{
          for(auto it: s){
            if(it.second==-c[i].second){
                s.erase(it);break;
            }
            int fa_it=find_fa(it.second),fa_i=find_fa(-c[i].second);
            if(fa_it!=fa_i) fa[fa_it]=fa_i;
            else{
                cout<<"NO"<<endl;
                return 0;
            }
          }
        }
    }
    int root=find_fa(1);
    rep(i,1,n+1){
        if(root!=find_fa(i)){
             cout<<"NO"<<endl;
                return 0;
        }
    }
    cout<<"YES"<<endl;
return 0;
}
