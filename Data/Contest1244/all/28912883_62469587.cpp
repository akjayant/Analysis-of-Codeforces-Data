#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;

const ll N = 10010;
const ll mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,flag,res;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        flag = 0;
        res = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                res = max(res,2*(i-0+1));
                res = max(res,2*(n-i));
                flag = 1;
            }
        }
        if(!flag)   res = n;
        cout<<res<<endl;
    }
    return 0;
}