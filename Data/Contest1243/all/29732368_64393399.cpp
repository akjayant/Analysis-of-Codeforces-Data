#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int h, n;
string s, t;
bool sta[26];
vector<pair<int, int> > ans;

bool fun()
{
	for (int i = 0; i < n; i++) {
		sta[s[i] - 'a'] = !sta[s[i] - 'a'];
	}
	for (int i = 0; i < n; i++) {
		sta[t[i] - 'a'] = !sta[t[i] - 'a'];
	}
	for (int i = 0; i < 26; i++) {
		if (sta[i]) return false;
	}
	return true;
}

void gun(int cur)
{
	if (s[cur] == t[cur]) return;
	for (int i = cur + 1; i < n; i++) {
		if (t[i] == t[cur]) {
			ans.pb({ cur, i });
			swap(s[cur], t[i]);
			return;
		}
		else if (s[i] == t[cur]) {
			ans.pb({ i, cur + 1 });
			swap(s[i], t[cur + 1]);
			ans.pb({ cur, cur + 1 });
			swap(s[cur], t[cur + 1]);
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> h;
	while (h--) {
		cin >> n >> s >> t;
		memset(sta, 0, sizeof(sta));
		if (!fun()) {
			cout << "No" << E;
			continue;
		}
		ans.clear();
		for (int i = 0; i < n; i++) {
			gun(i);
		}
		cout << "Yes" << E;
		cout << ans.size() << E;
		for (int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i].fi + 1 << " " << ans[i].se + 1 << E;
		}
	}
	//system("pause");
	return 0;
}