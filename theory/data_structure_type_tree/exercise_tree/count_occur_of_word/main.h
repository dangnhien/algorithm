/*
    Dang Thi Nhien
    Start:  01/09/2022
    Update: 02/09/2022
*/

#ifndef MAIN_H
#define MAIN_H

struct Node{
    Node *right;
    Node *left;
    int count;
    string str;
};

void init(Tree &tree);


typedef Node *Tree;

#endif