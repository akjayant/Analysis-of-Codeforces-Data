#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        vector<int> diff;
        for(int i = 0; i < n; i++)
            if(a[i] != b[i])
                diff.push_back(i);

        if(diff.size() != 2){
            cout << "No" << endl;
        }else{
            swap(a[diff[0]], b[diff[1]]);
            if(a == b)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
