#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstring>
#include <stack>

using namespace std;

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

// Struktur dan variabel global
struct Player
{
    char name[20];
    int score;
};


Player players[100];
int playerCount = 0;
int maxWidth, maxHeight;

// Deklarasi fungsi
void SavePlayerData();
void LoadPlayerData();
void SearchPlayer(const char *playerName);
void DisplayPlayers();
void textcolor(int fc, int bc = -1);
void textcolor(const char *fc, const char *bc = "");
void gotoxy(int x, int y);
void getTerminalSize(int &width, int &height);
void getup();
void score(int sc);
void status(const char *s, int c = 7);
void PlayGame(const char *playerName, int difficulty);
void gameover();
void MainMenu();
void UserMenu();
void DeletePlayer(const char *playerName);
void EditPlayerName(const char *oldName, const char *newName);

int main()
{
    LoadPlayerData();
    MainMenu();
    return 0;
}

// Implementasi fungsi-fungsi yang dideklarasikan

void SavePlayerData()
{   
    ofstream file("player_data.txt");
    if (!file)
    {
        cout << "Tidak bisa membuka file untuk menyimpan data." << endl;
        return;
    }

    // Create a stack of players
    stack<Player> playerStack;

    // Push all players into the stack
    for (int i = 0; i < playerCount; i++)
    {
        playerStack.push(players[i]);
    }

    // Pop all players from the stack and write to file
    while (!playerStack.empty())
    {
        Player player = playerStack.top();
        playerStack.pop();
        file << player.name << " " << player.score << endl;
        
    }

    file.close();
}




void LoadPlayerData()
{
    ifstream file("player_data.txt");
    if (!file)
    {
        cout << "Tidak bisa membuka file untuk memuat data." << endl;
        return;
    }

    playerCount = 0;
    while (file >> players[playerCount].name >> players[playerCount].score)
    {
        playerCount++;
    }

    file.close();
}

void SearchPlayer(const char *playerName)
{
    bool found = false;
    int totalScore = 0;
    for (int i = 0; i < playerCount; i++)
    {
        if (strcmp(players[i].name, playerName) == 0)
        {
            found = true;
            totalScore += players[i].score;
        }
    }

    if (found)
    {
        cout << "Pemain ditemukan!" << endl;
        cout << "Nama: " << playerName << endl;
        cout << "Skor: " << totalScore << endl;
    }
    else
    {
        cout << "Pemain dengan nama '" << playerName << "' tidak ditemukan." << endl;
    }
}

void DisplayPlayers()
{
    cout << "=================================" << endl;
    cout << "           LEADERBOARD           " << endl;
    cout << "=================================" << endl;
    cout << " No | Nama Pemain          |Skor " << endl;
    cout << "=================================" << endl;

    // Create a temporary array to store the summed scores
    Player tempPlayers[100];
    int tempCount = 0;

    // Loop through the players and sum up their scores
    for (int i = 0; i < playerCount; i++)
    {
        bool found = false;
        for (int j = 0; j < tempCount; j++)
        {
            if (strcmp(players[i].name, tempPlayers[j].name) == 0)
            {
                tempPlayers[j].score += players[i].score;
                found = true;
                break;
            }
        }
        if (!found)
        {
            tempPlayers[tempCount] = players[i];
            tempCount++;
        }
    }

    // Sort the temporary array by score in descending order
    for (int i = 0; i < tempCount - 1; i++)
    {
        for (int j = i + 1; j < tempCount; j++)
        {
            if (tempPlayers[i].score < tempPlayers[j].score)
            {
                Player temp = tempPlayers[i];
                tempPlayers[i] = tempPlayers[j];
                tempPlayers[j] = temp;
            }
        }
    }

    int rank = 1;
    for (int i = 0; i < tempCount; i++)
    {
        cout << " " << setw(2) << rank++ << " | "
             << left << setw(20) << tempPlayers[i].name << " | "
             << right << setw(4) << tempPlayers[i].score << " " << endl;
    }
    cout << "=================================" << endl;
}


int strcmpi(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (tolower(*s1) != tolower(*s2))
        {
            break;
        }
        s1++;
        s2++;
    }
    return tolower(*(unsigned char *)s1) - tolower(*(unsigned char *)s2);
}

