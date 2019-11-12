#include <bits/stdc++.h>
using namespace std;

///Fastio (using only for int)
///Don't use (#define int long long)
void fin(int &a) {
    a = 0;
    char c = getchar();
    bool neg = false;
    while(c < '1' && c > '9' && c != '-')
        c = getchar();
    if(c == '-')
        neg = true, c = getchar();
    while(c != ' ' && c != '\n' && c != EOF)
        a = a * 10 + (c - 48), c = getchar();
    if(neg == true)
        a = -a;
}

void fout(int a) {
    if(a < 0)
        putchar('-');
    if(a == 0) {
        putchar('0');
        return ;
    }
    vector < char > v;
    while(a != 0)
        v.push_back(char(a % 10 + 48)), a = a / 10;
    for(int i = v.size() - 1; i >= 0; i--)
        putchar(v[i]);
}

void fout(string a) {
    for(int i = 0; i < a.size(); i++)
        putchar(a[i]);
}

///End of fastio

#define task ""
#define maxn 100005
#define ll long long
#define mod 1000000007
#define pii pair <int, int>
#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define fi(a) freopen(a, "r", stdin)
#define fo(a) freopen(a, "w", stdout)

int n, a[maxn], res, t, c1, c2, dem;
string s1, s2;
vector < int > v;
vector < pii > ans;

main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        c1 = -1, c2 = -1, dem = 0;
        cin >> s1 >> s2;
        v.clear();
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i])
                v.push_back(i);
        }
        string ss1 = s1, ss2 = s2;
        bool check = false;
        ans.clear();
        for(int i = 0; i < v.size(); i++) {
            int t1 = v[i];
            if(s1[t1] == s2[t1])
                continue;
            check = false;
            for(int j2 = i + 1; j2 < v.size(); j2++) {
                int j = v[j2];
                if(s1[j] == s1[t1]) {
                    swap(s1[j], s2[t1]);
                    ss1 = s1, ss2 = s2;
                    ans.push_back(mp(j, t1));
                    check = true;
                    break;
                }
            }
            if(check == false) {
                for(int j2 = i + 1; j2 < v.size(); j2++) {
                    int j = v[j2];
                    if(s2[j] == s1[t1]) {
                        char tmp = s1[t1];
                        swap(s2[j], s1[j]);
                        ss1 = s1, ss2 = s2;
                        swap(s1[j], s2[t1]);
                        ans.push_back(mp(j, j));
                        ans.push_back(mp(j, t1));
                        ss1 = s1, ss2 = s2;
                        check = true;
                        break;
                    }
                }
            }
            if(check == false) {
                cout << "NO\n";
                goto NEST;
            }
            if(ans.size() > 2 * n) {
                cout << "NO\n";
                goto NEST;
            }
        }
        if(ans.size() == 0 && v.size() != 0)
            cout << "NO\n";
        else {
            cout << "YES\n";
            cout << ans.size() << '\n';
            for(int i = 0; i < ans.size(); i++)
                cout << ans[i].ft + 1 << " " << ans[i].sd + 1 << '\n';
        }
NEST:
        ;
    }
}
