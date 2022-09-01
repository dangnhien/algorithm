#include <iostream>
#include <cstring>

using namespace std;

#include "main.h"
#include "list_student_using_point.h"

int main()
{
    menu();
    return 0;
}

void menu()
{
    int id_student;
    char *t;
    int choose;

    List l;
    ElementType X;
    Position P;

    Make_Null_List(l);

    Enter_List(l);

    system("cls");

    do
    {
        system("cls");
        cout << "\n0_Exit."
             << "\n1_Print list student."
             << "\n2_Sort list student by age increase."
             << "\n3_Age medium."
             << "\n4_Delete student by ID."
             << "\nYou choose: ";

        cin >> choose;

        switch (choose)
        {
        case 0:
            break;
        case 1:
            cout << "\nList student present:\n";
            Print_List(l);
            cout << "\n";
            system("pause");
            break;
        case 2:
            Sort(l);
            break;
        case 3:
            cout << "\nAge medium: " << Age_Medium(l) << "\n";
            system("pause");
            break;
        case 4:
            cout << "\nID student need clear: ";
            cin >> id_student;
            Delete(id_student, l);
            break;
        default:
            cout << "\nYou enter error!!! Please enter again."
                 << "\n";
            system("pause");
            break;
        }
    } while (choose != 0);
}