void textcolor(int fc, int bc)
{
    if (fc < 0 || fc > 15)
        return;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (bc >= 0 && bc < 16)
        SetConsoleTextAttribute(h, fc | bc * 16);
    else
        SetConsoleTextAttribute(h, fc);
}

void textcolor(const char *fc, const char *bc)
{
    int x, y = 16;
    const char *colors[] = {"Black", "Blue", "Green", "Aqua", "Red", "Purple", "Yellow", "White", "Gray", "LightBlue", "LightGreen", "LightAqua", "LightRed", "LightPurple", "LightYellow", "BrightWhite"};
    for (x = 0; x < 16; x++)
        if (strcmpi(colors[x], fc) == 0)
            break;
    if (strlen(bc) > 0)
        for (y = 0; y < 16; y++)
            if (strcmpi(colors[y], bc) == 0)
                break;
    textcolor(x, y);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void getTerminalSize(int &width, int &height)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    width = columns;
    height = rows;
}

void getup()
{
    HANDLE hout;
    CONSOLE_CURSOR_INFO cursor;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    cursor.dwSize = 1;
    cursor.bVisible = false;
    SetConsoleCursorInfo(hout, &cursor);
    system("Pawang Piton");

    getTerminalSize(maxWidth, maxHeight);

    system("cls");
    textcolor("LightAqua");

    // Membuat batas atas
    gotoxy(2, 1);
    cout << char(218); // Sudut kiri atas
    for (int x = 0; x < maxWidth - 5; x++)
        cout << char(196); // Garis horizontal
    cout << char(191);     // Sudut kanan atas

    // Membuat batas samping
    for (int y = 2; y < maxHeight - 5; y++)
    {
        gotoxy(2, y);
        cout << char(179); // Garis vertikal kiri
        gotoxy(maxWidth - 3, y);
        cout << char(179); // Garis vertikal kanan
    }

    // Membuat batas bawah
    gotoxy(2, maxHeight - 5);
    cout << char(192); // Sudut kiri bawah
    for (int x = 0; x < maxWidth - 5; x++)
        cout << char(196); // Garis horizontal
    cout << char(217);     // Sudut kanan bawah

    // Membuat judul tengah atas
    gotoxy((maxWidth / 2) - 10, 0);
    cout << char(218);
    for (int x = 0; x < 21; x++)
        cout << char(196);
    cout << char(191);
    gotoxy((maxWidth / 2) - 10, 1);
    cout << char(179) << " Pawang Piton " << char(179);
    gotoxy((maxWidth / 2) - 10, 2);
    cout << char(192);
    for (int x = 0; x < 21; x++)
        cout << char(196);
    cout << char(217);

    // Membuat area skor dan status di kanan bawah
    gotoxy(maxWidth - 21, maxHeight - 5);
    cout << char(218);
    for (int x = 0; x < 18; x++)
        cout << char(196);
    cout << char(191);
    gotoxy(maxWidth - 21, maxHeight - 4);
    cout << char(179) << " SCORE : 0      " << char(179);
    gotoxy(maxWidth - 21, maxHeight - 3);
    cout << char(179) << " STATUS: Playing  " << char(179);
    gotoxy(maxWidth - 21, maxHeight - 2);
    cout << char(192);
    for (int x = 0; x < 18; x++)
        cout << char(196);
    cout << char(217);

    // Menampilkan pesan kontrol
    gotoxy(10, maxHeight - 2);
    textcolor("Green", "blue");
    cout << "Press Space to Pause and Play";
    gotoxy(10, maxHeight - 1);
    cout << "Press X to Exit";
    textcolor(7);
}

void score(int sc)
{
    gotoxy(maxWidth - 11, maxHeight - 4);
    cout << setw(6) << sc * 10;
}

void status(const char *s, int c)
{
    gotoxy(maxWidth - 11, maxHeight - 3);
    textcolor(c);
    cout << left << setw(8) << s;
    textcolor(7);
}

