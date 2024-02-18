//
// Created by 泳钞 on 2024/2/8.
//


//1：线性DP（洛谷：B3637，最长上升子序列）
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int main()
{
    int n,arr[N+1],dp[N+1],Maxlength=1;
     cin>>n;
      for(int i=1;i<=n;i++){
          cin>>arr[i];
           dp[i]=1;
      }

       for(int i=1;i<=n;i++){
           for(int j=1;j<i;j++){
               if(arr[i]>arr[j]){//记忆每一个数字对于前面序列的最长上升单调的长度
                   dp[i]=max(dp[i],dp[j]+1);//记忆：error：dp[i]=dp[j]+1; 求最长长度，eg：1 2（dp[2]） 1(dp[1]) 3 :3是对于1 2 3，而不是1 3
                   Maxlength=max(dp[i],Maxlength);
               }
           }
       }
       cout<<Maxlength<<endl;
    return 0;
}*/



//最长有效括号
/*#include<bits/stdc++.h>
using namespace std;
const int N=3e4+9;
int main()
{
    int dp[N]={0},Max=0;
    string s;
     cin>>s;
       for(int i=1;i<s.size();i++){
           if(s[i]==')') {
               if (s[i - 1] == '('){
                   dp[i]=(i>=2? dp[i-2]: 0)+2;
               }
               else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='('){
                   dp[i]+=dp[i-1]+(i-dp[i-1]>=2 ? dp[i-dp[i-1]-2] : 0)+2;
               }
           }
            Max=max(Max,dp[i]);
       }
        cout<<Max<<endl;
    return 0;
}*/



//最长有效括号（，[
/*#include<bits/stdc++.h>
using namespace std;
const int N=1000006;
string s;
int dp[N],Max=0;
int main()
{
    cin>>s;
    for(int i=1;i<s.size();i++){
        if(s[i]==')'){
            if(s[i-1]=='('){
                dp[i]=(i>=2? dp[i-2]:0)+2;
            }
            else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='('){
                dp[i]+=dp[i-1]+(i-dp[i-1]>=2? dp[i-dp[i-1]-2] :0)+2;
            }
        }
        if(s[i]==']'){
            if(s[i-1]=='['){
                dp[i]=(i>=2? dp[i-2]: 0)+2;
            }
            else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='['){
                dp[i]+=dp[i-1]+(i-dp[i-1]>=2? dp[i-dp[i-1]-2] :0)+2;
            }
        }
        Max=max(Max,dp[i]);
    }
    for(int i=0;i<s.size();i++){
        if(dp[i]==Max){
            for(int j=i-Max+1;j<=i;j++){
                cout<<s[j];
            }
            break;
        }
    }
    return 0;
}*/