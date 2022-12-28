#pragma once
#include "ThueMotMay.hpp"
#include "ThueNhieuMay.hpp"

struct Node {
    ThueMotMay data;
    Node *pNext;
};

class ThueNhieuMay {
   public:
    Node *pHead;
    Node *pTail;
    void taoListThueMotMay();          // tạo List
    void themNodeVaoCuoi(ThueMotMay);  // thêm Node vào cuối
    void xoaNodeDauTien();             // xóa Node đầu tiên
    void xoaNodeCuoiCung();            // xóa Node cuối cùng
    void giaiPhongDanhSachNguoiThueTrucTiep();
    void moMayTrucTiep(MayTinh[], int);  // mở máy trực tiếp
    void thanhToan(MayTinh[], int);      // thanh toán
};

Node *taoNodeThueMotMay(ThueMotMay);                                  // tạo Node
void sapXepDanhSachNguoiThueTheoSoMay(ThueNhieuMay &);                // sắp xếp danh sách người thuê theo số máy
void docDanhSachNguoiThueTrucTiep(ThueNhieuMay &, MayTinh[], int &);  // đọc danh sách người thuê trực tiếp từ file
void ghiDanhSachNguoiThueTrucTiep(ThueNhieuMay, int);                 // ghi danh sách người thuê trực tiếp ra file
int tinhSoNgayGiuaHaiMocThoiGian(int, int, int, int, int, int);       // tính số ngày sử dụng

void ThueNhieuMay::taoListThueMotMay() {
    pHead = NULL;
    pTail = NULL;
}

Node *taoNodeThueMotMay(ThueMotMay thueMotMay) {
    Node *p = new Node;
    if (p == NULL) {
        cout << bright_red << "\n\t(!) Không đủ bộ nhớ" << reset << "\n";
        return NULL;
    } else {
        p->data = thueMotMay;
        p->pNext = NULL;
    }
    return p;
}

void ThueNhieuMay::themNodeVaoCuoi(ThueMotMay thueMotMay) {
    Node *p = taoNodeThueMotMay(thueMotMay);
    if (pHead == NULL)
        pHead = pTail = p;
    else {
        pTail->pNext = p;
        pTail = p;
    }
}

void ThueNhieuMay::xoaNodeDauTien() {
    if (pHead == NULL)  // không có phần tử nào
        return;
    else {
        Node *p = pHead;
        pHead = p->pNext;
        delete p;
    }
}

void ThueNhieuMay::xoaNodeCuoiCung() {
    if (pHead == NULL)
        return;
    // nếu phần tử nằm đầu cũng là phần tử nằm cuối
    else if (pHead == pTail)
        xoaNodeDauTien();
    else {
        for (Node *t = pHead; t != NULL; t = t->pNext) {
            if (t->pNext == pTail) {
                delete pTail;
                t->pNext = NULL;
                pTail = t;
                return;
            }
        }
    }
}

void ThueNhieuMay::giaiPhongDanhSachNguoiThueTrucTiep() {
    Node *t = NULL;
    while (pHead != NULL) {
        t = pHead;
        pHead = pHead->pNext;
        delete t;
    }
}

void sapXepDanhSachNguoiThueTheoSoMay(ThueNhieuMay &thueNhieuMay) {
    for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
        Node *minIndex = t;
        for (Node *g = t->pNext; g != NULL; g = g->pNext)
            if (minIndex->data.maytinh->soMay > g->data.maytinh->soMay)
                minIndex = g;
        if (minIndex != t)
            swap(t->data, minIndex->data);
    }
}

