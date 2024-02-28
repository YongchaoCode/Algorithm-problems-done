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




//time:24/02/27
//以下是代码随想录的讲解题
//leetcode:64题
//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//说明：每次只能向下或者向右移动一步。
//INPUT:
//[1,3,1]
//[1,5,1]
//[4,2,1]
//OUTPUT:
//7 (1->3->1->1->1)
/* 1:dp定义：dp[i][j]：走到map[i][j]的路径最小值
 * 2:状态转移方程：dp[i][j]=min(dp[i][j-1],dp[i-1][j])+Map[i][j]
 * 3:初始化：dp[0][0]=map[0][0]
 *         最上面一层：dp[0][i]=dp[0][i-1]+Map[0][i]：只能一直往右边走
 *         最左边的一列：dp[j][0]=dp[j-1][0]+Map[j][0];:只能一直往下走
 * */
/*#include<bits/stdc++.h>
using namespace std;
int Map[999][999];
int dp[999][999];
int main()
{
    int m,n;
     cin>>m>>n;
      for(int i=0;i<n;i++){//地图下标从0开始n行m列
          for(int j=0;j<m;j++){
              cin>>Map[i][j];
          }
      }

        dp[0][0]=Map[0][0];
        for(int i=1;i<m;i++){//初始化上面一层
            dp[0][i]=dp[0][i-1]+Map[0][i];
        }
        for(int j=1;j<n;j++){//初始化最左边一列
            dp[j][0]=dp[j-1][0]+Map[j][0];
        }

         for(int i=1;i<n;i++){
             for(int j=1;j<m;j++){
                 dp[i][j]=min(dp[i][j-1],dp[i-1][j])+Map[i][j];
             }
         }
          cout<<dp[n-1][m-1]<<endl;
    return 0;
}*/


//代码随想录讲解1：
//leetcode:两个字符串的删除操作
//题意：求出使两个字符串相同的最少删除次数（一次删除一个字符串的一个元素）
//     word1:sea
//     word2:eat
//最终： 2次 ea
/* 1：dp定义：dp[i][j]:以 i-1结尾 的word1和 以j-1结尾 的word2 相同的 最少删除次数
 * 2：状态转移方程:
 *   if(word1[i-1]==word2[j-1]){//word1的i-1元素==word2的i-1元素
 *       dp[i][j]=dp[i-1][j-1];//不用进行删除操作
 *   }
 *   else{//不相同，要进行删除操作
 *     dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+2);//分别是word1删除，word2删除，word1，2都删除
 *   }
 * 3：初始化：dp[i][j]推导来源于上一个，前一个，左上角
 *   所以初始化第一行，第一列
 *    第一行：dp[0][j]=j;（[0]代表word1长度==0时，要word2==word1，word2得删除自身的长度j）
 *    第一列：dp[i][0]=i;（同理）
 * 4：遍历顺序：左->右，上->下
 * */
/*#include<bits/stdc++.h>
using namespace std;
int dp[999][999];//[len1][len2]
int main()
{
    string word1,word2;
      cin>>word1>>word2;
       for(int j=0;j<=word2.size();j++){//初始化第一行：word2的删除操作!!!初始化要=到，dp会递推到=的
           dp[0][j]=j;
       }
       for(int i=0;i<=word1.size();i++){//初始化第一列：word1的删除操作
           dp[i][0]=i;
       }

        for(int i=1;i<=word1.size();i++){//1：i从1开始：0的位置已经初始化好了。2：i<=:dp[i][]是从word1的i-1结尾的
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){//error???
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+2});
                }
            }
        }
         cout<<dp[word1.size()][word2.size()]<<endl;
    return 0;
}*/


//代码随想录2：
//leetcode:编辑距离
//使word1删除，替换，插入元素的三种操作后==word2
//求操作的最小次数,一次操作算一次
/* 1：dp数组定义：dp[i][j]:以 i-1结尾 的word1和 以j-1结尾 的word2 相同的 最少操作次数
 * 2：状态转移方程：
 *   if(word1[i-1]==word2[j-1]){
 *      dp[i][j]=dp[i-1][j-1];
 *   }
 *   else{
 *    dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);//分别代表word1删除，添加，插入的三种操作：
 *   }      //a：添加（逆序思想）：看起来是word2的删除操作。word2的删除可以看成word1的添加，因为二者最后带来的操作次数都是相同的
 *          //b：插入：先看if成立条件：当word1的i-1结尾和word2的j-1结尾的元素相同的时候,dp[i][j]=dp[i-1][j-1],
 *          //        所以插入达到相同的状态就是dp[i-1][j-1]，只不过操作数+1。
 * 3:：初始化：dp[i][j]推导来源于上一个，前一个，左上角
 *     所以初始化第一行，第一列
 *     第一行：dp[0][j]=j;（[0]代表word1长度==0时，要word2==word1，word2得删除自身的长度j）
 *     第一列：dp[i][0]=i;（同理）
 * 4：遍历顺序：左->右，上->下
 * */
/*#include<bits/stdc++.h>
using namespace std;
int dp[2009][2009];
int main()
{
     string word1,word2;
      cin>>word1>>word2;
       for(int j=0;j<=word2.size();j++){//初始化第一行
           dp[0][j]=j;
       }
       for(int i=0;i<=word1.size();i++){//初始化第一列
        dp[i][0]=i;
       }

        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));
                }
            }
        }
         cout<<dp[word1.size()][word2.size()]<<endl;
    return 0;
}*/

//代码随想录：leetcode:最长重复子数组(连续的子序列)
/* 1：dp定义：dp[i][j]：以i-1结尾的num1和以j-1结尾的num2的最长连续子序列的长度
 * 2：状态转移方程：
 *     if(num1[i-1]==num2[j-1]){//！！！相等的时候都倒退一个元素+1，这样才能保证是连续的子序列
 *       dp[i][j]=dp[i-1][j-1]; //             实在不懂就画图
 *     }
 * 3:初始化：推导来源于左上角，第一行，第一列要初始化0
 * 4：遍历方向：for1:i for2:j=0;j<i
 * 5:结果!=dp[num1.size()][num2.size()]，要用Max记录下
 * */
/*#include<bits/stdc++.h>
using namespace std;
int dp[1009][1009],num1[1009],num2[1009];
int main()
{
     int n1,n2,Max=0;
      cin>>n1>>n2;
       for(int i=0;i<n1;i++){
           cin>>num1[i];
       }
       for(int i=0;i<n2;i++){
           cin>>num2[i];
       }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(num1[i-1]==num2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                Max=max(dp[i][j],Max);
            }
        }
         cout<<Max<<endl;
    return 0;
}*/

//代码随想录：leetcode:最长公共子序列（不用连续）
/* 1:dp定义：dp[i][j]:以i-1结尾的word1和以j-1结尾的word2的最长连续子序列数
 * 2:状态转移方程:
 *     if(word1[i-1]==word[j-1]){
 *       dp[i][j]=dp[i-1][j-1]=1;
 *     }
 *     else{//既然不相同，那就不考虑其中一个word的那个元素
 *       dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
 *     }
 * 3:初始化；第一行=0，第一列=0
 * 4:遍历顺序：for1:左->右，for2:左->右
 * */

/*
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1009][1009]={0};
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};*/