//KMP�㷨��
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int Next[N]={0};

//next[]:
void getNext(string &s) {//1:Next���飺��ǰi���ִ�ӵ�е��ǰ׺==��׺�ĳ���.ǰ׺==��׺�������ҵ�˳��
    int j = 0;           //eg: abcba :0 0 0 0 1
    for (int i = 1; i < s.size(); i++) {//2:j��ǰ׺��ĩβλ�ã���ǰ׺==��׺����󳤶ȡ�i:��׺��ĩβλ��
        while (j > 0 && s[j] != s[i]) {
            j--;
        }
        if (s[i] == s[j]) {
            j++;
            Next[i] = j;
        }
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    getNext(s2);

    int j = 0;//j��ģʽ��������
    for (int i = 0; i < s1.size(); i++) {
        if(s2.size()==0){
            cout<<0<<endl;
        }

        while (j > 0 && s1[i] != s2[j]) {
            j = Next[j - 1];
        }

        if (s1[i] == s2[j]) {
            j++;
        }
        if (j == s2.size()) {
            cout << i - s2.size() + 2 << endl;//+1�±��Ǵ�0��ʼ
        }
    }
    return 0;
}*/

//kmp����� Barn Echoes G��:���̣�
//����kmp�����̣�
//s1: a b d e e g
//s2: e g e d i c
//Ϊʲô�����2���s1�ĺ�׺==s2��ǰ׺��2:e g��,kmp forѭ�����j���Ǹó��ȣ�
//�������ٵ���һ��forѭ�������Ͷ���
/*#include<bits/stdc++.h>
using namespace std;
const int N=89;
int Next[N];

void getNext(string s){
    int j=0;
    for(int i=1;i<s.size();i++){
        while(j>0&&s[i]!=s[j]){
            j--;
        }
        if(s[i]==s[j]){
            j++;
            Next[i]=j;
        }
    }
}

int kmp(string s1,string s2){
    int j=0;
    for(int i=1;i<s1.size();i++){
        while(j>0&&s1[i]!=s2[j]){
            j=Next[j-1];
        }
        if(s1[i]==s2[j]){
            j++;
        }
    }
    return j;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    getNext(s2);
    int cnt1=kmp(s1,s2);
    memset(Next,0,sizeof(Next));
    getNext(s1);
    int cnt2=kmp(s2,s1);
    cout<<max(cnt1,cnt2)<<endl;
    return 0;
}*/


/*
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int a[N],b[N];
int Next[N];
int n1,n2;

void getNext(){
    int j=0;
    for(int i=1;i<n2;i++){
        while(j>0 && b[i]!=b[j]){
            j--;
        }

        if(b[i]==b[j]){
            j++;
            Next[i]=j;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(a,0,sizeof(b));
        memset(a,0,sizeof(Next));
        int flag=1;
        cin>>n1>>n2;
        for(int i=0;i<n1;i++){cin>>a[i];}//a:�ı���
        for(int i=0;i<n2;i++){cin>>b[i];}//b:ģʽ��

        //kmp�㷨
        getNext();
        int j=0;
        for(int i=0;i<n1;i++){
            while(j>0 && a[i]!=b[j]){
                j=Next[j-1];
            }

            if(a[i]==b[j]){
                j++;
            }

            if(j==n2){
                cout<<i-n2+2<<'\n';
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout<<-1<<'\n';
        }
    }
    return 0;
}*/




/*
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int Next[N];

void getNext(string &s){
    int j=0;
    for(int i=1;i<s.size();i++){
        while(j>0 && s[j]!=s[i]){
            j--;
        }

        if(s[i]==s[j]){
            j++;
            Next[i]=j;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int cnt=0;
        memset(Next,0,sizeof(Next));

        string s1,s2;
        cin>>s2>>s1;//s1:ģʽ��
        getNext(s1);
        //kmp
        int j=0;
        for(int i=0;i<s1.size();i++){
            while(j>0 && s1[i]!=s2[j]){
                j=Next[j-1];
            }

            if(s1[i]==s2[j]){
                j++;
            }

            if(j==s2.size()){
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}*/
