void luuNhaCungCapVaoTep() {
    FILE *f = fopen("nhacungcap.txt", "w");
    if (f == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fprintf(f, "%d\n", soLuongNhaCungCap);
    for (int i = 0; i < soLuongNhaCungCap; i++) {
        fprintf(f, "%d\n%s\n%s\n%s\n", dsNhaCungCap[i].ma, dsNhaCungCap[i].ten, dsNhaCungCap[i].diaChi, dsNhaCungCap[i].soDienThoai);
    }
    fclose(f);
    printf("Da luu danh sach nha cung cap vao tep nhacungcap.txt.\n");
}

void taiNhaCungCapTuTep() {
    FILE *f = fopen("nhacungcap.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }
    fscanf(f, "%d", &soLuongNhaCungCap);
    for (int i = 0; i < soLuongNhaCungCap; i++) {
        fscanf(f, "%d", &dsNhaCungCap[i].ma);
        fscanf(f, "%s", dsNhaCungCap[i].ten);
        fscanf(f, "%s", dsNhaCungCap[i].diaChi);
        fscanf(f, "%s", dsNhaCungCap[i].soDienThoai);
    }
    fclose(f);
    printf("Da tai danh sach nha cung cap tu tep nhacungcap.txt.\n");
}

void themNhaCungCap() {
    if (soLuongNhaCungCap >= MAX_SUPPLIERS) {
        printf("Khong the them nha cung cap moi. Danh sach da day.\n");
        return;
    }
    NhaCungCap ncc;
    printf("Nhap ma nha cung cap: ");
    scanf("%d", &ncc.ma);
    printf("Nhap ten nha cung cap: ");
    getchar();
    gets(ncc.ten);
    printf("Nhap dia chi nha cung cap: ");
    gets(ncc.diaChi);
    printf("Nhap so dien thoai nha cung cap: ");
    gets(ncc.soDienThoai);
    dsNhaCungCap[soLuongNhaCungCap++] = ncc;
    printf("Them nha cung cap thanh cong!\n");
}

void suaNhaCungCap() {
    int ma, i;
    printf("Nhap ma nha cung cap can sua: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhaCungCap; i++) {
        if (dsNhaCungCap[i].ma == ma) {
            printf("Nhap ten nha cung cap moi: ");
            getchar();
            gets(dsNhaCungCap[i].ten);
            printf("Nhap dia chi nha cung cap moi: ");
            gets(dsNhaCungCap[i].diaChi);
            printf("Nhap so dien thoai nha cung cap moi: ");
            gets(dsNhaCungCap[i].soDienThoai);
            printf("Sua thong tin nha cung cap thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay nha cung cap voi ma da cho.\n");
}

void xoaNhaCungCap() {
    int ma, i, j;
    printf("Nhap ma nha cung cap can xoa: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhaCungCap; i++) {
        if (dsNhaCungCap[i].ma == ma) {
            for (j = i; j < soLuongNhaCungCap - 1; j++) {
                dsNhaCungCap[j] = dsNhaCungCap[j + 1];
            }
            soLuongNhaCungCap--;
            printf("Xoa nha cung cap thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay nha cung cap voi ma da cho.\n");
}

void timNhaCungCap() {
    int ma, i;
    printf("Nhap ma nha cung cap can tim: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhaCungCap; i++) {
        if (dsNhaCungCap[i].ma == ma) {
            printf("Nha cung cap tim thay: Ma: %d, Ten: %s, Dia chi: %s, So dien thoai: %s\n",
                   dsNhaCungCap[i].ma, dsNhaCungCap[i].ten, dsNhaCungCap[i].diaChi, dsNhaCungCap[i].soDienThoai);
            return;
        }
    }
    printf("Khong tim thay nha cung cap voi ma da cho.\n");
}

