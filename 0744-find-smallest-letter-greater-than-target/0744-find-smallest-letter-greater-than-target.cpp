class Solution {
public:
    
    char binSearch(vector<char>& letters, char target, int low, int high){
        if(low <=high){
            int mid = low+(high-low)/2;
            if(mid==0 && letters[mid] > target) return letters[mid];
            else if(letters[mid] > target && letters[mid-1] <= target) return letters[mid];
            else if(letters[mid] <= target) return binSearch(letters, target, mid+1, high);
            else return binSearch(letters, target, low, mid-1);
        } 
        return letters[0];
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target > letters[letters.size()-1]) return letters[0];
        
        return binSearch(letters, target, 0, letters.size()-1);
    }
};