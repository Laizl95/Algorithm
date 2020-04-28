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
const int N=5e2+5,inf=1e9+5;
typedef long long LL;
int n,m;
int a[N][N];
int main(){
    int k;
    scanf("%d",&k);
    vector<int> v;
    int x=k,bit=0;
    while(x){
        v.pb(x%2);
        x/=2;
        bit++;
    }
    int y=(1<<bit)|k,z=1<<bit;
    printf("3 3\n");
    rep(i,0,3) rep(j,0,3) a[i][j]=y;
    a[2][2]=k;
    a[0][2]=z;
    a[2][0]=z;
    a[1][2]=y;
    a[2][1]=y;
    a[1][1]=k;
    rep(i,0,3) {rep(j,0,3) printf("%d ",a[i][j]);puts("");}
return 0;
}
