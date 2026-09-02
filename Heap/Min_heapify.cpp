#include<bits/stdc++.h>
using namespace std;

int parent(int i){return i / 2;}
int left(int i) {return 2 * i;}
int right(int i){return 2 * i + 1;}

// Pulling down the root of the Complete Binary Tree to the proper location;

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

// Iterative:
void min_heapify(vector<int>&a, int i){
    int n = a.size() - 1, l = left(i), r = right(i), mn;
    while(l <= n){
        if(r > n)   mn = l;
        else mn = (a[l] < a[r]) ? l : r;
        if(a[mn] >= a[i])    break;
        swap(a[i], a[mn]);
        i = mn;
        l = left(i), r = right(i);
    }
}