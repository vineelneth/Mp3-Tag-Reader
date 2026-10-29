#include<stdio.h>
#include<string.h>
#include "edit.h"
int size;
int size1;
int size2;
int size3;
int size4;
int size5;
int size6;
int size7;
void mp3_edit(char* tagName,char* newText,char* filename){
        if(isValidFileVersionEdit(filename)==0)
        {
            printf("File version is not ID3\n");
        }
        else if(isValidFileVersionEdit(filename)==1)
        {
            printf("File version: ID3\n");
            tag_reader_edit(filename);
            func(tagName,newText,filename);
        }
        else
        {
            printf("File not found\n");
        }
}
int isValidFileVersionEdit(char* filename)
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
void func(char* tagName,char* newText, char* filename)
{
    FILE* fptr = fopen(filename,"rb");
    FILE* dfptr = fopen("edited_f.mp3","wb");  
    char buf[10];
    fread(buf, 10, 1,fptr);
    fwrite(buf, 10, 1, dfptr);
    int newText_len = strlen(newText);
    if(strcmp(tagName,"TIT2")==0)
    {
        char buf1[5];
        fread(buf1, 4, 1,fptr);
        buf1[4]='\0';
        fwrite(buf1, 4, 1, dfptr);
        int newText_len = strlen(newText);
        int backup_size;
        fread(&backup_size,sizeof(int),1,fptr);
        bigtolittleedit((char*)&backup_size);
        char buf2[newText_len];
        littletobig((char*)&newText_len);
        fwrite(&newText_len,sizeof(int),1,dfptr);
        char flag[2];
        fread(flag, 2, 1, fptr);
        fwrite(flag, 2, 1, dfptr);
        char null[1];
        fread(null, 1, 1, fptr);
        fwrite(null, 1, 1, dfptr);
        bigtolittleedit((char*)&newText_len);
        fwrite(newText,newText_len,1,dfptr);
        fseek(fptr,backup_size-1,SEEK_CUR);
        char ch;
        while(fread(&ch,1,1,fptr)==1)
        {
            fwrite(&ch,1,1,dfptr);
        }
    }
        else if(strcmp(tagName,"TPE1")==0)
        {
            char buf3[5];
            fread(buf3, 4, 1, fptr);
            buf3[4] = '\0';
            fwrite(buf3, 4, 1, dfptr);
            char buf4[10 + size];
            fread(buf4, 10 + size, 1, fptr);
            fwrite(buf4, 10 + size, 1, dfptr);
            int backup_size1;
            fread(&backup_size1, sizeof(int), 1, fptr);
            bigtolittleedit((char*)&backup_size1);
            newText_len = strlen(newText) + 1;
            littletobig((char*)&newText_len);
            fwrite(&newText_len, sizeof(int), 1, dfptr);
            bigtolittleedit((char*)&newText_len);
            char flag1[2];
            fread(flag1, 2, 1, fptr);
            fwrite(flag1, 2, 1, dfptr);
            char null1[1];
            fread(null1, 1, 1, fptr);
            fwrite(null1, 1, 1, dfptr);
            fwrite(newText, newText_len - 1, 1, dfptr);
            fseek(fptr, backup_size1 - 1, SEEK_CUR);
            char ch;
            while(fread(&ch, 1, 1, fptr) == 1)
            {
                fwrite(&ch, 1, 1, dfptr);
            }
        }
        else if(strcmp(tagName,"TALB")==0)
        {
            char buf5[5];
            fread(buf5, 4, 1, fptr);
            buf5[4] = '\0';
            fwrite(buf5, 4, 1, dfptr);
            char buf6[20 + size + size1];
            fread(buf6, 20 + size+ size1, 1, fptr);
            fwrite(buf6, 20 + size + size1, 1, dfptr);
            int backup_size2;
            fread(&backup_size2, sizeof(int), 1, fptr);
            bigtolittleedit((char*)&backup_size2);
            newText_len = strlen(newText) + 1;
            littletobig((char*)&newText_len);
            fwrite(&newText_len, sizeof(int), 1, dfptr);
            bigtolittleedit((char*)&newText_len);
            char flag2[2];
            fread(flag2, 2, 1, fptr);
            fwrite(flag2, 2, 1, dfptr);
            char null2[1];
            fread(null2, 1, 1, fptr);
            fwrite(null2, 1, 1, dfptr);
            fwrite(newText, newText_len - 1, 1, dfptr);
            fseek(fptr, backup_size2 - 1, SEEK_CUR);
            char ch;
            while(fread(&ch, 1, 1, fptr) == 1)
            {
                fwrite(&ch, 1, 1, dfptr);
            }
        }
        else if(strcmp(tagName,"TYER")==0)
        {
            char buf7[5];
            fread(buf7, 4, 1, fptr);
            buf7[4] = '\0';
            fwrite(buf7, 4, 1, dfptr);
            char buf8[30 + size + size1 +size2];
            fread(buf8, 30 + size + size1 +size2, 1, fptr);
            fwrite(buf8, 30 + size + size1 +size2, 1, dfptr);
            int backup_size3;
            fread(&backup_size3, sizeof(int), 1, fptr);
            bigtolittleedit((char*)&backup_size3);
            newText_len = strlen(newText) + 1;
            littletobig((char*)&newText_len);
            fwrite(&newText_len, sizeof(int), 1, dfptr);
            bigtolittleedit((char*)&newText_len);
            char flag3[2];
            fread(flag3, 2, 1, fptr);
            fwrite(flag3, 2, 1, dfptr);
            char null3[1];
            fread(null3, 1, 1, fptr);
            fwrite(null3, 1, 1, dfptr);
            fwrite(newText, newText_len - 1, 1, dfptr);
            fseek(fptr, backup_size3 - 1, SEEK_CUR);
            char ch;
            while(fread(&ch, 1, 1, fptr) == 1)
            {
                fwrite(&ch, 1, 1, dfptr);
            }
        }
        else if(strcmp(tagName,"TCON")==0)
        {
            char buf9[5];
            fread(buf9, 4, 1, fptr);
            buf9[4] = '\0';
            fwrite(buf9, 4, 1, dfptr);
            char buf10[40 + size + size1 +size2 + size3];
            fread(buf10, 40 + size + size1 +size2 + size3, 1, fptr);
            fwrite(buf10, 40 + size + size1 +size2+size3, 1, dfptr);
            int backup_size4;
            fread(&backup_size4, sizeof(int), 1, fptr);
            bigtolittleedit((char*)&backup_size4);
            newText_len = strlen(newText) + 1;
            littletobig((char*)&newText_len);
            fwrite(&newText_len, sizeof(int), 1, dfptr);
            bigtolittleedit((char*)&newText_len);
            char flag4[2];
            fread(flag4, 2, 1, fptr);
            fwrite(flag4, 2, 1, dfptr);
            char null4[1];
            fread(null4, 1, 1, fptr);
            fwrite(null4, 1, 1, dfptr);
            fwrite(newText, newText_len - 1, 1, dfptr);
            fseek(fptr, backup_size4 - 1, SEEK_CUR);
            char ch;
            while(fread(&ch, 1, 1, fptr) == 1)
            {
                fwrite(&ch, 1, 1, dfptr);
            }
        }
        else if(strcmp(tagName,"TCOM")==0)
        {
            char buf12[70+size+size1+size2+size3+size4+size5+size6];
            fread(buf12, 70+size+size1+size2+size3+size4+size5+size6, 1, fptr);
            fwrite(buf12, 70+size+size1+size2+size3+size4+size5+size6, 1, dfptr);
            char buf11[5];
            fread(buf11, 4, 1, fptr);
            buf11[4] = '\0';
            fwrite(buf11, 4, 1, dfptr);
            int backup_size5;
            fread(&backup_size5, sizeof(int), 1, fptr);
            bigtolittleedit((char*)&backup_size5);
            newText_len = strlen(newText) + 1;
            littletobig((char*)&newText_len);
            fwrite(&newText_len, sizeof(int), 1, dfptr);
            bigtolittleedit((char*)&newText_len);
            char flag5[2];
            fread(flag5, 2, 1, fptr);
            fwrite(flag5, 2, 1, dfptr);
            char null5[1];
            fread(null5, 1, 1, fptr);
            fwrite(null5, 1, 1, dfptr);
            fwrite(newText, newText_len - 1, 1, dfptr);
            fseek(fptr, backup_size5 - 1, SEEK_CUR);
            char ch;
            while(fread(&ch, 1, 1, fptr) == 1)
            {
                fwrite(&ch, 1, 1, dfptr);
            }
        }
    fclose(fptr);
    fclose(dfptr);
}
void tag_reader_edit(char* filename)
{
    char buffer[5];
    FILE* fptr = fopen(filename, "rb");
    fseek(fptr, 10, SEEK_SET);
    fread(buffer, 4, 1, fptr);
    buffer[4] = '\0';
    fseek(fptr, 14, SEEK_SET);
    fread(&size, sizeof(int), 1, fptr);
    bigtolittleedit((char*)&size);
    fseek(fptr, 21, SEEK_SET);
    char buffer2[size];
    fread(buffer2, size-1, 1, fptr);
    buffer2[size-1] = '\0';
    fseek(fptr, 20+size, SEEK_SET);
    char buffer3[5];
    fread(buffer3, 4, 1, fptr);
    buffer3[4] = '\0';
    fread(&size1, 4, 1, fptr);
    bigtolittleedit((char*)&size1);
    char buffer1[size1];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer1, size1-1, 1, fptr);
    buffer1[size1-1] = '\0';
    fseek(fptr, 30+size+size1, SEEK_SET);
    char buffer4[5];
    fread(buffer4, 4, 1, fptr);
    buffer4[4] = '\0';
    fread(&size2, 4, 1, fptr);
    bigtolittleedit((char*)&size2);
    char buffer5[size2];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer5, size2-1, 1, fptr);
    buffer5[size2-1] = '\0';
    fseek(fptr, 40+size+size1+size2, SEEK_SET);
    char buffer6[5];
    fread(buffer6, 4, 1, fptr);
    buffer6[4] = '\0';
    fread(&size3, 4, 1, fptr);
    bigtolittleedit((char*)&size3);
    char buffer7[size3];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer7, size3-1, 1, fptr);
    buffer7[size3-1] = '\0';
    fseek(fptr, 50+size+size1+size2+size3, SEEK_SET);
    char buffer8[5];
    fread(buffer8, 4, 1, fptr);
    buffer8[4] = '\0';
    fread(&size4, 4, 1, fptr);
    bigtolittleedit((char*)&size4);
    char buffer9[size4];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer9, size4-1, 1, fptr);
    buffer9[size4-1] = '\0';
    fseek(fptr,60+size+size1+size2+size3+size4, SEEK_SET);
    char buffer10[5];
    fread(buffer10, 4, 1, fptr);
    buffer10[4] = '\0';
    fread(&size5, 4, 1, fptr);
    bigtolittleedit((char*)&size5);
    char buffer11[size5];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer11, size5-1, 1, fptr);
    fseek(fptr,70+size+size1+size2+size3+size4+size5, SEEK_SET);
    char buffer12[5];
    fread(buffer12, 4, 1, fptr);
    buffer12[4] = '\0';
    fread(&size6, 4, 1, fptr);
    bigtolittleedit((char*)&size6);
    char buffer13[size6];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer13, size6-1, 1, fptr);
    fseek(fptr,80+size+size1+size2+size3+size4+size5+size6, SEEK_SET);
    char buffer14[5];
    fread(buffer14, 4, 1, fptr);
    buffer14[4] = '\0';
    fread(&size7, 4, 1, fptr);
    bigtolittleedit((char*)&size7);
    char buffer15[size7];
    fseek(fptr, 3, SEEK_CUR);
    fread(buffer15, size7-1, 1, fptr);
    buffer15[size7-1]='\0';
    fclose(fptr);
}
void littletobig(char* num)
{
    char* ptr1 = num;
    for(int i = 0; i < 2; i++)
    {
        char temp = *(ptr1+i);
        *(ptr1+i) = *(ptr1+3-i);
        *(ptr1+3-i) = temp;
    }
}
void bigtolittleedit(char* num)
{
    char* ptr1 = num;
    for(int i = 0; i < 2; i++)
    {
        char temp = *(ptr1+i);
        *(ptr1+i) = *(ptr1+3-i);
        *(ptr1+3-i) = temp;
    }
}