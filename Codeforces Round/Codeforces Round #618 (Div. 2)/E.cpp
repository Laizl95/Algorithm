#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=1e6+5,inf=1e9+5;
typedef long long LL;
int a[N];

pair<double,int> b[N];
int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n+1){
        scanf("%d",&a[i]);
    }
    int p=0;
    rep(i,1,n+1){
        b[++p]=mp(a[i]*1.0,1);
        while(p>=2){
            if(b[p].first>b[p-1].first) break;
            else{
                int num=b[p].second+b[p-1].second;
                b[p-1]=mp((b[p].first*b[p].second+b[p-1].first*b[p-1].second)/num,num);
                p-=1;
            }
        }
    }
    rep(i,1,p+1){
        rep(j,0,b[i].second)
            printf("%.9f\n",b[i].first);
    }
return 0;
}
