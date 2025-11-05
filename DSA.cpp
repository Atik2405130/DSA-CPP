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

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>vec(5,0);//0
    vec.push_back(25);
    for(int i:vec)
    {
        cout<<i<<endl;
    }
    cout<<"size= "<<vec.size()<<endl;
}
