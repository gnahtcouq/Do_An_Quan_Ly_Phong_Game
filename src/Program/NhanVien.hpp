#pragma once
#include "NhieuMay.hpp"

struct NhanVien {
    int ma;
    string ten;
    string ho;
    string taiKhoan;
    string matKhau;
    string soDienThoai;
};

struct NodeT {
    NhanVien nv;
    NodeT *left;
    NodeT *right;
};
typedef struct NodeT *DanhSachNhanVien;

DanhSachNhanVien taoNodeNhanVien(NhanVien);                         // tạo Node
void khoiTaoDanhSachNhanVien(DanhSachNhanVien &);                   // tạo List
void timNutNhoNhatBenPhai(DanhSachNhanVien &, DanhSachNhanVien &);  // tìm nút nhỏ nhất bên phải
int taoMaNhanVien(DanhSachNhanVien);                                // tạo mã nhân viên ngẫu nhiên
void nhapMotNhanVien(DanhSachNhanVien &);                           // nhập một nhân viên
void themNhanVien(DanhSachNhanVien &, DanhSachNhanVien);            // thêm nhân viên vào cây
void xoaMotNhanVien(DanhSachNhanVien &);                            // xóa một nhân viên
void xoaNhanVien(DanhSachNhanVien &, int);                          // xóa nhân viên khỏi cây
void giaiPhongDanhSachNhanVien(DanhSachNhanVien &);                 // xóa danh sách nhân viên
bool kiemTraMaNhanVienTrung(DanhSachNhanVien, int);                 // kiểm tra mã nhân viên trùng
bool kiemTraTaiKhoanNhanVienTrung(string);                          // kiểm tra tài khoản nhân viên trùng
void inMotNhanVien(DanhSachNhanVien);                               // in một nhân viên
void inDanhSachNhanVien(DanhSachNhanVien);                          // in danh sách nhân viên
void docDanhSachNhanVien(DanhSachNhanVien &);                       // đọc danh sách nhân viên
void ghiMotNhanVien(DanhSachNhanVien &, ofstream &);                // ghi một nhân viên
void ghiDanhSachNhanVien(DanhSachNhanVien &);                       // ghi danh sách nhân viên

DanhSachNhanVien taoNodeNhanVien(NhanVien nv) {
    DanhSachNhanVien nNV = new NodeT;
    nNV->nv = nv;
    nNV->left = NULL;
    nNV->right = NULL;
    return nNV;
}

void khoiTaoDanhSachNhanVien(DanhSachNhanVien &dsnv) {
    dsnv = NULL;
}

void timNutNhoNhatBenPhai(DanhSachNhanVien &p, DanhSachNhanVien &dsnv) {
    if (dsnv->left)
        timNutNhoNhatBenPhai(p, dsnv->left);
    else {
        p->nv = dsnv->nv;
        p = dsnv;
        dsnv = dsnv->right;
    }
}

int taoMaNhanVien(DanhSachNhanVien dsnv) {
    int ma;
    do {
        ma = rand() % (999 - 100 + 1) + 100;
    } while (kiemTraMaNhanVienTrung(dsnv, ma) == true);
    return ma;
}

