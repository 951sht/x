#include <bits/stdc++.h>
using namespace std;
class treeNode
{
	int val;
	treeNode *left, *right;
	friend class binary;

public:
	treeNode()
	{
		val = 0;
		left = NULL;
		right = NULL;
	}
};
class binary
{
	treeNode *root;

public:
	int leaves = 0, total = 0;
	binary()
	{
		root = NULL;
	}
	treeNode *createHelper(treeNode *root)
	{
		char chl;
		cout << "Do you want to insert to the left of " << root->val << "?" << endl;
		cin >> chl;
		if (chl == 'y' || chl == 'Y')
		{
			int l;
			cout << "Enter the value to be inserted to the left of " << root->val << ":" << endl;
			cin >> l;
			treeNode *treel = new treeNode();
			treel->val = l;
			root->left = treel;
			root->left = createHelper(root->left);
		}
		char chr;
		cout << "Do you want to insert to the right of " << root->val << "?" << endl;
		cin >> chr;
		if (chr == 'y' || chr == 'Y')
		{
			int r;
			cout << "Enter the value to be inserted to the right of " << root->val << ":" << endl;
			cin >> r;
			treeNode *treer = new treeNode();
			treer->val = r;
			root->right = treer;
			root->right = createHelper(root->right);
		}
		return root;
	}
	void create()
	{
		treeNode *tree = new treeNode();
		cout << "Enter the value of the root node: ";
		cin >> tree->val;
		root = tree;
		createHelper(root);
	}
	void nonReCreate()
	{
		queue<treeNode *> mq;
		if (root == NULL)
		{
			cout << "Enter the value of the root node: ";
			treeNode *tree = new treeNode();
			cin >> tree->val;
			root = tree;
		}
		mq.push(root);
		while (mq.size() > 0)
		{
			int count = mq.size();
			for (int i = 0; i < count; i++)
			{
				treeNode *t = mq.front();
				mq.pop();
				cout << "Do you want to insert to the left of " << t->val << " ?";
				char chl;
				cin >> chl;
				if (chl == 'y' || chl == 'Y')
				{
					treeNode *le = new treeNode();
					cout << "Enter the value to be inserted to the left of " << t->val << " : ";
					cin >> le->val;
					t->left = le;
					mq.push(le);
				}
				char chr;
				cout << "Do you want to insert to the right of " << t->val << " ?";
				cin >> chr;
				if (chr == 'y' || chr == 'Y')
				{
					treeNode *ri = new treeNode();
					cout << "Enter the value to be inserted to the right of " << t->val << " : ";
					cin >> ri->val;
					t->right = ri;
					mq.push(ri);
				}
			}
		}
	}
	void displayHelper(treeNode *tree)
	{
		if (tree == NULL)
		{
			cout << "Empty Tree" << endl;
			return;
		}
		queue<treeNode *> mq;
		mq.push(tree);
		while (mq.size() > 0)
		{
			int count = mq.size();
			for (int i = 0; i < count; i++)
			{
				treeNode *t = mq.front();
				mq.pop();
				cout << t->val << " ";
				if (t->left != NULL)
				{
					mq.push(t->left);
				}
				if (t->right != NULL)
				{
					mq.push(t->right);
				}
			}
			cout << endl;
		}
	}
	void display()
	{
		displayHelper(root);
	}
	void inorderHelper(treeNode *root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			inorderHelper(root->left);
			cout << root->val << " ";
			inorderHelper(root->right);
		}
	}
	void inorder()
	{
		inorderHelper(root);
	}
	void non_recursive()
	{
		stack<pair<treeNode *, int>> st;
		vector<int> pre;
		vector<int> in;
		vector<int> post;
		st.push(make_pair(root, 1));
		while (st.size() > 0)
		{
			if (st.top().second == 1)
			{
				pre.push_back(st.top().first->val);
				st.top().second++;
				if (st.top().first->left != NULL)
				{
					st.push(make_pair(st.top().first->left, 1));
				}
			}
			else if (st.top().second == 2)
			{
				in.push_back(st.top().first->val);
				st.top().second++;
				if (st.top().first->right != NULL)
				{
					st.push(make_pair(st.top().first->right, 1));
				}
			}
			else
			{
				post.push_back(st.top().first->val);
				st.pop();
			}
		}
		cout << endl;
		cout << "PREORDER: ";
		for (int i = 0; i < pre.size(); i++)
		{
			cout << pre[i] << " ";
		}
		cout << endl;
		cout << "INORDER: ";
		for (int i = 0; i < in.size(); i++)
		{
			cout << in[i] << " ";
		}
		cout << endl;
		cout << "POSTORDER: ";
		for (int i = 0; i < post.size(); i++)
		{
			cout << post[i] << " ";
		}
		cout << endl;
	}
	void height()
	{
		cout << "The height of the tree is:" << heightHelper(root) << endl;
	}
	int heightHelper(treeNode *root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int ldepth = heightHelper(root->left);
		int rdepth = heightHelper(root->right);
		return max(ldepth, rdepth) + 1;
	}
	void countLeaves()
	{
		countHelper(root);
		cout << "The number of leaves in the tree are: " << leaves << endl;
		cout << "The number of internal nodes in the tree are: " << total - leaves - 1 << endl;
	}
	void countHelper(treeNode *root)
	{
		int leaves = 0, total = 0;
		if (root == NULL)
		{
			return;
		}
		else if (root->left == NULL && root->right == NULL)
		{
			leaves++;
			total++;
		}
		else
		{
			total++;
			countHelper(root->left);
			countHelper(root->right);
		}
	}
	void swap()
	{
		swapHelper(root);
		display();
	}
	void swapHelper(treeNode *root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			treeNode *temp = root->left;
			root->left = root->right;
			root->right = temp;
			swapHelper(root->left);
			swapHelper(root->right);
		}
	}
	void erase()
	{
		root = NULL;
		int leaves = 0, total = 0;
	}
};
int main()
{
	binary b, obj;
	int choice;
	do
	{
		cout << endl;
		cout << "1. Recursive Create                   : " << endl;
		cout << "2. Non-Recursively Create             : " << endl;
		cout << "3. Display                            : " << endl;
		cout << "4. Display In-Order Recursively       : " << endl;
		cout << "5. Display All Orders Non-Recursively : " << endl;
		cout << "6. Display Height                     : " << endl;
		cout << "7. Display Leaf Count                 : " << endl;
		cout << "8. Display Swapped Tree               : " << endl;
		cout << "9. Make Tree Empty                    : " << endl;
		cout << "Enter your choice                     : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "You have chosen Create Recursively, the Process begins. " << endl;
			b.create();
			break;
		case 2:
			cout << "You have chosen Create Non-Recursively, the Process begins. " << endl;
			b.nonReCreate();
			break;
		case 3:
			cout << "You have chosen Display, the Process begins. " << endl;
			b.display();
			break;
		case 4:
			cout << "You have chosen Display In-Order Recursively, the Process begins. " << endl;
			b.inorder();
			break;
		case 5:
			cout << "You have chosen Display All Orders Non-Recursively, the Process begins. " << endl;
			b.non_recursive();
			break;
		case 6:
			cout << "You have chosen Display Height, the Process begins. " << endl;
			b.height();
			break;
		case 7:
			cout << "You have chosen Display Leaf Count, the Process begins. " << endl;
			b.countLeaves();
			break;
		case 8:
			cout << "You have chosen Display Swapped Tree, the Process begins. " << endl;
			b.swap();
			break;
		case 9:
			cout << "You have chosen to Make Tree Empty, the Process begins. " << endl;
			b.erase();
			break;
		}
	} while (choice != 0);
	return 0;
}
