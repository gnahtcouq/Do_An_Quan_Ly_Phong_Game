#include <windows.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct KhachHang {
    int maKH;
    string taiKhoan;
    string matKhau;
    string soDienThoai;
    KhachHang* pleft;
    KhachHang* pright;
};
typedef struct KhachHang* tree;

struct DanhSachKhachHang {
    tree TREE = NULL;
    int soLuong = 0;
};

void xoaMotKyTu(string& s, int vitrixoa);
void chuanHoaTenTaiKhoan(string& s);
KhachHang* khoiTaoNodeKhachHang();
void nhapMotKhachHang(DanhSachKhachHang& dskh);
void themMotKhachHang(tree& t, KhachHang* p);
int taoMaKhachHang(tree t);
bool kiemTraMaKhachHangTrung(tree t, int ma);
bool kiemTraSoDienThoaiKhachHangTrung(tree t, string sdt);
void chuyenCaySangMang(tree t, KhachHang* ds[], int& nds);
void inDanhSachKhachHangTheoChieuDoc(KhachHang* ds[], int& nds);
void inDanhSachKhachHangTheoChieuNgang(KhachHang* ds[], int& nds);
void hoanViHaiKhachHang(KhachHang* a, KhachHang* b);
void sapXepDanhSachKhachHang(KhachHang* ds[], int& nds);
void giaiPhongDanhSachKhachHang(KhachHang* ds[], int& nds);
void xoaKhachHang(DanhSachKhachHang& dskh);
void xoaMotKhachHang(tree& t, int ma);
void timNodeTheMang(tree& t, KhachHang*& x);
void chinhSuaThongTinKhachHang(DanhSachKhachHang& dskh);
void chinhSuaThongTinMotKhachHang(tree t, string sdt);
void docDanhSachKhachHang(DanhSachKhachHang& dskh);

void xoaMotKyTu(string& s, int vitrixoa) {
    int length = s.length();
    for (int i = vitrixoa + 1; i < length; i++)
        s[i - 1] = s[i];
    s[length - 1] = '\0';
}

void chuanHoaTenTaiKhoan(string& s) {
    int length = s.length();
    // Chạy từ đầu đến cuối gặp 2 khoảng trắng liên tiếp thì xóa đi 1
    for (int i = 0; i < length; i++) {
        if (s[i] == ' ') {
            xoaMotKyTu(s, i);
            i--;       // Xóa xong thì i-- xuống
            length--;  // Giảm độ dài length xuống
        }
    }
    if (s[0] == ' ') {
        xoaMotKyTu(s, 0);
        length--;
    }
    if (s[length - 1] == ' ') {
        xoaMotKyTu(s, length - 1);
        length--;
    }
    for (int i = 0; i < length; i++)
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
}

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
    cout << "\n(!) Them thanh cong\n";
    system("pause");
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

bool kiemTraSoDienThoaiKhachHangTrung(tree t, string sdt) {
    if (t == NULL)
        return 0;
    else {
        if (t->soDienThoai == sdt)
            return 1;
        else if (t->soDienThoai < sdt)
            kiemTraSoDienThoaiKhachHangTrung(t->pright, sdt);
        else
            kiemTraSoDienThoaiKhachHangTrung(t->pleft, sdt);
    }
}

// Chuyển cây sang mảng
void chuyenCaySangMang(tree t, KhachHang* ds[], int& nds) {
    if (t != NULL) {
        // data
        ds[nds] = new KhachHang;
        ds[nds]->maKH = t->maKH;
        ds[nds]->taiKhoan = t->taiKhoan;
        ds[nds]->matKhau = t->matKhau;
        ds[nds]->soDienThoai = t->soDienThoai;
        nds++;
        chuyenCaySangMang(t->pleft, ds, nds);
        chuyenCaySangMang(t->pright, ds, nds);
    }
}
// Sắp xếp danh sách khách hàng
void hoanViHaiKhachHang(KhachHang* a, KhachHang* b) {
    KhachHang* tam = new KhachHang;
    tam->maKH = a->maKH;
    tam->taiKhoan = a->taiKhoan;
    tam->matKhau = a->matKhau;
    tam->soDienThoai = a->soDienThoai;
    //
    a->maKH = b->maKH;
    a->taiKhoan = b->taiKhoan;
    a->matKhau = b->matKhau;
    a->soDienThoai = b->soDienThoai;
    //
    b->maKH = tam->maKH;
    b->taiKhoan = tam->taiKhoan;
    b->matKhau = tam->matKhau;
    b->soDienThoai = tam->soDienThoai;
    delete tam;
}

void sapXepDanhSachKhachHang(KhachHang* ds[], int& nds) {
    for (int i = 0; i < nds - 1; i++)
        for (int j = i + 1; j < nds; j++)
            if (ds[i]->maKH > ds[j]->maKH)
                hoanViHaiKhachHang(ds[i], ds[j]);
}

