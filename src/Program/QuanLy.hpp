#pragma once
#include "MotMay.hpp"
#include "NhanVien.hpp"
#include "XuLy.hpp"

class Admin {
   private:
    string taiKhoanAdmin = "admin",
           matKhauAdmin = "admin";

   public:
    bool laAdmin(string taiKhoan, string matKhau) {
        if (taiKhoan == taiKhoanAdmin && matKhau == matKhauAdmin)
            return true;
        return false;
    }
    string getTaiKhoanAdmin() { return taiKhoanAdmin; }
    string getMatKhauAdmin() { return matKhauAdmin; }
};

int kiemTraTaiKhoan(DanhSachNhanVien, string, string);  // kiểm tra tài khoản
int xacThucDangNhap(DanhSachNhanVien, string, string);  // xác thực đăng nhập
void dangNhap(DanhSachNhanVien, int &, string &);       // đăng nhập
void docLichSu(string &);                               // đọc file lịch sử
bool kiemTraNgayHopLe(int, int, int);                   // kiểm tra ngày nhập vào hợp lệ
void kiemTraDoanhThu7NgayGanNhat();                     // kiểm tra doanh thu 7 ngày gần nhất
void kiemTraDoanhThuNgayTuyChinh();                     // kiểm tra doanh thu theo ngày tùy chỉnh

int kiemTraTaiKhoan(DanhSachNhanVien dsnv, string taiKhoan, string matKhau) {
    if (dsnv) {
        if (dsnv->nv.taiKhoan == taiKhoan && dsnv->nv.matKhau == matKhau)
            return 1;
        return kiemTraTaiKhoan(dsnv->left, taiKhoan, matKhau) + kiemTraTaiKhoan(dsnv->right, taiKhoan, matKhau);
    } else
        return 0;
}

int xacThucDangNhap(DanhSachNhanVien dsnv, string taiKhoan, string matKhau) {
    Admin dangNhap;
    if (dangNhap.laAdmin(taiKhoan, matKhau))
        return 1;
    else {
        if (kiemTraTaiKhoan(dsnv, taiKhoan, matKhau) == 1)
            return 2;
    }
    return 0;
}

void dangNhap(DanhSachNhanVien dsnv, int &phanQuyen, string &ten) {
    string taiKhoan, matKhau;
    do {
        char c;
        int viTri = 0;
        char *str = new char[30];
        assert(str != NULL);
        system("cls");
        inLogo();
        cout << "\t\t\t*-----------------------------------*\n";
        cout << "\t\t\t|" << on_blue << "         QUAN LY STU CYBER         " << reset << "|\n";
        cout << "\t\t\t|" << on_blue << "             DANG NHAP             " << reset << "|\n";
        cout << "\t\t\t*-----------------------------------*\n";
        cout << "\n\t\t\t(?) Nhap tai khoan: \t";
        cin >> taiKhoan;
        cin.ignore();
        cout << "\n\t\t\t(?) Nhap mat khau:  \t";
        while (true) {
            c = getch();
            if (c == 13)  // break vì nhấn ENTER
                break;
            else if (c == 8) {
                // nhấn BACKSPACE sẽ xóa kí tự
                cout << (viTri > 0 ? "\b \b" : "");
                str[--viTri] = '\0';
            } else {
                cout << "*";
                str[viTri++] = c;
                if (viTri > 30) break;  // break vì mật khẩu quá dài
            }
            if (viTri < 0)
                viTri = 0;
        }
        str[viTri] = '\0';
        matKhau = str;
        ten = taiKhoan;
        phanQuyen = xacThucDangNhap(dsnv, taiKhoan, matKhau);
        if (phanQuyen == 0) {
            cout << bright_red << "\n\n\t\t\t(!) Tai khoan/Mat khau khong chinh xac. Xin hay nhap lai" << reset << "\n";
            system("pause");
        }
    } while (phanQuyen == 0);
    cout << bright_green << "\n\n\t\t\t(!) Dang nhap thanh cong" << reset << "\n";
    system("pause");

    // Ghi lịch sử đăng nhập
    int gio, phut, giay, ngay, thang, nam;
    layThoiGianHeThong(gio, phut, giay, ngay, thang, nam);

    string GIO = to_string(gio);
    string PHUT = to_string(phut);
    string GIAY = to_string(giay);
    string NGAY = to_string(ngay);
    string THANG = to_string(thang);
    string NAM = to_string(nam);

    if (GIO.length() == 1) GIO = "0" + GIO;
    if (PHUT.length() == 1) PHUT = "0" + PHUT;
    if (GIAY.length() == 1) GIAY = "0" + GIAY;
    if (NGAY.length() == 1) NGAY = "0" + NGAY;
    if (THANG.length() == 1) THANG = "0" + THANG;
    if (NAM.length() == 1) NAM = "0" + NAM;

    string thoiGianDangNhap = GIO + ":" + PHUT + ":" + GIAY + " - " + NGAY + "/" + THANG + "/" + NAM;
    string fileName = "../File/lichsu/lichsudangnhap.txt";
    ofstream fileOut(fileName, ios::app);
    if (fileOut.fail()) {
        cout << bright_red << "\n\t(!) Khong tim thay tap tin" << reset << "\n";
        system("pause");
    } else {
        fileOut << setw(25) << left << "| " + thoiGianDangNhap << "|\t";
        fileOut << setw(30) << left << ten << "|\t";
        fileOut << setw(10) << left << "Dang nhap"
                << " |\n";
    }
    fileOut.close();
}

