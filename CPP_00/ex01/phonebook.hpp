
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contacts.hpp"

class PhoneBook {

	public:
	PhoneBook(void);
	~PhoneBook(void);
	int	contact_index;
	int	max_index;

	void	AddContact(void);
	void	SearchContact(void);
	void	Exit(void);
	void	PrintList();
	void	PrintContactInfo();

	private:
	Contact contact[8];
};

#endif