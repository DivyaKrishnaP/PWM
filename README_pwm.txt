PWM_demo is an application through which desired duty cycle can be set to a PWM channel and generate PWM. 

 
Hardware setup:
Connect oscilloscope to PWM channel (PWM_A, PWM_B, PWM_C, PWM_D) signal.

Compiling the application:
In the application directory, run make command preceding machine(module) name.
e.g: MACHINE=colibri-t20 make
Copy the exe to the module either through ethernet and USB.
Ethernet:
scp pwm_demo root@10.18.0.162:/home/root
USB:
cp pwm_demo /media/USB

Run the application:
./pwm_demo

Output:
Output shows to generate PWM, select the PWM channel and give the dutycycle range and can see the pWM output in oscilloscope.
