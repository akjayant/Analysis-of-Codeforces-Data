#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
const int N = 1010;
int a[N];
inline int cmp(const int &a, const int &b) {return a > b;}
int main()
{
    int n, T;
    cin>>T;
    while(T--){
        cin>>n;
        int ans = 0;
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; ++i) if (i <= a[i]) ans = i;
        printf("%d\n", ans);
    }    
    // system("pause");
}