#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define x first
#define y second
#define mp make_pair

int br[30][2], n;
string s, t;
vector <pii> res;

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
	memset(br, 0, sizeof(br));
	res.clear();
	for(int i = 0 ; i < n ; ++i){
		br[s[i] - 'a'][0]++;
		br[t[i] - 'a'][1]++;
	}
	bool p = 1;
	for(int i = 0 ; i < 26 ; ++i){
		int x = br[i][0] + br[i][1];
		if(x & 1){
			cout << "No" << endl;
			p = 0;
			break;
		}
	}
	if(!p)
		continue;
	cout << "Yes" << endl;
	for(int i = 0 ; i < n ; ++i){
		int prvi = s[i] - 'a';
		int drugi = t[i] - 'a';
		if(s[i] == t[i])
			continue;
		bool je = 0;
		for(int j = i + 1 ; j < n ; ++j){
			if(s[j] == s[i]){
				res.push_back(mp(j, i));
				swap(t[i], s[j]);
				je = 1;
				break;
			}
		}
		if(!je){
			for(int j = i + 1 ; j < n ; ++j){
				if(t[j] == s[i]){
					res.push_back(mp(i, i));
					res.push_back(mp(i, j));
					swap(t[j], t[i]);
					break;
				}
			}
		}
	}
	cout << (int)res.size() << endl;
	for(int i = 0 ; i < (int)res.size() ; ++i){
		cout << res[i].x + 1 << ' ' << res[i].y + 1 << endl;
	}
}

return 0;
}

