#include "xuly.hpp"

KhachHang* khoiTaoNodeKhachHang();
void nhapMotKhachHang(DanhSachKhachHang& dskh);
void themMotKhachHang(tree& t, KhachHang* p);
int taoMaKhachHang(tree t);
bool kiemTraMaKhachHangTrung(tree t, int ma);

KhachHang* khoiTaoNodeKhachHang() {
    KhachHang* p = new KhachHang;
    p->pleft = NULL;
    p->pright = NULL;
    return p;
}

void nhapMotKhachHang(DanhSachKhachHang& dskh) {
    KhachHang* p = khoiTaoNodeKhachHang();
    cin.ignore();
    cout << "\n(?) Nhap tai khoan: ";
    getline(cin, p->taiKhoan);
    cout << "\n(?) Nhap mat khau: ";
    getline(cin, p->matKhau);
    do {
        cout << "\n(?) Nhap so dien thoai (10 so): ";
        getline(cin, p->soDienThoai);
        if (p->soDienThoai.length() <= 0 || p->soDienThoai.length() > 10 || p->soDienThoai.length() != 10)
            cout << "\n\t(!) So dien thoai khong hop le - Nhap lai\n";
    } while (p->soDienThoai.length() <= 0 || p->soDienThoai.length() > 10 || p->soDienThoai.length() != 10);
    chuanHoaTenTaiKhoan(p->taiKhoan);
    p->maKH = taoMaKhachHang(dskh.TREE);
    themMotKhachHang(dskh.TREE, p);
    dskh.soLuong++;
}

void themMotKhachHang(tree& t, KhachHang* p) {
    if (t == NULL)
        t = p;
    else {
        if (p->maKH > t->maKH)
            themMotKhachHang(t->pright, p);
        else if (p->maKH < t->maKH)
            themMotKhachHang(t->pleft, p);
    }
}

int taoMaKhachHang(tree t) {
    int ma;  // ngẫu nhiên từ 100 đến 999
    do {
        ma = rand() % (999 - 100 + 1) + 100;
    } while (kiemTraMaKhachHangTrung(t, ma) == true);
    return ma;
}

bool kiemTraMaKhachHangTrung(tree t, int ma) {
    if (t == NULL)
        return 0;
    else {
        if (t->maKH == ma)
            return 1;
        else if (t->maKH < ma)
            kiemTraMaKhachHangTrung(t->pright, ma);
        else
            kiemTraMaKhachHangTrung(t->pleft, ma);
    }
}