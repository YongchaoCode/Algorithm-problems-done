//����ֱ��������dfs��dp�����������ģ���С������(���)��Kruskal�㷨��,���鼯


//����ֱ������Ȩ·����dfs��
//1:Cow Marathon
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5;

int c=0;
int d[N];
//vector<int>G[N];
vector<pair<int,int>>G[N];//first:ֵ��

void dfs(int u,int fu){//u����ǰ��㣬fu����ǰ���ĸ��ڵ㣨ȷ����������������в������ŷ���·�����ݣ�
    for(auto[x,y]:G[u]){//y:����
        if(y==fu){
            continue;
        }
        d[y]=d[u]+x;
        if(d[y]>d[c]){
            c=y;
        }
        dfs(y,u);
    }                                                  // ��Ч��ֹ�ظ����ʺ���ѭ����
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
    d[c]=0;//���ﲻ��Ҫ��ʼ��d[],dfs��d[v]=d[u]+1�Ḳ��ԭ���Ľ��ֱ����������ͼ��
    dfs(c,0);
    cout<<d[c]<<endl;
    return 0;
}*/


//2:oj�������Թ�
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



//�����·������״dp��
//3:TWO
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int ver[N],edge[N],nxt[N],head[N],tot=0;
int vis[N];
int ans=0,sum=0;

void add(int x,int y,int len){
   ver[++tot]=y;
   edge[tot]=len;
   nxt[tot]=head[x] ;
   head[x]=tot;
}

int dfs(int u){
    vis[u]=1;
     int d1=0,d2=0;//�������γ�
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
      ans=max(ans,d1+d2);//ע��ans��λ�ã�Ҫ��ǰ�������������ӽڵ�󣬷��زŸ���ans
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
//        cout<<2*sum-ans<<endl;
    cout<<ans<<endl;
    return 0;
}*/



//4:��������
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
int n;
int ver[N],nxt[N],head[N],tot=0;
int vis[N];
int ans=N;//ans:�����ĵ���С����

