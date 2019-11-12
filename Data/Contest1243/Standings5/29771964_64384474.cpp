#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

int main(){
    int k;cin>>k;
    REP(q,k){
        int n;cin>>n;
        string s,t;cin>>s>>t;
        vector<char> a;
        REP(i,n) {
            if(s[i]!=t[i]){
                a.push_back(s[i]);
                a.push_back(t[i]);
            }
        }
        if(a.size()==4&&a[0]==a[2]&&a[1]==a[3]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}