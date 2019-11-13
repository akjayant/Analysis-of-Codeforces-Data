#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }

template <typename T> inline T read(){
    T sum = 0;
    int fl = 1,ch = getchar();
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') fl = -1;
    for(; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
    return sum * fl;
}

int n,k;
int sum[30],S[30],T[30];

string s,t;

inline void init(){
	memset(sum,0,sizeof(sum));
	memset(S,0,sizeof(S));
	memset(T,0,sizeof(T));
}

inline void Solve (){
	while(k--){
		init();
		n = read<int>();
		cin >> s >> t;
		bool flag = true;
		for(int i = 0; i < n; i++){
			sum[s[i] - 'a']++;
			sum[t[i] - 'a']++;
			S[s[i] - 'a']++;
			T[t[i] - 'a']++;
		}
		for(int i = 0; i < 26; i++){
			if(sum[i] % 2) flag = false;
		}
		if(!flag){
			puts("No");
			continue;
		}
		vector <pii> ans;
		for(int i = 0; i < n; i++){
			if(s[i] != t[i]){
				int last = 0;
				for(int j = i + 1; j < n; j++){
					if(t[j] == t[i]){
						last = j;
						break;
					}
				}
				if(last){
					ans.pb(mp(i,last));
					swap(s[i],t[last]);
					continue;
				}
				last = 0;
				for(int j = i + 1; j < n; j++){
					if(t[i] == s[j]){
						last = j;
						break;
					}
				}			
				if(last){
					ans.pb(mp(last,n - 1));
					ans.pb(mp(i,n - 1));
					swap(s[last],t[n - 1]);
					swap(s[i],t[n - 1]);
				}
			}
		}
		puts("Yes");
		printf("%d\n",ans.size());
		for(int i = 0; i < ans.size(); i++){
			printf("%d %d\n",ans[i].first + 1,ans[i].second + 1);
		}
	}
}

inline void Input (){
	k = read<int>();
}

int main(){
	Input();
	Solve();
	return 0;
}