void add(int x,int y){
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

int dfs(int u){
    vis[u]=1;
    int size=0;//u�����������
    int sum=1;//u�������������ܽ��
     for(int i=head[u];i!=0;i=nxt[i]){
         int j=ver[i];
         if(vis[j]){
             continue;
         }
          int s=dfs(j);//dfs���ص���u������������
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


//5:Anton and Tree
//���鼯���㣬����ֱ��
/*#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int color[N];
int fa[N];//���ĸ������
vector<int>G[N];
vector<int>BG[N];//���鼯��ͼ
queue<pair<int,int>>q;
int ans=0;
vector<int>vis(N,0);

int get_fa(int u){
    if(u==fa[u]){
        return u;
    }
    return fa[u]=get_fa(fa[u]);//���ҵ�ͬʱ��ѹ��·��
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
    return d1;//�������
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
//        if(color[x]==color[y]&&x!=y){//���鼯����
//            fa[y]=x;
//        }
         if(color[x]==color[y]){
             fa[y]=x;
         }
        else if(color[x]!=color[y]){
            q.push({x,y});
        }
    }//����󣺺ڰ����ĵ㡣ѹ����ĺڰ׵㣬ѹ����q������

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
//���Ӽ��ģ�����ֱ����and�����鼯���㣩!!!
//���鼯���ĵ㣬ֱ��Ȩֵ=0����ֱ�������뼴��



// Balancing Act���������ģ�
/*#include<iostream>
using namespace std;
const int N=2e4+9;
int ver[N],nxt[N],head[N],tot=0;
int vis[N];
int n,ans=N,g=N;//ans:�����ġ�g�����Ľ��

void add(int x,int y){
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

int dfs(int u){
    vis[u]=1;
    int size=0,sum=1;//size:u�����������sum:u����������
    for(int i=head[u];i!=0;i=nxt[i]){
        int j=ver[i];
        if(vis[j]){
            continue;
        }
        int s=dfs(j);//����u�������һ����������
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



//��С������(���)��Kruskal�㷨��
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


//�������ȣ���С������
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
            if(i==j){ continue;}//i==j:continue�� i!=j&&w==0
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


//���鼯(ģ��)
/*#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const ll Mod=998244353;
const ll N=4e6+9;
ll f[N];
ll n,m,ans=0;
int find(int u){return f[u]==u ? u : find(f[u]);}

void unite(int u,int v){
    int fa=find(u),fb=find(v);
    if(fa>fb){swap(fa,fb);}
    if(fa!=fb){
        f[fb]=fa;
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     int x,y,op;
      cin>>n>>m;
        for(int i=0;i<=n;i++){
            f[i]=i;
        }
        for(int i=0;i<m;i++){
            cin>>op;
            if(!op){//����
              cin>>x>>y;
               unite(x,y);
            }
            else{//��ѯ��ͨ
               cin>>x>>y;
               if(find(x)==find(y)){//
                   ans*=2;
                   ans++;
                   ans%=Mod;
               }
               else{
                   ans*=2;
                   ans%=Mod;
               }
            }
        }
         cout<<ans<<endl;
    return 0;
}*/






//���鼯����ȣ�
/*#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int fa[N];
int find(int u){
    return fa[u]==u ? u : find(fa[u]);
}

void unite(int x,int y){
   fa[find(x)]=find(y);
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,op,x,y;
     cin>>n>>m;
       for(int i=1;i<=n;i++){
           fa[i]=i;
       }
        for(int i=1;i<=m;i++){
            cin>>op;
             if(op==1){//�ϲ�
               cin>>x>>y;
                 unite(x,y);
             }
             else{//�ж�
               cin>>x>>y;
                if(find(x)==find(y)){
                    cout<<"Y"<<'\n';
                }
                else{
                    cout<<"N"<<'\n';
                }
             }
        }
    return 0;
}*/


//���ݣ���ȣ�
//���鼯
/*#include<bits/stdc++.h>
using namespace std;
const int N=5009;
int fa[N];

int find(int u){
    return fa[u]==u? u :find(fa[u]);
}

void unite(int x,int y){
    fa[find(x)]=find(y);
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,q,x,y;
     cin>>n>>m>>q;
      for(int i=1;i<=n;i++){
          fa[i]=i;
      }
       for(int i=1;i<=m;i++){
           cin>>x>>y;
            unite(x,y);
       }
         for(int i=1;i<=q;i++){
             cin>>x>>y;
              if(find(x)==find(y)){
                  cout<<"Yes"<<'\n';
              }
              else{
                  cout<<"No"<<'\n';
              }
         }
    return 0;
}*/


//���ͨ����ȣ������鼯
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
            }//��ʼ��fa

              for(int i=1;i<=m;i++){
                  int x=find(e[i].u);
                  int y=find(e[i].v);
                   if(x!=y){
                       fa[y]=x;
                   }
              }//·��ѹ��

             for(int i=1;i<=n;i++){
                 if(i==fa[i]){
                     ans++;
                 }
             }//����ѹ����� ����ɵ㼯

               cout<<ans-1<<endl;
         memset(e,0,sizeof(e));
         memset(fa,0,sizeof(fa));
     }
    return 0;
}*/


//�ڴ���գ���ȣ��������Ҫ����
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
         int num=n-k;//num:���ٽ��ߵ�����

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


//���鼯���Ż��ȣ�
/*#include<bits/stdc++.h>
using namespace std;
const int N=5009;
vector<int>f(N,0),e(N,0);

int find(int u){return f[u]==u ? u : find(f[u]);}

void unite(int u,int v){
    int fa=find(u),fb=find(v);
     if(fa>fb){swap(fa,fb);}
      if(fa!=fb){
          f[fb]=fa;
      }
}

int main()
{
     int n,m,x,y,sum=0;
     char op;
      cin>>n>>m;
       iota(f.begin(),f.end(),0);
        for(int i=1;i<=m;i++){
            cin>>op>>x>>y;
             if(op=='F'){//�ϲ�
                unite(x,y);
             }
             else{
                if(e[x]==0) e[x]=y;
                 else unite(e[x],y);
                if(e[y]==0) e[y]=x;
                 else unite(x,e[y]);
             }
        }

         for(int i=1;i<=n;i++){
             if(f[i]==i){
                 sum++;
             }
         }
          cout<<sum<<endl;
    return 0;
}*/

