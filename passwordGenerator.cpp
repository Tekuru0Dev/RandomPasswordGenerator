#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<algorithm>
#include<random>
using namespace std;

string randomPasswrodGenerator(int length)
{
    const string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    const string digits = "0123456789";
    const string specialLetters = "!@#$%^&*()-=_+";
    const string allChar = upperCase + lowerCase + digits + specialLetters;

    string password;

    password += upperCase[rand() % upperCase.length()];
    password += lowerCase[rand() % lowerCase.length()];
    password += digits[rand() % digits.length()];
    password += specialLetters[rand() % specialLetters.length()];

    for(int i = 4; i < length; i++)
    {
        password += allChar[rand() % allChar.length()];
    }

    // Create a random number generator
    random_device rd; // Random device for seed
    mt19937 rng(rd()); // Mersenne Twister generator
    shuffle(password.begin(),password.end(),rng);

    return password;
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generator

    int length;
    cout << "Enter desired password length (minimum 8): ";
    cin >> length;

    if (length < 8) {
        cout << "Password length must be at least 8." << endl;
        return 1;
    }

    string password = randomPasswrodGenerator(length);
    cout << "Generated Password: " << password << endl;

    return 0;
}