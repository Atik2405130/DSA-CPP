#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &a, int n, int exp) {
    vector<int> cnt(10, 0);
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++) cnt[(a[i] / exp) % 10]++;
    for(int i = 1; i <= 9; i++) cnt[i] += cnt[i - 1];
    for(int i = n; i >= 1; i--){
        int val = (a[i] / exp) % 10;
        ans[cnt[val]] = a[i];
        cnt[val]--;
    }
    for(int i = 1; i <= n; i++)
        a[i] = ans[i];
}

int main(){
    int n; 
    cin >> n;
    vector<int> a(n + 1);
    int mx = INT_MIN;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int exp = 1;
    while(mx / exp > 0){
        count_sort(a, n, exp);
        exp *= 10;
    }

    for(int i = 1; i <= n; i++)  cout << a[i] << ' ';
    cout << endl;
}
