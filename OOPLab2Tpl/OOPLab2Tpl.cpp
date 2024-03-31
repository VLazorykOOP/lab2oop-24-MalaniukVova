#include <iostream>
#include <iostream>
#include <string>
#include <bitset>

// Функція шифрування тексту у двобайтовий формат 
//Це 2 завдання
std::string encryptText(std::string text) {
    std::string encryptedText;

    for (char c : text) {
        // ASCII код символу
        int asciiCode = static_cast<int>(c);
        // Позиція символу в рядку
        int position = encryptedText.length() % 128;

        // Молодша частина ASCII коду (4 біти)
        int lowerASCII = asciiCode & 0b1111;
        // Старша частина ASCII коду (4 біти)
        int upperASCII = (asciiCode >> 4) & 0b1111;
        // Позиція символу в рядку (7 біт)
        int posBits = position & 0b1111111;

        // Біт парності для молодшої та старшої частин ASCII коду
        int parityBit = (lowerASCII + upperASCII + posBits) % 2;

        // Формуємо перший байт (біти 0-7)
        int firstByte = (lowerASCII << 4) | posBits;
        // Формуємо другий байт (біти 8-15)
        int secondByte = (upperASCII << 4) | parityBit;

        // Додаємо шифрований символ у двобайтовому форматі до результату
        encryptedText += static_cast<char>(firstByte);
        encryptedText += static_cast<char>(secondByte);
    }

    return encryptedText;
}

auto Task1()
{       
        int main() {
        int a, c, d;
        std::cout << "Enter values for a, c, d: ";
        std::cin >> a >> c >> d;

        int result = ((200 * a + 312 * c) / 16) - d * 120 + c * 124;

        std::cout << "Result: " << result << std::endl;

        return 0;
    }
}
auto Task2()
{
    int main() {
        std::string word;
        std::cout << "Enter a word to encrypt: ";
        std::cin >> word;

        std::string encryptedWord = encryptText(word);

        std::cout << "Encrypted Word:\n" << encryptedWord << std::endl;

        return 0;
    }

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