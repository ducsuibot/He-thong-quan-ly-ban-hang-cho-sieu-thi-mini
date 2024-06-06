#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 100
#define MAX_SUPPLIERS 100
#define MAX_BILLS 100 
#define MAX_EMPLOYEES 100 
typedef struct {
    int ma;
    char ten[50];
    float luong;
    char chucVu[50];
    char soDienThoai[15];
} NhanVien; 



typedef struct {
    int ma;
    char ten[50];
    float gia;
    int soLuong;
} SanPham;

typedef struct {
    int ma;
    char ten[50];
    char diaChi[100];
    char soDienThoai[15];
} KhachHang;

typedef struct {
    int ma;
    char ten[50];
    char diaChi[100];
    char soDienThoai[15];
} NhaCungCap;

typedef struct {
    int ma;
    int maKhachHang;
    int maSanPham;
    int soLuong;
    float tongGia;
    float giamGia;
    float giaCuoi;
} HoaDon;

SanPham dsSanPham[MAX_PRODUCTS];
int soLuongSanPham = 0;

KhachHang dsKhachHang[MAX_CUSTOMERS];
int soLuongKhachHang = 0;

NhaCungCap dsNhaCungCap[MAX_SUPPLIERS];
int soLuongNhaCungCap = 0;

HoaDon dsHoaDon[MAX_BILLS];
int soLuongHoaDon = 0; 
NhanVien dsNhanVien[MAX_EMPLOYEES];
int soLuongNhanVien = 0; 

void themSanPham();
void suaSanPham();
void xoaSanPham();
void timSanPham();
void timSanPhamTheoTen();
void sapXepSanPhamTheoGia();
void sapXepSanPhamTheoTen();
void luuSanPhamVaoTep();
void taiSanPhamTuTep(); 

void luuKhachHangVaoTep();
void taiKhachHangTuTep();
void themKhachHang();
void suaKhachHang();
void xoaKhachHang();
void timKhachHang();  

void themNhanVien(); 
void suaNhanVien();
void xoaNhanVien();
void timNhanVien();
void luuNhanVienVaoTep(); 
void taiNhanVienTuTep(); 

void luuNhaCungCapVaoTep();
void taiNhaCungCapTuTep();
void themNhaCungCap();
void suaNhaCungCap();
void xoaNhaCungCap();
void timNhaCungCap(); 

void themHoaDon();
void suaHoaDon();
void xoaHoaDon();
void timHoaDon();
void tinhTongDoanhThu();
void menuChinh();

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

void menuChinh() {
    int luaChon;
    do {
        printf("\n============= MENU =============\n");
        printf("1. Quan ly san pham\n");
        printf("2. Quan ly khach hang\n"); 
        printf("3. Quan ly nhan vien\n");
        printf("4. Quan ly nha cung cap\n");
        printf("5. Lap hoa don\n");
        printf("6. Tim kiem hoa don\n");
        printf("7. Tinh tong doanh thu\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                printf("\n============= QUAN LY SAN PHAM =============\n");
                printf("1. Them san pham\n");
                printf("2. Sua san pham\n");
                printf("3. Xoa san pham\n");
                printf("4. Tim san pham\n");
                printf("5. Tim san pham theo ten\n");
                printf("6. Sap xep san pham theo gia\n");
                printf("7. Sap xep san pham theo ten\n");
                printf("8. Luu danh sach san pham vao tep\n");
                printf("9. Tai danh sach san pham tu tep\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &luaChon);
                switch (luaChon) {
                    case 1:
                        themSanPham();
                        break;
                    case 2:
                        suaSanPham();
                        break;
                    case 3:
                        xoaSanPham();
                        break;
                    case 4:
                        timSanPham();
                        break;
                    case 5:
                        timSanPhamTheoTen();
                        break;
                    case 6:
                        sapXepSanPhamTheoGia();
                        break;
                    case 7:
                        sapXepSanPhamTheoTen();
                        break;
                    case 8:
                        luuSanPhamVaoTep();
                        break;
                    case 9:
                        taiSanPhamTuTep();
                        break;
                    default:
                        printf("Lua chon khong hop le!\n");
                        break;
                }
                break;
            case 2:
                printf("\n============= QUAN LY KHACH HANG =============\n");
                printf("1. Them khach hang\n");
                printf("2. Sua khach hang\n");
                printf("3. Xoa khach hang\n");
                printf("4. Tim khach hang\n");
                printf("5. Luu danh sach khach hang vao tep\n");
                printf("6. Tai danh sach khach hang tu tep\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &luaChon);
                switch (luaChon) {
                    case 1:
                        themKhachHang();
                        break;
                    case 2:
                        suaKhachHang();
                        break;
                    case 3:
                        xoaKhachHang();
                        break;
                    case 4:
                        timKhachHang();
                        break;
                    case 5:
                        luuKhachHangVaoTep();
                        break;
                    case 6:
                        taiKhachHangTuTep();
                        break;
                    default:
                        printf("Lua chon khong hop le!\n");
                        break;
                }
                break; 
            case 3: 
            	printf("\n============= QUAN LY NHAN VIEN =============\n");
        printf("1. Them nhan vien\n");
        printf("2. Sua nhan vien\n");
        printf("3. Xoa nhan vien\n");
        printf("4. Tim nhan vien\n");
        printf("5. Luu danh sach nhan vien vao tep\n");
        printf("6. Tai danh sach nhan vien tu tep\n");
        printf("0. Quay lai\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                themNhanVien();
                break;
            case 2:
                suaNhanVien();
                break;
            case 3:
                xoaNhanVien();
                break;
            case 4:
                timNhanVien();
                break;
            case 5:
                luuNhanVienVaoTep();
                break;
            case 6:
                taiNhanVienTuTep();
                break;
            case 0:
                return;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
             
            case 4:
                printf("\n============= QUAN LY NHA CUNG CAP =============\n");
                printf("1. Them nha cung cap\n");
                printf("2. Sua nha cung cap\n");
                printf("3. Xoa nha cung cap\n");
                printf("4. Tim nha cung cap\n");
                printf("5. Luu danh sach nha cung cap vao tep\n");
                printf("6. Tai danh sach nha cung cap tu tep\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &luaChon);
                switch (luaChon) {
                    case 1:
                        themNhaCungCap();
                        break;
                    case 2:
                        suaNhaCungCap();
                        break;
                    case 3:
                        xoaNhaCungCap();
                        break;
                    case 4:
                        timNhaCungCap();
                        break;
                    case 5:
                        luuNhaCungCapVaoTep();
                        break;
                    case 6:
                        taiNhaCungCapTuTep();
                        break;
                    default:
                        printf("Lua chon khong hop le!\n");
                        break;
                }
                break;
            case 5:
                printf("\n============= LAP HOA DON =============\n");
                themHoaDon();
                break;
            case 6:
                printf("\n============= TIM KIEM HOA DON =============\n");
                timHoaDon();
                break;
            case 7:
                printf("\n============= TINH TONG DOANH THU =============\n");
                tinhTongDoanhThu();
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (luaChon != 0);
}

int main() {
    menuChinh();
    return 0;
}



