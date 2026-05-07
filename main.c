#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void loadData(int *total);
void printTitle(char title[], int padding);
void printMenu(int choice);
void deposit(int *amountDep, int *total);
void withdraw(int *amountWith, int *total);
void checkBalance(int *total);
void saveData(int *total);

int main(){

    int choice = 0;
    int  amountDep = 0;
    int amountWith = 0;
    int total = 0;
    char title[15] = "Banking System";
    int padding = (40 - strlen(title)) / 2;

    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printTitle(title, padding);
        printMenu(choice);
        scanf("%d", &choice);
        loadData(&total);


        switch (choice){
            case 1:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                deposit(&amountDep, &total);
                saveData(&total);
                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;

            case 2:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                withdraw(&amountWith, &total);
                saveData(&total);
                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;

            case 3:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                checkBalance(&total);
                saveData(&total);
                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;
                
            case 4:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                saveData(&total);
                printf("Exited successfully!");
                exit(0);
                break;

            default:
            break;
        }

    } while (choice != 4);



    return 0;
}

void loadData(int *total){
    FILE *pFile = fopen("account.dat", "rb");

    if (pFile == NULL){
        *total = 0;
        return;
    }

    fread(total, sizeof(int), 1, pFile);

    fclose(pFile);
}

void printTitle(char title[], int padding){
    printf("========================================\n");

    for (int i = 0; i < padding; i++){
        printf(" ");
    }

    printf("%s\n", title);

    printf("========================================\n");
}

void printMenu(int choice){
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. exit\n");
    printf("\n");
    printf("Enter Your Choice: ");
}

void deposit(int *amountDep, int *total){
    printf("Enter Deposit Amount: ");
    scanf("%d", amountDep);

    (*total) += *amountDep;
}

void withdraw(int *amountWith, int *total){
    printf("Enter Withdraw Amount: ");
    scanf("%d", amountWith);

    if (*amountWith > *total){
        printf("Insufficient Balance!\n");
        return;
    }

    (*total) -= *amountWith;
}

void checkBalance(int *total){
    printf("Your Current Balance: %d\n", *total);
}

void saveData(int *total){
    FILE *pFile = fopen("account.dat", "wb");

    if (pFile == NULL){
        printf("Error saving data!");
        return;
    }

    fwrite(total, sizeof(int), 1, pFile);

    fclose(pFile);
}