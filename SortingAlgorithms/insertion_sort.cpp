#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++){
        int val = a[i];
        int j = i - 1;
        while(j > 0 && a[j] > val){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = val;
    }
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
    return 0;
}