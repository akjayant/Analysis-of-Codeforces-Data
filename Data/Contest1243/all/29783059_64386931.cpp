#include <bits/stdc++.h>
using namespace std;
int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		string s,t;
		cin >> s >> t;
		int a=-1,b=-1,flag=0;
		for(int i=0;i<n;i++){
			if(s[i]==t[i])
				continue;
			if(a!=-1 and b!=-1){
				flag=1;
				break;
			}
			if(a==-1)
				a=i;
			else
				b=i;
		}
		if(b==-1 and a!=-1)
			flag=1;
		if(flag){
			cout << "No" << endl;
			continue;
		}
		if(t[a]==t[b] and s[b]==s[a])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}