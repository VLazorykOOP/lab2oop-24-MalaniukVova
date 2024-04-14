#include <iostream>
#include <string>
#include <iomanip> // для використання std::setw та std::setfill
using namespace std;

string encryptText(const string& text) {
    // Доповнюємо текст пробілами до 128 символів
    string paddedText = text;
    paddedText.resize(128, ' ');

    // Шифруємо кожен символ у два байти
    string encryptedText;
    for (char c : paddedText) {
        // Отримуємо ASCII-код символу
        int asciiCode = static_cast<int>(c);

        // Отримуємо позицію символу в рядку (додаємо 1, оскільки позиція починається з 1)
        int position = 0;
        for (char ch : paddedText) {
            position++;
            if (ch == c) break;
        }
        position = (position - 1) % 128 + 1; // Циклічна зміна позиції у межах 1-128

        // Формуємо два байти згідно зі структурою
        char byte1 = static_cast<char>((asciiCode & 0x0F) | ((position << 4) & 0x7F));
        char byte2 = static_cast<char>((asciiCode >> 4) | (((position >> 3) & 0x78) | ((position << 1) & 0x80)));

        // Додаємо байти до зашифрованого тексту
        encryptedText += byte1;
        encryptedText += byte2;
    }

    return encryptedText;
}

string decryptText(const string& encryptedText) {
    string decryptedText;
    for (size_t i = 0; i < encryptedText.length(); i += 2) {
        char byte1 = encryptedText[i];
        char byte2 = encryptedText[i + 1];

        // Відновлюємо ASCII-код символу та позицію з байтів
        int asciiCode = ((byte2 & 0x0F) << 4) | ((byte1 & 0x0F));
        int position = ((byte2 & 0x70) >> 1) | ((byte1 & 0x78) >> 4);

        // Відновлюємо символ з ASCII-коду та позиції
        char decryptedChar = static_cast<char>(asciiCode);
        decryptedText += decryptedChar;
    }

    return decryptedText;
}

void printHex(const string& text) {
    cout << "Tekst (u heksadecimal'nykh znachennyakh): ";
    for (char c : text) {
        cout << setw(2) << setfill('0') << hex << static_cast<int>(c) << " ";
    }
    cout << endl;
}

auto Task1()
{       
    int a, b, c, d;
    int result;
    float check_res;
    cout << " Calculation of expressions using bitwise operations  \n";
    cout << "Enter A:";
    cin >> a;
    cout << "Enter B:";
    cin >> b;
    cout << "Enter C:";
    cin >> c;
    cout << "Enter D:";
    cin >> d;
    result = ((((a << 7) + (a << 6) + (a << 3)) + ((c << 3) + (c << 4) + (c << 5) + (c << 8))) >> 4) - ((d << 7) - (d << 3)) + ((c << 7) - (c << 2));
    cout << "Result:" << result << endl;
    check_res = ((a * 200 + c * 312) / 16) - d * 120 + c * 124;
    printf("Check result: %0.5f", check_res);
    }
}
auto Task2()
{
    int main() {
        string inputText;
        cout << "Vvedit' tekst dlya shifruvannya (do 128 symboliv): ";
        getline(cin, inputText);

        string encrypted = encryptText(inputText);
        printHex(encrypted);

        string decrypted = decryptText(encrypted);
        cout << "Deshifrovanyy tekst: " << decrypted << endl;

        return 0;

}
auto Task3()
{
   
}

int main()
{
    int x;
    cout << "Choose Task!" << endl;
    cout << "1.Task1" << "\n";
    cout << "2.Task2" << "\n";
    cout << "3.Task3" << "\n";
    cout << "4.Exit!" << "\n";

    cin >> x;

    switch (x) {
    case 1:
        Task1();
        break;

    case 2:
        Task2();
        break;
    case 3:
        Task3();
        break;
    case 4:
        cout << "Well goodbye!" << endl;
        break;

    }

}