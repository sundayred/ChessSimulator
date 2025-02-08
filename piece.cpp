#include "piece.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

piece::piece(int S, string N, char C) {
    count = S;
    name = N;
    lable = C;
}
