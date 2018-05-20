#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>  
#include <exception> 
#include "fileIOs_wordPairs.h"

using namespace std;


bool sentenceSplitter(string& fname, vector<string>& sentences)
{
	fstream  filename;
	//string temp;
	//char c;
	filename.open(fname.c_str(), ios::in | ios::out);
	if (filename.fail())
	{
		cout << "Failed to open file" << endl;
		return false;
	}
	else 
	{
		try  
		{  
			//cout << "test1" << endl;
			long fileLength;

			filename.seekg(0, filename.end);
			fileLength = (long)filename.tellg();
			filename.seekg(0, filename.beg);
			//cout << "test2" << endl;

			//char * temp = new char[fileLength];
			//cin.getline(temp, fileLength);
			char *temp = new char[fileLength];
			memset(temp, 0, fileLength);
			filename.read(temp, fileLength);
			//cout << "test3" << endl;
			//cout << temp[1];
			string tempLine = temp;
			//convert to lower
			//transform(tempLine.begin(), tempLine.end(), tempLine.begin(), ::tolower); 

			//the length of the text
			long txtlen = (long)tempLine.length();
			//mark begin and end postion of the target sentence
			int pos1=0,pos2=0;
			int index = 0;

			while(pos1<txtlen)
			{
				//skip space && \n
				while((pos1<txtlen) && ((tempLine[pos1] == 0x20) || (tempLine[pos1] == 0x0D) || (tempLine[pos1] == 0x0A)))
				{
					pos1++;
				}
				pos2 = pos1;
				//search clause end character
				while((pos2<txtlen) && (tempLine[pos2] != '.') && (tempLine[pos2] != '?') && (tempLine[pos2] != 0x0D) && (tempLine[pos2] != 0x0A))
				{
					pos2++;
				}
				if(pos2>=txtlen)
				{
					break;
				}
/*
				stringstream ss;
				string dth;
				ss<<index<<"th---";
				ss>>dth;
				index++;
				sentences.push_back(dth + wordstr);
*/
				int chrcnt = pos2-pos1;
				string wordstr = tempLine.substr(pos1, chrcnt);
				sentences.push_back(wordstr);

				if(pos2+1>=txtlen)
				{
					break;
				}
				pos2++;
				//skip double quote
				if(tempLine[pos2] == '"')
				{
					pos2++;
				}
				else if(((unsigned char)(tempLine[pos2])==0xE2)&&((unsigned char)(tempLine[pos2+1])==0x80)&&((unsigned char)(tempLine[pos2+2])==0x9D))
				{
					pos2+=3;
				}
				//search the next target sentence
				pos1 = pos2;
			}
			return true;
		}  
		catch (exception& e)  
		{  
			cout << "Standard exception: " << e.what() << endl;  
			return false;
		}  
	}
}


bool wordpairMapping(vector<string>& sentences, map < pair<string, string>, int> &wordpairFreq_map)
{
    try  
    {
		string stcstr, first_token, second_token;
		set<string,mycomp> unique_tokens;
		pair<string, string> wordPair;

		typedef set<string,mycomp>::iterator SETITOR;

		for (int i = 0; i < sentences.size(); i++)
		{
			unique_tokens.clear();
/*
			stcstr = sentences.at(i);
 			char *pStr = (char *)stcstr.c_str();

			char seps[]   = " \"\t\n";//separator characters
			char *token, *p;//
			token = strtok_s( pStr, seps, &p);
			while( token != NULL )
			{
				unique_tokens.insert(token);
				token = strtok_s( NULL, seps, &p);
			}
*/
			istringstream tokenizer(sentences.at(i));			
			while (getline(tokenizer, stcstr, ' '))
			{
				//character index;
				int pos = 0;

				unsigned char ch = stcstr.at(pos);
				while((ch==0x09)||(ch==0x20)||(ch==0x0A)||(ch==0x0D)||(ch==0xE2)||(ch==0x80)||(ch==0x9C)||(ch==0x9D))
				{
					ch = stcstr.at(++pos);
				}

				stcstr = stcstr.substr(pos, stcstr.length()-pos);

				transform(stcstr.begin(), stcstr.end(), stcstr.begin(), ::tolower);   
				unique_tokens.insert(stcstr);
			}

			for(SETITOR it=unique_tokens.begin();it!=unique_tokens.end();it++)
			{
				first_token = *it;
				SETITOR jt=it;
				for(jt++;jt!=unique_tokens.end();jt++)
				{
					second_token = *jt;
					//int icmp = stricmp(first_token.c_str(), second_token.c_str());
					int icmp = first_token.compare(second_token);
					if (icmp != 0)
					{ 
						if (icmp < 0)
							wordPair = make_pair(first_token, second_token);					
						else
							wordPair = make_pair(second_token, first_token);

						wordpairFreq_map[wordPair]++;
					}
				}
			}
		}
		return true;
    }  
    catch (exception& e)  
    {  
        cout << "Standard exception: " << e.what() << endl;  
		return false;
    }  
}

//function 3 
bool freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string, string> > &freqWordpair_mmap )
{
	try
	{	
		map< pair<string,string>, int> :: iterator it1;
	    map< pair<string,string>, int> :: iterator it2;
	    map< pair<string,string>, int> :: iterator it3;
	    vector<int> wpfrq;
	  
	    for(it1 = wordpairFreq_map.begin(); it1 != wordpairFreq_map.end(); it1++)
		{
	        wpfrq.push_back(it1->second);
	    }
	
		sort(wpfrq.begin(), wpfrq.end());
	    wpfrq.erase(unique ( wpfrq.begin(), wpfrq.end()), wpfrq.end());
	   
	    for(unsigned int i = 0; i < wpfrq.size(); i++)
		{
	        for(it2= wordpairFreq_map.begin(); it2 != wordpairFreq_map.end(); it2++)
			{
	            if (it2->second == wpfrq[i])
				{
	                pair <string, string> pairs;
	                pairs.first = it2->first.first;
	                pairs.second = it2->first.second;
	                freqWordpair_mmap.insert(make_pair(it2->second, pairs));             
	            }
	        }
	        it2 = wordpairFreq_map.begin();
	    }
	    return true;
	}
    catch (exception& e)  
    {  
        cout << "Standard exception: " << e.what() << endl;  
		return false;
    }      
}

//function 4 
void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt)
{
	try
	{
		ofstream outfile;
	    multimap<int, pair<string, string> > :: iterator it;
	    multimap<int, pair<string, string> > :: reverse_iterator rit;
	
	    int count = 0;
	    outfile.open(outFname.c_str());
	    if(outfile.is_open())
		{
	        for(it = freqWordpair_multimap.begin(); it != freqWordpair_multimap.end(); it++)
			{
	            if(count < topCnt)
				{
	                outfile << "<" << it->second.first << ", " << it->second.second << ">: " << it->first << endl;
	                count++;
	            }
	        }
			count =0;
			for(rit = freqWordpair_multimap.rbegin(); rit!= freqWordpair_multimap.rend(); rit++)
			{
	            if (count < botCnt )
				{
	                outfile << "<" << rit->second.first << ", " << rit->second.second << ">: " << rit->first << endl;
	                count ++;
	            }
	        }
	    }
	    else
		{
	        cout << "cannot open file" << endl;
	    }
	    outfile.close();
	}
    catch (exception& e)  
    {  
        cout << "Standard exception: " << e.what() << endl;
    }     
}

