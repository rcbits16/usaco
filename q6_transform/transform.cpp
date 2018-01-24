/*
ID: rohitch1
PROG: transform
LANG: C++
*/

#include<iostream>
#include<fstream>
using namespace std;

void rotate_clock_90(int size,char src[10][10],char dest[10][10]);
void flip_horizontal(int size,char src[10][10],char dest[10][10]);
bool compare(int size,char b1[10][10],char b2[10][10]);

int main(void)
{
	ifstream fin;
	fin.open("transform.in");
	ofstream fout;
	fout.open("transform.out",ios::out);

	int size;
	char block_original[10][10];
	char block_transformed[10][10];
	char block_trying[7][10][10];
	fin >> size;
	for(int i=0;i<size;i++)
	{
		fin >> block_original[i];
	}
	for(int i=0;i<size;i++)
	{
		fin >> block_transformed[i];
	}

	//90 degree clockwise rotated matrix - in block_trying[0]
	rotate_clock_90(size,block_original,block_trying[0]);
	//180 degree clockwise rotated matrix- in block_trying[1]
	rotate_clock_90(size,block_trying[0],block_trying[1]);
	//270 degree clockwise rotated matrix- in block_trying[2]
	rotate_clock_90(size,block_trying[1],block_trying[2]);
	//Horizontaliy flipped matrix - in block_trying[3]
	flip_horizontal(size,block_original,block_trying[3]);
	//Flip then 90 clockwise rotated - in block_trying[4]
	rotate_clock_90(size,block_trying[3],block_trying[4]);
	//Flip then 180 clockwise rotated - in block_trying[5]
	rotate_clock_90(size,block_trying[4],block_trying[5]);
	//Flip then 270 clockwise rotated - in block_trying[6]
	rotate_clock_90(size,block_trying[5],block_trying[6]);
	//No change-> Both original and transformed same.

	// If nothing matched, invalid transformation.
	if( compare(size,block_transformed,block_trying[0]) ){
		fout <<"1\n";
		return 0;

	}
	else if( compare(size,block_transformed,block_trying[1]) ){
		fout <<"2\n";	return 0;
	}

	else if( compare(size,block_transformed,block_trying[2]) ){
		fout <<"3\n";	return 0;
	}

	else if( compare(size,block_transformed,block_trying[3]) ){
		fout <<"4\n";	return 0;
	}
	else if( (compare(size,block_transformed,block_trying[4]))||
			 (compare(size,block_transformed,block_trying[5]))||
			 (compare(size,block_transformed,block_trying[6]))	){
		fout <<"5\n";	return 0;
	}

	else if( compare(size,block_original,block_transformed) ){
		fout <<"6\n";	return 0;
	}
	else{
		fout <<"7\n"; return 0;
	}

}
void rotate_clock_90(int size,char src[10][10],char dest[10][10])
{
	for(int i =0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			dest[i][j] = src[(size-1)-j][i];
		}
	}
}
void flip_horizontal(int size,char src[10][10],char dest[10][10])
{
	for(int i =0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			dest[i][j] = src[i][(size-1)-j];
		}
	}
}
bool compare(int size,char b1[10][10],char b2[10][10])
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(b1[i][j]!= b2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
