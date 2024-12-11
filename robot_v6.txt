
from vex import *

brain = Brain()
r1 = Motor(Ports.PORT15, GearSetting.RATIO_18_1, True)
r2 = Motor(Ports.PORT6, GearSetting.RATIO_18_1, True)
l1 = Motor(Ports.PORT2, GearSetting.RATIO_18_1, False)
l2 = Motor(Ports.PORT1, GearSetting.RATIO_18_1, False)
belt = Motor(Ports.PORT8, GearSetting.RATIO_18_1, False)
portable_score = Motor(Ports.PORT10, GearSetting.RATIO_18_1, False)

controller = Controller()

def autonomous():
    belt.spin(FORWARD)

    l1.set_velocity(50, PERCENT)
    l2.set_velocity(50, PERCENT)
    r1.set_velocity(-50, PERCENT)
    r2.set_velocity(-50, PERCENT)

    l1.spin(FORWARD)
    l2.spin(FORWARD)
    r1.spin(FORWARD)
    r2.spin(FORWARD)

    wait(5, SECONDS)

    l1.stop()
    l2.stop()
    r1.stop()
    r2.stop()

    l1.set_velocity(50, PERCENT)
    l2.set_velocity(50, PERCENT)
    r1.set_velocity(50, PERCENT)
    r2.set_velocity(50, PERCENT)

    l1.spin(FORWARD)
    l2.spin(FORWARD)
    r1.spin(FORWARD)
    r2.spin(FORWARD)

    wait(5, SECONDS)

    l1.stop()
    l2.stop()
    r1.stop()
    r2.stop()
    belt.stop()

autonomous()

while True:
    if controller.buttonBack.pressing():
        l1.set_velocity(100, PERCENT)
        l2.set_velocity(100, PERCENT)
        r1.set_velocity(100, PERCENT)
        r2.set_velocity(100, PERCENT)

        l1.spin(FORWARD)
        l2.spin(FORWARD)
        r1.spin(FORWARD)
        r2.spin(FORWARD)
    else:
        l1.set_velocity(controller.axis3.position(), PERCENT) 
        l2.set_velocity(controller.axis3.position(), PERCENT) 
        r1.set_velocity(-controller.axis2.position(), PERCENT)  
        r2.set_velocity(-controller.axis2.position(), PERCENT)

        l1.spin(FORWARD)
        l2.spin(FORWARD)
        r1.spin(FORWARD)
        r2.spin(FORWARD)

        if controller.buttonUp.pressing(): 
            belt.spin(FORWARD)
        elif controller.buttonDown.pressing(): 
            belt.spin(REVERSE)
        else:
            belt.stop()
        
        if controller.buttonA.pressing(): 
            portable_score.spin(FORWARD)
        elif controller.buttonB.pressing(): 
            portable_score.spin(REVERSE)
        else:
            portable_score.stop()

    wait(10, MSEC)
