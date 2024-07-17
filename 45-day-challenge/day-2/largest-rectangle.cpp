class Solution {
private:
    vector<int> nextSmallerELement(vector<int>& heights,int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--)
        {
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = (s.top() == -1) ? n : s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerELement(vector<int>& heights,int n)
    {
        stack<int> s1;
        s1.push(-1);
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int curr = heights[i];
            while(s1.top() != -1 && heights[s1.top()] >= curr)
            {
                s1.pop();
            }
            ans[i] = (s1.top() == -1) ? -1 : s1.top();
            s1.push(i);
        }
        return ans;
    }
   
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallerELement(heights,n);
        vector<int> prev(n);
        prev = prevSmallerELement(heights,n);
        int area = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }
};