void PlayGame(const char *playerName)
{
	//deklarasi variabel
    register int flow, size, i, xb, yb; //variable, arah, ukuran ular, index, dan koordinat makanan
    int speed, restart = 1, tmp, xpos[100], ypos[100], scr; // variabel kecepatan, flag restart, flag sementara, posisi ular, dan skor
    srand(time(NULL)); // Menginisialisasi seed untuk fungsi rand()
    while (true)
    {
    if (restart) // Jika restart diaktifkan, inisialisasi ulang permainan
{
    status("Playing", 10); // Menampilkan status "Playing"

    // Membersihkan area permainan
    for (int k = 1; k < maxWidth - 5; k += 2)
        for (int j = 0; j < maxHeight - 7; j++)
        {
            gotoxy(k + 3, j + 2); // Pindah kursor ke posisi (k+3, j+2)
            cout << " "; // Mengosongkan karakter pada posisi tersebut
        }

    // Inisialisasi variabel permainan
    size = 2; // Ukuran awal ular
    speed = 100; // Kecepatan awal ular
    scr = 0; // Skor awal
    score(scr); // Menampilkan skor awal
    flow = RIGHT; // Arah awal ular
    xpos[0] = 20; // Posisi awal kepala ular

    // Mengatur posisi awal seluruh segmen ular
    for (i = 0; i < size; i++)
    {
        xpos[i] = xpos[0] - i * 2; // Mengatur posisi x segmen ular
        ypos[i] = 10; // Mengatur posisi y segmen ular
    }

    // Menampilkan ular di layar
    for (i = 0; i < size; i++)
    {
        gotoxy(xpos[i], ypos[i]); // Pindah kursor ke posisi segmen ular
        cout << "o"; // Menampilkan segmen ular
    }

    // Menentukan posisi acak untuk makanan
    for (tmp = 1; true;)
    {
        do
        {
            xb = rand() % (maxWidth - 6) + 3; // Posisi x acak untuk makanan
        } while (xb % 2 != 0); // Memastikan posisi x adalah genap
        yb = rand() % (maxHeight - 8) + 2; // Posisi y acak untuk makanan

        // Memastikan makanan tidak berada di posisi ular
        for (i = 0; i < size; i++)
            if (xb == xpos[i] && yb == ypos[i])
            {
                tmp = 0; // Menandai tabrakan dengan ular
                break;
            }
        if (tmp)
            break; // Keluar dari perulangan jika posisi makanan valid
    }

    // Menampilkan makanan di layar
    gotoxy(xb, yb);
    textcolor("Red");
    cout << "@";
    textcolor(7);
    restart = 0; // Menonaktifkan flag restart
}

// Loop utama permainan
while (!kbhit() && !restart)
{
    // Logika ketika ular memakan makanan
    if (xpos[0] == xb && ypos[0] == yb)
    {
        for (tmp = 1; true;)
        {
            do
            {
                xb = rand() % (maxWidth - 6) + 3; // Posisi x acak untuk makanan
            } while (xb % 2 != 0); // Memastikan posisi x adalah genap
            yb = rand() % (maxHeight - 8) + 2; // Posisi y acak untuk makanan

            // Memastikan makanan tidak berada di posisi ular
            for (i = 0; i < size; i++)
                if (xb == xpos[i] && yb == ypos[i])
                {
                    tmp = 0; // Menandai tabrakan dengan ular
                    break;
                }
            if (tmp)
                break; // Keluar dari perulangan jika posisi makanan valid
        }

        // Menampilkan makanan di layar
        gotoxy(xb, yb);
        textcolor("Red");
        cout << "@";
        textcolor(7);
        size++; // Menambah ukuran ular
        scr++; // Menambah skor
        speed -= 3; // Meningkatkan kecepatan ular
        score(scr); // Menampilkan skor baru
    }

    // Memindahkan segmen terakhir ular
    gotoxy(xpos[size - 1], ypos[size - 1]);
    for (i = size - 1; i > 0; i--)
    {
        xpos[i] = xpos[i - 1]; // Memindahkan posisi x segmen
        ypos[i] = ypos[i - 1]; // Memindahkan posisi y segmen
    }

    // Menggerakkan kepala ular sesuai arah
    switch (flow)
    {
    case RIGHT:
        xpos[i] += 2; // Gerak ke kanan
        break;
    case LEFT:
        xpos[i] -= 2; // Gerak ke kiri
        break;
    case UP:
        ypos[i] -= 1; // Gerak ke atas
        break;
    case DOWN:
        ypos[i] += 1; // Gerak ke bawah
    }

    // Memeriksa tabrakan dengan tubuh ular atau dinding
    tmp = 1;
    for (i = 1; i < size; i++)
        if (xpos[i] == xpos[0] && ypos[i] == ypos[0])
        {
            tmp = 0; // Tabrakan dengan tubuh
            break;
        }
    if (xpos[0] > maxWidth - 4 || xpos[0] < 4 || ypos[0] < 2 || ypos[0] > maxHeight - 6)
        tmp = 0; // Tabrakan dengan dinding

    // Menampilkan ular di layar jika tidak ada tabrakan
    if (tmp)
    {
        cout << " ";
        gotoxy(xpos[0], ypos[0]); // Pindah kursor ke kepala ular
        cout << "O"; // Menampilkan kepala ular
        gotoxy(xpos[1], ypos[1]); // Pindah kursor ke segmen kedua
        cout << "o"; // Menampilkan segmen kedua
    }
    else // Jika ada tabrakan
    {
        textcolor("LIGHTRED");
        cout << "o"; // Menampilkan segmen ular berwarna merah
        gotoxy(xpos[1], ypos[1]);
        cout << "O"; // Menampilkan kepala ular berwarna merah
        for (i = 2; i < size; i++)
        {
            gotoxy(xpos[i], ypos[i]);
            cout << "o"; // Menampilkan sisa segmen ular berwarna merah
        }
        textcolor(7);
        status("GameOver", 12); // Menampilkan status "GameOver"
        
        // Simpan skor pemain
        Player newPlayer;
        strcpy(newPlayer.name, playerName);
        newPlayer.score = scr * 10;
        players[playerCount++] = newPlayer;
        SavePlayerData(); // Menyimpan data pemain
        restart = 1; // Mengaktifkan flag restart
        getch(); // Menunggu input dari pemain
//        UserMenu();
    }
    Sleep(speed); // Menunggu sesuai kecepatan ular
}

// Mengambil input dari pemain
char ch = getch();
switch (tolower(ch))
{
case 'x':
    system("cls"); // Membersihkan layar
//    return; // Keluar dari permainan
    UserMenu();
case ' ':
    status("Paused"); // Menampilkan status "Paused"
    while (true)
    {
        char z = getch();
        if (z == 'x')
            return; // Keluar dari permainan saat paused
        if (z == ' ')
            break; // Melanjutkan permainan
    }
    status("Playing", 10); // Menampilkan status "Playing"
    break;
case 'w': // Mengubah arah ke atas saat tombol W ditekan
    if (flow != DOWN)
        flow = UP;
    break;
case 's': // Mengubah arah ke bawah saat tombol S ditekan
    if (flow != UP)
        flow = DOWN;
    break;
case 'a': // Mengubah arah ke kiri saat tombol A ditekan
    if (flow != RIGHT)
        flow = LEFT;
    break;
case 'd': // Mengubah arah ke kanan saat tombol D ditekan
    if (flow != LEFT)
        flow = RIGHT;
    break;
		}

    }
}


