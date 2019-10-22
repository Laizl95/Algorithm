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
char a[N];
int vis[26];
int n,k;
struct node{
 int l,r;
 int v[26];
}s[N<<2];

void build(int l,int r,int i){
   int mid=l+r>>1;
    s[i].l=l;
    s[i].r=r;
   if(l==r){
        ms(s[i].v,0);
        s[i].v[a[l]-'a']+=1;
        return;
   }
   build(lson);
   build(rson);
   rep(j,0,26) s[i].v[j]=s[ls].v[j]+s[rs].v[j];
}
void update(int l,int r,int pre,int x,int i){
       int mid=s[i].l+s[i].r>>1;
       //cout<<s[i].l<<" "<<s[i].r<<" "<<x<<endl;
        if(l<=s[i].l && s[i].r<=r){
            s[i].v[pre]-=1;
            s[i].v[x]+=1;
            // cout<<s[i].v<<endl;
            return;
        }
        if(l<=mid)
            update(l,r,pre,x,ls);
        if(r>mid)
            update(l,r,pre,x,rs);
    rep(j,0,26) s[i].v[j]=s[ls].v[j]+s[rs].v[j];
}
int query(int l,int r,int i){
        int mid=s[i].l+s[i].r>>1;
        if(l<=s[i].l && s[i].r<=r){
            int t=0;
         rep(j,0,26) if(s[i].v[j]!=0 && !vis[j]) vis[j]=1,t+=1;
            return t;
        }
        int ans=0;
        if(l<=mid)
            ans+=query(l,r,ls);
        if(r>mid)
            ans+=query(l,r,rs);
        return ans;
}
int main(){
       while(scanf("%s",a+1)!=EOF){
            int t;
            build(1,strlen(a+1),1);
            scanf("%d",&t);
            while(t--){
                int id,l,r;char c;
                scanf("%d",&id);
                if(id==1){
                    scanf("%d %c",&l,&c);
                    update(l,l,a[l]-'a',c-'a',1);
                    a[l]=c;
                }else{
                    scanf("%d %d",&l,&r);
                    ms(vis,0);
                    int ans=query(l,r,1);
                    cout<<ans<<endl;
                }
            }
       }
return 0;
}
