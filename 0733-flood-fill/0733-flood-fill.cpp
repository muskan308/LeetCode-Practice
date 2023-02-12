class Solution {
public:
    vector<vector<int>> dsf(vector<vector<int>> &image, int sr, int sc, int newcolor,int color){
        // if(image[sr][sc] == newcolor) return image;
        
        image[sr][sc] = newcolor;
        
        if(sr-1 >= 0 && image[sr-1][sc] == color){ 
            dsf(image, sr-1, sc, newcolor, color);
        }
        if(sc-1 >=0 && image[sr][sc-1] == color){
            dsf(image, sr, sc-1, newcolor, color);
        }
        if(sc+1 < image[0].size() && image[sr][sc+1] == color){
            dsf(image, sr, sc+1, newcolor, color);
        }
        if(sr+1 < image.size() && image[sr+1][sc] == color){
            dsf(image, sr+1, sc, newcolor, color);
        }
        
        return image;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(color == image[sr][sc]) return image;
        else{
            
            //vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            image = dsf(image, sr, sc, color, image[sr][sc]);
        }
        return image;
    }
};