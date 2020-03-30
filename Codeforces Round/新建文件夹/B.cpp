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
const int N=1e5+5,inf=1e9+5;
typedef long long LL;

int a[N],b[N];
int main(){
    int n,m,k,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        int j=1;
        while(1){
            if(j*1LL*(j+1)/2<k) ++j;
            else break;
        }
        int x=j*1LL*(j+1)/2-k;
        //cout<<j<<" "<<x<<endl;
        x=j-x-1;
        per(i,0,n){
            if(i!=x && i!=j) printf("a");
            else cout<<"b";
        }
        cout<<endl;
    }
    return 0;
}
