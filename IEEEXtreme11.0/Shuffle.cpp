#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;

//有n个家庭，每个家庭需要寄宿在其他家庭，已经寄宿过的不能再寄宿。
//如果这个家庭不能再寄宿在其他家庭，则需要去酒店。求需要住酒店家庭的最小值

int edge[N][N],f[N];
bool used[N];
void solve(char s[],int u){
    //puts(s);
    int x=0,len=strlen(s)-1;
   // printf("len=%d\n",len);
    rep(i,0,len+1){
        if(s[i]==' '|| i==len){
           // cout<<x<<endl;
            edge[u][x]=0;
            x=0;
        }else x=x*10+s[i]-'0';
    }
}
//匈牙利算法
bool finds(int u,int n){//u为当前正在匹配的左边元素
       for (int v=0;v<n;++v){//扫描右边每个元素v
           if (edge[u][v]==1 && used[v]==false){
               // line[u][v]==true表示元素u和v之间有连线，
               //used[v]表示这个元素的曾是否有过要更改匹配的，这样可以省下一些时间

           used[v]=true;
           if (f[v]==-1 || finds(f[v],n)){   //f[v]表示v元素所匹配的元素
             //f[v]==0表示该元素仍未匹配 find(f[v])是去尝试能否改变匹配j元素的元素的匹配（就是先前匹配j的元素x能否匹配另一个元素）
            f[v]=u;
            return true;
                }
            }
       }
     return false;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        getchar();
        char s[N];
        rep(i,0,n) {f[i]=-1;rep(j,0,n) edge[i][j]=(i!=j);}
        rep(i,0,n){
           //cin.getline(s,N-1);
            fgets(s,N,stdin);
            solve(s,i);
        }
        //rep(i,0,n) {rep(j,0,n) printf("%d",edge[i][j]);puts("");}
        int ans=0;
        rep(i,0,n){
            rep(j,0,n) used[j]=false;
            if(finds(i,n)) ans+=1;
        }
        printf("%d\n",n-ans);
    }
return 0;
}
