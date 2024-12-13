#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<algorithm>
#include<random>
using namespace std;

string randomPasswrodGenerator(int length)
{
    //creating all possible values
    const string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    const string digits = "0123456789";
    const string specialLetters = "!@#$%^&*()-=_+";
    const string allChar = upperCase + lowerCase + digits + specialLetters;

    //defining out variable/password
    string password;

    //ensuring atleast 1 of each character type is used
    password += upperCase[rand() % upperCase.length()];
    password += lowerCase[rand() % lowerCase.length()];
    password += digits[rand() % digits.length()];
    password += specialLetters[rand() % specialLetters.length()];

    //randomly select from all characters the rest of the password
    for(int i = 4; i < length; i++)
    {
        password += allChar[rand() % allChar.length()];
    }

    // Create a random number generator
    random_device rd; // Random device for seed
    mt19937 rng(rd()); // Mersenne Twister generator
    shuffle(password.begin(),password.end(),rng); //shuffle the password to create properly random password

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
