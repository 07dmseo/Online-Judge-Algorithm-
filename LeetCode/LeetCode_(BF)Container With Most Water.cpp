class Solution {
public:
    int maxArea(vector<int>& height) {
        int m = 0, fidx = 0, ridx = height.size() - 1;
        while (fidx != ridx) {
            m = max(m, (ridx - fidx) * min(height[fidx], height[ridx]));
            if (height[fidx] > height[ridx]) ridx -= 1;
            else fidx += 1;
        }
	    return m;
    }
};