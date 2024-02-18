//BFS
//D:�Թ�����
#include<bits/stdc++.h>
#include<queue>
typedef long long LL;
using namespace std;
LL n,m;//��ͼ��ģn*m
int st_x,st_y,te_x,te_y;//��� and �յ�

char MAP[100][100]={0};
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0}; //�ĸ����������
struct node
{
    int x,y,step; //���꣬����
};

queue<node> q;
node temp;// �䵱��ͷ

bool flag= false; //����Ƿ����߳��Թ�
void bfs()
{
    q.push({st_x,st_y,0}); //���
    while(!q.empty()){
        temp=q.front();
        q.pop();  //temp��¼�˶�ͷ��pop��ͷ
        if(temp.x==te_x&&temp.y==te_y){ //�����յ�
            flag= true;
            cout<<temp.step<<endl;
            break;
        }

        if(MAP[temp.x][temp.y]=='.'||MAP[temp.x][temp.y]=='S'){// �������Ϸ�λ��
            MAP[temp.x][temp.y]='*';  //���Ϊ*�������Ѿ�����������һ�κ���
            for(int i=0;i<4;i++){ //����4������
                int tx=temp.x+dx[i];
                int ty=temp.y+dy[i];
                int t_step=temp.step+1;//����+1
                if(tx>=0 && tx<n && ty>=0 && ty<m && MAP[tx][ty]=='.'){//�Ϸ� ���
                    q.push({tx,ty,t_step});
                }
            }
        }
    }
    if(!flag){
        cout<<"-1"<<endl;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>MAP[i][j];
            if(MAP[i][j]=='S'){//��¼���
                st_x=i,st_y=j;
            }
            if(MAP[i][j]=='T'){//��¼�յ�
                te_x=i,te_y=j;
                MAP[i][j]='.';  //�Ѿ���¼���յ��ˣ��յ�ͬ��Ϊ.
            }
        }
    }

    bfs();
    return 0;
}


//DFS
//M:ȫ�������� �����ƿ�Ƭ���������⣩  A��n�����ӣ�n�ſ�Ƭ  ��һ��ģ��
/*#include<bits/stdc++.h>
using namespace std;
int n;
int a[10]={0}; //����
int used[10]={0}; //��� ��Ƭ�Ƿ񱻻���������  0:����������  1������������
void dfs(int step)
{
    if(step==n+1){ // ȫ�������Ѿ�����
         for(int i=1;i<=n;i++){  //������ӵĿ�Ƭ����
             cout<<setw(5)<<a[i];
         }
         cout<<endl;
          return ;//���ص��� ��һ�εݹ飬������������
    }

     for(int i=1;i<=n;i++){ //�����ӷſ�Ƭ
         if(used[i]==0){   //����������
            a[step]=i;  //���뿨Ƭ
             used[i]=1;   //��ǿ�Ƭ������������
             dfs(step+1);  //���õݹ� ������һ������
               used[i]=0;  // ������һ�����ӣ���ǿ��� ��ʾ�ûؿ�Ƭ
         }
     }
     return;  // �Ż���һ���ݹ飬���ǿ�Ƭ������0�� ����Ϊ��step��i=1��forѭ��return��used[i]��step+1����һ���ݹ飩��for���룬
              // used[i]=1 ����Ҳ����Ϊʲô������һ�����ӣ�������Ͷ��ͬһ������
}

int main()
{
     cin>>n;
       dfs(1); //�ӵ�һ�����ӿ�ʼ
    return 0;
}*/


