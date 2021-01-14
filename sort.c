#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN_ATT 16//maximum length of each attribute value=15(+1 for '\0')
/*
//for time measure
#include <time.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")//^
*/


//char priority[63] = { ' ', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm','M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u','U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z' };
int obj_num = 0;
int index = 0;//used as merge sort sub-array's index for order to print out

void OrderMergeSort(char** keyObjects, int order[], int low, int high, int type);
void NewMerge(char** keyObjects, int order[], int low, int mid, int high);

int main(void)
{
	//DWORD dwStartTime = timeGetTime();//^

	FILE* fp_i = NULL;//file pointer for input file
	FILE* fp_o = NULL;//file pointer for output file

	char error_message[] = "NO INPUT\n";

	//file open
	fopen_s(&fp_i, "hw1_input_5.txt", "rt");
	fopen_s(&fp_o, "hw1_result_5.txt", "wt");
	if (fp_i == NULL)
	{

		perror(error_message);
		return 0;
	}//Exception :: No Input file


	//char separator[3] = { '$', ':', '\n' };//part separtor, attribute separator, object(line) separator
	char l_separator = '\n';
	char buf, tmp_buf[2], tmp;
	int digit = 0;
	int digit_num[7];
	obj_num = 0;
	int key_num = 0;
	int att_num = 1, att_len = 0;
	char** key_objects;//actual source to sort
	char** objects;//for output print
	int i = 0, j = 0, k = 0, att_check = 0;
	int* sorted_order;


	/***********************************************************************************************************************/
	//READ INPUT
	//read file by 1 byte, 1 cycle

	//read 1st part : the number of objects(obj_num)
	while (fread(&buf, 1, 1, fp_i))
	{
		if (buf != '\n')
		{
			digit_num[digit] = buf - '0';
			digit++;
		}
		else break;
	}
	for (i = digit - 1; i >= 0; i--)
	{
		obj_num += digit_num[digit - 1 - i] * pow(10, i);
	}

	fread(&tmp_buf, 2, 1, fp_i);//skip '$\n'

	//find where is key(key_num) in the attributes
	//find the number of attributes(att_num)
	while (fread(&buf, 1, 1, fp_i))
	{
		if (buf != '\n')
		{
			if (buf == '(') key_num = att_num - 1;
			else if (buf == ':') att_num++;
		}
		else break;
	}

	fread(&tmp_buf, 2, 1, fp_i);


	//dynamic allocation to arrays
	key_objects = (char**)malloc(sizeof(char*) * obj_num);
	for (i = 0; i < obj_num; i++)
	{
		key_objects[i] = (char*)malloc(sizeof(char) * att_num * MAX_LEN_ATT);
		key_objects[i][MAX_LEN_ATT - 1] = '\0';//null char
	}

	att_len = att_num * MAX_LEN_ATT;
	objects = (char**)malloc(sizeof(char*) * obj_num);
	for (i = 0; i < obj_num; i++)
	{
		objects[i] = (char*)malloc(sizeof(char) * att_len);
		objects[i][att_len - 1] = '\0';
	}


	//store objects in the array
	i = 0;//to count object numbers

	fread(&buf, 1, 1, fp_i);
	while (!feof(fp_i))
	{
		if (buf == '\n')
		{
			if (att_check == key_num)
			{
				key_objects[i][j] = '\0';
				j = 0;
			}

			objects[i][k] = '\0';
			i++;
			k = 0;
			att_check = 0;
		}

		else
		{
			if (buf == ':')
			{
				if (att_check == key_num)
				{
					key_objects[i][j] = '\0';
					j = 0;
				}
				att_check++;
			}

			//copy key attributes
			else if (att_check == key_num)
			{
				//save differently when it's alphabet
				//rearrange
				tmp = buf;
				switch (tmp)
				{
				case 'a':
					tmp -= 32; break;
				case 'A':
					tmp += 1; break;
				case 'b':
					tmp -= 31; break;
				case 'B':
					tmp += 2; break;
				case 'c':
					tmp -= 30; break;
				case 'C':
					tmp += 3; break;
				case 'd':
					tmp -= 29; break;
				case 'D':
					tmp += 4; break;
				case 'e':
					tmp -= 28; break;
				case 'E':
					tmp += 5; break;
				case 'f':
					tmp -= 27; break;
				case 'F':
					tmp += 6; break;
				case 'g':
					tmp -= 26; break;
				case 'G':
					tmp += 7; break;
				case 'h':
					tmp -= 25; break;
				case 'H':
					tmp += 8; break;
				case 'i':
					tmp -= 24; break;
				case 'I':
					tmp += 9; break;
				case 'j':
					tmp -= 23; break;
				case 'J':
					tmp += 10; break;
				case 'k':
					tmp -= 22; break;
				case 'K':
					tmp += 11; break;
				case 'l':
					tmp -= 21; break;
				case 'L':
					tmp += 12; break;
				case 'm':
					tmp -= 20; break;
				case 'M':
					tmp += 13; break;
				case 'n':
					tmp -= 13; break;
				case 'N':
					tmp += 20; break;
				case 'o':
					tmp -= 12; break;
				case 'O':
					tmp += 21; break;
				case 'p':
					tmp -= 11; break;
				case 'P':
					tmp += 22; break;
				case 'q':
					tmp -= 10; break;
				case 'Q':
					tmp += 23; break;
				case 'r':
					tmp -= 9; break;
				case 'R':
					tmp += 24; break;
				case 's':
					tmp -= 8; break;
				case 'S':
					tmp += 25; break;
				case 't':
					tmp -= 7; break;
				case 'T':
					tmp += 26; break;
				case 'u':
					tmp -= 6; break;
				case 'U':
					tmp += 27; break;
				case 'v':
					tmp -= 5; break;
				case 'V':
					tmp += 28; break;
				case 'w':
					tmp -= 4; break;
				case 'W':
					tmp += 29; break;
				case 'x':
					tmp -= 3; break;
				case 'X':
					tmp += 30; break;
				case 'y':
					tmp -= 2; break;
				case 'Y':
					tmp += 31; break;
				case 'z':
					tmp -= 1; break;
				case 'Z':
					tmp += 32; break;
				}
				key_objects[i][j++] = tmp;
			}

			//copy input file to objects' content array
			objects[i][k++] = buf;
		}

		fread(&buf, 1, 1, fp_i);
	}
	objects[i][k] = '\0';
	if (att_check == key_num) key_objects[i][j] = '\0';

	fclose(fp_i);


	//***********************************************************************************************************************
	//SORTING
	//fast and stable
	//sorted array¿Í key_attributes array »ç¿ë

	i = 0;//for order number

	//dynamic allocation of sorted_order array
	sorted_order = (int*)malloc(sizeof(int) * obj_num);
	for (i = 0; i < obj_num; i++) sorted_order[i] = i;

	OrderMergeSort(key_objects, sorted_order, 0, obj_num - 1, 0);


	//***********************************************************************************************************************
	//WRITE OUTPUT
	//write all objects by 1 byte for 1 cycle

	for (k = 0, i = sorted_order[k]; k < obj_num; i = sorted_order[++k])
	{
		j = 0;
		while (objects[i][j] != '\0')
		{
			fwrite(&objects[i][j++], 1, 1, fp_o);
		}
		fwrite(&l_separator, 1, 1, fp_o);
	}


	//***********************************************************************************************************************

	//free
	for (i = 0; i < obj_num; i++) {
		free(key_objects[i]);
		free(objects[i]);
	}
	free(key_objects); free(objects); free(sorted_order);


	//file close
	fclose(fp_o);

	//DWORD dwEndTime = timeGetTime();
	//printf("%d ms\n", dwEndTime - dwStartTime);//^

	return 0;
}


