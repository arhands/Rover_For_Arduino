/*
 Name:		Rover.ino
 Created:	11/7/2017 9:35:57 PM
 Author:	Boys64Bit
*/
float WheelRadius = 0.5;//in inches
float QuarterTurnLength;//for the wheel
float QuarterRotateStepCount;// for rotating the cart clockwise and counter clockwise

void setup() {
	QuarterTurnLength = PI*WheelRadius / 2;
	
}

float Traveling = 0;
int RWPinS = 0, LWPinS = 4;//starting pins for each wheel (total amount required is 4 per wheel)
void loop() {
	if (Traveling > 0)
	{

	}
}
enum StepDirection
{
	Foward = 0,
	Backward,
	RotateClockwise,
	RotateCounterClockwise,
};
void Step(StepDirection dir)
{
	switch (dir) {
		case Foward: {
			MoveWheel(Right, Foward);
			MoveWheel(Left, Foward);
			break;
		}
		case Backward: {
			MoveWheel(Right, Backward);
			MoveWheel(Left, Backward);
			break;
		}
		case RotateClockwise: {
			MoveWheel(Right, Backward);
			MoveWheel(Left, Foward);
			break;
		}
		case RotateCounterClockwise:
		{
			MoveWheel(Right, Foward);
			MoveWheel(Left, Backward);
			break;
		}
	}
}

enum Wheel
{
	Right = 0,
	Left,
};
byte ActiveRight = 0, ActiveLeft = 0;
void MoveWheel(Wheel wheel, signed char increment) {
	switch (wheel)
	{
		case Right:
		{
			pinMode(ActiveRight, LOW);
			ActiveRight += increment;
			if (ActiveRight > RWPinS + 4)
				ActiveRight = RWPinS;
			else if (ActiveRight < RWPinS)
				ActiveRight = RWPinS + 4;
			pinMode(ActiveRight, HIGH);
			break;
		}
		case Left:
		{
			pinMode(ActiveLeft, LOW);
			ActiveLeft += increment;
			if (ActiveLeft > RWPinS + 4)
				ActiveLeft = RWPinS;
			else if (ActiveLeft < RWPinS)
				ActiveLeft = RWPinS + 4;
			pinMode(ActiveLeft, HIGH);
			break;
		}
		default:
			break;
	}
}
