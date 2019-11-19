#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define int long long

using namespace std;

const int N = 300707;
int n, m;
int a[N];
int b[N];
string s;
vector <int> v1;
vector <int> v2;
int mx = 0;
int id1 = 0;
int id2 = 0;
int pref[N];
int colp[N];
int suf[N];
int cols[N];

void check(int x, int y){
    //cout << x << " " << y << endl;
    swap(b[x], b[y]);
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        colp[i] = colp[i - 1] + b[i];
        pref[i] = min(pref[i - 1], colp[i]);
    }
    for (int i = n; i >= 1; i--){
        cols[i] = cols[i + 1] + b[i];
        suf[i] = max(suf[i + 1], cols[i]);
        if (cols[i] == suf[i] && cols[i] + pref[i - 1] == 0){
            cnt++;
        }
    }

    if (mx < cnt){
        mx = cnt;
        id1 = x;
        id2 = y;
    }
    swap(b[x], b[y]);
}

signed main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("diameter.in", "r", stdin);
    //freopen("diameter.out", "w", stdout);
    cin >> n;
    cin >> s;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            c1++;
            a[i + 1] = 1;
            v1.pb(i + 1);
        }
        else {
            c2++;
            a[i + 1] = -1;
            v2.pb(i + 1);
        }
    }

    for (int i = 1; i <= n; i++){
        b[i] = a[i];
    }

    //cout << c1 << " " << c2 << endl;

    if (c1 != c2){
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    for (int i = 0; i < v1.size(); i++){
        for (int j = 0; j < v2.size(); j++){
            check(v1[i], v2[j]);
        }
    }

    check(1, 1);

    cout << mx << endl;
    cout << id1 << " " << id2 << endl;


    return 0;
}
