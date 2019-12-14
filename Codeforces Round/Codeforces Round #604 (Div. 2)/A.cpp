#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e5+5,inf=1e9+5;
typedef long long LL;
char s[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       scanf("%s",s);
       int len=strlen(s),ok=1;
       char pre='d';
       rep(i,0,len-1)
         if(s[i]=='?'){
            if(pre=='d'){
                if(s[i+1]=='?') s[i]='a',pre='a';
                else{
                    if(s[i+1]=='a') s[i]='b',pre='b';
                    else if(s[i+1]=='b') s[i]='a',pre='a';
                    else if(s[i+1]=='c') s[i]='a',pre='a';
                }
            }
            else{

               if(pre=='a'){
                if(s[i+1]=='a') s[i]='b',pre='b';
                else if(s[i+1]=='b') s[i]='c',pre='c';
                else if(s[i+1]=='c') s[i]='b',pre='b';
                else s[i]='b',pre='b';
                }
                 else if(pre=='b'){
                if(s[i+1]=='a') s[i]='c',pre='c';
                else if(s[i+1]=='b') s[i]='c',pre='c';
                else if(s[i+1]=='c') s[i]='a',pre='a';
                else s[i]='c',pre='c';
                }
                 else if(pre=='c'){
                if(s[i+1]=='a') s[i]='b',pre='b';
                else if(s[i+1]=='b') s[i]='a',pre='a';
                else if(s[i+1]=='c') s[i]='a',pre='a';
                else s[i]='b',pre='b';
                }
            }
         }else {
             if(s[i]==pre) ok=0;
             pre=s[i];
        }
        if(s[len-1]=='?'){
            if(pre=='a') s[len-1]='b';
            else s[len-1]='a';
        }else if(s[len-1]==pre) ok=0;
       if(!ok) puts("-1");
       else printf("%s\n",s);
    }
return 0;
}
