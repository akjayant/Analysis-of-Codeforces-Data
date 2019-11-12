#include <iostream>
#include <algorithm>

using namespace std;

int arr[1010];

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);
        int best = 0;
        for(int sz = 1; sz <= n; sz++){
            if(arr[n - sz] >= sz)
                best = max(best, sz);
        }
        cout << best << endl;
    }

    return 0;
}
