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
        cout << "\n(?) Nhap tai khoan:   \t\t";
        getline(cin, nv.taiKhoan);
        if (nv.taiKhoan == "admin") {
            cout << bright_red << "\n\t(!) Tai khoan khong duoc trung voi Admin" << reset << "\n";
        } else if (nv.taiKhoan.length() > 30) {
            cout << bright_red << "\n\t(!) Tai khoan khong duoc lon hon 30 ki tu. Xin hay nhap lai" << reset << "\n";
        } else if (kiemTraTaiKhoanNhanVienTrung(nv.taiKhoan) == true)
            cout << bright_red << "\n\t(!) Tai khoan da ton tai. Xin hay nhap lai" << reset << "\n";
    } while (nv.taiKhoan == "admin" || nv.taiKhoan.length() > 30 || kiemTraTaiKhoanNhanVienTrung(nv.taiKhoan) == true);
    xoaKhoangTrangThua(nv.taiKhoan);

    do {
        cout << "\n(?) Nhap mat khau:   \t\t";
        getline(cin, nv.matKhau);
        if (nv.matKhau.length() > 30) {
            cout << bright_red << "\n\t(!) Mat khau khong duoc lon hon 30 ki tu. Xin hay nhap lai" << reset << "\n";
        }
    } while (nv.matKhau.length() > 30);
    xoaKhoangTrangThua(nv.matKhau);

    do {
        cout << "\n(?) Nhap so dien thoai (10 so):\t";
        getline(cin, nv.soDienThoai);
        if (nv.soDienThoai.length() <= 0 || nv.soDienThoai.length() > 10 || nv.soDienThoai.length() != 10) {
            cout << bright_red << "\n\t(!) So dien thoai khong hop le. Xin hay nhap lai" << reset << "\n";
        }
    } while (nv.soDienThoai.length() <= 0 || nv.soDienThoai.length() > 10 || nv.soDienThoai.length() != 10);

    nv.ma = taoMaNhanVien(dsnv);

    do {
        cout << "\n(?) Nhap ten:  \t\t\t";
        cin >> nv.ten;
        if (nv.ten.length() > 8) {
            cout << bright_red << "\n\t(!) Ten khong duoc lon hon 8 ki tu. Xin hay nhap lai" << reset << "\n";
        }
    } while (nv.ten.length() > 8);
    xoaKhoangTrangThua(nv.ten);
    vietHoaKiTuDauMoiTu(nv.ten);
    cin.ignore();

    do {
        cout << "\n(?) Nhap ho:   \t\t\t";
        cin >> nv.ho;
        if (nv.ho.length() > 8) {
            cout << bright_red << "\n\t(!) Ho khong duoc lon hon 8 ki tu. Xin hay nhap lai" << reset << "\n";
        }
    } while (nv.ho.length() > 8);
    xoaKhoangTrangThua(nv.ho);
    vietHoaKiTuDauMoiTu(nv.ho);
    cin.ignore();

    themNhanVien(dsnv, taoNodeNhanVien(nv));
    system("cls");
    cout << bright_green << "\n\t(!) Tao tai khoan thanh cong. Ma tai khoan la " << nv.ma << reset << "\n";
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
    cout << "\n(?) Nhap ma nhan vien can xoa: ";
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
            cout << bright_green << "\n\t(!) Xoa thanh cong" << reset << "\n";
        }
    } else {
        cout << bright_red << "\n\t(!) Khong tim thay nhan vien can xoa" << reset << "\n";
    }
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
        cout << setw(6) << left << "| " + to_string(dsnv->nv.ma) << "|";
        cout << setw(20) << left << " " + dsnv->nv.ho + " " + dsnv->nv.ten << "|";
        cout << setw(30) << left << " " + dsnv->nv.taiKhoan << "|";
        cout << setw(30) << left << " " + dsnv->nv.matKhau << "|";
        cout << setw(14) << left << " " + dsnv->nv.soDienThoai << "|\n";
        inMotNhanVien(dsnv->left);
        inMotNhanVien(dsnv->right);
    }
}

void inDanhSachNhanVien(DanhSachNhanVien dsnv) {
    cout << on_bright_blue << "*-----*--------------------*------------------------------*------------------------------*--------------*\n";
    cout << setw(6) << left << "| Ma"
         << "|";
    cout << setw(20) << left << " Ho ten"
         << "|";
    cout << setw(30) << left << " Tai khoan"
         << "|";
    cout << setw(30) << left << " Mat khau"
         << "|";
    cout << setw(14) << left << " So dien thoai"
         << "|\n";
    cout << "*-----*--------------------*------------------------------*------------------------------*--------------*\n";
    inMotNhanVien(dsnv);
    cout << "*-----*--------------------*------------------------------*------------------------------*--------------*" << reset << "\n";
}

void docDanhSachNhanVien(DanhSachNhanVien &dsnv) {
    string fileName = "../File/nhanvien/danhsachnhanvien.txt";
    ifstream fileIn(fileName);
    if (fileIn.fail()) {
        cout << bright_red << "\n\t(!) Khong tim thay tap tin" << reset << "\n";
        system("pause");
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
        cout << bright_red << "\n\t(!) Khong tim thay tap tin" << reset << "\n";
        system("pause");
    } else
        ghiMotNhanVien(dsnv, fileOut);
    fileOut.close();
}