// C Program to check 
// Test cases for signup page 
#include "test.h" 
#include <stdbool.h> 
#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 

char temp_name[100], temp_password1[100]; 
char temp_password2[100], temp_email[100]; 
char temp_mobile[100]; 
int temp_age; 

struct det { 
	char uname[50]; 
	int age; 
	char password[100]; 
	char email[100]; 
	char mobile[10]; 
}; 
int count, success, j; 
struct det s[100]; 
UNIT_TEST(Signup_TEST) 
{ 
	printf("\n\n"); 
	printf("\n\tEnter Your name : "); 
	scanf("%s", temp_name); 
	printf("\tEnter Your Email : "); 
	scanf("%s", temp_email); 
	printf("\tEnter Password : "); 
	scanf("%s", temp_password1); 
	printf("\tConfirm Password : "); 
	scanf("%s", temp_password2); 
	printf("\tEnter Your Mobile Number : "); 
	scanf("%s", temp_mobile); 
	printf("\tEnter Your Age : "); 
	scanf("%d", &temp_age); 
	int i = 0, flag = 1; 
	int check = 0; 
	do { 
		if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')//checking whether name contains any numbers 
			|| (temp_name[i] >= 'A'
				&& temp_name[i] <= 'Z'))) { 
			flag = 0; 
			break; 
		} 
		i = i + 1; 
	} while (temp_name[i] != '\0'); 
	if (flag == 1) { 
		check++; 
		printf("Test for name		 : "); 
		test_assert(true); 
	} 
	else { 

		printf("Test for name		 : "); 
		test_assert(false); 
	} 

	do { 
		if (temp_email[i] == '@' || temp_email[i] == '.') {//checking email contains @ and . or not 
			count++; 
		} 
		i = i + 1; 
	} while (temp_email[i] != '\0'); 
	if (count >= 2 && strlen(temp_email) >= 5) { 
		check++; 
		printf("Test for email		 : "); 
		test_assert(true); 
	} 
	else { 

		printf("Test for email		 : "); 
		test_assert(false); 
	} 

	if (!strcmp(temp_password1, temp_password2)) {//checking password and confirmpassword is same 
		check++; 
		printf("Test for password match : "); 
		test_assert(true); 
	} 
	else { 

		printf("Test for password match : "); 
		test_assert(false); 
	} 

	if (strlen(temp_password1) >= 8 
		&& strlen(temp_password1) <= 12) {// password must be greater than or equal to 8 and less than or equal to 12 
		check++; 
		printf("Test for password length : "); 
		test_assert(true); 
	} 
	else { 

		printf("Test for password length : "); 
		test_assert(false); 
	} 
	if (strlen(temp_password1) >= 8 
		&& strlen(temp_password1) <= 12) { 
		int caps = 0; 
		int Small = 0; 
		int numbers = 0; 
		int special = 0; 
		i = 0; 
		do { 
			if (temp_password1[i] >= 'A'//password must be contain capital letter 
				&& temp_password1[i] <= 'Z') { 
				caps = caps + 1; 
			} 
			else if (temp_password1[i] >= 'a'//password must be contain small letter 
					&& temp_password1[i] <= 'z') { 
				Small = Small + 1; 
			} 
			else if (temp_password1[i] >= '0'//password must be contain numbers 
					&& temp_password1[i] <= '9') { 
				numbers = numbers + 1; 
			} 
			else if (temp_password1[i] == '@'//password must be contain special character 
					|| temp_password1[i] == '&'
					|| temp_password1[i] == '#'
					|| temp_password1[i] == '*') { 
				special = special + 1; 
			} 
			i = i + 1; 
		} while (temp_password1[i] != '\0'); 
		if (caps >= 1 && Small >= 1 && numbers >= 1 
			&& special >= 1) { 
			check++; 
			printf("Test for password strength : "); 
			test_assert(true); 
		} 
		else { 

			printf("Test for password strength : "); 
			test_assert(false); 
		} 
	} 

	if (temp_age > 0) {//age must be greater than 0 
		check++; 
		printf("Test for age		 : "); 
		test_assert(true); 
	} 
	else { 

		printf("Test for age		 : "); 
		test_assert(false); 
	} 
	if (strlen(temp_mobile) == 10) {//contact number should be exact 10 digits 
		do { 
			if (temp_mobile[i] >= '0'
				&& temp_mobile[i] <= '9') { 
				success = 1; 
			} 
			else { 
				break; 
			} 
			i = i + 1; 
		} while (i < 10); 
		if (success = 1) { 
			check++; 
			printf("Test for mobile number	 : "); 
			test_assert(true); 
		} 
		else { 

			printf("Test for mobile number	 : "); 
			test_assert(false); 
		} 
	} 
	else { 

		printf("Test for mobile number	 : "); 
		test_assert(false); 
	} 
	i = 0; 

	do { 
		if (!(strcmp(temp_email, s[i].email) 
			&& strcmp(temp_password1, s[i].password))) { 
			printf("\n\n\tAccount Already Existed. Please "
				"Login !!\n\n"); 
			flag = 0; 
			break; 
		} 
		i = i + 1; 
	} while (i < 100); 
	if (check == 7) { 
		strcpy(s[j].uname, temp_name); 
		s[j].age = temp_age; 
		strcpy(s[j].password, temp_password1); 
		strcpy(s[j].email, temp_email); 
		strcpy(s[j].mobile, temp_mobile); 
		j++; 
		printf("All test case		 : "); 
		test_assert(true); 
		printf("\n\n\tAccount Successfully Created!!\n\n"); 
	} 
	else { 
		printf("\n\n\tOop something is wrong !!\n\n"); 
	} 
	printf("\n\n"); 
}
