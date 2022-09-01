#ifndef LIST_INT_USING_POINT_H
#define LIST_INT_USING_POINT_H

// elementType này là kiểu dữ liệu tổng quan, khi làm nó sẽ là kiểu int, float hay kiểu cấu trúc sinh viên.
typedef int ElementType;

struct Node
{
    ElementType Element; // Thành phần thức 1: Biến nguyên chứa dữ liệu
    struct Node *Next;   // Thành phần thứ 2: 1 con trỏ chứa địa chỉ của nút kế tiếp
};

typedef struct Node Node; // Định nghĩa 1 kiểu dữ liệu con trỏ tới nút có tên Node

typedef Node *Position;

typedef Position List;

void Make_Null_List(List &Header);
int Empty_List(List L);

Position First_List(List L);
Position End_List(List L);
Position Next_List(Position P, List L);

void Insert_Into_List(ElementType X, Position P, List &L);
void Insert_List(ElementType X, int location, List &L);

void Insert_First_List(ElementType X, List &L);
void Insert_End_List(ElementType X, List &L);
void Delete_List(Position P, List &L);

Position Locate(ElementType X, List L);
ElementType Retrieve(Position P, List L);

void Read_List(List &L);
void Print_List(List &L);
void Print_Rev_List(List L);
void Distinct(List &L);
void Sort(List &L);
int Element_Counter(List L);


#endif