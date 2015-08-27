#include <stdio.h>
unsigned long long count = 0;

void print_cycle(unsigned int * this_current_path){



    count++;
}

int main(int argc, const char * argv[]) {
    const unsigned int vo0[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    const unsigned int vo1[12] = {0,2,3,4,5,6,7,8,9,10,11,12};
    const unsigned int vo2[12] = {0,1,3,4,5,6,7,8,9,10,11,12};
    const unsigned int vo3[12] = {0,1,2,4,5,6,7,8,9,10,11,12};
    const unsigned int vo4[12] = {0,1,2,3,5,6,7,8,9,10,11,12};
    const unsigned int vo5[12] = {0,1,2,3,4,6,7,8,9,10,11,12};
    const unsigned int vo6[12] = {0,1,2,3,4,5,7,8,9,10,11,12};
    const unsigned int vo7[12] = {0,1,2,3,4,5,6,8,9,10,11,12};
    const unsigned int vo8[12] = {0,1,2,3,4,5,6,7,9,10,11,12};
    const unsigned int vo9[12] = {0,1,2,3,4,5,6,7,8,10,11,12};
    const unsigned int vo10[12] = {0,1,2,3,4,5,6,7,8,9,11,12};
    const unsigned int vo11[12] = {0,1,2,3,4,5,6,7,8,9,10,12};
    const unsigned int vo12[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
    const unsigned int vo13[0] = {};
    const unsigned int vo14[0] = {};
    const unsigned int vo15[0] = {};
    const unsigned int vo16[0] = {};
    const unsigned int vo17[0] = {};
    const unsigned int vo18[0] = {};
    const unsigned int vo19[0] = {};
    const unsigned int vo20[0] = {};
    const unsigned int vo21[0] = {};
    const unsigned int vo22[0] = {};
    const unsigned int vo23[0] = {};
    const unsigned int vo24[0] = {};
    const unsigned int vo25[0] = {};
    const unsigned int vo26[0] = {};
    const unsigned int vo27[0] = {};
    const unsigned int vo28[0] = {};
    const unsigned int vo29[0] = {};
    const unsigned int vo30[0] = {};
    const unsigned int vo31[0] = {};
    const unsigned int vo32[0] = {};
    const unsigned int vo33[0] = {};
    const unsigned int vo34[0] = {};
    const unsigned int vo35[0] = {};
    const unsigned int vo36[0] = {};
    const unsigned int vo37[0] = {};
    const unsigned int vo38[0] = {};
    const unsigned int vo39[0] = {};
    const unsigned int vo40[0] = {};
    const unsigned int vo41[0] = {};
    const unsigned int vo42[0] = {};
    const unsigned int vo43[0] = {};
    const unsigned int vo44[0] = {};
    const unsigned int vo45[0] = {};
    const unsigned int vo46[0] = {};
    const unsigned int vo47[0] = {};
    const unsigned int vo48[0] = {};
    const unsigned int vo49[0] = {};
    const unsigned int vo50[0] = {};
    const unsigned int vo51[0] = {};
    const unsigned int vo52[0] = {};
    const unsigned int vo53[0] = {};
    const unsigned int vo54[0] = {};
    const unsigned int vo55[0] = {};
    const unsigned int vo56[0] = {};
    const unsigned int vo57[0] = {};
    const unsigned int vo58[0] = {};
    const unsigned int vo59[0] = {};
    const unsigned int vo60[0] = {};
    const unsigned int vo61[0] = {};
    const unsigned int vo62[0] = {};
    const unsigned int vo63[0] = {};
    const unsigned int vo64[0] = {};
    const unsigned int vo65[0] = {};
    const unsigned int vo66[0] = {};
    const unsigned int vo67[0] = {};
    const unsigned int vo68[0] = {};
    const unsigned int vo69[0] = {};
    const unsigned int vo70[0] = {};
    const unsigned int vo71[0] = {};
    const unsigned int vo72[0] = {};
    const unsigned int vo73[0] = {};
    const unsigned int vo74[0] = {};
    const unsigned int vo75[0] = {};
    const unsigned int vo76[0] = {};
    const unsigned int vo77[0] = {};
    const unsigned int * vos[78] = {vo0,vo1,vo2,vo3,vo4,vo5,vo6,vo7,vo8,vo9,vo10,vo11,vo12,vo13,vo14,vo15,vo16,vo17,vo18,vo19,vo20,vo21,vo22,vo23,vo24,vo25,vo26,vo27,vo28,vo29,vo30,vo31,vo32,vo33,vo34,vo35,vo36,vo37,vo38,vo39,vo40,vo41,vo42,vo43,vo44,vo45,vo46,vo47,vo48,vo49,vo50,vo51,vo52,vo53,vo54,vo55,vo56,vo57,vo58,vo59,vo60,vo61,vo62,vo63,vo64,vo65,vo66,vo67,vo68,vo69,vo70,vo71,vo72,vo73,vo74,vo75,vo76,vo77};
    const unsigned int vomax[78] = {12,12,12,12,12,12,12,12,12,12,12,12,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    unsigned int current_path[78];
    unsigned int adjacency_path[78];
    register unsigned int path_position = 0;
    unsigned char fresh[78] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    unsigned char inplay[78] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    register unsigned int start = 0;
    register unsigned int fresh_found;
    register unsigned int fresh_found_adjacency;

    register unsigned int possible_fresh;
    register unsigned int possible_fresh_adjacency;
    register unsigned int local_max;



    starter_loop:
    if (start != 2 ) {
        inplay[start] = 0;
    fresh[0] = inplay[0]; fresh[1] = inplay[1]; fresh[2] = inplay[2]; fresh[3] = inplay[3]; fresh[4] = inplay[4]; fresh[5] = inplay[5]; fresh[6] = inplay[6]; fresh[7] = inplay[7]; fresh[8] = inplay[8]; fresh[9] = inplay[9]; fresh[10] = inplay[10]; fresh[11] = inplay[11]; fresh[12] = inplay[12]; fresh[13] = inplay[13]; fresh[14] = inplay[14]; fresh[15] = inplay[15]; fresh[16] = inplay[16]; fresh[17] = inplay[17]; fresh[18] = inplay[18]; fresh[19] = inplay[19]; fresh[20] = inplay[20]; fresh[21] = inplay[21]; fresh[22] = inplay[22]; fresh[23] = inplay[23]; fresh[24] = inplay[24]; fresh[25] = inplay[25]; fresh[26] = inplay[26]; fresh[27] = inplay[27]; fresh[28] = inplay[28]; fresh[29] = inplay[29]; fresh[30] = inplay[30]; fresh[31] = inplay[31]; fresh[32] = inplay[32]; fresh[33] = inplay[33]; fresh[34] = inplay[34]; fresh[35] = inplay[35]; fresh[36] = inplay[36]; fresh[37] = inplay[37]; fresh[38] = inplay[38]; fresh[39] = inplay[39]; fresh[40] = inplay[40]; fresh[41] = inplay[41]; fresh[42] = inplay[42]; fresh[43] = inplay[43]; fresh[44] = inplay[44]; fresh[45] = inplay[45]; fresh[46] = inplay[46]; fresh[47] = inplay[47]; fresh[48] = inplay[48]; fresh[49] = inplay[49]; fresh[50] = inplay[50]; fresh[51] = inplay[51]; fresh[52] = inplay[52]; fresh[53] = inplay[53]; fresh[54] = inplay[54]; fresh[55] = inplay[55]; fresh[56] = inplay[56]; fresh[57] = inplay[57]; fresh[58] = inplay[58]; fresh[59] = inplay[59]; fresh[60] = inplay[60]; fresh[61] = inplay[61]; fresh[62] = inplay[62]; fresh[63] = inplay[63]; fresh[64] = inplay[64]; fresh[65] = inplay[65]; fresh[66] = inplay[66]; fresh[67] = inplay[67]; fresh[68] = inplay[68]; fresh[69] = inplay[69]; fresh[70] = inplay[70]; fresh[71] = inplay[71]; fresh[72] = inplay[72]; fresh[73] = inplay[73]; fresh[74] = inplay[74]; fresh[75] = inplay[75]; fresh[76] = inplay[76]; fresh[77] = inplay[77]; 
    current_path[0] = start; current_path[1] = 0; current_path[2] = 0; current_path[3] = 0; current_path[4] = 0; current_path[5] = 0; current_path[6] = 0; current_path[7] = 0; current_path[8] = 0; current_path[9] = 0; current_path[10] = 0; current_path[11] = 0; current_path[12] = 0; current_path[13] = 0; current_path[14] = 0; current_path[15] = 0; current_path[16] = 0; current_path[17] = 0; current_path[18] = 0; current_path[19] = 0; current_path[20] = 0; current_path[21] = 0; current_path[22] = 0; current_path[23] = 0; current_path[24] = 0; current_path[25] = 0; current_path[26] = 0; current_path[27] = 0; current_path[28] = 0; current_path[29] = 0; current_path[30] = 0; current_path[31] = 0; current_path[32] = 0; current_path[33] = 0; current_path[34] = 0; current_path[35] = 0; current_path[36] = 0; current_path[37] = 0; current_path[38] = 0; current_path[39] = 0; current_path[40] = 0; current_path[41] = 0; current_path[42] = 0; current_path[43] = 0; current_path[44] = 0; current_path[45] = 0; current_path[46] = 0; current_path[47] = 0; current_path[48] = 0; current_path[49] = 0; current_path[50] = 0; current_path[51] = 0; current_path[52] = 0; current_path[53] = 0; current_path[54] = 0; current_path[55] = 0; current_path[56] = 0; current_path[57] = 0; current_path[58] = 0; current_path[59] = 0; current_path[60] = 0; current_path[61] = 0; current_path[62] = 0; current_path[63] = 0; current_path[64] = 0; current_path[65] = 0; current_path[66] = 0; current_path[67] = 0; current_path[68] = 0; current_path[69] = 0; current_path[70] = 0; current_path[71] = 0; current_path[72] = 0; current_path[73] = 0; current_path[74] = 0; current_path[75] = 0; current_path[76] = 0; current_path[77] = 0; 
    adjacency_path[0] = 0; adjacency_path[1] = 0; adjacency_path[2] = 0; adjacency_path[3] = 0; adjacency_path[4] = 0; adjacency_path[5] = 0; adjacency_path[6] = 0; adjacency_path[7] = 0; adjacency_path[8] = 0; adjacency_path[9] = 0; adjacency_path[10] = 0; adjacency_path[11] = 0; adjacency_path[12] = 0; adjacency_path[13] = 0; adjacency_path[14] = 0; adjacency_path[15] = 0; adjacency_path[16] = 0; adjacency_path[17] = 0; adjacency_path[18] = 0; adjacency_path[19] = 0; adjacency_path[20] = 0; adjacency_path[21] = 0; adjacency_path[22] = 0; adjacency_path[23] = 0; adjacency_path[24] = 0; adjacency_path[25] = 0; adjacency_path[26] = 0; adjacency_path[27] = 0; adjacency_path[28] = 0; adjacency_path[29] = 0; adjacency_path[30] = 0; adjacency_path[31] = 0; adjacency_path[32] = 0; adjacency_path[33] = 0; adjacency_path[34] = 0; adjacency_path[35] = 0; adjacency_path[36] = 0; adjacency_path[37] = 0; adjacency_path[38] = 0; adjacency_path[39] = 0; adjacency_path[40] = 0; adjacency_path[41] = 0; adjacency_path[42] = 0; adjacency_path[43] = 0; adjacency_path[44] = 0; adjacency_path[45] = 0; adjacency_path[46] = 0; adjacency_path[47] = 0; adjacency_path[48] = 0; adjacency_path[49] = 0; adjacency_path[50] = 0; adjacency_path[51] = 0; adjacency_path[52] = 0; adjacency_path[53] = 0; adjacency_path[54] = 0; adjacency_path[55] = 0; adjacency_path[56] = 0; adjacency_path[57] = 0; adjacency_path[58] = 0; adjacency_path[59] = 0; adjacency_path[60] = 0; adjacency_path[61] = 0; adjacency_path[62] = 0; adjacency_path[63] = 0; adjacency_path[64] = 0; adjacency_path[65] = 0; adjacency_path[66] = 0; adjacency_path[67] = 0; adjacency_path[68] = 0; adjacency_path[69] = 0; adjacency_path[70] = 0; adjacency_path[71] = 0; adjacency_path[72] = 0; adjacency_path[73] = 0; adjacency_path[74] = 0; adjacency_path[75] = 0; adjacency_path[76] = 0; adjacency_path[77] = 0; 

        fresh_found = 0;
        fresh_found_adjacency = 0;
        path_position = 0;
        begin_stepper:{
                local_max = vomax[current_path[path_position]];
                possible_fresh_adjacency = adjacency_path[path_position];
                begin_find_fresh:{
                    possible_fresh = vos[current_path[path_position]][possible_fresh_adjacency];
                    if (possible_fresh_adjacency != local_max) {
                        if (possible_fresh == start) {
                                if (path_position > 1) {
                                    print_cycle(current_path);
                                } else {
                                        ;
                                }
                                possible_fresh_adjacency++;
                                goto begin_find_fresh;
                        } else {
                            if (fresh[possible_fresh] && (possible_fresh_adjacency >= adjacency_path[path_position])) {
                                fresh_found = possible_fresh;
                                fresh_found_adjacency = possible_fresh_adjacency;
                                possible_fresh_adjacency++;
                                goto begin_check_for_cycle;
                            }
                        }
                        possible_fresh_adjacency++;
                        goto begin_find_fresh;
                    } else {
                        goto end_find_fresh;
                    }
                }end_find_fresh: goto step_back;
            begin_check_for_cycle:{
                if (possible_fresh_adjacency != local_max) {
                    possible_fresh = vos[current_path[path_position]][possible_fresh_adjacency];
                    if (possible_fresh == start) {
                            if (path_position > 1) {
                                    print_cycle(current_path);
                            } else {
                                    ;
                            }
                            goto end_check_for_cycle;
                    }
                    possible_fresh_adjacency++;
                    goto begin_check_for_cycle;
                } else {
                    goto end_check_for_cycle;
                }
            }end_check_for_cycle: goto step_forward;
            step_forward:
                adjacency_path[path_position] = fresh_found_adjacency;
                path_position++;
                current_path[path_position] = fresh_found;
                fresh[fresh_found] = 0;
                goto begin_stepper;
            step_back:
                if (path_position == 0) {
                    goto end_stepper;
                } else {
                    fresh[current_path[path_position]] = 1;
                    current_path[path_position] = 0;
                    adjacency_path[path_position] = 0;
                    path_position--;
                    adjacency_path[path_position]++;
                    goto begin_stepper;
                }
        }end_stepper:;
    
        start++;
        goto starter_loop;
    } else {

            printf("%llu\n", count);

            return 0;
    }
    return 0;
}

