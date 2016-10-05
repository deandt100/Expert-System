#pragma once
# include <string>

using namespace std;

class Rule
{
	private:
		string	expr;
		string	conc;

	public:
		void		setExpr(string expr){ this->expr = expr; }
		void		setConc(string conc){ this->conc = conc; }
		string		getExpr(){ return (expr); }
		string		getConc(){ return (conc); }

		//Construct
		Rule(string, string);

};