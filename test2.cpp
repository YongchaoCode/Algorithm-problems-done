                 /* **                      ��                 *** */
////����
///*
// �洢��ʽ��
//    1��˫�ױ�ʾ�����ýڵ�֪���Լ�����֪��������λ�á����ǲ�֪���Լ������ӽڵ㣨Ҫ�Ľ�����
//    2�����ӱ�ʾ��������+����Ĵ洢��ʽ��PPT����p10����
//*/
////2�����ӱ�ʾ�����룺
//
////���ӽ�������:
//typedef struct CNod{
//    int pos;//���ӽڵ���±�
//    struct CNod* next;//ָ����һ���ӽ��
//}*ChildNod;
//
////��ͷ�ṹ��
//typedef struct {
//    char data;//���������
//    int parent;//���ĸ������±�
//    ChildNod child;//���ĵ�һ������  ������ָ��
//}ThNod;
//
////���ṹ
//typedef struct {
//    ThNod nods[100];//���Ľ��
//    int r,n;//r:����λ�ã�n:��������
//};


                            /*           ͼ            */
//ͼ��
/*1���洢�������ڽӾ����ڽӱ�ʮ������
 *
 *
 *
*/

//�ڽӱ�洢:https://zhuanlan.zhihu.com/p/618361957
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int head[100],ver[100],nxt[100],edge[100];
     int tot=0;
     int n,m;
     cin>>n>>m;
      for(int i=1;i<=m;i++){//������������4,5�죬���ơ�
          int x,y,z;
           cin>>x>>y>>z;
           ver[++tot]=y;
           edge[tot]=z;
           nxt[tot]=head[x];
           head[x]=tot;
      }

        int a;
          cin>>a;
       //����a��������г���
        for(int i=head[a];i;i=nxt[i]){
            int j=ver[i],w=edge[i];//j�յ㣬wȨ
             cout<<j<<" "<<w<<endl;
        }
    return 0;
}*/


//1:ͼ�Ĵ洢����ȣ������ڽӾ���+�ڽӱ�ʵ�֣�
/*
#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int M[N][N],r[N];
vector<int>g[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        M[a][b]=M[b][a]=1;
        g[a].push_back(b);
        g[b].push_back(a);
        r[a]++;
        r[b]++;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<M[i][j]<<" \n"[j==n];
        }
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
        cout<<r[i]<<" ";
        for(auto j:g[i]){
            cout<<j<<" ";
      }
        cout<<endl;
    }
    return 0;
}*/


//2:ͼ�ı�������ȣ��ڽӱ�+dfs���� �����ɣ������ڽӱ�
/*
#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=1e5+9;

vector<int>G[N];
int vis[N];//���ã���Ƿ���+�洢 i�����ܵ������ı�Ŷ���

void dfs(int x,int d){
    if(vis[x]){
        return;
    }
    vis[x]=d;
     for(int i=0;i<G[x].size();i++){
         dfs(G[x][i],d);
     }
}

int main()
{
    int n,m;
     cin>>n>>m;
      for(int i=1;i<=m;i++){
          int a,b;
           cin>>a>>b;
            G[b].push_back(a);
      }

       for(int i=n;i;i--){
           dfs(i,i);
       }
       for(int i=1;i<=n;i++){
           cout<<vis[i]<<" ";
       }
    return 0;
}*/


//3:��������/������
/*#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
const int N=1000009;

vector<int> G[N];//�ڽӾ���
queue<int> q;
int R[N];//����������

void solve(){
     while(!q.empty()){
         int t=q.front();
          q.pop();
          cout<<t<<" ";
          //�����ö���ĺ����G[t]
          for(auto x:G[t]){
              R[x]--;
              if(R[x]==0){
                  q.push(x);
              }
          }
     }
}

int main()
{
    int n;
     cin>>n;
      for(int i=1;i<=n;i++){
          int a;
          while(cin>>a&&a){
             G[i].push_back(a);
             R[a]++;
          }
      }

       for(int i=1;i<=n;i++){
           if(R[i]==0){
               q.push(i);//���==0�Ķ������
           }
       }
       solve();
    return 0;
}*/



//4:Count Connected Components
//dfs����
/*#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=109;

vector<int>G[N];
int vis[N];
int ans=0;

void dfs(int x){
    if(vis[x]==1){
        return;
    }
    vis[x]=1;
    for(auto i:G[x]){
        dfs(i);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}*/


