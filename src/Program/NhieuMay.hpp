#pragma once
#include "MotMay.hpp"

void docDanhSachCacMay(MayTinh[], int &);                        // đọc danh sách các máy
void ghiDanhSachCacMay(MayTinh[], int &);                        // ghi danh sách các máy
MayTinh *layViTriCuaMay(MayTinh[], int, int);                    // lấy vị trí của máy
void xuatDanhSachCacMay(MayTinh[], int);                         // xuất danh sách các máy (cả trống và đã được sử dụng)
void xuatDanhSachCacMayDay(MayTinh[], int);                      // xuất danh sách các máy đã được sử dụng
void xuatDanhSachCacMayTrong(MayTinh[], int);                    // xuất danh sách các máy trống
void sapXepDanhSachMayTinh(MayTinh[], int &);                    // sắp xếp danh sách máy tính tăng dần theo số máy
void sapXepDanhSachMayTinh_MergeSort(MayTinh[], int, int, int);  // thuật toán sắp xếp mergeSort
void mergeSort(MayTinh[], int, int);                             // thuật toán sắp xếp mergeSort
bool kiemTraHetMay(MayTinh[], int);                              // kiểm tra hết máy
bool kiemTraTrangThai(MayTinh[], int);                           // kiểm tra trạng thái
bool kiemTraSoMay(MayTinh[], int, int);                          // kiểm tra máy còn trống hay đã được sử dụng
bool kiemTraSoMayCanThanhToan(MayTinh[], int, int);              // kiểm tra số máy cần thanh toán

void docDanhSachCacMay(MayTinh nhieuMay[], int &n) {
    string fileName = "../File/maytinh/danhsachmaytinh.txt";
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
        n = 0;
        while (!fileIn.eof()) {
            MayTinh mt;
            mt.docMotMay(fileIn);
            nhieuMay[n++] = mt;  // đưa máy vừa đọc vào mảng
        }
    }
    fileIn.close();
}

void ghiDanhSachCacMay(MayTinh nhieuMay[], int &n) {
    string fileName = "../File/maytinh/danhsachmaytinh.txt";
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
        for (int i = 0; i < n; i++) {
            fflush(stdin);
            nhieuMay[i].ghiMotMay(fileOut);
            if (i != n - 1)
                fileOut << endl;
        }
    }
    fileOut.close();
}

MayTinh *layViTriCuaMay(MayTinh nhieuMay[], int n, int soMay) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].soMay == soMay)
            return &nhieuMay[i];
    return NULL;
}

void xuatDanhSachCacMay(MayTinh nhieuMay[], int n) {
    if (n != 0) {
        cout << on_bright_blue << "*---------*----------*--------------------*--------------------*-----------------------*" << reset << "\n";
        cout << on_bright_blue << setw(12) << left << "| Mã máy"
             << "|" << reset;
        cout << on_bright_blue << setw(13) << left << " Số máy"
             << "|" << reset;
        cout << on_bright_blue << setw(23) << left << " Kiểu máy"
             << "|" << reset;
        cout << on_bright_blue << setw(23) << left << " Tình trạng"
             << "|" << reset;
        cout << on_bright_blue << setw(30) << left << " Thời gian bắt đầu"
             << "|" << reset << "\n";
        cout << on_bright_blue << "*---------*----------*--------------------*--------------------*-----------------------*\n";
        for (int i = 0; i < n; i++)
            nhieuMay[i].inMotMayTheoChieuNgangCoThoiGian();
        cout << on_bright_blue << "*---------*----------*--------------------*--------------------*-----------------------*" << reset << "\n";
    } else
        cout << bright_red << "\n\t(!) Danh sách máy tính trống" << reset << "\n";
}

