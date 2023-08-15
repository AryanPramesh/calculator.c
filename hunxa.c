#include <stdio.h>
#include <math.h>
#include <string.h>
char user[100];


void printMenu() {
    printf("\t\t **********WELCOME TO THE SIMPLE CALCULATOR MADE BY PRAMESH ARYAL AND RABIN POUDEL**********\n");
    printf("\t\t \t\t**********CALCULATOR MENU**********\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Power\n");
    printf("7. Square\n");
    printf("8. Cube\n");
    printf("9. 1/X\n");
    printf("10. Exponent\n");
    printf("11. Factorial\n");
    printf("12. Percentage\n");
    printf("13. Logarithm\n");
    printf("14. Remainder\n");
    printf("15. Sin(x)\n");
    printf("16. Cos(x)\n");
    printf("17. Tan(x)\n");
    printf("18. Cosec(x)\n");
    printf("19. Sec(x)\n");
    printf("20. Cot(x)\n");
    printf("21. Matrix Addition\n");
    printf("22. Matrix Multiplication\n");
}


void signup() {
    char username[20], password[20];

    printf("Enter a username (max 19 characters): ");
    scanf("%19s", username);
    printf("Enter a password (max 19 characters): ");
    scanf("%19s", password);

    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error: Cannot open the user file.\n");
        return;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);
    printf("Account created successfully!\n");
}


int login() {
    char username[20], password[20];

    printf("Enter your username: ");
    scanf("%19s", username);
    printf("Enter your password: ");
    scanf("%19s", password);

    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open the user file.\n");
        return 0;
    }

    char storedUsername[20], storedPassword[20];
    while (fscanf(file, "%19s %19s", storedUsername, storedPassword) == 2) {
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            strcpy(user, username);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0; 
}


void matrixAddition() {
 int m, n;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    float matrix1[m][n], matrix2[m][n], result[m][n];

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m; i++)
	 {
        for (int j = 0; j < n; j++) 
		{
            scanf("%f", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix2[i][j]);
        }
    }

   
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

 
    printf("Result:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", result[i][j]);
        }
        printf("\n");
    }
}




void matrixMultiplication() {
   int m1, n1, m2, n2;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &m1, &n1);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &m2, &n2);

    if (n1 != m2) {
        printf("Invalid matrix dimensions for multiplication!\n");
        return;
    }

    float matrix1[m1][n1], matrix2[m2][n2], result[m1][n2];

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%f", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%f", &matrix2[i][j]);
        }
    }

   
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    
    printf("Result:\n"); 
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%.2f\t", result[i][j]);
        }
        printf("\n");
    }

}

void saveCalculation(float x, char operation, float y, float result) {
    FILE *file = fopen("calculations.txt", "a+");
    if (file == NULL) {
        printf("Error: Cannot open the calculation history file.\n");
        return;
    }
   
    fprintf(file, " %.2f %c %.2f = %.2f\n" ,x, operation, y, result);
    fclose(file);
}

int main() {
    int choice;
    char addAnother;
    float x, y, result;

    printf("\n\n Welcome to the Calculator Program!\n");

    int loggedIn = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Sign-up\n");
        printf("2. Log-in\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                loggedIn = login();
                if (!loggedIn) {
                    printf("Login failed. Please try again.\n");
                } else {
                    printf("Login successful.\n");
                }
                break;
            case 3:
                printf("Program terminated.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (!loggedIn);

    do {
        printMenu();
        printf("Enter your choice (1-22): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = x + y;
                break;
            case 2:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = x - y;
                break;
            case 3:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = x * y;
                break;
            case 4:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = x / y;
                break;
            case 5:
                printf("Enter X: ");
                scanf("%f", &x);
                result = sqrt(x);
                break;
            case 6:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = pow(x, y);
                break;
            case 7:
                printf("Enter X: ");
                scanf("%f", &x);
                result = pow(x, 2);
                break;
            case 8:
                printf("Enter X: ");
                scanf("%f", &x);
                result = pow(x, 3);
                break;
            case 9:
                printf("Enter X: ");
                scanf("%f", &x);
                result = 1 / x;
                break;
            case 10:
                printf("Enter X: ");
                scanf("%f", &x);
                result = exp(x);
                break;
            case 11:
                printf("Enter X: ");
                scanf("%f", &x);
                result = 1;
                for (int i = 1; i <= x; i++) {
                    result *= i;
                }
                break;
            case 12:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = (x * y) / 100;
                break;
            case 13:
                printf("Enter X: ");
                scanf("%f", &x);
                result = log(x);
                break;
            case 14:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = fmod(x, y);
                break;
            case 15:
                printf("Enter X: ");
                scanf("%f", &x);
                result = sin(x * 3.14159 / 180.0);
                break;
            case 16:
                printf("Enter X: ");
                scanf("%f", &x);
                result = cos(x * 3.14159 / 180.0);
                break;
            case 17:
                printf("Enter X: ");
                scanf("%f", &x);
                result = tan(x * 3.14159 / 180.0);
                break;
            case 18:
                printf("Enter X: ");
                scanf("%f", &x);
                result = 1 / sin(x * 3.14159 / 180.0);
                break;
            case 19:
                printf("Enter X: ");
                scanf("%f", &x);
                result = 1 / cos(x * 3.14159 / 180.0);
                break;
            case 20:
                printf("Enter X: ");
                scanf("%f", &x);
                result = 1 / tan(x * 3.14159 / 180.0);
                break;
            case 21:
                matrixAddition();
                break;
            case 22: 
                matrixMultiplication();
                break;
            default:
                printf("Invalid choice!\n");
                return 1;
        }

        printf("Result: %.2f\n\n", result);
        saveCalculation(x, (char)choice, y, result);

        printf("Do you want to do more calculations? (y/n): ");
        scanf(" %c", &addAnother);

    } while (addAnother == 'y' || addAnother == 'Y');
    printf("\t\t ***********THANK YOU FOR USING OURCALCULATOR ***********\n");

    printf(" \t\t\t\t***********PROGRAM TERMINATED ***********\n");
    return 0;
}