void ThueNhieuMay::moMayTrucTiep(MayTinh nhieuMay[], int n) {
    if (n != 0) {
        if (kiemTraHetMay(nhieuMay, n)) {  // nếu hết máy
            system("cls");
            cout << bright_red << "\n\t(!) Hết máy" << reset << "\n";
        } else {
            int gioBD = 0, phutBD = 0, giayBD = 0, ngayBD = 0, thangBD = 0, namBD = 0;
            ThueMotMay r;
            r.chonMay(nhieuMay, n);
            r.maytinh->tinhTrang = 1;  // cập nhật lại tình trạng máy -> 1 (máy đã có người sử dụng)
            layThoiGianHeThong(gioBD, phutBD, giayBD, ngayBD, thangBD, namBD);
            r.maytinh->gioBD = gioBD;
            r.maytinh->phutBD = phutBD;
            r.maytinh->giayBD = giayBD;
            r.maytinh->ngayBD = ngayBD;
            r.maytinh->thangBD = thangBD;
            r.maytinh->namBD = namBD;
            cout << bright_green << "\n\t(!) Mở máy thành công" << reset << "\n";
            cout << "\n\t[Nhấn ENTER để tiếp tục...]";
            while (true) {
                int key = _getch();
                if (key == KEY_ENTER)
                    break;
            }
        }
    } else {
        cout << bright_red << "\n\t(!) Danh sách máy tính trống" << reset << "\n";
        cout << "\n\t[Nhấn ENTER để tiếp tục...]";
        while (true) {
            int key = _getch();
            if (key == KEY_ENTER)
                break;
        }
    }
}

void docDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int &n) {
    string fileName = "../File/maytinh/momaytructiep.txt";
    ifstream fileIn(fileName);
    n = kiemTraFileTrong(fileName);
    if (fileIn.fail()) {
        cout << bright_red << "\n\t(!) Không tìm thấy tập tin" << reset << "\n";
        cout << "\n\t[Nhấn ENTER để tiếp tục...]";
        while (true) {
            int key = _getch();
            if (key == KEY_ENTER)
                break;
        }
    } else {
        ThueMotMay r;
        int x;
        fileIn >> x;
        fileIn.ignore();
        if (n != -1) {
            for (int i = 0; i < n; i++) {
                r.docMotNguoiThueTrucTiep(fileIn, nhieuMay, n);
                thueNhieuMay.themNodeVaoCuoi(r);
            }
        }
    }
    fileIn.close();
}

void ghiDanhSachNguoiThueTrucTiep(ThueNhieuMay thueNhieuMay, int n) {
    string fileName = "../File/maytinh/momaytructiep.txt";
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
        fileOut << n << endl;
        for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
            t->data.ghiMotNguoiThueTrucTiep(fileOut);
            if (t->pNext != NULL)
                fileOut << endl;
        }
    }
    fileOut.close();
}

