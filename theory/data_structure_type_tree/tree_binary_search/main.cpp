#include <iostream>
using namespace std;

#include "main.h"
#include "tree_binary_search.h"

int main()
{
    /*
        Tree:     50
                 /  \
                30    70
               / \    / \
              20 40  60 90
    */

    Tree t;

    init(t);

    enter(t);

    cout << "\nTraverse tree NLR ";
    node_left_right(t);

    cout << "\nTraverse tree NRL ";
    node_right_left(t);

    cout << "\nTraverse tree LNR ";
    left_node_right(t);

    cout << "\nTraverse tree RNL ";
    right_node_left(t);

    cout << "\nTraverse tree LRN ";
    left_right_node(t);

    cout << "\nTraverse tree RLN ";
    right_left_node(t);
    cout << "\n";

    cout << "\nNumber Leaf Node: " << countLeafNode(t) << "\n";

    cout << "\nSum nodes leaf: " << sumOfLeafNode(t) << "\n";

    /*
        // Way 1: Delete leaf node
        deleteLeafNode(t);
        cout<<"\nBinary search tree remain after clear leaf nodes: ";
        left_node_right(t);
    */

    /*
         // Way 2: Delete leaf node
         t = removeLeafNode(t);
         cout<<"\nBinary search tree remain after clear leaf nodes: ";
         left_node_right(t);
     */

    cout << "\nNumber of node in binary search tree: " << countNode(t) << "\n";

    int count_node_tree = 0;
    countNode_Way2(t, count_node_tree);
    cout << "\nNumber of node in binary search tree: " << count_node_tree << "\n";

    cout << "\nSum of node in binary search tree: " << sumNodeOfTree(t) << "\n";

    int sum=0;
    sumNodeOfTree_Way2(t, sum);
    cout << "\nSum of node in binary search tree way 2: " << sum << "\n";

    cout << "\nTrung binh cong of binary search tree: " << (1.*sumNodeOfTree(t) / count_node_tree) << "\n";

    cout<<"\nHight max of tree: "<<maxDepth(t)<<"\n";

    cout<<"\nHight min of tree: "<<minDepth(t)<<"\n";

    int node_need_find_hight;
    cout<<"\nEnter node need find maxDepth: ";cin>>node_need_find_hight;
    Node *p = searchNode(t, node_need_find_hight);
    cout<<"\nHight max of node( tree child): "<<maxDepth(p)<<"\n";

    return 0;
}
