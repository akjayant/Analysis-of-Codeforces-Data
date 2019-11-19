#include<bits/stdc++.h>
using namespace std;

int t, n, m;
char str[2000];

int main()
{
    cin >> t;
    while(t--){
        scanf("%d %s", &n, str);

        int anss = n;
        for(int i = 0; i < n; i++){
            if(str[i] == '1'){
                anss = max(anss, 2 * (i + 1));
                int tmp = n - i;
                anss = max(anss, 2 * tmp);
            }
        }
        printf("%d\n", anss);
    }
    return 0;
}