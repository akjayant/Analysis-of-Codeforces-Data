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
char st[mx];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		scanf("%s", st);
		int one = 0;
		int k = -1, l;
		for(int i = 0; i<n; i++){
			if(st[i]=='1') {
				one++;
				if(k == -1) k = i;
				l = i;
			}

		}
		if(one == 0){
			printf("%d\n", n);
		} else{
			printf("%d\n", max((l+1)*2, (n-k)*2));
		}

	}
	return 0;
}