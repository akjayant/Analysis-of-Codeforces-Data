#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,i,j,s[750005],sm;
	bool same=false,dif=false;
	int k;
	char ss[200005];
	cin >> n >> k >> ss;
	for(i=0;i<n;i++){
		if(ss[i]=='W') s[i]=1;
		else s[i]=0;
		s[n+i]=s[i];
		s[2*n+i]=s[i];
	}
	for(i=1;i<=n;i++){
		if(s[i]==s[i+1]){
			same=true;
			sm=i;
		} else {
			dif=true;
		}
	}
	if(!same){
		if(k%2==0){
			for(i=1;i<=n;i++){
				if(s[i-1]==1) cout << "W";
				else cout << "B";
			}
			cout << endl;
		} else {
			for(i=1;i<=n;i++){
				if(s[i-1]==1) cout << "B";
				else cout << "W";
			}
			cout << endl;
		}
		return 0;
	}
	if(!dif){
		for(i=1;i<=n;i++){
			if(s[i-1]==1) cout << "W";
			else cout << "B";
		}
		cout << endl;
		return 0;
	}
	while(1){
		if(s[sm]==s[sm+1]) sm=(1+sm)%n;
		else break;
	}
	vector<int> st,en;
	for(i=sm+n;i<sm+2*n;i++){
		if(s[i-2]==s[i-1]&&s[i-1]!=s[i]&&s[i]!=s[i+1]){
			st.push_back(i);
		}
		if(s[i-1]!=s[i]&&s[i]!=s[i+1]&&s[i+1]==s[i+2]){
			en.push_back(i);
		}
	}
	int d,a,b;
	for(i=0;i<st.size();i++){
		a=st[i]%n; b=en[i]%n;
		a=a+n; b=b+n;
		if(a>b) b=b+n;
		if(k%2==1) for(j=a;j<=b;j++) s[j%n]=1-s[j%n];
		d=b-a+1;
		if(d%2==0) d=d/2;
		else d=(d+1)/2;
		d=min(d,k);
		for(j=a;j<a+d;j++) s[j%n]=s[(a-1)%n];
		for(j=b;j>b-d;j--) s[j%n]=s[(b+1)%n];
	}
	for(i=1;i<=n;i++){
		if(s[i-1]==1) cout << "W";
		else cout << "B";
	}
	cout << endl;
	return 0;
}