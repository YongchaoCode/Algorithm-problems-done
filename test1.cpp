//�ֵ���
/*
#include<bits/stdc++.h>
using namespace std;
int trie[99999][26];
int id=0;//id:����ÿ�����ı�ţ���С������˳���й�
int cnt[99999];
void insert(string s){
    int p=0;
     for(int i=0;i<s.size();i++){
        int x=s[i]-'a';
         if(trie[p][x]==0){
             trie[p][x]=++id;
         }
         p=trie[p][x];
          cnt[p]++;//ÿһ��p�ı�Ŵ����˸��ַ����ֵĴ���
                   //eg:abd:cnt[a,b,c]==1���ٴβ���ab,cnt[a,b]==2;
     }
}

int find(string s){//���ظ���
    int p=0;
     for(int i=0;i<s.size();i++){
         int x=s[i]-'a';
          if(trie[p][x]==0){
              return 0;
          }
          p=trie[p][x];
     }
      return cnt[p];
}

int main() {
    int n, q;
    cin >> n >> q;
    while (n--) {
        string s;
        cin >> s;
        insert(s);
        while(q--)
        {
            string s1;
            cout<<find(s1)<<endl;
        }
    }
    return 0;
}*/


//�ֵ�����ǰ׺��ѯ��
//����жϿ��У�!!!
// 1��gets����������Ļس������Զ�ת��ΪNULL������ѭ�����룬ÿ�μ�����������ַ����ĵ�һ���ַ��Ƿ�ΪNULL����
// 2����strlen()�����ַ����ĳ��ȣ��������Ϊ0��˵��Ϊ���У��˳�����ѭ����
/*#include<bits/stdc++.h>
using namespace std;
int trie[1000010][26];
int cnt[1000010];
int id=0;

void insert(char s[]){
    int p=0;
    for(int i=0;i<strlen(s);i++){
        int x=s[i]-'a';
        if(trie[p][x]==0){
            trie[p][x]=++id;
        }
        p=trie[p][x];
        cnt[p]++;
    }
}

int find(char s[]){
    int p=0;
    for(int i=0;i<strlen(s);i++){
        int x=s[i]-'a';
        if(trie[p][x]==0){
            return 0;
        }
        p=trie[p][x];
    }
    return cnt[p];
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    char s[19];
    while(gets(s)){
        if(strlen(s)==0 || s[0]==' '){
            break;
        }
        insert(s);
    }

    while(gets(s)){
        cout<<find(s)<<'\n';
    }
    return 0;
}*/