#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class MayTinh {
   private:
    string maMay;  // mã máy

   public:
    int soMay;                              // số máy
    int kieuMay;                            // kiểu máy: - 0:thường     1:cao cấp
    bool tinhTrang = 0;                     // tình trạng máy: - 0:trống     1:đã được sử dụng
    int gioBD = 0, phutBD = 0, giayBD = 0;  // thời gian bắt đầu (giờ:phút:giây)
    int gioKT = 0, phutKT = 0, giayKT = 0;  // thời gian kết thúc (giờ:phút:giây)
    void themMayTinh(MayTinh[], int &);
    void xoaMayTinh(MayTinh[], int &);
    void inMotMayTheoChieuNgang();
    void inMotMayTheoChieuNgangCoThoiGian();
    void docMotMay(ifstream &);
    void ghiMotMay(ofstream &);

    //** Getters, setters
    string getter_MaMay() { return maMay; };
    void setter_MaMay(string MAMAY) { maMay = MAMAY; };
};

void layThoiGianHeThong(int &gio, int &phut, int &giay);           // lấy thời gian hệ thống
string taoMaMayTinh(MayTinh nhieuMay[], int n);                    // tạo mã máy tính ngẫu nhiên
int kiemTraTrungMaMayTinh(MayTinh nhieuMay[], int n, string str);  // kiểm tra mã máy tính đã tồn tại
int kiemTraTrungSoMay(MayTinh nhieuMay[], int n, int soMay);       // kiểm tra số máy đã tồn tại

void layThoiGianHeThong(int &gio, int &phut, int &giay) {
    time_t baygio = time(0);
    tm *ltm = localtime(&baygio);
    gio = ltm->tm_hour;
    phut = ltm->tm_min;
    giay = ltm->tm_sec;
}

string taoMaMayTinh(MayTinh nhieuMay[], int n) {
    string ma = "STU000";
    do {
        for (int i = 3; i < ma.length(); i++)
            ma[i] = rand() % (57 - 48 + 1) + 48;
    } while (kiemTraTrungMaMayTinh(nhieuMay, n, ma) >= 0);
    return ma;
}

int kiemTraTrungMaMayTinh(MayTinh nhieuMay[], int n, string str) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].getter_MaMay() == str)
            return i;
    return -1;
}

int kiemTraTrungSoMay(MayTinh nhieuMay[], int n, int soMay) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].soMay == soMay)
            return i;
    return -1;
}

void MayTinh::themMayTinh(MayTinh nhieuMay[], int &n) {
    MayTinh mt;
    mt.maMay = taoMaMayTinh(nhieuMay, n);
    do {
        cout << "\n(?) Nhap so may: ";
        // cin.ignore();
        cin >> mt.soMay;
        if (kiemTraTrungSoMay(nhieuMay, n, mt.soMay) != -1)
            cout << "\n\t(!) So may da ton tai - Nhap lai (!)\n";
    } while (kiemTraTrungSoMay(nhieuMay, n, mt.soMay) != -1);
    do {
        cout << "\n(?) Nhap kieu may (0: Thuong - 1: Cao cap): ";
        cin >> mt.kieuMay;
        if (mt.kieuMay < 0 || mt.kieuMay > 1)
            cout << "\n\t(!) Kieu may khong hop le - Nhap lai (!)\n";
    } while (mt.kieuMay < 0 || mt.kieuMay > 1);
    for (int i = n - 1; i >= 0; i--)
        nhieuMay[i + 1] = nhieuMay[i];
    nhieuMay[0] = mt;
    n++;
}

void MayTinh::xoaMayTinh(MayTinh nhieuMay[], int &n) {
    string str;
    cout << "\n(?) Nhap ma may tinh can xoa: ";
    cin >> str;
    int vitri = kiemTraTrungMaMayTinh(nhieuMay, n, str);
    // Dời
    if (vitri < 0) {
        cout << "\n(!) May tinh khong ton tai - Nhap lai (!)\n";
        system("pause");
    } else {
        for (int i = vitri; i < n - 1; i++) {
            nhieuMay[i].maMay = nhieuMay[i + 1].maMay;
            nhieuMay[i].soMay = nhieuMay[i + 1].soMay;
            nhieuMay[i].kieuMay = nhieuMay[i + 1].kieuMay;
            nhieuMay[i].tinhTrang = nhieuMay[i + 1].tinhTrang;
        }
        // Giảm số lượng
        MayTinh tam = nhieuMay[n - 1];
        n--;
        cout << "\n(!) Da xoa thanh cong (!)\n";
        system("pause");
    }
}

void MayTinh::inMotMayTheoChieuNgang() {
    string loaiKieuMay, tinhTrangMay;
    if (tinhTrang == 1)  // tinhTrang == 1 -> Máy đã có người sử dụng
        tinhTrangMay = "Day";
    else  // tinhTrang == 0 -> Máy trống
        tinhTrangMay = "Trong";
    if (kieuMay == 1)  // kieuMay == 1 -> Máy cao cấp
        loaiKieuMay = "Cao cap";
    else  // kieuMay == 0 -> Máy thường
        loaiKieuMay = "Thuong";
    cout << setw(10) << left << maMay << "\t";
    cout << setw(10) << left << soMay << "\t";
    cout << setw(20) << left << loaiKieuMay << "\t";
    cout << setw(20) << left << tinhTrangMay << "\t" << endl;
}

void MayTinh::inMotMayTheoChieuNgangCoThoiGian() {
    string loaiKieuMay, tinhTrangMay;
    if (tinhTrang == 1)  // tinhTrang == 1 -> Máy đã có người sử dụng
        tinhTrangMay = "Day";
    else  // tinhTrang == 0 -> Máy trống
        tinhTrangMay = "Trong";
    if (kieuMay == 1)  // kieuMay == 1 -> Máy cao cấp
        loaiKieuMay = "Cao cap";
    else  // kieuMay == 0 -> Máy thường
        loaiKieuMay = "Thuong";
    cout << setw(10) << left << maMay << "\t";
    cout << setw(10) << left << soMay << "\t";
    cout << setw(20) << left << loaiKieuMay << "\t";
    cout << setw(20) << left << tinhTrangMay << "\t";
    if (tinhTrang != 0) {
        cout << setw(2) << left << gioBD << ":";
        cout << setw(2) << left << phutBD << ":";
        cout << setw(2) << left << giayBD << "\t" << endl;
    } else {
        cout << setw(2) << left << "__:";
        cout << setw(2) << left << "__:";
        cout << setw(2) << left << "__"
             << "\t" << endl;
    }
}

void MayTinh::docMotMay(ifstream &fileIn) {
    getline(fileIn, maMay, ' ');
    fileIn >> soMay;
    fileIn >> kieuMay;
    fileIn >> tinhTrang;
    fileIn.ignore();
}

void MayTinh::ghiMotMay(ofstream &fileOut) {
    fileOut << maMay << ' ';
    fileOut << soMay << ' ';
    fileOut << kieuMay << ' ';
    fileOut << tinhTrang;
}