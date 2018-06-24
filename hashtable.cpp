#include <iostream>
#include "hashtable.h"
using namespace std;

template <class HashedObj>
HashTable<HashedObj>::HashTable()
{
	for(int i=0;i<4096;i++)
	{
		array.push_back(HashEntry("",EMPTY));
	}
}

// Return the position where the search for x terminates
template <class HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj & x) const
{
	int currentPos = 0;

	while(array[currentPos].info != EMPTY && array[currentPos].element != x)
	{
		currentPos ++;
	}
	if(currentPos >= array.size()) // perform the mod
	{
		currentPos = currentPos - array.size(); // if necessary
	}
	return currentPos;
}

// Return true if currentPos exists and is active.
template <class HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
	return array[currentPos].info == ACTIVE;
}

/*** Remove item x from the hash table.  x has to be in the table*/
template <class HashedObj>
void HashTable<HashedObj>::remove(const HashedObj & x)
{
	int currentPos = findPos(x);
	if( isActive(currentPos))
		array[currentPos].info = DELETED;
}

/*** Find item x in the hash table. Return the matching item, or ITEM_NOT_FOUND, if not found.*/
template <class HashedObj>
const HashedObj & HashTable<HashedObj>::find(const HashedObj & x) const
{
	int currentPos = findPos(x);
	if (isActive(currentPos)) 
		return array[currentPos].element; 

	return   ITEM_NOT_FOUND;
}

/*** Insert item x into the hash table. If the item is already present, then do nothing.*/
template <class HashedObj>
void HashTable<HashedObj>::insert(const HashedObj & x)
{
	// Insert x as active
	int currentPos = findPos(x);
	if(isActive(currentPos))
		return;
	array[currentPos] = HashEntry(x,ACTIVE);
}

