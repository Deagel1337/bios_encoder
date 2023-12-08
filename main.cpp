#include <iostream>
#include <iomanip>
#include <sstream>

std::string xor_strings(const std::string& str1, const std::string& str2) {
    // Stelle sicher, dass beide Strings die gleiche Länge haben
    size_t length = std::min(str1.length(), str2.length());

    // Konvertiere die beiden Strings in Byte-Arrays
    std::stringstream result_stream;
    for (size_t i = 0; i < length; ++i) {
        int byte1, byte2;
        std::stringstream(str1.substr(i, 2)) >> std::hex >> byte1;
        std::stringstream(str2.substr(i, 2)) >> std::hex >> byte2;

        // Führe die XOR-Operation durch und füge das Ergebnis dem Stream hinzu
        result_stream << std::setfill('0') << std::setw(2) << std::hex << (byte1 ^ byte2);
    }

    return result_stream.str();
}

int main() {
    // Beispielaufruf
    std::string string1 = "1a2b3c";
    std::string string2 = "4d5e6f";
    std::string result = xor_strings(string1, string2);

    std::cout << "String 1: " << string1 << std::endl;
    std::cout << "String 2: " << string2 << std::endl;
    std::cout << "XOR-Ergebnis: " << result << std::endl;

    return 0;
}
