#include <bits/stdc++.h>

using namespace std;

void solvre(){
	int n;
	string s, t;
	cin>>n>>s>>t;
	int found = 0;
	bool ans = true;
	char a, b;
	for(int i = 0; i<n; i++){
		if(s[i]!=t[i]){
			if(found>0){
				if(a!=s[i] || b!=t[i]){
					ans = false;
				}
			}else{
				a = s[i];
				b = t[i];
			}
			found++;
		}
	}
	if(found>2 || found==1) ans = false;
	if(ans) printf("Yes\n");
	else printf("No\n");
}

int main(){
	int t;
	cin>>t;
	while(t--) solvre();
}
