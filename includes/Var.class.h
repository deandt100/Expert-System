#pragma once

class Var
{
	private:
		bool	state;
		bool	isFinal;
		char	name;
	public:
		void	setState(bool state){ this->state = state; }
		void	setFinal(bool isFinal){ this->isFinal = isFinal; }
		bool	getState(){ return (state); }
		bool	getFinal(){ return (isFinal); }
		char	getName(){ return (name); }

	//Construct
	Var(bool, char);
};