#include <expert.h>

class Var
{
	private:
		bool	state;
		bool	isFinal;

	public:
		void	setState(bool state){ this->state = state; }
		void	setFinal(bool isFinal){ this->isFinal = isFinal; }
		bool	getState(){ return (state); }
		bool	getFinal(){ return (state); }
};