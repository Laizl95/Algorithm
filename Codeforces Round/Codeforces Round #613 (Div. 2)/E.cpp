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
int l[N],r[N],a[2*N],n;
struct node{
 int l,r;
 int cnt,mark,cov;
}s[N*10];

void build(int l,int r,int i){
   int mid=l+r>>1;
   s[i].l=l;s[i].r=r;
   if(l==r){
        s[i].mark=0;s[i].cnt=0;s[i].cov=0;
        return;
   }
   build(lson);
   build(rson);
   s[i].cnt=0;
   s[i].mark=0;
   s[i].cov=0;
}
void update(int l,int r,int x,int i){
       int mid=s[i].l+s[i].r>>1;
        if(l<=s[i].l && s[i].r<=r){
             s[i].cov+=x;
            if(s[i].cov>0){
                s[i].cnt=1;
            }else{
                if(s[i].l!=s[i].r)
                    s[i].cnt=s[ls].cnt+s[rs].cnt-(s[i].mark==0?0:1);
                else s[i].cnt=0;
            }
            return;
        }

        if(l<=mid)
            update(l,r,x,ls);
        if(r>mid)
            update(l,r,x,rs);
    if(l<=mid && mid<r) s[i].mark+=x;
    if(s[i].cov) s[i].cnt=1;
    else s[i].cnt=s[ls].cnt+s[rs].cnt-(s[i].mark==0?0:1);
    //s[i].cov=min(s[ls].cov,s[rs].cov);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n){
            scanf("%d %d",&l[i],&r[i]);
            a[2*i]=l[i];
            a[2*i+1]=r[i];
        }
        sort(a,a+2*n);
        int num=unique(a,a+2*n)-a;
        build(1,num,1);
        rep(i,0,n){
            l[i]=lower_bound(a,a+num,l[i])-a+1;
            r[i]=lower_bound(a,a+num,r[i])-a+1;
            //cout<<l[i]<<" "<<r[i]<<endl;
            update(l[i],r[i],1,1);
        }

        int ans=0;
        rep(i,0,n){
            update(l[i],r[i],-1,1);
            ans=max(ans,s[1].cnt);
            update(l[i],r[i],1,1);
        }
        printf("%d\n",ans);
    }
return 0;
}
