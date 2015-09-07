#include <stdio.h>
unsigned long long count = 0;

void print_cycle(unsigned int * this_current_path){



    count++;
}

void bp(int lmax){
    int a;
if (lmax > 3) {
    ;
}
    printf("%d\n", a);
}

int main(int argc, const char * argv[]) {
    const unsigned int vo0[3] = {1,2,3};
    const unsigned int vo1[3] = {0,2,4};
    const unsigned int vo2[4] = {0,1,3,4};
    const unsigned int vo3[4] = {0,2,5,6};
    const unsigned int vo4[4] = {1,2,5,7};
    const unsigned int vo5[4] = {3,4,6,7};
    const unsigned int vo6[4] = {3,5,8,9};
    const unsigned int vo7[4] = {4,5,8,10};
    const unsigned int vo8[4] = {6,7,9,10};
    const unsigned int vo9[4] = {6,8,11,12};
    const unsigned int vo10[4] = {7,8,11,13};
    const unsigned int vo11[4] = {9,10,12,13};
    const unsigned int vo12[4] = {9,11,14,15};
    const unsigned int vo13[4] = {10,11,14,16};
    const unsigned int * vos[14] = {vo0,vo1,vo2,vo3,vo4,vo5,vo6,vo7,vo8,vo9,vo10,vo11,vo12,vo13};
    const unsigned int vomax[14] = {2,2,3,3,3,3,3,3,3,3,3,3,3,3}; //{3,3,4,4,4,4,4,4,4,4,4,4,4,4};
    unsigned int current_path[14];
    unsigned int adjacency_path[14];
    register unsigned int path_position = 0;
    unsigned char fresh[14] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    unsigned char inplay[14] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    register unsigned int start = 0;
    register unsigned int fresh_found;
    register unsigned int fresh_found_adjacency;

    register unsigned int possible_fresh;
    register unsigned int possible_fresh_adjacency;
    register unsigned int local_max = 0;



    starter_loop:
    if (start != 2 ) {
        inplay[start] = 0;
    fresh[0] = inplay[0]; fresh[1] = inplay[1]; fresh[2] = inplay[2]; fresh[3] = inplay[3]; fresh[4] = inplay[4]; fresh[5] = inplay[5]; fresh[6] = inplay[6]; fresh[7] = inplay[7]; fresh[8] = inplay[8]; fresh[9] = inplay[9]; fresh[10] = inplay[10]; fresh[11] = inplay[11]; fresh[12] = inplay[12]; fresh[13] = inplay[13]; 
    current_path[0] = start; current_path[1] = 0; current_path[2] = 0; current_path[3] = 0; current_path[4] = 0; current_path[5] = 0; current_path[6] = 0; current_path[7] = 0; current_path[8] = 0; current_path[9] = 0; current_path[10] = 0; current_path[11] = 0; current_path[12] = 0; current_path[13] = 0; 
    adjacency_path[0] = 0; adjacency_path[1] = 0; adjacency_path[2] = 0; adjacency_path[3] = 0; adjacency_path[4] = 0; adjacency_path[5] = 0; adjacency_path[6] = 0; adjacency_path[7] = 0; adjacency_path[8] = 0; adjacency_path[9] = 0; adjacency_path[10] = 0; adjacency_path[11] = 0; adjacency_path[12] = 0; adjacency_path[13] = 0;
        
        if (local_max > 3) {
            ;
        }
        
        fresh_found = 0;
        fresh_found_adjacency = 0;
        path_position = 0;
        begin_stepper:{
            
                if (local_max > 3) {
                    ;
                }
            
                local_max = vomax[current_path[path_position]];
            
                if (local_max > 3) {
                    ;
                }
            
                possible_fresh_adjacency = adjacency_path[path_position];
                begin_find_fresh:{
                    
                    if (local_max > 3) {
                        ;
                    }
                    
                    possible_fresh = vos[current_path[path_position]][possible_fresh_adjacency];
                    if (possible_fresh_adjacency != local_max) { // made <
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
                if (possible_fresh_adjacency != local_max) { // made <
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

