#include "../src/door/motor-stepper.h"
#include <gtest/gtest.h>
#include <unistd.h>
#include <string>

class MotorStepperTest : public ::testing::Test {
protected:
    MotorStepper* motorstepper;
    Motor* motor;

    void SetUp() override {
        motorstepper = new MotorStepper("/dev/gpiochip0", 26, 17, "2000000", "1000000");
        motor = motorstepper;
    }

    void TearDown() override {
        delete motorstepper;
    }
};

TEST_F(MotorStepperTest, MotorMovesForward) {
    motor->forward();
    EXPECT_EQ(motor->get_direction(), Motor::Direction::FORWARD);
    sleep(2);
}

TEST_F(MotorStepperTest, MotorMovesBackward) {
    motor->backward();
    EXPECT_EQ(motor->get_direction(), Motor::Direction::BACKWARD);
    sleep(2);
}

TEST_F(MotorStepperTest, MotorStops) {
    motor->stop();
    EXPECT_EQ(motor->get_direction(), Motor::Direction::IDLE);
    sleep(2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}