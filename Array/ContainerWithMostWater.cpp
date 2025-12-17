// Brute force //
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>height={1,8,6,2,5,4,8,3,7};
    int area=0;
    int w,h=0;
    for(int i=0;i<height.size();i++)
    {
        for(int j=i+1;j<height.size();j++)
        {
            w=j-i;
            h=min(height[i],height[j]);
            int t=w*h;
            area=max(area,t);
        }
    }
    cout<<area;
    return 0;
}

// 2 Pointer Approach //
 #include<iostream>
 #include<vector>
 using namespace std;
 int main()
 {
    vector<int>height={1,8,6,2,5,4,8,3,7};
    int maxwater=0;
    int lp=0,rp=height.size()-1;
    while(lp<rp)
    {
        int width=rp-lp;
        int h=min(height[lp],height[rp]);
        int temp=width*h;
        maxwater=max(maxwater,temp);
        int a=(height[lp]<height[rp])?lp++:rp--;
    }
    cout<<maxwater;
 }
