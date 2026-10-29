#include<stdio.h>
#include<string.h>
#include "view.h"
#include "edit.h"
int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("INVALID ARGUMENTS\nUSAGE:\nTo view, pass: ./a.out -v mp3filename\nTo edit, pass: ./a.out -e -t/-a/-A/-m/-y/-c updated_text mp3filename\nTo get help,  pass: ./a.out --help\n");
        return -1;
    }
    else
    {
        if(strcmp(argv[1],"--help")==0)
        {
            printf("Help\n> to view mp3 file contents: ./a.out -v mp3filename\n> to edit mp3 file contents: ./a.out -e -t/-a/-A/-m/-y/-c updated_text mp3filename\n2.1. -t -> to edit song title\n2.2. -a -> to edit artist name\n2.3. -A -> to edit album name\n2.4. -y -> to edit year\n2.5. -m -> to edit content\n2.6. -c -> to edit comment\n");
        }
        else if(strcmp(argv[1],"-v")==0)
        {
            if(argv[2]!=NULL)
            {
                if(strlen(argv[2])>4&&(strcmp((argv[2]+strlen(argv[2])-4),".mp3")==0||strcmp((argv[2]+strlen(argv[2])-5),".mpeg")==0))
                {
                   // printf("Good file name, ready to view\n");
                    mp3_view(argv[2]);
                }
                else
                {
                    printf("Please enter a valid file name\n");
                    return -1;
                }
            }
            else
            {
                printf("Please enter the file to view, refer help menu\n");
                return -1;
            }
        }
        else if(strcmp(argv[1],"-e")==0)
        {
            if(argc!=5)
            {
                printf("Invalid arguments\nPlease refer help menu\n");
            }
            else
            {
                if(argv[4]!=NULL)
                {
                    if(strlen(argv[4])>4&&strcmp((argv[4]+strlen(argv[4])-4),".mp3")==0)
                    {
                        //printf("Good file name, ready to edit\n");
                        if(strcmp(argv[2],"-t")==0)
                        {    
                            mp3_edit("TIT2",argv[3],argv[4]);
                        }
                        else if(strcmp(argv[2],"-a")==0)
                        {    
                            mp3_edit("TPE1",argv[3],argv[4]);
                        }
                        else if(strcmp(argv[2],"-A")==0)
                        {    
                            mp3_edit("TALB",argv[3],argv[4]);
                        }
                        else if(strcmp(argv[2],"-y")==0)
                        {    
                            mp3_edit("TYER",argv[3],argv[4]);
                        }
                        else if(strcmp(argv[2],"-m")==0)
                        {    
                            mp3_edit("TCON",argv[3],argv[4]);
                        }
                        else if(strcmp(argv[2],"-c")==0)
                        {    
                            mp3_edit("TCOM",argv[3],argv[4]);
                        }
                        else
                        {
                            printf("Invalid tag\nPlease refer help menu\n");
                            return -1;
                        }
                    }
                    else
                    {
                        printf("Please enter a valid file name\n");
                        return -1;
                    }
                }
            }
        }
    }
}