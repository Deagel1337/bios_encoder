#include <iostream>
#include <iomanip>
#include <sstream>

std::string xor_strings(const std::string& str1, const std::string& str2) {
    // Stelle sicher, dass beide Strings die gleiche Länge haben
    size_t length = std::min(str1.length(), str2.length());

    // Konvertiere die beiden Strings in Byte-Arrays
    std::stringstream result_stream;
    for (size_t i = 0; i < length/2; i += 4) {
        // Extrahiere jeweils 2 Bytes aus den Strings
        int word1, word2;
        std::stringstream(str1.substr(i, 4)) >> std::hex >> word1;
        std::stringstream(str2.substr(i, 4)) >> std::hex >> word2;

        // Führe die XOR-Operation durch und füge das Ergebnis dem Stream hinzu
        result_stream << std::setfill('0') << std::setw(4) << std::hex << (word1 ^ word2);
    }

    return result_stream.str();
}

int main() {
    std::string string1;
    std::string string2;

    std::cout << "String 1: " << string1 << std::endl;
    std::cin >> string1;
    
    std::cout << "String 2: " << string2 << std::endl;
    std::cin >> string2;
    
    std::string result = xor_strings(string1, string2);

    std::cout << "String 1: " << string1 << std::endl;
    std::cout << "String 2: " << string2 << std::endl;
    std::cout << "XOR-Ergebnis: " << result << std::endl;

    return 0;
}
