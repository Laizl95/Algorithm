#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define pdi pair<double,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;
int a[N],b[N];
int get(int x){
    int bit=0;
    while(x){
        x/=2;
        bit++;
    }
    return bit;
}
int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n+1) {
        scanf("%d",&a[i]);
        b[i]=get(a[i]);
        //printf("%d ",b[i]);
        a[i]^=a[i-1];
    }
    rep(i,1,n-1)
        if(b[i]==b[i+1] && b[i]==b[i+2]){
            puts("1");
            return 0;
        }
        
    int ans=n+5;
    rep(i,1,n+1){
        rep(j,i+1,n+1){
            rep(k,i,j){
                //a[i]^a[i+1]^...a[k] > a[k+1]^a[k+2]...^a[j]
                if((a[k]^a[i-1])>(a[j]^a[k])) {
                    //cout<<i<<" "<<k<<" "<<j<<endl;
                    ans=min(ans,j-i-1);
                    }
            }
        }
    }
    if(ans==n+5) ans=-1;
    cout<<ans<<endl;
    return 0;
}