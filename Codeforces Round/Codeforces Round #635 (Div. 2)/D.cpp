#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m,k;
int a[N],b[N],c[N];
LL get(int x,int y,int z){
    return (x-y)*1LL*(x-y)+(y-z)*1LL*(y-z)+(z-x)*1LL*(z-x);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        rep(i,0,n) scanf("%d",&a[i+1]);
        rep(i,0,m) scanf("%d",&b[i+1]);
        rep(i,0,k) scanf("%d",&c[i+1]);
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        sort(c+1,c+k+1);

        LL ans=-1;
        rep(i,1,n+1){
           // cout<<a[i]<<endl;
            int x1=lower_bound(b+1,b+m+1,a[i])-b;
            int y1=lower_bound(c+1,c+k+1,a[i])-c;

            if(x1>m) --x1;
            if(y1>k) --y1;
            //cout<<x1<<" "<<y1<<endl;
            vector<int> v1,v2;
            v1.pb(x1);
            if(x1-1>0) v1.pb(x1-1);
            v2.pb(y1);
            if(y1-1>0) v2.pb(y1-1);
            for(auto x:v1){
                for(auto y:v2)
                   if(ans==-1) ans=get(a[i],b[x],c[y]);
                   else ans=min(ans,get(a[i],b[x],c[y]));
            }
        }//cout<<ans<<endl;
         rep(i,1,m+1){
            int x1=lower_bound(a+1,a+n+1,b[i])-a;
            int y1=lower_bound(c+1,c+k+1,b[i])-c;
            if(x1>n) --x1;
            if(y1>k) --y1;
            //cout<<x1<<" "<<y1<<endl;
            vector<int> v1,v2;
            v1.pb(x1);
            if(x1-1>0) v1.pb(x1-1);
            v2.pb(y1);
            if(y1-1>0) v2.pb(y1-1);
            for(auto x:v1){
                for(auto y:v2)
                   if(ans==-1) ans=get(b[i],a[x],c[y]);
                   else ans=min(ans,get(b[i],a[x],c[y]));
            }
        }
        //cout<<ans<<endl;
         rep(i,1,k+1){
            int x1=lower_bound(a+1,a+n+1,c[i])-a;
            int y1=lower_bound(b+1,b+m+1,c[i])-b;
            if(x1>n) --x1;
            if(y1>m) --y1;
            //cout<<x1<<" "<<y1<<endl;
            vector<int> v1,v2;
            v1.pb(x1);
            if(x1-1>0) v1.pb(x1-1);
            v2.pb(y1);
            if(y1-1>0) v2.pb(y1-1);
            for(auto x:v1){
                for(auto y:v2)
                   if(ans==-1) ans=get(c[i],a[x],b[y]);
                   else ans=min(ans,get(c[i],a[x],b[y]));
            }
        }
        cout<<ans<<endl;
    }
return 0;
}
