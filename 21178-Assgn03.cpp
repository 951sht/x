#include <iostream>
#include <cstdlib>
#define MAX_VALUE 65536
using namespace std;
class Node
{
public:
	int key;
	Node *left, *right;
	bool leftThread, rightThread;
};
class TBST
{
private:
	Node *root;

public:
	TBST()
	{
		root = new Node();
		root->right = root->left = root;
		root->leftThread = true;
		root->key = MAX_VALUE;
	}
	void makeEmpty();
	void insert(int key);
	bool search(int key);
	void Delete(int key);
	void printTree();
};
void TBST::makeEmpty()
{
	root = new Node();
	root->right = root->left = root;
	root->leftThread = true;
	root->key = MAX_VALUE;
}
void TBST::insert(int key)
{
	Node *p = root;
	for (;;)
	{
		if (p->key < key)
		{
			if (p->rightThread)
				break;
			p = p->right;
		}
		else if (p->key > key)
		{
			if (p->leftThread)
				break;
			p = p->left;
		}
		else
			return;
	}
	Node *tmp = new Node();
	tmp->key = key;
	tmp->rightThread = tmp->leftThread = true;
	if (p->key < key)
	{
		tmp->right = p->right;
		tmp->left = p;
		p->right = tmp;
		p->rightThread = false;
	}
	else
	{
		tmp->right = p;
		tmp->left = p->left;
		p->left = tmp;
		p->leftThread = false;
	}
}
bool TBST::search(int key)
{
	Node *tmp = root->left;
	for (;;)
	{
		if (tmp->key < key)
		{
			if (tmp->rightThread)
				return false;
			tmp = tmp->right;
		}
		else if (tmp->key > key)
		{
			if (tmp->leftThread)
				return false;
			tmp = tmp->left;
		}
		else
			return true;
	}
}
void TBST::Delete(int key)
{
	Node *dest = root->left, *p = root;
	for (;;)
	{
		if (dest->key < key)
		{
			if (dest->rightThread)
				return;
			p = dest;
			dest = dest->right;
		}
		else if (dest->key > key)
		{
			if (dest->leftThread)
				return;
			p = dest;
			dest = dest->left;
		}
		else
			break;
	}
	Node *target = dest;
	if (!dest->rightThread && !dest->leftThread)
	{
		p = dest;
		target = dest->left;
		while (!target->rightThread)
		{
			p = target;
			target = target->right;
		}
		dest->key = target->key;
	}
	if (p->key >= target->key)
	{
		if (target->rightThread && target->leftThread)
		{
			p->left = target->left;
			p->leftThread = true;
		}
		else if (target->rightThread)
		{
			Node *largest = target->left;
			while (!largest->rightThread)
			{
				largest = largest->right;
			}
			largest->right = p;
			p->left = target->left;
		}
		else
		{
			Node *smallest = target->right;
			while (!smallest->leftThread)
			{
				smallest = smallest->left;
			}
			smallest->left = target->left;
			p->left = target->right;
		}
	}
	else
	{
		if (target->rightThread && target->leftThread)
		{
			p->right = target->right;
			p->rightThread = true;
		}
		else if (target->rightThread)
		{
			Node *largest = target->left;
			while (!largest->rightThread)
			{
				largest = largest->right;
			}
			largest->right = target->right;
			p->right = target->left;
		}
		else
		{
			Node *smallest = target->right;
			while (!smallest->leftThread)
			{
				smallest = smallest->left;
			}
			smallest->left = p;
			p->right = target->right;
		}
	}
}
void TBST::printTree()
{
	Node *tmp = root, *p;
	for (;;)
	{
		p = tmp;
		tmp = tmp->right;
		if (!p->rightThread)
		{
			while (!tmp->leftThread)
			{
				tmp = tmp->left;
			}
		}
		if (tmp == root)
			break;
		cout << tmp->key << "   ";
	}
	cout << endl;
}
int main()
{
	TBST tbst;
	cout << endl;
	cout << "Threaded Binary Search Tree Test " << endl;
	char ch;
	int choice, val;
	do
	{
		cout << "Threaded Binary Search Tree Operations " << endl;
		cout << "1. Insert : " << endl;
		cout << "2. Delete : " << endl;
		cout << "3. Search : " << endl;
		cout << "4. Clear  : " << endl;
		cout << "Enter Your Choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter integer element to insert : ";
			cin >> val;
			tbst.insert(val);
			break;
		case 2:
			cout << "Enter integer element to delete : ";
			cin >> val;
			tbst.Delete(val);
			break;
		case 3:
			cout << "Enter integer element to search : ";
			cin >> val;
			if (tbst.search(val) == true)
				cout << "Element " << val << " found in the tree" << endl;
			else
				cout << "Element " << val << " not found in the tree" << endl;
			break;
		case 4:
			cout << "Tree Cleared " << endl;
			tbst.makeEmpty();
			break;
		default:
			cout << "Wrong Entry " << endl;
			break;
		}
		cout << "Tree : ";
		tbst.printTree();
		cout << "Do you want to continue (Enter y or n) : ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	return 0;
}
