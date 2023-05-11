class Solution {
private:
    vector<int> nextSmallerElement(vector<int>& heights, int n) {
        vector<int> forward(n);
        stack<int> stack;
        stack.push(-1);

        for(int i = n-1; i >= 0; i--) {
            
            while(stack.top() != -1 && heights[stack.top()] >= heights[i]) {
                stack.pop();
            }

            if(stack.top() == -1)
                forward[i] = n;
            else
                forward[i] = stack.top();

            stack.push(i);

        }

        return forward;
    }

    vector<int> previousSmallerElement(vector<int>& heights, int n) {
        vector<int> backward(n);
        stack<int> stack;
        stack.push(-1);

        for(int i = 0; i < n; i++) {

            while(stack.top() != -1 && heights[stack.top()] >= heights[i]) {
                stack.pop();
            }

            backward[i] = stack.top();

            stack.push(i);

        }

        return backward;
    }

public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        vector<int> forward = nextSmallerElement(heights, n);
        vector<int> backward = previousSmallerElement(heights, n);

        int maxArea = INT_MIN;
        for(int i = 0; i < n; i++) {
            int width = forward[i] - backward[i] - 1;
            int newAns = width*heights[i]; 
            maxArea = max(maxArea, newAns);
        }

        return maxArea;

    }
};