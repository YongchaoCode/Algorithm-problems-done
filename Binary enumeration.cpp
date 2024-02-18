//
// Created by 泳钞 on 2024/1/16.
//
// 二进制枚举模板
/*
1<<0=1(0);
1<<1=2(10);
1<<2=4(100);
1<<3=8(1000);
1<<4=16(10000);
...
1<<7=128(10000000);
*/

/*#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;  //n:n未二进制位
    for(int i = 0; i < (1<<n); i++)  //1<<n n位不同的01组合，有2^n-1种，循环2^n-1次
    {
        for(int j = 0; j < n; j++)   // 遍历每种二进制的每一位  n关联下一个循环&的二进制位数
        {
            if(i & (1 << j))   //判断二进制第j位是否是1   1<<0=1(0) , 1<<1=2(10)
            {
                printf("%d ",j);  //如果是1输出对应二进制的位置  !!! 注意：为什么输出的是j 。 j==0的时候i==0，不需要位数
            }
        }
        printf("\n");   //输出: 在0～2^n-1中的 每一个元素的二进制中的 是1的位数
    }
    return 0;
}*/


//eg1:话说大诗人李白，一生好饮。幸好他从不开车。
//一天， 他提着酒壶，从家里出来，酒壶中有酒两斗。他边走边唱：
//无事街上走，提壶去打酒。
//逢店加一倍，遇花喝一斗。
//这一路上，他一共遇到店 5 次，遇到花 10 次，已知最后一次遇到的是花，他正好把酒喝
//光了。请你计算李白遇到店和花的次序，有多少种可能的方案？
//
// 分析：分析：
//二进制枚举是一种写起来非常简洁的解法。我们已知遇店 5 次，遇花10 次，并且最后一次遇到花，正好把酒喝光。那么我们可以把店作为二进制中的 1，把花作为二进制中的 0，因为已经确定最后一次遇到的是花，所以我们需要判断枚举的结果是否刚好有 5 个 1 和 9 个 0。那么我们就枚举出 14 位二进制的所有可能并加以判断即可
//判断思路：判断二进制是否有 9 个 0，5 个 1，并且最终酒刚好剩 1 斗

/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,t1,t0,cnt=0;
      for(int i=0;i<(1<<14);i++){
          s=2,t1=0,t0=0;
           for(int j=0;j<14;j++){
               if(i&(1<<j)){//酒
                   t1++;
                   s*=2;
               }
               else{
                   t0++;
                   s-=1;
               }
           }
           if(t0==9&&t1==5&&s==1){
               cnt++;
           }
      }
      cout<<cnt;
    return 0;
}*/



// 有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。
// John现在有n个想要得到的物品，每个物品的体积分别是a1，a2……an。John可以从这些物品中选择一些，
// 如果选出的物体的总体积是40，那么利用这个神奇的口袋，John就可以得到这些物品。
// 现在的问题是，John有多少种不同的选择物品的方式
//S: 神奇口袋 二进制枚举
/*#include<bits/stdc++.h>
using namespace std;
int V[21];
int main()
{
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>V[i];
    }
    // 1代表选，0代表不选
    for(int i=0;i<(1<<n);i++){
        int sum_v=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sum_v+=V[j];
            }
        }
        if(sum_v==40){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}*/

//Q - Jam's balance (二进制枚举，内含优化)
/*#include<bits/stdc++.h>
#include<map>

using namespace std;
int a[100];
int t, n, m, x;
int sum;
map<int, bool> map1;
map<int, bool> map2;

int main() {
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        map1.clear();
        map2.clear();

        cin >> n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for (int i = 0; i < (1 << n); i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sum += a[j];
                }
            }
            map1[sum] = true;
            map2[sum] = true;
        }

        cin >> m;
        for(int i=0;i<m;i++) {
            cin >> x;
            int flag = 0;
            for (auto  it : map1) {
                int temp = x - it.first;
                if (temp <= 0) {
                    temp = -temp;
                }
                else {
                    continue;
                }
                if (map2.count(temp)) {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}*/
