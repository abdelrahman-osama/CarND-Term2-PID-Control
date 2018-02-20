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
