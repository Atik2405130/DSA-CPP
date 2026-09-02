#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int>a(n + 1), cnt(k + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 1; i <= k; i++) cnt[i] += cnt[i - 1];
    vector<int>ans(n + 1);
    for(int i = n; i >= 1; i--){
        ans[cnt[a[i]]] = a[i];
        cnt[a[i]]--;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}