class Solution {
private:
    void checkTop(stack<int> &stack, int &width, int &num) {
        if(stack.empty()  || stack.top() < num)
            return ;

        int element = stack.top();
        stack.pop();

        checkTop(stack, ++width, num);

        stack.push(element);
    }

    int getWidth(stack<int> &forward,stack<int> &backward, int &num) {
        int width = 1;

        checkTop(backward, width, num);
        checkTop(forward, width, num);

        return width;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> forward;
        stack<int> backward;

        for(int i = heights.size()-1; i >= 1; i--) {
            forward.push(heights[i]);
        }

        int max = 0;
        for(int i = 0; i < heights.size(); i++) {

            int width = getWidth(forward, backward, heights[i]);

            int ans = heights[i]*width;

            if(ans > max)
                max = ans;

            backward.push(heights[i]);
            forward.pop();

        }

        return max;

    }
};