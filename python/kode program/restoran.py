# restoran.py

from makanan import Makanan
from minuman import Minuman

class Restoran:
    def __init__(self, nama, alamat, jam_operasional):
        self.nama = nama
        self.alamat = alamat
        self.jam_operasional = jam_operasional
        self.menu_list = []

    def tambah_menu(self, menu):
        self.menu_list.append(menu)

    def tampilkan_menu(self):
        print("=" * 60)
        print(f"Selamat Datang di Restoran {self.nama}")
        print(f"Alamat: {self.alamat} | Buka: {self.jam_operasional}")
        print("=" * 60)
        
        if not self.menu_list:
            print("\nBelum ada menu yang terdaftar.")
            return

        # Header Tabel disesuaikan agar pas
        print("\n" + "-" * 136)
        print(f"| {'KODE':<5} | {'NAMA MENU':<20} | {'HARGA':>12} | {'KATEGORI':<10} | {'DETAIL':<40} | {'DESKRIPSI':<30} |")
        print("-" * 136)

        # Body Tabel
        for menu in self.menu_list:
            # Mengambil semua atribut langsung dari objek menu
            kode = menu.kode_menu
            nama = menu.nama
            harga = f"Rp {menu.harga:,}"
            deskripsi = menu.deskripsi
            
            kategori = ""
            detail = ""

            # Logika untuk membedakan Makanan dan Minuman
            if isinstance(menu, Makanan):
                kategori = "Makanan"
                detail = f"Pedas: {menu.pedas}, Jenis: {menu.jenis_masakan}"
            elif isinstance(menu, Minuman):
                kategori = "Minuman"
                detail = f"Ukuran: {menu.ukuran}, Suhu: {menu.suhu}"

            # Mencetak satu baris tabel yang sudah rapi
            print(f"| {kode:<5} | {nama:<20} | {harga:>12} | {kategori:<10} | {detail:<40} | {deskripsi:<30} |")

        # Footer Tabel
        print("-" * 136)