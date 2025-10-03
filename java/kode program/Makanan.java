// Makanan.java
public class Makanan extends Menu {
    private String pedas;
    private String jenisMasakan;

    public Makanan(String nama, int harga, String kodeMenu, String deskripsi, String pedas, String jenisMasakan) {
        // Memanggil constructor dari superclass (Menu)
        super(nama, harga, kodeMenu, deskripsi);
        this.pedas = pedas;
        this.jenisMasakan = jenisMasakan;
    }

    // Getter untuk atribut spesifik Makanan
    public String getPedas() { return pedas; }
    public String getJenisMasakan() { return jenisMasakan; }

    @Override
    public void tampilkanDetail() {
        System.out.printf("[%s] %s - Rp%,d\n", this.kodeMenu, this.nama, this.harga);
        System.out.printf("    Deskripsi: %s\n", this.deskripsi);
        System.out.printf("    Info: Pedas level %s, Jenis: %s\n", this.pedas, this.jenisMasakan);
    }
}