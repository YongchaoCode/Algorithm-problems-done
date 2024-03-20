//字典树
/*
#include<bits/stdc++.h>
using namespace std;
int trie[99999][26];
int id=0;//id:代表每个结点的编号，大小与插入的顺序有关
int cnt[99999];
void insert(string s){
    int p=0;
     for(int i=0;i<s.size();i++){
        int x=s[i]-'a';
         if(trie[p][x]==0){
             trie[p][x]=++id;
         }
         p=trie[p][x];
          cnt[p]++;//每一个p的编号代表了该字符出现的次数
                   //eg:abd:cnt[a,b,c]==1，再次插入ab,cnt[a,b]==2;
     }
}

int find(string s){//返回个数
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


//字典树（前缀查询）
//如何判断空行：!!!
// 1：gets函数：读入的回车符会自动转换为NULL。所以循环读入，每次检测读入进来的字符串的第一个字符是否为NULL即可
// 2：用strlen()计算字符串的长度，如果长度为0，说明为空行，退出输入循环。
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