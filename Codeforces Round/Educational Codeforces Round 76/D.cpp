#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
//13:30
int a[N],b[N];
struct node{
    int p,s;
    bool operator < (const node &a) const{
        return s<a.s || (s==a.s && p<a.p);
    }
}c[N];
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",&a[i]);
        scanf("%d",&m);
        rep(i,0,m) scanf("%d %d",&c[i].p,&c[i].s);
        sort(c,c+m);
        rep(i,0,n+2) b[i]=0;
        per(i,0,m){
            b[c[i].s]=max(b[c[i].s],c[i].p);

        }
        per(i,1,n+1){
            b[i]=max(b[i],b[i+1]);
        }
        //rep(i,1,n+1) printf("%d ",b[i]); cout<<endl;
        int p=0,pre=-1,d=1,ans=0;
        while(p<n){
           int x=max(a[p],pre);
           pre=x;

           if(d==1) ans+=1;
           if(x<=b[d]) d+=1,p+=1;
           else{
                if(d==1) break;
                d=1,pre=-1;
           }
        }
        if(p<n) puts("-1");
        else printf("%d\n",ans);
    }
return 0;
}
