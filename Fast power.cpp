//
// Created by 泳钞 on 2024/1/22.
//

//初学者快速幂(超时)
/*#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    LL base,power,p,result=1;
     cin>>base>>power>>p;
      for(int i=1;i<=power;i++){
          result*=base;
      }
       result%=p;
        cout<<result<<endl;
    return 0;
}*/

//快速幂：
/*
 * 1:  3^10 == 9^5 == 9^1 * 9^4 == 9^1 * 81^2 == 9^1 * 6561^1
 *     当指数为奇数的时候，result*=base(记录此时的底数)
 *  2: 运算规则：(a * b) % p = (a % p * b % p) % p
 *
 */
//题目：求A^B的最后三位数表示的整数。
//     说明：A^B的含义是“A的B次方”
/*#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    LL base,power,result=1;
     cin>>base>>power;
       while(power>0){
           if(power%2!=0){ //指数为奇数
               result=result*base%1000;
           }
            power/=2;
            base=base*base%1000;
       }
        cout<<result<<endl;
    return 0;
}*/


//A - 快速幂
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll base,power,p,result=1;
      cin>>base>>power>>p;//a==2,b==10 2^10==1024
       ll a=base,b=power;
        while(power>0){
            if(power%2!=0){
                result=result*base%p;
            }
             power=power/2;
              base=base*base%p;
        }
          cout<<a<<"^"<<b<<" mod "<<p<<"="<<result<<endl;
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=998244352;
ll arr_power[5000009];
int main()
{

    ll base,n;
      cin>>base>>n;
     for(int i=0;i<n;i++){
         cin>>arr_power[i];
     }

       for(int i=0;i<n;i++){
           ll base_=base;
           ll result=1;
           ll power=arr_power[i];
            while(power>0){
                if(power&1){
                    result= result*base_%p;
                }
                 power>>=1;
                  base_=base_*base_%p;
            }
             cout<<result<<" ";
       }
    return 0;
}*/


//矩形阵快速幂
/*#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
ll n,k;
struct Matrix{
    ll c[101][101];
}A,I;

Matrix operator*(const Matrix &x,const Matrix &y){
    Matrix a;//记录结果
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a.c[i][j]=0;  //每次*重置
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int t=1;t<=n;t++){
                a.c[i][j]+=x.c[i][t]*y.c[t][j]%mod;
                a.c[i][j]%=mod;
            }
        }
    }
    return a;
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>A.c[i][j];//A.c：初始矩阵
        }
    }
    for(int i=1;i<=n;i++){
        I.c[i][i]=1;  //I.c:单位矩阵
    }
    while(k>0){
        if(k&1){
            I=I*A;//重载*
        }
        A=A*A;
        k>>=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<I.c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/



//斐波拉契数列（矩阵快速幂）
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
struct Matrix {
    ll ma[2][2];
};

Matrix operator*(Matrix &x, Matrix &y) {//重载*
    Matrix C;//记录答案
    memset(C.ma, 0, sizeof(C.ma));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C.ma[i][j] = (C.ma[i][j] + x.ma[i][k] * y.ma[k][j]) % mod;
            }
        }
    }
    return C;
}

Matrix q_pow(Matrix A, ll n) {
    Matrix B;
    B.ma[0][1] = B.ma[1][0] = 0;
    B.ma[0][0] = B.ma[1][1] = 1;//初始化M矩阵
    while (n > 0) {
        if (n & 1) {
            B = A * B; //重载*
        }
        A = A * A;
        n >>= 1;
    }
    return B;
}

int main() {
    ll n;
    cin >> n;
    Matrix A;
    A.ma[0][0] = 1, A.ma[0][1] = 1;
    A.ma[1][0] = 1, A.ma[1][1] = 0;
    Matrix ans = q_pow(A, n);
    cout << ans.ma[0][1] << endl;
    return 0;
}