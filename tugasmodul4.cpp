#include <iostream>
#include <string>
#include <vector>


struct User {
    std::string username;
    std::string password;
    std::string role;
};


std::vector<User> users = {
    {"admin", "admin123", "superadmin"},
    {"user", "user123", "user"}
};


bool authenticate(const std::string& username, const std::string& password, std::string& role) {
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            role = user.role;
            return true;
        }
    }
    return false;
}

int main() {
    std::string username, password;
    std::string role;

    std::cout << "Masukkan username: ";
    std::cin >> username;

    std::cout << "Masukkan password: ";
    std::cin >> password;

    if (authenticate(username, password, role)) {
        std::cout << "Login berhasil sebagai " << role << ".\n";
        if (role == "superadmin") {
            std::string option;
            std::cout << "Apakah Anda ingin menambahkan pengguna baru? (yes/no): ";
            std::cin >> option;
            if (option == "yes") {
                std::string newUsername, newPassword, newRole;
                std::cout << "Masukkan username baru: ";
                std::cin >> newUsername;
                std::cout << "Masukkan password baru: ";
                std::cin >> newPassword;
                std::cout << "Masukkan peran baru (superadmin/user): ";
                std::cin >> newRole;
                users.push_back({newUsername, newPassword, newRole});
                std::cout << "Pengguna baru ditambahkan.\n";
            }
        }
    } else {
        std::cout << "Login gagal. Periksa kembali username dan password Anda.\n";
    }

    return 0;
}
