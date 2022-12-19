#pragma once
#include "XuLy.hpp"

class MayTinh {
   private:
    string maMay;  // mã máy

   public:
    int soMay;                                                    // số máy
    int kieuMay;                                                  // kiểu máy:       -0:thường  1:cao cấp
    bool tinhTrang = 0;                                           // tình trạng máy: -0:trống   1:đã được sử dụng
    int gioBD = 0, phutBD = 0, giayBD = 0;                        // thời gian bắt đầu (giờ:phút:giây)
    int ngayBD = 0, thangBD = 0, namBD = 0;                       // thời gian bắt đầu (ngày/tháng/năm)
    int gioKT = 0, phutKT = 0, giayKT = 0;                        // thời gian kết thúc (giờ:phút:giây)
    int ngayKT = 0, thangKT = 0, namKT = 0;                       // thời gian kết thúc (ngày/tháng/năm)
    long long giaTien = 0, giaTienThuong = 0, giaTienCaoCap = 0;  // giá tiền
    void themMayTinh(MayTinh[], int &, int &);                    // thêm một máy tính
    void xoaMayTinh(MayTinh[], int &, int &);                     // xóa một máy tính
    void inMotMayTheoChieuNgang();                                // in một máy theo chiều ngang
    void inMotMayTheoChieuNgangCoThoiGian();                      // im một máy theo chiều ngang có thời gian truy cập
    void docMotMay(ifstream &);                                   // đọc thông tin một máy tính từ file
    void ghiMotMay(ofstream &);                                   // ghi thông tin một máy tính ra file
    void docGiaTien();                                            // đọc giá tiền từ file
    void ghiGiaTien();                                            // ghi giá tiền ra file
    void thietLapGiaTien();                                       // thiết lập giá tiền

    //** Getters, setters
    string getter_MaMay() { return maMay; };
    void setter_MaMay(string MAMAY) { maMay = MAMAY; };
};

string taoMaMayTinh(MayTinh[], int);                // tạo mã máy tính ngẫu nhiên
int kiemTraTrungMaMayTinh(MayTinh[], int, string);  // kiểm tra mã máy tính đã tồn tại
int kiemTraTrungSoMay(MayTinh[], int, int);         // kiểm tra số máy đã tồn tại

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

void MayTinh::themMayTinh(MayTinh nhieuMay[], int &n, int &soMay) {
    MayTinh mt;
    int soMayTam;
    mt.maMay = taoMaMayTinh(nhieuMay, n);
    string fileName = "../File/maytinh/danhsachmaytinh.txt";
    int x = kiemTraFileTrong(fileName);
    if (x != -1) {
        do {
            cout << "\n(?) Nhập số máy: ";
            cin >> mt.soMay;
            soMayTam = n + 1;
            if (kiemTraTrungSoMay(nhieuMay, n, mt.soMay) != -1) {
                cout << bright_red << "\n\t(!) Số máy đã tồn tại. Xin hãy nhập lại" << reset << "\n";
            } else if (mt.soMay > soMayTam) {
                cout << bright_red << "\n\t(!) Số máy chỉ được lớn hơn số máy lớn nhất hiện tại 1 đơn vị. Xin hãy nhập lại" << reset << "\n";
            }
        } while (kiemTraTrungSoMay(nhieuMay, n, mt.soMay) != -1 || mt.soMay > soMayTam);
    } else {
        do {
            cout << "\n(?) Nhập số máy: ";
            cin >> mt.soMay;
            if (mt.soMay != 1) {
                cout << bright_red << "\n\t(!) Số máy khởi đầu mặc định sẽ là 1. Xin hãy nhập lại" << reset << "\n";
            }
        } while (mt.soMay != 1);
    }
    soMay = mt.soMay;
    do {
        cout << "\n(?) Nhập kiểu máy (0: Thường - 1: Cao cấp): ";
        cin >> mt.kieuMay;
        if (mt.kieuMay < 0 || mt.kieuMay > 1) {
            cout << bright_red << "\n\t(!) Kiểu máy không hợp lệ. Xin hãy nhập lại" << reset << "\n";
        }
    } while (mt.kieuMay < 0 || mt.kieuMay > 1);
    for (int i = n - 1; i >= 0; i--)
        nhieuMay[i + 1] = nhieuMay[i];
    nhieuMay[0] = mt;
    n++;
    cout << bright_green << "\n\t(!) Thêm máy tính thành công" << reset << "\n";
    cout << "\n\t[Nhấn ENTER để tiếp tục...]";
    while (true) {
        int key = _getch();
        if (key == KEY_ENTER)
            break;
    }
}

