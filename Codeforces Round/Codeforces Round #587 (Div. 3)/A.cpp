#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
char s[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",s);
        int ans=0;
        for(int i=0;i<n;i+=2)
        if(s[i]==s[i+1]){ans+=1;if(s[i]=='a') s[i]='b';else s[i]='a';}
        printf("%d\n",ans);
        rep(i,0,n) printf("%c",s[i]);puts("");
    }
return 0;
}
