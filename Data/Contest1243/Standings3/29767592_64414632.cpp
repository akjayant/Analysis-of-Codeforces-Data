#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n;
string s, t;
vector<pii> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin>>tests;
    while (tests--){
        cin>>n>>s>>t;
        ans.clear();
        for (int i=0; i<n; i++)
            if (s[i]!=t[i]){
                for (int j=i+1; j<n; j++){
                    if (t[i]==t[j]){
                        swap(s[i],t[j]);
                        ans.push_back(pii(i,j));
                        break;
                    }
                    if (s[j]==s[i]){
                        swap(s[j],t[i]);
                        ans.push_back(pii(j,i));
                        break;
                    }
                    if (t[j]==s[i]){
                        swap(s[j],t[j]);
                        ans.push_back(pii(j,j));
                        swap(s[j],t[i]);
                        ans.push_back(pii(j,i));
                        break;
                    }
                    if (s[j]==t[i]){
                        swap(s[j],t[j]);
                        ans.push_back(pii(j,j));
                        swap(s[i],t[j]);
                        ans.push_back(pii(i,j));
                        break;
                    }
                }
            }
        if (s==t){
            cout <<"YES\n";
            cout <<ans.size()<<"\n";
            for (int i=0; i<ans.size(); i++)
                cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
        }
        else
            cout << "NO\n";
    }
}