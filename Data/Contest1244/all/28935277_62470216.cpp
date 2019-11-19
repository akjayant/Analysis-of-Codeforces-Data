#include <bits/stdc++.h>
#define MAXN 1100
using namespace std;


char seq[MAXN];
int n;



int main (){
	
	int t;
	cin >> t;
	
	while(t--){
		cin >> n;
		
		int res = n;
		cin >> &(seq[1]);
		
		for(int i = 1; i <= n; i++){
			if(seq[i] == '1'){
				int at = max(i, n-i+1)*2;
				res = max(res,at);
			}
		}
	
		cout << res << endl;
	}
}




