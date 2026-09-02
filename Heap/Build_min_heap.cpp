#include<bits/stdc++.h>
using namespace std;

int parent(int i){return i / 2;}
int left(int i) {return 2 * i;}
int right(int i){return 2 * i + 1;}

// Recursive:
void min_heapify(vector<int>&a, int i){ 
    int n = a.size() - 1, l = left(i), r = right(i), mn;
    if(l > n)   return;
    if(r > n)   mn = l;
    else mn = (a[l] < a[r]) ? l : r;
    if(a[mn] >= a[i])    return;
    swap(a[mn], a[i]);
    min_heapify(a, mn); 
}

void build_min_heap(vector<int>&a){
    int n = a.size() - 1;
    for(int i = n / 2; i >= 1; i--){
        min_heapify(a, i);
    }
}