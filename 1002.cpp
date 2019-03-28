#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define ms(x,y) memset(x,y,sizeof(x))
typedef long long LL;
using namespace std;
const int N=10005;
char s[N];
struct mat{
 int x,y;
};
void solve(int r,int c,vector<int> ans){
  int m[r][c];
  int y=ans.size()-1,x=0,row=1,column=1;
  //printf("%d %d\n",r,c);
  while(x<=y){
        //printf("%d\n",ans[x]);
    m[row][column++]=ans[x];
    if(column==c+1) row+=1,column=1;
    ++x;
  }
   rep(i,1,r){ rep(j,1,c) printf("%d ",m[i][j]);puts("");}
}
int main(){
    freopen("d://input.txt","r",stdin);
int n;
 while(scanf("%s",s+1)!=EOF){
    int len=strlen(s+1);
    int num1=0,i=1;
    char opr;
    while(i<=len){
      if(s[i]=='['){
            i+=1;int num=0,column=0,row=1;
            vector<int> x;
         while(s[i]!=']'){
           if(s[i]>='0' && s[i]<='9') num=num*10+s[i]-'0';
           else if(s[i]==',') x.push_back(num),num=0;
           else ++row,x.push_back(num),num=0;
           i+=1;
         }
         x.push_back(num);
         int y=x.size();
         column=y/row;
         //rep(i,0,y-1) printf("%d\n",x[i]);
         solve(row,column,x);
         i+=1;
      }
     else if(s[i]=='+' || s[i]=='-' || s[i]=='*') opr=s[i];
     else{
            int num=0;
         if(s[i]>='0' && s[i]<='9') num=num*10+s[i]-'0';
     }
    }
 }
return 0;
}
