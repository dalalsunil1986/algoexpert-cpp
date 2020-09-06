#include <string>

std::string caesarCypherEncryptor(std::string str, int key)
{
    key = key % 26;

    for (auto& c : str)
    {
        int nextCharacter = int(c) + key;
        if (nextCharacter > int('z'))
        {
            int diff = nextCharacter - int('z');
            nextCharacter = int('a') + diff - 1;
        }
        c = nextCharacter;
    }

    return str;
}
