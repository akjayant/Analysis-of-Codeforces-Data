#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        string s, t;
        cin>>s>>t;
        set<pair<char, int> > st;
        for (int i=0; i<n; i++){
            st.insert({s[i], i});
            st.insert({t[i], i+n});
        }
        vector<pair<int, int> > res;
        bool br = 0;
        for (int i=0; i<n; i++){
            //cout<<" - "<<i<<endl;
            //cout<<s<<endl;
            //cout<<t<<endl;
            char a = s[i];
            st.erase({a, i});
            auto p = st.upper_bound({a, -1});
            if (p == st.end() || p->first != a){
                br = 1;
                //cout<<"-----------"<<endl;
                //cout<<a<<" "<<i<<endl;
                break;
            }

            int pi = p->second;
            //cout<<pi<<endl;
            st.erase(p);
            char ta = t[i];
            st.erase({ta, i+n});
            if (pi == i+n){
                continue;
            }
            if (pi < n){
                res.push_back({pi, i});
                st.insert({ta, pi});
                s[pi] = ta;
                t[i] = a;
            } else {
                pi -= n;
                char saa = s[i+1];
                st.erase({saa, i+1});
                res.push_back({i+1, pi});
                res.push_back({i+1, i});
                st.insert({saa, pi+n});
                st.insert({ta, i+1});
                s[i+1] = ta;
                t[i] = a;
                t[pi] = saa;
            }
        }
        if (br){
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
            cout<<res.size()<<endl;
            for (int i=0; i<res.size(); i++){
                cout<<res[i].first+1<<" "<<res[i].second+1<<endl;
            }
        }
    }
    return 0;
}
