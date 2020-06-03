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
	int node_id;
    int nodesize;
	bool leaf;
	int numkeys;
	std::vector<int> keys ;//= new vector<int>(4);
	std::vector<TreeNode *> children;//children(5);
	TreeNode* next;


    TreeNode (bool is_leaf, int id){
        next = NULL;
		node_id = id;
        leaf = is_leaf;
        numkeys = 0;
		//keys.reserve(NODESIZE);
		//children.reserve(NODESIZE + 1);
    }

	//functions
	void print_TreeNode();

};

void TreeNode::print_TreeNode(){
    cout << "[ TreeNode ID: " << node_id<< " -- Keys:"<<endl;
	cout << "{ ";
    int size = numkeys;
    for(int i = 0; i < numkeys;i++){
        cout << keys[i] << " ";
    }
	cout << " }" << endl;
	cout << "Here:"<<endl;
	cout << " Next ID: "<< next->node_id << " ] \n\n";
    
}



void bulk_load(std::vector<int> inputs) {

	TreeNode* root = NULL;
	TreeNode* curr = NULL;

	vector<int> temp_keys;
	int nodes_count = 1;

	for(int i = 0; i < inputs.size(); i++){ // go through all input values
		temp_keys.push_back(inputs[i]);
		//cout << inputs[i] << endl;

		if ((i+1) % 4 == 0 && nodes_count == 1){ // this is the root node
			cout << "root node"<<endl;
			TreeNode* root_leaf = new TreeNode(true, nodes_count);
			root = root_leaf;
			root_leaf->keys = temp_keys;
			root_leaf->numkeys = temp_keys.size();
			nodes_count ++;
			temp_keys.clear();
		}
		else if ((i+1) % 4 == 0 || i == inputs.size()-1){ // not the root node
			cout << "not the root"<<endl;
			TreeNode* new_leaf = new TreeNode(true, nodes_count);
			new_leaf->keys = temp_keys;
			new_leaf->numkeys = temp_keys.size();
			root->next = new_leaf;
			root->print_TreeNode();
			root = new_leaf;
			

			nodes_count ++;
			temp_keys.clear();
		}

	}

}	




int main() {
	int x;
	//cout << "Enter 1 for input file of list of numbers, Enter 2 for input file of created B+ Tree: ";
	//cin >> x;


	//Input file of random unordered numbers
	//if (x == 1) {
		std::vector<int> datakeys;
		string s;

		// cout << "Enter name of the input file:";
		// cin >> s;
		ifstream infile;
		infile.open("input1.txt");

		// cout << "Enter name of output file:";
		// cin >> s;
		// ofstream output;
		// output.open(s);

		while (getline(infile, s)) {
			int z = std::stoi(s);
			datakeys.push_back(z);
		}
		std::sort(datakeys.begin(), datakeys.end());

		bulk_load(datakeys);
	//}
}