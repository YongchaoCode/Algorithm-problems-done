//BFS
//D:迷宫问题
#include<bits/stdc++.h>
#include<queue>
typedef long long LL;
using namespace std;
LL n,m;//地图规模n*m
int st_x,st_y,te_x,te_y;//起点 and 终点

char MAP[100][100]={0};
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0}; //四个方向的搜索
struct node
{
    int x,y,step; //坐标，步数
};

queue<node> q;
node temp;// 充当队头

bool flag= false; //标记是否能走出迷宫
void bfs()
{
    q.push({st_x,st_y,0}); //入队
    while(!q.empty()){
        temp=q.front();
        q.pop();  //temp记录了队头，pop队头
        if(temp.x==te_x&&temp.y==te_y){ //到达终点
            flag= true;
            cout<<temp.step<<endl;
            break;
        }

        if(MAP[temp.x][temp.y]=='.'||MAP[temp.x][temp.y]=='S'){// 搜索到合法位置
            MAP[temp.x][temp.y]='*';  //标记为*，代表已经搜索过，下一次忽略
            for(int i=0;i<4;i++){ //搜索4个方向
                int tx=temp.x+dx[i];
                int ty=temp.y+dy[i];
                int t_step=temp.step+1;//步数+1
                if(tx>=0 && tx<n && ty>=0 && ty<m && MAP[tx][ty]=='.'){//合法 入队
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
            if(MAP[i][j]=='S'){//记录起点
                st_x=i,st_y=j;
            }
            if(MAP[i][j]=='T'){//记录终点
                te_x=i,te_y=j;
                MAP[i][j]='.';  //已经记录了终点了，终点同化为.
            }
        }
    }

    bfs();
    return 0;
}


//DFS
//M:全排列问题 （类似卡片放箱子问题）  A：n个箱子，n张卡片  第一种模板
/*#include<bits/stdc++.h>
using namespace std;
int n;
int a[10]={0}; //箱子
int used[10]={0}; //标记 卡片是否被还在手里面  0:代表在手里  1：代表在箱子
void dfs(int step)
{
    if(step==n+1){ // 全部箱子已经放完
         for(int i=1;i<=n;i++){  //输出箱子的卡片种类
             cout<<setw(5)<<a[i];
         }
         cout<<endl;
          return ;//返回的是 上一次递归，而不是主函数
    }

     for(int i=1;i<=n;i++){ //走箱子放卡片
         if(used[i]==0){   //卡牌在手上
            a[step]=i;  //放入卡片
             used[i]=1;   //标记卡片放在箱子里了
             dfs(step+1);  //利用递归 进入下一个箱子
               used[i]=0;  // 返回上一个箱子，标记卡牌 表示拿回卡片
         }
     }
     return;  // 放回上一个递归，但是卡片不会变回0了 ，因为是step的i=1，for循环return的used[i]从step+1（下一个递归）的for进入，
              // used[i]=1 ，这也就是为什么返回上一个箱子，不会再投入同一个卡牌
}

int main()
{
     cin>>n;
       dfs(1); //从第一个箱子开始
    return 0;
}*/


/*#include<bits/stdc++.h>       第二种模板
using namespace std;
int n;
int a[10]={0}; //箱子
int used[10]={0}; //标记 卡片是否被还在手里面  0:代表在手里  1：代表在箱子
void dfs(int step)
{
    if(step==n+1){ // 全部箱子已经放完
        for(int i=1;i<=n;i++){  //输出箱子的卡片种类
            cout<<setw(5)<<a[i];
        }
        cout<<endl;
        return ;//返回的是 上一次递归，而不是主函数
    }

    for(int i=1;i<=n;i++){ //走箱子放卡片
        if(used[i]==0){   //卡牌在手上
            a[step]=i;  //放入卡片
            used[i]=1;   //标记卡片放在箱子里了
            if(step==n+1){
                for(int i=1;i<=n;i++){
                    cout<<setw(5)<<a[i];
                }
                cout<<endl;
            }
            else{
                dfs(step+1);  //利用递归 进入下一个箱子
            }
            used[i]=0;  // 返回上一个箱子，标记卡牌 表示拿回卡片
        }
    }
    // 放回上一个递归，但是卡片不会变回0了 ，因为是step的i=1，for循环return的used[i]从step+1（下一个递归）的for进入，
    // used[i]=1 ，这也就是为什么返回上一个箱子，不会再投入同一个卡牌
}

int main()
{
    cin>>n;
    dfs(1); //从第一个箱子开始
    return 0;
}*/

//T - 组合的输出  DFS (要求排列元素从小到大) （n个箱子，r张卡片问题）
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
    //如果不要求从小到大：
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

//AA： 迷宫记录路径问题
/*#include<iostream>
#include<queue>

using namespace std;
int start_x = 0, start_y = 0, end_x = 4, end_y = 4;
int tx[] = {0, 0, -1, 1};
int ty[] = {1, -1, 0, 0};
int MAP[10][10];
int uesd[10][10] = {0};


struct nod {   //这个结构体功能就是 记录路径数据
    int x, y, step;   //x,y就代表了 记录的上一次的路径
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
                path[dx][dy].x=temp.x;           //先判断边界，再&&MAP[dx][dy]，程序从左往右，防止越界
                path[dx][dy].y=temp.y;
                q.push({dx, dy, d_step});//已经入队了，标记已经访问过了，
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


//B: 红与黑DFS
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
                start_x = i, start_y = j; //起点位置
                break;
            }
        }
    }
    dfs(start_x, start_y);
    cout << sum;
    return 0;
}*/

//B: 红与黑 BFS
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
    q.push({x, y});   //头入队
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


//A—Catch That Cow BFS  有点像动态规划，线性BFS    ！！！再优化下，代码有点繁琐
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
        temp = q.front(); //用temp来模拟三种不同走法
        //q.pop();

        temp.path--; //向后走一步
        temp.sum++;
        if (temp.path == k) {
            cout << temp.sum << endl;
            return;
        } else if (temp.path >= 0 && used[temp.path] == 0) {
            q.push({temp.path, temp.sum});
            used[temp.path] = 1;
        }

        temp = q.front();  //需要更新下
        temp.path++; //向前走一步
        temp.sum++;
        if (temp.path == k) {
            cout << temp.sum << endl;
            return;
        } else if (temp.path <= 100000 && used[temp.path] == 0) {
            q.push({temp.path, temp.sum});
            used[temp.path] = 1;
        }

        temp = q.front();
        temp.path *= 2; //向前走 *2步
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



//F - Find a way  多个起点，多个终点，求多个起点到同个中终点的最短路径问题
// 用两个二维数组 分别记录两个人到所有KFC的步数，用两次BFS，
// 然后最后比较每个KFC两个人用的时间，输出最小的那个KFC的步数 *11
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
int result_Y[N][N]={0},result_M[N][N]={0}; //记录两个人（起点）到达不用终点的步数 初始化都是0（假），!0则说明该点是一个终点，且数值就是步数

struct nod{
    int x,y,step;
};
queue<nod> q;
nod temp;

void bfs(int x,int y,int result[][N],int step[][N]){
    memset(vis,0,sizeof(vis));   // !!! 注意：要在每一次bfs之前初始化，避免下一次使用没初始化
    q.push({x,y,0});
     while(!q.empty()){
         temp=q.front();
            q.pop();

             if(MAP[temp.x][temp.y]=='@'){
                 result[temp.x][temp.y]=temp.step; // 注意此时并没有return, 因为不止一个终点
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
//DFS种的奇偶减枝问题   (绕圈圈到终点问题)
/*#include<bits/stdc++.h>

using namespace std;
const int N = 10;
int n, m, t;
int start_x, start_y, end_x, end_y;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char MAP[N][N];

int dfs(int x, int y, int T) {
    if (T == 1) { //要走到最后一步了
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && tx == end_x && ty == end_y) { // T时到达终点
                return 1;
            }
            if (i == 3) {
                return 0; // 最后一个方位都无法到终点
            }
        }
    } else {    //继续走
        MAP[x][y] = 'X';  //标记已经走过
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && MAP[tx][ty] == '.') {
                if (dfs(tx, ty, T - 1)) {
                    return 1;
                }
                MAP[tx][ty] = '.'; // !!! 1:这里回溯的位置：MAP[tx][ty]='.'  ，这里表示的上一个结点的下一个结点  这样1和2才表示一样的结点
            }                      // 回溯时回溯走过的所有结点  !!!
        }
        // !!!  2:这里回溯的位置：MAP[x][y]='.' 这里表示的此结点  ， 这样1和2才表示一样的结点
        return 0;  // !!! else里面要写return 0， 终止为真的条件根本就不是最短路径，而是判断在T步内，是否能到达终点，会到主函数给出最终结果.
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
                    MAP[i][j] = '.';  //同化终点
                }
            }
        }
        if ((abs(start_x - end_x) + abs(start_y - end_y) - t) & 1) {  //奇数 不符合，不可能走到终点
            cout << "NO" << endl;
        } else if (dfs(start_x, start_y, t)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}*/

//J - 健康的荷斯坦奶牛 Healthy Holsteins(DFS)  题解的下标问题
/*#include<bits/stdc++.h>

using namespace std;
const int N = 1009;
int a[N]; //每种饲料所需量
int b[N][N];//二维数组存储所有种类饲料量
int c[N];
int ans[N];
int n, m, minn=1000000, sum = 0;

bool cheak(int x) { //判断当前选的饲料种类是否符合
    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = 1; j <= x; j++) {
            sum += b[c[j]][i];  //行变，列不变
        }
        if (sum < a[i]) { return false; }  //有一种饲料不够
    }
    return true;
}

void dfs(int t, int s) { //t:搜索到第几种饲料   s:选了的饲料总量
    if (t > m) { //边界
        if (cheak(s)) { //参数是：选了的饲料，种类用c[]存了的
            if (minn > s) {  //符合则：用minn记录选了多少种
                minn = s;
                for (int i = 1; i <= minn; i++) {
                    ans[i] = c[i];
                }
            }
        }
        return; //!!! 否则无限递归 ,大于边界了并且判断了就return，不用下面一直递归
    }

    c[s + 1] = t;  //选了S种，每种选的饲料存起来  （很巧妙，题目要输出种类）
    dfs(t + 1, s + 1);
    c[s + 1] = 0;  //回溯 ，子节点是当前的下一个结点 s的下一个s+1
    dfs(t + 1, s); // 搜索下一个t开头组合的饲料种类
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


//C - 棋盘问题 DFS
/*#include<bits/stdc++.h>
using namespace std;
const int N=100;
char MAP[N][N];
int n,k,ans=0;
int b[N];//标记第j行，是否被占领过了
void dfs(int i,int s){ //i:棋盘的第i行，s:放了多少个棋子了
    if(s==k){ //放够了
        ans++;
        return;
    }
    if(i>n){return;} //行数大于棋盘的边界了

    for(int j=1;j<=n;j++){
        if(!b[j] && MAP[i][j]=='#'){ //j列没有被占领，并且是棋盘位置
            b[j]=1;
            dfs(i+1,s+1); //下一行的下一列(因为有b[j]标记限制，会走下一列)
            b[j]=0; //回溯
        }
    }
    dfs(i+1,s); //找下一个行的起始位置的组合
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
    MAP[x][y]='.';                            //注意标记访问过了的写的位置 主节点和子节点的次序,写到这里，主函数调用的起始位置的点就算被访问了
    for(int i=-1;i<=1;i++){                   //写在下一次dfs后面的话，主函数就要加一个访问标记
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
                ans++;    //算的是联通的有多少个，不能在DFS里面ans++
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}*/


//R - 海战 (DFS)
/*#include<bits/stdc++.h>
using namespace std;
const int N=1009;
char MAP[N][N];
int n,m,ans=0;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

bool cheak(int i,int j){              //判断是否是规则形状，很巧妙
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
    for(int i=0;i<4;i++){      //方向是从下标0开始的
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


// V - Dungeon Master (BFS三维迷宫问题，第一次用三维数组)
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
    while(!q.empty()){                                         //  !!!多组输入，要把上一次队列清空，否则会影响下一次数据
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


//AE - Knight Moves (BFS不规则走法)
/*#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N = 309;
int vis[N][N];
int n, t;
int start_x, start_y, end_x, end_y; //是以0为边界开始的
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


//G - 逃离迷宫 (DFS，记录方向问题)
/*#include<bits/stdc++.h>

using namespace std;
const int N = 109;
char MAP[N][N];
int ans[N][N];//转弯次数
int dir[N][N];//转弯方向
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int m, n, k, t;
int start_x, start_y, end_x, end_y;

void dfs(int x, int y) {//x:行，y:列

    if (x == end_x && y == end_y) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && MAP[tx][ty] != '*') {
            if (dir[x][y] != i + 1) { //转弯（起点当作是转弯，初始化==0）
                if (ans[x][y] + 1 <= ans[tx][ty] && ans[x][y] + 1 <= k) {  //转了ans[x][y]+1 一定< ans[tx][ty] 。没有被访问 避免无限递归
                    ans[tx][ty] = ans[x][y] + 1;  //转弯次数+1
                    dir[tx][ty] = i + 1;         //记录转弯来历
                    dfs(tx,ty);
                }
            }
            else {//不转弯
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

        cin >> n >> m;//n行m列 (反)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> MAP[i][j];
            }
        }
        cin >> k >> start_y >> start_x >> end_y >> end_x;//从1开始 y是列，x是行，（反）

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = 9999;
            }
        }
        start_y-=1;
        start_x-=1;
        end_x-=1;
        end_y-=1;
        ans[start_x][start_y] = -1;    //起点4个方向都不是转弯
        dir[start_x][start_y] = 0;     //起点
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


//O - 八皇后 Checker Challenge (如何巧妙记录结果)
/*#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,sum=0,ans=0;
int vis[N];//列
int fr[N];//x+y
int lr[N];//y-x+n
int result[N];//记录列
bool cheak(int x,int y){//行，列
    if(vis[y] || fr[x+y] || lr[y-x+n]){
        return true; //有一个位置被访问
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

void dfs(int x){//行
    if(x==n+1){
        print();
        return;
    }

    for(int i=1;i<=n;i++){//i:列
        if(cheak(x,i)){
            continue;
        }
        result[x]=i; //记录第几列的行是多少
        vis[i]=1;
        fr[x+i]=1;
        lr[i-x+n]=1;
        dfs(x+1);
        vis[i]=0;  //回溯
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
