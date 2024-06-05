void themHoaDon() {
    if (soLuongHoaDon >= MAX_BILLS) {
        printf("Khong the them hoa don moi. Danh sach da day.\n");
        return;
    }
    HoaDon hd;
    printf("Nhap ma hoa don: ");
    scanf("%d", &hd.ma);
    printf("Nhap ma khach hang: ");
    scanf("%d", &hd.maKhachHang);
    printf("Nhap ma san pham: ");
    scanf("%d", &hd.maSanPham);
    printf("Nhap so luong san pham: ");
    scanf("%d", &hd.soLuong);
    hd.tongGia = dsSanPham[hd.maSanPham].gia * hd.soLuong;
    printf("Nhap giam gia: ");
    scanf("%f", &hd.giamGia);
    hd.giaCuoi = hd.tongGia - hd.giamGia;
    dsHoaDon[soLuongHoaDon++] = hd;
    printf("Them hoa don thanh cong!\n");
}

void suaHoaDon() {
    int ma, i;
    printf("Nhap ma hoa don can sua: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongHoaDon; i++) {
        if (dsHoaDon[i].ma == ma) {
            printf("Nhap ma khach hang moi: ");
            scanf("%d", &dsHoaDon[i].maKhachHang);
            printf("Nhap ma san pham moi: ");
            scanf("%d", &dsHoaDon[i].maSanPham);
            printf("Nhap so luong san pham moi: ");
            scanf("%d",&dsHoaDon[i].soLuong);
            dsHoaDon[i].tongGia = dsSanPham[dsHoaDon[i].maSanPham].gia * dsHoaDon[i].soLuong;
            printf("Nhap giam gia moi: ");
            scanf("%f", &dsHoaDon[i].giamGia);
            dsHoaDon[i].giaCuoi = dsHoaDon[i].tongGia - dsHoaDon[i].giamGia;
            printf("Sua thong tin hoa don thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay hoa don voi ma da cho.\n");
}

void xoaHoaDon() {
    int ma, i, j;
    printf("Nhap ma hoa don can xoa: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongHoaDon; i++) {
        if (dsHoaDon[i].ma == ma) {
            for (j = i; j < soLuongHoaDon - 1; j++) {
                dsHoaDon[j] = dsHoaDon[j + 1];
            }
            soLuongHoaDon--;
            printf("Xoa hoa don thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay hoa don voi ma da cho.\n");
}

void timHoaDon() {
    int ma, i;
    printf("Nhap ma hoa don can tim: ");
    scanf("%d", &ma);
    for (i = 0; i < soLuongHoaDon; i++) {
        if (dsHoaDon[i].ma == ma) {
            printf("Hoa don tim thay: Ma: %d, Ma khach hang: %d, Ma san pham: %d, So luong: %d, Tong gia: %.2f, Giam gia: %.2f, Gia cuoi: %.2f\n",
                   dsHoaDon[i].ma, dsHoaDon[i].maKhachHang, dsHoaDon[i].maSanPham, dsHoaDon[i].soLuong, dsHoaDon[i].tongGia, dsHoaDon[i].giamGia, dsHoaDon[i].giaCuoi);
            return;
        }
    }
    printf("Khong tim thay hoa don voi ma da cho.\n");
}

void tinhTongDoanhThu() {
    float tongDoanhThu = 0;
    for (int i = 0; i < soLuongHoaDon; i++) {
        tongDoanhThu += dsHoaDon[i].giaCuoi;
    }
    printf("Tong doanh thu: %.2f\n", tongDoanhThu);
}
