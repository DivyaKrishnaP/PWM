#ifndef PWM_DEMO_H_
#define PWM_DEMO_H_


//#define PWM0_DEV	"/sys/class/backlight/pwm-backlight/brightness"	
//By default the PWM-A was als0routed to LCD backlight.1

#define PWM1_DEV_T20	"/sys/class/leds/PWM\<B\>/brightness"
#define PWM2_DEV_T20	"/sys/class/leds/PWM\<C\>/brightness"
#define PWM3_DEV_T20	"/sys/class/leds/PWM\<D\>/brightness"
#define PWM0_DEV_T20	"/sys/class/backlight/pwm-backlight/brightness"	

//By default the PWM-A was als c 0routed to LCD backlight.
#define PWM1_DEV_T30	"/sys/class/leds/PWM\<B\>/brightness"
#define PWM2_DEV_T30	"/sys/class/leds/PWM\<C\>/brightness"
#define PWM3_DEV_T30	"/sys/class/leds/PWM\<D\>/brightness"
#define PWM0_DEV_T30	"/sys/class/backlight/pwm-backlight/brightness"
#define COLIBRI_T20	0
#define COLIBRI_T30	1

#define DUTY_CYCLE	1
#define EXIT		2

int setPWM(int pwm_channel, int duty_cycle, int mod_flag)
{
    char *pwm_dev;
    int fileDescriptor = 0;
    char buffer[10] = {0};

	if(pwm_channel >= 4 || pwm_channel < 0) { printf("Invalid PWM Channel\n"); return -1; }
	switch(pwm_channel)
	{
		case 0:
					if(mod_flag == COLIBRI_T20)
					pwm_dev = PWM0_DEV_T20;
					else if(mod_flag == COLIBRI_T30)
					pwm_dev = PWM0_DEV_T30;
		break;

		case 1:
					if(mod_flag == COLIBRI_T20)
					pwm_dev = PWM1_DEV_T20;
					else if(mod_flag == COLIBRI_T30)
					pwm_dev = PWM1_DEV_T30;
		break;

		case 2:
					if(mod_flag == COLIBRI_T20)
					pwm_dev = PWM2_DEV_T20;
					else if(mod_flag == COLIBRI_T30)
					pwm_dev = PWM2_DEV_T30;
		break;

		case 3:
					if(mod_flag == COLIBRI_T20)
					pwm_dev = PWM3_DEV_T20;
					else if(mod_flag == COLIBRI_T30)
					pwm_dev = PWM3_DEV_T30;
		break;

	}

	printf("Duty cycle is %d and pwm channel is %d\n", duty_cycle, pwm_channel);

	if(duty_cycle > 255 || duty_cycle < 1) { printf("Invalid value for duty cycle\n"); return -1;}

    fileDescriptor = open(pwm_dev, O_WRONLY);
    if(fileDescriptor < 0)
    {
    	perror("device open failed");
    	return -1;
    }
    sprintf(buffer, "%d", duty_cycle);
    if(write(fileDescriptor, buffer, strlen(buffer)) < 0)
    {

    	perror("write failed");
    	return -1;
    }

    printf("Period and prescale are hardcoded in driver, the frequency obtained at PWMA is 1kHz and remaining 3 PWM channels at 12kHz\n");
    close(fileDescriptor);
    return 0;
}


char *proc_info(char *detail)
{

	FILE *f = fopen ("/proc/cpuinfo", "r");

	char *a = malloc (256);
	char *b = malloc (128);
	char *c = malloc (128);

	while (!feof (f))
	{
		fgets (a, 512, f);

		if (strlen (a) == 1) continue;

		sscanf (a, "%[^\t:] : %[^\t\n]", b, c);

		if(strstr(b, detail))
		{
			return c;
		}
	}

	fclose (f);
	free(a);
	free(b);
	free(c);
	return "Unknown module";
}


#endif /* PWM_DEMO_H_ */
