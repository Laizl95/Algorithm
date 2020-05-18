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
const int N=2e5+5,inf=1e9+5,mod=998244353;
typedef long long LL;
int n,m,k;
int a[N],b[N],cnt[N];
vector<int> ans[N];
struct cmp{
    bool operator()(const int &a,const int &b){
        return a>b;
    }
};
int solve(const int &num){
    int l=1,r=k;
    while(l<=r){
        int mid=l+r>>1;
        if(b[mid]<num) r=mid-1;
        else l=mid+1;
    }
    return r;
}
int main(){
    scanf("%d %d",&n,&k);
    rep(i,0,n) {scanf("%d",&a[i]);cnt[a[i]]+=1;}
    rep(i,1,k+1) scanf("%d",&b[i]);
    sort(a,a+n);
    int x=unique(a,a+n)-a,id=0;
    set<int> s;
    rep(i,0,x) s.insert(a[i]);

    //cout<<x<<endl;
    int num=1,tmp=1;
    set<int>::iterator it;
    while(num<=n){
        int pos=solve(tmp);
        if(pos<=0){++id;tmp=1;continue;}
        int now=-1;
        //cout<<"pos="<<pos<<endl;
        it=s.lower_bound(pos);
        if(it==s.end()) it--;
        if(*it>pos && it==s.begin()){++id;tmp=1;continue;}
        if(*it>pos) it--;
        now=*it;
        ++num;
        ++tmp;
        --cnt[now];
        if(cnt[now]==0) s.erase(now);
        ans[id].pb(now);
    }
    cout<<id+1<<endl;
    rep(i,0,id+1){
        printf("%d ",ans[i].size());
        for(auto v:ans[i]) printf("%d ",v);
        printf("\n");
    }

return 0;
}
