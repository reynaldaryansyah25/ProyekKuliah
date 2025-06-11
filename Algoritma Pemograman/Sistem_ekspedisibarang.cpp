#include <iostream>
#include <cstdlib> //clearscreen
#include <fstream> //struk
#include <ctime>
#include <string.h>
using namespace std;

// Konstanta untuk biaya dan harga
const float BeratPaket = 3000;
const float BeratBarang = 2000;
const float HargaBerkas = 7000;
const float HargaBarang = 5000;
const float HargaPaket = 6000;

void clearscreeen()
{
    system("cls");
}

void Header()
{
    cout << "+============================================+" << endl;
    cout << "|      EKSPEDISI BARANG NITRO GO EXPRESS     |" << endl;
    cout << "+============================================+" << endl;
    cout << endl;
}

string generateResi()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "NTGE%Y%m%d%H%M%S", ltm);
    return buffer;
}

// enum untuk jenis pembayaran
enum MetodePembayaran
{
    TUNAI,
    KARTU_KREDIT,
};

// struktur data untuk informasi pembayaran
struct Pembayaran
{
    MetodePembayaran metode;
    double jumlah;
};

// struktur untuk menyimpan informasi
struct infologin
{
    string username;
    string password;
};

// Fungsi untuk membuat akun
infologin BuatAkun()
{
    infologin account;
    cout << "===========================================" << endl;
    cout << "              B U A T A K U N              " << endl;
    cout << "===========================================" << endl;
    cout << "     EKSPEDISI BARANG NITRO GO EXPRESS     " << endl;
    cout << "===========================================" << endl;
    cout << "Username: ";
    cin >> account.username;
    cout << "Password: ";
    cin >> account.password;
    return account;
}

// Fungsi untuk login
bool login(const infologin &account)
{
    string username, password;
    int attempts = 3;

    cout << "===========================================" << endl;
    cout << "              SELAMAT DATANG               " << endl;
    cout << "                    DI                     " << endl;
    cout << "===========================================" << endl;
    cout << "     EKSPEDISI BARANG NITRO GO EXPRESS     " << endl;
    cout << "===========================================" << endl;
    cout << "*Silahkan masukan Username dan Password anda untuk melanjutkan!" << endl;
    do
    {
        cout << "\nUsername: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == account.username && password == account.password)
        {
            cout << "\n   ----------Login Berhasil!----------" << endl;
            return true;
        }
        else
        {
            cout << "\n=================================================" << endl;
            cout << "Username atau Password salah. Sisa percobaan: " << attempts - 1 << endl;
            cout << "==================================================" << endl;
            attempts--;
        }

    } while (attempts > 0);
    cout << "\n===============================================================" << endl;
    cout << "Anda telah melebihi batas percobaan login. Program akan keluar." << endl;
    cout << "===============================================================" << endl;
    return false;
}

// Fungsi untuk input data pengirim dan penerima
void inputDataPengiriman(string &NamaPengirim, string &NamaPenerima, string &AlamatPengirim)
{
    cout << "================================" << endl;
    cout << "Tanggal Pengiriman     : " << __DATE__ << endl;
    cout << "Nama Pengirim          : ";
    cin >> NamaPengirim;
    cout << "Alamat Pengirim        : ";
    cin >> AlamatPengirim;
    cout << "Nama Penerima          : ";
    cin >> NamaPenerima;
    cout << "================================" << endl;
    cout << endl;
}

// Fungsi untuk memilih kota tujuan
void pilihKotaTujuan(float &jarak, string &kota)
{
    int pilih;

pertama:
    cout << "======================" << endl;
    cout << ": Pilih Kota Tujuan  :" << endl;
    cout << "======================" << endl;
    cout << ": 1. Palembang       :" << endl;
    cout << ": 2. Bali            :" << endl;
    cout << ": 3. Tangerang       :" << endl;
    cout << "======================" << endl;
    cout << "Pilihan : ";
    cin >> pilih;
    cout << endl;

    if (pilih == 1)
    {
        jarak = 7000;
        kota = "Palembang";
    }
    else if (pilih == 2)
    {
        jarak = 5000;
        kota = "Bali";
    }
    else if (pilih == 3)
    {
        jarak = 3000;
        kota = "Tangerang";
    }
    else
    {
        cout << "Pilihan Tidak Tersedia" << endl;
        cout << "Silahkan Pilih Kembali" << endl;
        cout << endl;
        goto pertama;
    }
}

