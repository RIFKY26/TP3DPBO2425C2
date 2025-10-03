// Main.java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Buat restoran
        Restoran resto = new Restoran("Warung Mantap", "Jl. Kenangan No. 10", "10:00 - 22:00");

        // Tambahkan menu awal
        resto.tambahMenu(new Makanan("Nasi Goreng", 20000, "M01", "Nasi goreng spesial", "Sedang", "Indonesia"));
        resto.tambahMenu(new Makanan("Ayam Bakar", 25000, "M02", "Ayam bakar madu", "Tidak Pedas", "Indonesia"));
        resto.tambahMenu(new Minuman("Es Teh", 5000, "N01", "Teh manis dingin", "Besar", "Dingin"));
        resto.tambahMenu(new Minuman("Kopi Hitam", 10000, "N02", "Kopi hitam robusta", "Kecil", "Panas"));
        
        // Tampilkan menu sebelum penambahan
        System.out.println("\n--- Menu Awal ---");
        resto.tampilkanMenu();

        // Tambah menu baru
        while (true) {
            System.out.println("\n--- Tambah Menu Baru ---");
            System.out.print("Tambah Makanan (1), Minuman (2), atau Selesai (0)? ");
            String pilihan = scanner.nextLine();

            if (pilihan.equals("1")) {
                System.out.print("Nama Makanan: ");
                String nama = scanner.nextLine();
                System.out.print("Harga: ");
                int harga = scanner.nextInt(); scanner.nextLine();
                System.out.print("Kode Menu: ");
                String kode = scanner.nextLine();
                System.out.print("Deskripsi: ");
                String desk = scanner.nextLine();
                System.out.print("Tingkat Pedas: ");
                String pedas = scanner.nextLine();
                System.out.print("Jenis Masakan: ");
                String jenis = scanner.nextLine();
                resto.tambahMenu(new Makanan(nama, harga, kode, desk, pedas, jenis));

            } else if (pilihan.equals("2")) {
                System.out.print("Nama Minuman: ");
                String nama = scanner.nextLine();
                System.out.print("Harga: ");
                int harga = scanner.nextInt(); scanner.nextLine();
                System.out.print("Kode Menu: ");
                String kode = scanner.nextLine();
                System.out.print("Deskripsi: ");
                String desk = scanner.nextLine();
                System.out.print("Ukuran (Kecil/Sedang/Besar): ");
                String ukuran = scanner.nextLine();
                System.out.print("Suhu (Panas/Dingin): ");
                String suhu = scanner.nextLine();
                resto.tambahMenu(new Minuman(nama, harga, kode, desk, ukuran, suhu));

            } else if (pilihan.equals("0")) {
                break;
            } else {
                System.out.println("Pilihan tidak valid!");
            }
        }

        // Tampilkan menu setelah penambahan
        System.out.println("\n--- Menu Setelah Penambahan ---");
        resto.tampilkanMenu();
        
        scanner.close();
    }
}