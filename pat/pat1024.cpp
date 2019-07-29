//给定一个数n,判断k步操作内能否形成回文数
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
typedef long long ll;
char a[N],b[N];
int judge(char s[]){
    int len=strlen(s);
  rep(j,0,len/2) if(s[j]!=s[len-j-1]) return 0;
  return 1;
}
int main(){
     int k;
    while(scanf("%s %d",a,&k)!=EOF){
        if(judge(a)){
            rep(j,0,strlen(a)) printf("%c",a[j]);puts("");
            printf("%d\n",0);
            continue;
        }
        int ok=0;
        rep(i,0,k){
             int id=0,p=0,len=strlen(a);
            rep(j,0,len){
                 int x=a[j]-'0'+a[len-j-1]-'0'+p;
                 b[id++]=(x%10)+'0';
                 p=x/10;
            }
            if(p) b[id++]=p+'0';
            b[id++]='\0';
            if(judge(b)){
             ok=1;
             per(j,0,strlen(b)) printf("%c",b[j]);puts("");
             printf("%d\n",i+1);
             break;
            }
            rep(j,0,strlen(b)) a[j]=b[j];a[strlen(b)]='\0';
            //rep(j,0,strlen(b)) printf("%c",a[j]);puts("");
        }
        if(!ok){
            per(j,0,strlen(b)) printf("%c",b[j]);puts("");
            printf("%d\n",k);
        }
    }
return 0;
}
