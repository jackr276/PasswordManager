/**
 * Jack Robbins
 * Password generator/strength checker -- still building
*/

#include "PasswordManager.h"


string generatePassword(int length, int option){
    if(option == 1){
        return LCG_RNG(length);
    } else {
        return MDG_RNG(length);
    }
}

void checkPasscodeStrength(string &passcode, int &length){

    double strength = checkPWStrength(passcode, length);

    cout << "Password Strength(//TODO): " << strength << endl;
}


