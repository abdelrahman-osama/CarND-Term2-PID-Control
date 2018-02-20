#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd)
{

	/*
  * Errors
  */
	p_error = 0;
	i_error = 0;
	d_error = 0;

	first_time = true;
	/*
  * Coefficients
  */
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
}

// The effect of the paramters on the car

// The P parameter controls how much the car will steer in proportional to the cross-track error.
// which is the distance from the center of the lane to help the car stay in the center.
// increasing it too much made the car osscilate while decreasing it too much made the car react
// slowly at sharp turns.

// The D parameter controls how much of the difference between the current and the previous cte
// will we consider when deciding the steering angle. Increasing it helped the car converge
// smoothly to the center of the lane and decreased the osscilation a bit, however increasing it
// made the opposite effect and increased the osscilation.

// The I parameter controls how much of the summation of the previous ctes to consider.
// which means if the car was off the center for a while in a certain side the summation
// would be a considerable value, usually this happens due to a drift in the car wheels.
// Taking this summation into considration will help us lead the car back to the center of the lane.
// however if the I paramter was high in comparison to the drift in the wheels, it will lead to
// more osscilation.

// Everything worked as expected which helped in tuning the paramters

// How the paramters were chosen

// Parameters were tuned manually. I first started with the values sebastian used in the lesson
// and tried decreasing or increasing from there.

void PID::UpdateError(double cte)
{
	if (first_time)
	{
		p_error = cte;
		first_time = false;
	}
	else
	{
		d_error = cte - p_error;
		i_error += cte;
		p_error = cte;
	}
}

double PID::TotalError()
{
	return -(Kp * p_error) - (Kd * d_error) - (Ki * i_error);
}
