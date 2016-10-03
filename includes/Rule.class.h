#pragma once
# include <string>

using namespace std;

class Rule
{
	private:
		string	expr;
		string	conc;
		bool	used;

	public:
		void		setExpr(string expr){ this->expr = expr; }
		void		setConc(string conc){ this->conc = conc; }
		void		setUsed(bool state){ this->used = state; }
		string		getExpr(){ return (expr); }
		string		getConc(){ return (conc); }
		bool		getUsed(){ return (used); }

		//Construct
		Rule(string, string);

};