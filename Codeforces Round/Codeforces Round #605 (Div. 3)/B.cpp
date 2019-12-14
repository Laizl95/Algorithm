#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
char s[N];
int tot[4];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
       scanf("%s",s);
       int len=strlen(s);
       ms(tot,0);
       rep(i,0,len){
            if(s[i]=='U') tot[0]+=1;
            else if(s[i]=='D') tot[1]+=1;
            else if(s[i]=='L') tot[2]+=1;
            else if(s[i]=='R') tot[3]+=1;
       }
       int num1=min(tot[1],tot[0]),num2=min(tot[3],tot[2]);
       if(num1==0) num2=min(num2,1);
       else if(num2==0) num1=min(num1,1);
       int t=num1+num2;
       printf("%d\n",t*2);
       rep(i,0,num2) printf("L");
       rep(i,0,num1) printf("U");
       rep(i,0,num2) printf("R");
       rep(i,0,num1) printf("D");
       puts("");
    }
return 0;
}
