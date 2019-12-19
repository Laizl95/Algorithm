#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
char s[N];

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s)-1;
       // cout<<len<<endl;
        int ok=0;
        if(len+1>=2){
            if(s[len]=='o' && s[len-1]=='p') ok=1;
        }
        if(len+1>=4){
           if(s[len]=='u' && s[len-1]=='s' && s[len-2]=='e' && s[len-3]=='d')
            ok=2;
            if(s[len]=='u' && s[len-1]=='s' && s[len-2]=='a' && s[len-3]=='m')
            ok=2;
        }
        if(len+1>=5){
            if(s[len]=='a' && s[len-1]=='d' && s[len-2]=='i' && s[len-3]=='n' &&
               s[len-4]=='m') ok=3;
        }
        if(ok==1) puts("FILIPINO");
        if(ok==2) puts("JAPANESE");
        if(ok==3)puts("KOREAN");
    }
return 0;
}
