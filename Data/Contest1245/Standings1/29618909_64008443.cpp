#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main() {
	string s;
	cin >> s;
	
	vector<long long> fib(s.length()+1,0);
	
	int n=s.length();
	
	fib[0]=fib[1]=1;
	
	if (s[0]=='w'||s[0]=='m') {cout << 0 << endl; return 0;}
	
	for (int i=2;i<=n;++i) {
		fib[i]=fib[i-1];
		if ((s[i-1]=='u' || s[i-1]=='n')&&s[i-2]==s[i-1]) fib[i]=(fib[i-1]+fib[i-2])%1000000007; 
		if (s[i-1]=='m' || s[i-1]=='w') {cout << 0 << endl; return 0;}
	}
	cout << fib[n] << endl;
}