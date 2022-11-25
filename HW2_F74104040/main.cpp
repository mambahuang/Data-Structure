#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

struct offsets{ // a -> row, b-> col 
	int a, b;
};

struct Items{
	int x,y,dir;
};

enum directions {E,SE,S,SW,W,NW,N,NE}; // eight direstion
	
offsets move[8];
int mark[17][17];
int maze[17][17];
int count = 0;

void Path(){
	
	ofstream ofile;
	ofile.open("output.txt");
	
	// Start from (1,0)
	mark[1][0] = 1;
	stack<Items> stack;
	Items temp;
	temp.x = 1;
	temp.y = 0;
	temp.dir = E;
	stack.push(temp);
	
	while(!stack.empty()){
		
		temp = stack.top();
		stack.pop();
		int i = temp.x; 
		int j = temp.y; 
		int d = temp.dir;
		int g,h;
		
		while(d < 8){
			g = i + move[d].a; 
			h = j + move[d].b;
			
			if((g == 15) && (h == 16)){
				ofile << count << ":" << g << "," << h << endl;
				cout << count << ":" << g << "," << h << endl;
				ofile << "Successfully escape!!" << endl;
				cout << "Successfully escape!!";
				return;
			}
			if((!maze[g][h]) && (!mark[g][h])){
				mark[g][h] = 1;
				temp.x = i; temp.y = j; temp.dir = d;
				stack.push(temp);
				ofile << count << ":" << i << "," << j << endl;
				cout << count << ":" << i << "," << j << endl;
				count++;
				i = g; j = h; d = E;
			}
			else{
				d++;
			}
				
		}		
		ofile << count << ":" << i << "," << j << endl;
		cout << count << ":" << i << "," << j << endl;
		count++;
	}
	ofile << "Failed to escape." << endl;
	cout << "Failed to escape.";
}

int main() {
	
	// Initialize "mark", "maze" to be 0
	for( int i=0; i<17; i++)
		for(int j=0; j<17; j++){
			mark[i][j] = 0;
			maze[i][j] = 0;
		}

	// Initialize move[]
	move[N].a = -1;
	move[N].b = 0;
	move[NE].a = -1;
	move[NE].b = 1;
	move[E].a = 0;
	move[E].b = 1;
	move[SE].a = 1;
	move[SE].b = 1;
	move[S].a = 1;
	move[S].b = 0;
	move[SW].a = 1;
	move[SW].b = -1;
	move[W].a = 0;
	move[W].b = -1;
	move[NW].a = -1;
	move[NW].b = -1;
	
	ifstream iFile;
	string file_name;
	cout << "enter filename : ";
	cin >> file_name;
	iFile.open(file_name.c_str());
	
	/*int val, i=0, j=0;
	if(iFile.is_open()){
		while(true){
			iFile >> val;
			maze[i][j] = val;
			j++;
			if(j == 17){
				j = 0;
				i++;
			}
			if(iFile.eof()) break;
		}
		iFile.close();
	}else{
		cout << "File not found!";
	}*/
	char ch;
	int i=0, j=0;
	while((ch = iFile.get()) != EOF){
		if(ch == '\n') continue;
		maze[i][j] = ch - 48;
		j++;
		if(j == 17){
			j = 0;
			i++;
		}
	}
	
	for( int i=0; i<17; i++){
		for(int j=0; j<17; j++){
			cout << maze[i][j];
		}
		cout << endl;
	}
	cout << "----------------------" << endl;
	Path();
	
	return 0;
}
