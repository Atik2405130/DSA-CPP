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

void percolate_up(vector<int>&a, int i){
    while(i > 1 && a[i] > a[parent(i)]){
        swap(a[i], a[parent(i)]);
        i = parent(i);
    }
}

void heap_delete(vector<int>&a, int i){
    if(i == a.size() - 1){
        a.pop_back();
    }
    int old_key = a[i];
    swap(a[i], a[a.size() - 1]);
    a.pop_back();
    if(old_key < a[i])  percolate_up(a, i);
    else max_heapify(a, i);
}

