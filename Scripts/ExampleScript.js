var forceParam = script.addFloatParameter("Force","The Force",0,0,1);


var myVar = 5; //You can add custom vars here that will stay

function reset()
{
	//Here you can reset your custom vars to prepare for a new simulation
	myVar = 5;
}

function processFrame(time,deltaTime,targetPos, curPos, curSpeed, curAccel)
{
	if(time < 1) script.log("Time : "+time);

	//Get the custom parameter
	var force = forceParam.get();

	var targetPos = targetPos; //set pos (white curve)
	var targetSpeed = (targetPos - curPos)*deltaTime;//set speed (red curve)
	var targetAcc = (targetSpeed - curSpeed)*deltaTime;	//set acc (blue curve)
	var targetJerk = (targetAcc - curAcc) * deltaTime; // set jerk (green curve)

	return [targetPos,targetSpeed,targetAcc,targetJerk];
}