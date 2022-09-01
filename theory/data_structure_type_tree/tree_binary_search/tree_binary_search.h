#ifndef TREE_BINARY_SEARCH_H
#define TREE_BINARY_SEARCH_H

typedef int ElementType;

struct Node
{
    struct Node *left, *right;
    ElementType data;
};

typedef struct Node Node;

typedef Node *Tree;

void init(Tree &t);

Node *createNode(int x);

void insertNode(Tree &t, Node *p);

void enter(Tree &t);

void node_left_right(Tree t);
void node_right_left(Tree t);

void left_node_right(Tree t);
void right_node_left(Tree t);

void left_right_node(Tree t);
void right_left_node(Tree t);

int countLeafNode(Tree t);

int sumOfLeafNode(Tree root);

void deleteLeafNode(Tree &root);
Node *removeLeafNode(Tree &root);


int countNode(Tree root);
void countNode_Way2(Tree root, int &count);

int sumNodeOfTree(Tree root);
int sumNodeOfTree_Way2(Tree root, int &sum);

int maxDepth(Tree root);
int minDepth(Tree root);

Node *searchNode(Tree root, int x);

#endif