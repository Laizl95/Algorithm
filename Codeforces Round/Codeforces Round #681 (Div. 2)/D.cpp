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
int n;
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",&a[i]);
        int ok=1,l=a[0],r=0;//最多砍l棵 至少砍r棵
        rep(i,0,n){
            if(l+r>=a[i]){
                if(r>a[i]) ok=0;
                else{
                    l=a[i]-r;
                }
            }else{
                r=a[i]-l;
            }
        }    
        puts(ok?"YES":"NO");
    }
    return 0;
}