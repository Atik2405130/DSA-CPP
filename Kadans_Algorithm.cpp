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