#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int datas[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
	cin>>n;
	for(int a=0;a<n;a++){
		cin>>datas[a];
	}
	sort(datas, datas+n);
	int R=n-1, L=0;
	bool con=1;
	LL h1=0, h2=0;
	while(L<=R){
		if(con){
			h1+=datas[R];
			R--;
		}
		else{
			h2+=datas[L];
			L++;
		}
		con^=1;
	}
	cout<<(h1*h1)+(h2*h2)<<endl;
    return 0;
}