/*#include<bits/stdc++.h>       �ڶ���ģ��
using namespace std;
int n;
int a[10]={0}; //����
int used[10]={0}; //��� ��Ƭ�Ƿ񱻻���������  0:����������  1������������
void dfs(int step)
{
    if(step==n+1){ // ȫ�������Ѿ�����
        for(int i=1;i<=n;i++){  //������ӵĿ�Ƭ����
            cout<<setw(5)<<a[i];
        }
        cout<<endl;
        return ;//���ص��� ��һ�εݹ飬������������
    }

    for(int i=1;i<=n;i++){ //�����ӷſ�Ƭ
        if(used[i]==0){   //����������
            a[step]=i;  //���뿨Ƭ
            used[i]=1;   //��ǿ�Ƭ������������
            if(step==n+1){
                for(int i=1;i<=n;i++){
                    cout<<setw(5)<<a[i];
                }
                cout<<endl;
            }
            else{
                dfs(step+1);  //���õݹ� ������һ������
            }
            used[i]=0;  // ������һ�����ӣ���ǿ��� ��ʾ�ûؿ�Ƭ
        }
    }
    // �Ż���һ���ݹ飬���ǿ�Ƭ������0�� ����Ϊ��step��i=1��forѭ��return��used[i]��step+1����һ���ݹ飩��for���룬
    // used[i]=1 ����Ҳ����Ϊʲô������һ�����ӣ�������Ͷ��ͬһ������
}

int main()
{
    cin>>n;
    dfs(1); //�ӵ�һ�����ӿ�ʼ
    return 0;
}*/

//T - ��ϵ����  DFS (Ҫ������Ԫ�ش�С����) ��n�����ӣ�r�ſ�Ƭ���⣩
/*#include<bits/stdc++.h>
using namespace std;
int n,r;
int a[100000];
int vis[100000];
void dfs(int step){
    if(step==r+1){
        for(int i=1;i<=r;i++){
            cout<<setw(3)<<a[i];
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(i>a[step-1]){
                a[step]=i;
                vis[i]=1;
                dfs(step+1);
                vis[i]=0;
            }

        }
    }
    //�����Ҫ���С����
//    for(int i=1;i<=n;i++){
//        if(vis[i]==0){
//            a[step]=i;
//            vis[i]=1;
//            dfs(step+1);
//            vis[i]=0;
//        }
//    }
}

int main()
{
    cin>>n>>r;
    dfs(1);
    return 0;
}*/

//AA�� �Թ���¼·������
/*#include<iostream>
#include<queue>

using namespace std;
int start_x = 0, start_y = 0, end_x = 4, end_y = 4;
int tx[] = {0, 0, -1, 1};
int ty[] = {1, -1, 0, 0};
int MAP[10][10];
int uesd[10][10] = {0};


struct nod {   //����ṹ�幦�ܾ��� ��¼·������
    int x, y, step;   //x,y�ʹ����� ��¼����һ�ε�·��
}path[10][10];

queue<nod> q;
nod temp;

void show_path(int x,int y) {
    if (x == 0 && y == 0)
        return;

    show_path(path[x][y].x, path[x][y].y);
    cout << "(" << path[x][y].x << ", " << path[x][y].y << ")" << endl;
}

void bfs() {
    q.push({start_x, start_y, 0});
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp.x == end_x && temp.y == end_y) {
            show_path(end_x,end_y);
            break;
        }

        for(int i = 0;i<4;i++){
            int dx = temp.x + tx[i];
            int dy = temp.y + ty[i];
            int d_step = temp.step + 1;
            if (dx >= 0 && dx < 5 && dy >= 0 && dy < 5&&MAP[dx][dy] == 0&&uesd[dx][dy] == 0 ) {
                path[dx][dy].x=temp.x;           //���жϱ߽磬��&&MAP[dx][dy]������������ң���ֹԽ��
                path[dx][dy].y=temp.y;
                q.push({dx, dy, d_step});//�Ѿ�����ˣ�����Ѿ����ʹ��ˣ�
                uesd[dx][dy] = 1;
            }
        }
//        if (MAP[temp.x][temp.y] == 0 && uesd[temp.x][temp.y] == 0) {
//            uesd[temp.x][temp.y] = 1;
//            for (int i = 0; i < 4; i++) {
//                int dx = temp.x + tx[i];
//                int dy = temp.y + ty[i];
//                int d_step = temp.step + 1;
//                if (dx >= 0 && dx < 5 && dy >= 0 && dy < 5&&MAP[dx][dy] == 0 ) {
//                    path[dx][dy].x=temp.x;
//                    path[dx][dy].y=temp.y;
//                    q.push({dx, dy, d_step});
//                }
//            }
//        }

    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> MAP[i][j];
        }
    }
    bfs();
    cout << "(4, 4)" << endl;
    return 0;
}*/


