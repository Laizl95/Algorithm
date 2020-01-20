#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int mat[5][N];
int main(){
    int t,q,m,n;
    scanf("%d",&t);
    scanf("%d",&q);
    int dir[6][2]={1,0,-1,0,-1,-1,1,-1,-1,1,1,1};
    int tot=0;
    while(q--){
        scanf("%d %d",&n,&m);
        if(mat[n][m]==0){
                rep(j,0,6){
                    int x=n+dir[j][0],y=m+dir[j][1];
                    //cout<<x<<" "<<y<<" "<<mat[x][y]<<endl;
                    if(mat[x][y]==1) ++tot;
                }
                mat[n][m]=1;
        }else{
            rep(j,0,6){
                    int x=n+dir[j][0],y=m+dir[j][1];
                    if(mat[x][y]==1) --tot;
                }
                mat[n][m]=0;
        }
       // cout<<"tot:"<<tot<<endl;
        if(tot) puts("No");
        else puts("Yes");
    }

return 0;
}
