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
int ans[N],b[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL l,r;
        scanf("%d %lld %lld",&n,&l,&r);
        LL x=(n-1)*1LL*2,sum=x;int p=1;
         if(x*n-n*1LL*(n-1)+1==l){
            cout<<"1"<<endl;
            continue;
        }
        while(sum<l){
            ++p;
            sum=x*p-p*1LL*(p-1);
           // cout<<sum<<endl;
            //if(p>90) break;

        }
        LL y=sum-l+1;
        int x2=n-(y-1)/2,x1,j=r-l+1;

        if(y&1){
            x1=x2,x2=p;
            rep(i,0,j){
                if(i%2==0){
                    ans[i]=x1;
                    ++x1;
                    if(x1>n){
                        ++x2;
                        if(x2==n) x2=1;
                        x1=x2+1;
                    }
                }
                else ans[i]=x2;
            }
        }
        else{
            x1=p;
            rep(i,0,j){
                if(i%2==0){
                    ans[i]=x1;
                }else{
                    ans[i]=x2;
                    ++x2;
                    if(x2>n){
                        ++x1;
                        if(x1==n) x1=1;
                        x2=x1+1;
                    }
                }
            }
        }
        rep(i,0,j) printf("%d ",ans[i]);
        puts("");

    }
return 0;
}
