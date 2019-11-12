#include<cstdio>
#include<algorithm>
using namespace std;

int k;
int tab[1005];

int main(){
	scanf("%d", &k);
	for(int l = 1; l <= k; l++){
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &tab[i]);
		}
		int L = 0;
		int R = n + 1;
		while(R - L > 1){
			int sr = (R + L)/2;
			int note = 0;
			for(int i = 1; i <= n; i++){
				if(tab[i] >= sr) note++;
			}
			if(note >= sr) L = sr;
			else R = sr;
		}
		printf("%d\n", L);
	}
	return 0;
}

//FUCK YOU WINDOWS