// next greater element
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    vector<int>arr={6,8,0,1,3};
    stack<int>st;
    vector<int>ans(arr.size(),0);
    for(int i=arr.size()-1;i>=0;i--) // for circular array: for(i=2*(arr.size()-1);i>=0;i--)
    {  // int idx=(i%(arr.size));
        while(!st.empty() && arr[i]>=st.top()) //i=idx; and continue
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    for(int val:ans){
        cout<<val<<" ";
    }
}