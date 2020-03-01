#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define lson l,mid,i<<1
#define rson mid+1,r,i<<1|1
#define ls i<<1
#define rs i<<1|1
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int n;
int a[N],b[N];
pii c[N];
struct node{
 int l,r,cnt;
 LL v;
}s[N<<2];
void build(int l,int r,int i){
   int mid=l+r>>1;
    s[i].l=l;
    s[i].r=r;
   if(l==r){
        s[i].cnt=0;
        s[i].v=0;//²»ÊÇa[i]
        return;
   }
   build(lson);
   build(rson);
   s[i].v=0;
   s[i].cnt=0;
}
void update(int l,int r,int cnt,int x,int i){
        if(l>r) return;
       int mid=s[i].l+s[i].r>>1;
        if(l<=s[i].l && s[i].r<=r){
            s[i].cnt+=cnt;
            s[i].v+=x;
            return;
        }
        if(l<=mid)
            update(l,r,cnt,x,ls);
        if(r>mid)
            update(l,r,cnt,x,rs);
        s[i].v=s[ls].v+s[rs].v;
        s[i].cnt=s[ls].cnt+s[rs].cnt;
}
LL query(int l,int r,int i,int id){
        int mid=s[i].l+s[i].r>>1;
        if(l<=s[i].l && s[i].r<=r){
            if(id==1) return s[i].v;
            return s[i].cnt*1LL;
        }
        LL ans=0;
        if(l<=mid)
            ans+=query(l,r,ls,id);
        if(r>mid)
            ans+=query(l,r,rs,id);
        return ans;
}
bool cmp(const pii &a,const pii &b){
    return a.second<b.second;
}
int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    rep(i,1,n+1) scanf("%d",&b[i]),c[i]=mp(b[i],a[i]);
    sort(b+1,b+1+n);
    sort(c+1,c+1+n,cmp);
    int num=unique(b+1,b+1+n)-b-1;
    rep(i,1,n+1) c[i].first=lower_bound(b+1,b+1+num,c[i].first)-b;
    //rep(i,1,n+1) printf("%d %d\n",c[i].first,c[i].second);
    build(1,num,1);
    LL ans=0;
    per(i,1,n+1){
        LL dis=query(c[i].first,num,1,1)-
               c[i].second*query(c[i].first,num,1,0);
        update(c[i].first,c[i].first,1,c[i].second,1);
        //cout<<dis<<endl;
        ans+=dis;
    }
    printf("%lld\n",ans);
return 0;
}
