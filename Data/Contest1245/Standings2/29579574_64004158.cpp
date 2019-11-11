#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
signed main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n, a, b, c;
        cin>>n>>a>>b>>c;
        string s;
        cin>>s;
        string ans;
        ans.assign(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(!a)
                break;
            if(s[i] == 'S')
                a--, ans[i] = 'R', cnt++;
        }
        for(int i = 0; i < n; i++)
        {
            if(!b)
                break;
            if(s[i] == 'R')
                b--, ans[i] = 'P', cnt++;
        }
        for(int i = 0; i < n; i++)
        {
            if(!c)
                break;
            if(s[i] == 'P')
                c--, ans[i] = 'S', cnt++;
        }
        deque<char> left;
        while(a > 0)
        {
            a--;
            left.push_back('R');
        }
        while(b > 0)
        {
            b--;
            left.push_back('P');
        }
        while(c > 0)
        {
            c--;
            left.push_back('S');
        }
        for(int i = 0; i < n; i++)
        {
            if(ans[i] == 0)
                ans[i] = left.front(), left.pop_front();
        }
        if(cnt * 2 >= n)
        {
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
       // cout<<ans<<endl;
    }
}