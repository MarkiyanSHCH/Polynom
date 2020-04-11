#include "Operation.h"
int main()
{
    string pol, pol1;
    map<int, float> dictPolOne;
    map<int, float> dictPolTwo;
    map<int, float> result;

   

    
    while (true) {
        short op;
        cout << "Select operation: \n 1)Add Polynoms; \n 2)Substration Polynoms; \n 3)Multiplay Polynoms; \n 4)Division Polynoms; \n 5)Derivative Polynom; \n 6)Integral Polynom; \n 7)Horner Method \n 8)Superposition Polynoms;" << endl;
        cin >> op;
        system("cls");

        result.clear();

        switch (op) {
        case 1: {
            cout << "Enter first Polynom" << endl;
            cin >> pol;
            cout << "Enter second Polynom" << endl;
            cin >> pol1;
            int power = 0;
            vector<pair<int, float>> polynom_one = readPolynom(pol);
            vector<pair<int, float>> polynom_two = readPolynom(pol1);
            maxPower(polynom_one, polynom_two,power);
            fillMap(dictPolOne, polynom_one,true ,power);
            fillMap(dictPolTwo, polynom_two,true, power);
            addPolynom(dictPolOne, dictPolTwo, result);
            cout << "Result: ";
            printPolynom(result);
            break;
        }
        case 2: {
            cout << "Enter first Polynom" << endl;
            cin >> pol;
            cout << "Enter second Polynom" << endl;
            cin >> pol1;
            int power = 0;
            vector<pair<int, float>> polynom_one = readPolynom(pol);
            vector<pair<int, float>> polynom_two = readPolynom(pol1);
            maxPower(polynom_one, polynom_two, power);
            fillMap(dictPolOne, polynom_one, true, power);
            fillMap(dictPolTwo, polynom_two, true, power);
            subPolynom(dictPolOne, dictPolTwo, result);
            cout << "Result: ";
            printPolynom(result);
            break;
        }
        case 3: {
            cout << "Enter first Polynom" << endl;
            cin >> pol;
            cout << "Enter second Polynom" << endl;
            cin >> pol1;
            vector<pair<int, float>> polynom_one = readPolynom(pol);
            vector<pair<int, float>> polynom_two = readPolynom(pol1);
            fillMap(dictPolOne, polynom_one);
            fillMap(dictPolTwo, polynom_two);
            multPolynom(dictPolOne, dictPolTwo, result);
            cout << "Result: ";
            printPolynom(result);
            break;
        }
        case 4: {
            cout << "Enter first Polynom" << endl;
            cin >> pol;
            cout << "Enter second Polynom" << endl;
            cin >> pol1;
            if (pol == pol1) {
                cout << "Result: 1" << endl;
            }
            else {
                vector<pair<int, float>> polynom_one = readPolynom(pol);
                vector<pair<int, float>> polynom_two = readPolynom(pol1);
                fillMap(dictPolOne, polynom_one);
                fillMap(dictPolTwo, polynom_two);
                divPolynom(dictPolOne, dictPolTwo, result);
            }
            break;
        }
        case 5: {
            cout << "Enter Polynom" << endl;
            cin >> pol;
            vector<pair<int, float>> polynom_one = readPolynom(pol);
            fillMap(dictPolOne, polynom_one);
            derPolynom(dictPolOne, result);
            cout << "Result: ";
            printPolynom(result);
            break;
        }
        case 6: {
            cout << "Enter Polynom" << endl;
            cin >> pol;
            vector<pair<int, float>> polynom_one = readPolynom(pol);
            fillMap(dictPolOne, polynom_one);
            intPolynom(dictPolOne, result);
            cout << "Result: ";
            printPolynom(result,true);
            break;
        }
        case 7: {
            cout << "Enter Polynom" << endl;
            cin >> pol;
            cout << "Enter x: " << endl;
            int x;
            cin >> x;
            vector<pair<int, float>> polynom_one = readPolynom(pol);
            int max_power = polynom_one[polynom_one.size() - 1].first;
            fillMap(dictPolOne, polynom_one,true,max_power);
            cout << "Result: " << horPolynom(dictPolOne, x) << endl;
            break;
        }
        case 8: {
            cout << "Enter first Polynom" << endl;
            cin >> pol;
            cout << "Enter second Polynom" << endl;
            cin >> pol1;
            int power = 0;
            vector<pair<int, float>> polynom_one = readPolynom(pol);
            vector<pair<int, float>> polynom_two = readPolynom(pol1);
            maxPower(polynom_one, polynom_two, power);
            fillMap(dictPolOne, polynom_one,true,power);
            fillMap(dictPolTwo, polynom_two,true,power);

            map<int, float> result;
            vector<map<int, float>> polynoms;
            supPolynom(dictPolOne, dictPolTwo, polynoms);

            map<int, float> temp = polynoms[polynoms.size() - 1];


            for (int i = polynoms.size()-2; i >= 0 ; i--) {
                if (temp.size()) {
                    addPolynom(temp, polynoms[i], result);
                    temp = result;
                }
                else {
                    break;
                }

            }
            printPolynom(result);
            break;
        }
        default:
            cout << "Error: Select Wrong Operation" << endl;
            break;
        }
        cout << endl;

        dictPolOne.clear();
        dictPolTwo.clear();
        result.clear();
    }
  


   

    return 0;

}
