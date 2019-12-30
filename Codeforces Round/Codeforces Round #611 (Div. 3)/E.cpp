#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,mod=1e9+7;
typedef long long LL;

int a[N],c[N];
int main(){
    int n,x,ans1=0,ans2=0,ok=1;
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",&x);
        a[x]+=1;
    }
    rep(i,1,n+1){
        if(a[i]>=3){
            c[i-1]+=1;
            c[i+1]+=1;
            c[i]-=2;
        }else if(a[i]>0){
            if(a[i-1]+c[i-1]<=0) c[i-1]+=1,c[i]-=1;
            else if(c[i]>0 || a[i]>1) c[i+1]+=1,c[i]-=1;
        }
    }
    rep(i,0,n+2) if(a[i]+c[i]>0) ans1+=1;
    int i=1;
    while(i<=n){
        if(a[i]==0){ok=1;i+=1;continue;}
        if(ok){
            a[i+1]+=a[i];a[i]=0;
            ok=0;
            i+=2;
        }
        else if(!ok){
             a[i-1]+=a[i];a[i]=0;
             ok=1;
             i+=1;
        }
    //rep(i,0,n+2) printf("%d ",a[i]);puts("");
    }
     rep(i,0,n+2) if(a[i]) ans2+=1;
     cout<<ans2<<" "<<ans1<<endl;
return 0;
}
