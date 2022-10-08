#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iomanip>
#include <iostream>

using namespace std;

struct MayTinh {
    int soMay;
    char kieuMay[10];
    bool tinhTrang;
};

void inMotMayTheoChieuNgang(MayTinh maytinh);
void removeEnterChar(char *s);
void docMotMay(FILE *fileIn, MayTinh &maytinh);
void ghiMotMay(FILE *fileOut, MayTinh maytinh);

void inMotMayTheoChieuNgang(MayTinh maytinh) {
    char tinhTrangMay[20];
    if (maytinh.tinhTrang == 1)
        strcpy(tinhTrangMay, "Day");
    else
        strcpy(tinhTrangMay, "Trong");
    cout << setw(10) << left << maytinh.soMay << "\t";
    cout << setw(20) << left << maytinh.kieuMay << "\t";
    cout << setw(20) << left << tinhTrangMay << "\t"
         << "\n";
}

void removeEnterChar(char *s) {
    size_t length = strlen(s);
    if (s[length - 1] == '\n')
        s[length - 1] = '\0';
}

void docMotMay(FILE *fileIn, MayTinh &maytinh) {
    fscanf(fileIn, "%d", &maytinh.soMay);
    fgetc(fileIn);
    fgets(maytinh.kieuMay, sizeof(maytinh.kieuMay), fileIn);
    removeEnterChar(maytinh.kieuMay);
    fscanf(fileIn, "%d", &maytinh.tinhTrang);
}

void ghiMotMay(FILE *fileOut, MayTinh maytinh) {
    fprintf(fileOut, "\n%d", maytinh.soMay);
    fprintf(fileOut, "\n%s", maytinh.kieuMay);
    fprintf(fileOut, "\n%d", maytinh.tinhTrang);
}