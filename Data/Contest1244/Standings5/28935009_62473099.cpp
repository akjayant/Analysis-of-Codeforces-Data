#include <bits/stdc++.h>

using namespace std;

int t, n;
char str[1005];
int main()
{
    scanf("%d",&t);
    while (t--){
        scanf("%d", &n);
        scanf("%s", str);
        int pos1 = -1, pos2 = -1;
        for (int i=0; i<n; i++){
            if (str[i] == '1'){
                pos1 = i;
                break;
            }
        }
        for (int i=n-1; i>=0; i--){
            if (str[i] == '1'){
                pos2 = i;
                break;
            }
        }
        if (pos1 == -1){
            cout<<n<<endl;
            continue;
        }
        int x = n-pos1, y = pos2+1;
        cout<<max(x,y)*2<<endl;
    }
}
