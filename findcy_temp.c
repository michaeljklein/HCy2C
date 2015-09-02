#include <stdio.h>
unsigned long long count = 0;

void print_cycle(FILE * outfile, unsigned int * this_current_path){
    char lookup[28][2] = {"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27"};
    char str[86] = "[__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__]\n";
    str[1] = lookup[this_current_path[0]][0];
    str[2] = lookup[this_current_path[0]][1];

    str[4] = lookup[this_current_path[1]][0];
    str[5] = lookup[this_current_path[1]][1];

    str[7] = lookup[this_current_path[2]][0];
    str[8] = lookup[this_current_path[2]][1];

    str[10] = lookup[this_current_path[3]][0];
    str[11] = lookup[this_current_path[3]][1];

    str[13] = lookup[this_current_path[4]][0];
    str[14] = lookup[this_current_path[4]][1];

    str[16] = lookup[this_current_path[5]][0];
    str[17] = lookup[this_current_path[5]][1];

    str[19] = lookup[this_current_path[6]][0];
    str[20] = lookup[this_current_path[6]][1];

    str[22] = lookup[this_current_path[7]][0];
    str[23] = lookup[this_current_path[7]][1];

    str[25] = lookup[this_current_path[8]][0];
    str[26] = lookup[this_current_path[8]][1];

    str[28] = lookup[this_current_path[9]][0];
    str[29] = lookup[this_current_path[9]][1];

    str[31] = lookup[this_current_path[10]][0];
    str[32] = lookup[this_current_path[10]][1];

    str[34] = lookup[this_current_path[11]][0];
    str[35] = lookup[this_current_path[11]][1];

    str[37] = lookup[this_current_path[12]][0];
    str[38] = lookup[this_current_path[12]][1];

    str[40] = lookup[this_current_path[13]][0];
    str[41] = lookup[this_current_path[13]][1];

    str[43] = lookup[this_current_path[14]][0];
    str[44] = lookup[this_current_path[14]][1];

    str[46] = lookup[this_current_path[15]][0];
    str[47] = lookup[this_current_path[15]][1];

    str[49] = lookup[this_current_path[16]][0];
    str[50] = lookup[this_current_path[16]][1];

    str[52] = lookup[this_current_path[17]][0];
    str[53] = lookup[this_current_path[17]][1];

    str[55] = lookup[this_current_path[18]][0];
    str[56] = lookup[this_current_path[18]][1];

    str[58] = lookup[this_current_path[19]][0];
    str[59] = lookup[this_current_path[19]][1];

    str[61] = lookup[this_current_path[20]][0];
    str[62] = lookup[this_current_path[20]][1];

    str[64] = lookup[this_current_path[21]][0];
    str[65] = lookup[this_current_path[21]][1];

    str[67] = lookup[this_current_path[22]][0];
    str[68] = lookup[this_current_path[22]][1];

    str[70] = lookup[this_current_path[23]][0];
    str[71] = lookup[this_current_path[23]][1];

    str[73] = lookup[this_current_path[24]][0];
    str[74] = lookup[this_current_path[24]][1];

    str[76] = lookup[this_current_path[25]][0];
    str[77] = lookup[this_current_path[25]][1];

    str[79] = lookup[this_current_path[26]][0];
    str[80] = lookup[this_current_path[26]][1];

    str[82] = lookup[this_current_path[27]][0];
    str[83] = lookup[this_current_path[27]][1];


    fwrite(str, 1, 86, outfile);
}

