#include "menu.hpp"

int main() {
    srand(time(NULL));
    thietLapKichThuocManHinh(120, 30);
    SetConsoleOutputCP(65001);  // Hiển thị giao diện tiếng việt
    chanThayDoiKichThuocManHinh();
    chanNutCtrl(false, false, true);
    anThanhTruot(false);
    menu();
    return 0;
}