//B: �����DFS
/*#include<bits/stdc++.h>

using namespace std;
const int N = 30;
int n, m, sum = 0;
int start_x, start_y;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char a[N][N];

void dfs(int x, int y) {
    a[x][y] = '#';
    sum++;
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (tx >= 0 && tx < n && ty >= 0 && ty < m && a[tx][ty] == '.') {
            dfs(tx, ty);
        }

    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '@') {
                start_x = i, start_y = j; //���λ��
                break;
            }
        }
    }
    dfs(start_x, start_y);
    cout << sum;
    return 0;
}*/

//B: ����� BFS
/*#include<bits/stdc++.h>
#include<queue>

using namespace std;
const int N = 30;
char a[N][N];
int used[N][N];
int n, m, sum = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int start_x, start_y;
struct nod {
    int x, y;
};
queue<nod> q;
nod temp;

void BFS(int x, int y) {
    q.push({x, y});   //ͷ���
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = temp.x + dx[i];
            int ty = temp.y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && a[tx][ty] == '.' && used[tx][ty] == 0) {
                q.push({tx, ty});
                sum++;
                used[tx][ty] = 1;
            }
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '@') {
                start_x = i, start_y = j;
                 sum++;
                break;
            }
        }
    }
    BFS(start_x, start_y);
    cout << sum;
    return 0;
}*/


//A��Catch That Cow BFS  �е���̬�滮������BFS    ���������Ż��£������е㷱��
/*
#include<bits/stdc++.h>
#include<queue>

using namespace std;
const int N = 1e5 + 9;
int n, k;
int used[N];
struct nod {
    int path, sum;
};
queue<nod> q;
nod temp;

void bfs() {
    if(n==k){
        cout<<"0"<<endl;
        return;
    }
    q.push({n, 0});
    while (!q.empty()) {
        temp = q.front(); //��temp��ģ�����ֲ�ͬ�߷�
        //q.pop();

        temp.path--; //�����һ��
        temp.sum++;
        if (temp.path == k) {
            cout << temp.sum << endl;
            return;
        } else if (temp.path >= 0 && used[temp.path] == 0) {
            q.push({temp.path, temp.sum});
            used[temp.path] = 1;
        }

        temp = q.front();  //��Ҫ������
        temp.path++; //��ǰ��һ��
        temp.sum++;
        if (temp.path == k) {
            cout << temp.sum << endl;
            return;
        } else if (temp.path <= 100000 && used[temp.path] == 0) {
            q.push({temp.path, temp.sum});
            used[temp.path] = 1;
        }

        temp = q.front();
        temp.path *= 2; //��ǰ�� *2��
        temp.sum++;
        if (temp.path == k) {
            cout << temp.sum << endl;
            return;
        } else if (temp.path <= 100000 && used[temp.path] == 0) {
            q.push({temp.path, temp.sum});
            used[temp.path] = 1;
        }
        q.pop();
    }
}

int main() {
    cin >> n >> k;
    bfs();
    return 0;
}*/



