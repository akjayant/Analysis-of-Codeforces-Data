#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    int q, n; cin >> q;
    while(q--) {
        string s, t; cin >> n >> s >> t;
        int a=-1, h=0;
        bool x=true;
        for(int i=0;i<n;i++)
            if(s[i]!=t[i]) {
                h++;
                if(a==-1) a=i;
                else if(s[i]!=s[a]||t[i]!=t[a]||h>2) x=false;
            }
        cout << (x && h!=1 ? "Yes":"No") << endl;
    }
    return 0;
}
