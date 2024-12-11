#include "main.h"

Motor r1(15, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor r2(6, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor l1(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor l2(1, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor belt(8, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor portable_score(10, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

Controller controller(E_CONTROLLER_MASTER);

void autonomous() {
    belt.move_velocity(100);

    l1.move_velocity(50);
    l2.move_velocity(50);
    r1.move_velocity(-50);
    r2.move_velocity(-50);

    pros::delay(5000);

    l1.move_velocity(0);
    l2.move_velocity(0);
    r1.move_velocity(0);
    r2.move_velocity(0);

    l1.move_velocity(50);
    l2.move_velocity(50);
    r1.move_velocity(50);
    r2.move_velocity(50);

    pros::delay(5000);

    l1.move_velocity(0);
    l2.move_velocity(0);
    r1.move_velocity(0);
    r2.move_velocity(0);
    belt.move_velocity(0);
}

void opcontrol() {
    while (true) {
        if (controller.get_digital(E_CONTROLLER_DIGITAL_LEFT)) {
            l1.move_velocity(100);
            l2.move_velocity(100);
            r1.move_velocity(100);
            r2.move_velocity(100);
        } else {
            l1.move_velocity(controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
            l2.move_velocity(controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
            r1.move_velocity(-controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
            r2.move_velocity(-controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));

            if (controller.get_digital(E_CONTROLLER_DIGITAL_UP)) {
                belt.move_velocity(100);
            } else if (controller.get_digital(E_CONTROLLER_DIGITAL_DOWN)) {
                belt.move_velocity(-100);
            } else {
                belt.move_velocity(0);
            }

            if (controller.get_digital(E_CONTROLLER_DIGITAL_A)) {
                portable_score.move_velocity(100);
            } else if (controller.get_digital(E_CONTROLLER_DIGITAL_B)) {
                portable_score.move_velocity(-100);
            } else {
                portable_score.move_velocity(0);
            }
        }
        pros::delay(10);
    }
