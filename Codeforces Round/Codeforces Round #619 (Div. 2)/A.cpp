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
char a[N],b[N],c[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s %s %s",a,b,c);
        int len=strlen(a),ok=1;

        rep(i,0,len){
            if(b[i]==c[i]) swap(a[i],c[i]);
            else if(a[i]==c[i]) swap(b[i],c[i]);
            else ok=0;
        }
        if(ok) puts("YES");
        else puts("NO");

    }
return 0;
}
