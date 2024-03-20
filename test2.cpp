//manacher算法：（还有一个二分+哈希算法，后面学习下）
/*#include<bits/stdc++.h>
using namespace std;
const int N=31000005;
int d[N];//盒子
char a[N];
char s1[N];
int manacher(char s[]){//n:新串的长度
    int Max=0;
    d[1]=1;
    int l,r=1;//盒子边界
    int n=strlen(s+1);
    for(int i=2;i<=n;i++){
        if(i<r){//i在盒子内
            d[i]=min(d[r-i+l],r-i+1);//为什么是min:当i刚好在最右边界时,d[i]不能直接等于左对称d[r-i+1],
        }                      // 而是r-i+1（1）,后面的while也会再更新d[i]
        else {
            d[i]=1;
        }
        while(s[i-d[i]]==s[i+d[i]]){
            d[i]++;
        }
        if(i+d[i]-1>r){           //盒子边界更新:始终记住盒子带来的意义：能为后面的i的d[i]直接等于在盒子范围内的对称d[r-i+1]
            l=i-d[i]+1,r=i+d[i]-1;            //d[i]含义：以i为中心的右半径值（包括自身）
        }
        Max=max(Max,d[i]);
    }
    return Max;
}
int main() {
    cin >> (a+1);
    int n=strlen(a+1);
    int k = 0;
    s1[0] = '$';
    s1[++k] = '#';
    for (int i = 1; i <= n; i++) {//s1：新串
        s1[++k] = a[i], s1[++k] = '#';
    }
    cout<<manacher(s1)-1<<endl;
    return 0;
}*/


