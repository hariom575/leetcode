
class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		  int r=mat.size(),c=mat[0].size();
		if(r==1)
			 return mat;
		//storing element corresponding to one diagonal
		  unordered_map<int,multiset<int>> mp;
		//O(r*c)
		 for(int i=0;i<r;i++){
			 for(int j=0;j<c;j++){
				 mp[i-j].insert(mat[i][j]);
			 }
		 }

		//start filling element in increasing order
		//row fixed to 0
		for(int j=0;j<c;j++){
			int row=0,col=j;
				for(auto it: mp[row-col]){
					 mat[row][col]=it;
					 row++;
					col++;
				}
		}
		//column fixed to 0
		for(int i=1;i<r;i++){
			int row=i,col=0;
				for(auto it: mp[row-col]){
					 mat[row][col]=it;
					 row++;
					col++;
				}
		}
		return mat;

	}
};