
int** Transpose(int** sm, int a_terms, int a_cols){ // <row, col, value>
		int** rlt = new int*[a_terms];
		for(int i=0; i<a_terms; i++)
			rlt[i] = new int[3];
		
		if(a_terms > 0){
			int currentB = 0;
			for(int c=0; c<a_cols; c++){
				for(int i=0; i<a_terms; i++){
					if(sm[i][1] == c){
						rlt[currentB][0] = c;
						rlt[currentB][1] = sm[i][0];
						rlt[currentB][2] = sm[i][2];
						currentB++;
					}
				}
			}
		}
		return rlt;
}
