#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "pwm_demo.h"

int main(void)
{
    char *detail = "Hardware";
    char *module_name;
    int firstChoice = 0, mod_flag = -1;

    int pwm_channel = 0;
    int duty_cycle = 0;

    module_name = proc_info(detail);

    if(strstr(module_name, "Colibri T20"))
    {
    	printf("%s detected\n", module_name);
    	mod_flag = 0;
    }
    else if(strstr(module_name, "Colibri T30"))
    {
    	printf("%s detected\n", module_name);
    	mod_flag = 1;
    }
    else if(strstr(module_name, "Colibri VF50"))
    {
    	printf("%s detected\n", module_name);
    }
    else if(strstr(module_name, "Colibri VF61"))
    {
    	printf("%s detected\n", module_name);
    }
    else if(strstr(module_name, "Apalis T30"))
    {
    	printf("%s detected\n", module_name);
    }
    else
    {
    	printf("unknown module\n");
    	return -1;
    }

    while(1)
    {
        printf("\n*****************************************\n");
        printf("\t  Toradex PWM Demo\n");
        printf("*****************************************\n");
        printf("[1] Generate PWM\n[2] Exit\n");
        printf("Enter your choice:");
        scanf("%d", &firstChoice);

        if ((firstChoice > 2))
        {
            printf("Please enter your choice between 1-2.. Press Enter to exit\n");
            getchar();
            return -1;
        }

        switch (firstChoice)
        {
            case DUTY_CYCLE:
            	printf("Select the PWM Channel (0-3): ");
            	scanf("%d", &pwm_channel);
            	printf("Enter the duty cycle (1-255), [127]->50 percent duty cycle, [255]-> 100 percent duty cycle: ");
            	scanf("%d", &duty_cycle);

            	setPWM(pwm_channel, duty_cycle, mod_flag);

                break;

            case EXIT:
            			return 0;
                break;
        }
    }
    return 0;
}
