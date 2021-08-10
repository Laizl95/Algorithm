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
const int N=2e5+5,inf=1e9+5,mod=998244353;
typedef long long LL;
int n,m,k;


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a<=b) printf("%d\n",b);
        else{
            if(c<=d){puts("-1");continue;}
            int x=(a-b)/(c-d)+((a-b)%(c-d)!=0);
            cout<<x*1LL*c+b<<endl;
        }
    }
return 0;
}
