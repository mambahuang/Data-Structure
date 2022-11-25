#include <iostream>
#include <fstream>
#include "transpose.h"
#include "ftranspose.h"
#include <time.h>
#include <iomanip>

using namespace std;

int main() {
	
	int r, c, row, col, term;
	int** smArray = new int*[1000000];
	int** smArray2 = new int*[1000000];
	int** smArray3 = new int*[1000000];
	for(int i=0; i<1000000; i++){ // initialize
		smArray[i] = new int[3];
		smArray2[i] = new int[3];
		smArray3[i] = new int[3];
	}
	
	int i=0, terms=0, cols=0;
	ifstream iFile;
	
	// input file
	iFile.open("test2_testing_data.in", ios::in);
	if(iFile){
		iFile >> r >> c;
		while(true){
			iFile >> row >> col >> term;
			smArray[i][0] = row;
			smArray[i][1] = col;
			smArray[i][2] = term;
			if(iFile.eof()) break;
			i++; terms++; cols++;
		}
		iFile.close();
	}else{
		cout << "File not found!";
	}
	
	// Transpose's time
	clock_t start = clock();
	smArray2 = Transpose(smArray, terms, cols);
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	
	// Fast transpose's time
	clock_t start_f = clock();
	smArray3 = f_Transpose(smArray, terms, cols);
	clock_t end_f = clock();
	double elapsed_f = double(end_f - start_f) / CLOCKS_PER_SEC;
	
	/*
	for(int i=0; i<terms; i++){
		cout << "(" << smArray[i][0] << ", " << smArray[i][1] << ", " << smArray[i][2] << ") ";
		for(int j=0; j<terms; j++){
			if(smArray2[j][1] == smArray[i][0] && smArray2[j][0] == smArray[i][1] && smArray2[j][2] == smArray[i][2]){
				cout << "becomes (" << smArray2[j][0] << ", " << smArray2[j][1] << ", " << smArray2[j][2] << ") in the transpose\n";
				break;
			}	
		}
			
	}
	cout << endl;
	for(int i=0; i<terms; i++){
		cout << "(" << smArray[i][0] << ", " << smArray[i][1] << ", " << smArray[i][2] << ") ";
		for(int j=0; j<terms; j++){
			if(smArray3[j][1] == smArray[i][0] && smArray3[j][0] == smArray[i][1] && smArray3[j][2] == smArray[i][2]){
				cout << "becomes (" << smArray3[j][0] << ", " << smArray3[j][1] << ", " << smArray3[j][2] << ") in the transpose\n";
				break;
			}	
		}
			
	}
	cout << elapsed << endl << elapsed_f;
	*/
	ofstream outfile("test2_testing_data.txt");
	
	for(int i=0; i<terms; i++){
		outfile << "(" << smArray[i][0] << ", " << smArray[i][1] << ", " << smArray[i][2] << ") ";
		for(int j=0; j<terms; j++){
			if(smArray2[j][1] == smArray[i][0] && smArray2[j][0] == smArray[i][1] && smArray2[j][2] == smArray[i][2]){
				outfile << "becomes (" << smArray2[j][0] << ", " << smArray2[j][1] << ", " << smArray2[j][2] << ") in the transpose\n";
				break;
			}	
		}
			
	}
	outfile << elapsed << endl << elapsed_f;
	outfile.close();
	
	return 0;
}
