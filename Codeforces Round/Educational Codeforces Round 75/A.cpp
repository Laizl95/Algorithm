#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=3e5+5,inf=1e9+5;
typedef long long LL;
char s[N];
int n,m,ans[30];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        for(char c='a';c!='z'+1;++c) ans[c-'a']=-1;
        int len=strlen(s),p=1,num=1;
        char pre=s[0];
        while(p<len){
            if(s[p]==pre) ++num;
            else{

               if(num%2==0 && ans[pre-'a']!=0) ans[pre-'a']=1;
               if(num%2!=0)  ans[pre-'a']=0;
               num=1;
               pre=s[p];
            }
            ++p;
        }
        if(num%2==0 && ans[pre-'a']!=0) ans[pre-'a']=1;
        if(num%2!=0) ans[pre-'a']=0;
        for(char c='a';c!='z'+1;++c){
            if(ans[c-'a']==0) printf("%c",c);
        }puts("");
    }
return 0;
}
