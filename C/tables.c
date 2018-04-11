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

unsigned indexArray[8][3] =
{{0, 0, 0},
 {1, 0, 0},
 {1, 1, 0},
 {0, 1, 0},
 {0, 0, 1},
 {1, 0, 1},
 {1, 1, 1},
 {0, 1, 1}};

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
unsigned* Edges[] = {edgesRow0, edgesRow1, edgesRow2, edgesRow3, edgesRow4, edgesRow5, edgesRow6, edgesRow7, edgesRow8, edgesRow9, edgesRow10, edgesRow11, edgesRow12, edgesRow13, edgesRow14, edgesRow15, edgesRow16, edgesRow17, edgesRow18, edgesRow19, edgesRow20, edgesRow21, edgesRow22, edgesRow23, edgesRow24, edgesRow25, edgesRow26, edgesRow27, edgesRow28, edgesRow29, edgesRow30, edgesRow31, edgesRow32, edgesRow33, edgesRow34, edgesRow35, edgesRow36, edgesRow37, edgesRow38, edgesRow39, edgesRow40, edgesRow41, edgesRow42, edgesRow43, edgesRow44, edgesRow45, edgesRow46, edgesRow47, edgesRow48, edgesRow49, edgesRow50, edgesRow51, edgesRow52, edgesRow53, edgesRow54, edgesRow55, edgesRow56, edgesRow57, edgesRow58, edgesRow59, edgesRow60, edgesRow61, edgesRow62, edgesRow63, edgesRow64, edgesRow65, edgesRow66, edgesRow67, edgesRow68, edgesRow69, edgesRow70, edgesRow71, edgesRow72, edgesRow73, edgesRow74, edgesRow75, edgesRow76, edgesRow77, edgesRow78, edgesRow79, edgesRow80, edgesRow81, edgesRow82, edgesRow83, edgesRow84, edgesRow85, edgesRow86, edgesRow87, edgesRow88, edgesRow89, edgesRow90, edgesRow91, edgesRow92, edgesRow93, edgesRow94, edgesRow95, edgesRow96, edgesRow97, edgesRow98, edgesRow99, edgesRow100, edgesRow101, edgesRow102, edgesRow103, edgesRow104, edgesRow105, edgesRow106, edgesRow107, edgesRow108, edgesRow109, edgesRow110, edgesRow111, edgesRow112, edgesRow113, edgesRow114, edgesRow115, edgesRow116, edgesRow117, edgesRow118, edgesRow119, edgesRow120, edgesRow121, edgesRow122, edgesRow123, edgesRow124, edgesRow125, edgesRow126, edgesRow127, edgesRow128, edgesRow129, edgesRow130, edgesRow131, edgesRow132, edgesRow133, edgesRow134, edgesRow135, edgesRow136, edgesRow137, edgesRow138, edgesRow139, edgesRow140, edgesRow141, edgesRow142, edgesRow143, edgesRow144, edgesRow145, edgesRow146, edgesRow147, edgesRow148, edgesRow149, edgesRow150, edgesRow151, edgesRow152, edgesRow153, edgesRow154, edgesRow155, edgesRow156, edgesRow157, edgesRow158, edgesRow159, edgesRow160, edgesRow161, edgesRow162, edgesRow163, edgesRow164, edgesRow165, edgesRow166, edgesRow167, edgesRow168, edgesRow169, edgesRow170, edgesRow171, edgesRow172, edgesRow173, edgesRow174, edgesRow175, edgesRow176, edgesRow177, edgesRow178, edgesRow179, edgesRow180, edgesRow181, edgesRow182, edgesRow183, edgesRow184, edgesRow185, edgesRow186, edgesRow187, edgesRow188, edgesRow189, edgesRow190, edgesRow191, edgesRow192, edgesRow193, edgesRow194, edgesRow195, edgesRow196, edgesRow197, edgesRow198, edgesRow199, edgesRow200, edgesRow201, edgesRow202, edgesRow203, edgesRow204, edgesRow205, edgesRow206, edgesRow207, edgesRow208, edgesRow209, edgesRow210, edgesRow211, edgesRow212, edgesRow213, edgesRow214, edgesRow215, edgesRow216, edgesRow217, edgesRow218, edgesRow219, edgesRow220, edgesRow221, edgesRow222, edgesRow223, edgesRow224, edgesRow225, edgesRow226, edgesRow227, edgesRow228, edgesRow229, edgesRow230, edgesRow231, edgesRow232, edgesRow233, edgesRow234, edgesRow235, edgesRow236, edgesRow237, edgesRow238, edgesRow239, edgesRow240, edgesRow241, edgesRow242, edgesRow243, edgesRow244, edgesRow245, edgesRow246, edgesRow247, edgesRow248, edgesRow249, edgesRow250, edgesRow251, edgesRow252, edgesRow253};
unsigned edgesLengths[254] =   {3, 3, 6, 3, 0, 6, 9, 3, 6, 0, 9, 6, 9, 9, 6, 3, 6, 0, 9, 0, 
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