int main(int argc, const char * argv[]) {
    const unsigned int vo0[7] = {1,2,3,4,5,6,7};
    const unsigned int vo1[7] = {0,2,3,4,5,6,7};
    const unsigned int vo2[7] = {0,1,3,4,5,6,7};
    const unsigned int vo3[7] = {0,1,2,4,5,6,7};
    const unsigned int vo4[7] = {0,1,2,3,5,6,7};
    const unsigned int vo5[7] = {0,1,2,3,4,6,7};
    const unsigned int vo6[7] = {0,1,2,3,4,5,7};
    const unsigned int vo7[7] = {0,1,2,3,4,5,6};
    const unsigned int vo8[0] = {};
    const unsigned int vo9[0] = {};
    const unsigned int vo10[0] = {};
    const unsigned int vo11[0] = {};
    const unsigned int vo12[0] = {};
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
    const unsigned int * vos[28] = {vo0,vo1,vo2,vo3,vo4,vo5,vo6,vo7,vo8,vo9,vo10,vo11,vo12,vo13,vo14,vo15,vo16,vo17,vo18,vo19,vo20,vo21,vo22,vo23,vo24,vo25,vo26,vo27};
    const unsigned int vomax[28] = {7,7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    unsigned int current_path[28];
    unsigned int adjacency_path[28];
    register unsigned int path_position = 0;
    unsigned char fresh[28] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    unsigned char inplay[28] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    register unsigned int start = 0;
    register unsigned int fresh_found;
    register unsigned int fresh_found_adjacency;

    register unsigned int possible_fresh;
    register unsigned int possible_fresh_adjacency;
    register unsigned int local_max;
    FILE * outfile = fopen("findcy_temp.txt", "w");
    fwrite("[[0,1],[0,2],[0,3],[0,4],[0,5],[0,6],[0,7],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7],[2,3],[2,4],[2,5],[2,6],[2,7],[3,4],[3,5],[3,6],[3,7],[4,5],[4,6],[4,7],[5,6],[5,7],[6,7]]\n", 1,170,outfile);

    starter_loop:
    if (start != 2 ) {
        inplay[start] = 0;
    fresh[0] = inplay[0]; fresh[1] = inplay[1]; fresh[2] = inplay[2]; fresh[3] = inplay[3]; fresh[4] = inplay[4]; fresh[5] = inplay[5]; fresh[6] = inplay[6]; fresh[7] = inplay[7]; fresh[8] = inplay[8]; fresh[9] = inplay[9]; fresh[10] = inplay[10]; fresh[11] = inplay[11]; fresh[12] = inplay[12]; fresh[13] = inplay[13]; fresh[14] = inplay[14]; fresh[15] = inplay[15]; fresh[16] = inplay[16]; fresh[17] = inplay[17]; fresh[18] = inplay[18]; fresh[19] = inplay[19]; fresh[20] = inplay[20]; fresh[21] = inplay[21]; fresh[22] = inplay[22]; fresh[23] = inplay[23]; fresh[24] = inplay[24]; fresh[25] = inplay[25]; fresh[26] = inplay[26]; fresh[27] = inplay[27]; 
    current_path[0] = start; current_path[1] = 0; current_path[2] = 0; current_path[3] = 0; current_path[4] = 0; current_path[5] = 0; current_path[6] = 0; current_path[7] = 0; current_path[8] = 0; current_path[9] = 0; current_path[10] = 0; current_path[11] = 0; current_path[12] = 0; current_path[13] = 0; current_path[14] = 0; current_path[15] = 0; current_path[16] = 0; current_path[17] = 0; current_path[18] = 0; current_path[19] = 0; current_path[20] = 0; current_path[21] = 0; current_path[22] = 0; current_path[23] = 0; current_path[24] = 0; current_path[25] = 0; current_path[26] = 0; current_path[27] = 0; 
    adjacency_path[0] = 0; adjacency_path[1] = 0; adjacency_path[2] = 0; adjacency_path[3] = 0; adjacency_path[4] = 0; adjacency_path[5] = 0; adjacency_path[6] = 0; adjacency_path[7] = 0; adjacency_path[8] = 0; adjacency_path[9] = 0; adjacency_path[10] = 0; adjacency_path[11] = 0; adjacency_path[12] = 0; adjacency_path[13] = 0; adjacency_path[14] = 0; adjacency_path[15] = 0; adjacency_path[16] = 0; adjacency_path[17] = 0; adjacency_path[18] = 0; adjacency_path[19] = 0; adjacency_path[20] = 0; adjacency_path[21] = 0; adjacency_path[22] = 0; adjacency_path[23] = 0; adjacency_path[24] = 0; adjacency_path[25] = 0; adjacency_path[26] = 0; adjacency_path[27] = 0; 

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
                                    print_cycle(outfile, current_path);
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
                                    print_cycle(outfile, current_path);
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

            fwrite("DONE.", 1, 5, outfile);
            fclose(outfile);
            return 0;
    }
    return 0;
}

