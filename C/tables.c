#ifndef __HEADER__
#define __HEADER__
#include "marchingCubes.h"
#endif

int CaseRotationFlip[256][3] =
 {{1, 24, 1},
  {2, 19, 1},
  {2, 17, 1},
  {3, 17, 1},
  {2, 24, 1},
  {4, 24, 1},
  {3, 24, 1},
  {6, 10, 1},
  {2, 15, 1},
  {3, 19, 1},
  {4, 17, 1},
  {6, 9, 1},
  {3, 9, 1},
  {6, 8, 1},
  {6, 1, 1},
  {9, 23, -1},
  {2, 20, 1},
  {3, 18, 1},
  {4, 7, 1},
  {6, 16, 1},
  {5, 24, 1},
  {7, 5, 1},
  {7, 24, 1},
  {12, 9, 1},
  {4, 20, 1},
  {6, 22, 1},
  {8, 24, 1},
  {10, 24, -1},
  {7, 9, 1},
  {15, 24, -1},
  {13, 20, -1},
  {6, 20, -1},
  {2, 21, 1},
  {4, 6, 1},
  {3, 16, 1},
  {6, 4, 1},
  {4, 16, 1},
  {8, 23, 1},
  {6, 14, 1},
  {10, 23, -1},
  {5, 21, 1},
  {7, 10, 1},
  {7, 16, 1},
  {15, 9, 1},
  {7, 2, 1},
  {13, 8, 1},
  {12, 23, -1},
  {6, 6, -1},
  {3, 6, 1},
  {6, 17, 1},
  {6, 18, 1},
  {9, 18, 1},
  {7, 4, 1},
  {13, 17, 1},
  {15, 18, 1},
  {6, 13, -1},
  {7, 6, 1},
  {12, 16, 1},
  {13, 18, 1},
  {6, 2, -1},
  {11, 24, 1},
  {7, 3, -1},
  {7, 12, -1},
  {3, 12, -1},
  {2, 23, 1},
  {5, 23, 1},
  {4, 23, 1},
  {7, 1, 1},
  {3, 14, 1},
  {7, 14, 1},
  {6, 21, 1},
  {15, 23, -1},
  {4, 15, 1},
  {7, 19, 1},
  {8, 19, 1},
  {13, 23, -1},
  {6, 11, 1},
  {12, 17, -1},
  {10, 19, -1},
  {6, 23, -1},
  {4, 12, 1},
  {7, 18, 1},
  {8, 22, 1},
  {13, 16, 1},
  {7, 13, 1},
  {11, 23, 1},
  {13, 21, 1},
  {7, 15, -1},
  {8, 21, 1},
  {13, 22, 1},
  {14, 24, -1},
  {8, 15, -1},
  {13, 11, 1},
  {7, 7, -1},
  {8, 12, -1},
  {4, 22, -1},
  {3, 23, 1},
  {7, 23, 1},
  {6, 24, 1},
  {12, 18, 1},
  {6, 7, 1},
  {13, 19, -1},
  {9, 24, 1},
  {6, 19, -1},
  {7, 21, 1},
  {11, 18, 1},
  {13, 24, 1},
  {7, 20, -1},
  {15, 16, -1},
  {7, 22, -1},
  {6, 15, -1},
  {3, 22, -1},
  {6, 3, 1},
  {15, 17, 1},
  {10, 22, -1},
  {6, 12, -1},
  {12, 24, 1},
  {7, 11, -1},
  {6, 5, -1},
  {3, 15, -1},
  {13, 10, -1},
  {7, 8, -1},
  {8, 20, -1},
  {4, 9, -1},
  {7, 17, -1},
  {5, 22, -1},
  {4, 18, -1},
  {2, 22, -1},
  {2, 22, 1},
  {4, 18, 1},
  {5, 22, 1},
  {7, 17, 1},
  {4, 9, 1},
  {8, 20, 1},
  {7, 8, 1},
  {13, 10, 1},
  {3, 15, 1},
  {6, 5, 1},
  {7, 11, 1},
  {12, 24, -1},
  {6, 12, 1},
  {10, 22, 1},
  {15, 17, -1},
  {6, 3, -1},
  {3, 22, 1},
  {6, 15, 1},
  {7, 22, 1},
  {15, 16, 1},
  {7, 20, 1},
  {13, 24, -1},
  {11, 18, -1},
  {7, 21, -1},
  {6, 19, 1},
  {9, 24, -1},
  {13, 19, 1},
  {6, 7, -1},
  {12, 18, -1},
  {6, 24, -1},
  {7, 23, -1},
  {3, 23, -1},
  {4, 22, 1},
  {8, 12, 1},
  {7, 7, 1},
  {13, 11, -1},
  {8, 15, 1},
  {14, 24, 1},
  {13, 22, -1},
  {8, 21, -1},
  {7, 15, 1},
  {13, 21, -1},
  {11, 23, -1},
  {7, 13, -1},
  {13, 16, -1},
  {8, 22, -1},
  {7, 18, -1},
  {4, 12, -1},
  {6, 23, 1},
  {10, 19, 1},
  {12, 17, 1},
  {6, 11, -1},
  {13, 23, 1},
  {8, 19, -1},
  {7, 19, -1},
  {4, 15, -1},
  {15, 23, 1},
  {6, 21, -1},
  {7, 14, -1},
  {3, 14, -1},
  {7, 1, -1},
  {4, 23, -1},
  {5, 23, -1},
  {2, 23, -1},
  {3, 12, 1},
  {7, 12, 1},
  {7, 3, 1},
  {11, 24, -1},
  {6, 2, 1},
  {13, 18, -1},
  {12, 16, -1},
  {7, 6, -1},
  {6, 13, 1},
  {15, 18, -1},
  {13, 17, -1},
  {7, 4, -1},
  {9, 18, -1},
  {6, 18, -1},
  {6, 17, -1},
  {3, 6, -1},
  {6, 6, 1},
  {12, 23, 1},
  {13, 8, -1},
  {7, 2, -1},
  {15, 9, -1},
  {7, 16, -1},
  {7, 10, -1},
  {5, 21, -1},
  {10, 23, 1},
  {6, 14, -1},
  {8, 23, -1},
  {4, 16, -1},
  {6, 4, -1},
  {3, 16, -1},
  {4, 6, -1},
  {2, 21, -1},
  {6, 20, 1},
  {13, 20, 1},
  {15, 24, 1},
  {7, 9, -1},
  {10, 24, 1},
  {8, 24, -1},
  {6, 22, -1},
  {4, 20, -1},
  {12, 9, -1},
  {7, 24, -1},
  {7, 5, -1},
  {5, 24, -1},
  {6, 16, -1},
  {4, 7, -1},
  {3, 18, -1},
  {2, 20, -1},
  {9, 23, 1},
  {6, 1, -1},
  {6, 8, -1},
  {3, 9, -1},
  {6, 9, -1},
  {4, 17, -1},
  {3, 19, -1},
  {2, 15, -1},
  {6, 10, -1},
  {3, 24, -1},
  {4, 24, -1},
  {2, 24, -1},
  {3, 17, -1},
  {2, 17, -1},
  {2, 19, -1},
  {1, 24, -1}};

