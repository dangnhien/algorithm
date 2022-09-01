#include <iostream>
using namespace std;

#include "list_int_using_point.h"

/*
Chúng ta sẽ tìm hiểu các vấn đề cơ bản sau:

    Cài đặt danh sách (Khai báo)
    Khởi tạo danh sách rỗng
    Kiểm tra danh sách rỗng (danh sách đầy khi cài bằng mảng)
    Chèn phần tử vào đầu danh sách
    Chèn phần tử vào vị trí thứ k trong danh sách
    Nhập danh sách
    Xuất danh sách
    Tìm 1 phần tử trong danh sách
    Xóa phần tử đầu tiên trong danh sách
    Xóa phần tử thứ k trong danh sách
    Xóa phần tử có nội dung X trong danh sách
*/

// Create list empty.
void Make_Null_List(List &Header)
{
    Header = new Node[sizeof(Node)];
    Header->Next = NULL;
}

/*
    Check list empty:
        if empty --> return  1
        else not empty --> return 0 
*/
int Empty_List(List L)
{
    return (L->Next == NULL);
}

// Return value first list
Position First_List(List L)
{
    return L;
}

Position End_List(List L)
{
    Position P;
    P = First_List(L);
    while (P->Next != NULL)
        P = P->Next;
    return P;
}

Position Next_List(Position P, List L)
{
    return P->Next;
}

// Insert element X into list L at location P
void Insert_Into_List(ElementType X, Position P, List &L)
{
    Position Temp; //Create node new
    
    Temp = new Node[sizeof(Node)]; // Memory allocation node new. This node pointed to by Temp
    Temp->Element = X; // Assign the appropriate value 
    Temp->Next = P->Next;
    P->Next = Temp;
}

// Insert element X into list L at location: location
void Insert_List(ElementType X, int location, List &L)
{
    Position P;

    P = L;
    while ((P->Next != NULL) && (location > 1))
    {
        P = P->Next;
        location--;
    }

    Insert_Into_List(X, P, L);
}


// Insert element X into first list 
void Insert_First_List(ElementType X, List &L)
{
    Insert_Into_List(X, First_List(L), L);
}

// Insert element X into end list
void Insert_End_List(ElementType X, List &L)
{
    Insert_Into_List(X, End_List(L), L);
}

// Delete element P in list L
void Delete_List(Position P, List &L)
{
    Position Temp;
    if (P->Next != NULL)
    {
        Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}

// Location element X in list L
Position Locate(ElementType X, List L)
{
    Position P = L;
    while (P->Next != NULL)
        if (P->Next->Element == X)
            break;
        else
            P = P->Next;
    return P;
}


// Value element at location P in list L
ElementType Retrieve(Position P, List L)
{
    if (P->Next != NULL)
        return P->Next->Element;
}
// Enter list 
void Read_List(List &L) 
{
    int n, i = 0;
    cout << "\nEnter number of element of list: ";
    cin >> n;

    ElementType X;
    while (i < n)
    {
        cout << "\n-Enter element number " << i + 1 << ": ";
        cin >> X;
        Insert_End_List(X, L);
        i++;
    }
}

// Printf list
void Print_List(List &L)
{
    Position P = First_List(L);
    while (P->Next != NULL)
    {
        cout << P->Next->Element << " ";
        P = P->Next;
    }
}

// Printf list reserver
void Print_Rev_List(List L)
{

    if (L->Next != NULL)
    {
        Position P = L->Next;
        if (P->Next == NULL)
            cout << P->Element << " ";
        else
        {
            Print_Rev_List(L->Next);
            cout << P->Element << " ";
        }
    }
}

// Filter elements sample
void Distinct(List &L)
{
    Position P, Q;

    for (P = L; P->Next != NULL; P = P->Next)
        for (Q = P->Next; Q->Next != NULL;)
            if (P->Next->Element == Q->Next->Element)
                Delete_List(Q, L);
            else
                Q = Q->Next;
}

void Swap(Position &x1, Position &x2)
{
    ElementType Temp = x1->Next->Element;
    x1->Next->Element = x2->Next->Element;
    x2->Next->Element = Temp;
}

// Sort list increase
void Sort(List &L)
{
    Position P, Q;
    ElementType Temp;

    for (P = L; P->Next != NULL; P = P->Next)
        for (Q = P->Next; Q->Next != NULL; Q = Q->Next)
            if (P->Next->Element > Q->Next->Element)
                Swap(P, Q);
}

// Counter element in list
int Element_Counter(List L)
{
    int numberElement = 0;
    Position P = First_List(L);
    while (P != End_List(L))
    {
        numberElement++;
        P = Next_List(P, L);
    }
    return numberElement;
}

