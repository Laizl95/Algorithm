#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e3+5,mod=1e9+7;
typedef long long LL;
int mat[N][N];
int a[N],b[N];
int main(){
    int h,w;
    while(scanf("%d %d",&h,&w)!=EOF){
          ms(mat,0);
          rep(i,0,h){
            scanf("%d",&a[i]);
            if(a[i]==0) mat[i][0]=-1;
            rep(j,0,a[i]) mat[i][j]=1;
          }
          rep(i,0,w){
            scanf("%d",&b[i]);
            if(b[i]==0) mat[0][i]=-1;
            rep(j,0,b[i]) mat[j][i]=1;
          }
            int ok=1;
          rep(i,0,h){
              int sum=0;
              rep(j,0,w)
                if(mat[i][j]==1) sum+=1;
                else break;
                if(sum!=a[i]) ok=0;
          }
           rep(j,0,w){
              int sum=0;
              rep(i,0,h)
                if(mat[i][j]==1) sum+=1;
                else break;
                if(sum!=b[j]) ok=0;
          }
          if(!ok) printf("%d\n",0);
          else{
            int ans=0;
            rep(i,0,h) rep(j,0,w){
                if(mat[i][j]==0 && j>a[i] && i>b[j]) ans+=1;
            }
                LL g=1;
            rep(i,0,ans) g=g*1LL*2%mod;
            printf("%lld\n",g);
        }

    }
return 0;
}
