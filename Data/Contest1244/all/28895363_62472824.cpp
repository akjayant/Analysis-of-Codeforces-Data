#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1005;

int t, n;
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%s", s+1);
		int k = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] == '1'){
				k = n - i + 1;
				break;
			}
			if(s[n-i+1] == '1'){
				k = n - i + 1;
				break;
			}
		}
		printf("%d\n", max(n, k * 2));
	}
	return 0;
}
