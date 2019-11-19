#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int f_st = -1;
        int l_st = -1;
        for(int i = 0; i < n; i++){
            bool st;
            char x;
            cin >> x;
            st = (x == '1');
            if(st){
                if(f_st == -1)
                    f_st = i;
                l_st = i;
            }
        }

        if(f_st == -1 || l_st == -1){
            cout << n << endl;
            continue;
        }

        int sol_for_f = max(f_st+1 + max(f_st + 1, n - f_st), n-f_st + max(f_st + 1, n - f_st));
        int sol_for_l = max(l_st+1 + max(l_st + 1, n - l_st), n-l_st + max(l_st + 1, n - l_st));
        cout << max(max(n, sol_for_f), sol_for_l) << endl;
    }
    return 0;
}
