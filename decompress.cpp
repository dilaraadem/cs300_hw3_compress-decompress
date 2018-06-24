//Dilara Ademoðlu
#include <string>
#include <iostream>
#include "hashtable.h"
#include <fstream>
using namespace std;

int main()
{
	ifstream input("compout");
	ofstream output("decompout");
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
	string word;
	while ( ch != ' ' )
	{
		word = word + ch;
		input.get(ch);
	}
	string old=word;
	int code,ncode,ocode;
	code=atoi(old.c_str()); //get the position of the value
	string phrase=h.array[code].element; //value in that code
	output<< phrase; //output it
	cout<<phrase<<endl;
	char new_code;
	string newstr, str, c, oc;
	c=phrase;
	while(input.get(new_code))//read new code
	{
		word=""; 
		while (new_code != ' ')
		{
			word = word + new_code;
			input.get(new_code);
		}
		newstr=word;
		ncode=atoi(newstr.c_str());
		ocode=h.findPos(phrase);
		if(!h.isActive(ncode)) //not in the dict
		{
			str=h.array[ocode].element; //translation of old code
			str=str+c;
		}
		else //in the dict
		{
			if(new_code>4096)
				return 0;
			str=h.array[ncode].element; //translation of new code
		}
		output<<str; //output
		cout<<str<<endl;
		c=str.substr(0,1);
		oc=phrase+c;
		h.insert(oc);
		phrase=h.array[ncode].element;
	}
	input.close();
	output.close();
	return 0;
}