// Closed Hashing
// a program to show searching using closed hashing.
#include <iostream>
#include <cstdlib>
#include "hash.h"
using namespace std;

ClosedHashtable::ClosedHashtable()
{
	for ( i = 0;i < 10;i++ ) //to initialize every element as ‘-1’
		ht[i] = -1;
}

void ClosedHashtable::insert_val()
{
	string val, f = "";
	cout <<  "\nEnter the element to be inserted : ";
	cin >> val;
	key = ( val % 10 ) - 1;
	if ( ht[key] == "-1" )
	{
		ht[key] = val;
	}
	else
	{
		if ( key < 9 )
		{
			for ( i = key + 1;i < 10;i++ )
			{
				if ( ht[i] == -1 )
				{
					ht[i] = val;
					break;
				}
			}
		}

		for ( i = 0;i < key;i++ )
		{
			if ( ht[i] == -1 )
			{
				ht[i] = val;
				break;
			}
		}
	}
}

void ClosedHashtable::display()
{
	for (i = 0;i < 10;i++)
	cout <<  "\t" << ht[ i ];
}

void ClosedHashtable::search_val()
{
	int val, flag = 0;
	cout <<  "\nEnter the element to be searched :: ";
	cin >> val;
	key = ( val % 10 ) - 1;
	if ( ht[ key ] == val )
		flag = 1;
	else
	{
		for (i = key + 1;i < 10;i++)
		{
			if(ht[i] == val)
			{
				flag = 1;
				key = i;
				break;
			}
		}
	}

	if (flag == 0)
	{
		for (i = 0;i < key;i++)
		{
			if (ht[ i ] == val)
			{
				flag = 1;
				key = i;
				break;
			}
		}
	}

	if (flag == 1)
	{
		found=1;
		cout << "\n The item searched was found at position " << key + 1;
	}
	else
	{
		key = -1;
		cout <<  "\nThe item searched was not found in the hash table";
	}
}

void ClosedHashtable::delete_val()
{
	int val, flag = 0;
	cout <<  "\nEnter the element to be deleted :: ";
	cin >> val;
	key = ( val % 10 ) - 1;
	if ( ht[ key ] == val )
		flag = 1;
	else
	{
		for (i = key + 1;i < 10;i++)
		{
			if(ht[i] == val)
			{
				flag = 1;
				key = i;
				break;
			}
		}
	}

	if (flag == 0)
	{
		for (i = 0;i < key;i++)
		{
			if (ht[ i ] == val)
			{
				flag = 1;
				key = i;
				break;
			}
		}
	}

	if (flag == 1)
	{
		ht[key+1] = -1;
		cout << "\n The item searched was found at position " << key + 1;
	}
	else
	{
		key = -1;
		cout <<  "\nThe item you wanted to delete was not found in the hash table.";
	}


}