void MayTinh::xoaMayTinh(MayTinh nhieuMay[], int &n, int &kiemTra) {
    string str;
    cout << "\n(?) Nhập mã máy tính cần xóa: ";
    cin >> str;
    int vitri = kiemTraTrungMaMayTinh(nhieuMay, n, str);
    // Dời
    if (vitri < 0) {
        cout << bright_red << "\n\t(!) Mã máy tính không tồn tại. Xin hãy nhập lại" << reset << "\n";
        kiemTra = 0;
        cout << "\n\t[Nhấn ENTER để tiếp tục...]";
        while (true) {
            int key = _getch();
            if (key == KEY_ENTER)
                break;
        }
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
        cout << bright_green << "\n\t(!) Xóa máy tính thành công" << reset << "\n";
        kiemTra = 1;
        cout << "\n\t[Nhấn ENTER để tiếp tục...]";
        while (true) {
            int key = _getch();
            if (key == KEY_ENTER)
                break;
        }
    }
}

void MayTinh::inMotMayTheoChieuNgang() {
    string loaiKieuMay, tinhTrangMay;
    if (tinhTrang == 1)  // tinhTrang == 1 -> Máy đã có người sử dụng
        tinhTrangMay = "Đầy";
    else  // tinhTrang == 0 -> Máy trống
        tinhTrangMay = "Trống";
    if (kieuMay == 1)  // kieuMay == 1 -> Máy cao cấp
        loaiKieuMay = "Cao cấp";
    else  // kieuMay == 0 -> Máy thường
        loaiKieuMay = "Thường";
    cout << on_bright_blue << setw(10) << left << "| " + maMay << "|" << reset;
    cout << on_bright_blue << setw(10) << left << " " + to_string(soMay) << "|" << reset;
    if (loaiKieuMay == "Thường")
        cout << on_bright_blue << setw(23) << left << " " + loaiKieuMay << "|" << reset;
    else
        cout << on_bright_blue << setw(22) << left << " " + loaiKieuMay << "|" << reset;
    if (tinhTrangMay == "Đầy")
        cout << on_bright_blue << setw(23) << left << " " + tinhTrangMay << "|" << reset;
    else
        cout << on_bright_blue << setw(22) << left << " " + tinhTrangMay << "|" << reset << "\n";
}

