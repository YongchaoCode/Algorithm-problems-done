//
// Created by 泳钞 on 2024/1/24.
//


//埃氏筛法
/*#include<bits/stdc++.h>
using namespace std;
const int n=1e5;
typedef long long ll;
int main()
{
    ll pri[n+9]={0};  //0:素数 1:合数
    ll N=n,cnt=0;       //找出1~1e7所有的素数
     for(ll i=2;i<=N/i;i++){
         if(!pri[i]){//i是素数，则素数的所有倍数都是合数
             for(ll j=i*i;j<=N;j+=i) {pri[j]=1;}
         }
     }
      for(ll i=2;i<=N;i++) {
          if (pri[i] == 0) { cnt++; } //范围内素数的个数
      }
          cout<<cnt<<endl;
    return 0;
}*/

//欧拉算法  流程？
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int pri[N+1],primes[N];//素数标记（0代表素数，1代表非素数）,存素数
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,cnt=0;
    for(int i=2;i<=N;i++){
        if(!pri[i]){//是素数0
            primes[++cnt]=i;//存储素数
        }
        for(int j=1;primes[j]<=N/i;j++){
            pri[primes[j]*i]=1;//标记非素数1
            if(i%primes[j]==0){//可约
                break;
            }
        }
    }
    return 0;
}*/


//分解质因数
//定义：每个合数都可以写成几个质数相乘的形式，其中每个质数都是这个合数的因数，把一个合数用质因数相乘的形式表示出来，叫做分解质因数，
// 也叫做分解质因子。如30=2×3×5 。分解质因数只针对合数
//分解质因数只针对合数。（分解质因数也称分解素因数）求一个数分解质因数，要从最小的质数除起，一直除到结果为质数为止。分解质因数的算式叫短除法，
// 和除法的性质相似，还可以用来求多个数的公因式。

//x有多少个不同的素因子？
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll x,ans=0;
     cin>>x;
       for(int i=2;i<=x/i;i++){
           if(x%i==0){
               while(x%i==0){
                   x/=i;
               }
                ans++;
           }
       }
        if(x>1){ans++;}
          cout<<ans<<endl;
    return 0;
}