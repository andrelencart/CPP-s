
#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact {

	public:
	Contact(void);
	~Contact(void);

	void	SetFstName(const std::string &str);
	void	SetLstName(const std::string &str);
	void	SetNkName(const std::string &str);
	void	SetPhNumber(const std::string &str);
	void	SetDkSecret(const std::string &str);
	
	std::string GetFstName(void);
	std::string GetLstName(void);
	std::string GetNkName(void);
	std::string GetPhNumber(void);
	std::string GetDkSecret(void);

	private:
	std::string	f_name;
	std::string	l_name;
	std::string	nk_name;
	std::string	ph_number;
	std::string	dk_secret;

};

#endif