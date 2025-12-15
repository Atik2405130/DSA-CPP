//#include<iostream>
//using namespace std;
// #include<iostream>
// using namespace std;
// int main()
// {
//     int arr[10];
//     for(int i=0;i<10;i++)
//     {
//         cin>>arr[i];
//     }
//     int max=arr[0];
//     int imax=0;
//     for(int i=0;i<10;i++)
//     {
//         if(arr[i]>max)
//         {
//             max=arr[i];
//             imax=i;
//         }
//     }
//     int ismax=0;
//     cout<<"Maximum number in the array is "<<max<<endl;
//     int smax=arr[0];
//     for(int j=0;j<10;j++)
//     {
//         if(arr[j]>smax && arr[j]<max)
//         {
//             smax=arr[j];
//             ismax=j;
//         }
//     }
//     cout<<"Secondary Max is "<<smax<<endl;
//     int temp=arr[imax];
//     arr[imax]=smax;
//     arr[ismax]=temp;
//     cout<<arr[imax]<<arr[ismax]<<endl;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int>vec;//0
//     //vec.push_back(25);
//     //cout<<"size= "<<vec.size()<<endl;
//     vec.push_back(0);//Insert Value
//     vec.push_back(1);
//     vec.push_back(2);
//     vec.push_back(3);
//     vec.push_back(4);//Capacity doubled in each case not size(elements)
//     cout<<"size = "<<vec.size()<<endl;
//     cout<<vec.capacity()<<endl;// Capacity 
//     //vec.pop_back();//delete element from the last
//     //for(int val:vec){
//     //cout<<val<<endl;
//     //}
// }
<<<<<<< HEAD
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n=5;
//     int arr[]={1,2,3,4,5};
//     for(int start=0;start<n;start++)
//     {
//         for(int end=start;end<n;end++)
//         {
//             for(int i=start;i<=end;i++)
//             {
//                 cout<<arr[i];
//             }
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n=5;
//     int arr[5]={1,2,3,4,5};
//     int maxSum=INT_MIN;
//     for(int start=0;start<n;start++)
//     {
//         int currsum=0;
//         for(int end=start;end<n;end++)
//         {
//             currsum+=arr[end];
//             maxSum=max(currsum,maxSum);
//         }
//     }
//     cout<<"max subarray sum = "<<maxSum<<endl;
// }
=======

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5};
    int maxsum=0;
    for(int start=0;start<5;start++)
    {
        int cursum=0;
        for(int end=start;end<5;end++)
        {
            cursum+=arr[end];
            maxsum=max(maxsum,cursum);
        }
    }
    cout<<maxsum;
}
//Kadans algorithm
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int cursum=0;
    int maxsum=INT_MIN;
    vector<int>vec;
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
>>>>>>> fab1da80942473717e3ea54278087924c599ae51
