//进制哈希
/*#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1e4+9;
ull a[N];//存每一种字符串的hash值

ull getHash(string &s){
    ull P=131,H=0;
    for(int i=0;i<s.size();i++){
        H=H*P+s[i]-'a'+1;
    }
    return H;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        a[i]= getHash(s);
    }
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]!=a[i+1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}*/