void nhapMotNhanVien(DanhSachNhanVien &dsnv) {
    NhanVien nv;
    do {
        cout << "\n(?) Nhập tài khoản:   \t\t";
        getline(cin, nv.taiKhoan);
        if (nv.taiKhoan == "admin") {
            cout << bright_red << "\n\t(!) Tài khoản không được trùng với tài khoản Admin" << reset << "\n";
        } else if (nv.taiKhoan.length() > 30) {
            cout << bright_red << "\n\t(!) Tài khoản không được lớn hơn 30 kí tự. Xin hãy nhập lại" << reset << "\n";
        } else if (kiemTraTaiKhoanNhanVienTrung(nv.taiKhoan) == true)
            cout << bright_red << "\n\t(!) Tài khoản đã tồn tại. Xin hãy nhập lại" << reset << "\n";
    } while (nv.taiKhoan == "admin" || nv.taiKhoan.length() > 30 || kiemTraTaiKhoanNhanVienTrung(nv.taiKhoan) == true);
    xoaKhoangTrangThua(nv.taiKhoan);

    do {
        cout << "\n(?) Nhập mật khẩu:   \t\t";
        getline(cin, nv.matKhau);
        if (nv.matKhau.length() > 30) {
            cout << bright_red << "\n\t(!) Mật khẩu không được lớn hơn 30 kí tự. Xin hãy nhập lại" << reset << "\n";
        }
    } while (nv.matKhau.length() > 30);
    xoaKhoangTrangThua(nv.matKhau);

    do {
        cout << "\n(?) Nhập số điện thoại (10 số):\t";
        getline(cin, nv.soDienThoai);
        if (nv.soDienThoai.length() <= 0 || nv.soDienThoai.length() > 10 || nv.soDienThoai.length() != 10) {
            cout << bright_red << "\n\t(!) Số điện thoại không hợp lệ. Xin hãy nhập lại" << reset << "\n";
        }
    } while (nv.soDienThoai.length() <= 0 || nv.soDienThoai.length() > 10 || nv.soDienThoai.length() != 10);

    nv.ma = taoMaNhanVien(dsnv);

    do {
        cout << "\n(?) Nhập tên:  \t\t\t";
        cin >> nv.ten;
        if (nv.ten.length() > 8) {
            cout << bright_red << "\n\t(!) Tên không được lớn hơn 8 kí tự. Xin hãy nhập lại" << reset << "\n";
        }
    } while (nv.ten.length() > 8);
    xoaKhoangTrangThua(nv.ten);
    vietHoaKiTuDauMoiTu(nv.ten);
    cin.ignore();

    do {
        cout << "\n(?) Nhập họ:   \t\t\t";
        cin >> nv.ho;
        if (nv.ho.length() > 8) {
            cout << bright_red << "\n\t(!) Họ không được lớn hơn 8 kí tự xin hãy nhập lại" << reset << "\n";
        }
    } while (nv.ho.length() > 8);
    xoaKhoangTrangThua(nv.ho);
    vietHoaKiTuDauMoiTu(nv.ho);
    cin.ignore();

    themNhanVien(dsnv, taoNodeNhanVien(nv));
    system("cls");
    cout << bright_green << "\n\t(!) Tạo tài khoản thành công. Mã tài khoản là " << nv.ma << reset << "\n";
}

void themNhanVien(DanhSachNhanVien &dsnv, DanhSachNhanVien nv) {
    if (dsnv) {
        if (dsnv->nv.ma == nv->nv.ma)  // Trùng
            return;
        if (nv->nv.ma < dsnv->nv.ma)
            themNhanVien(dsnv->left, nv);
        else
            themNhanVien(dsnv->right, nv);
    } else
        dsnv = nv;
}

void xoaMotNhanVien(DanhSachNhanVien &dsnv) {
    int ma;
    cout << "\n(?) Nhập mã nhân viên cần xóa: ";
    cin >> ma;
    xoaNhanVien(dsnv, ma);
}

void xoaNhanVien(DanhSachNhanVien &dsnv, int ma) {
    if (dsnv) {
        if (ma > dsnv->nv.ma)
            xoaNhanVien(dsnv->right, ma);
        else if (ma < dsnv->nv.ma)
            xoaNhanVien(dsnv->left, ma);
        else {
            DanhSachNhanVien p = dsnv;
            if (!dsnv->left)
                dsnv = dsnv->right;
            else if (!dsnv->right)
                dsnv = dsnv->left;
            else
                timNutNhoNhatBenPhai(p, dsnv->right);
            delete p;
            cout << bright_green << "\n\t(!) Xóa thành công" << reset << "\n";
        }
    } else
        cout << bright_red << "\n\t(!) Không tìm thấy nhân viên cần xóa" << reset << "\n";
}

void giaiPhongDanhSachNhanVien(DanhSachNhanVien &dsnv) {
    if (dsnv) {
        giaiPhongDanhSachNhanVien(dsnv->left);
        giaiPhongDanhSachNhanVien(dsnv->right);
        delete dsnv;
    }
}

bool kiemTraMaNhanVienTrung(DanhSachNhanVien dsnv, int ma) {
    if (dsnv) {
        if (dsnv->nv.ma == ma)
            return true;
        if (ma < dsnv->nv.ma)
            kiemTraMaNhanVienTrung(dsnv->left, ma);
        else
            kiemTraMaNhanVienTrung(dsnv->right, ma);
    }
    return false;
}

