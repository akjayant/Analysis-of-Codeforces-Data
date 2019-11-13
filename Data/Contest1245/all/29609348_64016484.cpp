#include<bits/stdc++.h>
using namespace std;

#define db double
#define MAXN 30005

inline int read()
{
    register int x = 0 , ch = getchar();
    while( !isdigit( ch ) ) ch = getchar();
    while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();
    return x;
}

int n,m;
int a,b,c;
int x,y,z;
string s;

void rd() {
	cin >> n; 
	cin >> a >> b >> c;
	cin >> s;
	x = y = z = 0;
	for(int i = 0; i < s.size(); i ++)  {
		if(s[i] == 'P') z ++;
		if(s[i] == 'S') x ++;
		if(s[i] == 'R') y ++;
	}
}
char an[MAXN]; 

signed main()
{
	int T;
	cin >> T;
	while(T --) {
		rd();
		for(int i = 0; i < n; i ++)
			an[i] = '%';
		int ans = 0;
		ans = min(a,x) + min(b,y) + min(c,z);
		if(ans >= ((n+1)>>1)) {
			cout<<"YES\n";
			for(int i = 0; i < n; i ++) {
				if(s[i] == 'P' && c > 0)  {
					c --;
					an[i] = 'S';
				}
				
				if(s[i] == 'S' && a > 0)  {
					a --;
					an[i] = 'R';
				}
				if(s[i] == 'R' && b > 0)  {
					b --;
					an[i] = 'P';
				}
			}
		//	for(int i = 0; i < n; i ++)
		//		cout<<an[i];
		//	cout<<"\n";
		//	cout<<a<<" "<<b<<" "<<c<<"\n";
		//	cout<<"\n";
			for(int i = 0; i < n; i ++) 
			if(an[i] == '%'){
				if(a > 0) {
					an[i] = 'R';
					a --;
					continue;
				}
				if(b > 0) {
					an[i] = 'P';
					b --;
					continue;
				}
				if(c > 0) {
					an[i] = 'S';
					c --;
					continue;
				}
			}
			for(int i = 0; i < n; i ++)
				cout<<an[i];
			cout<<"\n";
		} else {
			cout<<"NO\n";
		}
	}
	return 0;
}
/*
1
4
2 1 1
PPRR
*/