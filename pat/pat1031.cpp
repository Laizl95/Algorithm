#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=505;

int main(){
    char s[N];
    scanf("%s",s);
    int len=strlen(s);
    int c=(len+2)/3;
    int r=len-c*2,p=0;
    rep(i,0,c){
        int pre=p;
        printf("%c",s[p++]);
        rep(j,0,r)
            if(i==c-1) printf("%c",s[p++]);
            else printf(" ");
            printf("%c\n",s[len-pre-1]);
    }
return 0;
}
