#include<bits/stdc++.h>
using namespace std;
const int N =1e5+9;
const int mod = 1e9+7;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int mat[n][n];
    int i=0,j=0,c=1;
    while(c<=(n*n)){
    	mat[i][j] = c++;
    	if(j&1){
    		i--;
    		if(i==-1) i++,j++;
		}
		else{
			i++;
			if(i==n) i--,j++;
		}
	}
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++)
    		cout<<mat[i][j]<<" ";
    	cout<<"\n";
	}
	return 0;
}