//树的直径（两次dfs，dp），树的重心，并查集缩点最小生成树(洛谷)（Kruskal算法），树状数组，线段树


//树的直径（有权路劲，dfs）
//1:Cow Marathon
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5;

int c=0;
int d[N];
//vector<int>G[N];
vector<pair<int,int>>G[N];//first:值，

void dfs(int u,int fu){//u：当前结点，fu：当前结点的父节点（确保在深度优先搜索中不会沿着反向路径回溯，
    for(auto[x,y]:G[u]){//y:顶点
        if(y==fu){
            continue;
        }
        d[y]=d[u]+x;
        if(d[y]>d[c]){
            c=y;
        }
        dfs(y,u);
    }                                                  // 有效防止重复访问和死循环。
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,len;
        char a;
        cin>>x>>y>>len>>a;
        G[x].push_back({len,y});
        G[y].push_back({len,x});
    }
    dfs(1,0);
    d[c]=0;//这里不需要初始化d[],dfs中d[v]=d[u]+1会覆盖原来的结点直径（不懂画图）
    dfs(c,0);
    cout<<d[c]<<endl;
    return 0;
}*/


//2:oj：逃离迷宫
/*#include<bits/stdc++.h>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int main()
{
    int n,m,h;
    cin>>n>>m>>h;
    vector<vector<int>>mp(n+1,vector<int>(m+1,0)),
            dis(n+1,vector<int>(m+1,1e16)),vis(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    int sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;
    priority_queue<tuple<int,int,int>>q;
    q.emplace(0,sx,sy);
    dis[sx][sy]=0;
    while(q.size()){
        auto[di,x,y]=q.top();
        q.pop();
        if(vis[x][y]==1){
            continue;
        }
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int tx=x+dx[i];
            int ty=y+dy[i];
            if(tx>=1&&tx<=n && ty>=1&&ty<=m && dis[tx][ty]>dis[x][y]+mp[tx][ty]){
                dis[tx][ty]=dis[x][y]+mp[tx][ty];
                q.emplace(-dis[tx][ty],tx,ty);
            }
        }
    }
    if(dis[ex][ey]>=h){
        cout<<"N0"<<endl;
    }
    else{
        cout<<"YES"<<endl<<h-dis[ex][ey]<<endl;
    }
    return 0;
}*/



//树的最长路径（树状dp）
//3:TWO
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int ver[N],edge[N],nxt[N],head[N],tot=0;
int vis[N];
int ans=0,sum=0;

void add(int x,int y,int len){
   ver[++tot]=y;
   edge[tot]=len;//edge[2]=len
   nxt[tot]=head[x] ;//nxt[3]=2
   head[x]=tot;
}

int dfs(int u){
    vis[u]=1;
     int d1=0,d2=0;//主长，次长
      for(int i=head[u];i!=0;i=nxt[i]){
          int j=ver[i];
           if(vis[j]){
               continue;
           }
            int d=dfs(j)+edge[i];
             if(d>=d1){
                 d2=d1,d1=d;
             }
             else if(d>d2){
                 d2=d;
             }
      }
      ans=max(ans,d1+d2);//注意ans的位置，要当前结点遍历完所有子节点后，返回才更新ans
       return d1;
}

int main()
{

     int n,s;
      cin>>n>>s;
       for(int i=1;i<=n-1;i++){
           int a,b,len;
            cin>>a>>b>>len;
             sum+=len;
            add(a,b,len);
            add(b,a,len);
       }
           dfs(s);
        cout<<2*sum-ans<<endl;
    return 0;
}*/



//4:树的重心
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
int n;
int ver[N],nxt[N],head[N],tot=0;
int vis[N];
int ans=N;//ans:树重心的最小子树

