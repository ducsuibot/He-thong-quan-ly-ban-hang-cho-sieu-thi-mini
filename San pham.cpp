void themSanPham() {
    if (soLuongSanPham >= MAX_PRODUCTS) {
        printf("Khong the them san pham moi. Danh sach da day.\n");
        return;
    }
    SanPham sp;
    printf("Nhap ma san pham: ");
    scanf("%d", &sp.ma);
    printf("Nhap ten san pham: ");
    getchar();
    gets(sp.ten);
    printf("Nhap gia san pham: ");
    scanf("%f", &sp.gia);
    printf("Nhap so luong san pham: ");
    scanf("%d", &sp.soLuong);
    dsSanPham[soLuongSanPham++] = sp;
    printf("Them san pham thanh cong!\n");
}

void suaSanPham() {
    int ma, i;
    printf("Nhap ma san pham can sua: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].ma == ma) {
            printf("Nhap ten san pham moi: ");
            getchar();
            gets(dsSanPham[i].ten);
            printf("Nhap gia san pham moi: ");
            scanf("%f", &dsSanPham[i].gia);
            printf("Nhap so luong san pham moi: ");
            scanf("%d", &dsSanPham[i].soLuong);
            printf("Sua thong tin san pham thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay san pham voi ma da cho.\n");
}

void xoaSanPham() {
    int ma, i, j;
    printf("Nhap ma san pham can xoa: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].ma == ma) {
            for (j = i; j < soLuongSanPham - 1; j++) {
                dsSanPham[j] = dsSanPham[j + 1];
            }
            soLuongSanPham--;
            printf("Xoa san pham thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay san pham voi ma da cho.\n");
}

void timSanPham() {
    int ma, i;
    printf("Nhap ma san pham can tim: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].ma == ma) {
            printf("San pham tim thay: Ma: %d, Ten: %s, Gia: %.2f, So luong: %d\n",
                   dsSanPham[i].ma, dsSanPham[i].ten, dsSanPham[i].gia, dsSanPham[i].soLuong);
            return;
        }
    }
    printf("Khong tim thay san pham voi ma da cho.\n");
}

void timSanPhamTheoTen() {
    char ten[50];
    printf("Nhap ten san pham can tim: ");
    getchar();
    gets(ten);
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(dsSanPham[i].ten, ten) == 0) {
            printf("San pham tim thay: Ma: %d, Ten: %s, Gia: %.2f, So luong: %d\n",
                   dsSanPham[i].ma, dsSanPham[i].ten, dsSanPham[i].gia, dsSanPham[i].soLuong);
            return;
        }
    }
    printf("Khong tim thay san pham voi ten da cho.\n");
}

void sapXepSanPhamTheoGia() {
    int i, j;
    for (i = 0; i < soLuongSanPham - 1; i++) {
        for (j = i + 1; j < soLuongSanPham; j++) {
            if (dsSanPham[i].gia > dsSanPham[j].gia) {
                SanPham temp = dsSanPham[i];
                dsSanPham[i] = dsSanPham[j];
                dsSanPham[j] = temp;
            }
        }
    }
    printf("Da sap xep san pham theo gia tang dan.\n");
}

void sapXepSanPhamTheoTen() {
    int i, j;
    for (i = 0; i < soLuongSanPham - 1; i++) {
        for (j = i + 1; j < soLuongSanPham; j++) {
            if (strcmp(dsSanPham[i].ten, dsSanPham[j].ten) > 0) {
                SanPham temp = dsSanPham[i];
                dsSanPham[i] = dsSanPham[j];
                dsSanPham[j] = temp;
            }
        }
    }
    printf("Da sap xep san pham theo ten tang dan.\n");
}

void luuSanPhamVaoTep() {
    FILE *f = fopen("sanpham.txt", "w");
    if (f == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fprintf(f, "%d\n", soLuongSanPham);
    for (int i = 0; i < soLuongSanPham; i++) {
        fprintf(f, "%d\n%s\n%f\n%d\n", dsSanPham[i].ma, dsSanPham[i].ten, dsSanPham[i].gia, dsSanPham[i].soLuong);
    }
    fclose(f);
    printf("Da luu danh sach san pham vao tep sanpham.txt.\n");
}

void taiSanPhamTuTep() {
    FILE *f = fopen("sanpham.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }
    fscanf(f, "%d", &soLuongSanPham);
    for (int i = 0; i < soLuongSanPham; i++) {
        fscanf(f, "%d", &dsSanPham[i].ma);
        fscanf(f, "%s", dsSanPham[i].ten);
        fscanf(f, "%f", &dsSanPham[i].gia);
        fscanf(f, "%d", &dsSanPham[i].soLuong);
    }
    fclose(f);
    printf("Da tai danh sach san pham tu tep sanpham.txt.\n");
}

