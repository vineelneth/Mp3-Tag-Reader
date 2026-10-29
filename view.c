#include<stdio.h>
#include<string.h>
#include "view.h"
void mp3_view(char* filename){
        if(isValidFileVersion(filename)==0)
        {
            printf("File version is not ID3\n");
        }
        else if(isValidFileVersion(filename)==1)
        {
            printf("File version: ID3\n");
            tag_reader(filename);
        }
        else
        {
            printf("File not found\n");
        }
}
int isValidFileVersion(char* filename)
{
            char buffer[3];
            FILE* fptr = fopen(filename,"rb");
            if(fptr!=NULL)
            {   
                fread(buffer, 3, 1,fptr);
                if(strcmp(buffer,"ID3")!=0)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
                fclose(fptr);
            }
            else
            {
                return -1;
            }
}
void tag_reader(char* filename)
{
    char buffer[5];
    FILE* fptr = fopen(filename, "rb");
    fseek(fptr, 10, SEEK_SET);
    fread(buffer, 4, 1, fptr);
    buffer[4] = '\0';
    fseek(fptr, 14, SEEK_SET);
    int size;
    fread(&size, sizeof(int), 1, fptr);
    bigtolittle((char*)&size);
    fseek(fptr, 21, SEEK_SET);
    char buffer2[size];
    fread(buffer2, size-1, 1, fptr);
    buffer2[size-1] = '\0';
    printf("%s -> %s\n", buffer, buffer2);
    fseek(fptr, 20+size, SEEK_SET);
    char buffer3[5];
    fread(buffer3, 4, 1, fptr);
    buffer3[4] = '\0';
    int size1;
    fread(&size1, 4, 1, fptr);
    bigtolittle((char*)&size1);
    char buffer1[size1];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer1, size1-1, 1, fptr);
    buffer1[size1-1] = '\0';
    printf("%s -> %d %s\n", buffer3, size1, buffer1);
    fseek(fptr, 30+size+size1, SEEK_SET);
    char buffer4[5];
    fread(buffer4, 4, 1, fptr);
    buffer4[4] = '\0';
    int size2;
    fread(&size2, 4, 1, fptr);
    bigtolittle((char*)&size2);
    char buffer5[size2];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer5, size2-1, 1, fptr);
    buffer5[size2-1] = '\0';
    printf("%s -> %d %s\n", buffer4, size2, buffer5);
    fseek(fptr, 40+size+size1+size2, SEEK_SET);
    char buffer6[5];
    fread(buffer6, 4, 1, fptr);
    buffer6[4] = '\0';
    int size3;
    fread(&size3, 4, 1, fptr);
    bigtolittle((char*)&size3);
    char buffer7[size3];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer7, size3-1, 1, fptr);
    buffer7[size3-1] = '\0';
    printf("%s -> %d %s\n", buffer6, size3, buffer7);
    fseek(fptr, 50+size+size1+size2+size3, SEEK_SET);
    char buffer8[5];
    fread(buffer8, 4, 1, fptr);
    buffer8[4] = '\0';
    int size4;
    fread(&size4, 4, 1, fptr);
    bigtolittle((char*)&size4);
    char buffer9[size4];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer9, size4-1, 1, fptr);
    buffer9[size4-1] = '\0';
    printf("%s -> %d %s\n", buffer8, size4, buffer9);
    fseek(fptr,60+size+size1+size2+size3+size4, SEEK_SET);
    char buffer10[5];
    fread(buffer10, 4, 1, fptr);
    buffer10[4] = '\0';
    int size5;
    fread(&size5, 4, 1, fptr);
    bigtolittle((char*)&size5);
    char buffer11[size5];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer11, size5-1, 1, fptr);
    fseek(fptr,70+size+size1+size2+size3+size4+size5, SEEK_SET);
    char buffer12[5];
    fread(buffer12, 4, 1, fptr);
    buffer12[4] = '\0';
    int size6;
    fread(&size6, 4, 1, fptr);
    bigtolittle((char*)&size6);
    char buffer13[size6];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer13, size6-1, 1, fptr);
    fseek(fptr,80+size+size1+size2+size3+size4+size5+size6, SEEK_SET);
    char buffer14[5];
    fread(buffer14, 4, 1, fptr);
    buffer14[4] = '\0';
    int size7;
    fread(&size7, 4, 1, fptr);
    bigtolittle((char*)&size7);
    char buffer15[size7];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer15, size7-1, 1, fptr);
    buffer15[size7-1]='\0';
    printf("%s -> %d %s\n", buffer14, size7, buffer15);
    fclose(fptr);
}
void bigtolittle(char* num)
{
    char* ptr1 = num;
    for(int i = 0; i < 2; i++)
    {
        char temp = *(ptr1+i);
        *(ptr1+i) = *(ptr1+3-i);
        *(ptr1+3-i) = temp;
    }
}