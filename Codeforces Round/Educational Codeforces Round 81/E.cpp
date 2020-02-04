#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define lson l,mid,i<<1
#define rson mid+1,r,i<<1|1
#define ls i<<1
#define rs i<<1|1
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int a[N],pos[N],n;
LL b[N];
struct node{
 int l,r;
 LL mark,v;
}s[N<<2];
void push_down(int i){
  if(s[i].mark){
        s[ls].mark+=s[i].mark;
        s[rs].mark+=s[i].mark;
        s[ls].v+=s[i].mark;
        s[rs].v+=s[i].mark;
        s[i].mark=0;
  }
}
void build(int l,int r,int i){
   int mid=l+r>>1;
    s[i].l=l;
    s[i].r=r;
   if(l==r){
        s[i].mark=0;
        s[i].v=b[l];

        return;
   }
   build(lson);
   build(rson);
   s[i].v=min(s[ls].v,s[rs].v);
   s[i].mark=0;
}
void update(int l,int r,int x,int i){
        if(l>r) return;
       int mid=s[i].l+s[i].r>>1;
        if(l<=s[i].l && s[i].r<=r){
            s[i].mark+=x;
            s[i].v+=x;
            return;
        }
        push_down(i);
        if(l<=mid)
            update(l,r,x,ls);
        if(r>mid)
            update(l,r,x,rs);
    s[i].v=min(s[ls].v,s[rs].v);
}
LL query(int l,int r,int i){
        int mid=s[i].l+s[i].r>>1;
        if(l<=s[i].l && s[i].r<=r){
            return s[i].v;
        }
        push_down(i);
        LL ans=1e17;
        if(l<=mid)
            ans=min(ans,query(l,r,ls));
        if(r>mid)
            ans=min(ans,query(l,r,rs));
        return ans;
}
int main(){
    scanf("%d",&n);
    int x;
    rep(i,1,n+1){
        scanf("%d",&x);
        pos[x]=i;
    }
    rep(i,1,n+1){
        scanf("%lld",&a[i]);
        b[i]=a[i]+b[i-1];
    }
    build(1,n-1,1);
    LL ans=a[n];

    rep(i,1,n+1){
        ans=min(ans,query(1,n-1,1));
       // cout<<query(1,1,1)<<endl;
         //cout<<query(2,2,1)<<endl;
         //cout<<"ss"<<pos[i]<<" "<<a[pos[i]]<<endl;
        update(pos[i],n-1,-a[pos[i]],1);
        update(1,pos[i]-1,a[pos[i]],1);
    }
    printf("%lld\n",ans);
return 0;
}
