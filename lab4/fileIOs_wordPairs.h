#ifndef WORD_PAIR_H
#define WORD_PAIR_H

#include <map>

using namespace std;

struct mycomp  
{ //user defined set compare operator
	bool operator() (const string &a, const string &b)  
	{  
		int cmprst = a.compare(b);  
		return cmprst<0;  
	}  
}; 

bool sentenceSplitter(string& fname, vector<string>& sentences);

/*const string d(".?.\"?\"");
inline bool isD(char dc)
{
	for (int i = 0; i < d.size(); i++)
		if (d[i] == dc)
			return true;
	return false;
}*/

bool wordpairMapping(vector<string>& sentences, map < pair<string, string>, int> &wordpairFreq_map);


//function 3 
bool freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string, string> > &freqWordpair_mmap );

//function 4 
void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt);

#endif
