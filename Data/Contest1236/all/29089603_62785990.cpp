#include <iostream>
using namespace std;

int main()

{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--){
		int a,b,c,ans=0;
		cin>>a>>b>>c;
		if (c/2<=b){
			ans+=c/2;
			b-=c/2;
		}
		else{
			ans+=b;
			b=0;
		}

		if (b/2<=a){
			ans+=b/2;
			a-=b/2;
		}
		else{
			ans+=a;
			a=0;
		}

		cout<<ans*3<<endl;
	}
	return 0;
}