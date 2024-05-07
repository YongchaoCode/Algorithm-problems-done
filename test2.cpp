//��״���飬�߶�����ST��,����ԣ���״����+��ɢ��ѧ���鲢����Ҳ��ʵ�֣�

//��״���飺֧�ֵ����޸ģ������ѯ��lowbit���ռ�O(n),ʱ��O(logn)
//��״����1����ȣ�
//��Ҫ���ʣ�
/* 1��lowbit(x):x���������һ��1��λ�ã���ʮ���Ƶ����֡�eg��lowbit(1000110)==10 (2)
 * 2�����Ϊi������ ���þ��� ����Ϊlowbit(i) �� ��i��β������
 * 3������b[i]���Ϸ������У����þ��� b[lowbit(i)+i]
 */
/*#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int n,m;
int tree[N];

int lowbit(int k){
   return k & (-k);
}

void add(int x,int k){//b[i]�����ϣ�== b[i+lowbit]
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
            add(i,a);//ԭʼtree����
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

//����ԣ���״����
//��ν����ɢ��ѧ֪ʶ�����ӳ���������״��״��֪ʶ
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
    if(x.val==y.val){return x.order<y.order;}//Ԫ����ͬ��λ�򲻱�
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

    for(int i=1;i<=n;i++){//a[]:��������
        t[a[i].order]=i;//t[i]:��iС���±���t[i]
    }

    for(int i=n;i>=1;i--){//���ִ������
        update(t[i],1);
        ans+=get_sum(t[i]-1);
    }
    cout<<ans<<'\n';
    return 0;
}*/

//�߶���:O(logn)ʵ�ֵ����޸ġ������޸ġ������ѯ��������ͣ����������ֵ����������Сֵ���Ȳ�����
//����build()->�����޸�update()��lazy���->�����ѯgetsum()
/*#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int arr[N],tree[4*N];
int b[4*N];//lazy���

void build(int s,int t,int p){//�� [s,t] ���佨���߶���,��ǰ���ı��Ϊ p
     if(s==t){//Ҷ��
         tree[p]=arr[s];
         return;
     }
    int m=(s+t)/2;//���Ż�
     build(s,m,2*p),build(m+1,t,2*p+1);
      tree[p]=tree[2*p]+tree[2*p+1];
}

void update(int l,int r,int c,int s,int t,int p){//[l,r]Ϊ�޸�����,cΪ���޸ĵ�Ԫ�صı仯��,[s,t]Ϊ��ǰ�ڵ����������,pΪ��ǰ�ڵ�ı��
     if(l<=s && t<=r){
         tree[p]+=(t-s+1)*c,b[p]+=c;
         return;
     }
    int m=(s+t)/2;
     if(b[p]&&s!=t){//��lazy���
         tree[2*p]+=b[p]*(m-s+1),tree[2*p+1]+=b[p]*(t-m);
          b[2*p]+=b[p],b[2*p+1]+=b[p];//�´�lazy���
          b[p]=0;
     }
     if(l<=m) update(l,r,c,s,m,2*p);//��������ͼ�Ͷ���:[1,m[l ] [ r]m+1,4]
     if(r>m)  update(l,r,c,m+1,t,2*p+1);
      tree[p]=tree[2*p]+tree[2*p+1];
}

int getsum(int l,int r,int s,int t,int p){//[l,r]Ϊ��ѯ����,[s,t]Ϊ��ǰ�ڵ����������,pΪ��ǰ�ڵ�ı��
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
         build(1,n,1);//���ڵ��ţ�1
      for(int i=1;i<=m;i++){
          int op,x,y,k;
           cin>>op;
            if(op==1){//�����޸�
               cin>>x>>y>>k;
                update(x,y,k,1,n,1);
            }
            else if(op==2){//�����ѯ�������ѯ��
               cin>>x>>y;
               int sum=getsum(x,y,1,n,1);
                cout<<sum<<endl;
            }
      }
    return 0;
}*/


//ST��Ԥ����ʱ�䣬�ռ临�Ӷ�O(nlogn)����ѯO(1)
//�޷������޸�
//������P3865����ȣ�
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