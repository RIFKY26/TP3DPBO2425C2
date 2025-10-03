# main.py

from restoran import Restoran
from makanan import Makanan
from minuman import Minuman

def main():
    # Buat restoran dengan atribut baru
    resto = Restoran("Warung Mantap", "Jl. Kenangan No. 10", "10:00 - 22:00")

    # Tambahkan menu awal (statis) dengan atribut baru
    resto.tambah_menu(Makanan("Nasi Goreng", 20000, "M01", "Nasi goreng spesial", "Sedang", "Indonesia"))
    resto.tambah_menu(Makanan("Ayam Bakar", 25000, "M02", "Ayam bakar madu", "Tidak Pedas", "Indonesia"))
    resto.tambah_menu(Minuman("Es Teh", 5000, "N01", "Teh manis dingin", "Besar", "Dingin"))
    resto.tambah_menu(Minuman("Kopi Hitam", 10000, "N02", "Kopi hitam robusta", "Kecil", "Panas"))

    # Tampilkan menu sebelum penambahan
    print("\n--- Menu Awal ---")
    resto.tampilkan_menu()

    # Tambah menu baru (dinamis)
    while True:
        print("\n--- Tambah Menu Baru ---")
        pilihan = input("Tambah Makanan (1), Minuman (2), atau Selesai (0)? ")

        if pilihan == "1":
            nama = input("Nama Makanan: ")
            harga = int(input("Harga: "))
            kode = input("Kode Menu: ")
            desk = input("Deskripsi: ")
            pedas = input("Tingkat Pedas: ")
            jenis = input("Jenis Masakan: ")
            resto.tambah_menu(Makanan(nama, harga, kode, desk, pedas, jenis))

        elif pilihan == "2":
            nama = input("Nama Minuman: ")
            harga = int(input("Harga: "))
            kode = input("Kode Menu: ")
            desk = input("Deskripsi: ")
            ukuran = input("Ukuran (Kecil/Sedang/Besar): ")
            suhu = input("Suhu (Panas/Dingin): ")
            resto.tambah_menu(Minuman(nama, harga, kode, desk, ukuran, suhu))

        elif pilihan == "0":
            break

        else:
            print("Pilihan tidak valid!")

    # Tampilkan menu setelah penambahan
    print("\n--- Menu Setelah Penambahan ---")
    resto.tampilkan_menu()

if __name__ == "__main__":
    main()