#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <exception>
#include "fileIOs_wordPairs.h"

using namespace std;

int main()
{
	try{
		vector <string> vec;
		string test = "SteveJobsSpeech2005.txt";
		bool splitter;
		bool wordpair;

		//summary the clauses of the text
		splitter = sentenceSplitter(test, vec);
		//cout << splitter;

		//print

		for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			cout << *it << endl;
		}
		cout<<endl;

		//cout << "vecSize" << vec.size() << endl;
		//cout << "vecAt(1)"<< vec.at(1) << endl;
		
		map < pair<string, string>, int> wordPair;
		//summary the frequency to the word pairs
		wordpair = wordpairMapping(vec, wordPair);

		int minfreq=1000000000, maxfreq=0;
		map<pair<string, string>, int>::iterator minit;
		map<pair<string, string>, int>::iterator maxit;
		map<pair<string, string>, int>::iterator it;
		for (it = wordPair.begin(); it != wordPair.end(); it++)
		{
			if(it->second < minfreq)
			{
				minfreq = it->second;
				minit = it;
			}
			if(it->second > maxfreq)
			{
				maxfreq = it->second;
				maxit = it;
			}
			cout<< "(" << it->first.first << "," << it->first.second << ")" << " = " << it->second << endl;
		}
	
		cout<<endl;
		cout<<"minfreq:"<<endl;
		it = minit;
		cout<< "(" << it->first.first << "," << it->first.second << ")" << " = " << it->second << endl;
		cout<<"maxfreq:"<<endl;
		it = maxit;
		cout<< "(" << it->first.first << "," << it->first.second << ")" << " = " << it->second << endl;
		cout<<endl;

		//convert to multimap
		multimap<int, pair<string, string> > freqWordpair_mmap;
		freqWordpairMmap(wordPair, freqWordpair_mmap);

		//save min freq & max freq to file
		printWordpairs(freqWordpair_mmap, "mxfreq.txt", 4, 4);
	}  
	catch (exception& e)  
	{  
		cout << "Standard exception: " << e.what() << endl;  
		return false;
	}  
	system("pause");
}