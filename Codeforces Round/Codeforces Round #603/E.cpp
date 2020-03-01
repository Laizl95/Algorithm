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
const int N=1e6+5,inf=1e9+5;
typedef long long LL;
char a[N];
int n,k;
struct node{
 int l,r,v,mn,mx;
}s[N<<2];
void build(int l,int r,int i){
   int mid=l+r>>1;
    s[i].l=l;
    s[i].r=r;
   if(l==r){
        s[i].v=0;s[i].mn=0;s[i].mx=0;
        return;
   }
   build(lson);
   build(rson);
   s[i].v=0;s[i].mn=0;s[i].mx=0;
}
void update(int l,int r,int x,int i){
        if(l>r) return;
       int mid=s[i].l+s[i].r>>1;
        if(l<=s[i].l && s[i].r<=r){
            s[i].v=x;
            s[i].mn=x;
            s[i].mx=x;
            return;
        }
        if(l<=mid)
            update(l,r,x,ls);
        if(r>mid)
            update(l,r,x,rs);
    s[i].v=s[ls].v+s[rs].v;
    s[i].mn=min(s[ls].mn,s[ls].v+s[rs].mn);
    s[i].mx=max(s[ls].mx,s[ls].v+s[rs].mx);
}

int main(){

    scanf("%d %s",&n,a+1);
    int r=1,now=1;
    rep(i,1,n+1)
        if(a[i]=='R') now+=1,r=max(now,r);
        else if(a[i]=='L') now-=1,now=max(1,now);
    //cout<<r<<endl;
    build(1,r,1);
    now=1;
    rep(i,1,n+1){
        if(a[i]=='('){
           update(now,now,1,1);
        }else if(a[i]==')'){
           update(now,now,-1,1);
        }else
            if(a[i]=='R') now+=1;
        else
            if(a[i]=='L') now-=1,now=max(1,now);
        else update(now,now,0,1);
        if(s[1].v==0 && s[1].mn>=0)
            printf("%d ",s[1].mx);
        else printf("-1 ");
    }puts("");
return 0;
}
