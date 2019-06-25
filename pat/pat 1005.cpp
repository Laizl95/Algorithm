#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=105;

int main(){
    char str[N];
    char word[10][10]={"zero","one","two","three","four",
                        "five","six","seven","eight","nine"};
    while(scanf("%s",str)!=EOF){
        int len=strlen(str),sum=0;
        rep(i,0,len) sum+=str[i]-'0';
        if(sum==0) puts("zero");
        vector<int> v;
        while(sum>0){
            v.pb(sum%10);
            sum/=10;
        }
        int t=v.size();
        per(i,0,t) printf("%s%c",word[v[i]],i==0?'\n':' ');

    }
return 0;
}
