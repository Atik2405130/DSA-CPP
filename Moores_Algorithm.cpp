// Moores voting algorithm //


#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>vec={1,2,2,1,1};
    int f=0;
    int ans=0;
    for(int i=0;i<vec.size();i++)
    {
        if(f==0)ans=vec[i];
        if(ans==vec[i])f++;
        else f--;
    }
    int count = 0;
    for(int num : vec) {
        if(num == ans) count++;
    }
    if(count > vec.size() / 2)
    cout << ans;
    else
    cout << "No majority element";
}










//Majority Element
//exist more than floor of (n/2) times

//////       BRUTE FORCE    //////
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int major;
//         int n=nums.size();
//         for(int value:nums)
//         {
//             int frequency=0;
//             for(int element:nums)
//             {
//                 if(value==element)
//                 {
//                     frequency++;
//                 }
//             }
//             if(frequency>(int)(n/2))
//             {
//                 major=value;
//                 return major;
//             }
//         }
//         return major;
//     }
// };

////// For soting vector ////



//   sort(nums.begin(),nums.end());
