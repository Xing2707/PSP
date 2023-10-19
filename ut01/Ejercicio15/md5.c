#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

#define MD5_LEN 16
#define CHAR_ST 97
#define CHAR_EN 122
#define STR_LEN 5
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3

void generateMD5(const char *string, unsigned char *str_result) {
    EVP_MD_CTX *ctx;
    const EVP_MD *md;
    unsigned char result[EVP_MAX_MD_SIZE];

    ctx = EVP_MD_CTX_new();
    md = EVP_md5();

    EVP_DigestInit_ex(ctx, md, NULL);
    EVP_DigestUpdate(ctx, string, strlen(string));
    EVP_DigestFinal_ex(ctx, result, NULL);

    EVP_MD_CTX_free(ctx);

    for(int i = 0; i < MD5_LEN; i++){   // MD5 result is always 16 bytes
        sprintf(str_result+(i*2),"%02x", result[i]);
    }
}

int main(int argc, char *argv[]){

    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int result_len;
    
    char *hasts[] = {"582fc884d6299814fbd4f12c1f9ae70f","74437fabd7c8e8fd178ae89acbe446f2","28ea19352381b8659df830dd6d5c90a3","90f077d7759d0d4d21e6867727d4b2bd"};
    int length = sizeof(hasts) / sizeof(hasts[ZERO]);
    char mystring[STR_LEN];

    for (int i = CHAR_ST; i < CHAR_EN; i++)
    {
        mystring[ZERO] = i;
        for (int j = CHAR_ST; j <= CHAR_EN; j++)
        {
            mystring[ONE] = j;
            for (int y = CHAR_ST; y <= CHAR_EN; y++)
            {
                mystring[TWO] = y;
                for (int e = CHAR_ST; e <= CHAR_EN; e++)
                {
                    mystring[THREE] = e;
                    generateMD5(mystring,result);

                    for(int f = 0; f <length; f++){
                        if(strcmp(hasts[f],result) == ZERO){
                            printf("%s es: %s\n",hasts[f],mystring);
                        }
                    }
                }
            }
        }
    }

    return 0;
}