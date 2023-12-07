#include <wchar.h>
#include <stdio.h>
#include <string.h>

void PasswordEncode(char *Password, size_t MaxSize) {
    size_t ii;
    unsigned int key = 0x935b;

    for (ii = 0; ii < MaxSize; ii++) {
        Password[ii] = ((Password[ii] >= 'a') && (Password[ii] <= 'z')) ? (Password[ii] + 'A' - 'a') : Password[ii];
    }

    // Encode the password..
    for (ii = 1; ii <= MaxSize / 2; ii++) {
        Password[ii - 1] = (char)(Password[ii - 1] ^ (key * ii));
    }
}

int main() {
    // Ursprüngliches Passwort
    char password[] = "adm1nistrat0r";
    size_t passwordSize = strlen(password);

    // Verschlüsselung
    PasswordEncode(password, passwordSize);

    // Ausgabe des verschlüsselten Passworts
    wprintf(L"Encoded Password: ");
    for (size_t i = 0; i < passwordSize; i++) {
        wprintf(L"%p ", (unsigned char)password[i]);
    }
    wprintf(L"\n");
    return 0;
}
