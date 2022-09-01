#ifndef LIST_STUDENT_USING_POINT_H
#define LIST_STUDENT_USING_POINT_H

struct Element_Type
{
    int id; // code student-msv
    char name[30];
    int age;
};

typedef struct Element_Type ElementType;

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node Node;
typedef Node *Position;
typedef Position List;

void Make_Null_List(List &Header);
Position First(List L);
Position End(List L);
Position Next(Position p, List L);
void Insert_List(ElementType X, Position P, List &L);
void Delete_List(Position P, List &L);
Position Find(int id_student, List L);
void Delete(int id_student, List &L);
Position Locate_Sorted_List(int age, List L);
void Insert_Sorted_List(ElementType x, List &L);
ElementType Retrieve(Position p, List L);
void Sort(List &L);
void Print_List(List L);
void Enter_List(List &L);
double Age_Medium(List L);

#endif