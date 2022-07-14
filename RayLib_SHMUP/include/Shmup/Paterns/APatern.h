#pragma once

class AMovable;
/// <summary>
/// An util class that contains methods to move a movable.
/// </summary>
class APatern
{
	public:
		/// <summary>
		/// Datas to pass to the patern.<br/>
		/// Overriden by the child classes.
		/// </summary>
		struct IPaternData {};

	/// <summary>
	/// Init the patern.
	/// </summary>
	virtual void SetDefault(IPaternData* data) = 0;
	/// <summary>
	/// Execute the patern.
	/// </summary>
	/// <param name="movable">An object to move</param>
	/// <param name="data">The datas of the patern</param>
	virtual void DoPatern(AMovable* movable, IPaternData* data) = 0;
};

