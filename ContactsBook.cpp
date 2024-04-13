#include "ContactsBook.h"

void ContactsBook::add_contact(const Contact& contact)
{
	// Check if the list is full, if it is full call the resize function
	if (full())
	{
		resize_list();
	}
	// If list is not full add the contact to the end of the array
	contacts_list[contacts_count] = contact;
	// Increment the count
	contacts_count++;
}

int ContactsBook::total_contacts() const
{
	// Return the total contacts currently stored
	return contacts_count;
}

bool ContactsBook::full() const
{
	// Return true if list is full, false otherwise
	if(size_of_contacts == contacts_count)
	{
		return true;
	}
	return false;
	
}

void ContactsBook::resize_list()
{
	// Allocate a temporary new array of double the current size
	Contact *temp = new Contact[size_of_contacts * 2];
	for (size_t i = 0; i < size_of_contacts; i++)
	{
		// copy the contacts from previous array to this array one by one get the copy of each contact using copy_contact function of Contact class
		temp[i] = *(contacts_list[i].copy_contact());
	}
	// Delete the previous array
	delete[] contacts_list;
	// Assign the new temporary array to the contacts_list pointer
	contacts_list = temp;
	// Update the this->size_of_contacts with new size
	size_of_contacts *= 2;
}

Contact* ContactsBook::search_contact(std::string first_name, std::string last_name)
{
	// Search the contact in the list according to the given first name and last name
	for (size_t i = 0; i < contacts_count; i++)
	{
		// If found return a copy of the contact using copy func
		if (contacts_list[i].get_first_name() == first_name && contacts_list[i].get_last_name() == last_name)
		{
			return contacts_list[i].copy_contact();
		}
	}
	// If not found return nullptr
	return nullptr;
}

Contact* ContactsBook::search_contact(std::string phone)
{
	// Search the contact in the list according to the given phone number
	for (size_t i = 0; i < contacts_count; i++)
	{
		// If found return a copy of the contact using copy func
		if (contacts_list[i].get_mobile_number() == phone)
		{
			return contacts_list[i].copy_contact();
		}
	}
}

Contact* ContactsBook::search_contact(const Address& address)
{
	// Search the contact in the list according to the given address
	for (size_t i = 0; i < contacts_count; i++)
	{
		// If found return a copy of the contact using copy func
		if (contacts_list[i].get_address()->equals(address))
		{
			return contacts_list[i].copy_contact();
		}
	}
}

ContactsBook::ContactsBook(int size_of_list)
{
	// Initialize the contacts_list array, also initialize the size and count members accordingly
	contacts_list = new Contact[size_of_list];
	size_of_contacts = size_of_list;
	contacts_count = 0;
}

ContactsBook::~ContactsBook()
{
	// Delete the contacts_list array
	delete[] contacts_list;
}

void ContactsBook::print_contacts_sorted(std::string choice)
{
	/*
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/
}

void ContactsBook::sort_contacts_list(Contact *contacts_list, std::string choice)
{
	/*
		You should not duplicate the code to sort based on choices
		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
		Sort by the fist letter of first name or last name as given in choice
	*/
}

void ContactsBook::merge_duplicates() 
{
	// Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal
	// If there are three copies of a Contact, then only one should remain
	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
	// 9 contacts will be left; and the this->contacts_count of list will 9
	// At the end display contacts merged, and count of merged contacts

	// Iterate through the contacts list to look for duplicates
	for (size_t i = 0; i < contacts_count; i++)
	{
		for (size_t j = i + 1; j < contacts_count; j++)
		{
			// If found a duplicate
			if (contacts_list[i].equals(contacts_list[j]))
			{
				// Destroy the duplicate contact 
				contacts_list[j].~Contact();
				// Shift the contacts to fill the gap
				for (size_t k = j; k < contacts_count - 1; k++)
				{
					contacts_list[k] = contacts_list[k + 1];
				}
				// Decrement the count
				contacts_count--;
			}
		}
	}
}


void ContactsBook::load_from_file(std::string file_name) 
{
	/*
	*	Read contacts back from file in the same format	
	*	Read the contacts_count, and run a loop for this contacts_count and read the 
	*	contacts in the same format as you stored
	*	Add them to contact book (this.add_contact function can be used)
	*	Finally, close the file
	*/
}


void ContactsBook::save_to_file(std::string file_name) 
{
	/*
	*	In this function you will store all the contacts to a file
	*	On first line store contacts_count
	*	On next lines store contacts in the following format:
	*       2 lines for each contact
	*       On oneline write contact attributes(except address) in comma separated format. On second line
	*	store address atributes in the same format
	*	first_name,last_name,mobile_number,email_address
	*	house,street,city,country
	*	Close the file
	*/
}
