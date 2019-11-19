#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int llint;
llint arr[100005];
map <llint,int> m;
vector <llint> v;
int main()
{
	int n;
	llint k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		cin >> arr[i];
		v.push_back(arr[i]);
		m[arr[i]]+=1;
	}
	sort(arr,arr+n);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	if(v.size()==2) {
		llint raz=(v[1]-v[0]);
		raz-=k/min(m[v[1]],m[v[0]]);
		if(raz<0) cout << 0;
		else cout << raz;
		return 0;
	}
	llint mini=v[0],maxi=v[v.size()-1],ind1=1,ind2=v.size()-2;
	if(maxi-mini==0) {
		cout << 0;
		return 0;
	}
	while(k>0) {
		//cout << k << "\n";
		llint a=(v[ind1]-mini)*m[mini],b=(maxi-v[ind2])*m[maxi];
		llint x=min(k/m[mini],a);
		llint y=min(k/m[maxi],b);
		//cout << x << " " << y << "\n";
		//cout << "a\n";
		if(m[mini]<m[maxi]) {
			llint mini2=mini;
			mini+=min(k/m[mini],a/m[mini]);
			k-=min(k,a);
			ind1+=1;
			m[mini]+=m[mini2];
			//cout << "min\n";
			//cout << mini << " " << maxi << " " << k << "\n";
			if(k==0) break;
		}
		else {
			llint maxi2=maxi;
			maxi-=min(k/m[maxi],b/m[maxi]);
			k-=min(k,b);
			ind2-=1;
			m[maxi]+=m[maxi2];
			//cout << "max\n";
			//cout << mini << " " << maxi << " " << k << "\n";
			if(k==0) break;
		}
		if(maxi==mini) break;
		//cout << "b\n";
	}
	cout << maxi-mini;
	return 0;
}
