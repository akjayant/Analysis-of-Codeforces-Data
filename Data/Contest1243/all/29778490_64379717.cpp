#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;


 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("testcases.txt", "r", stdin);

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        string a,b;
        cin>>a>>b;

        if(a==b) {
            cout<<"Yes"<<endl;
            continue;
        }

        vector<int>v;

        for(int i=0;i<n;i++) {
            if(a[i]!=b[i]) {
                v.push_back(i);
            }
        }

        if(v.size()!=2) {
            cout<<"No"<<endl;
            continue;
        }

        if(a[v[0]]==a[v[1]] && b[v[0]]==b[v[1]]) {
            cout<<"Yes"<<endl;
            continue;
        }

        cout<<"No"<<endl;
    }



 
    return 0;
}