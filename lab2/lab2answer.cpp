

#include <iostream>
#include <string>
#include <vector> // 2D-vector
#include <sstream> // isStream
#include <algorithm>

using namespace std;

void matrixInit(vector<vector<int>>&, int, int);



struct TokenFreq
{
	string token;
	int freq = 1; //contains itself so not 0

};

void ShortenSpace(string &input)
{
	int endOfTempInput = 0;
	char *tempInput;
	tempInput = new char[input.size() + 1];

	for (int i = 0; i < input.size(); endOfTempInput++)
	{
		tempInput[endOfTempInput] = input[i];
		if (isspace(input[i]))
		{
			while (isspace(input[i]))
				i = i + 1;
		}
		else i = i + 1;
	}
	//eol
	tempInput[endOfTempInput] = NULL;
	input = tempInput;

}

void getTokenFreqVec(string&, vector<TokenFreq>&);
void selectionSort(vector<TokenFreq> & );
void insertionSort(vector<TokenFreq> & );

int main()
{
	//test
	vector<TokenFreq> t;
	vector<vector<int> > tempM;
	int numRows = 3;
	int numCols = 4;
	//input
	string testStr;
	testStr = "And no, I'm not a walking C++ dictionary. I do not keep every technical detail in my head at all times. If I did that, I would be a much poorer programmer. I do keep the main points straight in my head most of the time, and I do know where to find the details when I need them. by Bjarne Stroustrup";
	//test matrix
	ShortenSpace(testStr);
	cout << testStr << endl;
	matrixInit(tempM, numRows, numCols);
	cout << "size of matrix is:" << " " << numRows << "x" << numCols;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			cout << "matrix[" << i << "][" << j << "]=" << tempM[i][j] << endl;
	}
	//tokenlize and print
	getTokenFreqVec(testStr, t);
	cout << "size=" << t.size() << endl;
	for (int i = 0; i < t.size(); i++)
		cout << "[" << i << "] = (token = \"" << t[i].token << "\"" << ", freq: " << t[i].freq <<")"<< endl;
	//debug
	//for (int i = 0; i < t.size(); i++)
	//cout << t[i].token;
	//test selectionsort
	selectionSort(t);
	//debug
	//for (int i = 0; i < t.size(); i++)
	//	cout << t[i].token;
	cout << "selectionSort" << endl;
	for (int i = 0; i < t.size(); i++)
		cout << "[" << i << "] = (token = \"" << t[i].token << "\"" << ", freq: " << t[i].freq <<")"<< endl;
	//test insetionsort
	insertionSort(t);
	//debug
	//for (int i = 0; i < t.size(); i++)
	//	cout << t[i].token;
	cout << "insetionSort" << endl;
	for (int i = 0; i < t.size(); i++)
		cout << "[" << i << "] = (token = \"" << t[i].token << "\"" << ", freq: " << t[i].freq <<")"<< endl;
	system("pause");
	return 0;
}

void matrixInit(vector<vector<int>> &matrix, int numRows, int numCols)
{
	//create enough sapce for the matrix
	matrix.resize(numRows,vector<int>(numCols));
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
			matrix[i][j] = i * j;

	}
}

void getTokenFreqVec(string& istr, vector<TokenFreq>& tfVec)
{
	bool newStr;
	string token;
	TokenFreq tempTokenFreq;
	istringstream isStr(istr);
	
	
	while (getline(isStr, token, ' '))
	{
		
		//tokenlizing the string
		ShortenSpace(token);
		//string to lower-case
		//if first string is whitespace
	   
		//if (token.find_first_not_of(' ') != std::string::npos)
		//{
		for (int i = 0; i<token.size(); i++)
		  if (token[i] != ' ')
		{
		for (int i = 0; i<token.size(); i++)
			token[i] = tolower(token[i]);
		
	
     if (token[0] != ' ')
			
	   
		newStr = true;
		for (int i = 0; i < tfVec.size(); i++)
		{
			//if find the same string
			if (tfVec[i].token == token)
			{
				//then freq+1
				tfVec[i].freq += 1;
				//set nextString
				newStr = false;
			}
		}
		if (newStr)
		{
			//temptoken hold the duplicated token that we just found
			tempTokenFreq.token = token;
			//add token back to <vector> t in main
			tfVec.push_back(tempTokenFreq);
			
		}
		}
		//}
	}
}


void selectionSort(vector<TokenFreq> & tokFreqVector)
{
	TokenFreq tok;
	int i, j, minIndex;
	
	for (i = 0; i < tokFreqVector.size() - 1; i++)
	{
		minIndex = i;
		for (j = i ; j < tokFreqVector.size(); j++)
		{
			if (tokFreqVector[j].freq < tokFreqVector[minIndex].freq)
			{
				//minIndex = j;
				//if (minIndex != i)
				{
					tok = tokFreqVector[minIndex];
					tokFreqVector[minIndex] = tokFreqVector[j];
					tokFreqVector[j] = tok;
				}
		
			}

		}
	}

}

void insertionSort(vector<TokenFreq> & tokFreqVector)
{
	TokenFreq tok;
	int i, j;
	
	for (i = 1; i < tokFreqVector.size(); i++)
	{
		tok = tokFreqVector[i];
		for (j = i - 1; j >= 0 && tokFreqVector[j].freq < tok.freq; j--)
		{	
			tokFreqVector[j + 1] = tokFreqVector[j];
			
		}
		tokFreqVector[j + 1] = tok;
	}
}