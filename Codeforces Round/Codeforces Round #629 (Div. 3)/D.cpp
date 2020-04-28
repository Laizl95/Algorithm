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
int a[N],b[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",&a[i]);

        int vis[3]={0};
        b[0]=0;
        vis[0]=1;
        int ok=-1;
        rep(i,1,n){
            if(a[i]==a[i-1]) b[i]=b[i-1],ok=i;
            else b[i]=1-b[i-1];
            vis[b[i]]=1;
        }
        if(a[n-1]!=a[0] && b[n-1]==b[0]){
              if(ok==-1)  b[n-1]=2,vis[2]=1;
              else{
                 rep(j,ok,n) b[j]=1-b[j],vis[b[j]]=1;
              }
        }
        int num=0;
        rep(i,0,3) num+=(vis[i]==1);
        cout<<num<<endl;
        rep(i,0,n) printf("%d ",b[i]+1);puts("");

    }
return 0;
}
