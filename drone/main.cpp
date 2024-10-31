//Dependencies
#include <PID_v1.h>

//#define motors here

//Flight Variables
//SetPoint is the target value, Input is the measured value, Output is what's changed to meet the target
double rollSetpoint, rollInput, rollOutput;
double pitchSetpoint, pitchInput, pitchOutput;
double yawSetpoint, yawInput, yawOutput;		//Yaw may not be needed, remove if unnecessary. All further yaw mentions will be marked as comments for now.

//Define parameters for above variables

double const tuneKp = 1, tuneKi = 0.05, tuneKd = 0.25;	//Define variables for proportional, integral, and derivative tuning parameters

PID rollPID(&rollInput, &rollOutput, &rollSetpoint, tuneKp, tuneKi, tuneKd, P_ON_M, DIRECT);
PID pitchPID(&pitchInput, &pitchOutput, &pitchSetpoint, tuneKp, tuneKi, tuneKd, P_ON_M, DIRECT);
//PID yawPID(&yawInput, &yawOutput, &yawSetpoint, tuneKp, tuneKi, tuneKd, P_ON_M, DIRECT);

//Setup and Loop functions

void setup()
{
	//Variables
	rollInput = 0, rollSetpoint = 0;
	pitchInput = 0, pitchSetpoint = 0;
	//yawInput = 0, yawSetpoint = 0;

	//Turn the PID on
	rollPID.SetMode(AUTOMATIC)
	pitchPID.SetMode(AUTOMATIC)
	//yawPID.SetMode(AUTOMATIC)

	console.log("Completed setup.")
}

void loop()
{
 	rollPID.Compute()
	pitchPID.Compute()
	//yawPID.Compute()
}
