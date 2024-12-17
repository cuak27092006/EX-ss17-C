#include <stdio.h>
#include <stdlib.h>

int timphantulonnhat(int n, int *Mang);
int tinhtongcacphantu(int n, int *Mang);
void incacphantutrongmang(int n, int *Mang);
void khaibaomang(int *n, int **Mang);

int main() {
    int *Mang = NULL, n = 0, chon;

    do {
        printf("\n---MENU---\n");
        printf("1. Nhap vao so phan tu va cac phan tu cua mang\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                khaibaomang(&n, &Mang);
                break;

            case 2:
                incacphantutrongmang(n, Mang);
                break;

            case 3:
                printf("Do dai cua mang la: %d\n", n);
                break;

            case 4:
                printf("Tong cac phan tu trong mang la: %d\n", tinhtongcacphantu(n, Mang));
                break;

            case 5:
                printf("Phan tu lon nhat trong mang la: %d\n", timphantulonnhat(n, Mang));
                break;

            case 6:
                printf("Thoat chuong trinh.\n");
                free(Mang); 
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 6);

    return 0;
}

int timphantulonnhat(int n, int *Mang) {
    int lonnhat = Mang[0];
    for (int i = 1; i < n; i++) {
        if (*(Mang + i) > lonnhat) {
            lonnhat = *(Mang + i);
        }
    }
    return lonnhat;
}

int tinhtongcacphantu(int n, int *Mang) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += *(Mang + i);
    }
    return tong;
}

void incacphantutrongmang(int n, int *Mang) {
    printf("Cac phan tu trong mang la:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: %d\n", i + 1, *(Mang + i));
    }
}

void khaibaomang(int *n, int **Mang) {
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", n);
    
    *Mang = (int *)malloc(*n * sizeof(int)); 
    if (*Mang == NULL) {
        printf("Khong du bo nho de cap phat!\n");
        exit(1);
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", (*Mang + i));
    }
}

