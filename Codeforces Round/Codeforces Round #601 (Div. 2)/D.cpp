#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=105+5,inf=1e9+5;
typedef long long LL;
//48
char mat[N][N];
int ans[N][N];
char s[N]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
int main(){
    int t,n,m,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        rep(i,0,n) scanf("%s",mat[i]);
        int num=0;
        rep(i,0,n) rep(j,0,m) if(mat[i][j]=='R') num++;
        int need=num/k,tot=num%k,now=0,id=0;
        if(tot) ++need;
        //cout<<need<<" "<<tot<<endl;
        rep(i,0,n){
           if(!(i&1)){
            rep(j,0,m){
                ans[i][j]=id;
                if(mat[i][j]=='R')   now++;
                if(now==need){
                    now=0;
                    ++id;
                    id=min(id,k-1);
                    if(--tot==0) --need;
                }
            }
          }
          else{
             per(j,0,m){
                ans[i][j]=id;
                if(mat[i][j]=='R')   now++;
                if(now==need){
                    now=0;
                    ++id;
                    id=min(id,k-1);
                    if(--tot==0) --need;
                }
            }
          }
        }
        rep(i,0,n){rep(j,0,m) printf("%c",s[ans[i][j]]);puts("");}
    }
return 0;
}
