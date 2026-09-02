#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<double> &v) {
    for (int i = 1; i < v.size(); i++) {
        double key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main(){
    int n; cin >> n;
    vector<double>a(n + 1);
    vector<vector<double>>b(n);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[min(n - 1, (int)floor(n * a[i]))].push_back(a[i]);
    }
    for(int i = 0; i < n; i++){
        insertion_sort(b[i]);
    }
    vector<double>ans;
    for(int i = 0; i < n; i++){
        for(auto ele : b[i])    ans.push_back(ele);
    }
    for(auto ele : ans) cout << ele << '\n';
    return;
}