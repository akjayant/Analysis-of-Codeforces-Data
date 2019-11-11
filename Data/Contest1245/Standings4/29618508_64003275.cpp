#include <bits/stdc++.h>

using namespace std;

vector<char> v;

char tab[200];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int r,p,s,n;
		cin >> n;
		cin >> r >> p >> s;
		string str;
		cin >> str;
		int cntr = 0;
		int cntp = 0;
		int cnts = 0;
		for(int i = 0; i < (int) str.size(); i++)
			if(str[i] == 'R')
				cntr++;
			else if(str[i] == 'P')
				cntp++;
			else
				cnts++;
		int ans = min(cntr,p);
		ans += min(cntp,s);
		ans +=min(cnts,r);
		if(ans >= (n + 1) / 2){
			cout << "YES" <<'\n';
			for(int i = 0; i < (int) str.size(); i++)
				if(str[i] == 'P' && s > 0){
					tab[i] = 'S';
					s--;
				}
				else if(str[i] == 'S' && r > 0){
					tab[i] = 'R';
					r--;
				}
				else if(str[i] == 'R' && p > 0){
					tab[i] = 'P';
					p--;
				}
			for(int i = 0; i < (int) str.size(); i++)
				if(tab[i] == 0){
					if(r > 0){
						tab[i] = 'R';
						r--;
					}
					else if(p > 0){
						tab[i] = 'P';
						p--;
					}
					else if(s > 0){
						tab[i] = 'S';
						s--;
					}
				}
			for(int i = 0; i < (int) str.size(); i++)
				cout << tab[i];
			cout << '\n';
			for(int i = 0; i < (int) str.size(); i++)
				tab[i] = 0;
		}
		else
			cout << "NO"<<'\n';
	}
	
	
	
	return 0;
}
