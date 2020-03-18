#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n;
int a[N];
map<int,int> mp;
int solve(int num1,int num2){
    if(num1==num2) return 0;
    int x=num1-num2,goal,ans=2*n;
    if(mp.count(-x)){
        ans=min(ans,mp[-x]-(n+1)+1);
    }
    per(i,1,n+1){
        if(a[i]==1) --x;
        else ++x;
        if(x==0) ans=min(ans,n-i+1);
        if(mp.count(-x)){
            ans=min(ans,mp[-x]-i+1);
        }
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int num1=0,num2=0;
        rep(i,1,2*n+1){
            scanf("%d",&a[i]);
            if(a[i]==1) ++num1;
            else ++num2;
        }
        int x=0;
        mp.clear();
        rep(i,n+1,2*n+1){
            if(a[i]==1){
                --x;
                if(!mp.count(x)) mp[x]=i;
            }else{
                ++x;
                if(!mp.count(x)) mp[x]=i;
            }
           // cout<<x<<endl;
        }
        int ans=solve(num1,num2);
        printf("%d\n",ans);
    }
return 0;
}
