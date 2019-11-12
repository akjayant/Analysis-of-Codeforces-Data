#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define sz size()
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
int32_t main()
{
    int k; cin>>k;
    while(k--){
        int n; string s,t;
        cin>>n>>s>>t;
        vector<int> vec;
        map<char,int> mark;
        bool ok = false;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]) vec.pb(i);
            mark[s[i]]++;
            if(mark[s[i]]>1) ok=1;
        }
        if(vec.size()==0){
            cout<<(ok?"Yes":"No")<<endl;
            continue;
        }
        if(vec.size()==2){
            if(s[vec[0]]==s[vec[1]] && t[vec[1]]==t[vec[0]])
                cout<<"Yes";
            else cout<<"No";
            cout<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
    return 0;
}
