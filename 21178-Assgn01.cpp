#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *left;
	Node *right;
};
class BST
{
public:
	Node *root;
	BST()
	{
		root = NULL;
	}
	void insert();
	void inorder(Node *);
	void search(int key);
	void minimum();
	void maximum();
	int height(Node *);
	void mirror(Node *);
};
void BST::insert()
{
	Node *curr, *temp;
	cout << "Enter Data : ";
	curr = new Node;
	cin >> curr->data;
	curr->left = curr->right = NULL;
	if (root == NULL)
	{
		root = curr;
	}
	else
	{
		temp = root;
		while (1)
		{
			if (curr->data <= temp->data)
			{
				if (temp->left == NULL)
				{
					temp->left = curr;
					break;
				}
				else
				{
					temp = temp->left;
				}
			}
			else
			{
				if (temp->right == NULL)
				{
					temp->right = curr;
					break;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
}
void BST::inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << " " << root->data;
		inorder(root->right);
	}
}
void BST::minimum()
{
	Node *temp;
	int min;
	temp = root;
	while (temp->left != NULL)
	{
		min = temp->data;
		temp = temp->left;
		if (temp->data < min)
		{
			min = temp->data;
		}
		else
		{
			temp = temp->left;
		}
	}
	cout << "minimum no. is:" << min;
}
void BST::maximum()
{
	Node *temp;
	int max;
	temp = root;
	while (temp->right != NULL)
	{
		max = temp->data;
		temp = temp->right;
		if (temp->data > max)
		{
			max = temp->data;
		}
		else
		{
			temp = temp->right;
		}
	}
	cout << "Maximum no. is : " << max;
}
int BST::height(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		if (height(root->right) > height(root->left))
		{
			return (1 + height(root->right));
		}
		else
		{
			return (1 + height(root->left));
		}
	}
}
void BST::search(int key)
{
	Node *curr;
	curr = root;
	while (curr != NULL)
	{
		if (curr->data == key)
		{
			cout << "found";
			break;
		}
		else
		{
			if (key < curr->data)
			{
				curr = curr->left;
			}
			else
			{
				curr = curr->right;
			}
		}
	}
	if (curr == NULL)
	{
		cout << "not found";
	}
}
void BST::mirror(Node *node)
{
	if (node == NULL)
		return;
	else
	{
		Node *temp;
		mirror(node->left);
		mirror(node->right);
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}
int main()
{
	BST b;
	int key, ch;
	do
	{
		cout << endl;
		cout << "1. Insert    : " << endl;
		cout << "2. Inorder   : " << endl;
		cout << "3. Search    : " << endl;
		cout << "4. Minimum   : " << endl;
		cout << "5. Maximum   : " << endl;
		cout << "6. Height    : " << endl;
		cout << "7. Swap      : " << endl;
		cout << "Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			b.insert();
			break;
		case 2:
			cout << "InOrder traversal is : " << endl;
			b.inorder(b.root);
			break;
		case 3:
			cout << "Enter key : " << endl;
			cin >> key;
			b.search(key);
			break;
		case 4:
			b.minimum();
			break;
		case 5:
			b.maximum();
			break;
		case 6:
			cout << "Height of tree: " << b.height(b.root) << endl;
			break;
		case 7:
			cout << "Initially, the BST is : " << endl;
			b.inorder(b.root);
			b.mirror(b.root);
			cout << "Finally, the BST is : " << endl;
			b.inorder(b.root);
			break;
		}
	} while (ch != 0);
	return 0;
}
