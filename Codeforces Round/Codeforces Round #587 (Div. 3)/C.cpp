#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
int x[6],y[6];
map<int,int> X,Y;
int vis[50][50];
int main(){
    int n;
    while(scanf("%d %d %d %d",&x[0],&y[0],&x[1],&y[1])!=EOF){
            ms(vis,0);
            X.clear();Y.clear();
       rep(i,2,6) scanf("%d %d",&x[i],&y[i]);
       int a[6],b[6];
       rep(i,0,6) a[i]=x[i],b[i]=y[i];
       sort(a,a+6);sort(b,b+6);
       int tot1=1,tot2=1;
       rep(i,0,6){
        if(X.count(a[i])==0) X[a[i]]=tot1++;
        if(Y.count(b[i])==0) Y[b[i]]=tot2++;
       }
        rep(i,X[x[2]],X[x[3]]){
            rep(j,Y[y[2]],Y[y[3]])
              vis[i][j]=1;
        }
        rep(i,X[x[4]],X[x[5]]){
            rep(j,Y[y[4]],Y[y[5]])
              vis[i][j]=1;
        }
        int ok=0;
        rep(i,X[x[0]],X[x[1]]){
            rep(j,Y[y[0]],Y[y[1]])
              if(vis[i][j]==0) ok=1;
        }
        puts(ok?"YES":"NO");
    }
return 0;
}
