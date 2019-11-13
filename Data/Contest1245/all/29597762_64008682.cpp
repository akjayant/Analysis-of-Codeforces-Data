#include <iostream>
#include <string>
#define MAXN 100000
#define PRIME 1000000007
using namespace std;
int main(){
	int fib[MAXN] = {1, 1};
	for(int i=2; i<MAXN; i++)
		fib[i] = (fib[i-1] + fib[i-2]) % PRIME;
	long long ans = 1;
	int runlen = 1;
	char cstr[MAXN+1];
	cin >> cstr;
	string str(cstr);
	int last = str[0];
	if(str.find('m') != string::npos || str.find('w') != string::npos){
		cout << "0\n";
		return 0;
	}
	for(int i=1; i<=str.size(); i++){
		if(cstr[i] == last)
			runlen++;
		else if(last == 'u' || last == 'n'){
			ans = (ans * fib[runlen]) % PRIME;
			last = cstr[i];
			runlen = 1;
		}
		else{
			last = cstr[i];
			runlen = 1;
		}
	}
	cout << ans << endl;
}

			


	
