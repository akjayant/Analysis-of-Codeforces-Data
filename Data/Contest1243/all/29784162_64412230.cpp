#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ll long long

void solve(string &s, string &t, ll n)
{
    vector<ll> count(26, 0);
    
    vector<ll> diff_idx_vec;
    
    for (ll i = 0; i < n; ++i)
    {
        if (s[i] != t[i])
        {
            diff_idx_vec.push_back(i);
            
            count[s[i] - 'a']++;
            count[t[i] - 'a']++;
        }
    }
    
    bool valid = true;
    
    for (ll i = 0; i < 26; ++i)
    {
        if (count[i] % 2)
        {
            valid = false;
            break;
        }
    }
    
    if (!valid)
    {
        cout << "No" << endl;
        return;
    }
    
    cout << "Yes" << endl;
    
    ll len = diff_idx_vec.size();
    
    vector< pair<ll, ll> > ans;
    
    for (ll i = 0; i < (len - 1); ++i)
    {
        if (s[diff_idx_vec[i]] == t[diff_idx_vec[i]])
        {
            continue;
        }
        
        ll j;
        
        for (j = i + 1; j < len; ++j)
        {
            if (t[diff_idx_vec[j]] == s[diff_idx_vec[i]])
            {
                break;
            }
        }
        
        if (j == len)
        {
            for (j = i + 1; j < len; ++j)
            {
                if (s[diff_idx_vec[i]] == s[diff_idx_vec[j]])
                {
                    break;
                }
            }
            
            swap(s[diff_idx_vec[j]], t[diff_idx_vec[i]]);
            
            ans.push_back(make_pair(diff_idx_vec[j], diff_idx_vec[i]));
            
            continue;
        }
        
        if (i != j)
        {
            swap(s[diff_idx_vec[j]], t[diff_idx_vec[j]]);
            swap(s[diff_idx_vec[j]], t[diff_idx_vec[i]]);
            
            ans.push_back(make_pair(diff_idx_vec[j], diff_idx_vec[j]));
            ans.push_back(make_pair(diff_idx_vec[j], diff_idx_vec[i]));
        }
    }
    
    ll ans_size = ans.size();
    
    cout << ans_size << endl;
    
    for (ll i = 0; i < ans_size; ++i)
    {
        cout << (ans[i].first + 1) << " " << (ans[i].second + 1) << endl;
    }
}

int main()
{
    ll k, n;
    
    cin >> k;
    
    string s, t;
    
    while(k--)
    {
        cin >> n;
        
        cin >> s;
        cin >> t;
        solve(s, t, n);
    }
    
    return 0;
}
