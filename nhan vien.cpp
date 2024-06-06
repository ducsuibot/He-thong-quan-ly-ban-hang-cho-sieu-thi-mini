void themNhanVien() {
    if (soLuongNhanVien >= MAX_EMPLOYEES) {
        printf("Khong the them nhan vien moi. Danh sach da day.\n");
        return;
    }
    NhanVien nv;
    printf("Nhap ma nhan vien: ");
    scanf("%d", &nv.ma);
    printf("Nhap ten nhan vien: ");
    getchar();
    gets(nv.ten);
    printf("Nhap luong nhan vien: ");
    scanf("%f", &nv.luong);
    printf("Nhap chuc vu nhan vien: ");
    getchar();
    gets(nv.chucVu);
    printf("Nhap so dien thoai nhan vien: ");
    gets(nv.soDienThoai);
    dsNhanVien[soLuongNhanVien++] = nv;
    printf("Them nhan vien thanh cong!\n");
}

void suaNhanVien() {
    int ma, i;
    printf("Nhap ma nhan vien can sua: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhanVien; i++) {
        if (dsNhanVien[i].ma == ma) {
            printf("Nhap ten nhan vien moi: ");
            getchar();
            gets(dsNhanVien[i].ten);
            printf("Nhap luong nhan vien moi: ");
            scanf("%f", &dsNhanVien[i].luong);
            printf("Nhap chuc vu nhan vien moi: ");
            getchar();
            gets(dsNhanVien[i].chucVu);
            printf("Nhap so dien thoai nhan vien moi: ");
            gets(dsNhanVien[i].soDienThoai);
            printf("Sua thong tin nhan vien thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay nhan vien voi ma da cho.\n");
}

void xoaNhanVien() {
    int ma, i, j;
    printf("Nhap ma nhan vien can xoa: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhanVien; i++) {
        if (dsNhanVien[i].ma == ma) {
            for (j = i; j < soLuongNhanVien - 1; j++) {
                dsNhanVien[j] = dsNhanVien[j + 1];
            }
            soLuongNhanVien--;
            printf("Xoa nhan vien thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay nhan vien voi ma da cho.\n");
}

void timNhanVien() {
    int ma, i;
    printf("Nhap ma nhan vien can tim: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongNhanVien; i++) {
        if (dsNhanVien[i].ma == ma) {
            printf("Nhan vien tim thay: Ma: %d, Ten: %s, Luong: %.2f, Chuc vu: %s, So dien thoai: %s\n",
                   dsNhanVien[i].ma, dsNhanVien[i].ten, dsNhanVien[i].luong, dsNhanVien[i].chucVu, dsNhanVien[i].soDienThoai);
            return;
        }
    }
    printf("Khong tim thay nhan vien voi ma da cho.\n");
}

void luuNhanVienVaoTep() {
    FILE *f = fopen("nhanvien.txt", "w");
    if (f == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fprintf(f, "%d\n", soLuongNhanVien);
    for (int i = 0; i < soLuongNhanVien; i++) {
        fprintf(f, "%d\n%s\n%f\n%s\n%s\n", dsNhanVien[i].ma, dsNhanVien[i].ten, dsNhanVien[i].luong, dsNhanVien[i].chucVu, dsNhanVien[i].soDienThoai);
    }
    fclose(f);
    printf("Da luu danh sach nhan vien vao tep nhanvien.txt.\n");
}

void taiNhanVienTuTep() {
    FILE *f = fopen("nhanvien.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }
    fscanf(f, "%d", &soLuongNhanVien);
    for (int i = 0; i < soLuongNhanVien; i++) {
        fscanf(f, "%d", &dsNhanVien[i].ma);
        fscanf(f, "%s", dsNhanVien[i].ten);
        fscanf(f, "%f", &dsNhanVien[i].luong);
        fscanf(f, "%s", dsNhanVien[i].chucVu);
        fscanf(f, "%s", dsNhanVien[i].soDienThoai);
    }
    fclose(f);
    printf("Da tai danh sach nhan vien tu tep nhanvien.txt.\n");
} 

