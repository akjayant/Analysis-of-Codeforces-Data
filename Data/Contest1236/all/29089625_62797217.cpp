///By Stephan Ramirez dsramirezc@unal.edu.co
#include<bits/stdc++.h>
#define ms(a,v) memset(a,v,sizeof a)
#define ll long long
using namespace std;


int main(){
	#ifdef LOCAL
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	int mt[n][n];
	int cur=1;
	for(int k=0;k<n;k++){
        if(k%2==0){
            for(int i=0;i<n;i++){
                mt[i][k]=cur;
                cur++;
            }
        }else{
            for(int i=n-1;i>=0;i--){
                mt[i][k]=cur;
                cur++;
            }
        }
	}
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mt[i][j]);
        }
        printf("\n");
	}
	return 0;
}

