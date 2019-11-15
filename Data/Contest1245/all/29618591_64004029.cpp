#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, a, b, c;
        cin>>n>>a>>b>>c;
        string s;
        cin>>s;

        vector<int> av, bv, cv;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'R') bv.push_back(i);
            else if(s[i] == 'P') cv.push_back(i);
            else av.push_back(i);
        }

        int as = av.size(), bs = bv.size(), cs = cv.size();
        int ax = min(as, a), bx = min(bs, b), cx = min(cs, c);

        if(2*(ax+bx+cx) < n)
        {
            printf("NO\n");
            continue;
        }

        printf("YES\n");

        string ans(n, '0');

        for(int i = 0; i < ax; i++) ans[av[i]] = 'R';
        for(int i = 0; i < bx; i++) ans[bv[i]] = 'P';
        for(int i = 0; i < cx; i++) ans[cv[i]] = 'S';

        a -= ax, b -= bx, c -= cx;

        for(int i = 0; i < n; i++)
        {
            if(ans[i] != '0') continue;

            if(a) ans[i] = 'R', a--;
            else if(b) ans[i] = 'P', b--;
            else ans[i] = 'S', c--;
        }

        cout<<ans<<endl;
    }

    return 0;
}
