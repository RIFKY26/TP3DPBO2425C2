#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>
#include <limits>

class Menu {
protected:
    std::string nama;
    int harga;
    std::string kodeMenu;
    std::string deskripsi;
public:
    Menu(std::string nama, int harga, std::string kodeMenu, std::string deskripsi)
        : nama(nama), harga(harga), kodeMenu(kodeMenu), deskripsi(deskripsi) {}
    virtual ~Menu() = default;
    std::string getNama() const { return nama; }
    int getHarga() const { return harga; }
    std::string getKodeMenu() const { return kodeMenu; }
    std::string getDeskripsi() const { return deskripsi; }
    virtual void tampilkanDetail() const = 0;
};

class Makanan : public Menu {
private:
    std::string pedas;
    std::string jenisMasakan;
public:
    Makanan(std::string nama, int harga, std::string kodeMenu, std::string deskripsi, std::string pedas, std::string jenisMasakan)
        : Menu(nama, harga, kodeMenu, deskripsi), pedas(pedas), jenisMasakan(jenisMasakan) {}
    std::string getPedas() const { return pedas; }
    std::string getJenisMasakan() const { return jenisMasakan; }
    void tampilkanDetail() const override {
        std::cout << "[" << kodeMenu << "] " << nama << " - Rp" << harga << std::endl;
        std::cout << "    Deskripsi: " << deskripsi << std::endl;
        std::cout << "    Info: Pedas level " << pedas << ", Jenis: " << jenisMasakan << std::endl;
    }
};

class Minuman : public Menu {
private:
    std::string ukuran;
    std::string suhu;
public:
    Minuman(std::string nama, int harga, std::string kodeMenu, std::string deskripsi, std::string ukuran, std::string suhu)
        : Menu(nama, harga, kodeMenu, deskripsi), ukuran(ukuran), suhu(suhu) {}
    std::string getUkuran() const { return ukuran; }
    std::string getSuhu() const { return suhu; }
    void tampilkanDetail() const override {
        std::cout << "[" << kodeMenu << "] " << nama << " - Rp" << harga << std::endl;
        std::cout << "    Deskripsi: " << deskripsi << std::endl;
        std::cout << "    Info: Ukuran " << ukuran << ", Suhu: " << suhu << std::endl;
    }
};

class Restoran {
private:
    std::string nama;
    std::string alamat;
    std::string jamOperasional;
    std::vector<std::shared_ptr<Menu>> menuList;

public:
    Restoran(std::string nama, std::string alamat, std::string jamOperasional)
        : nama(nama), alamat(alamat), jamOperasional(jamOperasional) {}

    void tambahMenu(std::shared_ptr<Menu> menu) {
        menuList.push_back(menu);
    }

    void tampilkanMenu() const {
        std::cout << std::string(60, '=') << std::endl;
        std::cout << "Selamat Datang di Restoran " << nama << std::endl;
        std::cout << "Alamat: " << alamat << " | Buka: " << jamOperasional << std::endl;
        std::cout << std::string(60, '=') << std::endl;

        if (menuList.empty()) {
            std::cout << "\nBelum ada menu yang terdaftar." << std::endl;
            return;
        }

        // Header Tabel
        std::cout << "\n" << std::string(125, '-') << std::endl;
        std::cout << "| " << std::left << std::setw(5) << "KODE"
                  << "| " << std::setw(20) << "NAMA MENU"
                  << "| " << std::right << std::setw(12) << "HARGA" << std::left
                  << " | " << std::setw(10) << "KATEGORI"
                  << "| " << std::setw(35) << "DETAIL"
                  << "| " << std::setw(25) << "DESKRIPSI" << " |" << std::endl;
        std::cout << std::string(125, '-') << std::endl;

        // Body Tabel
        for (const auto& menu : menuList) {
            std::string kategori, detail;
            
            if (auto m = std::dynamic_pointer_cast<Makanan>(menu)) {
                kategori = "Makanan";
                detail = "Pedas: " + m->getPedas() + ", Jenis: " + m->getJenisMasakan();
            } else if (auto m = std::dynamic_pointer_cast<Minuman>(menu)) {
                kategori = "Minuman";
                detail = "Ukuran: " + m->getUkuran() + ", Suhu: " + m->getSuhu();
            }
            
            // --- PERBAIKAN DI SINI ---
            // 1. Buat string harga yang lengkap terlebih dahulu
            std::string hargaStr = "Rp " + std::to_string(menu->getHarga());

            // 2. Cetak semua dengan std::left untuk kolom setelah harga
            std::cout << "| " << std::left << std::setw(5) << menu->getKodeMenu()
                      << "| " << std::setw(20) << menu->getNama()
                      // 3. Cetak string harga yang sudah jadi dengan std::right
                      << "| " << std::right << std::setw(12) << hargaStr << std::left
                      << " | " << std::setw(10) << kategori
                      << "| " << std::setw(35) << detail
                      << "| " << std::setw(25) << menu->getDeskripsi() << " |" << std::endl;
        }
        std::cout << std::string(125, '-') << std::endl;
    }
};

