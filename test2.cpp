//堆，二叉堆，优先队列（本质：堆）

//堆（洛谷）
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     priority_queue<int>q;
      int n,op,x;
       cin>>n;
        for(int i=1;i<=n;i++){
            cin>>op;
             if(op==1){
               cin>>x;
                q.push(-x);
             }
             else if(op==2){
               cout<<-(q.top())<<'\n';
             }
             else{
                q.pop();
             }
        }
    return 0;
}*/


//堆（洛谷）二叉堆（小根堆）
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int heap[N];
int n,op,s=0;//size:树的高度

void up(int &i,int val){
   while(i>1 && heap[i/2]>val){//不满足小根堆
       heap[i]=heap[i/2];
       i/=2;
   }
}

void down(int &i,int val){// !!!
    int x=i*2;
     while(x<=s){
         if(x+1<=s && heap[x+1]<heap[x]){
             x++;
         }
          if(val<=heap[x]){
              break;
          }
          heap[i]=heap[x];
           i=x;
           x*=2;
     }
}

void insert(int val){//插入
   int i=++s;
     up(i,val);
     heap[i]=val;
}

void delete_min(){
    int i=1;
    int val=heap[s--];
     down(i,val);
     heap[i]=val;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int x;
     cin>>n;
      while(n--){
          cin>>op;
           if(op==1){//插入，建堆
               cin>>x;
               insert(x);
           }
           else if(op==2){//输出最小值
               cout<<heap[1]<<'\n';
           }
           else if(op==3){//删除最小值
              delete_min();
           }
      }
    return 0;
}*/


//合并果子（洛谷） 优先队列
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>>q;
     int n,num,ans=0;
      cin>>n;
       while(n--){
          cin>>num;
           q.push(num);
       }
         while(q.size()>=2){
             int a=q.top();
              q.pop();
             int b=q.top();
              q.pop();
               ans+=(a+b);
               q.push(a+b);
         }
          cout<<ans<<endl;
    return 0;
}*/