#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>prices={7,1,5,3,6,4};
    int maxp=0;
    int bestbuy=prices[0];
    int n=prices.size();
    for(int i=1;i<n;i++)
    {
        if(prices[i]>bestbuy)maxp=max(maxp,prices[i]-bestbuy);
        bestbuy=min(bestbuy,prices[i]);
    }
    cout<<maxp<<endl;
}
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxp=0;
//         int bestbuy=prices[0];
//         for(int i=1;i<prices.size();i++)
//         {
//             if(prices[i]>bestbuy)maxp=max(maxp,prices[i]-bestbuy);
//             bestbuy=min(bestbuy,prices[i]);
//         }
//         if(maxp>0)return maxp;
//         else return 0;
//     }
// };