void add(int x,int y){
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

int dfs(int u){
    vis[u]=1;
    int size=0;//u结点的最大子树
    int sum=1;//u的所有子树的总结点
     for(int i=head[u];i!=0;i=nxt[i]){
         int j=ver[i];
         if(vis[j]){
             continue;
         }
          int s=dfs(j);//dfs返回的是u结点的子树总数
          size=max(size,s);
          sum+=s;
     }
      ans=min(ans,max(size,(n-sum)));
     return sum;
}

int main()
{
     cin>>n;
      for(int i=1;i<=n-1;i++){
          int x,y;
           cin>>x>>y;
            add(x,y);
            add(y,x);
      }

         dfs(1);
       cout<<ans<<endl;
    return 0;
}*/


//WA
//5:Anton and Tree
//并查集缩点，树的直径
/*#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int color[N];
int fa[N];//结点的父根结点
vector<int>G[N];
vector<int>BG[N];//并查集后图
queue<pair<int,int>>q;
int ans=0;
vector<int>vis(N,0);

int get_fa(int u){
    if(u==fa[u]){
        return u;
    }
    return fa[u]=get_fa(fa[u]);//查找的同时，压缩路径
}

int dfs(int u){
    vis[u]=1;
    int d1=0,d2=0;
    for(auto x:BG[u]){
        if(vis[x]){
            continue;
        }
        int d=dfs(x)+1;
        if(d>=d1){
            d2=d1,d1=d;
        }
        else if(d>d2){
            d2=d;
        }
    }
    ans=max(ans,d1+d2);
    return d1;//返回最长边
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>color[i];
        fa[i]=i;
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        x= get_fa(x);
        y= get_fa(y);
//        if(color[x]==color[y]&&x!=y){//并查集缩点
//            fa[y]=x;
//        }
         if(color[x]==color[y]){
             fa[y]=x;
         }
        else if(color[x]!=color[y]){
            q.push({x,y});
        }
    }//缩点后：黑白相间的点。压缩后的黑白点，压入了q队列中

      if(q.empty()){
          cout<<"0"<<endl;
          return 0;
      }
      int start= get_fa(q.front().first);
    while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();
        int u= get_fa(x);
        int v= get_fa(y);
        BG[u].push_back(v);
        BG[v].push_back(u);
    }

    dfs(start);
    cout<<(ans+1)/2<<'\n';
    return 0;
}*/

//Anton and Tree
//更加简便的（树的直径）and（并查集缩点）!!!
//并查集缩的点，直接权值=0，求直径不计入即可





// Balancing Act（树的重心）
/*#include<iostream>
using namespace std;
const int N=2e4+9;
int ver[N],nxt[N],head[N],tot=0;
int vis[N];
int n,ans=N,g=N;//ans:树重心。g：重心结点

void add(int x,int y){
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

int dfs(int u){
    vis[u]=1;
    int size=0,sum=1;//size:u的最大子树。sum:u的子树总数
    for(int i=head[u];i!=0;i=nxt[i]){
        int j=ver[i];
        if(vis[j]){
            continue;
        }
        int s=dfs(j);//返回u结点其中一条子树数量
        size=max(s,size);
        sum+=s;
    }
    if(ans>max(size,(n-sum))){
        ans=max(size,(n-sum));
        g=u;
    }
    else if(ans==max(size,(n-sum))){
        g=min(g,u);
    }
//      ans=min(ans,max(size,(n-sum)));
    return sum;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        tot=0,ans=N,g=N;
        cin>>n;
        for(int i=0;i<=n;i++){
            vis[i]=0,head[i]=0,nxt[i]=0,ver[i]=0;
        }
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            add(x,y);
            add(y,x);
        }
        dfs(1);
        cout<<g<<" "<<ans<<'\n';
    }
    return 0;
}*/


/*
#include<bits/stdc++.h>
using namespace std;
const int N=109;
int n;
vector<vector<int>>G(N,vector<int>(N,INT16_MAX));

void Floyd(){
  for(int k=1;k<=n;k++){
      for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
              if(G[i][j]>G[i][k]+G[k][j]){
                  G[i][j]=G[i][k]+G[k][j];
              }
          }
      }
  }
}

int main()
{
      cin>>n;
       for(int i=1;i<=n;i++){
           G[i][i]=0;
            int w,l,r;
            cin>>w>>l>>r;
             if(l){G[i][l]=G[l][i]=1;};
             if(r){G[i][r]=G[r][i]=1;};
       }

//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                  cout<<G[i][j]<<" ";
//             }
//              cout<<endl;
//         }
    return 0;
}
*/



//最小生成树(洛谷)（Kruskal算法）
/*#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,cnt=0;
int fa[5009];
const int N=200009;
int find(int u){
    if(fa[u]==u){
        return u;
    }
    return fa[u]=find(fa[u]);
}

struct edge{
   int u,v,w;
}e[N];

bool cmp(edge a,edge b){
    return a.w<b.w;
}

void Kruskal(){
    sort(e+1,e+1+m, cmp);
      for(int i=1;i<=n;i++){
          fa[i]=i;
      }
     for(int i=1;i<=m;i++){
         int x=find(e[i].u);
         int y=find(e[i].v);
          if(x!=y){
              fa[x]=y;
              ans+=e[i].w;
              cnt++;
          }
     }
}

int main()
{
     cin>>n>>m;
      for(int i=1;i<=m;i++){
          int x,y,z;
            cin>>x>>y>>z;
            e[i].u=x,e[i].v=y,e[i].w=z;
      }
        Kruskal();
       if(cnt==n-1){
           cout<<ans<<endl;
       }
       else{
           cout<<"orz"<<endl;
       }
    return 0;
}*/


//买礼物（洛谷）最小生成树
/*#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
int fa[N];
int tot=0,ans=0;

int find(int u){
    if(fa[u]==u){
        return u;
    }
    return fa[u]=find(fa[u]);
}

struct edge{
    int u,v,w;
}e[N];

bool cmp(edge a,edge b){
    return a.w<b.w;
}

void Kruskal(){
    sort(e+1,e+1+tot,cmp);
    for(int i=1;i<=tot;i++){
        fa[i]=i;
    }
    for(int i=1;i<=tot;i++){
        int x=find(e[i].u);
        int y=find(e[i].v);
        if(x!=y){
            fa[x]=y;
            ans+=e[i].w;
        }
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=b;i++){
        for(int j=1;j<=b;j++){
            int w;
            cin>>w;
            if(i==j){ continue;}//i==j:continue。 i!=j&&w==0
            if(i!=j&&w==0){
                w=a;
            }
            if(i!=j&&w>a){
                w=a;
            }
            e[++tot].v=i,e[tot].u=j,e[tot].w=w;
        }
    }
    Kruskal();
    cout<<a+ans<<endl;
    return 0;
}*/


//村村通（洛谷），并查集
/*#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,m;
int fa[N];

int find(int u){
    if(fa[u]==u){
        return u;
    }
    return fa[u]=find(fa[u]);
}

struct edge{
    int u,v;
}e[N];

int main()
{

     while(true){
         int ans=0;
         cin>>n;
          if(!n){break;}
          cin>>m;
           for(int i=1;i<=m;i++){
               int x,y;
                cin>>x>>y;
                e[i].u=x,e[i].v=y;
           }

            for(int i=1;i<=n;i++){
                fa[i]=i;
            }//初始化fa

              for(int i=1;i<=m;i++){
                  int x=find(e[i].u);
                  int y=find(e[i].v);
                   if(x!=y){
                       fa[y]=x;
                   }
              }//路径压缩

             for(int i=1;i<=n;i++){
                 if(i==fa[i]){
                     ans++;
                 }
             }//计算压缩后的 不相干点集

               cout<<ans-1<<endl;
         memset(e,0,sizeof(e));
         memset(fa,0,sizeof(fa));
     }
    return 0;
}*/


//口袋天空（洛谷，审题的重要！）
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9;
int fa[N];

int find(int u){
    if(fa[u]==u){
        return u;
    }
    return fa[u]=find(fa[u]);
}

struct edge{
    int u,v,w;
}e[N];

bool cmp(edge a,edge b){
    return a.w<b.w;
}

int main()
{
    int n,m,k,ans=0;
     cin>>n>>m>>k;
      for(int i=1;i<=m;i++){
          int x,y,z;
           cin>>x>>y>>z;
            e[i].u=x,e[i].v=y,e[i].w=z;
      }
         sort(e+1,e+1+m,cmp);
         int num=n-k;//num:至少建边的数量

          if((num==0&&m>0)||(k>n)){
              cout<<"No Answer"<<endl;
              return 0;
          }

            for(int i=1;i<=n;i++){
                fa[i]=i;
            }

              for(int i=1;i<=m;i++){
                  if(num==0){
                      break;
                  }
                  int x=find(e[i].u);
                  int y=find(e[i].v);
                   if(x!=y){
                       fa[y]=x;
                       ans+=e[i].w;
                       num--;
                   }
              }
               if(num){
                   cout<<"No Answer"<<endl;
               }
               else{
                   cout<<ans<<endl;
               }
    return 0;
}*/



//树状数组：支持单点修改，区间查询，lowbit。空间O(n),时间O(logn)
//树状数组1（洛谷）
/*#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int n,m;
int tree[N];

int lowbit(int k){
   return k & (-k);
}

void add(int x,int k){//b[i]（向上）== b[i+lowbit]
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
}

int getsum(int x){//sum: tree[1]+...+tree[x]
    int ans=0;
     while(x>0){
         ans+=tree[x];
         x-=lowbit(x);
     }
     return ans;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
      cin>>n>>m;
       for(int i=1;i<=n;i++){
           int a;
            cin>>a;
            add(i,a);//原始tree数组
       }

         for(int i=1;i<=m;i++){
             int op,x,y;
              cin>>op>>x>>y;
               if(op==1){//add
                  add(x,y);
               }
               else if(op==2){//cout(sum)
                  cout<<getsum(y)-getsum(x-1)<<'\n';
               }
         }
    return 0;
}*/


//error
//线段树:O(logn)实现单点修改、区间修改、区间查询（区间求和，求区间最大值，求区间最小值）等操作。
//建树build()->区间修改update()，lazy标记->区间查询getsum()
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int arr[N],tree[4*N];
int b[4*N];//lazy标记

void build(int s,int t,int p){//对 [s,t] 区间建立线段树,当前根的编号为 p
     if(s==t){//叶子
         tree[p]=arr[s];
         return;
     }
    int m=(s+t)/2;//可优化
     build(s,m,2*p),build(m+1,t,2*p+1);
      tree[p]=tree[2*p]+tree[2*p+1];
}

void update(int l,int r,int c,int s,int t,int p){//[l,r]为修改区间,c为被修改的元素的变化量,//[s,t]为当前节点包含的区间,p为当前节点的编号
     if(l<=s && t<=r){
         tree[p]+=(t-s+1)*c,b[p]+=c;
         return;
     }
    int m=(s+t)/2;
     if(b[p]&&s!=t){//有lazy标记
         tree[2*p]+=b[p]*(m-s+1),tree[2*p+1]+=b[p]*(t-m);
          b[2*p]+=b[p],b[2+p+1]+=b[p];//下传lazy标记
          b[p]=0;
     }
     if(l<=m) update(l,r,c,s,m,2*p);
     if(r>m)  update(l,r,c,m+1,t,2*p+1);
      tree[p]=tree[2*p]+tree[2*p+1];
}

int getsum(int l,int r,int s,int t,int p){//[l,r]为查询区间,[s,t]为当前节点包含的区间,p为当前节点的编号
     if(l<=s && t<=r){
         return tree[p];
     }
    int m=(s+t)/2;
     if(b[p]){
         tree[2*p]+=b[p]*(m-s+1),tree[2*p+1]+=b[p]*(t-m);
          b[2*p]+=b[p],b[2*p+1]+=b[p];
          b[p]=0;
     }
     int sum=0;
      if(l<=m) sum=getsum(l,r,s,m,2*p);//=
      if(r>m) sum+=getsum(l,r,m+1,t,2*p+1);//+=
       return sum;
}

int main()
{
    int n,m;
     cin>>n>>m;
     for(int i=1;i<=n;i++){
         cin>>arr[i];
     }
         build(1,n,1);//根节点编号：1
      for(int i=1;i<=m;i++){
          int op,x,y,k;
           cin>>op;
            if(op==1){//区间修改
               cin>>x>>y>>k;
                update(x,y,k,1,n,1);
            }
            else if(op==2){//区间查询（单点查询）
               cin>>x;
               int sum=getsum(x,x,1,n,1);
                cout<<sum<<endl;
            }
      }
    return 0;
}
*/

