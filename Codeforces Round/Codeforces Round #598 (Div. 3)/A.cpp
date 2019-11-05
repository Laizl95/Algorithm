#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int main(){
    int t,a,b,n,s;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&a,&b,&n,&s);
        if(s<=b) puts("YES");
        else{
            s-=b;
            int num1=s/n,num2=s%n;
            if(num1<a && n-num2<=b) puts("YES");
            else if(num1<=a && num2==0) puts("YES");
            else puts("NO");
        }
    }
return 0;
}
