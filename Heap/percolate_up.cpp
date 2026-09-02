#include<bits/stdc++.h>
using namespace std;

int parent(int i){return i / 2;}

void percolate_up(vector<int>&a, int i){
    while(i > 1 && a[i] > a[parent(i)]){
        swap(a[i], a[parent(i)]);
        i = parent(i);
    }
}