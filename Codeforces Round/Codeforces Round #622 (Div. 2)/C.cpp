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
const int N=5e5+5,inf=1e9+5;
typedef long long LL;

int n,m;
int a[N],b[N];
LL sum_l[N],sum_r[N];
struct node{
 int l,r,v,p;
}s[N<<2];
void build(int l,int r,int i){
   int mid=l+r>>1;
    s[i].l=l;
    s[i].r=r;
   if(l==r){
        s[i].v=a[l];
        s[i].p=l;
        return;
   }
   build(lson);
   build(rson);
   s[i].v=min(s[ls].v,s[rs].v);
   if(s[ls].v<s[rs].v) s[i].p=s[ls].p;
   else s[i].p=s[rs].p;
}
int query(int l,int r,int i,int x,int dir){
        if(l>r || s[i].l>r || s[i].r<l) return -1;
        int mid=s[i].l+s[i].r>>1;
        if(s[i].v>x) return -1;
        if(s[i].l==s[i].r){
            return s[i].p;
        }
        int ans=-1;
        if(!dir){
            if(l<=mid)
                ans=query(l,r,ls,x,dir);
            if(ans!=-1) return ans;
            if(r>mid)
                ans=query(l,r,rs,x,dir);
        }else{
            if(r>mid)
                ans=query(l,r,rs,x,dir);
            if(ans!=-1) return ans;
            if(l<=mid)
                ans=query(l,r,ls,x,dir);
        }
        return ans;
}
int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    build(1,n,1);
    rep(i,1,n+1){
        if(a[i]>=a[i-1]) sum_l[i]=sum_l[i-1]+a[i];
        else{
           int p=query(1,i-1,1,a[i],1);
           if(p==-1) p=0;
           sum_l[i]=sum_l[p]+(i-p)*1LL*a[i];
        }
    }
    per(i,1,n+1){
        if(a[i]>=a[i+1]) sum_r[i]=sum_r[i+1]+a[i];
        else{
            int p=query(i+1,n,1,a[i],0);
            if(p==-1) p=n+1;
            sum_r[i]=sum_r[p]+(p-i)*1LL*a[i];
        }
    }
    LL ans=0;int p=1;
    rep(i,1,n+1){
        LL g=sum_l[i]+sum_r[i]-a[i];
        if(g>ans) ans=g,p=i;
    }
    //cout<<ans<<" "<<p<<endl;
    b[p]=a[p];
    per(i,1,p)
        if(a[i]>b[i+1]) b[i]=b[i+1];
        else b[i]=a[i];
    rep(i,p+1,n+1)
        if(a[i]>b[i-1]) b[i]=b[i-1];
        else b[i]=a[i];
    rep(i,1,n+1) printf("%d ",b[i]);puts("");
return 0;
}
