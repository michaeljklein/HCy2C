//
//  main.c
//  testing_trimmer
//
//  Created by Michael Klein on 8/1/15.
//  Copyright (c) 2015 Michael Klein. All rights reserved.
//

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>



void executeFile(char *path){
    FILE *fp; /*filepointer*/
    size_t size; /*filesize*/
    unsigned char *buffer;
    
    fp = fopen(path,"rb"); /*open file*/
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);         /*calc the size needed*/
    fseek(fp, 0, SEEK_SET);
    buffer = (unsigned char *) malloc(size);
    
    if (fp == NULL){ /*ERROR detection if file == empty*/
        printf("Error: There was an Error reading the file %s \n", path);
        exit(1);
    }
    else if (fread(&buffer, sizeof(*buffer), size, fp) != size){ /* if count of read bytes != calculated size of .bin file -> ERROR*/
        printf("Error: There was an Error reading the file %s\n", path);
        exit(1);
    }else{
        dostuff;
    }
    fclose(fp);
    free(buffer);
}





//int main() {
//    char cwd[1024];
//    if (getcwd(cwd, sizeof(cwd)) != NULL)
//        fprintf(stdout, "Current working dir: %s\n", cwd);
//    else
//        perror("getcwd() error");
//    return 0;
//}


int find_after2brackets(char * array, size_t size){
    char currentc = array[1];
    char pastc = array[0];
    int i = 2;
    while ((i < size) && (currentc != 93) && (pastc != 93)) { //93 is ']'
        pastc = currentc;
        currentc = array[i];
        i++;
    }
    return i + 1;
}

const int powof10[5] = [10000,1000,100,10,1]

int find_next_best(char * array, size_t size, int startpos){
    int pos = startpos;
    char intbuffer[5];
    int bufpos = 0;
    // seek to comma
    while ((array[pos] != 44) && (pos != size)) {pos++}
    pos++; //go after comma
    // load into buffer until it hits ']'
    while ((array[pos] != 93) && (pos != size)) {
        intbuffer[bufpos++] = array[pos];
        pos++;
    }
    int thisbest = 0;
    for (bufpos = 0; bufpos != 5; bufpos++) {
        thisbest += powof10[bufpos]*intbuffer[bufpos];
    }
    
    if (pos != size) {
        return thisbest;
    } else {
        return 0;
    }
}

int find_all_best(char * array, size_t size, int startpos){
    
}

int main(int argc, const char * argv[]) {
//    FILE * infile  = fopen("test.txt","rb");
//    FILE * outfile = fopen("tout.txt","wb");

    // get first few lines
//    fread(buffer, bufsize, 1, infile);
    
    
    
    return 0;
}
