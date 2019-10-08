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
const int N=2*1e5+5;
typedef long long LL;
LL inf=5*1LL*1e10;
int a[N];
int n,k;
struct node{
 int l,r;
 LL mark,v;
}s[N<<2];
void push_down(int i){
  if(s[i].mark){
        s[ls].mark=min(s[ls].mark,s[i].mark);
        s[rs].mark=min(s[rs].mark,s[i].mark);
        s[ls].v=min(s[ls].v,s[i].mark);
        s[rs].v=min(s[rs].v,s[i].mark);
        s[i].mark=inf;
  }
}
void build(int l,int r,int i){
   int mid=l+r>>1;
    s[i].l=l;
    s[i].r=r;
   if(l==r){
        s[i].mark=inf;
        s[i].v=inf;
        return;
   }
   build(lson);
   build(rson);
   s[i].v=max(s[ls].v,s[rs].v);
   s[i].mark=inf;
}
void update(int l,int r,LL x,int i){
       int mid=s[i].l+s[i].r>>1;
        if(l<=s[i].l && s[i].r<=r){
            s[i].mark=min(s[i].mark,x);
            s[i].v=min(s[i].v,x);
            return;
        }
        push_down(i);
        if(l<=mid)
            update(l,r,x,ls);
        if(r>mid)
            update(l,r,x,rs);
    s[i].v=max(s[ls].v,s[rs].v);
}
LL query(int l,int r,int i){
        int mid=s[i].l+s[i].r>>1;
        if(l<=s[i].l && s[i].r<=r){
            return s[i].v;
        }
        push_down(i);
        LL ans=0;
        if(l<=mid)
            ans+=query(l,r,ls);
        if(r>mid)
            ans+=query(l,r,rs);
        return ans;
}
int main(){
        LL dp[105];
       while(scanf("%d %d",&n,&k)!=EOF){
            char c;
            rep(i,1,n+1){
                scanf(" %c",&c);
                a[i]=c=='1';
            }
            /*rep(i,1,n+1) dp[i]=inf;dp[0]=0;
            rep(i,1,n+1){
                dp[i]=min(dp[i-1]+i,dp[i]);
                if(a[i]==1){
                    LL x=dp[max(i-k,1)-1]+i;
                    dp[i]=min(x,dp[i]);
                    rep(j,max(i-k,1),min(i+k,n)+1)
                        dp[j]=min(dp[j],x);
                }
            }*/
            build(1,n,1);
            rep(i,1,n+1){
                  LL t1=query(i-1,i-1,1)+i;
                  update(i,i,t1,1);
                  if(a[i]==1){
                    t1=query(max(i-k,1)-1,max(i-k,1)-1,1)+i;
                    update(i,i,t1,1);
                    update(max(i-k,1),min(i+k,n),t1,1);
                  }
            }
            printf("%lld\n",query(n,n,1));
       }
return 0;
}