//5:�������ף���ȣ�
//ͼ�ı�����dfs��bfs�����������С��Ԫ�أ�����(set�������)��
/*#include<bits/stdc++.h>
#include<set>
#include<queue>
using namespace std;
const int N=1e6+9;

int vis[N];
set<int>G[N];
queue<int>q;

void dfs(int x){
    if(vis[x]==1){return;}
    vis[x]=1;
    cout<<x<<" ";
    for(auto it:G[x]){
        if(!vis[it]){
          dfs(it);
        }
    }
}

void bfs(){
    q.push(1);
     vis[1]=1;//ERROR
    while(!q.empty()){
        int x=q.front();
        cout<<x<<" ";
        for(auto a:G[x]){
            if(!vis[a]){
                vis[a]=1;
                q.push(a);
            }
        }
        q.pop();
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        G[a].insert(b);
    }

    dfs(1);
    cout<<endl;
    memset(vis,0,sizeof(vis));

    bfs();
    return 0;
}*/


//WA!!!
//6:Valid BFS?
/*#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;

int vis[N];
int result1[N];
int result2[N];
int k=0;
vector<int>G[N];
queue<int>q;

void bfs(){
      q.push(1);
       vis[1]=1;
     while(!q.empty()){
         int x=q.front();
         result1[k++]=x;
         q.pop();
         for(auto a:G[x]){
             if(!vis[a]){
                 vis[a]=1;
                 q.push(a);
             }
         }
     }
}

int main()
{
    int n;
     cin>>n;

        for(int i=1;i<n;i++){
            int a,b;
             cin>>a>>b;
              G[a].push_back(b);
              G[b].push_back(a);
        }

     for(int i=0;i<n;i++){
         cin>>result2[i];
     }

        bfs();
       int flag=0;
         for(int i=0;i<n;i++){
             if(result1[i]!=result2[i]){
                 flag=1;
                 break;
             }
         }

          if(!flag){
              cout<<"Yes"<<endl;
          }
          else{
              cout<<"No"<<endl;
          }
    return 0;
}*/



//dijkstra�㷨(ͼ����㵽�յ�����·��):
/*#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[100];//��ͼ�� firstΪֵ???��secondΪ��
vector<int>vis(100,0),dis(100,INT_MAX);

void dijkstra(){
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
     priority_queue<pair<int,int>>q;
      q.push({0,1});
         dis[1]=0;
       while(!q.empty()){
           int u=q.top().second;//��ǰͼ�о��������С����ĵ�
            q.pop();
            if(vis[u]){
                continue;
            }
             vis[u]=1;
            for(auto [x,y]:v[u]){
                if(dis[y]>dis[u]+x){
                    dis[y]=dis[u]+x;
                    q.push({-dis[y],y});
                }
            }
       }
}

int main()
{
    int n,m;
     cin>>n>>m;
      int end=n;
      while(m--){
          int a,b,len;
           cin>>a>>b>>len;
            v[a].push_back({len,b});
            v[b].push_back({len,a});
      }
           dijkstra();
        cout<<dis[end]<<endl;
    return 0;
}*/



//7:Dijkstra(���ͨ����·��)
/*#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;//???
ll d[N];//��¼·��
ll R[N];
vector<pair<ll,ll>>G[N];
vector<ll>vis(N,0),dis(N,INF);
priority_queue<pair<ll,ll>>q;

void dijkstra(){
    q.push({0,1});//first���룬second���
      dis[1]=0;
      while(!q.empty()){
          int t=q.top().second;
           q.pop();
            if(vis[t]){
                continue;
            }
             vis[t]=1;
            for(auto[x,y]:G[t]){
                if(dis[y]>dis[t]+x){
                    dis[y]=dis[t]+x;
                      d[y]=t;
                     q.push({-dis[y],y});
                }
            }
      }
}

int main()
{
     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
         int n,m;
       cin>>n>>m;
      for(int i=1;i<=m;i++){
          int a,b,len;
           cin>>a>>b>>len;
           G[a].push_back({len,b});
           G[b].push_back({len,a});
      }
        dijkstra();
          vector<int>path;
         if(dis[n]==INF){
             cout<<-1<<'\n';
         }
         else{
              while(n){
                  path.push_back(n);
                  n=d[n];
              }
             int len=path.size();
             for(int i=len-1;i>=0;i--){
                 cout<<path[i]<<" ";
             }
             cout<<'\n';
         }

    return 0;
}*/



