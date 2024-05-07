//树状数组，线段树，ST表,逆序对（树状数组+离散数学，归并排序也可实现）

//树状数组：支持单点修改，区间查询，lowbit。空间O(n),时间O(logn)
//树状数组1（洛谷）
//重要性质：
/* 1：lowbit(x):x二进制最后一个1的位置，的十进制的数字。eg：lowbit(1000110)==10 (2)
 * 2：序号为i的序列 正好就是 长度为lowbit(i) 且 以i结尾的序列
 * 3：序列b[i]正上方的序列，正好就是 b[lowbit(i)+i]
 */
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

//逆序对：树状数组
//所谓的离散数学知识。更加充分了理解树状树状的知识
/*#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
int tree[N],t[N];
int n,ans=0;

struct nod{
    int val,order;
}a[N];

bool cmp(nod x,nod y){
    if(x.val==y.val){return x.order<y.order;}//元素相同，位序不变
    return x.val<y.val;
}

int lowbit(int x){return x & (-x);}

void update(int x,int k){
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
}

int get_sum(int x){
    int sum=0;
    while(x>0){
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;
        a[i].order=i;
    }
    sort(a+1,a+1+n,cmp);

    for(int i=1;i<=n;i++){//a[]:递增排序
        t[a[i].order]=i;//t[i]:第i小的下标是t[i]
    }

    for(int i=n;i>=1;i--){//数字大的先入
        update(t[i],1);
        ans+=get_sum(t[i]-1);
    }
    cout<<ans<<'\n';
    return 0;
}*/

//线段树:O(logn)实现单点修改、区间修改、区间查询（区间求和，求区间最大值，求区间最小值）等操作。
//建树build()->区间修改update()，lazy标记->区间查询getsum()
/*#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
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

void update(int l,int r,int c,int s,int t,int p){//[l,r]为修改区间,c为被修改的元素的变化量,[s,t]为当前节点包含的区间,p为当前节点的编号
     if(l<=s && t<=r){
         tree[p]+=(t-s+1)*c,b[p]+=c;
         return;
     }
    int m=(s+t)/2;
     if(b[p]&&s!=t){//有lazy标记
         tree[2*p]+=b[p]*(m-s+1),tree[2*p+1]+=b[p]*(t-m);
          b[2*p]+=b[p],b[2*p+1]+=b[p];//下传lazy标记
          b[p]=0;
     }
     if(l<=m) update(l,r,c,s,m,2*p);//画个交集图就懂了:[1,m[l ] [ r]m+1,4]
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
               cin>>x>>y;
               int sum=getsum(x,y,1,n,1);
                cout<<sum<<endl;
            }
      }
    return 0;
}*/


//ST表：预处理时间，空间复杂度O(nlogn)，查询O(1)
//无法单点修改
//板子题P3865（洛谷）
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int st_max[N][20];

int query(int l,int r){
    int k=log2(r-l+1);
     return max(st_max[l][k],st_max[r-(1<<k)+1][k]);
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,l,r;
     cin>>n>>m;
      for(int i=1;i<=n;i++){
          cin>>st_max[i][0];
      }
       int k=log2(n);
       for(int j=1;j<=k;j++){
           int R=n-(1<<j)+1;
            for(int i=1;i<=R;i++){
                st_max[i][j]=max(st_max[i][j-1], st_max[i+(1<<(j-1))][j-1]);
            }
       }

        while(m--){
            cin>>l>>r;
             cout<<query(l,r)<<'\n';
        }
    return 0;
}*/