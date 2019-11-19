#include <bits/stdc++.h>
#define MAXN -1
using namespace std;



int teto(int a, int b){
	return a/b + (a%b>0);
}


int main (){
	int t;
	cin >> t;
	
	while(t--){
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		
		int qx = teto(a,c);
		int qy = k - qx;
		
		if(qy < 1 or qy*d < b){
			cout << -1 << endl;
			continue;
		}else{
			cout << qx << " " << qy << endl;
		}
		
	}
	
	
	
	
	
}
