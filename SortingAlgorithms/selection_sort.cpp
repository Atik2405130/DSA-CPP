#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int min_idx = a[i];
        for(int j = i + 1; j <= n; j++){
            if(a[j] < a[min_idx]){
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
    return 0;
}