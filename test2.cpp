//�������У�����ջ����������

//1:����������ȣ�
//����ʵ�ֵ�������
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
struct nod{
    int last,next;
}l[N];
int main()
{
    int t,nxt,op,x,y;
    cin>>t;
    for(int i=1;i<=N;i++){
        l[i].next=0;
    }
    while(t--){
        cin>>op;
        if(op==1){
            cin>>x>>y;
            nxt=l[x].next;
            l[x].next=y;
            l[y].next=nxt;
        }
        else{
            cin>>x;
            if(op==2){
                cout<<l[x].next<<endl;
            }
            else{
                nxt=l[x].next;
                l[x].next=l[nxt].next;
            }
        }
    }
    return 0;
}*/

//2:˫������
//���а��ţ���ȣ�
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int vis[N];
struct nod{
   int last,next;
}l[N];

int main()
{
     for(int i=1;i<=N;i++){
         l[i].next=0,l[i].last=0;
     }
     l[0].next=1;
     l[1].last=0;
     vis[1]=1;
    int n,k,p,nxt,lst;
     cin>>n;
      for(int i=2;i<=n;i++){
          vis[i]=1;
          cin>>k>>p;//p0:k��ߣ�p1:k�ұ�
          nxt=l[k].next,lst=l[k].last;
           if(p==0){
               l[lst].next=i;
               l[k].last=i;
               l[i].last=lst;
               l[i].next=k;
           }
           else{
               l[k].next=i;
               l[i].last=k;
               l[i].next=nxt;
               l[nxt].last=i;
           }
      }
      int m,op;
       cin>>m;
        for(int i=1;i<=m;i++){
             cin>>op;
              if(!vis[op]){//0û�������||��ɾ����
                  continue;
              }
              vis[op]=0;
               lst=l[op].last,nxt=l[op].next;
                l[lst].next=nxt;
                l[nxt].last=lst;
        }
         int now=0;
         while(l[now].next!=0){
             cout<<l[now].next<<" ";
             now=l[now].next;
         }
    return 0;
}*/



//TLE !!! ������ڶ�λ������λ����ҪO(n)����ǳ���ʱ�����������Ҫ�� map������λ
//3:Insert or Erase
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e9+9;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    list<int>l;
     int n,q,op,x,y;
      cin>>n;
       for(int i=1;i<=n;i++){
           int num;
            cin>>num;
             l.push_back(num);
       }
         cin>>q;
        for(int i=1;i<=q;i++){
            cin>>op;
             if(op==1){
                 cin>>x>>y;
                  auto pos=find(l.begin(),l.end(),x);
                  l.insert(++pos,y);
             }
             else{
                cin>>x;
                 auto pos=find(l.begin(),l.end(),x);
                 l.erase(pos);
             }
        }
         for(auto a:l){
             cout<<a<<" ";
         }
    return 0;
}*/
//Insert or Erase
//mapά������λ(map����ʵ������)
/*#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
map<int,int>last,nxt;//key,value
int main()
{
    int a,n,q,op,x,y;
    cin>>n;
    for(int i=1,temp=-1;i<=n;i++){
        cin>>a;
        last[a]=temp,nxt[temp]=a;
        temp=a;//temp������һ��
        if(i==n){
            nxt[a]=-1;
        }
    }
    cin>>q;
    while(q--){
        cin>>op;
        if(op==1){//errror
            cin>>x>>y;
             last[y]=x;
             nxt[y]=nxt[x];
             last[nxt[x]]=y;
             nxt[x]=y;
        }
        else{
            cin>>x;
            nxt[last[x]]=nxt[x];
            last[nxt[x]]=last[x];
        }
    }
    int cnt=-1;
    while(nxt[cnt]!=-1){
        cout<<nxt[cnt]<<" ";
        cnt=nxt[cnt];
    }
    return 0;
}*/

//Look Up S����ȣ�����ջ
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int a[N],q[N],ans[N],top=0;
int main()
{
    int n;
     cin>>n;
      for(int i=1;i<=n;i++){
          cin>>a[i];
      }
        for(int i=1;i<=n;i++){
            while(top>0 && a[i]>a[q[top]]){
                ans[q[top]]=i;
                top--;
            }
             q[++top]=i;
        }
         for(int i=1;i<=n;i++){
             cout<<ans[i]<<endl;
         }
    return 0;
}*/


//�������ڣ���ȣ���������
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int a[N],q[N];
int h,t,n,k;

void min_q(){
    h=1,t=0;//�ն���
     for(int i=1;i<=n;i++){
         while(t>=h && a[i]<=a[q[t]]){//q������±�
             t--;
         }
            q[++t]=i;
          if(i-k+1>q[h]){//ά�����ڳ���
              h++;
          }
           if(i>=k){
               cout<<a[q[h]]<<" ";
           }
     }
      cout<<endl;
}

void max_q(){
    h=1,t=0;
     for(int i=1;i<=n;i++){
         while(t>=h && a[i]>=a[q[t]]){
             t--;
         }
          q[++t]=i;
         if(i-k+1>q[h]){
             h++;
         }
          if(i>=k){
              cout<<a[q[h]]<<" ";
          }
     }
}

int main()
{
     cin>>n>>k;
      for(int i=1;i<=n;i++){ cin>>a[i]; }
         min_q();
         max_q();
    return 0;
}*/