class Solution {
public:
    vector<vector<int>> dsf(vector<vector<int>> &image, int sr, int sc, int newcolor,int color,vector<vector<bool>> &visited){
        visited[sr][sc] = true;
        if(sr-1 >= 0 && visited[sr-1][sc] == false && image[sr-1][sc] == color){
            dsf(image, sr-1, sc, newcolor, color, visited);
        }
        if(sc-1 >=0 && visited[sr][sc-1] == false && image[sr][sc-1] == color){
            dsf(image, sr, sc-1, newcolor, color, visited);
        }
        if(sc+1 < image[0].size() && visited[sr][sc+1] == false && image[sr][sc+1] == color){
            dsf(image, sr, sc+1, newcolor, color, visited);
        }
        if(sr+1 < image.size() && visited[sr+1][sc] == false && image[sr+1][sc] == color){
            dsf(image, sr+1, sc, newcolor, color, visited);
        }
        image[sr][sc] = newcolor;
        return image;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(color == image[sr][sc]) return image;
        else{
            int rows= image.size();
            int cols = image[0].size();
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            image = dsf(image, sr, sc, color, image[sr][sc], visited);
        }
        return image;
    }
};