//8: Ordering Tasks
//��������
/*#include<bits/stdc++.h>
using namespace std;
const int N=10009;
int R[N];//����������
queue<int>q;
vector<int>G[N];

void solve(){
     while(!q.empty()){
         int t=q.front();
          cout<<t<<" ";
          q.pop();
          for(auto x:G[t]){
              R[x]--;
               if(R[x]==0){
                   q.push(x);
               }
          }
     }
     cout<<endl;
}

int main()
{
    int n,m;
      while(cin>>n>>m){
          memset(G,0,sizeof(G));
           if(n==0&&m==0){ break;}
          for(int i=0;i<m;i++){
              int a,b;
               cin>>a>>b;
                G[a].push_back(b);
                 R[b]++;
          }

            for(int i=1;i<=n;i++){
                if(R[i]==0){
                    q.push(i);
                }
            }
               solve();
      }
    return 0;
}*/


//Dijkstra:
//����ͼ
//9:
/*#include<bits/stdc++.h>
using namespace std;
const int N=20009;

vector<pair<int,int>>G[N];//firstֵ��second���
vector<int>vis(N,0),dis(N,INT_MAX);
priority_queue<pair<int,int>>q;

void solve(){

    q.push({0,1});
         dis[1]=0;
       while(!q.empty()){
           int t=q.top().second;
             q.pop();
            if(vis[t]==1){
                continue;
            }
             vis[t]=1;
             for(auto[x,y]:G[t]){
                 if(dis[y]>dis[t]+x){
                     dis[y]=dis[t]+x;
                      q.push({-dis[y],y});
                 }
             }
       }
}

int main()
{
    int n,m;
      while(cin>>n>>m)
      {
           fill(vis.begin(),vis.end(),0);
           fill(dis.begin(),dis.end(),INT_MAX);
            memset(G,0,sizeof(G));
          if(n==0&&m==0){ break;}
          for(int i=1;i<=m;i++){
              int a,b,len;
                cin>>a>>b>>len;
                 G[a].push_back({len,b});
                  G[b].push_back({len,a});
          }
           solve();
          cout<<dis[n]<<endl;
      }
    return 0;
}*/



//10��Floyd�㷨����ȣ������⣩��
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=109;

ll G[N][N];
int n,m;

void floyd(){
    for(int k=1;k<=n;k++){//k:��תվ
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

      cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                G[i][j]=0;
            }
            else{
                G[i][j]=INT_MAX;
            }
        }
    }

       for(int i=1;i<=m;i++){
           ll a,b,len;
            cin>>a>>b>>len;
            G[a][b]=min(G[a][b],len);
            G[b][a]=min(G[b][a],len);
       }


        floyd();

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<G[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}*/

//11: ��Դ���·���������棩(���)
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;

vector<pair<int,int>>G[N];//firstֵ
vector<int>vis(N,0),dis(N,INT_MAX);
priority_queue<pair<int,int>>q;
int n,m,s;

void dij(){
    q.push({0,s});
      dis[s]=0;
        while(!q.empty()){
            int t=q.top().second;
             q.pop();
             if(vis[t]){
                 continue;
             }
              vis[t]=1;
              for(auto[x,y]:G[t]){
                  if(dis[y]>dis[t]+x){
                      dis[y]=dis[t]+x;
                       q.push({-dis[y],y});
                  }
              }
        }
}

int main()
{

      cin>>n>>m>>s;//sΪ���
       for(int i=1;i<=m;i++){
           int u,v,w;
            cin>>u>>v>>w;
              G[u].push_back({w,v});
       }

         dij();
        for(int i=1;i<=n;i++){
            cout<<dis[i]<<" ";
        }
    return 0;
}*/


//12:���·����:dij��dfs��(���)
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;

vector<pair<int,int>>G[N];
vector<int>vis(N,0),dis(N,INT_MAX);
priority_queue<pair<int,int>>q;
int cnt=0;

void dij(){
    q.push({0,1});
      dis[1]=0;
        while(!q.empty()){
            int t=q.top().second;
             q.pop();
             if(vis[t]){
                 continue;
             }
              vis[t]=1;
              for(auto[x,y]:G[t]){
                  if(dis[y]>dis[t]+x){
                      dis[y]=dis[t]+x;
                       q.push({-dis[y],y});
                  }
              }
        }
}

