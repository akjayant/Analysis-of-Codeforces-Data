#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e4+5;

char s[sz], t[sz];

int main()
{
    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        scanf("%s %s", s, t);

        vector < int > v;
        for(int i=0; i<n; i++) {
            if(s[i]!=t[i]) v.push_back(i);
        }

        if(v.size()==0) puts("YES");
        else if(v.size() == 2) {
            int x=v[0], y=v[1];
            if(s[x]==s[y] && t[y]==t[x]) puts("YES");
            else puts("NO");
        }
        else puts("NO");
    }
}
