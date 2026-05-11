#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    system("bash sys.sh");
    ifstream file("info.txt");
    string line;
    while(getline(file,line)){
	    cout << line << endl;
    }

    
    return 0;
}