//F - Find a way  �����㣬����յ㣬������㵽ͬ�����յ�����·������
// ��������ά���� �ֱ��¼�����˵�����KFC�Ĳ�����������BFS��
// Ȼ�����Ƚ�ÿ��KFC�������õ�ʱ�䣬�����С���Ǹ�KFC�Ĳ��� *11
/*#include<bits/stdc++.h>
#include<queue>
using namespace std;
const int N=209;
int n,m;
int start_Mx,start_My,start_Yx,start_Yy;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
char MAP[N][N];
int vis[N][N];
int result_Y[N][N]={0},result_M[N][N]={0}; //��¼�����ˣ���㣩���ﲻ���յ�Ĳ��� ��ʼ������0���٣���!0��˵���õ���һ���յ㣬����ֵ���ǲ���

struct nod{
    int x,y,step;
};
queue<nod> q;
nod temp;

void bfs(int x,int y,int result[][N],int step[][N]){
    memset(vis,0,sizeof(vis));   // !!! ע�⣺Ҫ��ÿһ��bfs֮ǰ��ʼ����������һ��ʹ��û��ʼ��
    q.push({x,y,0});
     while(!q.empty()){
         temp=q.front();
            q.pop();

             if(MAP[temp.x][temp.y]=='@'){
                 result[temp.x][temp.y]=temp.step; // ע���ʱ��û��return, ��Ϊ��ֹһ���յ�
             }

          for(int i=0;i<4;i++){
              int tx=temp.x+dx[i];
              int ty=temp.y+dy[i];
              int t_step=temp.step+1;
               if(tx>=0 && tx<n && ty>=0 && ty<m && (MAP[tx][ty]=='.'||MAP[tx][ty]=='@') && vis[tx][ty]==0){
                   q.push({tx,ty,t_step});
                    vis[tx][ty]=1;
               }
          }
     }
}
int main()
{
     while(cin>>n>>m){
         int MIN=1000000;
        for(int i=0;i<n;i++){
            cin>>MAP[i];
        }
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(MAP[i][j]=='Y'){
                     start_Yx=i,start_Yy=j;
                 }
                 if(MAP[i][j]=='M'){
                     start_Mx=i,start_My=j;
                 }
             }
         }

          bfs(start_Yx,start_Yy,result_Y,result_Y);
          bfs(start_Mx,start_My,result_M,result_M);

           for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   if(MIN>result_M[i][j]+result_Y[i][j] && result_M[i][j] && result_Y[i][j]){
                       MIN=result_M[i][j]+result_Y[i][j];
                   }
               }
           }
           MIN*=11;
            cout<<MIN<<endl;

         memset(result_Y,0,sizeof(result_Y));
         memset(result_M,0,sizeof(result_M));
     }
    return 0;
}*/


//H - Tempter of the Bone
//DFS�ֵ���ż��֦����   (��ȦȦ���յ�����)
/*#include<bits/stdc++.h>

using namespace std;
const int N = 10;
int n, m, t;
int start_x, start_y, end_x, end_y;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char MAP[N][N];

int dfs(int x, int y, int T) {
    if (T == 1) { //Ҫ�ߵ����һ����
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && tx == end_x && ty == end_y) { // Tʱ�����յ�
                return 1;
            }
            if (i == 3) {
                return 0; // ���һ����λ���޷����յ�
            }
        }
    } else {    //������
        MAP[x][y] = 'X';  //����Ѿ��߹�
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && MAP[tx][ty] == '.') {
                if (dfs(tx, ty, T - 1)) {
                    return 1;
                }
                MAP[tx][ty] = '.'; // !!! 1:������ݵ�λ�ã�MAP[tx][ty]='.'  �������ʾ����һ��������һ�����  ����1��2�ű�ʾһ���Ľ��
            }                      // ����ʱ�����߹������н��  !!!
        }
        // !!!  2:������ݵ�λ�ã�MAP[x][y]='.' �����ʾ�Ĵ˽��  �� ����1��2�ű�ʾһ���Ľ��
        return 0;  // !!! else����Ҫдreturn 0�� ��ֹΪ������������Ͳ������·���������ж���T���ڣ��Ƿ��ܵ����յ㣬�ᵽ�������������ս��.
    }
}

int main() {
    while (cin >> n >> m >> t && (n != 0 || m != 0 || t != 0)) {
        for (int i = 0; i < n; i++) {
            cin >> MAP[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (MAP[i][j] == 'S') {
                    start_x = i, start_y = j;
                }
                if (MAP[i][j] == 'D') {
                    end_x = i, end_y = j;
                    MAP[i][j] = '.';  //ͬ���յ�
                }
            }
        }
        if ((abs(start_x - end_x) + abs(start_y - end_y) - t) & 1) {  //���� �����ϣ��������ߵ��յ�
            cout << "NO" << endl;
        } else if (dfs(start_x, start_y, t)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}*/

