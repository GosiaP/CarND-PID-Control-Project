#include "PID.h"
#include <limits>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID()
  : is_first_update(true)
{
}

PID::~PID() 

{
}

void PID::Init(double Kp, double Ki, double Kd) 
{
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
}

void PID::UpdateError(double cte)
{
  p_error = is_first_update ? cte : p_error;
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;

  is_first_update = false;
}

double PID::TotalError()
{
  return -Kp * p_error - Kd * d_error - Ki * i_error;
}

