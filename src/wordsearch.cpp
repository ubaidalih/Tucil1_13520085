#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	string line;
	vector<string> s, q;
	bool isQuery = false;
	cout<<"Masukkan nama file : "<<endl;
	string input;
	cin>>input;
	string dir = "../test/"+input;
	ifstream testfile (dir);
  	if (testfile.is_open()){
    	while ( getline (testfile,line) ){
    		if (line == ""){
    			isQuery = true;
    			continue;
			}
			if (!isQuery){
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				s.push_back(line);
			}
			else{
				q.push_back(line);
			}
      		
    	}
    testfile.close();
  	}
	clock_t startGlobal, endGlobal;
	startGlobal = clock();
	int compareGlobal;
  	int row = s.size();
  	int col = s[0].length();
  	int it = q.size();
	for(int k=0; k<it ; k++){
		clock_t start, end;
		start = clock();
		int r1, c1, r2, c2;
		string query = q[k];
		int length = query.size();
		bool found = false;
		int compare = 0;
		for(int i=0; i<row && !found; i++){
			for(int j=0; j<col && !found; j++){
				for(int sbX=-1; sbX<=1 && !found;sbX++){
					for(int sbY=-1; sbY<=1 && !found;sbY++){
						if(sbX!=0 || sbY!=0){
							bool sama = false;
							if(i+sbX*(length-1)>=0 && i+sbX*(length-1) <= row-1 && j+sbY*(length-1)>=0 && j+sbY*(length-1) <= col-1){
								int idx = 0;
								sama = true;
								while(idx < length && sama){
									compare++;
									if(s[i+sbX*idx][j+sbY*idx] == query[idx]){
										idx++;
									}
									else{
										sama = false;
									}
								}
							}
							if (sama){
								r1 = i;
								c1 = j;
								r2 = i+sbX*(length-1);
								c2 = j+sbY*(length-1);
								found = true;
								compareGlobal += compare;
							}
						}
					}
				}
			}
		}
		if (!found){
			cout << "Kata tidak ditemukan." << '\n';
		}
		else{
			if(r1 == r2){
				for(int i=0; i<row; i++){
					for(int j=0; j<col; j++){
						if(i == r1 && j <= c1 && j >= c2){
							cout<<s[i][j]<<" ";
						}
						else if(i == r1 && j >= c1 && j <= c2){
							cout<<s[i][j]<<" ";
						}
						else {
							cout<<"-"<<" ";
						}
					}
					cout<<'\n';
				}
			}
			else if (c1 == c2) {
				for(int i=0; i<row; i++){
					for(int j=0; j<col; j++){
						if(j == c1 && i <= r1 && i >= r2){
							cout<<s[i][j]<<" ";
						}
						else if(j == c1 && i >= r1 && i <= r2){
							cout<<s[i][j]<<" ";
						}
						else {
							cout<<"-"<<" ";
						}
					}
					cout<<'\n';
				}
			}
			else {
				for(int i=0; i<row; i++){
					for(int j=0; j<col; j++){
						if((abs(i-r1) == abs(j-c1)) && i <= r1 && i >= r2 && j <= c1 && j >= c2){
							cout<<s[i][j]<<" ";
						}
						else if((abs(i-r1) == abs(j-c1)) && i <= r1 && i >= r2 && j >= c1 && j <= c2){
							cout<<s[i][j]<<" ";
						}
						else if((abs(i-r1) == abs(j-c1)) && i >= r1 && i <= r2 && j <= c1 && j >= c2){
							cout<<s[i][j]<<" ";
						}
						else if((abs(i-r1) == abs(j-c1)) && i >= r1 && i <= r2 && j >= c1 && j <= c2){
							cout<<s[i][j]<<" ";
						}
						else {
							cout<<"-"<<" ";
						}
					}
					cout<<'\n';
				}
			}
			end = clock();
			double duration = double(end - start)/double(CLOCKS_PER_SEC);
			cout<<"Jumlah perbandingan huruf : "<<compare<<'\n';
			cout<<"Durasi program : "<<fixed<<duration<<setprecision(6)<<" sec"<<'\n';
			cout<<'\n';
		}
	}
	endGlobal = clock();
	double durationGlobal = double(endGlobal - startGlobal)/double(CLOCKS_PER_SEC);
	cout<<"Jumlah semua perbandingan huruf : "<<compareGlobal<<'\n';
	cout<<"Durasi keseleruhan program : "<<fixed<<durationGlobal<<setprecision(6)<<" sec"<<'\n';
}