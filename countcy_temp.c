#include <stdio.h>
unsigned long long count = 0;

void print_cycle(unsigned int * this_current_path){



    count++;
}

int main(int argc, const char * argv[]) {
    const unsigned int vo0[2] = {1,3};
    const unsigned int vo1[2] = {0,2};
    const unsigned int vo2[2] = {1,3};
    const unsigned int vo3[2] = {0,2};
    const unsigned int * vos[4] = {vo0,vo1,vo2,vo3};
    const unsigned int vomax[4] = {2,2,2,2};
    unsigned int current_path[4];
    unsigned int adjacency_path[4];
    register unsigned int path_position = 0;
    unsigned char fresh[4] = {1,1,1,1};
    unsigned char inplay[4] = {1,1,1,1};
    register unsigned int start = 0;
    register unsigned int fresh_found;
    register unsigned int fresh_found_adjacency;

    register unsigned int possible_fresh;
    register unsigned int possible_fresh_adjacency;
    register unsigned int local_max;



    starter_loop:
    if (start != 2 ) {
        inplay[start] = 0;
    fresh[0] = inplay[0]; fresh[1] = inplay[1]; fresh[2] = inplay[2]; fresh[3] = inplay[3]; 
    current_path[0] = start; current_path[1] = 0; current_path[2] = 0; current_path[3] = 0; 
    adjacency_path[0] = 0; adjacency_path[1] = 0; adjacency_path[2] = 0; adjacency_path[3] = 0; 

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

