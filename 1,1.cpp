#include <iostream>
#include <string>

void CheckDateStrToInt(std::string _date) 
{
	int day = 0;
	int month = 0;
	int year = 0;
	int size = _date.size(); // size of the date

	if (_date[2] != '.' || _date[5] != '.' || size != 10)
	{
		throw std::exception("Invalid format(1)!");
	}
	for (size_t i = 0; i < size; i++)
	{
		if ((_date[i] >= 0 && _date[i] <= '9') || _date[i] == '.')
		{

		}
		else throw std::exception("Invalid format!(2)");
	}

	day = ((int)_date[0] - 48) * 10  + ((int)_date[1] - 48);
	month = ((int)_date[3] - 48) * 10 + ((int)_date[4] - 48);
	year = ((int)_date[6] - 48) * 1000 + ((int)_date[7] - 48) * 100 + ((int)_date[8] - 48) * 10 + ((int)_date[9] - 48);
	if (month > 12)
		throw std::exception("Invalid month!");
	if (day > 31)
		throw std::exception("Invalid day!");
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw std::exception("Invalid day at this month!");
	if (((month == 2) && day > 28 && year%4!=0) || ((month == 2) && day > 29 && year % 4 == 0))
		throw std::exception("Invalid day at this month!");
		
	//std::cout<< day<<"."<<month<<"."<<year<<std::endl; just print to see whats happened 
}

int StrToDay(std::string _date)
{
	int day;
	day = ((int)_date[0] - 48) * 10 + ((int)_date[1] - 48);
	return day;
}

int StrToMonth(std::string _date)
{
	int month;
	month = ((int)_date[3] - 48) * 10 + ((int)_date[4] - 48);
	return month;
}

int StrToYear(std::string _date)
{
	int year;
	year = ((int)_date[6] - 48) * 1000 + ((int)_date[7] - 48) * 100 + ((int)_date[8] - 48) * 10 + ((int)_date[9] - 48);
	return year;
}

void decToHexa(std::string _date)
{
	//CheckDateStrToInt(_date);
	int day = StrToDay(_date);
	int month = StrToMonth(_date);
	int year = StrToYear(_date);

	
	// char array to store hexadecimal number
	char hexaDeciNum[100];

	// counter for hexadecimal number array
	int i = 0;
	
	while (day != 0) {
		// temporary variable to store remainder
		int temp = 0;

		// storing remainder in temp variable.
		temp = day % 16;

		// check if temp < 10
		if (temp < 10) {
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else {
			hexaDeciNum[i] = temp + 55;
			i++;
		}

		day = day / 16;
	}
	hexaDeciNum[i] = '.';
	i++;

	while (month != 0) {
		// temporary variable to store remainder
		int temp = 0;

		// storing remainder in temp variable.
		temp = month % 16;

		// check if temp < 10
		if (temp < 10) {
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else {
			hexaDeciNum[i] = temp + 55;
			i++;
		}

		month = month / 16;
	}
	hexaDeciNum[i] = '.';
	i++;
	
	while (year != 0) 
	{
		// temporary variable to store remainder
		int temp = 0;

		// storing remainder in temp variable.
		temp = year % 16;

		// check if temp < 10
		if (temp < 10) {
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else {
			hexaDeciNum[i] = temp + 55;
			i++;
		}

		year = year / 16;
		
	}
	// printing hexadecimal number array in reverse order
	std::cout << "Format (yyyy.mm.dd)!" << std::endl;
	for (int j = i - 1; j >= 0; j--)
		std::cout << hexaDeciNum[j];
	std::cout<<std::endl;



}


int main()
{
	try 
	{
		
		std::string date;
		std::cout << "Enter the date in format 'dd.mm.yyyy' !" << std::endl;
		std::cin >> date;
		//CheckDateStrToInt(date);
		decToHexa(date);
		
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}


