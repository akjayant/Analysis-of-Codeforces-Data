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
int n;
string s,t;
int32_t main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int k; cin>>k;
    while(k--){
        cin>>n>>s>>t;
        map<char,int> mark;
        for(int i=0;i<n;i++){
            mark[s[i]]++;
            mark[t[i]]++;
        }
        bool flag=0;
        for(int i=0;i<26;i++){
            char c = 'a'+i;
            if(mark[c]%2) flag=1;
        }
        if(flag){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        vector<int> vec;
        for(int i=0;i<n;i++) if(s[i]!=t[i]){
            for(int j=i+1;j<n;j++) if(s[j]==s[i]){
                vec.pb(j),vec.pb(i);
                swap(s[j],t[i]);
                break;
            }
            if(s[i]==t[i]) continue;
            vec.pb(i),vec.pb(i);
            swap(s[i],t[i]);
            for(int j=i+1;j<n;j++) if(t[j]==t[i]){
                vec.pb(i),vec.pb(j);
                swap(s[i],t[j]);
                break;
            }
        }
        cout<<vec.size()/2<<endl;
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]+1<<' ';
            if(i%2) cout<<endl;
        }
     }
    return 0;
}
