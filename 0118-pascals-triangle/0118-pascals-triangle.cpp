class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    
        vector<vector<int>> ans;
        
        vector<int> vec;
        vec.push_back(1);
        ans.push_back(vec);
        if( numRows==1) return ans;
        vec.push_back(1);
        ans.push_back(vec);
        for(int i=2;i<numRows;i++){
            vector<int> vec1;
            vec1.push_back(1);
            for(int j=0;j<vec.size()-1;j++){
                vec1.push_back(vec[j]+vec[j+1]);   
            }
            vec1.push_back(1);
            ans.push_back(vec1);
            vec=vec1;
        }
        return ans;
    }
};