#include <iostream>
#include <string>

class String
{
private:
	char* m_string;
	int m_size;

public:
	String()
		: m_size(0), m_string(NULL) {}

	String(const char* str)
		: m_size(strlen(str)), m_string(new char[m_size + 1]) 
	{
		strcpy_s(m_string, m_size + 1, str);
	}

	String(const String& str)
		: m_size(strlen(str.m_string)), m_string(new char[m_size + 1]) 
	{
		strcpy_s(m_string, str.m_size + 1, str.m_string);
	}

	const char& operator[](const int index) const
	{
		return m_string[index];
	}
	
	friend bool operator==(const String& s1, const String& s2);
	friend bool operator!=(const String& s1, const String& s2);
	friend bool operator>(const String& s1, const String s2);
	friend bool operator<(const String& s1, const String s2);
	friend std::istream& operator>>(std::istream& is, const String s1);
	friend std::ostream& operator<<(std::ostream& os, const String s1);

	void operator+(const String& s1)
	{
		int t_size = this->m_size;
		
		char* t_string = new char[this->m_size];

		for (int i = 0; i < this->m_size; i++)
		{
			t_string[i] = this->m_string[i];
		}

		delete[] this->m_string;

		this->m_size += s1.m_size;

		this->m_string = new char[this->m_size];

		for (int i = 0; i < t_size; i++)
		{
			this->m_string[i] = s1.m_string[i];
		}

		for (int i = s1.m_size; i < this->m_size; i++)
		{
			this->m_string[i] = s1.m_string[i - s1.m_size];
		}
	}


	int findStr(const char* str) // доробити логіку
	{
		int str_length = strlen(str);
		int index_element = 0;
		int index = 0;
		int index_str = 0;

		for (int i = 0; i < this->m_size; i++)
		{
			if (this->m_string[i] == str[index_str])
			{
				index++;
				index_str++;
				index_element = i;
			}
			else
			{
				if (index == str_length)
				{
					break;
				}
				else
				{
					index = 0;
					index_str = 0;
					index_element = 0;
				}
			}
		}

		return index_element;
	}

	void replaceStr(const char* str, const char* replace_str)
	{

	}

	void withdrawal(const char* str)
	{

	}

	void insertStr(const char* element, int insert_index)
	{

	}
};

bool operator==(const String& s1, const String& s2)
{
	if (s1.m_size != s2.m_size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < s1.m_size; i++)
		{
			if (s1[i] == s2[i])
			{
				continue;
			}
			else
			{
				return false;
			}
		}

		return true;
	}
}

bool operator!=(const String& s1, const String& s2)
{
	if (s1.m_size != s2.m_size)
	{
		return true;
	}
	else
	{
		for (int i = 0; i < s1.m_size; i++)
		{
			if (s1[i] != s2[i])
			{
				return true;
			}
		}

		return false;
	}
}

bool operator>(const String& s1, const String s2)
{
	int size;
	s1.m_size < s2.m_size ? size = s1.m_size : size = s2.m_size;

	for (int i = 0; i < size; i++)
	{
		if (s1[i] > s2[i])
		{
			return true;
		}
	}
	if (s1.m_size > s2.m_size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<(const String& s1, const String s2)
{
	int size;
	s1.m_size < s2.m_size ? size = s1.m_size : size = s2.m_size;

	for (int i = 0; i < size; i++)
	{
		if (s1[i] < s2[i])
		{
			return true;
		}
	}
	if (s1.m_size < s2.m_size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::istream& operator>>(std::istream& is, const String s1)
{
	return is;
}

std::ostream& operator<<(std::ostream& os, const String s1)
{
	os << s1.m_string;
	return os;
}

int main()
{
	String s1("John");
	String s2("Johns");
	s1 + s2;
	std::cout << s1 << '\n';

	return 0;
}