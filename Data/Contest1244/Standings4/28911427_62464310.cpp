#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--){

        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = a / c;
        int y = b / d;
        if(x * c != a)
            x ++;
        if(y * d != b)
            y ++;
        if(x + y > k)
            cout << -1 << endl;
        else
            cout << x << " " << y << endl;
    }
	return 0;
}
