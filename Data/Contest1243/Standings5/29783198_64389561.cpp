#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        string a, b;
        cin >> n >> a >> b;

        vector<pair<int, int> > swaps;
        for(int i = 0; i < n - 1; i++){
            int loc_of_x = -1;
            for(int j = i + 1; j < n; j++){
                if(a[j] == a[i]){
                    loc_of_x = j;
                    break;
                }
            }

            if(loc_of_x != -1){
                swaps.push_back(make_pair(loc_of_x+1, i+1));
                swap(a[loc_of_x], b[i]);
                continue;
            }

            loc_of_x = -1;
            for(int j = i; j < n; j++){
                if(b[j] == a[i]){
                    loc_of_x = j;
                    break;
                }
            }

            if(loc_of_x != -1){
                swaps.push_back(make_pair(i+2, loc_of_x+1));
                swaps.push_back(make_pair(i+2, i+1));
                swap(a[i+1], b[loc_of_x]);
                swap(a[i+1], b[i]);
            }else{
                break;
            }
        }

        if(a == b){
            cout << "Yes" << endl;
            cout << swaps.size() << endl;
            for(int i = 0; i < swaps.size(); i++)
                cout << swaps[i].first << " " << swaps[i].second << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
