#include <bits/stdc++.h>

using namespace std;
void testcase(){
    int a , b, c;
    cin >> a >> b >> c;

    int ans = 0;
    while(c >= 2 && b){
        c -= 2;
        b--;
        ans += 3;
    }
    while(b >= 2 && a){
        b -= 2;
        a--;
        ans += 3;
    }
    cout << ans <<"\n";

}
int main()
{
    int t;
    cin >> t;
    while(t--){
        testcase();
    }





    return 0;
}