void docLichSu(string &fileName) {
    ifstream fileIn(fileName);
    if (fileIn.fail()) {
        cout << bright_red << "\n\t(!) Khong tim thay tap tin" << reset << "\n";
        system("pause");
    } else {
        string line;
        vector<string> list;
        while (getline(fileIn, line)) {
            list.push_back(line);
        }
        fileIn.close();
        for (int i = 0; i < list.size(); i++)
            cout << list[i] << endl;
    }
}

bool kiemTraNgayHopLe(int ngay, int thang, int nam) {
    time_t baygio = time(0);
    tm *ltm = localtime(&baygio);
    int namHienTai = 1900 + ltm->tm_year;
    if (nam <= 1900 || thang <= 0 || thang > 12 || ngay <= 0 || ngay > 31 || nam >= namHienTai + 1)
        return 0;
    if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
        if (ngay <= 31)
            return 1;
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
        if (ngay <= 30)
            return 1;
    if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0) {
        if (ngay <= 29)
            return 1;
    } else {
        if (ngay <= 28)
            return 1;
    }
    return 0;
}

void kiemTraDoanhThu7NgayGanNhat() {
    int gio, phut, giay, ngay, thang, nam, soNgay;
    int ngay2, ngay3, ngay4, ngay5, ngay6, ngay7;
    layThoiGianHeThong(gio, phut, giay, ngay, thang, nam);
    int thang2 = thang - 1;
    if (thang2 == 4 || thang2 == 6 || thang2 == 9 || thang2 == 11)
        soNgay = 30;
    if (thang2 == 1 || thang2 == 3 || thang2 == 5 || thang2 == 7 || thang2 == 8 || thang2 == 10 || thang2 == 12)
        soNgay = 31;
    if (thang2 == 2) {
        if ((nam % 4 == 0) && (nam % 100 != 0) || (nam % 400 == 0))
            soNgay += 29;
        else
            soNgay += 28;
    }

    if (thang != 1) {
        if (ngay - 1 <= 0) {
            ngay2 = soNgay;
            ngay3 = soNgay - 2;
            ngay4 = soNgay - 3;
            ngay5 = soNgay - 4;
            ngay6 = soNgay - 5;
            ngay7 = soNgay - 6;
        } else {
            ngay2 = ngay - 1;
            ngay3 = ngay - 2;
            ngay4 = ngay - 3;
            ngay5 = ngay - 4;
            ngay6 = ngay - 5;
            ngay7 = ngay - 6;
        }
    } else {
        if (ngay - 1 <= 0) {
            ngay2 = 31;
            ngay3 = 31 - 2;
            ngay4 = 31 - 3;
            ngay5 = 31 - 4;
            ngay6 = 31 - 5;
            ngay7 = 31 - 7;
        } else {
            ngay2 = ngay - 1;
            ngay3 = ngay - 2;
            ngay4 = ngay - 3;
            ngay5 = ngay - 4;
            ngay6 = ngay - 5;
            ngay7 = ngay - 6;
        }
    }
    string doanhThu1, doanhThu2, doanhThu3, doanhThu4, doanhThu5, doanhThu6, doanhThu7;
    string tenFile1, tenFile2, tenFile3, tenFile4, tenFile5, tenFile6, tenFile7;

    string NGAY1 = to_string(ngay);
    string NGAY2 = to_string(ngay2);
    string NGAY3 = to_string(ngay3);
    string NGAY4 = to_string(ngay4);
    string NGAY5 = to_string(ngay5);
    string NGAY6 = to_string(ngay6);
    string NGAY7 = to_string(ngay7);
    string THANG1 = to_string(thang);
    string THANG2 = to_string(thang - 1);
    string NAM1 = to_string(nam);
    string NAM2 = to_string(nam - 1);

    if (NGAY1.length() == 1) NGAY1 = "0" + NGAY1;
    if (NGAY2.length() == 1) NGAY2 = "0" + NGAY2;
    if (NGAY3.length() == 1) NGAY3 = "0" + NGAY3;
    if (NGAY4.length() == 1) NGAY4 = "0" + NGAY4;
    if (NGAY5.length() == 1) NGAY5 = "0" + NGAY5;
    if (NGAY6.length() == 1) NGAY6 = "0" + NGAY6;
    if (NGAY7.length() == 1) NGAY7 = "0" + NGAY7;
    if (THANG1.length() == 1) THANG1 = "0" + THANG1;
    if (THANG2.length() == 1) THANG2 = "0" + THANG2;
    if (NAM1.length() == 1) NAM1 = "0" + NAM1;
    if (NAM2.length() == 2) NAM2 = "0" + NAM2;

    fstream docDoanhThu;
    docDoanhThu.open("../File/doanhthu/" + NGAY1 + "_" + THANG1 + "_" + NAM1 + ".txt");
    docDoanhThu >> doanhThu1;
    docDoanhThu.close();

    if (thang != 1) {
        if (ngay - 1 < 0) {
            tenFile1 = "../File/doanhthu/" + NGAY1 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile2 = "../File/doanhthu/" + NGAY2 + "_" + THANG2 + "_" + NAM1 + ".txt";
            tenFile3 = "../File/doanhthu/" + NGAY3 + "_" + THANG2 + "_" + NAM1 + ".txt";
            tenFile4 = "../File/doanhthu/" + NGAY4 + "_" + THANG2 + "_" + NAM1 + ".txt";
            tenFile5 = "../File/doanhthu/" + NGAY5 + "_" + THANG2 + "_" + NAM1 + ".txt";
            tenFile6 = "../File/doanhthu/" + NGAY6 + "_" + THANG2 + "_" + NAM1 + ".txt";
            tenFile7 = "../File/doanhthu/" + NGAY7 + "_" + THANG2 + "_" + NAM1 + ".txt";
        } else {
            tenFile1 = "../File/doanhthu/" + NGAY1 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile2 = "../File/doanhthu/" + NGAY2 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile3 = "../File/doanhthu/" + NGAY3 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile4 = "../File/doanhthu/" + NGAY4 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile5 = "../File/doanhthu/" + NGAY5 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile6 = "../File/doanhthu/" + NGAY6 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile7 = "../File/doanhthu/" + NGAY7 + "_" + THANG1 + "_" + NAM1 + ".txt";
        }
    } else {
        if (ngay - 1 < 0) {
            tenFile1 = "../File/doanhthu/" + NGAY1 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile2 = "../File/doanhthu/" + NGAY2 + "_" + THANG2 + "_" + NAM2 + ".txt";
            tenFile3 = "../File/doanhthu/" + NGAY3 + "_" + THANG2 + "_" + NAM2 + ".txt";
            tenFile4 = "../File/doanhthu/" + NGAY4 + "_" + THANG2 + "_" + NAM2 + ".txt";
            tenFile5 = "../File/doanhthu/" + NGAY5 + "_" + THANG2 + "_" + NAM2 + ".txt";
            tenFile6 = "../File/doanhthu/" + NGAY6 + "_" + THANG2 + "_" + NAM2 + ".txt";
            tenFile7 = "../File/doanhthu/" + NGAY7 + "_" + THANG2 + "_" + NAM2 + ".txt";
        } else {
            tenFile1 = "../File/doanhthu/" + NGAY1 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile2 = "../File/doanhthu/" + NGAY2 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile3 = "../File/doanhthu/" + NGAY3 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile4 = "../File/doanhthu/" + NGAY4 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile5 = "../File/doanhthu/" + NGAY5 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile6 = "../File/doanhthu/" + NGAY6 + "_" + THANG1 + "_" + NAM1 + ".txt";
            tenFile7 = "../File/doanhthu/" + NGAY7 + "_" + THANG1 + "_" + NAM1 + ".txt";
        }
    }

    if (kiemTraFileTrong(tenFile1) == -1)
        doanhThu1 = "0 VND";
    else {
        docDoanhThu.open(tenFile1);
        docDoanhThu >> doanhThu1;
        doanhThu1 += " VND";
        docDoanhThu.close();
    }
    if (kiemTraFileTrong(tenFile2) == -1)
        doanhThu2 = "0 VND";
    else {
        docDoanhThu.open(tenFile2);
        docDoanhThu >> doanhThu2;
        doanhThu2 += " VND";
        docDoanhThu.close();
    }
    if (kiemTraFileTrong(tenFile3) == -1)
        doanhThu3 = "0 VND";
    else {
        docDoanhThu.open(tenFile3);
        docDoanhThu >> doanhThu3;
        doanhThu3 += " VND";
        docDoanhThu.close();
    }
    if (kiemTraFileTrong(tenFile4) == -1)
        doanhThu4 = "0 VND";
    else {
        docDoanhThu.open(tenFile4);
        docDoanhThu >> doanhThu4;
        doanhThu4 += " VND";
        docDoanhThu.close();
    }
    if (kiemTraFileTrong(tenFile5) == -1)
        doanhThu5 = "0 VND";
    else {
        docDoanhThu.open(tenFile5);
        docDoanhThu >> doanhThu5;
        doanhThu5 += " VND";
        docDoanhThu.close();
    }
    if (kiemTraFileTrong(tenFile6) == -1)
        doanhThu6 = "0 VND";
    else {
        docDoanhThu.open(tenFile6);
        docDoanhThu >> doanhThu6;
        doanhThu6 += " VND";
        docDoanhThu.close();
    }
    if (kiemTraFileTrong(tenFile7) == -1)
        doanhThu7 = "0 VND";
    else {
        docDoanhThu.open(tenFile7);
        docDoanhThu >> doanhThu7;
        doanhThu7 += " VND";
        docDoanhThu.close();
    }

    system("cls");
    cout << bright_yellow << "\nMENU/KIEM TRA DOANH THU/DOANH THU 7 NGAY GAN NHAT" << reset << "\n";
    cout << "*------------------------*------------------------------------*\n";
    cout << setw(25) << left << "| Thoi gian"
         << "|\t";
    cout << setw(30) << left << "Tong doanh thu"
         << "|\n";
    cout << "*------------------------*------------------------------------*\n";
    cout << setw(25) << "| " + NGAY1 + "/" + THANG1 + "/" + NAM1 + " (Hom nay)"
         << "|\t";
    cout << setw(30) << doanhThu1 << "|\n";
    cout << setw(25) << "| " + NGAY2 + "/" + THANG1 + "/" + NAM1 << "|\t";
    cout << setw(30) << doanhThu2 << "|\n";
    cout << setw(25) << "| " + NGAY3 + "/" + THANG1 + "/" + NAM1 << "|\t";
    cout << setw(30) << doanhThu3 << "|\n";
    cout << setw(25) << "| " + NGAY4 + "/" + THANG1 + "/" + NAM1 << "|\t";
    cout << setw(30) << doanhThu4 << "|\n";
    cout << setw(25) << "| " + NGAY5 + "/" + THANG1 + "/" + NAM1 << "|\t";
    cout << setw(30) << doanhThu5 << "|\n";
    cout << setw(25) << "| " + NGAY6 + "/" + THANG1 + "/" + NAM1 << "|\t";
    cout << setw(30) << doanhThu6 << "|\n";
    cout << setw(25) << "| " + NGAY7 + "/" + THANG1 + "/" + NAM1 << "|\t";
    cout << setw(30) << doanhThu7 << "|\n";
    cout << "*------------------------*------------------------------------*\n";
}

