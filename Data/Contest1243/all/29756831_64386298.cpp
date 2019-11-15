#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi acos(-1)
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int cnt[26];
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; i++){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
        }
        bool f = true;
        for(int i = 0; i < 26; i++){
            if(cnt[i] & 1){
                f = false;
            }
        }
        if(!f){
            cout << "No";
        }else{
            vector<pair<int, int> > ans;
            for(int i = 0; i < n; i++){
                char ch = s[i];
                if(t[i] == ch){
                    continue;
                }
                for(int j = i + 1; j < n; j++){
                    if(s[j] == ch){
                        swap(s[j], t[i]);
                        ans.push_back({j+1, i+1});
                        break;
                    }
                }
                if(s[i] != t[i]){
                    for(int j = i + 1; j < n; j++){
                        if(t[j] == ch){
                            swap(s[n-1], t[j]);
                            ans.push_back({n, j+1});
                            swap(s[n-1], t[i]);
                            ans.push_back({n, i+1});
                            break;
                        }
                    }
                }
            }
            cout << "Yes" << endl;
            cout << (int)ans.size() << endl;
            for(auto it :ans){
                cout << it.first << " " << it.second << endl;
            }
            //cout << s << " " << t << endl;
        }
        cout << endl;
    }
    return 0;
}