//J - �����ĺ�˹̹��ţ Healthy Holsteins(DFS)  �����±�����
/*#include<bits/stdc++.h>

using namespace std;
const int N = 1009;
int a[N]; //ÿ������������
int b[N][N];//��ά����洢��������������
int c[N];
int ans[N];
int n, m, minn=1000000, sum = 0;

bool cheak(int x) { //�жϵ�ǰѡ�����������Ƿ����
    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = 1; j <= x; j++) {
            sum += b[c[j]][i];  //�б䣬�в���
        }
        if (sum < a[i]) { return false; }  //��һ�����ϲ���
    }
    return true;
}

void dfs(int t, int s) { //t:�������ڼ�������   s:ѡ�˵���������
    if (t > m) { //�߽�
        if (cheak(s)) { //�����ǣ�ѡ�˵����ϣ�������c[]���˵�
            if (minn > s) {  //��������minn��¼ѡ�˶�����
                minn = s;
                for (int i = 1; i <= minn; i++) {
                    ans[i] = c[i];
                }
            }
        }
        return; //!!! �������޵ݹ� ,���ڱ߽��˲����ж��˾�return����������һֱ�ݹ�
    }

    c[s + 1] = t;  //ѡ��S�֣�ÿ��ѡ�����ϴ�����  ���������ĿҪ������ࣩ
    dfs(t + 1, s + 1);
    c[s + 1] = 0;  //���� ���ӽڵ��ǵ�ǰ����һ����� s����һ��s+1
    dfs(t + 1, s); // ������һ��t��ͷ��ϵ���������
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a[i]; }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> b[i][j];
        }
    }
    dfs(1, 0);
    cout << minn<<" ";
    for (int i = 1; i <= minn; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}*/


//C - �������� DFS
/*#include<bits/stdc++.h>
using namespace std;
const int N=100;
char MAP[N][N];
int n,k,ans=0;
int b[N];//��ǵ�j�У��Ƿ�ռ�����
void dfs(int i,int s){ //i:���̵ĵ�i�У�s:���˶��ٸ�������
    if(s==k){ //�Ź���
        ans++;
        return;
    }
    if(i>n){return;} //�����������̵ı߽���

    for(int j=1;j<=n;j++){
        if(!b[j] && MAP[i][j]=='#'){ //j��û�б�ռ�죬����������λ��
            b[j]=1;
            dfs(i+1,s+1); //��һ�е���һ��(��Ϊ��b[j]������ƣ�������һ��)
            b[j]=0; //����
        }
    }
    dfs(i+1,s); //����һ���е���ʼλ�õ����
}
int main()
{
    while(cin>>n>>k&&(n!=-1||k!=-1)){
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>MAP[i][j];
            }
        }
        dfs(1,0);
        cout<<ans<<endl;
        memset(MAP,0,sizeof(MAP));
        memset(b,0,sizeof(b));
    }
    return 0;
}*/

//N - Lake Counting S (DFS)
/*#include<bits/stdc++.h>
using namespace std;
const int N=109;
char MAP[N][N];
int n,m,ans=0;

void dfs(int x,int y){
    MAP[x][y]='.';                            //ע���Ƿ��ʹ��˵�д��λ�� ���ڵ���ӽڵ�Ĵ���,д��������������õ���ʼλ�õĵ���㱻������
    for(int i=-1;i<=1;i++){                   //д����һ��dfs����Ļ�����������Ҫ��һ�����ʱ��
        for(int j=-1;j<=1;j++){
            int tx=x+i;
            int ty=y+j;
            if(tx>=1 && tx<=n && ty>=1 && ty<=m &&MAP[tx][ty]=='W'){
                dfs(tx,ty);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>MAP[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(MAP[i][j]=='W'){
                dfs(i,j);
                ans++;    //�������ͨ���ж��ٸ���������DFS����ans++
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}*/