int main() {
    Restoran resto("Warung Mantap", "Jl. Kenangan No. 10", "10:00 - 22:00");

    resto.tambahMenu(std::make_shared<Makanan>("Nasi Goreng", 20000, "M01", "Nasi goreng spesial", "Sedang", "Indonesia"));
    resto.tambahMenu(std::make_shared<Makanan>("Ayam Bakar", 25000, "M02", "Ayam bakar madu", "Tidak Pedas", "Indonesia"));
    resto.tambahMenu(std::make_shared<Minuman>("Es Teh", 5000, "N01", "Teh manis dingin", "Besar", "Dingin"));
    resto.tambahMenu(std::make_shared<Minuman>("Kopi Hitam", 10000, "N02", "Kopi hitam robusta", "Kecil", "Panas"));
    
    std::cout << "\n--- Menu Awal ---" << std::endl;
    resto.tampilkanMenu();

    std::string pilihan;
    while (true) {
        std::cout << "\n--- Tambah Menu Baru ---" << std::endl;
        std::cout << "Tambah Makanan (1), Minuman (2), atau Selesai (0)? ";
        std::getline(std::cin, pilihan);

        if (pilihan == "1") {
            std::string nama, kode, desk, pedas, jenis;
            int harga;
            std::cout << "Nama Makanan: "; std::getline(std::cin, nama);
            std::cout << "Harga: "; std::cin >> harga; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Kode Menu: "; std::getline(std::cin, kode);
            std::cout << "Deskripsi: "; std::getline(std::cin, desk);
            std::cout << "Tingkat Pedas: "; std::getline(std::cin, pedas);
            std::cout << "Jenis Masakan: "; std::getline(std::cin, jenis);
            resto.tambahMenu(std::make_shared<Makanan>(nama, harga, kode, desk, pedas, jenis));
        } else if (pilihan == "2") {
            std::string nama, kode, desk, ukuran, suhu;
            int harga;
            std::cout << "Nama Minuman: "; std::getline(std::cin, nama);
            std::cout << "Harga: "; std::cin >> harga; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Kode Menu: "; std::getline(std::cin, kode);
            std::cout << "Deskripsi: "; std::getline(std::cin, desk);
            std::cout << "Ukuran (Kecil/Sedang/Besar): "; std::getline(std::cin, ukuran);
            std::cout << "Suhu (Panas/Dingin): "; std::getline(std::cin, suhu);
            resto.tambahMenu(std::make_shared<Minuman>(nama, harga, kode, desk, ukuran, suhu));
        } else if (pilihan == "0") {
            break;
        } else {
            std::cout << "Pilihan tidak valid!" << std::endl;
        }
    }

    std::cout << "\n--- Menu Setelah Penambahan ---" << std::endl;
    resto.tampilkanMenu();

    return 0;
}