#include <iostream>
using namespace std;

#include "tree_binary_search.h"

void init(Tree &t)
{
    t = NULL;
}

Node *createNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

// Insert element into binary search tree
void insertNode(Tree &t, Node *p)
{
    if (t)
    {
        if (p->data == t->data)
            return;
        else if (p->data < t->data)
            insertNode(t->left, p);
        else
            insertNode(t->right, p);
    }
    else
    {
        t = new Node;
        t = p;
    }
}

void enter(Tree &t)
{
    while (1)
    {
        int x;

        cout << "\nEnter x = ";
        cin >> x;

        if (x != 0)
        {
            Node *p = createNode(x);
            insertNode(t, p);
        }
        else
            break;
    }
}

// Traverse binary search tree - duyêt cây
void node_left_right(Tree t)
{
    if (t != NULL) // t != empty --> t != NULL
    {
        cout << t->data << " ";
        node_left_right(t->left);
        node_left_right(t->right);
    }
}

void node_right_left(Tree t)
{
    if (t) // t != empty --> t != NULL
    {
        cout << t->data << " ";
        node_right_left(t->right);
        node_right_left(t->left);
    }
}

// Order increase
void left_node_right(Tree t)
{
    if (t)
    {
        left_node_right(t->left);
        cout << t->data << " ";
        left_node_right(t->right);
    }
}

// Order decrease
void right_node_left(Tree t)
{
    if (t)
    {
        right_node_left(t->right);
        cout << t->data << " ";
        right_node_left(t->left);
    }
}

void left_right_node(Tree t)
{
    if (t)
    {
        left_right_node(t->left);
        left_right_node(t->right);
        cout << t->data << " ";
    }
}

void right_left_node(Tree t)
{
    if (t)
    {
        right_left_node(t->right);
        right_left_node(t->left);
        cout << t->data << " ";
    }
}

/*
    - Ý tưởng:
    Xuất phát từ nút gốc, tìm ở hai nhánh cây con trái và phải của node gốc.
    Nếu tìm thấy thì trả về giá trị 1, nếu node đang xét là NULL thì trả về 0.
    Tiếp tục cho tới khi duyệt hết cây con thì thôi.

    - Các bước thực hiện:
    Step 1: Điều kiện dừng: if root == NULL thì return 0;
    Step 2: Nếu root->left = root->right = NULL thì return 1;
    Step 3: Call đệ quy tìm số node leaf of tree child bên left and tree child bên right
*/
int countLeafNode(Tree t)
{
    if (t == NULL)
        return 0;

    if (t->left == NULL && t->right == NULL)
        return 1;
    else
        return (countLeafNode(t->left) + countLeafNode(t->right));
}

/*
    Chương trình tính tổng các node leaf in binary search tree have node root is root.
    - Ý tưởng: tương tự như đếm số node lá.
    - Các step thực hiện:
    Step 1: Nếu root == NULL thì return 0;
    Step 2: Nếu root is root leaf thì return root->data;
    Step 3: Call đệ quy cộng tổng và return value of các node leaf in tree.
*/
int sumOfLeafNode(Tree root)
{
    if (!root)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return root->data;
    else
        return (sumOfLeafNode(root->left) + sumOfLeafNode(root->right));
}

/*
    Xoá leaf node
    Cách 1: sử dụng hàm void bình thường, không trả về.
*/
void deleteLeafNode(Tree &root)
{
    // Duyệt theo kiểu node_left_right
    if (root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            root = NULL;
        }
        else
        {
            deleteLeafNode(root->left);
            deleteLeafNode(root->right);
        }
    }
}

/*
    Xoá leaf node
    Cách 2: sử dụng con trỏ node.
*/
Node *removeLeafNode(Tree &root)
{
    if (root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else
        {
            root->left = removeLeafNode(root->left);
            root->right = removeLeafNode(root->right);
        }
    }
    return root;
}

/*
    Program count số node of a binary search tree
    Cách 1:Đệ quy
    Step 1: Điều kiện true: root = NULL---> return 0;
    Step 2: Start from node root, count number of node of tree child left
    Step 3: Count number of node of tree child right
    Step 4: Return result: return (number of node child left + number of node child right) + 1;  (+1 is nude root)
*/

int countNode(Tree root)
{
    if (root == NULL)
        return 0;
    else
        return (countNode(root->left) + countNode(root->right) + 1);
}

/*
    Program count số node of a binary search tree
    Cách 2: Đệ quy + duyệt node( left_node_right )
    Duyệt cây theo thứ tự bất kỳ , use variable count to count number of node in tree.
    Thay vì output information node, ta increase value variable count.
    Call đệ quy để thực hiện cho tới khi duyệt hết tree thì stop.
*/
void countNode_Way2(Tree root, int &count)
{
    if (root)
    {
        count++;
        countNode_Way2(root->left, count);
        countNode_Way2(root->right, count);
    }
}

/*
    Tính trung bình cộng các node in tree
    = Tổng các nude / Số nude.
*/

/*
    Sum of nudes in binary search tree
    Way 1:
    - Steps thực hiện
    Step 1: Điều kiện dừng là root == NULL: return 0;
    Step 2: Start from node root, cộng tổng các node of tree child left
    Step 3: Tương tự, cộng tổng các nude của cây con phải.
    Step 4: Return result : return (sum các nude child left + sum nudes child right + root->data);
*/
int sumNodeOfTree(Tree root)
{
    if (root == NULL)
        return 0;
    else
        return (sumNodeOfTree(root->left) + sumNodeOfTree(root->right) + root->data);
}

/*
    Sum of nudes in binary search tree
    Way 2:
    - Steps thực hiện
    Duyệt tree theo thứ tự bất kỳ, use variable sum to tính sum nodes in tree.
    Thay vì output information node thì ta increase update sum = sum + root->data.
    Call đệ quy để thực hieenjcho tới khi duyệt hết tree thì stop
*/
int sumNodeOfTree_Way2(Tree root, int &sum)
{
    if (root)
    {
        sum += root->data;
        sumNodeOfTree_Way2(root->left, sum);
        sumNodeOfTree_Way2(root->right, sum);
    }
}

/*
    Program find hight max of tree start from node root of binary search tree.
    Step 1: if root == NULL: return -1;
    Step 2: Find hight of tree child left
    Step 3: Find hight of tree child right
    Step 4: Return hight max: Max(leftDepth, rightDepth) + 1;
    Here chính is hight need find of binary search tree
    ____Logic tượng tự, ta find được hight of a nhánh start from a node bất kỳ of tree.
    You want find hight min tree start from node root?
    -->Hãy do tương tự above chỉ different at step 4 is return Min(leftDepth, rightDepth);
*/
int maxDepth(Tree root)
{
    if (!root)
        return -1;
    else
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int minDepth(Tree root)
{
    if (!root)
        return -1;
    else
        return min(minDepth(root->left), minDepth(root->right)) + 1;
}

Node *searchNode(Tree root, int x)
{
    if (root != NULL)
    {
        if (root->data == x)
            return root;
        else if (root->data > x)
            return searchNode(root->left, x);
        else if (root->data < x)
            return searchNode(root->right, x);
    }
    return NULL;
}

/*
    Clear a node in binary search tree
    Explain --> file pdf.
*/