size_t indexArray[8][3] =
{{0, 0, 0},
 {1, 0, 0},
 {1, 1, 0},
 {0, 1, 0},
 {0, 0, 1},
 {1, 0, 1},
 {1, 1, 1},
 {0, 1, 1}};

unsigned edgesLengths[254] =
  {3, 3, 6, 3, 0, 6, 9, 3, 6, 0, 9, 6, 9, 9, 6, 3, 6, 0, 9, 0,
   0, 0, 12, 0, 9, 0, 12, 0, 12, 0, 9, 3, 0, 6, 9, 0, 0, 9, 12,
   0, 0, 0, 12, 0, 0, 12, 9, 6, 9, 9, 6, 0, 0, 12, 9, 0, 12, 0,
   9, 0, 0, 0, 6, 3, 0, 0, 0, 6, 0, 9, 12, 0, 0, 0, 0, 9, 12, 12,
   9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 9, 12,
   9, 0, 6, 9, 0, 0, 0, 0, 12, 0, 9, 6, 9, 12, 12, 9, 12, 0, 9,
   6, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 6, 9, 0, 12,
   9, 12, 12, 9, 6, 9, 0, 12, 0, 0, 0, 0, 9, 6, 0, 9, 12, 9, 0,
   6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 12, 12,
   9, 0, 0, 0, 0, 12, 9, 0, 6, 0, 0, 0, 3, 6, 0, 0, 0, 9, 0, 12,
   0, 9, 12, 0, 0, 6, 9, 9, 6, 9, 12, 0, 0, 12, 0, 0, 0, 12, 9,
   0, 0, 9, 6, 0, 3, 9, 0, 12, 0, 12, 0, 9, 0, 12, 0, 0, 0, 9, 0,
   6, 3, 6, 9, 9, 6, 9, 0, 6, 3, 9, 6, 0, 3, 6, 3, 3};

unsigned EdgePoints[13][3] =
 {{1, 1, 2},
  {2, 2, 3},
  {3, 3, 4},
  {4, 4, 1},
  {5, 5, 6},
  {6, 6, 7},
  {7, 7, 8},
  {8, 8, 5},
  {9, 1, 5},
  {10, 2, 6},
  {11, 3, 7},
  {12, 4, 8},
  {13, 9, 9}};


