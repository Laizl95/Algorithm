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
const int N=2e5+5;
typedef long long LL;
int maxn,n,k;
struct node{
    int l,r,id;
    node(){}
    node(int _l,int _r,int _id){l=_l;r=_r;id=_id;}
    bool operator < (const node &a)const{
        return r<a.r || (r==a.r && l>a.l);
    }
}a[N];
struct E{
 int l,r,mark,v;
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
        s[i].v=0;
        return;
   }
   build(lson);
   build(rson);
   s[i].v=max(s[ls].v,s[rs].v);
   s[i].mark=0;
}
void update(int l,int r,int x,int i){
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
    s[i].v=max(s[ls].v,s[rs].v);
}
int query(int l,int r,int i){
        int mid=s[i].l+s[i].r>>1;
        if(s[i].v<k) return 1;
        if(l<=s[i].l && s[i].r<=r){
            return s[i].v<k;
        }
        push_down(i);
        int t1=1,t2=1;
        if(l<=mid)
            t1=query(l,r,ls);
        if(!t1) return 0;
        if(r>mid)
            t2=query(l,r,rs);
        return t2;
}
int main(){

    scanf("%d %d",&n,&k);
    rep(i,0,n){
        scanf("%d %d",&a[i].l,&a[i].r);
        a[i].id=i+1;
        maxn=max(max(a[i].l,a[i].r),maxn);
    }
    sort(a,a+n);
    build(1,maxn,1);
    vector<int> ans;
    rep(i,0,n){
        int ok=query(a[i].l,a[i].r,1);

        if(ok) update(a[i].l,a[i].r,1,1);
        else{
            ans.pb(a[i].id);
        }
    }
    int t=ans.size();
    printf("%d\n",t);
    rep(i,0,t) printf("%d ",ans[i]);
    puts("");
return 0;
}
