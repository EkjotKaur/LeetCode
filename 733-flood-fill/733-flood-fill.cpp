class Solution {
public:
    void FF(vector<vector<int>>& image, int sr, int sc, int newColor, int val)
    {
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size())
            return;
        if(image[sr][sc]==val)
        {
            image[sr][sc]=newColor;
            FF(image, sr+1, sc, newColor, val);
            FF(image, sr-1, sc, newColor, val);
            FF(image, sr, sc+1, newColor, val);
            FF(image, sr, sc-1, newColor, val);
        }            
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc])
            return image;
        FF(image, sr, sc, newColor, image[sr][sc]);
        image[sr][sc]=newColor;
        return image;
    }
};