void xuatDanhSachCacMayDay(MayTinh nhieuMay[], int n) {
    if (n != 0) {
        // nếu không có máy nào được bật
        if (!kiemTraTrangThai(nhieuMay, n))
            cout << bright_red << "\n\t(!) Không có máy đang được sử dụng" << reset << "\n";
        else {
            cout << on_bright_blue << "*---------*----------*--------------------*--------------------*-----------------------*" << reset << "\n";
            cout << on_bright_blue << setw(12) << left << "| Mã máy"
                 << "|" << reset;
            cout << on_bright_blue << setw(13) << left << " Số máy"
                 << "|" << reset;
            cout << on_bright_blue << setw(23) << left << " Kiểu máy"
                 << "|" << reset;
            cout << on_bright_blue << setw(23) << left << " Tình trạng"
                 << "|" << reset;
            cout << on_bright_blue << setw(30) << left << " Thời gian bắt đầu"
                 << "|" << reset << "\n";
            cout << on_bright_blue << "*---------*----------*--------------------*--------------------*-----------------------*" << reset << "\n";
            for (int i = 0; i < n; i++)
                if (nhieuMay[i].tinhTrang == 1)
                    nhieuMay[i].inMotMayTheoChieuNgangCoThoiGian();
            cout << on_bright_blue << "*---------*----------*--------------------*--------------------*-----------------------*" << reset << "\n";
        }
    } else
        cout << bright_red << "\n\t(!) Danh sách máy tính trống" << reset << "\n";
}

void xuatDanhSachCacMayTrong(MayTinh nhieuMay[], int n) {
    if (n != 0) {
        // nếu hết máy
        if (kiemTraHetMay(nhieuMay, n))
            cout << bright_red << "\n\t(!) Hết máy" << reset << "\n";
        else {
            cout << on_bright_blue << "*---------*----------*--------------------*--------------------*" << reset << "\n";
            cout << on_bright_blue << setw(12) << left << "| Mã máy"
                 << "|" << reset;
            cout << on_bright_blue << setw(13) << left << " Số máy"
                 << "|" << reset;
            cout << on_bright_blue << setw(23) << left << " Kiểu máy"
                 << "|" << reset;
            cout << on_bright_blue << setw(23) << left << " Tình trạng"
                 << "|" << reset << "\n";
            cout << on_bright_blue << "*---------*----------*--------------------*--------------------*" << reset << "\n";
            for (int i = 0; i < n; i++)
                if (nhieuMay[i].tinhTrang == 0)
                    nhieuMay[i].inMotMayTheoChieuNgang();
            cout << on_bright_blue << "*---------*----------*--------------------*--------------------*" << reset << "" << reset << "\n";
        }
    } else
        cout << bright_red << "\n\t(!) Danh sách máy tính trống" << reset << "\n";
}

void sapXepDanhSachMayTinh(MayTinh nhieuMay[], int &n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (nhieuMay[i].soMay > nhieuMay[j].soMay) {
                MayTinh tam = nhieuMay[i];
                nhieuMay[i] = nhieuMay[j];
                nhieuMay[j] = tam;
            }
}

// Thuật toán MergeSort
void merge(MayTinh nhieuMay[], int l, int m, int r) {
    vector<MayTinh> x(nhieuMay + l, nhieuMay + m + 1);
    vector<MayTinh> y(nhieuMay + m + 1, nhieuMay + r + 1);
    int i = 0, j = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i].soMay <= y[j].soMay) {
            nhieuMay[l] = x[i];
            ++l;
            ++i;
        } else {
            nhieuMay[l] = y[j];
            ++l;
            ++j;
        }
    }
    while (i < x.size()) {
        nhieuMay[l] = x[i];
        ++l;
        ++i;
    }
    while (j < y.size()) {
        nhieuMay[l] = y[j];
        ++l;
        ++j;
    }
}

void sapXepDanhSachMayTinh_MergeSort(MayTinh nhieuMay[], int l, int r) {
    if (l >= r)
        return;
    int m = (l + r) / 2;
    sapXepDanhSachMayTinh_MergeSort(nhieuMay, l, m);
    sapXepDanhSachMayTinh_MergeSort(nhieuMay, m + 1, r);
    merge(nhieuMay, l, m, r);
}

bool kiemTraHetMay(MayTinh nhieuMay[], int n) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].tinhTrang == 0)  // còn máy trống -> thì trả về false
            return false;
    return true;
}

bool kiemTraTrangThai(MayTinh nhieuMay[], int n) {
    bool kiemTra = false;
    for (int i = 0; i < n; i++) {
        if (nhieuMay[i].tinhTrang == 1) {
            kiemTra = true;
            break;
        }
    }
    return kiemTra;
}

bool kiemTraSoMay(MayTinh nhieuMay[], int n, int soMay) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].soMay == soMay && nhieuMay[i].tinhTrang == 0)
            return true;
    return false;
}

bool kiemTraSoMayCanThanhToan(MayTinh nhieuMay[], int n, int soMay) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].soMay == soMay && nhieuMay[i].tinhTrang == 1)
            return true;
    return false;
}