void MayTinh::inMotMayTheoChieuNgangCoThoiGian() {
    // Chuyển định dạng giờ, phút, giây, ngày, tháng, năm sang kiểu chuỗi
    string loaiKieuMay, tinhTrangMay;
    string GIOBD = to_string(gioBD);
    string PHUTBD = to_string(phutBD);
    string GIAYBD = to_string(giayBD);
    string NGAYBD = to_string(ngayBD);
    string THANGBD = to_string(thangBD);
    string NAMBD = to_string(namBD);
    // Nếu (ngày, phút, giây, ngày, tháng, năm) < 10 -> Thêm '0' vào đằng trước
    if (GIOBD.length() == 1)
        GIOBD = "0" + GIOBD;
    if (PHUTBD.length() == 1)
        PHUTBD = "0" + PHUTBD;
    if (GIAYBD.length() == 1)
        GIAYBD = "0" + GIAYBD;
    if (NGAYBD.length() == 1)
        NGAYBD = "0" + NGAYBD;
    if (THANGBD.length() == 1)
        THANGBD = "0" + THANGBD;
    if (NAMBD.length() == 1)
        NAMBD = "0" + NAMBD;

    string thoiGian = GIOBD + ":" + PHUTBD + ":" + GIAYBD + " - " + NGAYBD + "/" + THANGBD + "/" + NAMBD;

    if (tinhTrang == 1)  // tinhTrang == 1 -> Máy đã có người sử dụng
        tinhTrangMay = "Đầy";
    else  // tinhTrang == 0 -> Máy trống
        tinhTrangMay = "Trống";
    if (kieuMay == 1)  // kieuMay == 1 -> Máy cao cấp
        loaiKieuMay = "Cao cấp";
    else  // kieuMay == 0 -> Máy thường
        loaiKieuMay = "Thường";

    cout << on_bright_blue << setw(10) << left << "| " + maMay << "|" << reset;
    cout << on_bright_blue << setw(10) << left << " " + to_string(soMay) << "|" << reset;
    if (loaiKieuMay == "Thường")
        cout << on_bright_blue << setw(23) << left << " " + loaiKieuMay << "|" << reset;
    else
        cout << on_bright_blue << setw(22) << left << " " + loaiKieuMay << "|" << reset;
    if (tinhTrangMay == "Đầy")
        cout << on_bright_blue << setw(23) << left << " " + tinhTrangMay << "|" << reset;
    else
        cout << on_bright_blue << setw(22) << left << " " + tinhTrangMay << "|" << reset;

    if (tinhTrang != 0) {
        if (ngayBD != 0 && thangBD != 0 && namBD != 0)
            cout << on_bright_blue << setw(23) << left << " " + thoiGian << "|" << reset;
        else
            cout << on_bright_blue << setw(23) << left << " ";
        cout << "\n";
    } else
        cout << on_bright_blue << setw(23) << left << " "
             << "|" << reset << "\n";
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

void MayTinh::docGiaTien() {
    string fileName = "../File/maytinh/giatien.txt";
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
        while (!fileIn.eof()) {
            fileIn >> giaTienThuong;
            fileIn >> giaTienCaoCap;
        }
    }
    fileIn.close();
}

void MayTinh::ghiGiaTien() {
    string fileName = "../File/maytinh/giatien.txt";
    ofstream fileOut(fileName);
    if (fileOut.fail()) {
        cout << bright_red << "\n\t(!) Không tìm thấy tập tin" << reset << "\n";
        cout << "\n\t[Nhấn ENTER để tiếp tục...]";
        while (true) {
            int key = _getch();
            if (key == KEY_ENTER)
                break;
        }
    } else {
        fflush(stdin);
        fileOut << giaTienThuong << ' ';
        fileOut << giaTienCaoCap;
    }
    fileOut.close();
}

void MayTinh::thietLapGiaTien() {
    cout << on_bright_blue << "\n*--------- GIÁ TIỀN HIỆN TẠI ---------*" << reset << "\n";
    cout << on_bright_blue << setw(17) << left << "| Máy thường:" << reset;
    cout << on_bright_blue << setw(24) << right << to_string(giaTienThuong) + " VND"
         << " |" << reset << "\n";
    cout << on_bright_blue << setw(17) << left << "| Máy cao cấp:" << reset;
    cout << on_bright_blue << setw(23) << right << to_string(giaTienCaoCap) + " VND"
         << " |" << reset;
    cout << on_bright_blue << "\n*-------------------------------------*" << reset << "\n";
    cout << "\n(?) Nhập giá tiền máy thường / 1 giờ: ";
    cin >> giaTienThuong;
    cout << "\n(?) Nhập giá tiền máy cao cấp / 1 giờ: ";
    cin >> giaTienCaoCap;
    cout << bright_green << "\n\t(!) Thiết lập giá tiền thành công" << reset << "\n";
    ghiGiaTien();
}