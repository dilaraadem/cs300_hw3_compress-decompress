//Dilara Ademoðlu
#include <string>
#include <iostream>
#include "hashtable.h"
#include <fstream>
using namespace std;

int main()
{
	ifstream input("compin1");
	ofstream output("compout");
	HashTable<string> h;
	for(int i=0;i<256;i++)
	{
		unsigned char ch=i;
		string str="";
		str+=ch;
		h.insert(str);
	}
	char ch; //read first input
	input.get(ch);
	string prefix="";
	prefix=prefix+ch; //convert to string
	int pos=h.findPos(prefix);
	while(input.get(ch))//read next char
	{
		string c="";
		string pc="";
		c=c+ch; //convert to string
		pc=prefix+c;
		if(h.find(pc)==pc) //already in the table
		{
			prefix=pc;
		}
		else
		{
			pos=h.findPos(prefix); //find the index of that character
			output<<pos <<" "; // output the code for prefix
			h.insert(pc); //insert to hashtable
			prefix=c;
		}
	}
	pos=h.findPos(prefix);
	output<<pos<< " ";
	input.close();
	output.close();
	return 0;
}