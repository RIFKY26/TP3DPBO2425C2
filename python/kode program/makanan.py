# makanan.py

from menu import Menu

class Makanan(Menu):
    def __init__(self, nama, harga, kode_menu, deskripsi, pedas, jenis_masakan):
        super().__init__(nama, harga, kode_menu, deskripsi)
        self.pedas = pedas  # Tingkat kepedasan
        self.jenis_masakan = jenis_masakan

    def tampilkan(self):
        # Memanggil metode tampilkan dari parent class dan menambahkan info spesifik
        super().tampilkan()
        print(f"    Info: Pedas level {self.pedas}, Jenis: {self.jenis_masakan}")