//TIME:2024/2/22

//STL
//map:

// 题目（贪心）1：
// 阿里巴巴走进了装满宝藏的藏宝洞。藏宝洞里面有N(N≤100) 堆金币，第i堆金币的总重量和总价值分别是
// mi,vi(1<=mi,vi<=100)。阿里巴巴有一个重量为T(T<=1000)的背包,但并不一定有办法将全部的金币都
// 装进去。他想装走尽可能多价值的金币。所有金币都可以随意分割，分割完的金币重量价值比（也就是单位价格）
// 不变。请问阿里巴巴最多可以拿走多少价值的金币？

/*#include<bits/stdc++.h>
#include<map>
using namespace std;

class Compare{
public:
    bool operator()(double a,double b) const { //！！对于为什么要加const
        return a>b;
    }
};

int main()
{
    multimap<double,double,Compare> Map;//key：金币堆的单位价钱，实值：一堆有多少金币
    double n,T,m,v,Maxmoney=0;
    cin>>n>>T;
    for(int i=0;i<n;i++){
        cin>>m>>v;//m:金币的总质量，v:金币的总价值
        double temp=v/m;//金币的单价
        Map.insert(pair<double,double>(temp,m));//first:单价 second:金币重量
    }

    for(multimap<double,double>::iterator it=Map.begin();it!=Map.end();it++){//开始从单位高的，装金币
        if(it->second<=T){//该堆金币能全部装下
            Maxmoney+=it->first*it->second;
            if(T==it->second){
                cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
                return 0;
            }
            T-=it->second;//背包的剩余容量
        }
        else{//该堆金币只能装一部分
            Maxmoney+=T*it->first;
            cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
            return 0;
        }
    }
    cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
    return 0;
}*/

//题目2:
//  INPUT：
//    第一行一个整数n，表示班上人数。接下来n 行，每行一个字符串表示其名字（互不相同，且只含小写字母，长度不超过50）
//    第n+2行，每行一个字符串表示名字（互不相同，且只包含小写字母，长度不超过50）.
//    接下来m行，每行一个字符串表示教练报的名字（只包含小写字母，长度不超过50）
//  OUTPUT：
//    对于每个教练报的名字，输出一行。
//    如果该名字正确且是第一次出现，输出 OK，如果该名字错误，输出 WRONG，如果该名字正确但不是第一次出现
//    输出 REPEAT。
//INPUT：
//5
//a
//b
//c
//ad
//acd
//3
//a
//a
//e
//OUTPUT：
//OK
//REPEAT
//WRONG


/*#include<bits/stdc++.h>
#include<map>
using namespace std;

class Compare{
public:
    bool operator()(double a,double b) const {//！！！为什加const
        return a>b;
    }
};

int main()
{
    multimap<double,double,Compare> Map;//key：金币堆的单位价钱，实值：一堆有多少金币
    double n,T,m,v,Maxmoney=0;
    cin>>n>>T;
    for(int i=0;i<n;i++){
        cin>>m>>v;//m:金币的总质量，v:金币的总价值
        double temp=v/m;//金币的单价
        Map.insert(pair<double,double>(temp,m));//first:单价 second:金币重量
    }

    for(multimap<double,double>::iterator it=Map.begin();it!=Map.end();it++){//开始从单位高的，装金币
        if(it->second<=T){//该堆金币能全部装下
            Maxmoney+=it->first*it->second;
            if(T==it->second){
                cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
                return 0;
            }
            T-=it->second;//背包的剩余容量
        }
        else{//该堆金币只能装一部分
            Maxmoney+=T*it->first;
            cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
            return 0;
        }
    }
    cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
    return 0;
}*/


//queque优先队列
// 题目3：小明和小宝正在玩一个简单的数字游戏。在一个回合中，小明可以选择写下一个数字，或者问小宝第k个大数是多少。
// 因为小明写的数字太多了，小宝觉得头晕目眩。现在，试着帮助小宝。
//有几个测试用例。对于每个测试用例，输入的第一行包含两个正整数 n， k。然后 n 行紧随其后。如果小明选择写下一个数字，
// 就会有一个“I”，后面跟着一个小明会写下的数字。如果小明选择问小宝，就会出现“Q”，那么就需要输出第k个大数。
// 输出由一个整数组成，该整数表示所有岛屿都位于一条线上的最大数量
//
//INPUT:
//8 3
//I 1
//I 2
//I 3
//Q
//I 5
//Q
//I 4
//Q
//
//OUTPUT:
//1
//2
//3


/*#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int t,k,x;
    char a;
    while(scanf("%d%d",&t,&k)!=EOF){
        priority_queue<int,vector<int>,greater<int>> que;//!!!top,从小到大
        int num=0;
        while(t--){
            cin>>a;
            if(a=='I'){
                if(num<k){
                    cin>>x;
                    que.push(x);
                    num++;
                }
                else if(num>=k){
                    cin>>x;
                    if(x>que.top()){
                        que.pop();
                        que.push(x);
                    }
                }
            }
            else if(a=='Q'){
                cout<<que.top()<<endl;
            }
        }
    }
    return 0;
}*/

// set容器：
// 题目4：输出两个集合的并集和子集
// INPUT:
//  输入四行。
//  第一行整数x 表示集合A的元素的个数
//  第二行x个数，表示A集合的各个元素，保证不重复。如果A是空集，则这一行没有数字。
//  第一行整数y 表示集合B的元素的个数
//  第二行y个数，表示B集合的各个元素，保证不重复。如果B是空集，则这一行没有数字。
// OUTPUT:
//  输出三行，
//  第一行输出一个整数，表示∣A∣。
//  第二行输出若干个整数，表示A∩B 中对应元素，从小到大输出，用空格隔开。如果是空集，则这一行什么也不输出，保留换行。
//  第三行输出若干个整数，表示A∪B 中对应元素，从小到大输出，用空格隔开。如果是空集，则这一行什么也不输出，保留换行。
//
//  INPUT 1：
//4
//1 3 5 8
//3
//3 6 8
// OUTPUT 1：
//4
//3 8
//1 3 5 6 8
//
//  INPUT 2：
//0
//
//4
//1 2 3 4
//  OUTPUT 2：
//0
//
//1 2 3 4
//

/*#include<bits/stdc++.h>//set_intersection 和  set_union的是自带的交集并集函数
#include<set>
#include<vector>
using namespace std;
void print(int val){
    cout<<val<<" ";
}

int main()
{
    set<int>s1;
    set<int>s2;
    vector<int>v1;//交
    vector<int>v2;//并
    int n1,n2,x;
    cin>>n1;
    for(int i=0;i<n1;i++){
        cin>>x;
        s1.insert(x);
    }
    cin>>n2;
    for(int i=0;i<n2;i++){
        cin>>x;
        s2.insert(x);
    }
    cout<<n1<<endl;
    v1.resize(min(s1.size(),s2.size()));//???  //交集
    v2.resize(s1.size()+s2.size());
    vector<int>::iterator it= set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),v1.begin());
    for_each(v1.begin(), it,print);
    cout<<endl;
    //并集
    vector<int>::iterator itt= set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),v2.begin());
    for_each(v2.begin(),itt,print);
    return 0;
}*/
