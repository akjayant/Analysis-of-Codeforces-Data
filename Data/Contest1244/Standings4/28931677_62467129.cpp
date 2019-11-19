#include <bits/stdc++.h>
#define fs first
#define sc second
#define mx 100005
#define mod 1000000007
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define all(a) a.begin(),a.end()
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b, c, d, k;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		int ansi = -1, ansj;
		for(int i = 0; i<=((a+c-1)/c); i++){
			for(int j = 0; j<=((b+d-1)/d); j++){
				if(i + j <= k && i*c >= a && j*d>=b){
					ansi = i;
					ansj = j;
					break;
				}
			}
		}
		if(ansi == -1) printf("-1\n");
		else printf("%d %d\n", ansi, ansj);
	}
	return 0;
}