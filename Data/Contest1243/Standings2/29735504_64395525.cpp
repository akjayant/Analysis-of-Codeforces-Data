#include <bits/stdc++.h>
using namespace std;

#define N 1000012

int ntest, n, f[N];
vector<char> s, t;
vector<pair<int, int> > v;

bool Check(vector<char> s, vector<char> t){
    for (int i = 0; i < n; i++) f[s[i] - 'a']++;
    for (int i = 0; i < n; i++) f[t[i] - 'a']++;
    for (int i = 0; i <= 'z' - 'a'; i++) if (f[i] % 2 != 0) return false;
    return true;
}

int Get(vector<char> s, vector<char> t){
    int i = 0;
    while (s[i] == t[i] && i < n) i++;
    if (i == n) return 0;
    int pos = i, vt; bool kt = false;
    for (int i = pos + 1; i < n; i++){
        if (s[i] == s[pos]) vt = i, kt = true;
    }
    if (kt){
        char ch = t[pos]; t[pos] = s[vt], s[vt] = ch;
        v.push_back({vt + 1, pos + 1});
        return Get(s, t) + 1;
    } else {
        for (int i = pos + 1; i < n; i++)
            if (t[i] == s[pos]) vt = i;
        char ch = s[pos + 1]; s[pos + 1] = t[vt], t[vt] = ch;
        v.push_back({pos + 2, vt + 1});
        return Get(s, t) + 1;
    }
}

int main()
{
	#define file "huy"
	//freopen (file ".inp", "r", stdin);
	//freopen (file ".out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> ntest;

    while(ntest--){
        cin >> n;
        s.resize(n), t.resize(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++) cin >> t[i];

        for (int i = 0; i <= 'z' - 'a'; i++) f[i] = 0;
        if (!Check(s, t)) {cout << "No\n"; continue;}
        v.clear();
        Get(s, t);
        if (v.size() > 2 * n) {cout << "No\n"; continue;}
        cout << "Yes\n";
        cout << v.size() << "\n";
        for (int i = 0; i < v.size(); i++) cout << v[i].first << " " << v[i].second << "\n";
    }

	return 0;
}