void dfs(int x,int end){//��ǰ�㣬�յ�
    if(vis[x]){
        return;
    }
    vis[x]=1;

     if(x==end && ){//&&�ߵ�·��==���·��

     }

     for(int i=1;i<=G[x].size();i++){
         dfs(G[x][i],end);
     }
}

int main()
{
    int n,m;
     cin>>n>>m;
      for(int i=1;i<=m;i++){
          int a,b;
           cin>>a>>b;
           G[a].push_back({1,b});
           G[b].push_back({1,a});
      }

         dij();
        cout<<1<<" ";
       for(int i=2;i<=n;i++){
           fill(vis.begin(),vis.end(),0);
            dfs(1,n);//��㣬�յ�
       }
    return 0;
}*/



//13:Ѱ�ҵ�·������ȣ�:������������������
//����ͼ��orZ
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;

int vis[N];
int can[N];//����ܵ����յ�ĵ�
int ri[N];//��ǺϹ��
int dis[N];//��¼�Ϲ������·��,����vis����
vector<int>zG[N],fG[N];
queue<int>q;

int main()
{
    int n,m,s,t;
     cin>>n>>m;
      for(int i=1;i<=m;i++){
          int a,b;
           cin>>a>>b;//����ͼ
            zG[a].push_back(b);
            fG[b].push_back(a);//����ͼ
      }
      cin>>s>>t;
      //����bfs���ҳ��ܵ����յ�ĵ�
         q.push(t);
          can[t]=1;
        while(!q.empty()){
            int temp=q.front();
             q.pop();
              for(int i=fG[temp].size()-1;i>=0;i--){
                  int to=fG[temp][i];//to:temp�� �������
                   if(!can[to]){
                       q.push(to);
                       can[to]=1;//��ǣ��ܵ����յ�
                   }
              }
        }
         if(!can[s]){
             cout<<"-1"<<endl;
              return 0;
         }

        //�����ܵ����յ�Ķ��㣬���õ��в��ܵ����յ�ĵ㣬��ɾ���ö���
           for(int i=1;i<=n;i++){
               if(can[i]){
                    ri[i]=1;
                   for(int j=zG[i].size()-1;j>=0;j--){
                       int temp=zG[i][j];
                        if(!can[temp]){
                             ri[i]=0;
                            break;
                        }
                   }
               }
           }

    if(!ri[s])			            //������Ҫ�����ж�һ������Ƿ���������
    {
        cout<<"-1";
        return 0;
    }
       //����bfs�������Ϲ�㣬�����·��
        dis[s]=1;
        q.push(s);
         while(!q.empty()){
             int temp=q.front();
              q.pop();
               if(temp==t){
                   cout<<dis[temp]-1<<endl;//��Ϊ���dis[]+1�˵�
                    return 0;
               }
              for(int i=zG[temp].size()-1;i>=0;i--){
                  int to=zG[temp][i];
                  if(!dis[to]&&ri[to]){
                      dis[to]=dis[temp]+1;
                      q.push(to);
                  }
              }
         }

           cout<<"-1"<<endl;
    return 0;
}*/



//14:���·��������ȣ����ڽӱ�洢+���·��������
/*#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9;
const int Mod=100003;
int ans[N];//��¼·����

vector<pair<int,int>>G[N];//first:ֵ
vector<int>dis(N,INT_MAX),vis(N,0);
priority_queue<pair<int,int>>q;

void dig(){
     ans[1]=1;
     dis[1]=0;
      q.push({0,1});
       while(!q.empty()){
           int t=q.top().second;
            q.pop();
            if(vis[t]){
                continue;
            }
             vis[t]=1;
             for(auto[x,y]:G[t]){
                 if(dis[y]>dis[t]+1){
                     dis[y]=dis[t]+1;
                      ans[y]=ans[t];
                       q.push({-dis[y],y});
                 }
                 else if(dis[y]==dis[t]+1){
                     ans[y]+=ans[t];
                     ans[y]%=Mod;//
                 }
             }
       }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
     cin>>n>>m;
      for(int i=1;i<=m;i++){
          int x,y;
           cin>>x>>y;
            G[x].push_back({1,y});
            G[y].push_back({1,x});
      }

       dig();
       for(int i=1;i<=n;i++){
           cout<<ans[i]<<'\n';
       }
    return 0;
}*/

