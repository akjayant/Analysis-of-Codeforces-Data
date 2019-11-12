//μ's forever
#include <bits/stdc++.h>
using namespace std;
int q,n;
string s,t;
int main()
{
    cin>>q;
    while(q--)
    {
        cin>>n>>s>>t;
        int cnt[30] = {0}, cs[30] = {0}, ct[30] = {0};
        for(register int i=0;i<n;++i)
        {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']++;
            cs[s[i] - 'a']++;
            ct[t[i] - 'a']++;
        }
        int f = true;
        for(register int i=0;i<26;++i)
            if(cnt[i] % 2)
                f = false;
        if(!f)
        {
            puts("No");
            continue;
        }
        vector<pair<int, int> > ans;
        for(register int i=0;i<n;++i)
            if(s[i] != t[i])
            {
                int pt = 0;
                for(register int j=i+1;j<n;++j)
                    if(t[j] == t[i])
                    {
                        pt = j;
                        break;
                    }
                if(pt)
                {
                    ans.push_back(make_pair(i, pt));
                    swap(s[i], t[pt]);
                    continue;
                }
                int ps = 0;
                for(register int j=i+1;j<n;++j)
                    if(t[i] == s[j])
                    {
                        ps = j;
                        break;
                    }
                if(ps)
                {
                    ans.push_back(make_pair(ps, n - 1));
                    swap(s[ps], t[n - 1]);
                    ans.push_back(make_pair(i, n - 1));
                    swap(s[i], t[n - 1]);
                }
            }

        puts("Yes");
        cout << ans.size() << endl;
        for(register int i=0;i<ans.size();++i)
            cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    }
	return 0;
}
