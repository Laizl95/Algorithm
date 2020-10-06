
## Tarjan算法

#### 强连通:如果两个顶点可以相互通达,则称两个顶点强连通

#### 强连通图：如果有向图G的每两个顶点都强连通称G是一个强连通图

#### 强连通分量：非强连通图有向图的极大强连通子图

####适用问题：求解（有向图/无向图）的，桥，割点，环，回路等问题

Tarjan算法是用来求强连通分量的，它是一种基于DFS的算法，
每个强连通分量为搜索树中的一棵子树。并且运用了数据结构栈。
在介绍详细原理前，先引入两个非常重要的数组：dfn[ ] 与 low[ ]

dfn:就是一个时间戳（被搜到的次序），一旦某个点被DFS到后，这个时间戳就不再改变.所以常根据dfn的值来判断是否需要进行进一步的深搜

low:该子树中，且仍在栈中的最小时间戳，像是确立了一个关系，low相等的点在同一强连通分量中
```
void tarjan(int now){
    dfn[now]=low[now]=++cnt;  //初始化
    stack[++t]=now;　　　　　　 //入栈操作
    v[now]=1;　　　　　　　　    //v[]代表该点是否已入栈
    for(int i=f[now];i!=-1;i=e[i].next)  //邻接表存图
        if(!dfn[e[i].v]) 　　　　　　　　　 //判断该点是否被搜索过
        {
            tarjan(e[i].v);
            low[now]=min(low[now],low[e[i].v]); //回溯时更新low[ ]，取最小值
        }
        else if(v[e[i].v])
            low[now]=min(low[now],dfn[e[i].v]); //一旦遇到已入栈的点，就将该点作为连通量的根
　　　　　　　　　　　　　　　　　　　　　　　　　　　　 //这里用dfn[e[i].v]更新的原因是：这个点可能
　　　　　　　　　　　　　　　　　　　　　　　　　　　　 //已经在另一个强连通分量中了但暂时尚未出栈，所
　　　　　　　　　　　　　　　　　　　　　　　　　　　　 //以now不一定能到达low[e[i].v]但一定能到达
　　　　　　　　　　　　　　　　　　　　　　　　　　　　 //dfn[e[i].v].
    if(dfn[now]==low[now])
    {
        int cur;
        do
        {
            cur=stack[t--];
            v[cur]=false;                       //不要忘记出栈
        }while(now!=cur);
    }
}
int main(){

return 0;
}
```
