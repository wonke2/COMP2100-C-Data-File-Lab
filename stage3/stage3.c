#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef int boolean32;
typedef short int boolean16;
typedef char boolean8;
#define false '0';
#define true !false;

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


int cmpdata(const void *pp1, const void *pp2){
    data *p1 = *(data **)pp1;
    data *p2 = *(data **)pp2;

    if (p1->smoke - p2->smoke != 0)
        return (p1->smoke - p2->smoke);
    
    if (strcmp(p1->bit, p2->bit) != 0)
        return strcmp(p1->bit, p2->bit);
    
    if (p1->summer > p2->summer )
        return -1;
    
    if (p1->summer < p2->summer)
        return 1;
    
    if (p1->owner > p2->owner)
        return 1;
    
    if (p1->owner < p2->owner)
        return -1;
    
    int v1 = (p1->balance == 0) ? 0 : 1;
    int v2 = (p2->balance == 0) ? 0 : 1;
    if (v1 - v2 != 0)
        return (v1 - v2);
    
    if (p1->pancake - p2->pancake != 0)
        return (p1->pancake - p2->pancake);
    
    if (p1->eyes - p2->eyes != 0)
        return p1->eyes - p2->eyes;
    
    if (p1->peace - p2->peace != 0)
        return p1->peace - p2->peace;
    
    if (p1->exchange - p2->exchange != 0)
        return (p1->exchange - p2->exchange);
    
    if (p1->insect > p2->insect != 0)
        return -1;
    
    if (p1->insect < p2->insect != 0)
        return 1;
    
    if (p1->desk - p2->desk != 0)
        return (p1->desk - p2->desk);
    
    if (p1->sleep > p2->sleep != 0)
        return 1;
    
    if (p1->sleep < p2->sleep != 0)
        return -1;
    
    if (p1->thought -  p2->thought != 0)
        return (p2->thought - p1->thought);
    
    if (p1->sponge - p2->sponge != 0)
        return (p1->sponge - p2->sponge);
    
    if (p1->clam - p2->clam != 0)
        return (p2->clam - p1->clam);
    
    if (p1->stitch > p2->stitch)
        return -1;
    
    if (p1->stitch < p2->stitch)
        return 1;
    
    if (p1->girls > p2->girls)
        return 1;
    
    if (p1->girls < p2->girls)
        return -1;
    
}

int main(int argc, char **argv) {
    int nAlloc = 100;
    char E1[22] = "ERROR 1: No file name.";
    struct data temp;
    data **buffer = malloc(nAlloc * sizeof(data*));

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
            buffer = realloc(buffer, nAlloc * sizeof(data*));
            if (!buffer){
                fprintf(stderr, "No memory");
            }
        }

        buffer[i] = malloc(sizeof(temp));
        fread(&buffer[i]->smoke, sizeof(temp.smoke), 1, in_file);
        fread(&buffer[i]->eyes, sizeof(temp.eyes), 1, in_file);
        fread(&buffer[i]->sponge, sizeof(temp.sponge), 1, in_file);
        fread(&buffer[i]->exchange, sizeof(temp.exchange), 1, in_file);
        fread(&buffer[i]->balance, sizeof(temp.balance), 1, in_file);
        fread(&buffer[i]->clam, sizeof(temp.clam), 1, in_file);
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

    qsort(buffer, i, sizeof(data*), cmpdata);

    for (int k = 0; k < i; k++){
        temp = *buffer[k];
        fwrite(&temp.smoke, sizeof(temp.smoke), 1, out_file);
        fwrite(&temp.eyes, sizeof(temp.eyes), 1, out_file);
        fwrite(&temp.sponge, sizeof(temp.sponge), 1, out_file);
        fwrite(&temp.exchange, sizeof(temp.exchange), 1, out_file);
        fwrite(&temp.balance, sizeof(temp.balance), 1, out_file);
        fwrite(&temp.clam, sizeof(temp.clam), 1, out_file);
        fwrite(&temp.summer, sizeof(temp.summer), 1, out_file);
        fwrite(&temp.desk, sizeof(temp.desk), 1, out_file);
        fwrite(&temp.girls, sizeof(temp.girls), 1, out_file);
        fwrite(&temp.pancake, sizeof(temp.pancake), 1, out_file);
        fwrite(&temp.bit, sizeof(temp.bit), 1, out_file);
        fwrite(&temp.stitch, sizeof(temp.stitch), 1, out_file);
        fwrite(&temp.peace, sizeof(temp.peace), 1, out_file);
        fwrite(&temp.insect, sizeof(temp.insect), 1, out_file);
        fwrite(&temp.owner, sizeof(temp.owner), 1, out_file);
        fwrite(&temp.sleep, sizeof(temp.sleep), 1, out_file);
        fwrite(&temp.thought, sizeof(temp.thought), 1, out_file);
    }
    for (int l = 0; l < nAlloc; l++){
        free(buffer[l]);
    }
    free(buffer);
    fclose(out_file);
}