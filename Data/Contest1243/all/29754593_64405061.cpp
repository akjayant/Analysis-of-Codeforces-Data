#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    int q, n; cin >> q;
    while(q--) {
        string s, t; char p; bool c=true;
        cin >> n >> s >> t;
        vector<int> x(26,0);
        for(int i=0;i<n;i++)
            x[s[i]-'a']++, x[t[i]-'a']++;
        for(int i=0;i<26;i++)
            if(x[i]&1) c=false;
        if(!c) { cout << "No" << endl; continue; }
        vector<pair<int,int>> r;
        for(int i=0;i<n;i++)
            if(s[i]!=t[i]) {
                int j=i+1;
                while(j<n && s[j]!=s[i]) j++;
                if(j<n) r.push_back({j+1,i+1}), s[j]=t[i], t[i]=s[i];
                else {
                    j=i+1;
                    while(t[j]!=s[i]) j++;
                    r.push_back({n,j+1}); r.push_back({n,i+1});
                    t[j]=s[n-1], s[n-1]=t[i], t[i]=s[i];
                }
            }
        cout << "Yes" << endl << r.size() << endl;
        for(auto i:r)
            cout << i.first << " " << i.second << endl;
    }
    return 0;
}
