#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);

    long long int k;
    cin >> k;    
    for(int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    long long int iter = 1;
    long long int left = 0;
    long long int right = vec.size()-1;
    long long int diff = vec.back() - vec.front();
    while(k>0 && right-left>1){
        long long int current_gap = vec[right]-vec[right-1]+vec[left+1]-vec[left];
        long long int subtract = min(k/iter,current_gap);
        diff-=subtract;

        k -= min(k,current_gap*iter);
        iter++;
        left++;
        right--;
    }
    if(k != 0 && left != right){
        long long int current_gap = vec[right]-vec[right-1];
        long long int subtract = min(k/iter,current_gap);
        diff-=subtract;
    }
    cout << diff << "\n";
}