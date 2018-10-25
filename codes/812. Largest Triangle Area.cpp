class Solution {
public:
    
    double getSideLength(vector<int> X, vector<int> Y) {
        return sqrt(pow(X[0]-Y[0],2) + pow(X[1]-Y[1],2));    
    }
    
    double getArea(vector<int> X, vector<int> Y, vector<int> Z) {
        double s1 = getSideLength(X,Y);
        double s2 = getSideLength(Y,Z);
        double s3 = getSideLength(X,Z);
        
        double s = (s1+s2+s3)/2; // semiPerimeter
        double area = sqrt(s * (s-s1) * (s-s2) * (s-s3));
        return area;
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        int N = points.size();
        double ans = 0;
        
        for (int i=0;i<N;i++)
            for (int j=i+1;j<N;j++)
                for (int k=j+1;k<N;k++)
                    ans = max(ans, getArea(points[i], points[j], points[k]));
        
        return ans;
    }
};