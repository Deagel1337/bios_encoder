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
    // Beispielaufruf
    std::string string1 = "7B1394A6073A29CDD2601AF45C87ED1A07AEAE41DCD40A68ABFBFA0E55A2B0350BC9665CC1EF1C837716D2A92D3D88D0E3633EF7998AF41D4FB1AA4405D8606B";
    std::string string2 = "5B93B62611BA6C4DC7E022747D07D89A332E8EC1E95444E89F7BFA0E55A2B0350BC9665CC1EF1C837716D2A92D3D88D0E3633EF7998AF41D4FB1AA4405D8606B";
    std::string result = xor_strings(string1, string2);

    std::cout << "String 1: " << string1 << std::endl;
    std::cout << "String 2: " << string2 << std::endl;
    std::cout << "XOR-Ergebnis: " << result << std::endl;

    return 0;
}
