#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int n;
        scanf("%d", &n);
        string str;
        cin >> str;
        str = "#" + str;
        int maxs = n;
        for(int i=1; i<=n; i++){
            if(str[i] == '1'){
                maxs = max(maxs, i+i);
                maxs = max(maxs, i+n-i+1);
            }
        }
        for(int i=n; i>=1; i--){
            if(str[i] == '1'){
                maxs = max(maxs, 2*(n-i+1));
                maxs = max(maxs, n-i+1+i);
            }
        }
        cout << maxs << endl;
    }
}

