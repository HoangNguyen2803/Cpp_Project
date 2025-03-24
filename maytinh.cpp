#include <iostream>
#include <stdexcept> // De su dung exception khi chia cho 0

class Calculator {
public:
    // Phep cong
    double add(double a, double b) {
        return a + b;
    }

    // Phep tru
    double subtract(double a, double b) {
        return a - b;
    }

    // Phep nhan
    double multiply(double a, double b) {
        return a * b;
    }

    // Phep chia
    double divide(double a, double b) {
        if (b == 0) {
            throw std::invalid_argument("Loi: Chia cho 0 khong duoc.");
        }
        return a / b;
    }
};

int main() {
    Calculator calc;
    double num1, num2;
    int choice;

    do {
        // Menu cho nguoi dung chon
        std::cout << "\nHe thong may tinh don gian\n";
        std::cout << "1. Cong\n";
        std::cout << "2. Tru\n";
        std::cout << "3. Nhan\n";
        std::cout << "4. Chia\n";
        std::cout << "5. Thoat\n";
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;

        if (choice == 5) break;

        // Lay so dau vao tu nguoi dung
        std::cout << "Nhap so thu nhat: ";
        std::cin >> num1;
        std::cout << "Nhap so thu hai: ";
        std::cin >> num2;

        try {
            switch (choice) {
                case 1:
                    std::cout << "Ket qua: " << calc.add(num1, num2) << std::endl;
                    break;
                case 2:
                    std::cout << "Ket qua: " << calc.subtract(num1, num2) << std::endl;
                    break;
                case 3:
                    std::cout << "Ket qua: " << calc.multiply(num1, num2) << std::endl;
                    break;
                case 4:
                    std::cout << "Ket qua: " << calc.divide(num1, num2) << std::endl;
                    break;
                default:
                    std::cout << "Lua chon khong hop le, vui long thu lai.\n";
            }
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;  // Hien thi loi chia cho 0
        }

    } while (true);

    std::cout << "Thoat khoi may tinh...\n";
    return 0;
}

