#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
template <class HashedObj>
class HashTable
{
public:
	HashTable();
	
	const HashedObj & find(const HashedObj & x) const;

	void insert(const HashedObj & x);
	void remove(const HashedObj & x);

	const HashTable & operator=(const HashTable & rhs);

	enum EntryType {ACTIVE, EMPTY, DELETED}; //active means something is inside, empt means available for insertion, deleted for deleted cell available but not searchable

	int findPos(const HashedObj & x) const;
	struct HashEntry
	{
		HashedObj element;
		EntryType info;

		HashEntry(const HashedObj & e = HashedObj(), EntryType i = EMPTY)
			: element(e), info(i) {}
	};
	vector<HashEntry> array;
	
	bool isActive(int currentPos) const;
private:
	const HashedObj ITEM_NOT_FOUND;
};
#include "hashtable.cpp"
#endif