void DeletePlayer(const char *playerName)
{
    int count = 0;
    for (int i = 0; i < playerCount; i++)
    {
        if (strcmp(players[i].name, playerName) == 0)
        {
            // Shift all players to the left to delete the current player
            for (int j = i; j < playerCount - 1; j++)
            {
                players[j] = players[j + 1];
            }
            playerCount--;
            i--; // Decrement i to re-check the current index
            count++;
        }
    }
    if (count > 0)
    {
        cout << "Player dengan nama' " << playerName << " ' sudah dihapus dari leaderboard." << endl;
    }
    else
    {
        cout << "Tidak ada player dengan nama '" << playerName << "' di leaderboard" << endl;
    }
    SavePlayerData(); // Save the updated player data to file
}


void AdminMenu()
{
		char choice;
		system("cls");
        textcolor("LightAqua");
        gotoxy(65,13);
        cout << "=================================" << endl;
        gotoxy(65,14);
        cout << "           Menu Admin            " << endl;
        gotoxy(65,15);
        cout << "=================================" << endl;
        gotoxy(65,16);
        cout << "1. Delete Pemain Di LeaderBoard" << endl;
        gotoxy(65,17);
        cout << "2. Keluar dari Mode Admin" << endl;
        gotoxy(65,18);
        cout << "=================================" << endl;
        gotoxy(65,19);
        cout << "Masukkan pilihan : ";
        cin >> choice;
        
        switch(choice) 
        {
        	case '1':
        		system("cls");
			    char deleteName[20];
			    cout << "Masukkan nama pemain yang ingin Anda hapus: ";
			    cin >> deleteName;
			    DeletePlayer(deleteName);
			    cout << "Tekan tombol apa saja untuk kembali ke menu utama...";
			    _getch();
			    AdminMenu();
				break;
			case '2':
				system("cls");
				cout << "Kamu telah keluar dari mode Admin";
				Sleep(1000);
				system("cls");
				MainMenu();
				break;
				
				
		}
}


