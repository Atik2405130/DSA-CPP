#include<bits/stdc++.h>
using namespace std;

int parent(int i){return i / 2;}
int left(int i){return 2 * i;}
int right(int i){return 2 * i + 1;}

// Pulling down the root of the Complete Binary Tree to the proper location;

// Recursive
void max_heapify(vector<int>& a, int i){
    int l = left(i), r = right(i);
    int n = a.size() - 1, mx;
    if(l > n)   return;
    if(r > n)   mx = l;
    else mx = (a[l] > a[r]) ? l : r;
    if(a[mx] <= a[i])    return;
    swap(a[i], a[mx]);
    max_heapify(a, mx);
}

// Iterative
void max_heapify(vector<int>&a, int i){
    int l = left(i), r = right(i), n = a.size() - 1, mx;
    while(l <= n){
        if(r > n)   mx = l;
        else mx = (a[l] > a[r]) ? l : r;
        if(a[mx] <= a[i])    break;
        swap(a[i], a[mx]);
        i = mx;
        l = left(i), r = right(i);
    }
}