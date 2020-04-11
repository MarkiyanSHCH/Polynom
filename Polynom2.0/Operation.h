#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>
using namespace std;


vector<pair<int, float>> readPolynom(string& pol);
void maxPower(vector<pair<int, float>> polynom_one, vector<pair<int, float>> polynom_two, int& max_power);
void fillMap(map<int, float>& dict, const vector<pair<int, float>>& polynom, bool isTrue = false, int max_power = 0);
void addPolynom(map<int, float>& firstPol, map<int, float>& secondPol, map<int, float>& result);
void subPolynom(map<int, float>& firstPol, map<int, float>& secondPol, map<int, float>& result);
void multPolynom(map<int, float>& firstPol, map<int, float>& secondPol, map<int, float>& result);
void derPolynom(map<int, float>& firstPol, map<int, float>& result);
void printPolynom(map<int, float>& result, bool isIntegral = false);
void divPolynom(map<int, float>& pol_1, map<int, float>& pol_2, map<int, float>& result);
void intPolynom(map<int, float>& Pol, map<int, float>& result);
int horPolynom(map<int, float>& firstPol, int x);
void supPolynom(map<int, float>& firstPol, map<int, float>& secondPol, vector<map<int, float>>& polynoms);