void MainMenu()
{  
		char choice;
		string user,pass;
    	char playerName[20];
		system("cls");
        textcolor("LightAqua");
        gotoxy(65,13);
        cout << "=================================" << endl;
        gotoxy(65,14);
        cout << "          Menu Utama          " << endl;
        gotoxy(65,15);
        cout << "=================================" << endl;
        gotoxy(65,16);
        cout << "1. Login Admin" << endl;
        gotoxy(65,17);
        cout << "2. Mulai Permainan" << endl;
        gotoxy(65,18);
        cout << "3. Menu User" << endl;
        gotoxy(65,19);
        cout << "4. Keluar";
        gotoxy(65,20);
        cout << "=================================" << endl;
        gotoxy(65,21);
        cout << "Masukkan pilihan : ";
        cin >> choice;
        
        switch (choice)
        {
        case '1':
        	system("cls");
 			cout << "Login Admin : ";
 			cin >> user;
 			cout << "Password : ";
 			cin >> pass;
 			if (user == "admin#123" && pass == "admin#123" ) 
 			{
 				AdminMenu();
			}else
			{
				cout <<"username atau password mungkin salah";
				Sleep(1000);
				system("cls");
				MainMenu();
			}
			break;
        case '2':
            system("cls");
 			while (true)
            {
                cout << "Masukkan Nama Pemain: ";
                cin >> playerName;
                bool nameExists = false;
                for (int i = 0; i < playerCount; i++)
                {
                    if (strcmp(players[i].name, playerName) == 0)
                    {
                        nameExists = true;
                        break;
                    }
                }
                if (nameExists)
                {
                    cout << "Nama sudah ada. Silakan masukkan nama lain." << endl;
                }
                else
                {
                    break;
                }
            }
            getup();
            PlayGame(playerName);
            break;
        case '3':
            UserMenu();
            break;
        case '4':
        	exit(0);
        	break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            break;
        }
    }



void UserMenu()
{
    char choice;
    char playerName[20];
    int difficulty;

    while (true)
    {
    	
        system("cls");
        textcolor("LightAqua");
        gotoxy(65,13);
        cout << "=================================" << endl;
        gotoxy(65,14);
        cout << "            Menu User            " << endl;
        gotoxy(65,15);
        cout << "=================================" << endl;
        gotoxy(65,16);
        cout << "1. Leaderboard" << endl;
        gotoxy(65,17);
        cout << "2. Cari pemain" << endl;
        gotoxy(65,18);
        cout << "3. Keluar";
        gotoxy(65,19);
        cout << "=================================" << endl;
        gotoxy(65,20);
        cout << "Masukkan pilihan : ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            system("cls");
            DisplayPlayers();
            cout << "Tekan tombol apa saja untuk kembali ke menu utama...";
            _getch();
            break;
        case '2':
            system("cls");
            char searchName[20];
            cout << "Masukkan nama pemain yang ingin Anda cari: ";
            cin >> searchName;
            SearchPlayer(searchName);
            cout << "Tekan tombol apa saja untuk kembali ke menu utama...";
            _getch();
            break;
        case '3':
            MainMenu();
            break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            break;
        }
    }
}
