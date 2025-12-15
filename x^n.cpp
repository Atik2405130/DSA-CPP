#include<iostream>
using namespace std;
int main()
{
    int n;
    double x;
    cin>>n>>x;
    long bin=n;
    double ans=1;
    while(bin>0)
    {
        if(bin%2==1)
        {
            ans*=x;
        }
        x*=x;
        bin=bin>>1;
    }
    cout<<ans;
}
// Leetcode Solution //
// class Solution {
// public:
//     double myPow(double x, int n) {
//         double ans=1;
//         long bin=n;
//         if(n<0)
//         {
//             x=1/x;
//             bin=-bin;
//         }
//         while(bin>0)
//         {
//             if(bin%2==1)
//             {
//                 ans*=x;
//             }
//             x*=x;
//             bin>>=1;
//         }
//         return ans;
//     }
// };