#include<bits/stdc++.h>

using namespace std;

#define Q int t, q; scanf("%d", &t); for(q=1; q<=t; q++)
#define lli long long int

int zero[1000000];

int main()
{
    Q
    {
        int n, i;
        vector<int> v;
        string a, b;
        cin >> n >> a >> b;
        for(i=0; i<n; i++){
            if(a[i] != b[i]){
                v.push_back(i);
            }
        }
        if(v.size() == 0){
            printf("Yes\n");
        }
        else if(v.size() == 2){
            if(a[v[0]] == a[v[1]] && b[v[0]]==b[v[1]]){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else{
            printf("No\n");
        }

    }

    return 0;
}
