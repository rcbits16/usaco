/* 
ID: rohitch1
PROG: namenum
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

typedef pair<string,int> si;

int code(string name);
int charval(char c);
int main(void)
{
	vector<si> names;
// Building the dictionary	
	fstream dict;
	dict.open("dict.txt");
	//Code goes here	
	si temp;
	temp.second =0;
	while(getline (dict, temp.first))
	{
		names.push_back(temp);
	}
	dict.close();
	
//Computations
	for(int i=0;i<names.size();i++)
	{
		names[i].second = code(names[i].first);
	}
	
//Taking input number
	fstream fin;
	fin.open("namenum.in");
	int brand_number;
	fin >> brand_number;
	fin.close();	
	

//Opening for output
	ofstream fout;
	fout.open("namenum.out");
	// Outputting code here
	
	for(int i=0;i< names.size();i++)
	{
		if(brand_number == names[i].second)
		{
			fout << names[i].first << '\n';
			cout << names[i].first << '\n';
		}	
	}		
	fout.close();

	return 0;

}

int code(string name)
{
	int code =0,len = name.size();	
	for(int i=0;i<len;i++)
	{
		code+= pow(10,(len-(i+1)))*charval(name[i]);	
	}
	return code;
}

int charval(char c)
{
	switch(c){
		case 'A': case 'B': case 'C':
			return 2;
		case 'D': case 'E': case 'F':
			return 3;
		case 'G': case 'H': case 'I':
			return 4;
		case 'J': case 'K': case 'L':
			return 5;
		case 'M': case 'N': case 'O':
			return 6;
		case 'P': case 'R': case 'S':
			return 7;
		case 'T': case 'U': case 'V':
			return 8;		
		case 'W': case 'X': case 'Y':
			return 9;			
	}
}








