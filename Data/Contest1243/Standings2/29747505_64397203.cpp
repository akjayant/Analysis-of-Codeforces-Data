#include<bits/stdc++.h>
#define ll long long
#define mod (ll)1000000007
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int c[26];
        memset(c,0,sizeof(c));

        for(auto ch: s)
            c[ch-'a']++;
        for(auto ch:t)
            c[ch-'a']++;

        bool ok = true;
        for(int i = 0; i < 26; i++){
            if(c[i]%2){
                cout<<"No\n";
                ok = false;
                break;
            }
        }

        if(!ok)
            continue;

        vector<pair<int,int> > ans;
        for(int i = 0; i < n; i++){
            if(s[i] == t[i])    continue;
            else{
                // s search
                bool f = false;
                for(int j = i+1; j < n; j++){
                    if(s[i] == s[j]){
                        swap(t[i],s[j]);
                        ans.push_back({j,i});
                        f = true;
                        break;
                    }
                }

                // t search
                if(f)   continue;
                for(int j = i+1; j < n; j++){
                    if(t[j] == s[i]){
                        if(i+1 >= n){
                            cout<<"No\n";
                            ok = false;
                            break;
                        }
                        else{
                            swap(s[i+1],t[j]);
                            ans.push_back({i+1,j});
                            swap(s[i+1],t[i]);
                            ans.push_back({i+1,i});
                        }

                        break;
                    }
                }

                if(!ok)
                    break;
            }
        }

        if(!ok) continue;

        cout<<"Yes\n";
        cout<<ans.size()<<"\n";

        for(auto p: ans)
            cout<<p.first+1<<" "<<p.second+1<<"\n";

    }
    return 0;
}
