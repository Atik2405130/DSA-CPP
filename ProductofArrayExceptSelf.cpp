#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>nums={1,2,3,4};
    int n=nums.size();
    vector<int>ans(n,1);
    vector<int>prefix(n,1);
    vector<int>suffix(n,1);
  //Prefix
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]*nums[i-1];
    }
        //Suffix
    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=suffix[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++)
    {
        ans[i]=prefix[i]*suffix[i];
    }
    for(int value:ans)cout<<value<<" "; 
}

// Brute Force //
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int>ans;
//         for(int i=0;i<nums.size();i++)
//         {
//             int m=1;
//             for(int j=0;j<nums.size();j++)
//             {
//                 if(i!=j)
//                 {
//                     m=m*nums[j];
//                 }
//             }
//             ans.push_back(m);
//         }
//         return ans; 
//     }
// };