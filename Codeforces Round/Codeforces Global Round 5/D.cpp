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
const int N=3*1e5+5;
typedef long long LL;
int a[N],ans[N];
struct node{
 int l,r,v;
}s[N<<2];
void build(int l,int r,int i){
   int mid=l+r>>1;
    s[i].l=l;
    s[i].r=r;
   if(l==r){
        s[i].v=a[l];
        return;
   }
   build(lson);
   build(rson);
   s[i].v=max(s[ls].v,s[rs].v);
}

int query(int l,int r,int i,int goal,int pos){
        if(s[i].l>pos) return -1;
        if(s[i].v<=goal) return -1;
        int mid=s[i].l+s[i].r>>1;
        if(s[i].l==s[i].r){
            if(goal<s[i].v) return s[i].l;
            return -1;
        }
        int ans=-1;
        if(r>mid){
            ans=max(ans,query(l,r,rs,goal,pos));
        }
        if(ans!=-1) return ans;
        if(l<=mid){
             ans=max(ans,query(l,r,ls,goal,pos));
        }
        return ans;
}
int main(){// l-r min(a[j])*2>=max(a[i])
    int n;
    while(scanf("%d",&n)!=EOF){
       rep(i,0,n) scanf("%d",&a[i+1]);
       rep(i,n,3*n) a[i+1]=a[i+1-n];
       build(1,3*n,1);
       //rep(i,1,3*n+1) printf("%d ",a[i]);puts("");
       ans[0]=1;
       rep(i,1,3*n+1){
           int x=query(1,3*n,1,2*a[i],i-1)+1;
           ans[i]=max(ans[i-1],x);
           //printf("%d ",x);
       }
     //rep(i,1,3*n+1) printf("%d ",ans[i]);
     rep(i,1,n+1){
        int l=1,r=3*n;
        while(l<=r){
            int mid=l+r>>1;
            if(ans[mid]<=i) l=mid+1;
            else r=mid-1;
        }
        if(l>3*n) printf("-1 ");
        else printf("%d ",l-i);
     }
     puts("");
    }
return 0;
}
