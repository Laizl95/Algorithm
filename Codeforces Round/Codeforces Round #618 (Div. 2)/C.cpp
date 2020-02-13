#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int n,m;
int a[N];
int bit[N][35],num[35];
bool cmp(int &a,int &b){
    return a>b;
}
int main(){

        scanf("%d",&n);
        rep(i,0,n){
            scanf("%d",&a[i]);
            int x=a[i];
            vector<int> v;
            while(x){
                v.pb(x&1);
                x>>=1;
            }
            rep(j,0,v.size()){
                bit[i][j]=v[j];
                if(v[j]==1) num[j]+=1;
                //printf("%d ",bit[i][j]);
            }//puts("");

        }
        int p=-1;
        per(i,0,35){
            if(num[i]==1) {p=i;break;}
        }
        if(p==-1){
            rep(i,0,n) printf("%d ",a[i]);
            puts("");
        }else{
            int x;
            rep(i,0,n){
                if(bit[i][p]==1) {x=i;break;}
            }
            printf("%d ",a[x]);
            rep(i,0,n) if(i!=x)printf("%d ",a[i]);
            puts("");
        }

return 0;
}
