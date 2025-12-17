//Only applicable in the sorted array
#include<iostream>
#include<vector>
using namespace std;

vector<int> pairsum(vector<int>nums,int target)
{
    vector<int>ans;
    int start=0;
    int end=nums.size()-1;
    while(start<end)
    {
        if(nums[start]+nums[end]>target)
        {
            end--;
        }
        else if(nums[start]+nums[end]<target)
        {
            start++;
        }
        else
        {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
    }
    return ans;
}
int main()
{
    vector<int>nums={2,7,11,15};
    int target=9;
    vector<int>answer=pairsum(nums,target);
    cout<<answer[0]<<endl<<answer[1]<<endl;
    return 0;
}