// https://stackoverflow.com/questions/1083658/do-jagged-arrays-exist-in-c-c
unsigned edgesRow0[] = {4, 9, 1};
unsigned edgesRow1[] = {1, 10, 2};
unsigned edgesRow2[] = {9, 10, 4, 10, 2, 4};
unsigned edgesRow3[] = {2, 11, 3};
unsigned edgesRow4[] = {0};
unsigned edgesRow5[] = {10, 11, 1, 11, 3, 1};
unsigned edgesRow6[] = {4, 9, 3, 3, 9, 11, 9, 10, 11};
unsigned edgesRow7[] = {12, 4, 3};
unsigned edgesRow8[] = {12, 9, 3, 9, 1, 3};
unsigned edgesRow9[] = {0};
unsigned edgesRow10[] = {3, 12, 2, 2, 12, 10, 12, 9, 10};
unsigned edgesRow11[] = {4, 2, 12, 2, 11, 12};
unsigned edgesRow12[] = {2, 11, 1, 1, 11, 9, 11, 12, 9};
unsigned edgesRow13[] = {1, 10, 4, 4, 10, 12, 10, 11, 12};
unsigned edgesRow14[] = {11, 9, 10, 11, 12, 9};
unsigned edgesRow15[] = {8, 5, 9};
unsigned edgesRow16[] = {5, 1, 8, 1, 4, 8};
unsigned edgesRow17[] = {0};
unsigned edgesRow18[] = {10, 2, 5, 5, 2, 8, 2, 4, 8};
unsigned edgesRow19[] = {0};
unsigned edgesRow20[] = {0};
unsigned edgesRow21[] = {0};
unsigned edgesRow22[] = {3, 4, 8, 3, 8, 10, 3, 10, 11, 8, 5, 10};
unsigned edgesRow23[] = {0};
unsigned edgesRow24[] = {8, 5, 12, 12, 5, 3, 5, 1, 3};
unsigned edgesRow25[] = {0};
unsigned edgesRow26[] = {2, 5, 10, 2, 3, 8, 2, 8, 5, 8, 3, 12};
unsigned edgesRow27[] = {0};
unsigned edgesRow28[] = {2, 11, 12, 2, 12, 5, 2, 5, 1, 8, 12, 5};
unsigned edgesRow29[] = {0};
unsigned edgesRow30[] = {8, 5, 12, 5, 10, 12, 12, 10, 11};
unsigned edgesRow31[] = {6, 10, 5};
unsigned edgesRow32[] = {0};
unsigned edgesRow33[] = {1, 5, 2, 5, 6, 2};
unsigned edgesRow34[] = {5, 6, 9, 9, 6, 4, 6, 2, 4};
unsigned edgesRow35[] = {0};
unsigned edgesRow36[] = {0};
unsigned edgesRow37[] = {11, 3, 6, 6, 3, 5, 3, 1, 5};
unsigned edgesRow38[] = {6, 9, 5, 6, 11, 4, 6, 4, 9, 4, 11, 3};
unsigned edgesRow39[] = {0};
unsigned edgesRow40[] = {0};
unsigned edgesRow41[] = {0};
unsigned edgesRow42[] = {3, 6, 2, 3, 9, 6, 3, 12, 9, 5, 9, 6};
unsigned edgesRow43[] = {0};
unsigned edgesRow44[] = {0};
unsigned edgesRow45[] = {6, 1, 5, 6, 12, 1, 6, 11, 12, 1, 12, 4};
unsigned edgesRow46[] = {5, 6, 9, 6, 11, 9, 9, 11, 12};
unsigned edgesRow47[] = {8, 6, 9, 6, 10, 9};
unsigned edgesRow48[] = {1, 4, 10, 10, 4, 6, 4, 8, 6};
unsigned edgesRow49[] = {9, 8, 1, 1, 8, 2, 8, 6, 2};
unsigned edgesRow50[] = {4, 8, 6, 4, 6, 2};
unsigned edgesRow51[] = {0};
unsigned edgesRow52[] = {0};
unsigned edgesRow53[] = {9, 3, 1, 9, 6, 3, 9, 8, 6, 11, 6, 3};
unsigned edgesRow54[] = {11, 3, 6, 3, 4, 6, 6, 4, 8};
unsigned edgesRow55[] = {0};
unsigned edgesRow56[] = {10, 1, 3, 10, 3, 8, 10, 8, 6, 3, 12, 8};
unsigned edgesRow57[] = {0};
unsigned edgesRow58[] = {3, 12, 2, 12, 8, 2, 2, 8, 6};
unsigned edgesRow59[] = {0};
unsigned edgesRow60[] = {0};
unsigned edgesRow61[] = {0};
unsigned edgesRow62[] = {12, 8, 11, 11, 8, 6};
unsigned edgesRow63[] = {6, 7, 11};
unsigned edgesRow64[] = {0};
unsigned edgesRow65[] = {0};
unsigned edgesRow66[] = {0};
unsigned edgesRow67[] = {2, 6, 3, 6, 7, 3};
unsigned edgesRow68[] = {0};
unsigned edgesRow69[] = {6, 7, 10, 10, 7, 1, 7, 3, 1};
unsigned edgesRow70[] = {6, 7, 3, 6, 3, 9, 6, 9, 10, 4, 3, 9};
unsigned edgesRow71[] = {0};
unsigned edgesRow72[] = {0};
unsigned edgesRow73[] = {0};
unsigned edgesRow74[] = {0};
unsigned edgesRow75[] = {12, 4, 7, 7, 4, 6, 4, 2, 6};
unsigned edgesRow76[] = {1, 12, 9, 1, 6, 12, 1, 2, 6, 12, 6, 7};
unsigned edgesRow77[] = {4, 7, 12, 4, 1, 6, 4, 6, 7, 6, 1, 10};
unsigned edgesRow78[] = {6, 7, 10, 7, 12, 10, 10, 12, 9};
unsigned edgesRow79[] = {0};
unsigned edgesRow80[] = {0};
unsigned edgesRow81[] = {0};
unsigned edgesRow82[] = {0};
unsigned edgesRow83[] = {0};
unsigned edgesRow84[] = {0};
unsigned edgesRow85[] = {0};
unsigned edgesRow86[] = {0};
unsigned edgesRow87[] = {0};
unsigned edgesRow88[] = {0};
unsigned edgesRow89[] = {0};
unsigned edgesRow90[] = {0};
unsigned edgesRow91[] = {0};
unsigned edgesRow92[] = {0};
unsigned edgesRow93[] = {0};
unsigned edgesRow94[] = {0};
unsigned edgesRow95[] = {5, 7, 10, 7, 11, 10};
unsigned edgesRow96[] = {0};
unsigned edgesRow97[] = {2, 1, 11, 11, 1, 7, 1, 5, 7};
unsigned edgesRow98[] = {9, 5, 7, 9, 7, 2, 9, 2, 4, 7, 11, 2};
unsigned edgesRow99[] = {10, 5, 2, 2, 5, 3, 5, 7, 3};
unsigned edgesRow100[] = {0};
unsigned edgesRow101[] = {3, 1, 5, 3, 5, 7};
unsigned edgesRow102[] = {4, 9, 3, 9, 5, 3, 3, 5, 7};
unsigned edgesRow103[] = {0};
unsigned edgesRow104[] = {0};
unsigned edgesRow105[] = {0};
unsigned edgesRow106[] = {0};
unsigned edgesRow107[] = {10, 5, 7, 10, 7, 4, 10, 4, 2, 12, 7, 4};
unsigned edgesRow108[] = {0};
unsigned edgesRow109[] = {12, 4, 7, 4, 1, 7, 7, 1, 5};
unsigned edgesRow110[] = {9, 5, 12, 12, 5, 7};
unsigned edgesRow111[] = {7, 11, 8, 8, 11, 9, 11, 10, 9};
unsigned edgesRow112[] = {1, 11, 10, 1, 8, 11, 1, 4, 8, 7, 8, 11};
unsigned edgesRow113[] = {8, 1, 9, 8, 7, 2, 8, 2, 1, 2, 7, 11};
unsigned edgesRow114[] = {7, 11, 8, 11, 2, 8, 8, 2, 4};
unsigned edgesRow115[] = {2, 10, 9, 2, 9, 7, 2, 7, 3, 9, 8, 7};
unsigned edgesRow116[] = {0};
unsigned edgesRow117[] = {9, 8, 1, 8, 7, 1, 1, 7, 3};
unsigned edgesRow118[] = {8, 7, 4, 4, 7, 3};
unsigned edgesRow119[] = {0};
unsigned edgesRow120[] = {0};
unsigned edgesRow121[] = {0};
unsigned edgesRow122[] = {0};
unsigned edgesRow123[] = {0};
unsigned edgesRow124[] = {0};
unsigned edgesRow125[] = {0};
unsigned edgesRow126[] = {8, 7, 12};
unsigned edgesRow127[] = {8, 12, 7};
unsigned edgesRow128[] = {0};
unsigned edgesRow129[] = {0};
unsigned edgesRow130[] = {0};
unsigned edgesRow131[] = {0};
unsigned edgesRow132[] = {0};
unsigned edgesRow133[] = {0};
unsigned edgesRow134[] = {0};
unsigned edgesRow135[] = {8, 4, 7, 4, 3, 7};
unsigned edgesRow136[] = {9, 1, 8, 8, 1, 7, 1, 3, 7};
unsigned edgesRow137[] = {0};
unsigned edgesRow138[] = {2, 9, 10, 2, 7, 9, 2, 3, 7, 9, 7, 8};
unsigned edgesRow139[] = {7, 8, 11, 11, 8, 2, 8, 4, 2};
unsigned edgesRow140[] = {8, 9, 1, 8, 2, 7, 8, 1, 2, 2, 11, 7};
unsigned edgesRow141[] = {1, 10, 11, 1, 11, 8, 1, 8, 4, 7, 11, 8};
unsigned edgesRow142[] = {7, 8, 11, 8, 9, 11, 11, 9, 10};
unsigned edgesRow143[] = {9, 12, 5, 12, 7, 5};
unsigned edgesRow144[] = {12, 7, 4, 4, 7, 1, 7, 5, 1};
unsigned edgesRow145[] = {0};
unsigned edgesRow146[] = {10, 7, 5, 10, 4, 7, 10, 2, 4, 12, 4, 7};
unsigned edgesRow147[] = {0};
unsigned edgesRow148[] = {0};
unsigned edgesRow149[] = {0};
unsigned edgesRow150[] = {0};
unsigned edgesRow151[] = {4, 3, 9, 9, 3, 5, 3, 7, 5};
unsigned edgesRow152[] = {3, 5, 1, 3, 7, 5};
unsigned edgesRow153[] = {0};
unsigned edgesRow154[] = {10, 2, 5, 2, 3, 5, 5, 3, 7};
unsigned edgesRow155[] = {9, 7, 5, 9, 2, 7, 9, 4, 2, 7, 2, 11};
unsigned edgesRow156[] = {2, 11, 1, 11, 7, 1, 1, 7, 5};
unsigned edgesRow157[] = {0};
unsigned edgesRow158[] = {5, 10, 7, 7, 10, 11};
unsigned edgesRow159[] = {0};
unsigned edgesRow160[] = {0};
unsigned edgesRow161[] = {0};
unsigned edgesRow162[] = {0};
unsigned edgesRow163[] = {0};
unsigned edgesRow164[] = {0};
unsigned edgesRow165[] = {0};
unsigned edgesRow166[] = {0};
unsigned edgesRow167[] = {0};
unsigned edgesRow168[] = {0};
unsigned edgesRow169[] = {0};
unsigned edgesRow170[] = {0};
unsigned edgesRow171[] = {0};
unsigned edgesRow172[] = {0};
unsigned edgesRow173[] = {0};
unsigned edgesRow174[] = {0};
unsigned edgesRow175[] = {6, 10, 7, 7, 10, 12, 10, 9, 12};
unsigned edgesRow176[] = {4, 12, 7, 4, 6, 1, 4, 7, 6, 6, 10, 1};
unsigned edgesRow177[] = {1, 9, 12, 1, 12, 6, 1, 6, 2, 12, 7, 6};
unsigned edgesRow178[] = {12, 7, 4, 7, 6, 4, 4, 6, 2};
unsigned edgesRow179[] = {0};
unsigned edgesRow180[] = {0};
unsigned edgesRow181[] = {0};
unsigned edgesRow182[] = {0};
unsigned edgesRow183[] = {6, 3, 7, 6, 9, 3, 6, 10, 9, 4, 9, 3};
unsigned edgesRow184[] = {6, 10, 7, 10, 1, 7, 7, 1, 3};
unsigned edgesRow185[] = {0};
unsigned edgesRow186[] = {2, 3, 6, 6, 3, 7};
unsigned edgesRow187[] = {0};
unsigned edgesRow188[] = {0};
unsigned edgesRow189[] = {0};
unsigned edgesRow190[] = {6, 11, 7};
unsigned edgesRow191[] = {12, 11, 8, 11, 6, 8};
unsigned edgesRow192[] = {0};
unsigned edgesRow193[] = {0};
unsigned edgesRow194[] = {0};
unsigned edgesRow195[] = {3, 2, 12, 12, 2, 8, 2, 6, 8};
unsigned edgesRow196[] = {0};
unsigned edgesRow197[] = {10, 3, 1, 10, 8, 3, 10, 6, 8, 3, 8, 12};
unsigned edgesRow198[] = {0};
unsigned edgesRow199[] = {11, 6, 3, 3, 6, 4, 6, 8, 4};
unsigned edgesRow200[] = {9, 1, 3, 9, 3, 6, 9, 6, 8, 11, 3, 6};
unsigned edgesRow201[] = {0};
unsigned edgesRow202[] = {0};
unsigned edgesRow203[] = {4, 6, 8, 4, 2, 6};
unsigned edgesRow204[] = {9, 1, 8, 1, 2, 8, 8, 2, 6};
unsigned edgesRow205[] = {1, 10, 4, 10, 6, 4, 4, 6, 8};
unsigned edgesRow206[] = {8, 9, 6, 6, 9, 10};
unsigned edgesRow207[] = {5, 9, 6, 6, 9, 11, 9, 12, 11};
unsigned edgesRow208[] = {6, 5, 1, 6, 1, 12, 6, 12, 11, 1, 4, 12};
unsigned edgesRow209[] = {0};
unsigned edgesRow210[] = {0};
unsigned edgesRow211[] = {3, 2, 6, 3, 6, 9, 3, 9, 12, 5, 6, 9};
unsigned edgesRow212[] = {0};
unsigned edgesRow213[] = {0};
unsigned edgesRow214[] = {0};
unsigned edgesRow215[] = {6, 5, 9, 6, 4, 11, 6, 9, 4, 4, 3, 11};
unsigned edgesRow216[] = {11, 6, 3, 6, 5, 3, 3, 5, 1};
unsigned edgesRow217[] = {0};
unsigned edgesRow218[] = {0};
unsigned edgesRow219[] = {5, 9, 6, 9, 4, 6, 6, 4, 2};
unsigned edgesRow220[] = {1, 2, 5, 5, 2, 6};
unsigned edgesRow221[] = {0};
unsigned edgesRow222[] = {6, 5, 10};
unsigned edgesRow223[] = {8, 12, 5, 5, 12, 10, 12, 11, 10};
unsigned edgesRow224[] = {0};
unsigned edgesRow225[] = {2, 12, 11, 2, 5, 12, 2, 1, 5, 8, 5, 12};
unsigned edgesRow226[] = {0};
unsigned edgesRow227[] = {2, 10, 5, 2, 8, 3, 2, 5, 8, 8, 12, 3};
unsigned edgesRow228[] = {0};
unsigned edgesRow229[] = {8, 12, 5, 12, 3, 5, 5, 3, 1};
unsigned edgesRow230[] = {0};
unsigned edgesRow231[] = {3, 8, 4, 3, 10, 8, 3, 11, 10, 8, 10, 5};
unsigned edgesRow232[] = {0};
unsigned edgesRow233[] = {0};
unsigned edgesRow234[] = {0};
unsigned edgesRow235[] = {10, 5, 2, 5, 8, 2, 2, 8, 4};
unsigned edgesRow236[] = {0};
unsigned edgesRow237[] = {5, 8, 1, 1, 8, 4};
unsigned edgesRow238[] = {8, 9, 5};
unsigned edgesRow239[] = {11, 10, 9, 11, 9, 12};
unsigned edgesRow240[] = {1, 4, 10, 4, 12, 10, 10, 12, 11};
unsigned edgesRow241[] = {2, 1, 11, 1, 9, 11, 11, 9, 12};
unsigned edgesRow242[] = {4, 12, 2, 2, 12, 11};
unsigned edgesRow243[] = {3, 2, 12, 2, 10, 12, 12, 10, 9};
unsigned edgesRow244[] = {0};
unsigned edgesRow245[] = {12, 3, 9, 9, 3, 1};
unsigned edgesRow246[] = {12, 3, 4};
unsigned edgesRow247[] = {4, 3, 9, 3, 11, 9, 9, 11, 10};
unsigned edgesRow248[] = {10, 1, 11, 11, 1, 3};
unsigned edgesRow249[] = {0};
unsigned edgesRow250[] = {2, 3, 11};
unsigned edgesRow251[] = {9, 4, 10, 10, 4, 2};
unsigned edgesRow252[] = {1, 2, 10};
unsigned edgesRow253[] = {4, 1, 9};
unsigned (*Edges[])[] = {&edgesRow0, &edgesRow1, &edgesRow2, &edgesRow3, &edgesRow4, &edgesRow5, &edgesRow6, &edgesRow7, &edgesRow8, &edgesRow9, &edgesRow10, &edgesRow11, &edgesRow12, &edgesRow13, &edgesRow14, &edgesRow15, &edgesRow16, &edgesRow17, &edgesRow18, &edgesRow19, &edgesRow20, &edgesRow21, &edgesRow22, &edgesRow23, &edgesRow24, &edgesRow25, &edgesRow26, &edgesRow27, &edgesRow28, &edgesRow29, &edgesRow30, &edgesRow31, &edgesRow32, &edgesRow33, &edgesRow34, &edgesRow35, &edgesRow36,
   &edgesRow37, &edgesRow38, &edgesRow39, &edgesRow40, &edgesRow41, &edgesRow42, &edgesRow43, &edgesRow44, &edgesRow45, &edgesRow46, &edgesRow47, &edgesRow48, &edgesRow49, &edgesRow50, &edgesRow51, &edgesRow52, &edgesRow53, &edgesRow54, &edgesRow55, &edgesRow56, &edgesRow57, &edgesRow58, &edgesRow59, &edgesRow60, &edgesRow61, &edgesRow62, &edgesRow63, &edgesRow64, &edgesRow65, &edgesRow66, &edgesRow67, &edgesRow68, &edgesRow69, &edgesRow70, &edgesRow71, &edgesRow72, &edgesRow73, &edgesRow74,
   &edgesRow75, &edgesRow76, &edgesRow77, &edgesRow78, &edgesRow79, &edgesRow80, &edgesRow81, &edgesRow82, &edgesRow83, &edgesRow84, &edgesRow85, &edgesRow86, &edgesRow87, &edgesRow88, &edgesRow89, &edgesRow90, &edgesRow91, &edgesRow92, &edgesRow93, &edgesRow94, &edgesRow95, &edgesRow96, &edgesRow97, &edgesRow98, &edgesRow99, &edgesRow100, &edgesRow101, &edgesRow102, &edgesRow103, &edgesRow104, &edgesRow105, &edgesRow106, &edgesRow107, &edgesRow108, &edgesRow109, &edgesRow110, &edgesRow111,
   &edgesRow112, &edgesRow113, &edgesRow114, &edgesRow115, &edgesRow116, &edgesRow117, &edgesRow118, &edgesRow119, &edgesRow120, &edgesRow121, &edgesRow122, &edgesRow123, &edgesRow124, &edgesRow125, &edgesRow126, &edgesRow127, &edgesRow128, &edgesRow129, &edgesRow130, &edgesRow131, &edgesRow132, &edgesRow133, &edgesRow134, &edgesRow135, &edgesRow136, &edgesRow137, &edgesRow138, &edgesRow139, &edgesRow140, &edgesRow141, &edgesRow142, &edgesRow143, &edgesRow144, &edgesRow145, &edgesRow146,
   &edgesRow147, &edgesRow148, &edgesRow149, &edgesRow150, &edgesRow151, &edgesRow152, &edgesRow153, &edgesRow154, &edgesRow155, &edgesRow156, &edgesRow157, &edgesRow158, &edgesRow159, &edgesRow160, &edgesRow161, &edgesRow162, &edgesRow163, &edgesRow164, &edgesRow165, &edgesRow166, &edgesRow167, &edgesRow168, &edgesRow169, &edgesRow170, &edgesRow171, &edgesRow172, &edgesRow173, &edgesRow174, &edgesRow175, &edgesRow176, &edgesRow177, &edgesRow178, &edgesRow179, &edgesRow180, &edgesRow181,
   &edgesRow182, &edgesRow183, &edgesRow184, &edgesRow185, &edgesRow186, &edgesRow187, &edgesRow188, &edgesRow189, &edgesRow190, &edgesRow191, &edgesRow192, &edgesRow193, &edgesRow194, &edgesRow195, &edgesRow196, &edgesRow197, &edgesRow198, &edgesRow199, &edgesRow200, &edgesRow201, &edgesRow202, &edgesRow203, &edgesRow204, &edgesRow205, &edgesRow206, &edgesRow207, &edgesRow208, &edgesRow209, &edgesRow210, &edgesRow211, &edgesRow212, &edgesRow213, &edgesRow214, &edgesRow215, &edgesRow216,
   &edgesRow217, &edgesRow218, &edgesRow219, &edgesRow220, &edgesRow221, &edgesRow222, &edgesRow223, &edgesRow224, &edgesRow225, &edgesRow226, &edgesRow227, &edgesRow228, &edgesRow229, &edgesRow230, &edgesRow231, &edgesRow232, &edgesRow233, &edgesRow234, &edgesRow235, &edgesRow236, &edgesRow237, &edgesRow238, &edgesRow239, &edgesRow240, &edgesRow241, &edgesRow242, &edgesRow243, &edgesRow244, &edgesRow245, &edgesRow246, &edgesRow247, &edgesRow248, &edgesRow249, &edgesRow250, &edgesRow251,
   &edgesRow252, &edgesRow253};

