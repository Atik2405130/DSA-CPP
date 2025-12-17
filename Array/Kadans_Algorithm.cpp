#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int cursum=0;
    int maxsum=INT_MIN;
    vector<int>vec={1,2,3,4,5};
    for(int value:vec)
    {
        cursum+=value;
        if(cursum<0)
        {
            cursum=0;
        }    
        maxsum=max(maxsum,cursum);
    }
}

// Regular system //
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int arr[5]={1,2,3,4,5};
//     int maxsum=0;
//     for(int start=0;start<5;start++)
//     {
//         int cursum=0;
//         for(int end=start;end<5;end++)
//         {
//             cursum+=arr[end];
//             maxsum=max(maxsum,cursum);
//         }
//     }
//     cout<<maxsum;
// }