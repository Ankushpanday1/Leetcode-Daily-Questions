class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        int n = points.size();

        for (int i = 0; i < n; ++i) 
        {
            auto& A = points[i];
            for (int j = i + 1; j < n; ++j) 
            {
                auto& B = points[j];
                for (int k = j + 1; k < n; ++k) 
                {
                    auto& C = points[k];

                    double x1 = A[0], y1 = A[1];
                    double x2 = B[0], y2 = B[1];
                    double x3 = C[0], y3 = C[1];

                    double cross = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
                    double area = fabs(cross) * 0.5;
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};