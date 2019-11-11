#include<bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> pii;

int32_t main(){
	int tests; cin >> tests;
	//dati due interi determina se sono coprimi
	for(int t=0; t<tests; ++t){
		int n, a1, b1, c1; cin >> n >> a1 >> b1 >> c1;
		string s; cin >> s;
		int a2=0, b2=0, c2=0;
		for(char c:s){
			if(c == 'R') ++a2;
			if(c == 'P') ++b2;
			if(c == 'S') ++c2;
		}
		bool yes=(min(a1, c2)+min(b1, a2)+min(c1, b2)) >= ceil(float(n)/2);
		if(!yes) cout << "no" << endl;
		else {
			cout << "yes" << endl;
			int am=min(a1, c2);
			int bm=min(b1, a2);
			int cm=min(c1, b2);
			for(char c:s){
				if(c == 'S'){
					if(am){
						cout << 'R';
						--am;
						--a1;
					}
					else if(b1>bm){
						cout << 'P';
						--b1;
					}
					else if(c1>cm){
						cout << 'S';
						--c1;
					}

				}
				if(c == 'R'){
					if(bm){
						cout << 'P';
						--bm;
						--b1;
					}
					else if(c1>cm){
						cout << 'S';
						--c1;
					}
					else if(a1>am){
						cout << 'R';
						--a1;
					}
				}
				if(c == 'P'){
					if(cm){
						cout << 'S';
						--cm;
						--c1;
					}
					else if(a1>am){
						cout << 'R';
						--a1;
					}
					else if(b1>bm){
						cout << 'P';
						--b1;
					}
				}
			}
		}
		cout << endl;
	}
}
