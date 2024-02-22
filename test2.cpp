//TIME:2024/2/22

//STL
//map:

// ��Ŀ��̰�ģ�1��
// ����Ͱ��߽���װ�����صĲر������ر���������N(N��100) �ѽ�ң���i�ѽ�ҵ����������ܼ�ֵ�ֱ���
// mi,vi(1<=mi,vi<=100)������Ͱ���һ������ΪT(T<=1000)�ı���,������һ���а취��ȫ���Ľ�Ҷ�
// װ��ȥ������װ�߾����ܶ��ֵ�Ľ�ҡ����н�Ҷ���������ָ�ָ���Ľ��������ֵ�ȣ�Ҳ���ǵ�λ�۸�
// ���䡣���ʰ���Ͱ����������߶��ټ�ֵ�Ľ�ң�

/*#include<bits/stdc++.h>
#include<map>
using namespace std;

class Compare{
public:
    bool operator()(double a,double b) const { //��������ΪʲôҪ��const
        return a>b;
    }
};

int main()
{
    multimap<double,double,Compare> Map;//key����Ҷѵĵ�λ��Ǯ��ʵֵ��һ���ж��ٽ��
    double n,T,m,v,Maxmoney=0;
    cin>>n>>T;
    for(int i=0;i<n;i++){
        cin>>m>>v;//m:��ҵ���������v:��ҵ��ܼ�ֵ
        double temp=v/m;//��ҵĵ���
        Map.insert(pair<double,double>(temp,m));//first:���� second:�������
    }

    for(multimap<double,double>::iterator it=Map.begin();it!=Map.end();it++){//��ʼ�ӵ�λ�ߵģ�װ���
        if(it->second<=T){//�öѽ����ȫ��װ��
            Maxmoney+=it->first*it->second;
            if(T==it->second){
                cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
                return 0;
            }
            T-=it->second;//������ʣ������
        }
        else{//�öѽ��ֻ��װһ����
            Maxmoney+=T*it->first;
            cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
            return 0;
        }
    }
    cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
    return 0;
}*/

//��Ŀ2:
//  INPUT��
//    ��һ��һ������n����ʾ����������������n �У�ÿ��һ���ַ�����ʾ�����֣�������ͬ����ֻ��Сд��ĸ�����Ȳ�����50��
//    ��n+2�У�ÿ��һ���ַ�����ʾ���֣�������ͬ����ֻ����Сд��ĸ�����Ȳ�����50��.
//    ������m�У�ÿ��һ���ַ�����ʾ�����������֣�ֻ����Сд��ĸ�����Ȳ�����50��
//  OUTPUT��
//    ����ÿ�������������֣����һ�С�
//    �����������ȷ���ǵ�һ�γ��֣���� OK����������ִ������ WRONG�������������ȷ�����ǵ�һ�γ���
//    ��� REPEAT��
//INPUT��
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
//OUTPUT��
//OK
//REPEAT
//WRONG


/*#include<bits/stdc++.h>
#include<map>
using namespace std;

class Compare{
public:
    bool operator()(double a,double b) const {//������Ϊʲ��const
        return a>b;
    }
};

int main()
{
    multimap<double,double,Compare> Map;//key����Ҷѵĵ�λ��Ǯ��ʵֵ��һ���ж��ٽ��
    double n,T,m,v,Maxmoney=0;
    cin>>n>>T;
    for(int i=0;i<n;i++){
        cin>>m>>v;//m:��ҵ���������v:��ҵ��ܼ�ֵ
        double temp=v/m;//��ҵĵ���
        Map.insert(pair<double,double>(temp,m));//first:���� second:�������
    }

    for(multimap<double,double>::iterator it=Map.begin();it!=Map.end();it++){//��ʼ�ӵ�λ�ߵģ�װ���
        if(it->second<=T){//�öѽ����ȫ��װ��
            Maxmoney+=it->first*it->second;
            if(T==it->second){
                cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
                return 0;
            }
            T-=it->second;//������ʣ������
        }
        else{//�öѽ��ֻ��װһ����
            Maxmoney+=T*it->first;
            cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
            return 0;
        }
    }
    cout<<fixed<<setprecision(2)<<Maxmoney<<endl;
    return 0;
}*/


//queque���ȶ���
// ��Ŀ3��С����С��������һ���򵥵�������Ϸ����һ���غ��У�С������ѡ��д��һ�����֣�������С����k�������Ƕ��١�
// ��ΪС��д������̫���ˣ�С������ͷ��Ŀѣ�����ڣ����Ű���С����
//�м�����������������ÿ����������������ĵ�һ�а������������� n�� k��Ȼ�� n �н���������С��ѡ��д��һ�����֣�
// �ͻ���һ����I�����������һ��С����д�µ����֡����С��ѡ����С�����ͻ���֡�Q������ô����Ҫ�����k��������
// �����һ��������ɣ���������ʾ���е��춼λ��һ�����ϵ��������
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
        priority_queue<int,vector<int>,greater<int>> que;//!!!top,��С����
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

// set������
// ��Ŀ4������������ϵĲ������Ӽ�
// INPUT:
//  �������С�
//  ��һ������x ��ʾ����A��Ԫ�صĸ���
//  �ڶ���x��������ʾA���ϵĸ���Ԫ�أ���֤���ظ������A�ǿռ�������һ��û�����֡�
//  ��һ������y ��ʾ����B��Ԫ�صĸ���
//  �ڶ���y��������ʾB���ϵĸ���Ԫ�أ���֤���ظ������B�ǿռ�������һ��û�����֡�
// OUTPUT:
//  ������У�
//  ��һ�����һ����������ʾ�OA�O��
//  �ڶ���������ɸ���������ʾA��B �ж�ӦԪ�أ���С����������ÿո����������ǿռ�������һ��ʲôҲ��������������С�
//  ������������ɸ���������ʾA��B �ж�ӦԪ�أ���С����������ÿո����������ǿռ�������һ��ʲôҲ��������������С�
//
//  INPUT 1��
//4
//1 3 5 8
//3
//3 6 8
// OUTPUT 1��
//4
//3 8
//1 3 5 6 8
//
//  INPUT 2��
//0
//
//4
//1 2 3 4
//  OUTPUT 2��
//0
//
//1 2 3 4
//

/*#include<bits/stdc++.h>//set_intersection ��  set_union�����Դ��Ľ�����������
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
    vector<int>v1;//��
    vector<int>v2;//��
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
    v1.resize(min(s1.size(),s2.size()));//???  //����
    v2.resize(s1.size()+s2.size());
    vector<int>::iterator it= set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),v1.begin());
    for_each(v1.begin(), it,print);
    cout<<endl;
    //����
    vector<int>::iterator itt= set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),v2.begin());
    for_each(v2.begin(),itt,print);
    return 0;
}*/
