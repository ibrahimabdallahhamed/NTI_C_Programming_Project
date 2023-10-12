#include "STDTYPES.h"
#include "SchoolManagement.h"
Student_T *list1 = NULL;
int main()
{
    u32 op = 1;
    MAIN_MENU();
    while (op)
    {
        printf("\n\n");
        printf(" *****************************************\n");
        printf("* Enter operation you need                *\n");
        printf("* ----------------------------------------*\n");
        printf("* enter 1 -> for Add New Student          *\n");
        printf("* enter 2 -> for Edit Student informaion  *\n");
        printf("* enter 3 -> for delet Student informaion *\n");
        printf("* enter 4 -> for print Student informaion *\n");
        printf("* enter 5 -> for sort Student informaion  *\n");
        printf("* enter 6 -> for update Students score    *\n");
        printf("* enter 0 -> for exist from program       *\n");
        printf(" *****************************************\n");
        printf(">> ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:

            NEW_STUDENT(&list1);
            break;
        case 2:

            STUDENT_EDIT(&list1);
            break;
        case 3:

            DELETE_STUDENT(&list1);
            break;
        case 4:

            STUDENT_LIST(&list1);
            break;
        case 5:

            RANK_STUDENT(&list1);
            break;

        case 6:

            STUDENT_SCORE(&list1);
            break;
        case 0:

            break;

        default:
            printf("\n Invalid operation !!\n");
            break;
        }
    }
    printf("\n   Thank You   \n");

    return 0;
}