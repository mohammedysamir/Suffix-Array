#include<iostream>
#include<string>
using namespace std;
class SuffixArray{
	int SizeofString;
	int No_unique;
	int** Array;
	
	void BuildArray() {
		//initialy insert indexes and starting position
		for (int i = 0; i < SizeofString; i++) {
			Array[0][i] = i;
			Array[1][i] = i;
		}
	}

	void SortArray(string str) {
		string FirstSuff,SecondSuff;
		for (int i = 0; i < SizeofString; i++) {
			for (int j = i+1; j < SizeofString; j++) {
				FirstSuff = str.substr(Array[1][i]);//get value of first suff to compare
				SecondSuff=str.substr(Array[1][j]);//value of second suff to compare
				if (SecondSuff.compare(FirstSuff) < 0)//second suff smaller than first suff , swap
				{
					int tempPos = Array[1][j];
					Array[1][j] = Array[1][i];
					Array[1][i] = tempPos;
				}
			}
		}
	}
public:
	SuffixArray(string str) {
		SizeofString = str.size();
		No_unique = 0;//Numer of unique characters
		//Create 2D array 
		//First row for index
		//Second row for startingPos of String
		Array = new int*[2];
		for (int i = 0; i < 2; i++) {
			Array[i] = new int[SizeofString];
		}
		BuildArray();
		SortArray(str);
		Print();
	}
	void ConstructUsingPrefixDoubling() {

	}
	void Print() {
		for (int i = 0; i < SizeofString; i++)
			cout << Array[1][i] << " ";
		cout << endl;
	}
	
};