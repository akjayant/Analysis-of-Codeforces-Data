#include<bits/stdc++.h>
#define m_p make_pair
#define ss second
#define ff first
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e4+5;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Q;
    cin >> Q;
    for (int q=0; q<Q; ++q)
    {
        int n;
        string s, t;
        cin >> n >> s >> t;
        for (int i=0; i<26; ++i)
            a[i]=0;
        for (int i=0; i<n; ++i)
        {
            a[s[i]-'a']++;
            a[t[i]-'a']++;
        }
        bool no=0;
        for (int i=0; i<26; ++i)
          if (a[i]&1) {no =1; break;}
        if (no) {cout << "No\n"; continue;}
        set<int> st1[26], st2[26];
        vector<pair<int, int> > ans;
        for (int i=0; i<n; ++i)
        {
            if (s[i] == t[i]) continue;
            st1[s[i]-'a'].insert(i);
            st2[t[i]-'a'].insert(i);
        }
        for (int i=0; i<n-1; ++i)
        {
            if (s[i] == t[i])
            {
                st1[s[i]-'a'].erase(i);
                st2[t[i]-'a'].erase(i);
                continue;
            }
            int num = s[i]-'a';
            st1[num].erase(i);
          //  cout << num << " " << c[num].back() << " " << c[num].size() << endl;
            if (st1[num].size()!=0)
            {
                int it = *st1[num].begin();
                st2[t[i]-'a'].erase(i);
                st1[t[i]-'a'].insert(it);
                swap(t[i], s[it]);
                ans.pb(m_p(it, i));
                st1[num].erase(st1[num].begin());
            }
            else
            {
                int it = *st2[num].begin();
                st2[num].erase(st2[num].begin());
                st2[s[i+1]-'a'].insert(it);
                st1[s[i+1]-'a'].erase(i+1);
                swap(s[i+1], t[it]);
                ans.pb(m_p(i+1, it));

                st2[t[i]-'a'].erase(i);
                st1[t[i]-'a'].insert(i+1);
                swap(s[i+1], t[i]);
                ans.pb(m_p(i+1, i));
            }
           // cout << s<<'\n' << t << endl;
        }
        cout << "Yes\n";
        cout << ans.size() << '\n';
        for (int i =0; i<ans.size(); ++i)
            cout <<ans[i].ff+1 << " " << ans[i].ss+1 << '\n';
    }

}
