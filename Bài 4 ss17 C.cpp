#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int *Mang = 0;  
    int n = 0;         
    int chon;

    do {
        printf("\n---MENU---\n");
        printf("1. Nhap vao so phan tu va tinh tong phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: {
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("So phan tu khong hop le!\n");
                    break;
                }
                Mang = (int *)malloc(n * sizeof(int));
                printf("Nhap cac phan tu:\n");
                int tong = 0;
                for (int i = 0; i < n; i++) {
                    printf("Ph?n t? [%d]: ", i + 1);
                    scanf("%d", &Mang[i]);
                    tong += Mang[i];
                }
                printf("Tong cac phan tu: %d\n", tong);
                break;
            }

            case 2: {
                if (n > 0) {
                    printf("Cac phan tu la so chan: ");
                    for (int i = 0; i < n; i++) {
                        if (Mang[i] % 2 == 0) {
                            printf("%d ", Mang[i]);
                        }
                    }
                    printf("\n");
                }
                break;
            }

            case 3: {
                if (n > 0) {
                    printf("Cac phan tu la so nguyen to: ");
                    for (int i = 0; i < n; i++) {
                        bool songuyento = true;
                        if (Mang[i] <= 1) {
                            songuyento = false;
                        } else {
                            for (int j = 2; j * j <= Mang[i]; j++) {
                                if (Mang[i] % j == 0) {
                                    songuyento = false;
                                    break;
                                }
                            }
                        }
                        if (songuyento) {
                            printf("%d ", Mang[i]);
                        }
                    }
                    printf("\n");
                }
                break;
            }

            case 4: {
                if (n > 0) {
                    printf("Mang dao nguoc: ");
                    for (int i = n - 1; i >= 0; i--) {
                        printf("%d ", Mang[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 5: {
                if (n > 0) {
                    char luachon;
                    printf("a. Tang dan\n");
                    printf("b. Giam dan\n");
                    printf("Moi lua chon: ");
                    scanf(" %c", &luachon); 

                    if (luachon == 'a') {
                        for (int i = 0; i < n - 1; i++) {
                            for (int j = i + 1; j < n; j++) {
                                if (Mang[i] > Mang[j]) {
                                    int temp = Mang[i];
                                    Mang[i] = Mang[j];
                                    Mang[j] = temp;
                                }
                            }
                        }
                        printf("Mang sau khi sap xep tang dan: ");
                        for (int i = 0; i < n; i++) {
                            printf("%d ", Mang[i]);
                        }
                    } else if (luachon == 'b') {
                        for (int i = 0; i < n - 1; i++) {
                            for (int j = i + 1; j < n; j++) {
                                if (Mang[i] < Mang[j]) {
                                    int temp = Mang[i];
                                    Mang[i] = Mang[j];
                                    Mang[j] = temp;
                                }
                            }
                        }
                        printf("Mang sau khi sap xep giam dan: ");
                        for (int i = 0; i < n; i++) {
                            printf("%d ", Mang[i]);
                        }
                    } else {
                        printf("Lua chon khong hop le!\n");
                    }
                    printf("\n");
                }
                break;
            }

            case 6: {
                if (n > 0) {
                    int x, found = 0;
                    printf("Nhap phan tu can tim: ");
                    scanf("%d", &x);
                    for (int i = 0; i < n; i++) {
                        if (Mang[i] == x) {
                            printf("Phan tu %d xuat hien toi vi tri %d\n", x, i + 1);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("Phan tu %d khong co trong mang.\n", x);
                    }
                }
                break;
            }

            case 7:
                free(Mang); 
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 7);

    return 0;
}