//R - ��ս (DFS)
/*#include<bits/stdc++.h>
using namespace std;
const int N=1009;
char MAP[N][N];
int n,m,ans=0;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

bool cheak(int i,int j){              //�ж��Ƿ��ǹ�����״��������
    int c=0;
    if(MAP[i][j]=='#'){c++;}
    if(MAP[i][j+1]=='#'){c++;}
    if(MAP[i+1][j]=='#'){c++;}
    if(MAP[i+1][j+1]=='#'){c++;}
    if(c==3){
        return false;
    }
    return true;
}

void dfs(int x,int y){
    MAP[x][y]='.';
    for(int i=0;i<4;i++){      //�����Ǵ��±�0��ʼ��
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx>=1 && tx<=n && ty>=1 && ty<=m && MAP[tx][ty]=='#'){
            dfs(tx,ty);
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>MAP[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i<n && j<m && !cheak(i,j)){
                cout<<"Bad placement."<<endl;
                return 0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(MAP[i][j]=='#'){
                dfs(i,j);
                ans++;
            }
        }
    }

    cout<<"There are "<<ans<<" ships."<<endl;
    return 0;
}*/


// V - Dungeon Master (BFS��ά�Թ����⣬��һ������ά����)
/*#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 50;
char MAP[N][N][N];
int vis[N][N][N];
int z, x, y;
int flag = 0;
int start_z, start_x, start_y, end_z, end_x, end_y;
int dz[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1};

struct nod {
    int z, x, y, step;
};
queue<nod> q;
nod temp;

void bfs() {
    while(!q.empty()){                                         //  !!!�������룬Ҫ����һ�ζ�����գ������Ӱ����һ������
        q.pop();
    }

    q.push({start_z, start_x, start_y, 0});
    vis[start_z][start_x][start_y] = 1;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp.z == end_z && temp.x == end_x && temp.y == end_y) {
            flag = 1;
            cout << "Escaped in " << temp.step << " minute(s)." << endl;
            break;
        }

        for (int i = 0; i < 6; i++) {
            int tz = temp.z + dz[i];
            int tx = temp.x + dx[i];
            int ty = temp.y + dy[i];
            int t_step = temp.step + 1;
            if (tz >= 1 && tz <= z && tx >= 1 && tx <= x && ty >= 1 && ty <= y && MAP[tz][tx][ty] == '.' && vis[tz][tx][ty] == 0) {
                q.push({tz, tx, ty, t_step});
                vis[tz][tx][ty] = 1;
            }
        }
    }
}

int main() {
    while (cin >> z >> x >> y && !(z == 0 && x == 0 && y == 0)) {
        memset(vis, 0, sizeof(vis));
        memset(MAP, 0, sizeof(MAP));
        flag = 0;
        for (int i = 1; i <= z; i++) {
            for (int j = 1; j <= x; j++) {
                for (int t = 1; t <= y; t++) {
                    cin >> MAP[i][j][t];
                    if (MAP[i][j][t] == 'S') {
                        start_z = i, start_x = j, start_y = t;
                    }
                    if (MAP[i][j][t] == 'E') {
                        end_z = i, end_x = j, end_y = t;
                        MAP[i][j][t]='.';
                    }
                }
            }
        }
        bfs();
        if (flag == 0) {
            cout << "Trapped!" << endl;
        }

    }
    return 0;
}*/


