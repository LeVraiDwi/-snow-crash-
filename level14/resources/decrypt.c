#include <stdio.h>
#include <string.h> 

char* ft_des(char* arg1)
{
    char* result = strdup(arg1);
    int var_1c = 0;
    char* var_20 = NULL;
    
    while (1)
    {
        int i = 0xffffffff;
        char* result_1 = result;
        
        while (i)
        {
            int cond = 0 != *result_1;
            result_1 = &result_1[1];
            i -= 1;
            
            if (!cond)
                break;
        }
        
        if (~i - 1 <= (long int)var_20)
            break;
        
        if (var_1c == 6)
            var_1c = 0;
        char *tmp = "0123456";
        if ((long int)var_20 & 1)
        {
            for (int i_1 = 0; tmp[var_1c] > i_1; i_1 += 1)
            {
                char* eax_4 = (long int)var_20 + (long int)result;
                *eax_4 += 1;
                
                if (*(char *)((long int)var_20 + (long int)result) == 0x7f)
                    *(char *)((long int)var_20 + (long int)result) = 0x20;
            }
        }
        else if (!((int)var_20 & 1))
        {
            for (int i_2 = 0; tmp[var_1c] > i_2; i_2 += 1)
            {
                char* eax_17 = (long int)var_20 + (long int)result;
                *eax_17 -= 1;
                
                if (*(char *)((long int)var_20 + (long int)result) == 0x1f)
                    *(char *)((long int)var_20 + (long int)result) = 0x7e;
            }
        }
        
        var_20 += 1;
        var_1c += 1;
    }
    
    return result;
}

void main() {
    printf("%s\n", ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|"));
    return;
}