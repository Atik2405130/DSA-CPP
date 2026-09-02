#include<bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;

int parent(int i){return i / 2;}
int left(int i) {return 2 * i;}
int right(int i){return 2 * i + 1;}

const int N = (int)1e5 + 10;
int heap[N];

void push(vector<int>&heap, int val){
    heap.push_back(val);
    int i = heap.size() - 1;
    int par = parent(i);
    while(par >= 1 && heap[i] > heap[par]){
        swap(heap[par], heap[i]);
        i = par;
        par = parent(i);
    }
}

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

void pop(vector<int>&heap){  // Extract Maximum
    int n = heap.size() - 1;
    if(n < 1)   return;
    if(n == 1){
        heap.pop_back();
        return;
    }
    swap(heap[1], heap[n]);
    heap.pop_back();
    if(--n) max_heapify(heap, 1);
}

int top(vector<int>&heap){
    if(heap.size() == 1) return -INF;
    int ans = heap[1];
    pop(heap);
    return ans;
}