bool kiemTraTaiKhoanNhanVienTrung(string taiKhoan) {
    string layMa, layTen, layHo, layTaiKhoan, layMatKhau, laySoDienThoai;
    string fileName = "../File/nhanvien/danhsachnhanvien.txt";
    ifstream fileIn(fileName);
    while (fileIn >> layMa >> layTen >> layHo >> layTaiKhoan >> layMatKhau >> laySoDienThoai) {
        if (taiKhoan == layTaiKhoan) {
            return true;
        }
    }
    return false;
}

void inMotNhanVien(DanhSachNhanVien dsnv) {
    if (dsnv) {
        cout << on_bright_blue << setw(6) << left << "| " + to_string(dsnv->nv.ma) << "|" << reset;
        cout << on_bright_blue << setw(20) << left << " " + dsnv->nv.ho + " " + dsnv->nv.ten << "|" << reset;
        cout << on_bright_blue << setw(30) << left << " " + dsnv->nv.taiKhoan << "|" << reset;
        cout << on_bright_blue << setw(30) << left << " " + dsnv->nv.matKhau << "|" << reset;
        cout << on_bright_blue << setw(14) << left << " " + dsnv->nv.soDienThoai << "|" << reset << "\n";
        inMotNhanVien(dsnv->left);
        inMotNhanVien(dsnv->right);
    }
}

void inDanhSachNhanVien(DanhSachNhanVien dsnv) {
    cout << on_bright_blue << "*-----*--------------------*------------------------------*------------------------------*--------------*" << reset << "\n";
    cout << on_bright_blue << setw(7) << left << "| Mã"
         << "|" << reset;
    cout << on_bright_blue << setw(23) << left << " Họ tên"
         << "|" << reset;
    cout << on_bright_blue << setw(33) << left << " Tài khoản"
         << "|" << reset;
    cout << on_bright_blue << setw(34) << left << " Mật khẩu"
         << "|" << reset;
    cout << on_bright_blue << setw(18) << left << " Số điện thoại"
         << "|" << reset << "\n";
    cout << on_bright_blue << "*-----*--------------------*------------------------------*------------------------------*--------------*" << reset << "\n";
    inMotNhanVien(dsnv);
    cout << on_bright_blue << "*-----*--------------------*------------------------------*------------------------------*--------------*" << reset << "\n";
}

void docDanhSachNhanVien(DanhSachNhanVien &dsnv) {
    string fileName = "../File/nhanvien/danhsachnhanvien.txt";
    ifstream fileIn(fileName);
    if (fileIn.fail()) {
        cout << bright_red << "\n\t(!) Không tìm thấy tập tin" << reset << "\n";
        cout << "\n\t[Nhấn ENTER để tiếp tục...]";
        while (true) {
            int key = _getch();
            if (key == KEY_ENTER)
                break;
        }
    } else {
        if (kiemTraFileTrong(fileName) != -1) {
            while (!fileIn.eof()) {
                NhanVien nv;
                fileIn >> nv.ma >> nv.ten >> nv.ho >> nv.taiKhoan >> nv.matKhau >> nv.soDienThoai;
                themNhanVien(dsnv, taoNodeNhanVien(nv));
            }
        }
    }
    fileIn.close();
}

void ghiMotNhanVien(DanhSachNhanVien &dsnv, ofstream &fileOut) {
    if (dsnv) {
        fileOut << dsnv->nv.ma << " ";
        fileOut << dsnv->nv.ho << " ";
        fileOut << dsnv->nv.ten << " ";
        fileOut << dsnv->nv.taiKhoan << " ";
        fileOut << dsnv->nv.matKhau << " ";
        fileOut << dsnv->nv.soDienThoai << endl;
        ghiMotNhanVien(dsnv->left, fileOut);
        ghiMotNhanVien(dsnv->right, fileOut);
    }
}

void ghiDanhSachNhanVien(DanhSachNhanVien &dsnv) {
    string fileName = "../File/nhanvien/danhsachnhanvien.txt";
    ofstream fileOut(fileName);
    if (fileOut.fail()) {
        cout << bright_red << "\n\t(!) Không tìm thấy tập tin" << reset << "\n";
        cout << "\n\t[Nhấn ENTER để tiếp tục...]";
        while (true) {
            int key = _getch();
            if (key == KEY_ENTER)
                break;
        }
    } else
        ghiMotNhanVien(dsnv, fileOut);
    fileOut.close();
}