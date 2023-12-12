#include <iostream>
using namespace std;
class Node
{
	friend class hashTable;
	string word;
	string meaning;
	Node *next;

public:
	Node()
	{
		word = "";
		meaning = "";
		next = NULL;
	}
	Node(string w, string m)
	{
		word = w;
		meaning = m;
		next = NULL;
	}
};
class hashTable
{
	Node *hashArr[26];

public:
	hashTable()
	{
		for (int i = 0; i < 26; i++)
		{
			hashArr[i] = NULL;
		}
	}
	int hashFunc(string w)
	{
		return (int(w[0]) - int('A'));
	}
	void insert(string w, string m)
	{
		Node *nn = new Node(w, m);
		int k = hashFunc(w);
		if (hashArr[k] == NULL)
		{
			hashArr[k] = nn;
		}
		else
		{
			Node *temp = hashArr[k];
			while (temp->next)
				temp = temp->next;
			temp->next = nn;
		}
	}
	void display()
	{
		cout << "Index "
			 << " [Words,Meaning] " << endl;
		for (int i = 0; i < 26; i++)
		{
			cout << i + 1 << " [" << char(65 + i) << "] : ";
			Node *temp = hashArr[i];
			while (temp)
			{
				cout << "[" << temp->word << ", " << temp->meaning << "]"
					 << "==>";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	void remove(string w)
	{
		int hashValue = hashFunc(w);
		if (hashArr[hashValue] == NULL)
		{
			cout << "No such word is present. " << endl;
			return;
		}
		if (hashArr[hashValue]->word == w)
		{
			hashArr[hashValue] = hashArr[hashValue]->next;
			return;
		}
		Node *temp = hashArr[hashValue];
		Node *temp2 = hashArr[hashValue]->next;
		while (temp2 != NULL)
		{
			if (temp2->word == w)
			{
				temp->next = temp2->next;
				temp2 = NULL;
				return;
			}
		}
		cout << "No such word is present. " << endl;
	}
	void search(string w)
	{
		int hashValue = hashFunc(w);
		if (hashArr[hashValue] == NULL)
		{
			cout << "No such word is present. " << endl;
			return;
		}
		if (hashArr[hashValue]->word == w)
		{
			cout << "Word has been found at " << hashValue << "." << endl;
			return;
		}
		Node *temp2 = hashArr[hashValue];
		while (temp2 != NULL)
		{
			if (temp2->word == w)
			{
				cout << "Word has been found at " << hashValue + 1 << "." << endl;
				return;
			}
			temp2 = temp2->next;
		}
		cout << "No such word is present. " << endl;
	}
};
int main()
{
	hashTable h;
	string w1, m1, w2, w3;
	int choice;
	do
	{
		cout << endl;
		cout << "1. Insert  : " << endl;
		cout << "2. Search  : " << endl;
		cout << "3. Delete  : " << endl;
		cout << "4. Display : " << endl;
		cout << "Enter your Choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter Word to be Inserted : ";
			cin >> w1;
			cout << "Enter Meaning of the Word : ";
			cin >> m1;
			h.insert(w1, m1);
			break;
		case 2:
			cout << "Enter Word to be Searched : ";
			cin >> w2;
			h.search(w2);
			break;
		case 3:
			cout << "Enter Word to be Deleted  : ";
			cin >> w3;
			h.remove(w3);
			break;
		case 4:
			cout << "HashTable has been Displayed : " << endl;
			h.display();
			break;
		}
	} while (choice != 0);
	return 0;
}
