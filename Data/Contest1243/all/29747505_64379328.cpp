#include<bits/stdc++.h>
#define ll long long
#define mod (ll)1000000007
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string s,t;
        cin>>s>>t;


        vector<char> a,b;
        for(int i = 0; i < n; i++){
            if(s[i]!=t[i]){
                a.push_back(s[i]);
                b.push_back(t[i]);
            }
        }

        if(a.size()!=2)
            cout<<"No\n";
        else{
            if(a[0] == a[1] && b[0]==b[1])
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}