/* Special cases */
unsigned facesRow0[] = {0};
unsigned facesRow1[] = {0};
unsigned facesRow2[] = {0};
unsigned facesRow3[] = {0};
unsigned facesRow4[] = {5};
unsigned facesRow5[] = {0};
unsigned facesRow6[] = {0};
unsigned facesRow7[] = {0};
unsigned facesRow8[] = {0};
unsigned facesRow9[] = {-5};
unsigned facesRow10[] = {0};
unsigned facesRow11[] = {0};
unsigned facesRow12[] = {0};
unsigned facesRow13[] = {0};
unsigned facesRow14[] = {0};
unsigned facesRow15[] = {0};
unsigned facesRow16[] = {0};
unsigned facesRow17[] = {-1};
unsigned facesRow18[] = {0};
unsigned facesRow19[] = {7};
unsigned facesRow20[] = {5, 7};
unsigned facesRow21[] = {-1, 7};
unsigned facesRow22[] = {0};
unsigned facesRow23[] = {-4};
unsigned facesRow24[] = {0};
unsigned facesRow25[] = {-5, -1, -4, 7};
unsigned facesRow26[] = {0};
unsigned facesRow27[] = {-4, 7};
unsigned facesRow28[] = {0};
unsigned facesRow29[] = {-4, -1, 7};
unsigned facesRow30[] = {0};
unsigned facesRow31[] = {0};
unsigned facesRow32[] = {1};
unsigned facesRow33[] = {0};
unsigned facesRow34[] = {0};
unsigned facesRow35[] = {-2};
unsigned facesRow36[] = {-2, 1, 5, -7};
unsigned facesRow37[] = {0};
unsigned facesRow38[] = {0};
unsigned facesRow39[] = {-7};
unsigned facesRow40[] = {1, -7};
unsigned facesRow41[] = {-5, -7};
unsigned facesRow42[] = {0};
unsigned facesRow43[] = {-2, -7};
unsigned facesRow44[] = {-2, 1, -7};
unsigned facesRow45[] = {0};
unsigned facesRow46[] = {0};
unsigned facesRow47[] = {0};
unsigned facesRow48[] = {0};
unsigned facesRow49[] = {0};
unsigned facesRow50[] = {0};
unsigned facesRow51[] = {-2, 7};
unsigned facesRow52[] = {5, -2, 7};
unsigned facesRow53[] = {0};
unsigned facesRow54[] = {0};
unsigned facesRow55[] = {-4, -7};
unsigned facesRow56[] = {0};
unsigned facesRow57[] = {-4, -5, -7};
unsigned facesRow58[] = {0};
unsigned facesRow59[] = {-2, -4, 7};
unsigned facesRow60[] = {2, -7};
unsigned facesRow61[] = {4, 7};
unsigned facesRow62[] = {0};
unsigned facesRow63[] = {0};
unsigned facesRow64[] = {7};
unsigned facesRow65[] = {2};
unsigned facesRow66[] = {2, 7};
unsigned facesRow67[] = {0};
unsigned facesRow68[] = {5, 7};
unsigned facesRow69[] = {0};
unsigned facesRow70[] = {0};
unsigned facesRow71[] = {3};
unsigned facesRow72[] = {3, 7};
unsigned facesRow73[] = {-5, 3, 2, 7};
unsigned facesRow74[] = {2, 3, 7};
unsigned facesRow75[] = {0};
unsigned facesRow76[] = {0};
unsigned facesRow77[] = {0};
unsigned facesRow78[] = {0};
unsigned facesRow79[] = {6};
unsigned facesRow80[] = {6, 7};
unsigned facesRow81[] = {6, -1, 2, -7};
unsigned facesRow82[] = {2, 6, 7};
unsigned facesRow83[] = {6, 7};
unsigned facesRow84[] = {6, 5, 7};
unsigned facesRow85[] = {6, -1, 7};
unsigned facesRow86[] = {-6, -7};
unsigned facesRow87[] = {6, 3, -4, -7};
unsigned facesRow88[] = {6, 3, 7};
unsigned facesRow89[] = {-5, -1, 6, 3, 2, -4, 7};
unsigned facesRow90[] = {-3, -6, -2, 7};
unsigned facesRow91[] = {-4, 6, 7};
unsigned facesRow92[] = {-6, -7};
unsigned facesRow93[] = {-6, 4, 1, 7};
unsigned facesRow94[] = {-6};
unsigned facesRow95[] = {0};
unsigned facesRow96[] = {1, 7};
unsigned facesRow97[] = {0};
unsigned facesRow98[] = {0};
unsigned facesRow99[] = {0};
unsigned facesRow100[] = {5, 1, 7};
unsigned facesRow101[] = {0};
unsigned facesRow102[] = {0};
unsigned facesRow103[] = {3, -7};
unsigned facesRow104[] = {1, 3, 7};
unsigned facesRow105[] = {-5, 3, -7};
unsigned facesRow106[] = {-3, 7};
unsigned facesRow107[] = {0};
unsigned facesRow108[] = {-1, -7};
unsigned facesRow109[] = {0};
unsigned facesRow110[] = {0};
unsigned facesRow111[] = {0};
unsigned facesRow112[] = {0};
unsigned facesRow113[] = {0};
unsigned facesRow114[] = {0};
unsigned facesRow115[] = {0};
unsigned facesRow116[] = {-5, -7};
unsigned facesRow117[] = {0};
unsigned facesRow118[] = {0};
unsigned facesRow119[] = {-4, 3, -7};
unsigned facesRow120[] = {-3, -7};
unsigned facesRow121[] = {4, -3, 5, -7};
unsigned facesRow122[] = {-3};
unsigned facesRow123[] = {4, -7};
unsigned facesRow124[] = {-7};
unsigned facesRow125[] = {4};
unsigned facesRow126[] = {0};
unsigned facesRow127[] = {0};
unsigned facesRow128[] = {4};
unsigned facesRow129[] = {-7};
unsigned facesRow130[] = {4, -7};
unsigned facesRow131[] = {-3};
unsigned facesRow132[] = {4, -3, 5, -7};
unsigned facesRow133[] = {-3, -7};
unsigned facesRow134[] = {4, -3, -7};
unsigned facesRow135[] = {0};
unsigned facesRow136[] = {0};
unsigned facesRow137[] = {-5, -7};
unsigned facesRow138[] = {0};
unsigned facesRow139[] = {0};
unsigned facesRow140[] = {0};
unsigned facesRow141[] = {0};
unsigned facesRow142[] = {0};
unsigned facesRow143[] = {0};
unsigned facesRow144[] = {0};
unsigned facesRow145[] = {-1, -7};
unsigned facesRow146[] = {0};
unsigned facesRow147[] = {-3, 7};
unsigned facesRow148[] = {5, -3, 7};
unsigned facesRow149[] = {-1, -3, 7};
unsigned facesRow150[] = {3, -7};
unsigned facesRow151[] = {0};
unsigned facesRow152[] = {0};
unsigned facesRow153[] = {-5, -1, -7};
unsigned facesRow154[] = {0};
unsigned facesRow155[] = {0};
unsigned facesRow156[] = {0};
unsigned facesRow157[] = {1, 7};
unsigned facesRow158[] = {0};
unsigned facesRow159[] = {-6};
unsigned facesRow160[] = {-6, 4, 1, 7};
unsigned facesRow161[] = {-6, -7};
unsigned facesRow162[] = {4, -6, -7};
unsigned facesRow163[] = {-3, -6, -2, 7};
unsigned facesRow164[] = {5, 1, -6, -3, -2, 4, 7};
unsigned facesRow165[] = {-6, -3, -7};
unsigned facesRow166[] = {6, 3, -4, -7};
unsigned facesRow167[] = {-6, -7};
unsigned facesRow168[] = {-6, 1, -7};
unsigned facesRow169[] = {-6, -5, -7};
unsigned facesRow170[] = {6, 7};
unsigned facesRow171[] = {-2, -6, -7};
unsigned facesRow172[] = {6, -1, 2, -7};
unsigned facesRow173[] = {6, 7};
unsigned facesRow174[] = {6};
unsigned facesRow175[] = {0};
unsigned facesRow176[] = {0};
unsigned facesRow177[] = {0};
unsigned facesRow178[] = {0};
unsigned facesRow179[] = {-2, -3, 7};
unsigned facesRow180[] = {-5, 3, 2, 7};
unsigned facesRow181[] = {3, 7};
unsigned facesRow182[] = {3};
unsigned facesRow183[] = {0};
unsigned facesRow184[] = {0};
unsigned facesRow185[] = {5, 7};
unsigned facesRow186[] = {0};
unsigned facesRow187[] = {2, 7};
unsigned facesRow188[] = {2};
unsigned facesRow189[] = {7};
unsigned facesRow190[] = {0};
unsigned facesRow191[] = {0};
unsigned facesRow192[] = {4, 7};
unsigned facesRow193[] = {2, -7};
unsigned facesRow194[] = {2, 4, 7};
unsigned facesRow195[] = {0};
unsigned facesRow196[] = {4, 5, 7};
unsigned facesRow197[] = {0};
unsigned facesRow198[] = {-4, -7};
unsigned facesRow199[] = {0};
unsigned facesRow200[] = {0};
unsigned facesRow201[] = {-5, 2, -7};
unsigned facesRow202[] = {-2, 7};
unsigned facesRow203[] = {0};
unsigned facesRow204[] = {0};
unsigned facesRow205[] = {0};
unsigned facesRow206[] = {0};
unsigned facesRow207[] = {0};
unsigned facesRow208[] = {0};
unsigned facesRow209[] = {2, -1, -7};
unsigned facesRow210[] = {-2, -7};
unsigned facesRow211[] = {0};
unsigned facesRow212[] = {-5, -7};
unsigned facesRow213[] = {1, -7};
unsigned facesRow214[] = {-7};
unsigned facesRow215[] = {0};
unsigned facesRow216[] = {0};
unsigned facesRow217[] = {-2, 1, 5, -7};
unsigned facesRow218[] = {-2};
unsigned facesRow219[] = {0};
unsigned facesRow220[] = {0};
unsigned facesRow221[] = {1};
unsigned facesRow222[] = {0};
unsigned facesRow223[] = {0};
unsigned facesRow224[] = {4, 1, 7};
unsigned facesRow225[] = {0};
unsigned facesRow226[] = {-4, 7};
unsigned facesRow227[] = {0};
unsigned facesRow228[] = {-5, -1, -4, 7};
unsigned facesRow229[] = {0};
unsigned facesRow230[] = {-4};
unsigned facesRow231[] = {0};
unsigned facesRow232[] = {-1, 7};
unsigned facesRow233[] = {5, 7};
unsigned facesRow234[] = {7};
unsigned facesRow235[] = {0};
unsigned facesRow236[] = {-1};
unsigned facesRow237[] = {0};
unsigned facesRow238[] = {0};
unsigned facesRow239[] = {0};
unsigned facesRow240[] = {0};
unsigned facesRow241[] = {0};
unsigned facesRow242[] = {0};
unsigned facesRow243[] = {0};
unsigned facesRow244[] = {-5};
unsigned facesRow245[] = {0};
unsigned facesRow246[] = {0};
unsigned facesRow247[] = {0};
unsigned facesRow248[] = {0};
unsigned facesRow249[] = {5};
unsigned facesRow250[] = {0};
unsigned facesRow251[] = {0};
unsigned facesRow252[] = {0};
unsigned facesRow253[] = {0};
unsigned (*Faces[])[] = {&facesRow0, &facesRow1, &facesRow2, &facesRow3, &facesRow4, &facesRow5, &facesRow6, &facesRow7, &facesRow8, &facesRow9, &facesRow10, &facesRow11, &facesRow12, &facesRow13, &facesRow14, &facesRow15, &facesRow16, &facesRow17, &facesRow18, &facesRow19, &facesRow20, &facesRow21, &facesRow22, &facesRow23, &facesRow24, &facesRow25, &facesRow26, &facesRow27, &facesRow28, &facesRow29, &facesRow30, &facesRow31, &facesRow32, &facesRow33, &facesRow34, &facesRow35, &facesRow36,
   &facesRow37, &facesRow38, &facesRow39, &facesRow40, &facesRow41, &facesRow42, &facesRow43, &facesRow44, &facesRow45, &facesRow46, &facesRow47, &facesRow48, &facesRow49, &facesRow50, &facesRow51, &facesRow52, &facesRow53, &facesRow54, &facesRow55, &facesRow56, &facesRow57, &facesRow58, &facesRow59, &facesRow60, &facesRow61, &facesRow62, &facesRow63, &facesRow64, &facesRow65, &facesRow66, &facesRow67, &facesRow68, &facesRow69, &facesRow70, &facesRow71, &facesRow72, &facesRow73, &facesRow74,
   &facesRow75, &facesRow76, &facesRow77, &facesRow78, &facesRow79, &facesRow80, &facesRow81, &facesRow82, &facesRow83, &facesRow84, &facesRow85, &facesRow86, &facesRow87, &facesRow88, &facesRow89, &facesRow90, &facesRow91, &facesRow92, &facesRow93, &facesRow94, &facesRow95, &facesRow96, &facesRow97, &facesRow98, &facesRow99, &facesRow100, &facesRow101, &facesRow102, &facesRow103, &facesRow104, &facesRow105, &facesRow106, &facesRow107, &facesRow108, &facesRow109, &facesRow110, &facesRow111,
   &facesRow112, &facesRow113, &facesRow114, &facesRow115, &facesRow116, &facesRow117, &facesRow118, &facesRow119, &facesRow120, &facesRow121, &facesRow122, &facesRow123, &facesRow124, &facesRow125, &facesRow126, &facesRow127, &facesRow128, &facesRow129, &facesRow130, &facesRow131, &facesRow132, &facesRow133, &facesRow134, &facesRow135, &facesRow136, &facesRow137, &facesRow138, &facesRow139, &facesRow140, &facesRow141, &facesRow142, &facesRow143, &facesRow144, &facesRow145, &facesRow146,
   &facesRow147, &facesRow148, &facesRow149, &facesRow150, &facesRow151, &facesRow152, &facesRow153, &facesRow154, &facesRow155, &facesRow156, &facesRow157, &facesRow158, &facesRow159, &facesRow160, &facesRow161, &facesRow162, &facesRow163, &facesRow164, &facesRow165, &facesRow166, &facesRow167, &facesRow168, &facesRow169, &facesRow170, &facesRow171, &facesRow172, &facesRow173, &facesRow174, &facesRow175, &facesRow176, &facesRow177, &facesRow178, &facesRow179, &facesRow180, &facesRow181,
   &facesRow182, &facesRow183, &facesRow184, &facesRow185, &facesRow186, &facesRow187, &facesRow188, &facesRow189, &facesRow190, &facesRow191, &facesRow192, &facesRow193, &facesRow194, &facesRow195, &facesRow196, &facesRow197, &facesRow198, &facesRow199, &facesRow200, &facesRow201, &facesRow202, &facesRow203, &facesRow204, &facesRow205, &facesRow206, &facesRow207, &facesRow208, &facesRow209, &facesRow210, &facesRow211, &facesRow212, &facesRow213, &facesRow214, &facesRow215, &facesRow216,
   &facesRow217, &facesRow218, &facesRow219, &facesRow220, &facesRow221, &facesRow222, &facesRow223, &facesRow224, &facesRow225, &facesRow226, &facesRow227, &facesRow228, &facesRow229, &facesRow230, &facesRow231, &facesRow232, &facesRow233, &facesRow234, &facesRow235, &facesRow236, &facesRow237, &facesRow238, &facesRow239, &facesRow240, &facesRow241, &facesRow242, &facesRow243, &facesRow244, &facesRow245, &facesRow246, &facesRow247, &facesRow248, &facesRow249, &facesRow250, &facesRow251,
   &facesRow252, &facesRow253};

unsigned FacesSizes[254] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            2, 2, 1, 1, 1, 4, 1, 2, 1, 3, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 2,
                            2, 1, 2, 3, 1, 1, 1, 1, 1, 1, 2, 3, 1, 1, 2, 1, 3, 1, 3, 2, 2,
                            1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 4, 3, 1, 1, 1, 1, 1, 2, 4, 3,
                            2, 3, 3, 2, 4, 3, 7, 4, 3, 2, 4, 1, 1, 2, 1, 1, 1, 3, 1, 1, 2,
                            3, 3, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 3, 2, 4, 1, 2, 1,
                            1, 1, 1, 1, 1, 2, 1, 4, 2, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2,
                            1, 2, 3, 3, 2, 1, 1, 3, 1, 1, 1, 2, 1, 1, 4, 2, 3, 4, 7, 3, 4,
                            2, 3, 3, 2, 3, 4, 2, 1, 1, 1, 1, 1, 3, 4, 2, 1, 1, 1, 2, 1, 2,
                            1, 1, 1, 1, 2, 2, 3, 1, 3, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 1, 1,
                            3, 2, 1, 2, 2, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 3, 1, 2, 1, 4, 1,
                            1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1};
