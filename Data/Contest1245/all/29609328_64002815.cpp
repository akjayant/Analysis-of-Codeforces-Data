#include<bits/stdc++.h>

using namespace std;

vector<char> ch;
vector<char> er;
int t, n, a, b, c;

int main(){
	cin >> t;
	for(int z=0;z<t;z++){
		cin >> n >> a >> b >> c;
		ch.resize(n);
		er.assign(n,0);
		int aa=0, bb=0, cc=0;
		for(int i = 0; i < n; i ++ ){
			cin >> ch[i];
			if(ch[i]=='R') bb++;
			if(ch[i]=='P') cc++;
			if(ch[i]=='S') aa++;
		}
		int winny=min(a,aa)+min(b,bb)+min(c,cc);
		if(winny*2>=n){
			cout << "YES\n";
			
			for(int i=0;i<n;i++){
				if(ch[i]=='R' && b>0){
					b--;
					er[i]='P';
				} else if(ch[i]=='P' && c>0){
					c--;
					er[i]='S';
				} else if(ch[i]=='S' && a>0){
					a--;
					er[i]='R';
				}
			}
			for(int i=0;i<n;i++){	
				if(er[i]==0){
					if(b>0){
						b--;
						er[i]='P';
					} else if(c>0){
						c--;
						er[i]='S';
					} else if(a>0){
						a--;
						er[i]='R';
					}
				}
			}
			for(char chr:er) cout << chr;
			cout << "\n";
		} else {
			cout << "NO\n";
		}
	}
return 0;
}