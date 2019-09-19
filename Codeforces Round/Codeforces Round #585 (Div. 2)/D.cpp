#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=200005;

char s[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",s);
        int num1=0,num2=0,sum1=0,sum2=0;
        rep(i,0,n/2){
            if(s[i]=='?') ++num1;
            else sum1+=s[i]-'0';
        }
        rep(i,n/2,n)
            if(s[i]=='?') ++num2;
            else sum2+=s[i]-'0';
        int t=min(num1,num2);
        num1-=t;num2-=t;
        t=min(sum1,sum2);
        sum1-=t;sum2-=t;
        if(sum2>0){
            swap(sum1,sum2),swap(num1,num2);
            if(num1>=num2) puts("Monocarp");
            else{
                num2-=num1;
                if(sum1%9==0 && num2/2*9==sum1) puts("Bicarp");
                else puts("Monocarp");
            }
        }else if(sum2==0){
            if(sum1>0){
                if(num1>=num2) puts("Monocarp");
                else{
                    num2-=num1;
                    if(sum1%9==0 && num2/2*9==sum1) puts("Bicarp");
                    else puts("Monocarp");
                }
            }
            else if(sum1==0){
                if(num1==num2) puts("Bicarp");
                else puts("Monocarp");
            }
        }
    }
return 0;
}
