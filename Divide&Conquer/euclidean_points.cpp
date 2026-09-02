#include <bits/stdc++.h>
using namespace std;
const double INF = 1e18;

double dis(const pair<double,double>& a, const pair<double,double>& b){
    return sqrt((a.first - b.first)*(a.first - b.first) + 
                (a.second - b.second)*(a.second - b.second));
}

double min_dis(vector<pair<double,double>>& p, int l, int r){
    if(r - l + 1 <= 3){
        double ans = INF;
        for(int i = l; i <= r; i++){
            for(int j = i+1; j <= r; j++){
                ans = min(ans, dis(p[i], p[j]));
            }
        }
        return ans;
    }
    int mid = (l + r) / 2;
    double midx = p[mid].first;
    double dl = min_dis(p, l, mid);
    double dr = min_dis(p, mid+1, r);
    double d = min(dl, dr);

    vector<pair<double,double>> strip;
    for(int i = l; i <= r; i++){
        if(abs(p[i].first - midx) < d) strip.push_back(p[i]);
    }
    sort(strip.begin(), strip.end(), [](const pair<double,double>& a, const pair<double,double>& b){
        return a.second < b.second;
    });

    for(int i = 0; i < (int)strip.size(); i++){
        for(int j = i+1; j < (int)strip.size() && j <= i+7; j++){
            d = min(d, dis(strip[i], strip[j]));
        }
    }
    return d;
}

int main(){
    int n; cin >> n;
    vector<pair<double,double>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    double ans = min_dis(p, 0, n-1);
    cout << fixed << setprecision(6) << ans << "\n";
    return 0;
}
