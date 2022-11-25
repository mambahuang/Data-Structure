
int** f_Transpose(int** sm2, int aa_terms, int aa_cols){ // <row, col, value>
		int** rlt2 = new int*[aa_terms];
		for(int i=0; i<aa_terms; i++)
			rlt2[i] = new int[3];
		
		if(aa_terms > 0){
			int* rowSize = new int[aa_cols];
			int* rowStart = new int[aa_cols];
			for(int i=0; i<aa_cols; i++) rowSize[i] = 0; // initialize
			for(int i=0; i<aa_cols; i++) rowSize[sm2[i][1]]++; // row[i]'s size
			
			rowStart[0] = 0; //start point is 0
			for(int i=1; i<aa_terms; i++) rowStart[i] = rowStart[i-1] + rowSize[i-1]; // count row[i] starts at index {x}
			
			// fast transpose
			for(int i=0; i<aa_terms; i++){
				int j = rowStart[sm2[i][1]];
				rlt2[j][0] = sm2[i][1];
				rlt2[j][1] = sm2[i][0];
				rlt2[j][2] = sm2[i][2];
				rowStart[sm2[i][1]]++;
			}
			delete [] rowSize;
			delete [] rowStart;
		}
		return rlt2;
}
