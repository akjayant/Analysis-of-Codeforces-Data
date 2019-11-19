#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int sticks[100005];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &sticks[i]);
	}
	sort(sticks + 1, sticks + n + 1);
	int shorts = 0, longs = 0;
	for(int i = 1; i <= n; i++){
		if(i <= (n/2)) shorts += sticks[i];
		else longs += sticks[i];
	}
	long long score = (long long)shorts*(long long)shorts + (long long)longs*(long long)longs;
	printf("%I64d", score);
	return 0;
}