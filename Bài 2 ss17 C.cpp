#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countAlphabets(const char *Mang);
int countDigits(const char *Mang);
int countSpecialChars(const char *Mang);

int main() {
    char Mang[100];
    int chon;

    do {
        printf("\n---MENU---\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);
        getchar();  

        switch (chon) {
            case 1: 
                inputString(Mang);
                break;

            case 2:
                printString(Mang);
                break;

            case 3:
                printf("So luong chu cai trong chuoi la: %d\n", countAlphabets(Mang));
                break;

            case 4: 
                printf("So luong chu so trong chuoi la: %d\n", countDigits(Mang));
                break;

            case 5: 
                printf("So luong ky tu dac biet trong chuoi la: %d\n", countSpecialChars(Mang));
                break;

            case 6:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (chon != 6);

    return 0;
}

void inputString(char *Mang) {
    printf("Nhap chuoi ky tu: ");
    fgets(Mang, 100, stdin);
    Mang[strcspn(Mang, "\n")] = 0; 
}

void printString(const char *Mang) {
    printf("Chuoi hien tai la: %s\n", Mang);
}

int countAlphabets(const char *Mang) {
    int count = 0;
    for (int i = 0; i < strlen(Mang); i++) {
        if (isalpha(Mang[i])) {
            count++;
        }
    }
    return count;
}

int countDigits(const char *Mang) {
    int count = 0;
    for (int i = 0; i < strlen(Mang); i++) {
        if (isdigit(Mang[i])) {
            count++;
        }
    }
    return count;
}

int countSpecialChars(const char *Mang) {
    int count = 0;
    for (int i = 0; i < strlen(Mang); i++) {
        if (!isalpha(Mang[i]) && !isdigit(Mang[i]) && !isspace(Mang[i])) {
            count++;
        }
    }
    return count;
}

