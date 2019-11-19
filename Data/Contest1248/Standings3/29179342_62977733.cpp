#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main (){
	int Q, q, p1, p2, imp1, imp2, i, n, nr;
	cin >> Q;
	for (q=1; q<=Q; q++){
        cin >> n;
        p1 = p2 = imp1 = imp2 = 0;
        for (i=1; i<=n; i++){
            cin >> nr;
            if (nr %  2 == 0) p1 ++ ;
            else imp1 ++;
        }
        cin >> n;
        for (i=1; i<=n; i++){
            cin >> nr;
            if (nr %  2 == 0) p2 ++ ;
            else imp2 ++;
        }
        cout << (long long)(p1)*p2 + (long long)(imp1)*imp2 << "\n";
	}
	return 0;
}
