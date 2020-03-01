#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int n,m;
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int minx=1e9+5,maxx=-1,ok=0;
        rep(i,0,n){
            scanf("%d",&a[i]);
            if(a[i]==-1) continue;
            ok=1;
        }
        if(!ok){printf("0 0\n");continue;}
        rep(i,0,n){
            if(a[i]!=-1){
                if(i-1>=0 && a[i-1]==-1){
                    minx=min(a[i],minx);
                    maxx=max(a[i],maxx);
                }
                if(i+1<n && a[i+1]==-1){
                    minx=min(a[i],minx);
                    maxx=max(a[i],maxx);
                }
            }
        }
        int r=-1,l=1e9+5;
        rep(i,0,n-1){
            int x=a[i],y=a[i+1];
            if(x==-1) x=minx;
            if(y==-1) y=minx;
            r=max(abs(x-y),r);
            l=min(abs(x-y),l);
        }
        //cout<<r<<" "<<l<<" "<<minx<<endl;
        int x=(r+l)/2;
         minx+=x; r=-1;
         rep(i,0,n-1){
             if(a[i]==-1) a[i]=minx;
             if(a[i+1]==-1) a[i+1]=minx;
             r=max(r,abs(a[i]-a[i+1]));
        }
        cout<<r<<" "<<minx<<endl;
    }
return 0;
}
