#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<fstream>
#include<queue>
#include<iostream>
#include<unordered_map>
#include<math.h>
#include<stack>
#include <numeric>
#include<iomanip>
#include<unordered_set>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
const int maxm = 305;
ll arr[maxn];
ll arr1[maxn];
const ll mod = 1e9 + 7;
vector<ll> edges[maxn];
ll n, m, k, q, D, H, a, b, c, h, d, x, y, z, t,p;
string s, s1, s2;
ll gcd(ll a, ll b)
{
	ll t;
	while (b)
	{
		t = a;
		a = b;
		b = t % b;
	}
	return a;
}
ll par[maxn];
void init() {
	for (int i = 0; i < maxn; i++)
		par[i] = i;
}
void init(int n) {
	for (int i = 0; i < n+10; i++)
		par[i] = i;
}
ll find(int i) {
	if (par[i] != i) {
		return par[i] = find(par[i]);
	}
	else
		return i;
}
void merge(int x, int y) {
	par[find(x)] = par[find(y)];
}
ll presum[100];
bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
};

vector<int> get_pi(const string s) {
	int n = s.length();
	vector<int> pi(n);
	int k = 0;
	for (int i = 1; i < n; i++) {
		while (k > 0 && s[i] != s[k])
			k = pi[k - 1];
		if (s[i] == s[k])
			k++;
		pi[i] = k;
	}
	return pi;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		string s1, s2;
		cin >> s1;
		cin >> s2;
		vector<int> index;
		for (int i = 0; i < n; i++) {
			if (s1[i] != s2[i]) {
				index.push_back(i);
			}
		}
		bool ok = true;
		vector<pair<int, int> > ans;
		while (index.size() > 0 && ok) {
			vector<int> tmp;
			for (auto i : index) {
				if (s1[i] != s2[i]) {
					tmp.push_back(i);
				}
			}
			index = tmp;
			if (index.size() == 0) {
				break;
			}
			char cur = s1[index[0]];
			int nextIndex = -1;
			for (auto i : index) {
				if (s2[i] == cur) {
					nextIndex = i;
					break;
				}
			}
			if (nextIndex == -1) {
				bool tmpok = false;
				for (int i = 1; i < index.size(); i++) {
					if (cur == s1[index[i]]) {
						char c = s2[index[0]];
						ans.push_back({  index[i],index[0] });
						s2[index[0]] = s1[index[i]];
						s1[index[i]] = c;
						tmpok = true;
						break;
					}
				}
				if (!tmpok) {
					ok = false;
					break;
				}
			}
			else {
				ans.push_back({ nextIndex, nextIndex });
				char c = s1[nextIndex];
				s1[nextIndex] = s2[nextIndex];
				s2[nextIndex] = c;
				ans.push_back({ nextIndex,index[0] });
				c = s1[nextIndex];
				s1[nextIndex] = s2[index[0]];
				s2[index[0]] = c;
				ok = true;
			}
		}
		if (ok) {
			cout << "Yes" << endl;
			cout << ans.size() << endl;
			for (auto p : ans) {
				cout << p.first + 1 << " " << p.second + 1 << endl;
			}
		}
		else {
			cout << "No" << endl;
		}
	}
}