#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
#define x first
#define y second
#define mp make_pair

int n;
string s, t;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int temp;
cin >> temp;
while(temp--){
	cin >> n;
	cin >> s;
	cin >> t;
	vector <int> v;
	for(int i = 0 ; i < n ; ++i){
		if(s[i] != t[i]){
			v.push_back(i);
		}
	}
	if((int)v.size() == 0){
		cout << "Yes" << endl;
		continue;
	}
	if((int)v.size() != 2){
		cout << "No" << endl;
		continue;
	}
	int x = v[0];
	int y = v[1];
	if(t[x] == t[y] && s[x] == s[y]){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}

return 0;
}