//AE - Knight Moves (BFS�������߷�)
/*#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N = 309;
int vis[N][N];
int n, t;
int start_x, start_y, end_x, end_y; //����0Ϊ�߽翪ʼ��
int dx[] = {-1, -2, -2, -1, 1, 2, 1, 2};
int dy[] = {-2, -1, 1, 2, -2, -1, 2, 1};

struct nod {
    int x, y, step;
};

queue<nod> q;
nod temp;

void bfs(int x, int y) {
    while (!q.empty()) {
        q.pop();
    }

    memset(vis, 0, sizeof(vis));

    q.push({x, y, 0});
    vis[x][y] = 1;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp.x == end_x && temp.y == end_y) {

            cout << temp.step << endl;
            break;
        }

        for (int i = 0; i < 8; i++) {
            int tx = temp.x + dx[i];
            int ty = temp.y + dy[i];
            int t_step = temp.step + 1;
            if (tx >= 0 && tx < n && ty >= 0 && ty < n && vis[tx][ty] == 0) {
                q.push({tx, ty, t_step});
                vis[tx][ty] = 1;
            }
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> start_x >> start_y >> end_x >> end_y;
        bfs(start_x, start_y);
    }
    return 0;
}*/


//G - �����Թ� (DFS����¼��������)
/*#include<bits/stdc++.h>

using namespace std;
const int N = 109;
char MAP[N][N];
int ans[N][N];//ת�����
int dir[N][N];//ת�䷽��
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int m, n, k, t;
int start_x, start_y, end_x, end_y;

void dfs(int x, int y) {//x:�У�y:��

    if (x == end_x && y == end_y) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && MAP[tx][ty] != '*') {
            if (dir[x][y] != i + 1) { //ת�䣨��㵱����ת�䣬��ʼ��==0��
                if (ans[x][y] + 1 <= ans[tx][ty] && ans[x][y] + 1 <= k) {  //ת��ans[x][y]+1 һ��< ans[tx][ty] ��û�б����� �������޵ݹ�
                    ans[tx][ty] = ans[x][y] + 1;  //ת�����+1
                    dir[tx][ty] = i + 1;         //��¼ת������
                    dfs(tx,ty);
                }
            }
            else {//��ת��
                if (ans[x][y] <= ans[tx][ty] && ans[x][y]<= k) {    // !!!
                    ans[tx][ty] = ans[x][y];
                    dir[tx][ty] = i + 1;
                    dfs(tx,ty);
                }
            }
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        memset(dir,0,sizeof(dir));

        cin >> n >> m;//n��m�� (��)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> MAP[i][j];
            }
        }
        cin >> k >> start_y >> start_x >> end_y >> end_x;//��1��ʼ y���У�x���У�������

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = 9999;
            }
        }
        start_y-=1;
        start_x-=1;
        end_x-=1;
        end_y-=1;
        ans[start_x][start_y] = -1;    //���4�����򶼲���ת��
        dir[start_x][start_y] = 0;     //���
        MAP[start_x][start_y] = '*';
        dfs(start_x, start_y);

        if ((start_x == end_x && start_y == end_y) || ans[end_x][end_y] <= k) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}*/


//O - �˻ʺ� Checker Challenge (��������¼���)
/*#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,sum=0,ans=0;
int vis[N];//��
int fr[N];//x+y
int lr[N];//y-x+n
int result[N];//��¼��
bool cheak(int x,int y){//�У���
    if(vis[y] || fr[x+y] || lr[y-x+n]){
        return true; //��һ��λ�ñ�����
    }
    return false;
}


void print(){
    if(sum<=2){
        for(int i=1;i<=n;i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    sum++;
}

void dfs(int x){//��
    if(x==n+1){
        print();
        return;
    }

    for(int i=1;i<=n;i++){//i:��
        if(cheak(x,i)){
            continue;
        }
        result[x]=i; //��¼�ڼ��е����Ƕ���
        vis[i]=1;
        fr[x+i]=1;
        lr[i-x+n]=1;
        dfs(x+1);
        vis[i]=0;  //����
        fr[x+i]=0;
        lr[i-x+n]=0;
    }
}

int main()
{
    cin>>n;
    dfs(1);
    cout<<sum<<endl;
    return 0;
}*/