// Fungsi untuk memilih jenis pengiriman
void pilihJenisPengiriman(float &harga, int &x, float jarak)
{
    int pilihan;
    float berat, jumlah;

kedua:
    cout << "===========================" << endl;
    cout << ": Pilih Jenis Pengiriman  :" << endl;
    cout << "===========================" << endl;
    cout << ": 1. Berkas               :" << endl;
    cout << ": 2. Barang               :" << endl;
    cout << ": 3. Paket                :" << endl;
    cout << "==========================" << endl;
    cout << "Pilihan : ";
    cin >> pilihan;
    cout << endl;

    if (pilihan == 1)
    {
        cout << "Pengiriman Berkas" << endl;
        cout << "-----------------" << endl;
        cout << "Jumlah Berkas : ";
        cin >> jumlah;
        harga = (HargaBerkas * jumlah) + jarak;
    }
    else if (pilihan == 2)
    {
        cout << "Pengiriman Barang" << endl;
        cout << "-----------------" << endl;
        cout << "Berat Barang /kg = ";
        cin >> berat;
        harga = (BeratBarang * berat) + HargaBarang + jarak;
        cout << endl;
    }
    else if (pilihan == 3)
    {
        cout << "Pengiriman Paket" << endl;
        cout << "----------------" << endl;
        cout << "Berat Paket /kg = ";
        cin >> berat;
        harga = (BeratPaket * berat) + HargaPaket + jarak;
        cout << endl;
    }
    else
    {
        cout << "Pilihan Tidak Tersedia" << endl;
        cout << "Silahkan Pilih Kembali" << endl;
        cout << endl;
        goto kedua;
    }
    x++;
}

// Fungsi untuk memilih kecepatan pengiriman
void pilihKecepatan(int &b, string &kecepatan)
{
    int a;

    cout << "Metode Pengiriman" << endl;
    cout << "1. Express (2-3 hari)" << endl;
    cout << "2. Reguler (4-6 hari)" << endl;
    cout << "Pilihan : ";
    cin >> a;
    cout << endl;

    switch (a)
    {
    case 1:
        b = 10000;
        kecepatan = "Express";
        break;
    case 2:
        b = 5000;
        kecepatan = "Reguler";
        break;
    default:
        cout << "Pilihan Tidak Tersedia" << endl;
        cout << "Silahkan Pilih Kembali" << endl;
        cout << endl;
        pilihKecepatan(b, kecepatan); // Rekursif jika pilihan tidak valid
    }
}

void tampilkanInformasiPengiriman(const string &NamaPengirim, const string &NamaPenerima,
                                  const string &kota, const string &kecepatan, const string &AlamatPengirim, const float totalHarga)
{
    cout << "+====================================================+" << endl;
    cout << "| Tanggal Pengiriman   |:| " << __DATE__ << endl;
    cout << "| Nama Pengirim        |:| " << NamaPengirim << endl;
    cout << "| Alamat Pengirim      |:| " << AlamatPengirim << endl;
    cout << "| Nama Penerima        |:| " << NamaPenerima << endl;
    cout << "| Kota Tujuan          |:| " << kota << endl;
    cout << "| Kecepatan Pengiriman |:| " << kecepatan << endl;
    cout << "+====================================================+" << endl;
    cout << "| Total yang dibayar   |=| Rp. " << totalHarga << endl;
    cout << "+====================================================+" << endl;
}

// Fungsi untuk melakukan pembayaran
void lakukanPembayaran(float totalHarga, Pembayaran &pembayaran)
{
metodepembayaran:
    int pilihanMetode;
    cout << "==========================" << endl;
    cout << ":   Metode Pembayaran    :" << endl;
    cout << "==========================" << endl;
    cout << ": 1.Tunai                :" << endl;
    cout << ": 2.Kartu Kredit         :" << endl;
    cout << "==========================" << endl;
    cout << "Pilih Metode pembayaran = ";
    cin >> pilihanMetode;

    if (pilihanMetode == 1)
    {
        pembayaran.metode = TUNAI;
        cout << "Jumlah Pembayaran: Rp. ";
        cin >> pembayaran.jumlah;
        cout << "==========================" << endl;

        if (pembayaran.jumlah >= totalHarga)
        {
            float kembalian = pembayaran.jumlah - totalHarga;
            cout << "Pembayaran tunai diterima." << endl;
            cout << "==========================" << endl;
            cout << "Kembalian: Rp. " << kembalian << endl;
            cout << "==========================" << endl;
            cout << "Terimakasih" << endl;
            cout << "==========================" << endl;
        }
        else
        {
            cout << "Jumlah pembayaran kurang. Pembayaran tidak diterima." << endl;
            goto metodepembayaran;
        }
    }
    else if (pilihanMetode == 2)
    {
        pembayaran.metode = KARTU_KREDIT;
        pembayaran.jumlah = totalHarga;
        cout << "------------------------------------------------------" << endl;
        cout << "Pembayaran dengan kartu kredit berhasil. Terima kasih!" << endl;
    }
    else
    {
        cout << "Pilihan metode pembayaran tidak valid." << endl;
        goto metodepembayaran;
    }
}

