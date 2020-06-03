
class Leaf_Node {
    LeafNode nextNode;
    search
}

class Data_Node {
    Vector<String> data_list;
    Vector<Data_Node> child_node_list;
    Data_Node next_DataNode;
    
    //set next datanode
    //get data_list
    //add a value
    //set data index (index i, string value)
    //print data node
    //get children
    //add child at index (index i, datanode value)
    //add child (datanode value)
    //set children
    
}

// level has a vector of data nodes
// data node has vector of data, vector of children

class Tree_Node {
    // nodes need data, parent, and capacity
    int search_key_val; // must be distinct
    int record_id;
    
    Tree_Node parent;
    
    // vector of data_nodes for a tree node
    Vector<DataNode> data_nodes;
    
    // max number of data_nodes that can be stored
    int max_capacity;
    
    bool is_Leaf;
    
  
    
}

class B_Plus_Tree {
    int degree;
    Tree_Node root;
    
    


}