void kiemTraDoanhThuNgayTuyChinh() {
    int ngay, thang, nam;
    string doanhThu;
    do {
        system("cls");
        cout << bright_yellow << "\nMENU/KIEM TRA DOANH THU/DOANH THU NGAY TUY CHINH" << reset << "\n";
        cout << "\n(?) Nhap ngay: ";
        cin >> ngay;
        cout << "\n(?) Nhap thang: ";
        cin >> thang;
        cout << "\n(?) Nhap nam: ";
        cin >> nam;
        if (!kiemTraNgayHopLe(ngay, thang, nam)) {
            cout << bright_red << "\n\t(!) Ngay/Thang/Nam khong hop le. Xin hay nhap lai" << reset << "\n";
            system("pause");
        }
    } while (!kiemTraNgayHopLe(ngay, thang, nam));

    string NGAY = to_string(ngay);
    string THANG = to_string(thang);
    string NAM = to_string(nam);
    if (NGAY.length() == 1) NGAY = "0" + NGAY;
    if (THANG.length() == 1) THANG = "0" + THANG;
    if (NAM.length() == 1) NAM = "0" + NAM;
    string tenFile = "../File/doanhthu/" + NGAY + "_" + THANG + "_" + NAM + ".txt";

    fstream docDoanhThu;
    if (kiemTraFileTrong(tenFile) == -1)
        doanhThu = "0 VND";
    else {
        docDoanhThu.open(tenFile);
        docDoanhThu >> doanhThu;
        doanhThu += " VND";
        docDoanhThu.close();
    }

    system("cls");
    cout << bright_yellow << "\nMENU/KIEM TRA DOANH THU/DOANH THU NGAY TUY CHINH" << reset << "\n";
    cout << "*------------------------*------------------------------------*\n";
    cout << setw(25) << left << "| Thoi gian"
         << "|\t";
    cout << setw(30) << left << "Tong doanh thu"
         << "|\n";
    cout << "*------------------------*------------------------------------*\n";
    cout << setw(25) << "| " + NGAY + "/" + THANG + "/" + NAM << "|\t";
    cout << setw(30) << doanhThu << "|\n";
    cout << "*------------------------*------------------------------------*\n";
}