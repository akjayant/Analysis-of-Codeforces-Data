#include <iostream>

using namespace std;

int main(){
	int T; cin>>T;
	for(int t=0; t<T; t++){
		int N; cin>>N;
		int a, b, c; cin>>a>>b>>c;
		string s; cin>>s;
		int vic = 0;
		string seq = string(N, '-');
		for(int n=0; n<N; n++){
			if(s[n]=='R'){
				if(b>0){
					b--;
					seq[n] = 'P';
					vic++;
				}
			} else if(s[n]=='P'){
				if(c>0){
					c--;
					seq[n] = 'S';
					vic++;
				}
			} else {
				if(a>0){
					a--;
					seq[n] = 'R';
					vic++;
				}
			}
		}
		if(vic*2>=N){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
			continue;
		}
		for(int n=0; n<N; n++){
			if(seq[n] == '-'){
				if(a>0){
					a--;
					seq[n] = 'R';
				} else if(b>0){
					b--;
					seq[n] = 'P';
				} else {
					seq[n] = 'S';
					c--;
				}
			}
		}
		cout << seq << endl;
	}	
	return 0;
}
