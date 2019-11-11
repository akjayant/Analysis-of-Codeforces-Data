#include <iostream>
using namespace std;
#define maxn 300005

int n,a,b,c;
int t;
char A[105];
char B[105];
int r,p,s;
int lr,lp,ls;
int cnt;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		cin >> a >> b >> c;
		r = p = s = cnt = lr = lp = ls = 0;
		for (int i = 0;i<n;i++){
			cin >> A[i];
			if (A[i] == 'R') r++;
			if (A[i] == 'P') p++;
			if (A[i] == 'S') s++;
		}
		if (a>s) {
			lr = a-s;
			cnt += s;
		}else cnt += a;
		if (b>r) {
			lp = b-r;
			cnt += r;
		} else cnt += b;
		if (c>p) {
			ls = c-p;
			cnt += p;
		} else cnt +=c;
		for (int i = 0;i<n;i++){
			if (A[i] == 'R') {
				if (b){
					B[i] = 'P';
					b--;
				}else if (lr){
					B[i] = 'R';
					lr--;
				}else if (ls){
					B[i] = 'S';
					ls--;
				}
			}
			if (A[i] == 'P') {
				if (c){
					B[i] = 'S';
					c--;
				}else if (lr){
					B[i] = 'R';
					lr--;
				}else if (lp){
					B[i] = 'P';
					lp--;
				}
			}
			if (A[i] == 'S') {
				if (a){
					B[i] = 'R';
					a--;
				}else if (lp){
					B[i] = 'P';
					lp--;
				}else if (ls){
					B[i] = 'S';
					ls--;
				}
			}
		}
		
		if ((n%2 && cnt > n/2) || (!(n%2) && cnt >= n/2)){
			cout << "YES" << endl;
			for (int i = 0;i<n;i++) cout << B[i];
		} 
		else cout << "NO";
		cout << endl;

	}

}