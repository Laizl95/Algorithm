#pragma GCC optimize(2)
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
int n,m,k;
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int x,num1=0,num2=0;
        rep(i,0,n){
            scanf("%d",&x);
            if(x&1) num1+=1;
            if(!(x&1)) num2+=1;
        }
        if(num1&1) puts("YES");
        else{
            if(num2>0 && num1>0) puts("YES");
            else puts("NO");
        }

    }
return 0;
}
