#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<int,int>
#define iii pair<int, ii>
#define se second
#define double long double
#define mod 1000000007
#define popcount __builtin_popcountll
using namespace std;
const double PI = acos(-1.0);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string str;
        cin>>n>>str;
        str = '#' + str;
        int amid = n;
        for(int i=1;i<=n;i++){
            if(str[i]=='0')continue;
            amid = max(amid, 2*i);
            amid = max(amid, 2*(n-i+1));
        }
        cout<<amid<<endl;
    }
}
