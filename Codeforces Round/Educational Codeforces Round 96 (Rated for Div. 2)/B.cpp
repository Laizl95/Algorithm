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
const int N=2e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;
int a[N];
int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        rep(i,0,n) scanf("%d",&a[i]);
        sort(a,a+n);
        int p=n-2;
        LL num=a[n-1]*1LL;
        while(k--){
            num+=a[p];
            a[p]=0;
            if(--p<0) break;
        }
        cout<<num<<endl;
    }
return 0;
}