// Fungsi untuk mencetak struk
void cetakStruk(const string &NamaPengirim, const string &NamaPenerima,
                const string &kota, const string &kecepatan, const string &AlamatPengirim,
                const float totalHarga, const Pembayaran &pembayaran, const string &nomorResi)
{
    ofstream fileStruk("StrukPengiriman.txt");
    if (fileStruk.is_open())
    {
        fileStruk << "+============================================+" << endl;
        fileStruk << "|      EKSPEDISI BARANG NITRO GO EXPRESS     |" << endl;
        fileStruk << "+============================================+" << endl;
        fileStruk << endl;
        fileStruk << "+====================================================+" << endl;
        fileStruk << "| Nomor Resi           |:| " << nomorResi << endl;
        fileStruk << "| Tanggal Pengiriman   |:| " << __DATE__ << endl;
        fileStruk << "| Nama Pengirim        |:| " << NamaPengirim << endl;
        fileStruk << "| Alamat Pengirim      |:| " << AlamatPengirim << endl;
        fileStruk << "| Nama Penerima        |:| " << NamaPenerima << endl;
        fileStruk << "| Kota Tujuan          |:| " << kota << endl;
        fileStruk << "| Kecepatan Pengiriman |:| " << kecepatan << endl;
        fileStruk << "+====================================================+" << endl;
        fileStruk << "| Total yang dibayar   |=| Rp. " << totalHarga << endl;

        if (pembayaran.metode == TUNAI)
        {
            fileStruk << "| Pembayaran Metode    |=| Tunai" << endl;
            fileStruk << "| Jumlah Pembayaran    |=| Rp. " << pembayaran.jumlah << endl;
            if (pembayaran.jumlah > totalHarga)
            {
                float kembalian = pembayaran.jumlah - totalHarga;
                fileStruk << "| Kembalian            |=| Rp. " << kembalian << endl;
            }
        }
        else if (pembayaran.metode == KARTU_KREDIT)
        {
            fileStruk << "| Pembayaran Metode    |=| Kartu Kredit" << endl;
            fileStruk << "| Jumlah Pembayaran    |=| Rp. " << pembayaran.jumlah << endl;
        }

        fileStruk << "+====================================================+" << endl;
        fileStruk << "+----------------------------------------------- +" << endl;
        fileStruk << "|   TERIMAKASIH TELAH MENGGUNAKAN LAYANAN KAMI   | " << endl;
        fileStruk << "+----------------------------------------------- +" << endl;
        fileStruk.close();
        cout << "------------------------------------------------" << endl;
        cout << "Struk berhasil disimpan di StrukPengiriman.txt" << endl;
    }
    else
    {
        cout << "Gagal membuka file untuk menyimpan struk." << endl;
    }
}

int main()
{
    // Deklarasi variabel
    string Tanggal, NamaPengirim, NamaPenerima, AlamatPengirim, lagi, tambah = "y", kota, kecepatan;
    float total = 0, jarak = 0;
    float harga[10];
    int x = 0, b;
    do
    {

        clearscreeen(); // Menghapus seluruh tampilan pada layar

        // Membuat akun logi
        infologin account = BuatAkun();
        clearscreeen();

        string nomorResi = generateResi();

        // Panggil fungsi login
        if (!login(account))
        {
            return 1; // Keluar dari program jika login gagal
        }
        clearscreeen();

        Header();
        // Panggil fungsi untuk input data pengirim dan penerima
        inputDataPengiriman(NamaPengirim, NamaPenerima, AlamatPengirim);
        clearscreeen();

        Header();
        // Panggil fungsi untuk memilih kota tujuan
        pilihKotaTujuan(jarak, kota);
        clearscreeen();

        Header();
        while (tambah == "Y" || tambah == "y")
        {
            // Panggil fungsi untuk memilih jenis pengiriman
            pilihJenisPengiriman(harga[x], x, jarak);
            cout << "Tambah Pengiriman (Y/T) : ";
            cin >> tambah;
            cout << endl;
        }
        clearscreeen();

        Header();
        // Panggil fungsi untuk memilih kecepatan pengiriman
        pilihKecepatan(b, kecepatan);
        clearscreeen();

        for (int i = 0; i < x; i++)
        {
            total = total + harga[i];
        }

        Header();
        // Panggil fungsi untuk input tampilkan informasi pengiriman
        tampilkanInformasiPengiriman(NamaPengirim, NamaPenerima, kota, kecepatan, AlamatPengirim, total + b);

        // Tanya pengguna apakah ingin melakukan pembayaran
        char lanjutPembayaran;
        cout << "Apakah anda ingin melakukan pembayaran? (Y/T): ";
        cin >> lanjutPembayaran;
        clearscreeen();

        if (lanjutPembayaran == 'Y' || lanjutPembayaran == 'y')
        {
            Pembayaran pembayaran;
            lakukanPembayaran(total + b, pembayaran);

            cetakStruk(NamaPengirim, NamaPenerima, kota, kecepatan, AlamatPengirim, total + b, pembayaran, nomorResi);
        }

        // untuk mereset total harga
        total = 0;
        x = 0;
        b = 0;

        tambah = "y";
        cout << "Apakah anda ingin mengirim lagi (Y/T): ";
        cin >> lagi;

    } while (lagi == "Y" || lagi == "y");
    cout << "+----------------------------------------------- +" << endl;
    cout << "|   TERIMAKASIH TELAH MENGGUNAKAN LAYANAN KAMI   | " << endl;
    cout << "+----------------------------------------------- +" << endl;
    return 0;
}
