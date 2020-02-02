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
int n;
LL m;
vector<pii > v,buf;
bool cmp(const pii &a,const pii &b){
    return a.first<b.first || (a.first==b.first && a.second<b.second);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %lld",&n,&m);
        int x,y;
        v.clear();
        rep(i,0,n) {
            scanf("%d %d",&x,&y);
            v.pb(mp(x,y));
        }
        sort(v.begin(),v.end(),cmp);
        //for(auto it: v) printf("%d %d\n",it.first,it.second);
        int l=1L,r=1e9;
        while(l<=r){
            LL mid=(l+r)>>1;
            int tot=0;LL num=0;
            for(auto it: v){
                if(it.first>mid) ++tot,num+=it.first;
                else if(it.second>=mid && it.first<=mid){
                    buf.pb(it);
                }
            }
            int need=(n+1)/2-tot;
            //cout<<need<<" "<<buf.size()<<endl;
            if(need<=0 || num>m || buf.size()<need){
                   if(need<=0) l=mid+1;
                   else r=mid-1;
            }
            else{
                rep(i,0,need) num+=mid;
                rep(i,0,buf.size()-need) num+=buf[i].first;
                   // cout<<num<<endl;
                if(num>m) r=mid-1;
                else{
                    for(auto it: v)
                        if(it.second<mid) num+=it.first;
                    if(num>m) r=mid-1;
                    else l=mid+1;
                }

            }
            buf.clear();
        }
        printf("%d\n",l-1);
    }
return 0;
}
