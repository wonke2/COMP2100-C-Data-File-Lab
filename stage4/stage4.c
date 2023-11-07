#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef int boolean32;
typedef short int boolean16;
typedef char boolean8;
#define false '0';
#define true !false;
// error at byte 21
//
typedef struct data {
	short int smoke;
	char eyes;
	boolean32 sponge;
	boolean32 exchange;
	boolean8 balance;
	boolean16 clam;
	unsigned long int summer;
	short int desk;
	unsigned int girls;
	boolean16 pancake;
	char bit[7];
	double stitch;
	int8_t peace;
	long int insect;
	double owner;
	float sleep;
	boolean8 thought;
} data;

typedef struct data data;

typedef struct in_data {
    int smoke;
    char eyes;
    boolean8 sponge;
    boolean8 exchange;
    boolean8 balance;
    boolean8 clam;
    unsigned short int summer;
    int8_t desk;
    unsigned short int girls;
    int8_t pancake;
    char bit[11];
    float stitch;
    float peace;
    unsigned short int insect;
    float owner;
    double sleep;
    boolean8 thought;
} in_data;

char* substring(char *destination, const char *source, int beg, int n){
    while (n > 0){
        *destination = *(source + beg);
 
        destination++;
        source++;
        n--;
    }
    *destination = '\0';
    return destination;
}

int main(int argc, char **argv) {
    int nAlloc = 100;
    char E1[22] = "ERROR 1: No file name.";
    struct data temp_out;
    struct in_data temp;
    char bufferchar;
    in_data **buffer = malloc(nAlloc * sizeof(in_data*));
    if (argc != 3){
    fprintf(stderr, "usage: %s <filename>\n", argv[0]);
    exit(1);
    }

    FILE * in_file;
    in_file = fopen(argv[1] , "r");

    if (in_file == 0){
        fprintf(stderr, "ERROR 2: File: %s does not exist\nEnter valid file name.\n", argv[1]);
        exit(1);
    }

	FILE * out_file = fopen(argv[2], "w");

    int i = 0;
    while (!feof(in_file)){
        if (i >= nAlloc){
            nAlloc = nAlloc + 100;
            buffer = realloc(buffer, nAlloc * sizeof(in_data*));
            if (!buffer){
                fprintf(stderr, "No memory");
            }
        }

        buffer[i] = malloc(sizeof(temp));
        fread(&buffer[i]->smoke, sizeof(temp.smoke), 1, in_file);
        fread(&buffer[i]->eyes, sizeof(temp.eyes), 1, in_file);
        fread(&bufferchar, 1, 1, in_file);

        buffer[i]->sponge = (bufferchar & 0x01) ? 1 : 0;
        buffer[i]->exchange = (bufferchar & 0x20) ? 1 : 0;
        buffer[i]->balance = (bufferchar & 0x08) ? 1 : 0;
        buffer[i]->clam = (bufferchar & 0x80) ? 1 : 0;
        
        fread(&buffer[i]->summer, sizeof(temp.summer), 1, in_file);
        fread(&buffer[i]->desk, sizeof(temp.desk), 1, in_file);
        fread(&buffer[i]->girls, sizeof(temp.girls), 1, in_file);
        fread(&buffer[i]->pancake, sizeof(temp.pancake), 1, in_file);
        fread(&buffer[i]->bit, sizeof(temp.bit), 1, in_file);
        fread(&buffer[i]->stitch, sizeof(temp.stitch), 1, in_file);
        fread(&buffer[i]->peace, sizeof(temp.peace), 1, in_file);
        fread(&buffer[i]->insect, sizeof(temp.insect), 1, in_file);
        fread(&buffer[i]->owner, sizeof(temp.owner), 1, in_file);
        fread(&buffer[i]->sleep, sizeof(temp.sleep), 1, in_file);
        fread(&buffer[i]->thought, sizeof(temp.thought), 1, in_file);
        if (feof(in_file)){
            fclose(in_file);
            break;
        }
        i++;
    }

    for (int k = 0; k < i; k++){
        temp = *buffer[k];
        temp_out.smoke = (unsigned short int)temp.smoke;
        temp_out.eyes = (char)temp.eyes;
        temp_out.sponge = (boolean32)temp.sponge;
        temp_out.exchange = (boolean32)temp.exchange;
        temp_out.balance = (boolean8)temp.balance;
        temp_out.clam = (boolean16)temp.clam;
        temp_out.summer = (unsigned long int)temp.summer;
        temp_out.desk = (short int)temp.desk;
        temp_out.girls = (unsigned int)temp.girls;
        temp_out.pancake = (boolean16)temp.pancake;
        substring(temp_out.bit, temp.bit, 0, 7);
        temp_out.stitch = (double)temp.stitch;
        temp_out.peace = (int8_t)temp.peace;
        temp_out.insect = (long int)temp.insect;
        temp_out.owner = (double)temp.owner;
        temp_out.sleep = (float)temp.sleep;
        temp_out.thought = (boolean8)temp.thought;

        // printf("%ld\n", sizeof(temp_out.smoke));
        fwrite(&temp_out.smoke, sizeof(temp_out.smoke), 1, out_file);
        fwrite(&temp_out.eyes, sizeof(temp_out.eyes), 1, out_file);
        fwrite(&temp_out.sponge, sizeof(temp_out.sponge), 1, out_file);
        fwrite(&temp_out.exchange, sizeof(temp_out.exchange), 1, out_file);
        fwrite(&temp_out.balance, sizeof(temp_out.balance), 1, out_file);
        fwrite(&temp_out.clam, sizeof(temp_out.clam), 1, out_file);
        fwrite(&temp_out.summer, sizeof(temp_out.summer), 1, out_file);
        fwrite(&temp_out.desk, sizeof(temp_out.desk), 1, out_file);
        fwrite(&temp_out.girls, sizeof(temp_out.girls), 1, out_file);
        fwrite(&temp_out.pancake, sizeof(temp_out.pancake), 1, out_file);
        fwrite(&temp_out.bit, sizeof(temp_out.bit), 1, out_file);
        fwrite(&temp_out.stitch, sizeof(temp_out.stitch), 1, out_file);
        fwrite(&temp_out.peace, sizeof(temp_out.peace), 1, out_file);
        fwrite(&temp_out.insect, sizeof(temp_out.insect), 1, out_file);
        fwrite(&temp_out.owner, sizeof(temp_out.owner), 1, out_file);
        fwrite(&temp_out.sleep, sizeof(temp_out.sleep), 1, out_file);
        fwrite(&temp_out.thought, sizeof(temp_out.thought), 1, out_file);
    }
    for (int l = 0; l < nAlloc; l++){
        free(buffer[l]);
    }
    free(buffer);
    fclose(out_file);
}