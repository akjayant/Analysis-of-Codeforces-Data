#include<bits/stdc++.h>
#define m_p make_pair
#define ss second
#define ff first
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Q;
    cin >> Q;
    for (int q=0; q<Q; ++q)
    {
        int n;
        string s, t;
        int pos1 =-1, pos2=-1;
        cin >> n >> s >> t;
        bool no = 0;
        for (int i=0; i<n; ++i)
        {
            if (s[i]==t[i]) continue;
            if (pos1!=-1 && pos2!=-1) {no = 1; break;}
            if (pos1 == -1) pos1 = i;
            else pos2=i;
        }
        if (no || pos1==- 1 || pos2==-1) cout << "No\n";
        else if (s[pos1] == s[pos2] && t[pos2] == t[pos1]) cout << "Yes\n";
        else cout << "No\n";
    }

}
