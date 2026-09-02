#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1, m1, n2, m2; cin >> n1 >> m1 >> n2 >> m2;
    int a[n1 + 1][m2 + 1], b[n2 + 1][m2 + 1], c[n1 + 1][m2 + 1];
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= m1; j++)    cin >> a[i][j];
    }
    for(int i = 1; i <= n2; i++){
        for(int j = 1; j <= m2; j++)    cin >> b[i][j];
    }
    if(n2 != m1){
        cout << "Multiplication is not possible\n";
        return 0;
    }
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= m2; j++){
            c[i][j] = 0;
            for(int k = 1; k <= m1; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= m2; j++)    cout << c[i][j] << ' ';
        cout << endl;
    }
    return 0;
}