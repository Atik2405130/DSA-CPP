#include<bits/stdc++.h>
using namespace std;
int ans = 0;

void conquer(vector<int>&a, int l, int mid, int r){
    int i = l, j = mid + 1;
    vector<int>temp;
    while(i <= mid && j <= r){
        if(a[i] < a[j]) temp.push_back(a[i++]);
        else{
            temp.push_back(a[j++]);
            ans += mid - i + 1;
        }
    }
    while(i <= mid) temp.push_back(a[i++]);
    while(j <= r)   temp.push_back(a[j++]);
    for(int i = l; i <= r; i++){
        a[i] = temp[i - l];
    }
}

void divide(vector<int>&a , int l, int r){
    if(l >= r)  return;
    int mid = (l + r) / 2;
    divide(a, l, mid);
    divide(a, mid + 1, r);
    conquer(a, l, mid, r);
}