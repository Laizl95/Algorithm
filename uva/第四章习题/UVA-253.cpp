#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ms(x,y) memset(x,y,sizeof(x))
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=y;i>=x;i--)
using namespace std;
typedef long long  LL;
const int N=15;
char s[N];
int ans[7][7]={
{0,0,0,0,0,0,0},{0,1,2,3,4,5,6},{0,2,6,3,4,1,5},{0,3,2,6,1,5,4},{0,4,2,1,6,5,3},{0,5,1,3,4,6,2},{0,6,2,4,3,5,1}
};
int judge(int i){
	rep(j,1,6) if(s[ans[i][j]]!=s[j+6]) return 0;
	return 1;
}
int main(){
	while(scanf("%s",s+1)!=EOF){
		int flag=0;
		rep(i,1,6){
			rep(j,1,4){
				char c=s[ans[i][2]];
				s[ans[i][2]]=s[ans[i][4]];
				char a=s[ans[i][3]];
				s[ans[i][3]]=c;
				c=s[ans[i][5]];
				s[ans[i][5]]=a;
				s[ans[i][4]]=c;
				if(judge(i)){
					flag=1;
					puts("TRUE");
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) puts("FALSE");
	}
	return 0;
}