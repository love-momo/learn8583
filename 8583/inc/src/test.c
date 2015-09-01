#include <stdio.h>
#include <stdlib.h>
#include "8583.h"


char *strtrimr(char *pstr)
{
    int i;
    i = strlen(pstr) - 1;

     while (isspace(pstr[i]) && (i >= 0))
        pstr[i--] = '\0';
 
    return pstr;
 }
 
 
char *strtriml(char *pstr)
{
   int i = 0,j;
   j = strlen(pstr) - 1;

   while (isspace(pstr[i]) && (i <= j)) 
    i++;
    
    if (0<i)
    strcpy(pstr, &pstr[i]);
    
    return pstr;
}
 



char *strtrim(char *pstr) 
{
    char *p;
    p = strtrimr(pstr);
    return strtriml(p);
}



int main()
{
    FILE *fp;
    char lineCfg[1024];
    char tmplineCfg[1024];
    char *tmpline;
    ISO8583 tmp;

    memset(lineCfg, 0x00, sizeof(lineCfg));
    memset(tmplineCfg, 0x00, sizeof(tmplineCfg));

    /*检查配置文件map.cfg是否存在*/
    if((fp=fopen("map.cfg","rb"))==NULL) {
        printf("位图配置文件不存在,程序退出\n");
        exit -1;
    }

    while(fgets(lineCfg, 1023, fp)) {
    /*去#注释、去空格、去空行*/        
        if(strchr(lineCfg, '#')) {
            continue;
        }
    /*strncpy(tmplineCfg, lineCfg, sizeof(lineCfg));*/
    tmpline = strtrim(lineCfg);
    
    puts(tmpline);
    }


    return 0;
}