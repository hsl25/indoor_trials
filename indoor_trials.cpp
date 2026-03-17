// I am going to be using the Raspberry Pi Pico to program the motor drivers
// I need to use PWM to control the motor speed
// I also need to control the direction in which the motors spin
// I can possible implement a form of PID to ensure the motors are spinning at the right speed
// Important links:
// Raspberry Pi Pico datasheet: https://pip-assets.raspberrypi.com/categories/610-raspberry-pi-pico/documents/RP-008307-DS-1-pico-datasheet.pdf?disposition=inline
// RP2040 datasheet: https://pip-assets.raspberrypi.com/categories/814-rp2040/documents/RP-008371-DS-1-rp2040-datasheet.pdf?disposition=inline
// PWM - pages 522 to 535 on RP2040 datasheet
// There is example code on page 524, but I will explore it only if necessary. I will try and produce my own code.  
// A useful Pico simulator: https://wokwi.com/pi-pico 

// Motor diagram:
//   --------- FRONT ---------
//  |                        |
//  |                        |
//  O== Motor 1    Motor 3 ==O 
//  |                        |
//  |                        |
//  O== Motor 2    Motor 4 ==O 
//  |                        |  
//  |                        |
//  O== Motor 5    Motor 6 ==O
//  |                        |
//  |                        |
//   ---------- BACK ---------
//
//   <--- LEFT     RIGHT --->
//

#include <pico/stdlib.h>
#include <pico/time.h>
#include <hardware/pwm.h>

// #include <time.h> - not needed anymore 
#include <stdint.h>

#include "driving.hpp"

Drive drive;

int main () {
    // Initialise PWM Mode, slices, clk divider
    drive.init_pwm_mode();
    drive.init_clk_divider();

    // Initialise PWM and setup motors
    drive.setup_motors();
    
    // This code is test code to ensure the new motor PWM I calcuted is correct
    // I don't want to apply PWM to a motor without being sure it is safe and correct
    float new_pwm = drive.calc_pwm(OLD_WHEEL_DIAMETER, NEW_WHEEL_DIAMETER);
    printf("Calculated new PWM duty cycle: %f\n", new_pwm);

    // Drive forward for 5 seconds (so 5000ms)
    // drive.drive_forward();
    // sleep_ms(STRAIGHT_LINE_TIME);

    // float speed_ratio = calc_speed_ratio(TURN_RADIUS, TRACK_WIDTH);

    // turn_left(speed_ratio);
    // sleep_ms(TURN_TIME);

    // Steer left for 3 seconds (so 3000ms)
    // drive.skid_left();
    // sleep_ms(SKID_STEERING_TIME);

    // drive.brake();

    return 0;
}

