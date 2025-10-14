
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contacts.hpp"
// #include <vector>
#include <sstream>

class PhoneBook {

	public:
	PhoneBook(void);
	~PhoneBook(void);
	
	void	AddContact(void);
	void	SearchContact(void);
	void	Exit(void);
	void	PrintContactInfo(int i);
	
	private:
	Contact contact[8];
	int	contact_index;
	int	max_index;
};

#endif
