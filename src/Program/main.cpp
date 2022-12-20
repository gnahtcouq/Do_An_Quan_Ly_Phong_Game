#include "menu.hpp"

int main() {
    srand(time(NULL));
    SetConsoleOutputCP(65001);  // Hiển thị giao diện tiếng việt
    thietLapKichThuocManHinh(120, 30);
    chanThayDoiKichThuocManHinh();
    chanNutCtrl(false, false, true);
    anThanhTruot(false);
    menu();
    return 0;
}