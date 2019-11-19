#include <bits/stdc++.h>

#define int long long
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, x) for(int i = 0; i < x; i++)
#define rforn(i, x) for(int i = x - 1; i >= 0; i--)

using namespace std;

template<typename T> void print(T a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << endl;
}

signed main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    pii coord = {1, 1};
    forn (a, n) {
    	forn (b, a + 1) {
    		swap(s[a], s[b]);

    		int balance = 0, mn = 0;
		    forn (i, n) {
		    	if (s[i] == '(')
		    		balance++;
		    	else
		    		balance--;
		    	mn = min(mn, balance);
		    }

		    balance = 0;
		   	string t = "";
		   	bool ok = true;
		   	forn (i, n) {
		   		if (s[i] == '(')
		   			balance++;
		   		else
		   			balance--;
		   		if (balance < 0)
		   			ok = false;
		   	}
		   	if (balance != 0)
		   		ok = false;

		   	if (ok) {
		   		t = s;
		   	}
		   	else {
		   		balance = 0;
			    int id = -1;
			    rforn (i, n) {
			    	if (balance == -mn) {
			    		id = i;
			    		break;
			    	}
			    	if (s[i] == '(') 
			    		balance++;
			    	else
			    		balance--;
			    }
			    if (id == -1) {
			    	swap(s[a], s[b]);
			    	break;
			    }
			    id++;
			    if (id != n)
			    	t = s.substr(id, n - id + 1);
			   	t += s.substr(0, id);
		   	}
		
			int res = 0;
			balance = 0;
			forn (i, n) {
				if (t[i] == '(')
					balance++;
				else
					balance--;
				if (balance == 0)
					res++;
				if (balance < 0) {
					res = 0;
					break;
				}
			}
			if (balance != 0)
				res = 0;

			if (ans < res) {
				coord.ff = b + 1;
				coord.ss = a + 1;
				ans = res;
			} 

			swap(s[a], s[b]);
    	}
    }

    cout << ans << '\n';
    cout << coord.ff << ' ' << coord.ss;
    return 0;
}
