#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
typedef long long  LL;
const int N=1005;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){\
        vector<pair<string,string> > ans;
		int tot=0;
		char account[15],password[15];
	  rep(i,0,n){
	     scanf("%s %s",account,password);
	     int len=strlen(password),ok=0;
	     rep(j,0,len){
		     if(password[j]=='1') password[j]='@',ok=1;
		     if(password[j]=='0') password[j]='%',ok=1;
		     if(password[j]=='l') password[j]='L',ok=1;
		     if(password[j]=='O') password[j]='o',ok=1;
		 }
		 if(ok) ans.pb(make_pair(string(account),string(password))),++tot;
	  }
	  if(tot){
	  	printf("%d\n",tot);
	    rep(i,0,ans.size()) cout<<ans[i].first<<" "<<ans[i].second<<endl;
      }
	  else
	     printf("There %s %d %s and no account is modified\n",n==1?"is":"are",n,n==1?"account":"accounts");

	}
return 0;
}
