class Rule
{
	private:
		char	*expr;
		char	*conc;
		bool	used;

	public:
		void		setExpr(char *expr){ this->expr = expr; }
		void		setConc(char *conc){ this->conc = conc; }
		void		setUsed(bool state){ this->used = state; }
		char		*getExpr(){ return (expr); }
		char		*getConc(){ return (conc); }
		bool		getUsed(){ return (used); }

		//Construct
		Rule(char *, char *);

};