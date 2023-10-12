#include "STDTYPES.h"
#include "SchoolManagement.h"
#include "string.h"

void MAIN_MENU(void)
{
    printf("\n");
    printf(" ________________________________________________________________________\n");
    printf("|                                                                        |\n");
    printf("|                  Welcome to the School Management System               |\n");
    printf("|                                                                        |\n");
    printf("|________________________________________________________________________|\n");
    printf("\n");
}

void NEW_STUDENT(Student_T **list)
{
    u32 flag = 1;
    Student_T *student1 = NULL;
    Student_T *temp = *list;
    /*create a student*/
    student1 = (Student_T *)malloc(sizeof(Student_T));
    /*check if the student is created */
    if (NULL == student1)
    {
        printf("*****the student is not created ****\n");
    }
    else
    {
        /*Ask the user to input data*/
        /*check there is not anther student has same id*/
        /*ask to enter id*/
        do
        {
            printf("please enter Student id : ");
            scanf("%d", &(student1->Data.StudentID));
            while (getchar() != '\n')
                ;
            while (temp != NULL)
            {

                if ((student1->Data.StudentID) == (temp->Data.StudentID))
                {
                    printf("There is another student with the same ID.\n");
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
                temp = temp->Link;
            }

        } while (flag == 0);
        if (flag == 1)
        {

            /*Ask to enter the name */
            printf("please enter Student name : ");
            fgets(student1->Data.StudentName, 30, stdin);
            // strcopy(string,(student1->StudentName));

            /*ask to enter birth*/
            printf("please enter Student year birth (y/m/d): ");
            scanf("%d/%d/%d", &(student1->Data.StudentBirth.year), &(student1->Data.StudentBirth.month), &(student1->Data.StudentBirth.day));
            while (getchar() != '\n')
                ;

            /*ask to enter phone*/
            printf("please enter Student phone number  : ");
            scanf("%lld", &(student1->Data.StudentPhone));

            /*Ask to enter the address */
            printf("please enter Student address : ");
            while (getchar() != '\n')
                ;
            fgets(student1->Data.StudentAddress, 50, stdin);

            /*ask to enter phone*/
            printf("please enter Student score  : ");
            scanf("%f", &(student1->Data.StudentScore));
            while (getchar() != '\n')
                ;

            /*check if the list is empty or not */
            if (NULL == *list)
            {
                student1->Link = NULL;
                *list = student1;
            }
            else
            {
                student1->Link = *list;
                *list = student1;
            }
            printf("*** Student added successfully ***\n");
        }
    }
}
void STUDENT_LIST(Student_T **list)
{
    Student_T *temp = *list;
    /*check if the list is empty*/
    if (NULL == *list)
    {
        printf("the list is empty !!\n");
    }
    else
    {
        while (NULL != temp)
        {
            printf("---------------------------------\n");
            printf("Student Name is    : %s", temp->Data.StudentName);
            printf("Student id is      : %d \n", temp->Data.StudentID);
            printf("Student birth is   : %d / %d / %d \n", temp->Data.StudentBirth.year, temp->Data.StudentBirth.month, temp->Data.StudentBirth.day);
            printf("Student phone is   : %lld \n", temp->Data.StudentPhone);
            printf("Student address is : %s", temp->Data.StudentAddress);
            printf("Student score is   : %0.02f \n", temp->Data.StudentScore);
            printf("---------------------------------\n");
            temp = temp->Link;
        }
        printf("Operation completed successfully.\n");
    }
}

void STUDENT_EDIT(Student_T **list)
{
    Student_T *temp = *list;
    u32 id = 0, op = 0;

    // Check if the list is empty
    if (NULL == temp)
    {
        printf("The student list is empty!\n");
    }
    else
    {
        // Ask the user to input the student id
        printf("Enter the student ID: ");
        scanf("%d", &id);

        while (NULL != temp)
        {
            if (id == temp->Data.StudentID)
            {
                break;
            }
            temp = temp->Link;
        }

        // Check if the student ID is found
        if (NULL == temp)
        {
            printf("Student ID not found.\n");
        }
        else
        {
            printf("Editing student with ID %d:\n", temp->Data.StudentID);
            do
            {
                printf("*********************************\n");
                printf("*        Options:               *\n");
                printf("* ------------------------------*\n");
                printf("* 1 -> Edit student name        *\n");
                printf("* 2 -> Edit student ID          *\n");
                printf("* 3 -> Edit student birth       *\n");
                printf("* 4 -> Edit student phone       *\n");
                printf("* 5 -> Edit student address     *\n");
                printf("* 6 -> Edit student score       *\n");
                printf("* 0 -> Exit                     *\n");
                printf("*********************************\n");
                printf(">> ");
                scanf("%d", &op);
                while (getchar() != '\n')
                    ;

                switch (op)
                {
                case 1:
                    printf("Enter new student name: ");
                    fgets(temp->Data.StudentName, sizeof(temp->Data.StudentName), stdin);
                    printf("Name updated successfully.\n");
                    break;

                case 2:
                    printf("Enter new student ID: ");
                    scanf("%d", &(temp->Data.StudentID));
                    printf("ID updated successfully.\n");
                    break;

                case 3:
                    printf("please enter Student year birth (y/m/d): ");
                    scanf("%d/%d/%d", &(temp->Data.StudentBirth.year), &(temp->Data.StudentBirth.month), &(temp->Data.StudentBirth.day));
                    printf("Birthdate updated successfully.\n");
                    break;

                case 4:
                    printf("Enter new student phone: ");
                    scanf("%lld", &(temp->Data.StudentPhone));
                    printf("Phone number updated successfully.\n");
                    break;

                case 5:
                    printf("Enter new student address: ");
                    fgets(temp->Data.StudentAddress, sizeof(temp->Data.StudentAddress), stdin);
                    printf("Address updated successfully.\n");
                    break;

                case 6:
                    printf("Enter new student score: ");
                    scanf("%f", &(temp->Data.StudentScore));
                    printf("Score updated successfully.\n");
                    break;

                case 0:
                    printf("Editing completed.\n");
                    break;

                default:
                    printf("Invalid operation. Please choose a valid option.\n");
                    break;
                }
            } while (op != 0);
        }
    }
}
void STUDENT_SCORE(Student_T **list)
{
    Student_T *temp = *list;
    u32 id = 0, op = 0;
    /*chek if the list is empty*/
    if (NULL == temp)
    {
        printf("the list is empty !!\n");
    }
    else
    {
        do
        {

            /*ask the user to input the student id*/
            printf("Enter student id : ");
            scanf("%d", &id);
            while (NULL != temp)
            {
                if (id == (temp->Data.StudentID))
                {
                    break;
                }
                temp = temp->Link;
            }
            /*check if student id is founded*/
            if (NULL == temp)
            {
                printf("this Student id is not founded \n");
            }
            else
            {
                /*ask the user to updata the score*/
                printf("enter new score \n");
                printf(">> ");
                scanf("%f", &(temp->Data.StudentScore));
                printf("*** Done ***\n");
            }

            /*ask the user to conitiue or exist  */
            printf(" **********************\n");
            printf("*to continue enter : 1 *\n");
            printf("*to exist enter    : 0 *\n");
            printf(" **********************\n");
            printf(">> ");
            scanf("%d", &op);
            /*return temp to the head*/
            temp = *list;

        } while (op != 0);
    }
}

void RANK_STUDENT(Student_T **list)
{
    Student_T *temp1 = *list;
    Student_T *temp2 = *list;
    u32 sort = 0;
    s32 sp = 0;
    /*check if the list is empty*/
    if (NULL == *list)
    {
        printf("the list is empty !!\n");
    }
    else
    {
        printf("please enter type of sorting :  \n");
        printf("\n");
        printf("-----------------------------------------------\n");
        printf("| 1 -> for sorting according data science score|\n");
        printf("| 2 -> for sorting according alphabetically    |\n");
        printf("-----------------------------------------------\n");
        printf(">>");
        scanf("%d", &sort);
        if (sort == 1)
        {

            while (NULL != temp1)
            {
                temp2 = *list;
                while (NULL != temp2)
                {

                    // printf("%f\t%f\n",temp1->StudentScore,temp2->StudentScore);
                    if ((temp1->Data.StudentScore) < (temp2->Data.StudentScore))
                    {
                        // SwapTwoNode(list, temp2->Data.StudentID, temp1->Data.StudentID);
                        Data_T temp = temp1->Data;
                        temp1->Data = temp2->Data;
                        temp2->Data = temp;
                    }
                    temp2 = temp2->Link;
                }

                temp1 = temp1->Link;
            }
            printf("\n sorted successfully \n");
        }
        else if (sort == 2)
        {
            while (NULL != temp1)
            {
                temp2 = *list;
                while (NULL != temp2)
                {
                    sp = my_memcmp((temp1->Data.StudentName), (temp2->Data.StudentName), sizeof((temp1->Data.StudentName)));
                    if (sp < 0)
                    {
                        Data_T temp = temp1->Data;
                        temp1->Data = temp2->Data;
                        temp2->Data = temp;
                    }
                    temp2 = temp2->Link;
                }

                temp1 = temp1->Link;
            }
            printf("\n sorted successfully \n");
        }
        else
        {
            printf("Invalid number !!\n");
        }
    }
}

void DELETE_STUDENT(Student_T **list)
{
    u32 id = 0;
    u32 flag = 0;
    Student_T *temp = *list;
    Student_T *prev = NULL; // Pointer to the previous node

    /* Check if the list is empty */
    if (temp == NULL)
    {
        printf("List is empty !!\n");
        return;
    }

    /* Ask the user to input student id */
    printf("Enter student id to delete: ");
    scanf("%d", &id);

    while (temp != NULL)
    {
        if (id == temp->Data.StudentID)
        {
            flag = 1;
            break;
        }
        prev = temp;
        temp = temp->Link;
    }

    if (flag == 1)
    {
        if (prev == NULL)
        {
            /* If the first node is to be deleted */
            *list = temp->Link;
        }
        else
        {
            prev->Link = temp->Link;
        }
        free(temp); // Free the memory for the deleted node
        printf("Student with ID %d deleted successfully.\n", id);
    }
    else
    {
        printf("Student with ID %d not found in the list.\n", id);
    }
}
