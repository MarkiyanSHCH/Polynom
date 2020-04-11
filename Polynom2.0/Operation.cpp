#include "Operation.h"

vector<string> split(const string& fLine)
{
    string result = "";
    vector<string> arr_result;
    for (int n = 0; n < fLine.size(); n++) {
        if (fLine[n] != '+' && fLine[n] != '-') { result += fLine[n]; }
        else {
            if (n == 0) { result += fLine[n]; continue; }
            if ((fLine[n] == '+' || fLine[n] == '-') && result != "") {
                arr_result.push_back(result);
                result = "";
                result += fLine[n];
            }
        }
    }
    if (result != "") { arr_result.push_back(result); }
    return arr_result;
}

vector<pair<int, float>> readPolynom(string& pol) {
    vector<string> Pol_split;
    vector<pair<int, float>> dict;
    vector<float> coeff;
    vector<int> power;
    Pol_split = split(pol);

    for (auto elem : Pol_split) {
        for (int i = 0; i < elem.size(); i++) {
            if (elem[i] == 'x') {
                if (i == elem.size() - 1) { elem += "^1"; }
                if (i == 1 && (elem[i - 1] == '+' || elem[i - 1] == '-')) { elem.insert(1, "1"); }
                if (i == 0) { elem.insert(0, "1"); }
                break;
            }
            if (i == elem.size() - 1) { elem += "x^0"; break; }
        }

        string tempPol = "";

        for (int i = 0; i < elem.size(); i++) {
            switch (elem[i]) {
            case 'x':
                tempPol = elem.substr(0, i);
                coeff.push_back(stoi(tempPol));
                tempPol = "";
                break;

            case '^':
                tempPol = elem.substr(i + 1, elem.size() - 1);
                power.push_back(stoi(tempPol));
                break;
            }
        }
    }


    for (int i = 0; i < coeff.size(); i++) { dict.push_back(make_pair(power[i], coeff[i])); }
    sort(dict.begin(), dict.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.first < b.first; });
    return dict;


}

void maxPower(vector<pair<int, float>> polynom_one , vector<pair<int, float>> polynom_two, int &max_power) {
    max_power = 0;
    if (polynom_one[polynom_one.size() - 1].first > polynom_two[polynom_two.size() - 1].first) { max_power = polynom_one[polynom_one.size() - 1].first; }
    else { max_power = polynom_two[polynom_two.size() - 1].first; }
}

void fillMap(map<int, float>& dict, const vector<pair<int, float>>& polynom, bool isTrue, int max_power) {
    if(isTrue)
        for (int i = 0; i <= max_power; i++) { dict[i] = 0; }
    for (const auto& elem : polynom) { dict[elem.first] = elem.second; }
}

void addPolynom(map<int, float>& firstPol, map<int, float>& secondPol, map<int, float>& result) { for (int i = 0; i < firstPol.size(); i++) { int coeff = firstPol[i] + secondPol[i]; if (coeff != 0) { result[i] = coeff; } } }

void subPolynom(map<int, float>& firstPol, map<int, float>& secondPol, map<int, float>& result) { for (int i = 0; i < firstPol.size(); i++) { float coeff = firstPol[i] - secondPol[i]; if (coeff != 0) { result[i] = coeff; } } }

void multPolynom(map<int, float>& firstPol, map<int, float>& secondPol, map<int, float>& result) {
    result.clear();
    for (auto elemFirst : firstPol) {
        for (auto elemSecond : secondPol) {
            int power = elemFirst.first + elemSecond.first;
            float coeff = elemFirst.second * elemSecond.second;
            if (coeff != 0) { result[power] += coeff; }
        }
    }
}

void derPolynom(map<int, float>& firstPol, map<int, float>& result) {for (auto elemFirst : firstPol) { if (elemFirst.first != 0 && elemFirst.second != 0) { result[elemFirst.first - 1] = elemFirst.second * elemFirst.first; } }
}

void printPolynom(map<int, float>& result, bool isIntegral) {
    for (auto elem = result.begin(); elem != result.end(); elem++) {
        if (elem->first != 0 && elem->second != 0) {
            if (elem->first == 1 && elem->second == 1) {
                if (elem != result.begin()) {
                    cout << "+";
                }
                cout << "x";
            }
            else if (elem->second == 1 && elem->first != 1) {
                cout << "+x^" << elem->first;
            }
            else if (elem->second != 1 && elem->first == 1) {
                if (elem->second > 0) {
                    if (elem != result.begin()) {
                        cout << "+";
                    }
                    cout << elem->second << "x";
                }
                else {
                    if (elem->second == -1) {
                        cout << "-x";
                    }
                    else {
                        cout << elem->second << "x";
                    }
                }
            }
            else {
                if (elem->second > 0) {
                    if (elem != result.begin()) {
                        cout << "+";
                    }
                    cout << elem->second << "x^" << elem->first;
                }
                else {
                    if (elem->second == -1) {
                        cout << "-x^" << elem->first;
                    }
                    else {
                        cout << elem->second << "x^" << elem->first;
                    }
                }

            }
        }
        else if (elem->first == 0 && elem->second != 0) {
            if (elem->second > 0) {
                if (elem != result.begin()) {
                    cout << "+";
                }
                cout << elem->second;
            }
            else {
                cout << elem->second;

            }
        }
    }
    if (isIntegral)
        cout << "+C";
}

void divPolynom(map<int, float>& pol_1, map<int, float>& pol_2, map<int, float>& result) {

    map<int, float>::iterator itr_1;
    itr_1 = pol_1.end();
    --itr_1;
    map<int, float>::iterator itr_2;
    itr_2 = pol_2.end();
    --itr_2;


    if (!(itr_1->first < itr_2->first)) {
        map<int, float> r = pol_1;

        float resCoeff = float(itr_1->second) / itr_2->second;
        int resPower = itr_1->first - itr_2->first;

        map<int, float> mult = { {resPower,resCoeff} };
        map<int, float> resMult;

        result.insert({ resPower,resCoeff });

        multPolynom(pol_2, mult, resMult);

        r.clear();
        subPolynom(pol_1, resMult, r);
        divPolynom(r, pol_2, result);
    }
    else {
        cout << "Result: ";
        printPolynom(result);
        cout << endl;
        cout << "Remains: ";
        printPolynom(pol_1);
        cout << endl;
    }
}

void intPolynom(map<int, float>& Pol, map<int, float>& result) {for (auto elemPol : Pol) { if (elemPol.second != 0){result[elemPol.first + 1] = elemPol.second / (elemPol.first + 1);}}}

int horPolynom(map<int, float>& firstPol, int x) {
    int result = firstPol[firstPol.size() - 1];
    for (int i = firstPol.size() - 2; i >= 0; i--)
        result = result * x + firstPol[i];

    return result;
}

void supPolynom(map<int, float>& firstPol, map<int, float>& secondPol, vector<map<int, float>>& polynoms) {
    map<int, float> result;
    for (auto elem : firstPol) {
        map<int, float> pol_2 = secondPol;
        if (!(elem.first == 0)) {
            for (int i = 0; i < elem.first - 1; i++) {
                multPolynom(pol_2, secondPol, result);
                pol_2 = result;
            }
            map<int, float> coeff = { {0,elem.second} };
            multPolynom(pol_2, coeff, result);
            coeff.clear();
            polynoms.push_back(result);

        }
        else if(elem.first == 0) {
            map<int, float> coeff = { {0,elem.second} };
            polynoms.push_back(coeff);
            coeff.clear();
            
        }
    }


    
}