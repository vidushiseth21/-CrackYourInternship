class Solution {
public:
    int maxArea(vector<int>& height) {
      int n=height.size();
      int area=INT_MIN;
      int r=0,l=n-1;
      while(r<l)
      {
        int a=(l-r)*min(height[r],height[l]);
        cout<<a<<" ";
        area=max(area,a);
        if(height[r]<height[l])
         r++;
        else
         l--;
      }
      return area;
    }
};