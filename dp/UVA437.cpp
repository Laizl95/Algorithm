#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=205;
int dp[N];
struct node{
    int x,y,z;
    node(){}
    node(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
    bool operator < (const node &a) const{
     return x>a.x || (x==a.x && y>a.y);
    }
}s[N];

int main(){
    int n,cas=1;
    while(scanf("%d",&n)!=EOF && n){
            int a,b,c;
        rep(i,0,n){
            scanf("%d %d %d",&a,&b,&c);
            s[3*i+0]=node(min(a,b),max(a,b),c);
            s[3*i+1]=node(min(a,c),max(a,c),b);
            s[3*i+2]=node(min(b,c),max(b,c),a);
        }
        sort(s,s+3*n);
        //rep(i,0,3*n) printf("%d %d %d\n",s[i].x,s[i].y,s[i].z);
        rep(i,0,3*n){
            dp[i]=s[i].z;
            rep(j,0,3*n)
            if(s[j].x>s[i].x && s[j].y>s[i].y) dp[i]=max(dp[i],dp[j]+s[i].z);
        }
        printf("Case %d: maximum height = ",cas++);
        int ans=0;
        rep(i,0,3*n) ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }
return 0;
}
