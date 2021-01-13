//
// Created by li on 2020/12/11.
//

#include "assistant/inquire.h"

string eegNameList[64] = {"FP1", "AF7", "AF3", "F1", "F3", "F5", "F7", "FT7",     // A1 - A8
                          "FC5", "FC3", "FC1", "C1", "C3", "C5", "T7", "TP7",     // A9 - A16
                          "CP5", "CP3", "CP1", "P1", "P3", "P5", "P7", "P9",      // A17 - A24
                          "PO7", "PO3", "O1",  "lz", "Oz", "POz","Pz", "CPz",     // A25 - A32

                          "FPz", "FP2", "AF8", "AF4", "AFz", "Fz", "F2", "F4",    // B1 - B8
                          "F6",  "F8",  "FT8", "FC6", "FC4", "FC2","FCz","Cz",    // B9 - B16
                          "C2",  "C4",  "C6",  "T8",  "TP8", "CP6","CP4","CP2",   // B17 - B24
                          "P2",  "P4",  "P6",  "P8",  "P10", "PO8","PO4","O2"     // B25 - B32
};

int eegLocationXList[64] = {674, 595, 686, 704, 647, 590, 534, 494,
                            558, 627, 693, 696, 619, 549, 480, 493,
                            560, 626, 694, 707, 647, 590, 533, 491,
                            596, 685, 673, 760, 761, 759, 759, 759,
                            757, 846, 925, 833, 758, 760, 815, 873,
                            932, 986, 1026, 960, 893, 824, 759, 759,
                            830, 899, 970, 1040, 1027, 962, 893, 826,
                            816, 873, 931, 988, 1027, 925, 835, 846};

int eegLocationYList[64] = {302, 340, 352, 424, 420, 413, 400, 480,
                            487, 492, 494, 566, 567, 566, 566, 651,
                            645, 640, 637, 708, 712, 718, 730, 706,
                            791, 777, 831, 899, 845, 778, 707, 636,
                            287, 300, 340, 355, 357, 426, 425, 420,
                            414, 403, 481, 486, 492, 496, 496, 568,
                            566, 566, 567, 568, 652, 645, 640, 636,
                            709, 711, 717, 731, 709, 792, 777, 832};

msgNameLocation getFindResult(string name)
{
    msgNameLocation msg;
    string index = name.substr(1, name.length());
    int findIndex = stoi(index);
    if(name[0] == 'A')
    {
        //findIndex = name.mid(1, -1).toInt() - 1;
        msg.eegName = eegNameList[findIndex-1];
        msg.eegLocationX = eegLocationXList[findIndex-1];
        msg.eegLocationY = eegLocationYList[findIndex-1];
    }
    else
    {
        //findIndex = name.mid(1, -1).toInt() + 31;
        findIndex = findIndex + 32;
        msg.eegName = eegNameList[findIndex-1];
        msg.eegLocationX = eegLocationXList[findIndex-1];
        msg.eegLocationY = eegLocationYList[findIndex-1];
    }

    return msg;
}
