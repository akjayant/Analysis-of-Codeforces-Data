#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t-- > 0){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		int cont=0;
		int pos1 = -1, pos2 = -1;
		for (int i=0; i<n; i++){
			if(s[i] != t[i]){
				cont++;
				if(pos1 == -1) pos1 = i;
				else pos2 = i;
			}
		}
		if(cont == 2 && s[pos1] == s[pos2] && t[pos2] == t[pos1]) puts("Yes");
		else puts("No");
	}
}
