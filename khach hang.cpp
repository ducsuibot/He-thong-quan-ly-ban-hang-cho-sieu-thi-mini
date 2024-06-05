void luuKhachHangVaoTep() {
    FILE *f = fopen("khachhang.txt", "w");
    if (f == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fprintf(f, "%d\n", soLuongKhachHang);
    for (int i = 0; i < soLuongKhachHang; i++) {
        fprintf(f, "%d\n%s\n%s\n%s\n", dsKhachHang[i].ma, dsKhachHang[i].ten, dsKhachHang[i].diaChi, dsKhachHang[i].soDienThoai);
    }
    fclose(f);
    printf("Da luu danh sach khach hang vao tep khachhang.txt.\n");
}

void taiKhachHangTuTep() {
    FILE *f = fopen("khachhang.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }
    fscanf(f, "%d", &soLuongKhachHang);
    for (int i = 0; i < soLuongKhachHang; i++) {
        fscanf(f, "%d", &dsKhachHang[i].ma);
        fscanf(f, "%s", dsKhachHang[i].ten);
        fscanf(f, "%s", dsKhachHang[i].diaChi);
        fscanf(f, "%s", dsKhachHang[i].soDienThoai);
    }
    fclose(f);
    printf("Da tai danh sach khach hang tu tep khachhang.txt.\n");
}

void themKhachHang() {
    if (soLuongKhachHang >= MAX_CUSTOMERS) {
        printf("Khong the them khach hang moi. Danh sach da day.\n");
        return;
    }
    KhachHang kh;
    printf("Nhap ma khach hang: ");
    scanf("%d", &kh.ma);
    printf("Nhap ten khach hang: ");
    getchar();
    gets(kh.ten);
    printf("Nhap dia chi khach hang: ");
    gets(kh.diaChi);
    printf("Nhap so dien thoai khach hang: ");
    gets(kh.soDienThoai);
    dsKhachHang[soLuongKhachHang++] = kh;
    printf("Them khach hang thanh cong!\n");
}

void suaKhachHang() {
    int ma, i;
    printf("Nhap ma khach hang can sua: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongKhachHang; i++) {
        if (dsKhachHang[i].ma == ma) {
            printf("Nhap ten khach hang moi: ");
            getchar();
            gets(dsKhachHang[i].ten);
            printf("Nhap dia chi khach hang moi: ");
            gets(dsKhachHang[i].diaChi);
            printf("Nhap so dien thoai khach hang moi: ");
            gets(dsKhachHang[i].soDienThoai);
            printf("Sua thong tin khach hang thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay khach hang voi ma da cho.\n");
}

void xoaKhachHang() {
    int ma, i, j;
    printf("Nhap ma khach hang can xoa: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongKhachHang; i++) {
        if (dsKhachHang[i].ma == ma) {
            for (j = i; j < soLuongKhachHang - 1; j++) {
                dsKhachHang[j] = dsKhachHang[j + 1];
            }
            soLuongKhachHang--;
            printf("Xoa khach hang thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay khach hang voi ma da cho.\n");
}

void timKhachHang() {
    int ma, i;
    printf("Nhap ma khach hang can tim: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongKhachHang; i++) {
        if (dsKhachHang[i].ma == ma) {
            printf("Khach hang tim thay: Ma: %d, Ten: %s, Dia chi: %s, So dien thoai: %s\n",
                   dsKhachHang[i].ma, dsKhachHang[i].ten, dsKhachHang[i].diaChi, dsKhachHang[i].soDienThoai);
            return;
        }
    }
    printf("Khong tim thay khach hang voi ma da cho.\n");
}

