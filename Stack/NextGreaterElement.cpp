#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    vector<int>arr={6,8,0,1,3};
    stack<int>s;
    vector<int>ans(arr.size(),0);
    for(int i=arr.size()-1;i>=0;i--)
    {
        while(s.size()>0 && s.top()<=arr[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    for(int val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}

// Later must be cleared //

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int,int>m;
//         stack<int>s;
//         vector<int>ans;
//         for(int i=nums2.size()-1;i>=0;i--)
//         {
//             while(s.size()>0 && s.top()<=nums2[i])
//             {
//                 s.pop();
//             }
//             if(s.empty())
//             {
//                 m[nums2[i]]=-1;
//             }
//             else
//             {
//                 m[nums2[i]]=s.top();
//             }
//             s.push(nums2[i]);
//         }
//         for(int i=0;i<nums1.size();i++)
//         {
//             ans.push_back(m[nums1[i]]);
//         }
//         return ans;
//     }
// };