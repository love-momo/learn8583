#include <stdio.h>

typedef struct ISO8583 
{ 
     int bit_flag; /*域数据类型0 -- string, 1 -- int, 2 -- binary*/ 
     char *data_name; /*域名*/ 
     int length; /*数据域长度*/ 
     int length_in_byte;/*实际长度（如果是变长）*/ 
     int variable_flag; /*是否变长标志0：否 2：2位变长, 3：3位变长*/ 
     int datatyp; /*0 -- string, 1 -- int, 2 -- binary*/ 
     char *data; /*存放具体值*/ 
     int attribute; /*保留*/ 
} ISO8583;