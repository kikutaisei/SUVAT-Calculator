#include <iostream>
using namespace std;

// Parent class
class SuvatQuestion{
    protected:
        string s;
        string u;
        string v;
        string a;
        string t;
        string wantValue;
        string unknownValue;
        bool unknownValueExists;
        int chosenEquation;

    private:
        bool validateSuvat(string suvatInputs[]){
            int wants = 0;
            int unknowns = 0;
            int knowns = 0;
            for (int i = 0; i < 5; i++){
                if (suvatInputs[i] == "?"){
                    wants += 1;
                }else if(suvatInputs[i] == "-"){
                    unknowns += 1;
                }else{
                    knowns += 1;
                }
            }
            if (wants == 1 && unknowns == 1 && knowns == 3){
                unknownValueExists = true;
                return true;
            }else if (wants == 1 && unknowns == 0 && knowns == 4){
                unknownValueExists = false;
                return true;
            }else{
                return false;
            }
        }

        void setSuvat(string suvatInputs[]){
            for (int i = 0; i < 5; i++){
                if (suvatInputs[i] == "?"){
                    switch (i){
                        case 0:
                            wantValue = "S";
                            break;
                        case 1:
                            wantValue = "U";
                            break;
                        case 2:
                            wantValue = "V";
                            break;
                        case 3:
                            wantValue = "A";
                            break;
                        case 4:
                            wantValue = "T";
                            break;
                    }
                }else if (suvatInputs[i] == "-"){
                    switch (i){
                        case 0:
                            unknownValue = "S";
                            break;
                        case 1:
                            unknownValue = "U";
                            break;
                        case 2:
                            unknownValue = "V";
                            break;
                        case 3:
                            unknownValue = "A";
                            break;
                        case 4:
                            unknownValue = "T";
                            break;
                    }
                }else{
                    switch (i){
                        case 0:
                            s = suvatInputs[i];
                            break;
                        case 1:
                            u = suvatInputs[i];
                            break;
                        case 2:
                            v = suvatInputs[i];
                            break;
                        case 3:
                            a = suvatInputs[i];
                            break;
                        case 4:
                            t = suvatInputs[i];
                            break;
                    }
                }
            }
        }

        void chooseEquation(){
            string equationOptions[5] = {"V = U + AT", "V² = U² + 2AS", "S = UT + ½AT²", "S = VT - ½AT²", "S = ½(U + V)T"};
            if (unknownValueExists == true){
                int options;
                if (unknownValue == "S"){
                    options = 0;
                }else if (unknownValue == "U"){
                    options = 3;
                }else if (unknownValue == "V"){
                    options = 2;
                }else if (unknownValue == "A"){
                    options = 4;
                }else if (unknownValue == "T"){
                    options = 1;
                }
                while (true){
                    string choiceInputString;
                    cout << "\nYou can use the following equation(s):\n";
                    cout << "1) " << equationOptions[options] << "\n\n";
                    cout << "Press 1 to confirm and continue: ";
                    cin >> choiceInputString;
                    if (choiceInputString == "1"){
                        chosenEquation = options + 1;
                        break;
                    }else{
                        cout << "Your confirmation was invalid. Please try again.\n";
                    }
                }
            }else{
                int options[4];
                if (wantValue == "S"){
                    options[0] = 1;
                    options[1] = 2;
                    options[2] = 3;
                    options[3] = 4;
                }else if (wantValue == "U"){
                    options[0] = 0;
                    options[1] = 1;
                    options[2] = 2;
                    options[3] = 4;
                }else if (wantValue == "V"){
                    options[0] = 0;
                    options[1] = 1;
                    options[2] = 3;
                    options[3] = 4;
                }else if (wantValue == "A"){
                    options[0] = 0;
                    options[1] = 1;
                    options[2] = 2;
                    options[3] = 3;
                }else if (wantValue == "T"){
                    options[0] = 0;
                    options[1] = 2;
                    options[2] = 3;
                    options[3] = 4;
                }
                while (true){
                    string choiceInputString;
                    cout << "\nYou can use the following equation(s):\n";
                    for (int i = 0; i < 4; i++){
                        cout << i + 1 << ") " << equationOptions[options[i]] << "\n";
                    }
                    cout << "\nPress the number of your desired equation to confirm and continue: ";
                    cin >> choiceInputString;
                    if (choiceInputString == "1" || choiceInputString == "2" || choiceInputString == "3" || choiceInputString == "4"){
                        int choiceInputInt = stoi(choiceInputString);
                        chosenEquation = options[choiceInputInt - 1] + 1;
                        break;
                    }else{
                        cout << "Your confirmation was invalid. Please try again.\n";
                    }
                }
            }
        }

    public:
        int getChosenEquation(){
            return chosenEquation;
        }

        SuvatQuestion(){
                string suvatLetters[5] = {"S", "U", "V", "A", "T"};
                string suvatInputs[5];
            while (true){
                cout << "Enter numbers for known values, ? for values to find and - for unknown values.\n";
                for (int i = 0; i < 5; i++){
                    cout << suvatLetters[i] << " = ";
                    cin >> suvatInputs[i];
                }
                if (validateSuvat(suvatInputs) == true){
                    setSuvat(suvatInputs);
                    break;
                }else{
                    cout << "\nYour input(s) were invalid. Please try again.";
                }
            }
            chooseEquation();
        }
};

int main(){
    cout << "\n\n\n\n\n"; // Delete this later! This is to add some spacing between executions!

    SuvatQuestion newQuestion;

    switch(newQuestion.getChosenEquation()){
        case 1:
            cout << "You chose equation 1."; // Run code for EquationOne class here
            break;
        case 2:
            cout << "You chose equation 2."; // Run code for EquationTwo class here
            break;
        case 3:
            cout << "You chose equation 3."; // Run code for EquationThree class here
            break;
        case 4:
            cout << "You chose equation 4."; // Run code for EquationFour class here
            break;
        case 5:
            cout << "You chose equation 5."; // Run code for EquationFive class here
            break;
    }

    cout << "\n\n\n\n\n"; // Delete this later! This is to add some spacing between executions!
    return 0;
}