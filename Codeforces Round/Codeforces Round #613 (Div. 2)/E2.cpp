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
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
multiset<int>::iterator iter;
int n;
struct cmp{
    bool operator()
    (const pair<int,int> &a,const pair<int,int> &b){
        return a.first<b.first || (a.first==b.first && a.second>b.second);
    }
};
pair<int,int> a[2*N];

int num[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d",&n);
        multiset<int> s;
        int l,r;
        rep(i,0,n){
            scanf("%d %d",&l,&r);
            a[2*i]=mp(l,-(i+1));
            a[2*i+1]=mp(r,i+1);
        }
        sort(a,a+2*n);
        //rep(i,0,2*n) printf("%d %d\n",a[i].first,a[i].second);
        int cnt=0;
        rep(i,0,2*n){
            if(a[i].second<0)  s.insert(-a[i].second);
            else {
                s.erase(s.find(a[i].second));
            }
            if(s.size()==0) ++cnt;
            if(s.size()==1 && a[i].second>0 && a[i+1].second<0 &&
               a[i].first<a[i+1].first)
                ++num[(*s.begin())];
            if(s.size()==1 && a[i].second<0 && a[i+1].second>0)
                --num[(*s.begin())];
        }
        int ans=-n;
        rep(i,1,n+1)
            ans=max(ans,cnt+num[i]);
        rep(i,1,n+1) num[i]=0;
        printf("%d\n",ans);
    }
return 0;
}