// In danh sách khách hàng
void inDanhSachKhachHangTheoChieuDoc(KhachHang* ds[], int& nds) {
    for (int i = 0; i < nds; i++) {
        cout << "\nMa khach hang: " << ds[i]->maKH;
        cout << "\nTai khoan: " << ds[i]->taiKhoan;
        cout << "\nMat khau: " << ds[i]->matKhau;
        cout << "\nSo dien thoai: " << ds[i]->soDienThoai;
    }
}

void inDanhSachKhachHangTheoChieuNgang(KhachHang* ds[], int& nds) {
    cout << "\n";
    cout << setw(5) << left << "Ma KH"
         << "\t";
    cout << setw(30) << left << "Tai khoan"
         << "\t";
    cout << setw(30) << left << "Mat khau"
         << "\t";
    cout << setw(20) << left << "So dien thoai"
         << "\t" << endl;
    for (int i = 0; i < nds; i++) {
        cout << setw(5) << left << ds[i]->maKH
             << "\t";
        cout << setw(30) << left << ds[i]->taiKhoan
             << "\t";
        cout << setw(30) << left << ds[i]->matKhau
             << "\t";
        cout << setw(20) << left << ds[i]->soDienThoai
             << "\t" << endl;
    }
}

// Giải phóng
void giaiPhongDanhSachKhachHang(KhachHang* ds[], int& nds) {
    for (int i = 0; i < nds; i++)
        delete ds[i];
}

// Xóa khách hàng
void xoaKhachHang(DanhSachKhachHang& dskh) {
    int ma;
    cout << "\n(?) Nhap ma khach hang can xoa: ";
    cin >> ma;
    bool check = kiemTraMaKhachHangTrung(dskh.TREE, ma);
    if (check == true) {
        // Xóa
        xoaMotKhachHang(dskh.TREE, ma);
        dskh.soLuong--;
        cout << "\n(!) Xoa thanh cong\n";
    } else
        cout << "\n(!) Ma khach hang khong ton tai\n";
    system("pause");
}

void xoaMotKhachHang(tree& t, int ma) {
    if (t != NULL) {
        if (t->maKH == ma) {
            KhachHang* x = t;  // x sẽ lưu node cần giải phóng
            if (t->pleft == NULL)
                t = t->pright;
            else if (t->pright == NULL)
                t = t->pleft;
            else if (t->pleft != NULL && t->pright != NULL)
                // trái cùng cây con phải
                timNodeTheMang(t->pright, x);
            delete x;
        } else if (t->maKH < ma)
            xoaMotKhachHang(t->pright, ma);
        else if (t->maKH > ma)
            xoaMotKhachHang(t->pleft, ma);
    }
}

void timNodeTheMang(tree& t, KhachHang*& x) {
    if (t->pleft != NULL)
        timNodeTheMang(t->pleft, x);
    else {  // trái cùng
        hoanViHaiKhachHang(t, x);
        x = t;  // x sẽ lưu vị trí node này để tí nữa giải phóng
        t = t->pright;
    }
}

void chinhSuaThongTinKhachHang(DanhSachKhachHang& dskh) {
    string sdt;
    cout << "\n(?) Nhap so dien thoai khach hang can chinh sua: ";
    cin >> sdt;
    bool check = kiemTraSoDienThoaiKhachHangTrung(dskh.TREE, sdt);
    if (check == true) {
        chinhSuaThongTinMotKhachHang(dskh.TREE, sdt);
        cout << "\n(!) Chinh sua thong tin khach hang thanh cong\n";
    } else
        cout << "\n(!) So dien thoai khong ton tai\n";
    system("pause");
}

void chinhSuaThongTinMotKhachHang(tree t, string sdt) {
    if (t != NULL) {
        if (t->soDienThoai == sdt) {
            cin.ignore();
            cout << "\n(?) Nhap tai khoan moi: ";
            getline(cin, t->taiKhoan);
            cout << "\n(?) Nhap mat khau moi: ";
            getline(cin, t->matKhau);
            chuanHoaTenTaiKhoan(t->taiKhoan);
        } else if (t->soDienThoai > sdt)
            chinhSuaThongTinMotKhachHang(t->pleft, sdt);
        else if (t->soDienThoai < sdt)
            chinhSuaThongTinMotKhachHang(t->pright, sdt);
    }
}

void docDanhSachKhachHang(DanhSachKhachHang& dskh) {
    ifstream fileIn;
    fileIn.open("../File/khachhang/danhsachkhachhang.txt", ios_base::in);
    while (fileIn.eof() != true) {  // đọc đến cuối file thì dừng
        KhachHang* x = khoiTaoNodeKhachHang();
        fileIn >> x->maKH;
        fileIn.ignore();
        getline(fileIn, x->taiKhoan, ' ');
        getline(fileIn, x->matKhau, ' ');
        getline(fileIn, x->soDienThoai, '\n');
        themMotKhachHang(dskh.TREE, x);
        dskh.soLuong++;
        Sleep(50);  // delay 0.05s
        cout << "\n(*) Ban ghi thu " << dskh.soLuong << " (*)";
    }
    fileIn.close();
}