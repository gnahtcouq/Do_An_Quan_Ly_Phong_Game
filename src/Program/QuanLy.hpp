#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class DuLieuTaiKhoan {
   private:
    string ma;
    string ten;
    string ho;
    string taiKhoan;
    string matKhau;
    string soDienThoai;
    double soDu;

   public:
    //** Getters, setters
    void setMa(string ma) { this->ma = ma; }
    void setTen(string ten) { this->ten = ten; }
    void setHo(string ho) { this->ho = ho; }
    void setTaiKhoan(string taiKhoan) { this->taiKhoan = taiKhoan; }
    void setMatKhau(string matKhau) { this->matKhau = matKhau; }
    void setSoDienThoai(string sdt) { this->soDienThoai = sdt; }
    void setSoDu(double soDu) { this->soDu = soDu; }
    string getMa() { return ma; }
    string getTen() { return ten; }
    string getHo() { return ho; }
    string getTaiKhoan() { return taiKhoan; }
    string getMatKhau() { return matKhau; }
    string getSoDienThoai() { return soDienThoai; }
    double getSoDu() { return soDu; }
};

class Admin : public DuLieuTaiKhoan {
   private:
    string taiKhoanAdmin, matKhauAdmin;

   public:
    Admin() {
        taiKhoanAdmin = "admin";
        matKhauAdmin = "admin";
    }
    //** Getters, setters
    void setTaiKhoanAdmin(string taiKhoan) { taiKhoanAdmin = taiKhoan; }
    void setMatKhauAdmin(string matKhau) { matKhauAdmin = matKhau; }
    string getTaiKhoanAdmin() { return taiKhoanAdmin; }
    string getMatKhauAdmin() { return matKhauAdmin; }
};

void dangNhap();
bool xacThucDangNhap(string taiKhoan, string matKhau);
void xuatThongTinKhachHangTheoTenTaiKhoan();
bool timMaTaiKhoan(string taiKhoan, string &ma);
void napTien();

bool xacThucDangNhap(string taiKhoan, string matKhau) {
    Admin get;
    if (taiKhoan == get.getTaiKhoanAdmin() && matKhau == get.getMatKhauAdmin())
        return true;
    else
        return false;
}

void dangNhap() {
    bool kiemTraDangNhap;
    string taiKhoan, matKhau;
    system("cls");
    cout << "-----------------------------------\n";
    cout << "         QUAN LY STU CYBER         \n";
    cout << "             DANG NHAP             \n";
    cout << "-----------------------------------\n";
    do {
        cout << "(?) Nhap tai khoan: ";
        cin >> taiKhoan;
        cin.ignore();
        cout << "(?) Nhap mat khau: ";
        cin >> matKhau;
        cin.ignore();
        kiemTraDangNhap = xacThucDangNhap(taiKhoan, matKhau);

        if (!kiemTraDangNhap)
            cout << "(!) Tai khoan/mat khau khong hop le. Hay nhap lai\n";
    } while (!kiemTraDangNhap);
}

void xuatThongTinKhachHangTheoTenTaiKhoan() {
    ifstream fileIn;
    string ma, ten, ho, taiKhoan, soDienThoai, soDu;
    bool kiemTraTaiKhoan;
    do {
        cout << "(?) Nhap tai khoan muon xem: ";
        cin >> taiKhoan;
        kiemTraTaiKhoan = timMaTaiKhoan(taiKhoan, ma);
        if (!kiemTraTaiKhoan)  // nếu kiemTraTaiKhoan == false
            cout << "(!) Tai khoan khong ton tai. Hay nhap lai\n";
    } while (!kiemTraTaiKhoan);
    cin.ignore();
    fileIn.open("../File/khachhang/dulieu/" + ma + ".txt");

    if (fileIn.is_open()) {
        while (fileIn >> ten >> ho >> taiKhoan >> soDienThoai >> soDu)
            ;
        cout << "\n";
        cout << setw(20) << left << "Ma tai khoan: ";
        cout << setw(15) << right << ma << endl;
        cout << setw(20) << left << "Ho ten: ";
        cout << setw(15) << right << ho + " " + ten << endl;
        cout << setw(20) << left << "So dien thoai: ";
        cout << setw(15) << right << soDienThoai << endl;
        cout << setw(20) << left << "So du: ";
        cout << setw(15) << right << soDu + " VND" << endl;
    } else {
        cout << "(!) Khong tim thay tap tin\n";
        system("pause");
    }
    fileIn.close();
}

bool timMaTaiKhoan(string taiKhoan, string &ma) {
    bool kiemTra = false;
    string layMa, layTen, layHo, layTaiKhoan, layMatKhau, laySoDienThoai;
    ifstream fileIn;
    fileIn.open("../File/khachhang/thongtin.txt");
    while (fileIn >> layMa >> layTen >> layHo >> layTaiKhoan >> layMatKhau >> laySoDienThoai) {
        if (taiKhoan == layTaiKhoan) {
            kiemTra = true;
            break;
        }
    }
    ma = layMa;
    return kiemTra;
}

void napTien() {
    double soTien, soDu;
    string ma, ten, ho, taiKhoan, soDienThoai;
    fstream fileIn;
    bool kiemTraTaiKhoan;
    do {
        cout << "\n";
        cout << "(?) Nhap tai khoan muon nap tien: ";
        cin >> taiKhoan;
        kiemTraTaiKhoan = timMaTaiKhoan(taiKhoan, ma);
        if (!kiemTraTaiKhoan)  // nếu kiemTraTaiKhoan == false
            cout << "(!) Tai khoan khong ton tai. Hay nhap lai\n";
    } while (!kiemTraTaiKhoan);

    string tenFile = "../File/khachhang/dulieu/" + ma + ".txt";
    fileIn.open(tenFile, ios::in);
    fileIn >> ten >> ho >> taiKhoan >> soDienThoai >> soDu;
    fileIn.close();

    cout << "(?) Nhap so tien muon nap: ";
    cin >> soTien;
    soDu += soTien;
    fstream fileOut;
    fileOut.open(tenFile, ios::out);
    fileOut << ten << endl
            << ho << endl
            << taiKhoan << endl
            << soDienThoai << endl
            << (long long)soDu << endl;
    fileOut.close();
    cout << "(!) Nap tien thanh cong\n";
}