void ThueNhieuMay::thanhToan(MayTinh nhieuMay[], int n) {
    if (n != 0) {
        bool kiemTra = kiemTraTrangThai(nhieuMay, n);
        if (kiemTra == true) {
            MayTinh mt;
            ThueMotMay r;
            int gioSD = 0, phutSD = 0, giaySD = 0;
            int gioKT = 0, phutKT = 0, giayKT = 0, ngayKT = 0, thangKT = 0, namKT = 0;
            int soNgay = 0, thoiGian1 = 0, thoiGian2 = 0, tongThoiGian = 0;
            long long thoiGianBatDau = 0, thoiGianKetThuc = 0;
            double soTienMotGiay = 0;
            //
            //
            r.chonMayCanThanhToan(nhieuMay, n);  // hàm này trong file ThueMotMay.hpp
            r.maytinh->tinhTrang = 0;            // cập nhật lại tình trạng máy -> 0 (máy trống)
            //
            //
            // Lấy thời gian kết thúc
            layThoiGianHeThong(gioKT, phutKT, giayKT, ngayKT, thangKT, namKT);
            r.maytinh->gioKT = gioKT;
            r.maytinh->phutKT = phutKT;
            r.maytinh->giayKT = giayKT;
            r.maytinh->ngayKT = ngayKT;
            r.maytinh->thangKT = thangKT;
            r.maytinh->namKT = namKT;
            //
            //
            // Tính khoảng thời gian giữa 2 mốc thời gian
            if (r.maytinh->namBD == r.maytinh->namKT) {
                if (r.maytinh->thangBD == r.maytinh->thangKT) {
                    if (r.maytinh->ngayBD == r.maytinh->ngayKT)
                        thoiGianBatDau = 3600 * r.maytinh->gioBD + 60 * r.maytinh->phutBD + r.maytinh->giayBD;
                    else
                        thoiGianBatDau = 86400 - (3600 * r.maytinh->gioBD + 60 * r.maytinh->phutBD + r.maytinh->giayBD);
                    if (r.maytinh->ngayBD < r.maytinh->ngayKT)
                        thoiGianKetThuc = 3600 * r.maytinh->gioKT + 60 * r.maytinh->phutKT + r.maytinh->giayKT;
                    else {
                        thoiGianKetThuc = thoiGianBatDau - (3600 * r.maytinh->gioKT + 60 * r.maytinh->phutKT + r.maytinh->giayKT);
                        if (thoiGianKetThuc < 0)
                            thoiGianKetThuc = -thoiGianKetThuc;
                    }
                } else {
                    thoiGianBatDau = 86400 - (3600 * r.maytinh->gioBD + 60 * r.maytinh->phutBD + r.maytinh->giayBD);
                    thoiGianKetThuc = 3600 * r.maytinh->gioKT + 60 * r.maytinh->phutKT + r.maytinh->giayKT;
                }
            } else {
                thoiGianBatDau = 86400 - (3600 * r.maytinh->gioBD + 60 * r.maytinh->phutBD + r.maytinh->giayBD);
                thoiGianKetThuc = 3600 * r.maytinh->gioKT + 60 * r.maytinh->phutKT + r.maytinh->giayKT;
            }
            //
            //
            // Tính tổng thời gian đã sử dụng
            soNgay = tinhSoNgayGiuaHaiMocThoiGian(r.maytinh->ngayBD, r.maytinh->thangBD, r.maytinh->namBD, r.maytinh->ngayKT, r.maytinh->thangKT, r.maytinh->namKT);
            thoiGian1 = thoiGianBatDau + (86400 * (soNgay - 1));  // tổng thời gian của ngày bắt đầu + với thời gian của những ngày sử dụng tròn 24 tiếng
            thoiGian2 = thoiGianKetThuc;                          // tổng thời gian của ngày kết thúc
            tongThoiGian = thoiGian1 + thoiGian2;                 // tổng thời gian đã sử dụng
            //
            //
            // Quy đổi tổng thời gian ra giờ, phút, giây
            if (r.maytinh->namBD == r.maytinh->namKT)
                if (r.maytinh->thangBD == r.maytinh->thangKT)
                    if (r.maytinh->ngayBD == r.maytinh->ngayKT)
                        tongThoiGian = thoiGianKetThuc;
            gioSD = tongThoiGian / 3600;
            phutSD = (tongThoiGian % 3600) / 60;
            giaySD = (tongThoiGian % 3600) % 60;
            //
            //
            // Chuyển định dạng giờ, phút, giây, ngày, tháng, năm sang kiểu chuỗi
            string GIOSD = to_string(gioSD);
            string PHUTSD = to_string(phutSD);
            string GIAYSD = to_string(giaySD);
            string GIOBD = to_string(r.maytinh->gioBD);
            string PHUTBD = to_string(r.maytinh->phutBD);
            string GIAYBD = to_string(r.maytinh->giayBD);
            string NGAYBD = to_string(r.maytinh->ngayBD);
            string THANGBD = to_string(r.maytinh->thangBD);
            string NAMBD = to_string(r.maytinh->namBD);
            string GIOKT = to_string(gioKT);
            string PHUTKT = to_string(phutKT);
            string GIAYKT = to_string(giayKT);
            string NGAYKT = to_string(ngayKT);
            string THANGKT = to_string(thangKT);
            string NAMKT = to_string(namKT);
            //
            //
            // Nếu (ngày, phút, giây, ngày, tháng, năm) < 10 -> Thêm '0' vào đằng trước
            if (GIOSD.length() == 1) GIOSD = "0" + GIOSD;
            if (PHUTSD.length() == 1) PHUTSD = "0" + PHUTSD;
            if (GIAYSD.length() == 1) GIAYSD = "0" + GIAYSD;
            if (GIOBD.length() == 1) GIOBD = "0" + GIOBD;
            if (PHUTBD.length() == 1) PHUTBD = "0" + PHUTBD;
            if (GIAYBD.length() == 1) GIAYBD = "0" + GIAYBD;
            if (NGAYBD.length() == 1) NGAYBD = "0" + NGAYBD;
            if (THANGBD.length() == 1) THANGBD = "0" + THANGBD;
            if (NAMBD.length() == 1) NAMBD = "0" + NAMBD;
            if (GIOKT.length() == 1) GIOKT = "0" + GIOKT;
            if (PHUTKT.length() == 1) PHUTKT = "0" + PHUTKT;
            if (GIAYKT.length() == 1) GIAYKT = "0" + GIAYKT;
            if (NGAYKT.length() == 1) NGAYKT = "0" + NGAYKT;
            if (THANGKT.length() == 1) THANGKT = "0" + THANGKT;
            if (NAMKT.length() == 1) NAMKT = "0" + NAMKT;
            //
            //
            string thoiGianSuDung = GIOSD + ":" + PHUTSD + ":" + GIAYSD;
            string thoiGianLucDau = GIOBD + ":" + PHUTBD + ":" + GIAYBD + " - " + NGAYBD + "/" + THANGBD + "/" + NAMBD;
            string thoiGianThanhToan = GIOKT + ":" + PHUTKT + ":" + GIAYKT + " - " + NGAYKT + "/" + THANGKT + "/" + NAMKT;
            //
            //
            mt.docGiaTien();
            r.maytinh->giaTienThuong = mt.giaTienThuong;
            r.maytinh->giaTienCaoCap = mt.giaTienCaoCap;
            if (r.maytinh->kieuMay == 0)
                soTienMotGiay = r.maytinh->giaTienThuong / 3600;
            else
                soTienMotGiay = r.maytinh->giaTienCaoCap / 3600;
            r.maytinh->giaTien = tongThoiGian * soTienMotGiay;
            string giaTien = to_string(r.maytinh->giaTien) + " VND";
            //
            //
            string loaiKieuMay;
            if (r.maytinh->kieuMay == 1)  // kieuMay == 1 -> Máy cao cấp
                loaiKieuMay = "Cao cấp";
            else  // kieuMay == 0 -> Máy thường
                loaiKieuMay = "Thường";
            //
            //
            // Xuất thông tin thanh toán
            system("cls");
            cout << bright_yellow << "\nMENU/THANH TOÁN" << reset << "\n";
            cout << on_bright_blue << "\n*----------------- THÔNG TIN THANH TOÁN ----------------*\n";
            cout << setw(30) << left << "| Số máy: ";
            cout << setw(28) << right << r.maytinh->soMay << " |\n";
            cout << setw(30) << left << "| Kiểu máy: ";
            if (loaiKieuMay == "Thường")
                cout << setw(31) << right << loaiKieuMay << " |\n";
            else
                cout << setw(30) << right << loaiKieuMay << " |\n";
            cout << setw(30) << left << "| Thời gian bắt đầu: ";
            cout << setw(32) << right << thoiGianLucDau << " |\n";
            cout << setw(30) << left << "| Xuất hóa đơn lúc: ";
            cout << setw(31) << right << thoiGianThanhToan << " |\n";
            cout << setw(30) << left << "| Thời gian kết thúc: ";
            cout << setw(30) << right << thoiGianSuDung << " |\n";
            cout << setw(30) << left << "| Số tiền cần thanh toán: ";
            cout << setw(29) << right << giaTien << " |";
            cout << "\n*-------------------------------------------------------*" << reset << "\n";

            int key = 0;
            cout << bright_red << "\n\t(!) Nhấn ENTER để xác nhận hoàn thành thanh toán" << reset << "\n";
            while (true) {
                int key = _getch();
                if (key == KEY_ENTER)
                    break;
            }
            //
            //
            r.maytinh->gioBD = 0;
            r.maytinh->phutBD = 0;
            r.maytinh->giayBD = 0;
            r.maytinh->ngayBD = 0;
            r.maytinh->thangBD = 0;
            r.maytinh->namBD = 0;
            // xoaNodeDauTien();
            //
            //
            // Ghi lịch sử thanh toán ra file
            string fileNameLichSu = "../File/lichsu/lichsuthanhtoan.txt";
            ofstream fileOut(fileNameLichSu, ios::app);
            if (fileOut.fail()) {
                cout << bright_red << "\n\t(!) Không tìm thấy tập tin" << reset << "\n";
                cout << "\n\t[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else {
                fileOut << setw(25) << left << "| " + thoiGianLucDau << "|";
                fileOut << setw(25) << left << " " + thoiGianThanhToan << "|";
                fileOut << setw(10) << left << " " + to_string(r.maytinh->soMay) << "|";
                if (loaiKieuMay == "Thường")
                    fileOut << setw(13) << left << " " + loaiKieuMay << "|";
                else
                    fileOut << setw(12) << left << " " + loaiKieuMay << "|";
                fileOut << setw(20) << right << giaTien + " "
                        << "|\n";
            }
            fileOut.close();
            //
            //
            // Ghi doanh thu ra file
            double doanhThu;
            string fileNameDoanhThu = "../File/doanhthu/" + NGAYKT + "_" + THANGKT + "_" + NAMKT + ".txt";
            fstream docGhiDoanhThu;
            // Đọc doanh thu cũ vào trước
            docGhiDoanhThu.open(fileNameDoanhThu, ios::in);
            docGhiDoanhThu >> doanhThu;
            docGhiDoanhThu.close();
            // Cộng doanh thu mới vào rồi ghi ngược lại vào file
            docGhiDoanhThu.open(fileNameDoanhThu, ios::out);
            doanhThu += (double)r.maytinh->giaTien;
            docGhiDoanhThu << to_string((long long)doanhThu);
            docGhiDoanhThu.close();

            cout << bright_green << "\n\t(!) Thanh toán thành công" << reset << "\n";
            cout << "\n\t[Nhấn ENTER để tiếp tục...]";
            while (true) {
                int key = _getch();
                if (key == KEY_ENTER)
                    break;
            }
        } else {
            cout << bright_red << "\n\t(!) Không có máy đang được sử dụng" << reset << "\n";
            cout << "\n\t[Nhấn ENTER để tiếp tục...]";
            while (true) {
                int key = _getch();
                if (key == KEY_ENTER)
                    break;
            }
        }
    } else {
        cout << bright_red << "\n\t(!) Danh sách máy tính trống" << reset << "\n";
        cout << "\n\t[Nhấn ENTER để tiếp tục...]";
        while (true) {
            int key = _getch();
            if (key == KEY_ENTER)
                break;
        }
    }
}

