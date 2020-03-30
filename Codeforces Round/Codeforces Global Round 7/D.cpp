#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+5,inf=1e9+5;
typedef long long LL;
int n,m,k;
string s,str;
vector<int> d1(2*N+1);
string manacher(const string &a){
    int len=a.length();
    s="#";
    rep(i,0,len) s+=a[i],s+="#";
    int n=2*len+1;
    for(int i=0,l=0,r=-1;i<n;i++){
        int k=(i>r)?1:min(d1[l+r-i],r-i);//l+r-i是i关于回文串s[l-r]的对称中心
        while(0<=i-k && i+k<n && s[i-k]==s[i+k]){
            k++;
        }
        d1[i]=k--;

        if(i+k>r){
            l=i-k;
            r=i+k;
        }
    }
    //for(auto it:d1) printf("%d ",it);cout<<endl;
    int mx=-1,p;
    rep(i,0,n){
        if(i+1-d1[i]==0 || i+d1[i]==n){
            int x=(2*d1[i]-1)/2;
            if(x>mx) mx=x,p=i;
        }
    }
    string buf;
    rep(i,p-d1[p]+1,p+d1[p]){

        if(i&1) buf+=s[i];
    }
    return buf;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>str;
        int len=str.length();
        int l=0,r=len-1;
        while(l<r && str[l]==str[r]) ++l,--r;
        if(l==r){
            cout<<str<<endl;
            continue;
        }
        string a=str.substr(l,r-l+1);

        string buf=manacher(a);
        cout<<str.substr(0,l);
        cout<<buf;
        cout<<str.substr(r+1,l)<<endl;;
    }
return 0;
}
