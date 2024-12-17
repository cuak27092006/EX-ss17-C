#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char *Mang = NULL;  
    int chon;

    do {
        printf("\n---MENU---\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);
        getchar();  

        switch (chon) {
            case 1: {
                char buffer[100];
                printf("Nhap chuoi ki tu: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; 

                Mang = (char *)malloc(strlen(buffer) + 1);
                if (Mang == NULL) {
                    printf("Cap phat bo nho khong thanh cong!\n");
                    break;
                }
                strcpy(Mang, buffer);
                break;
            }

            case 2: {
                if (Mang) {
                    int nguoc = strlen(Mang);
                    printf("Chuoi dao nguoc: ");
                    for (int i = nguoc - 1; i >= 0; i--) {
                        printf("%c", Mang[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 3: {
                if (Mang) {
                    int Soluong = 0, inra = 0;
                    for (int i = 0; Mang[i] != '\0'; i++) {
                        if (isspace(Mang[i])) {
                            inra = 0;
                        } else if (!inra) {
                            inra = 1;
                            Soluong++;
                        }
                    }
                    printf("So luong tu trong chuoi: %d\n", Soluong);
                }
                break;
            }

            case 4: {
                if (Mang) {
                    char buffer[100];
                    printf("Nhap chuoi khac: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    buffer[strcspn(buffer, "\n")] = '\0'; 

                    if (strcmp(Mang, buffer) == 0) {
                        printf("Hai chuoi giong nhau.\n");
                    } else {
                        printf("Hai chuoi khac nhau.\n");
                    }
                }
                break;
            }

            case 5: {
                if (Mang) {
                    printf("Chuoi in hoa: ");
                    for (int i = 0; Mang[i] != '\0'; i++) {
                        printf("%c", toupper(Mang[i]));
                    }
                    printf("\n");
                }
                break;
            }

            case 6: {
                if (Mang) {
                    char buffer[100];
                    printf("Nhap chuoi khac them: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    buffer[strcspn(buffer, "\n")] = '\0'; 

                    Mang = (char *)realloc(Mang, strlen(Mang) + strlen(buffer) + 1);
                    if (Mang == NULL) {
                        printf("Cap phat bo nho khong thanh cong!\n");
                        break;
                    }
                    strcat(Mang, buffer);
                    printf("Chuoi sau khi them: %s\n", Mang);
                }
                break;
            }

            case 7:
                printf("Thoat chuong trinh.\n");
                if (Mang) free(Mang);  
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 7);

    return 0;
}