int tinhSoNgayGiuaHaiMocThoiGian(int ngayBD, int thangBD, int namBD, int ngayKT, int thangKT, int namKT) {
    int soNgay = 0;
    while (namKT >= namBD) {
        if (namKT == namBD && thangKT == thangBD) {
            soNgay += ngayKT - ngayBD;
            break;
        } else {
            // Tháng 4, 6, 9, 11 có 30 ngày
            if (thangBD == 4 || thangBD == 6 || thangBD == 9 || thangBD == 11)
                soNgay += 30 - ngayBD;
            // Tháng 1, 3, 5, 7, 8, 10, 12 có 31 ngày
            if (thangBD == 1 || thangBD == 3 || thangBD == 5 || thangBD == 7 || thangBD == 8 || thangBD == 10 || thangBD == 12)
                soNgay += 31 - ngayBD;
            // Tháng 2 có 28 ngày (trừ năm nhuận có 29 ngày)
            if (thangBD == 2) {
                if ((namBD % 4 == 0) && (namBD % 100 != 0) || (namBD % 400 == 0))
                    soNgay += 29 - ngayBD;
                else
                    soNgay += 28 - ngayBD;
            }
            thangBD++, ngayBD = 0;
            if (thangBD == 13)  // tăng năm lên
                namBD++, thangBD = 1;
        }
    }
    return soNgay;
}