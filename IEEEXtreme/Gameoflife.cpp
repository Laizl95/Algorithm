#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define make_pair mp
using namespace std;
const int N=28;
typedef long long LL;
/*1.Any live cell with fewer than two live neighbors dies, as if caused by under-population.
2.Any live cell with two or three live neighbors lives on to the next generation.
3.Any live cell with more than three live neighbors dies, as if by over-population..
4.Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.*/
char mat[N][N];
int n,m,T,id=0,hashs=100;
int cnt[N][N],dir[8][2]={0,1,0,-1,1,0,-1,0,-1,-1,-1,1,1,-1,1,1};
set<int> cell,is_new;
vector<int> death;
map<set<int>,int> mp;
int dfs(int t,int ok){
    set<int>::const_iterator iter,it;
    rep(i,0,t){
        //set<int> is_new;
        //vector<int> death;
    for(iter=cell.begin();iter!=cell.end();){
        int x=*iter/hashs,y=*iter%hashs,tot=0;
        rep(k,0,8){
            int dx=(x+dir[k][0]+n)%n,dy=(y+dir[k][1]+m)%m;
            if(mat[dx][dy]=='*') tot+=1;
            else if(mat[dx][dy]=='-'){
                cnt[dx][dy]+=1;
                is_new.insert(dx*hashs+dy);
            }
        }
        if(tot<2 || tot>3){
            death.pb(x*hashs+y);
            it=iter;++it;
            cell.erase(*iter);
            iter=it;
        }else ++iter;
    }
    int t=death.size();
    rep(i,0,t) mat[death[i]/hashs][death[i]%hashs]='-';
    death.clear();
    for(iter=is_new.begin();iter!=is_new.end();++iter){
        int i=*iter;
        int x=i/hashs,y=i%hashs;
        if(cnt[x][y]==3){
            mat[x][y]='*';
            cell.insert(i);
        }
        cnt[x][y]=0;
    }
     is_new.clear();
     if(cell.size()==0){
        rep(i,0,n) printf("%s\n",mat[i]);
        return -1;
     }
     if(ok){
        if(mp.count(cell)) return id;
        else mp[cell]=id++;
     }
    //puts("");rep(i,0,n) printf("%s\n",mat[i]);puts("");
    }//puts("");
    rep(i,0,n) printf("%s\n",mat[i]);
return -1;
}
int main(){

    while(scanf("%d %d %d",&n,&m,&T)!=EOF){
        ms(cnt,0);cell.clear();is_new.clear();death.clear();id=0;
        rep(i,0,n) scanf("%s",mat[i]);
        rep(i,0,n) rep(j,0,m) if(mat[i][j]=='*') cell.insert(i*hashs+j);
        mp[cell]=id++;
        int t=dfs(T,1);
        if(t!=-1){
            //cout<<t<<endl;
           /* rep(i,0,n) rep(j,0,m) mat[i][j]='-';
            set<int>::const_iterator iter,it;
            for(iter=cell.begin();iter!=cell.end();++iter){
                int x=*iter/hashs,y=*iter%hashs;
                mat[x][y]='*';
            }*/
            dfs(T%t,0);
        }
    }
return 0;
}
/*周期不一定是第一个开始
4 6 5
------
*-----
------
-***--/*
