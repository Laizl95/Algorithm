#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define lson l,mid,i<<1
#define rson mid+1,r,i<<1|1
#define ls i<<1
#define rs i<<1|1
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
}a[N];
struct E{
 int l,r,v,id;
}s[N<<2];
void build(int l,int r,int i){
   int mid=l+r>>1;
    s[i].l=l;
    s[i].r=r;
   if(l==r){
        s[i].id=inf;
        s[i].v=inf;
        return;
   }
   build(lson);
   build(rson);
   s[i].v=inf;
   s[i].id=inf;
}
void update(int l,int r,node x,int i){
       int mid=s[i].l+s[i].r>>1;
        if(l<=s[i].l && s[i].r<=r){
            s[i].id=x.id;
            s[i].v=x.v;
            return;
        }
        if(l<=mid)
            update(l,r,x,ls);
        if(r>mid)
            update(l,r,x,rs);
    if(s[ls].id<s[rs].id) s[i].v=s[ls].v;
    else s[i].v=s[rs].v;
    s[i].id=min(s[ls].id,s[rs].id);
}
int query(int l,int r,int k,int i){
        int mid=s[i].l+s[i].r>>1;
        if(s[i].id>k) return 0;
        if(l<=s[i].l && s[i].r<=r){
            return s[i].v;
        }

        int ans=0;

        if(l<=mid)
            ans=query(l,r,k,ls);
        if(r>mid && ans==0)
            ans=query(l,r,k,rs);
        return ans;
}
int main(){

    int n,q,m,k,x;
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",&x);
        a[i]=node(x,i);
    }
    sort(a,a+n);
    build(1,n,1);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&m,&k);
        build(1,m,1);
        int ans=query(1,m,k,1);
        printf("ans%d\n",ans);
    }
return 0;
}
