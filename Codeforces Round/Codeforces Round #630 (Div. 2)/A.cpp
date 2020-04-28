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

int cx[3],cy[3];
int main(){
    int t,a,b,c,d;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        rep(i,0,3) scanf("%d %d",&cx[i],&cy[i]);
        int x=b-a,y=d-c,ok=0;
        if(x+cx[0]<=cx[2] && x+cx[0]>=cx[1] &&
            y+cy[0]<=cy[2] && y+cy[0]>=cy[1]){
                int x1=0,x2=0;
            if((cx[1]==cx[2] && a+b==0) || cx[1]!=cx[2]) x1=1;
            if(((cy[1]==cy[2]) && c+d==0) || cy[1]!=cy[2]) x2=1;
            if(x1 && x2) ok=1;
        }
            puts(ok?"Yes":"No");
    }
return 0;
}
