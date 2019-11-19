#include <bits/stdc++.h>
using namespace std;
long long Read() {
	long long num=0;
	char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) {
		num=(num<<3)+(num<<1)+ch-'0';
		ch=getchar();
	}
	return num;
}
int main() {
	int t;
	cin>>t;
	while (t--) {
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		int ans1=a/c;
		if (a%c) ans1++;
		int ans2=b/d;
		if (b%d) ans2++;
		if (ans1+ans2>e) cout<<-1<<endl;
		else cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