//Sorting alphabetically but just set sorted_order array
//then sorted_order array is used to know the order when printing out the results

void OrderMergeSort(char** keyObjects, int order[], int low, int high, int type)
{
	if (low < high)
	{
		int type = 0;
		int mid = (low + high) / 2;

		if (type == 0) index = 0;//initial state
		else if (type == -1) index = low;//left state
		else if (type == 1) index = mid + 1;//right state

		OrderMergeSort(keyObjects, order, low, mid, -1);
		OrderMergeSort(keyObjects, order, mid + 1, high, 1);
		NewMerge(keyObjects, order, low, mid, high);
	}
}

void NewMerge(char** keyObjects, int order[], int low, int mid, int high)
{
	index = low;
	int left = low;
	int right = mid + 1;
	int* tmp_order = (int*)malloc(sizeof(int) * obj_num);//for using original order until the previous procedures
	for (int i = 0; i < obj_num; i++) tmp_order[i] = order[i];

	int index1, index2;
	index1 = tmp_order[left];
	index2 = tmp_order[right];


	//If left and right is in the range
	while (left <= mid && right <= high)
	{
		//if keyObjects[left] > keyObjects[right]
		//wrong order
		if (strcmp(keyObjects[index1], keyObjects[index2]) > 0)
		{
			order[index] = tmp_order[right];
			right++;
			index++;
			index2 = tmp_order[right];
		}

		//if keyObjects[left] < keyObjects[right]
		//correct order
		else
		{
			order[index] = tmp_order[left];
			left++;
			index++;
			index1 = tmp_order[left];
		}
	}

	//If no more elements in the left half and still elements exist in the right half
	if (left > mid)
	{
		while (right <= high)
		{
			order[index] = tmp_order[right];
			right++;
			index++;
		}
	}

	//If no more elements in the right half and still elements exist in the left half
	else if (right > high)
	{
		while (left <= mid)
		{
			order[index] = tmp_order[left];
			left++;
			index++;
		}
	}

	free(tmp_order);
}