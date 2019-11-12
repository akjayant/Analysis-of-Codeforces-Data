// TY Swistakk 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;
typedef long double ld;
 
const ll N = 200050;
const ll N1 = 100500;
const ll mod = 1000000007;
 
using namespace std;
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;}
 
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1<<" | ";
  __f(comma+1, args...);}
#else
#define trace(...)
#endif

int xd[30];
string s1, s2;
int n;
bool aea[60];
vector <pair <int, int>> cambios;
int primer(char c, string s, string sa){
	int l = s.size();

	for(int i = 0; i < l; i++){
		if(s[i] == c and sa[i] != c) return i;
	}

	return -1;
}

int seco(char c, int j, string s, string sa){
	int l = s.size();
	for(int i = 0; i < l; i++){
		if(i == j) continue;
		if(s[i] == sa[i]) continue;

		if(s[i] == c) return i;
	}
}

void camb(int i, int j){
	char c1 = s1[i];
	char c2 = s2[j];
	swap(c1, c2);
	s1[i] = c1;
	s2[j] = c2;
}
void recover(){
	for(int i = 0; i < 26; i++){
		char c = (char)(i + 'a');
		//trace(c, cambios.size());
		//buscaremos para el caracter c
		int m1 = 0;
		for(int j = 0; j < n; j++){
			if(s1[j] == c) m1++;
		}
		int m2 = 0;
		for(int j = 0; j < n; j++){
			if(s2[j] == c) m2++;
		}
		if(m1 > m2){
			//se cambia de la cadena 1 a la cadena 2
			for(int j = 0; j < n; j++){
				if(s1[j] == c and s2[j] != c){
					int pos = primer(c, s2, s1);
					if(pos != -1){
						cambios.push_back({pos, pos});
						cambios.push_back({pos, j});
						camb(pos, pos);
						camb(pos, j);
					}
					else{
						pos = seco(c, j, s1, s2);
						cambios.push_back({pos, j});
						camb(pos, j);
					}
				}
			}
		}
		else{
			//se cambia de la cadena 1 a la cadena 2
			for(int j = 0; j < n; j++){
				if(s2[j] == c and s1[j] != c){
					int pos = primer(c, s1, s2);
					if(pos != -1){
						cambios.push_back({pos, pos});
						cambios.push_back({j, pos});
						camb(pos, pos);
						camb(j, pos);
					}
					else{
						pos = seco(c, j, s2, s1);
						cambios.push_back({j, pos});
						camb(j, pos);
					}
				}
			}
		}
	}
}

int main(){

	fastio;
  	int t;
  	cin >> t;

  	while(t--){
  		cambios.clear();
  		for(int i = 0; i < 30; i++) xd[i] = 0;
  		cin >> n;

  		cin >> s1 >> s2;
  		
  		for(int i = 0; i < n; i++){
  			
  			xd[s1[i] - 'a']++;
  			xd[s2[i] - 'a']++;
  		}
  		bool cump = true;
  		for(int i = 0; i < 30; i++){
  			if(xd[i] % 2 != 0) {cump = false; break;}
  		}

  		if(!cump) cout << "No" << endl; 
  		else{
  			cout << "Yes" << endl;
  			recover();
  			cout << cambios.size() << endl;
  			for(auto x: cambios) cout << x.ff + 1 << " " << x.ss + 1 << endl;
  		}
  	}

  	return 0;
}

