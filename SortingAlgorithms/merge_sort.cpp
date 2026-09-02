#include<bits/stdc++.h>
using namespace std;

void conquer(vector<int>&a, int l, int mid, int r){
    vector<int>temp;
    int i = 1, j = mid + 1;
    while(i <= mid && j <= r){
        if(a[i] <= a[j])    temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while(i <= mid) temp.push_back(a[i++]);
    while(j <= r)   temp.push_back(a[j++]);
    for(int i = l; i <= r; i++) a[i] = temp[i - l];
}

void divide(vector<int>&a, int l, int r){
    if(l > r)   return;
    int mid = (l + r) >> 1;
    divide(a, l, mid);
    divide(a, mid + 1, r);
    conquer(a, l, mid, r);
}

int main(){
    int n; cin >> n;
    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    divide(a, 1, n);
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
    return 0;
}