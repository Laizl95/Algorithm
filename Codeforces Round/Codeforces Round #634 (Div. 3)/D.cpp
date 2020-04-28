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
int n,m;
char a[15][15];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        rep(i,0,9) scanf("%s",a[i]);

        a[0][6]=a[0][5];
        a[1][1]=a[1][0];
        a[2][5]=a[2][8];
        a[3][8]=a[2][8];
        a[4][2]=a[4][0];
        a[5][4]=a[5][7];
        a[6][7]=a[0][7];
        a[7][0]=a[4][0];
        a[8][3]=a[8][2];
        rep(i,0,9) puts(a[i]);

    }
return 0;
}
