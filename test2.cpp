//manacher�㷨��������һ������+��ϣ�㷨������ѧϰ�£�
/*#include<bits/stdc++.h>
using namespace std;
const int N=31000005;
int d[N];//����
char a[N];
char s1[N];
int manacher(char s[]){//n:�´��ĳ���
    int Max=0;
    d[1]=1;
    int l,r=1;//���ӱ߽�
    int n=strlen(s+1);
    for(int i=2;i<=n;i++){
        if(i<r){//i�ں�����
            d[i]=min(d[r-i+l],r-i+1);//Ϊʲô��min:��i�պ������ұ߽�ʱ,d[i]����ֱ�ӵ�����Գ�d[r-i+1],
        }                      // ����r-i+1��1��,�����whileҲ���ٸ���d[i]
        else {
            d[i]=1;
        }
        while(s[i-d[i]]==s[i+d[i]]){
            d[i]++;
        }
        if(i+d[i]-1>r){           //���ӱ߽����:ʼ�ռ�ס���Ӵ��������壺��Ϊ�����i��d[i]ֱ�ӵ����ں��ӷ�Χ�ڵĶԳ�d[r-i+1]
            l=i-d[i]+1,r=i+d[i]-1;            //d[i]���壺��iΪ���ĵ��Ұ뾶ֵ����������
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
    for (int i = 1; i <= n; i++) {//s1���´�
        s1[++k] = a[i], s1[++k] = '#';
    }
    cout<<manacher(s1)-1<<endl;
    return 0;
}*/


