#include <iostream>
using namespace std;

#include "main.h"
#include "list_int_using_point.h"

int main()
{
    menu();
    return 0;
}

void menu()
{
    system("cls");
    List L;
    ElementType X;
    Position P;
    int viTri;


    Make_Null_List(L);

    Read_List(L);

    int choose;

    do
    {
        system("cls");
        cout << "\n____________MENU_________________"
             << "\n1_Sort list."
             << "\n2_Insert element into end list."
             << "\n3_Delete element sample."
             << "\n4_Add element X into list."
             << "\n5_Delete element."
             << "\n6_Print list."
             << "\n7_Print reverse list."
             << "\n8_Count number of element into list."
             << "\n0_Exit."
             << "\nYou choose???";
        cin >> choose;

        switch (choose)
        {
        case 0:
            break;
        case 1:
            Sort(L);
            break;
        case 2:
            cout << "\nEnter value element: ";
            cin >> X;
            Insert_Into_List(X, End_List(L), L);
            break;
        case 3:
            Distinct(L);
            break;
        case 4:
            cout << "\nValue element need add into list: ";
            cin >> X;
            cout << "Position need add: ";
            cin >> viTri;
            Insert_List(X, viTri, L);
            break;
        case 5:
            cout << "\nValue need delete: ";
            cin >> X;
            P = Locate(X, L);
            Delete_List(P, L);
            break;
        case 6:
            Print_List(L);
            cout << "\n";
            system("pause");
            break;
        case 7:
            Print_Rev_List(L);
            cout << "\n";
            system("pause");
            break;
        case 8:
            cout<<"\nNumber of element: "\
                << Element_Counter(L) << "\n";
            cout << "\n";
            system("pause");
            break;
        default:
            cout << "\nYou enter error!! Please enter again."
                 << "\n";
            system("pause");
        }
    } while (choose != 0);
}
