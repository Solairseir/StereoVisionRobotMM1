#pragma once
#include "opencv.hpp"
#include "ProgramLog.h"
#include "GlobarVars.h"
//********************************
using namespace System;
using namespace std;
using namespace cv;
//********************************
#define DISPARITY_CONST 52
#define COEFFICIENT 10

// ----------------------------------------
// |            |            |            |
// |     NW     |      N     |     NE     |
// |    -45     |      0     |     45     |
// |            |            |            |
// ----------------------------------------
// |            |            |            |
// |     W      |            |     E      |
// |    -90     |            |     90     |
// |            |            |            |
// ----------------------------------------
// |            |            |            |
// |     SW     |     S      |     SE     |
// |    -135    |    180     |     135    |
// |            |            |            |
// ----------------------------------------
