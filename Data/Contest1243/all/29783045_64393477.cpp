#include <bits/stdc++.h>
using namespace std;
long long n, k;
string s, t;
vector<pair<int, int> > potezi;
int ss[30], tt[30];
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> k;
while (k--){
	cin >> n >> s >> t;
	for (int i=0; i<30; i++) ss[i]=tt[i]=0;
	for (int i=0; i<n; i++){
		if (s[i]!=t[i]){
			ss[s[i]-'a']++;
			tt[t[i]-'a']++;
		}
	}
	bool ok=1; 
	for (int i=0; i<30; i++)
		if ((ss[i]+tt[i])%2) ok=0;
	if (!ok) cout << "No\n";
	else {
		cout << "Yes\n"; potezi.clear();
		for (int i=0; i<n; i++){
			if (s[i]!=t[i]){
				bool potez=0;
				for (int j=i+1; j<n and !potez; j++){
					if (s[i]==s[j]){
						potez=1;
						potezi.push_back(make_pair(j, i));
						swap(t[i], s[j]);
					}
				}
				for (int j=i+1; j<n and !potez; j++){
					if (s[i]==t[j]){
						potezi.push_back(make_pair(i+1, j));
						potezi.push_back(make_pair(i+1, i));
						swap(t[j], s[i+1]); swap(t[i], s[i+1]);
						potez=1;
					}
				}
				if (!potez) return 0;
			}
		}
		cout << potezi.size() << endl;
		for (int i=0; i<potezi.size(); i++){
			pair<int, int> kl=potezi[i];
			cout << kl.first+1 << " " << kl.second+1 << endl;
		}
	}
}
return 0;
}

