#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cctype>
#include <cstring>
#include <iterator>
#include <fstream>

using namespace std;

const int NODESIZE = 4;

class TreeNode {
	public:
		int nodesize;
		bool leaf;
		int numkeys;
		std::vector<int> keys ;//= new vector<int>(4);
		std::vector<TreeNode *> children;//children(5);
		TreeNode* split;

		TreeNode (bool is_leaf){
			this -> split = NULL;
			this -> leaf = is_leaf;
			this -> numkeys = 0;
			this -> keys.reserve(NODESIZE);
			this -> children.reserve(NODESIZE + 1);
		}

};

//void TreeNode::print_TreeNode(TreeNode* treenode){
//    cout << "TreeNode keys: {"<<endl;
//    int size = treenode->numkeys;
//    for(int i = 0; i < numkeys;i++){
//        cout << treenode->keys[i] << " , ";
//    }
//    cout << "}" << endl;
//}

TreeNode* BulkLoad(std::vector<int> &inputs) {
 	std::vector<TreeNode> leafnodes;

	int y = 0;
	TreeNode* temp = new TreeNode(true);

	for (auto x : inputs) {
		if (y == 4) {
			
			leafnodes.push_back(*temp);
			if (leafnodes.size() > 1) {
				leafnodes[leafnodes.size() - 2].split = &leafnodes.back();
			}
			temp = new TreeNode(true);
			y = 0;
			temp->keys.push_back(x);
			y++;
		}else{
			temp->keys.push_back(x);
			y++;
		}
	}

	leafnodes.push_back(temp);
	leafnodes[leafnodes.size() - 2].split = &leafnodes[leafnodes.size()-1];
	//cout << leafnodes[0].keys[leafnodes[0].keys.size() - 2] << " " << leafnodes[0].keys[leafnodes[0].keys.size() - 1];


	
	cout << leafnodes[0].split->keys[0];
	for (int i = 0; i < leafnodes.size(); i++) {
		cout << "{";
		for (int y = 0; y < leafnodes[i].keys.size(); y++) {
			cout << leafnodes[i].keys[y] << ", ";
		}
		cout << "} and connects to: {";

		//if (i != leafnodes.size() - 1) {
		//	for (int y = 0; y < leafnodes[i].*split.keys.size(); y++) {
		//		cout << leafnodes[i].*split.keys[y] << ", ";
		//	}
		//}

		cout << "}\n";

	}

	return &leafnodes[0];
}


// ********************************************
//TreeNode* BulkLoad(std::vector<int> &inputs) {
//
//	TreeNode prev_leaf* = new TreeNode(true); // aka the root
//
//	for(int i = 0; i < inputs.size(); i++){ // go through all input values
//		TreeNode *new_leaf = new TreeNode(true)
//
//		for(int j = 0; j < 4; j++){ //for every 4 values, push_back to node's keys vector
//			new_leaf->keys.push_back(inputs[i])
//			new_leaf->numkeys++;
//		}
//
//		if (new_leaf->numkeys > 0) { // if not empty
//			prev_leaf->next = new_leaf;
//			prev_leaf = new_leaf;
//		}
//	}
//	return prev_leaf; 
//}	


// ****************************************************




int main() {
	int x;
	cout << "Enter 1 for input file of list of numbers, Enter 2 for input file of created B+ Tree: ";
	cin >> x;


	//Input file of random unordered numbers
	if (x == 1) {
		std::vector<int> datakeys;
		string s;

		cout << "Enter name of the input file:";
		cin >> s;
		ifstream infile;
		infile.open(s);

		//cout << "Enter name of output file:";
		//cin >> s;
		//ofstream output;
		//output.open(s);

		while (getline(infile, s)) {
			int z = std::stoi(s);
			datakeys.push_back(z);
		}
		std::sort(datakeys.begin(), datakeys.end());

		TreeNode* root = BulkLoad(datakeys);
	}
}