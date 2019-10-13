/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
bool validateMonthFormat(char *dob1, char *dob2)
{
	if (((dob1 + 3 && *(dob1 + 3) != '-') && (dob1 + 4 && *(dob1 + 4) != '-')) && ((dob2 + 3 && *(dob2 + 3) != '-') && (dob2 + 4 && *(dob2 + 4) != '-')))
	{
		if ((dob1 + 5 && *(dob1 + 5) == '-') && (dob2 + 5 && *(dob2 + 5) == '-'))
		{
			return true;
		}
		else return false;
	}
	else return false;
}
bool validateDateFormat(char *dob1, char *dob2)
{
	if ((dob1&& dob1 + 1) && (dob2 && dob2 + 1))
	{
		if ((*dob1 != '-' && *(dob1 + 1) != '-') && (*dob2 != '-' && *(dob2 + 1) != '-'))
		{
			if ((dob1 + 2 && *(dob1 + 2) == '-') && (dob2 + 2 && *(dob2 + 2) == '-'))
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else return false;
}

bool validateYearFormat(char *dob1, char *dob2)
{
	if (((dob1 + 6 && *(dob1 + 6) != '-') && (dob1 + 7 && *(dob1 + 7) != '-')) && ((dob2 + 6 && *(dob2 + 6) != '-') && (dob2 + 7 && *(dob2 + 7) != '-')) && ((dob1 + 8 && *(dob1 + 8) != '-') && (dob1 + 9 && *(dob1 + 9) != '-')) && ((dob2 + 8 && *(dob2 + 8) != '-') && (dob2 + 9 && *(dob2 + 9) != '-')))
	{
		return true;
	}
	else return false;
}
 
void getDateMonthYear(char *dob1, char *dob2,int *y1, int *y2, int *d1, int *d2, int *m1, int *m2)
{
	*d1 = ((*dob1 - 48) * 10) + (*(dob1 + 1) - 48);
	*d2 = ((*dob2 - 48) * 10) + (*(dob2 + 1) - 48);

	*m1 = (((*(dob1 + 3) - 48) * 10) + (*(dob1 + 4) - 48));
	*m2 = (((*(dob2 + 3) - 48) * 10) + (*(dob2 + 4) - 48));

	*y1 = (((((((*(dob1 + 6) - 48) * 10) + (*(dob1 + 7) - 48)) * 10) + (*(dob1 + 8) - 48)) * 10) + *(dob1 + 9) - 48);
	*y2 = (((((((*(dob2 + 6) - 48) * 10) + (*(dob2 + 7) - 48)) * 10) + (*(dob2 + 8) - 48)) * 10) + *(dob2 + 9) - 48);
}

bool checkForFebruaryDates(int y1, int y2, int d1, int d2, int m1, int m2)
{
	if ((d1 > 31 || d2 > 31) || (m1 > 12 || m2 > 12))
		return false;
	if (m1 == 2)
	{
		if (y1 % 400 == 0 || (y1 % 100 != 0 && y1 % 4 == 0))
		{
			if (d1 > 29)
				return false;
		}
		else if ((y1 % 4 != 0) && d1>28)
			return false;
	}
	if (m2 == 2)
	{
		if (y2 % 400 == 0 || (y2 % 100 != 0 && y2 % 4 == 0))
		{
			if (d2 > 29)
				return false;
		}
		else if ((y2 % 4 != 0) && d2>28)
			return false;
	}
}

int isOlder(char *dob1, char *dob2)
{
	int year1, year2, date1, date2, month1, month2;
	if (validateDateFormat(dob1, dob2) && validateMonthFormat(dob1, dob2) && validateYearFormat(dob1, dob2))
	{
		getDateMonthYear(dob1, dob2, &year1, &year2, &date1, &date2, &month1, &month2);
		if (checkForFebruaryDates(year1, year2, date1, date2, month1, month2))
		{
			if (year1 > year2)
			{
				return 2;
			}
			else if (year2 > year1)
			{
				return 1;
			}
			else
			{
				if (month1 > month2)
				{
					return 2;
				}
				else if (month2 > month1)
				{
					return 1;
				}
				else
				{
					if (date1 > date2)
					{
						return 2;
					}
					else if (date2 > date1)
					{
						return 1;
					}
					else return 0;
				}
			}
		}
	}
		return -1;
}