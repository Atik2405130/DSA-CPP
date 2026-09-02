#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&a, int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quick_sort(vector<int>&a, int l, int r){
    if(l >= r)   return;
    int partition_idx = f(a, l, r);
    quick_sort(a, l, partition_idx - 1);
    quick_sort(a, partition_idx + 1, r);
}

int main(){
    int n; cin >> n;
    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    quick_sort(a, 1, n);
    for(int i = 1; i <= n; i++) cout << a[i] <<  ' ';
    cout << endl;
    return 0; 
}