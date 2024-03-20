//KMP算法：
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int Next[N]={0};

//next[]:
void getNext(string &s) {//1:Next数组：求前i个字串拥有的最长前缀==后缀的长度.前缀==后缀都是左到右的顺序
    int j = 0;           //eg: abcba :0 0 0 0 1
    for (int i = 1; i < s.size(); i++) {//2:j：前缀的末尾位置，和前缀==后缀的最大长度。i:后缀的末尾位置
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

    int j = 0;//j是模式串的索引
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
            cout << i - s2.size() + 2 << endl;//+1下标是从0开始
        }
    }
    return 0;
}*/

//kmp（洛谷 Barn Echoes G）:流程：
//考验kmp的流程：
//s1: a b d e e g
//s2: e g e d i c
//为什么能输出2（最长s1的后缀==s2的前缀（2:e g）,kmp for循环后的j就是该长度）
//不懂了再调试一边for循环看看就懂了
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
        for(int i=0;i<n1;i++){cin>>a[i];}//a:文本串
        for(int i=0;i<n2;i++){cin>>b[i];}//b:模式串

        //kmp算法
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
        cin>>s2>>s1;//s1:模式串
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
