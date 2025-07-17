#include <stdio.h>

void _assembly_bubble_sort(int *data_list, int countof_list){
	int i, j, tmp, C, B;

	/* - - - - - - - - - - - *
	 * Bubble sort           *
	 * Assembly code version *
	 * - - - - - - - - - - - */

	j = -1;

	for(C = countof_list - 1; C > 0; C--){

		j++;
		i = j;

		for(B = C; B > 0; B--){

			i++;

			if(data_list[j] > data_list[i]){

				// Exchange
				tmp = data_list[i];
				data_list[i] = data_list[j];
				data_list[j] = tmp;
			}
		}
	}
}

void _standard_bubble_sort(int *data_list, int countof_list){
	int i, j, tmp;
	
	/* - - - - - - - - - -*
	 * Simple Bubble Sort *
	 * - - - - - - - - - -*/
	
	for(i = 1; i < countof_list; i++){
		for(j = 0; j < countof_list - i; j++){

			// If the next element is bigger than current element,
			// switch them

			if(data_list[j] > data_list[j + 1]){
				tmp = data_list[j];
				data_list[j] = data_list[j + 1];
				data_list[j + 1] = tmp;
			}
		}
	}
}

void _merge_sort(int *data_list, int countof_list){
	int i, u, l, upper_count, lower_count;
	int upper_list[256];
	int lower_list[256];
	
	/* - - - - - -*
	 * Merge Sort *
	 * - - - - - -*/
	
	upper_count = countof_list / 2;
	lower_count = countof_list - upper_count;
	
	// Coppy upper half
	
	for(i = 0; i < upper_count; i++){
		upper_list[i] = data_list[i];
	}
	
	// Copy lower half
	
	for(i = 0; i < lower_count; i++){
		lower_list[i] = data_list[i + upper_count];
	}
	
	// If the element count is more than 2
	// execute recursion

	if(upper_count > 1){
		_merge_sort(upper_list, upper_count);
	}
	
	if(lower_count > 1){
		_merge_sort(lower_list, lower_count);
	}
	
	// Sort
	
	for(i = u = l = 0; i < countof_list; i++){
		
		if(u == upper_count){
			for(;l < lower_count; l++){
				data_list[i] = lower_list[l];
				i++;
			}
			
			break;
		}
		
		if(l == lower_count){
			for(;u < upper_count; u++){
				data_list[i] = upper_list[u];
				i++;
			}
			
			break;
		}
		
		if(upper_list[u] < lower_list[l]){
			data_list[i] = upper_list[u];
			u++;
		}else{
			data_list[i] = lower_list[l];
			l++;
		}
	}
}

// Just for show results
	
void _show_Result(int *data_list, int countof_list){
	int i;
	
	for(i = 0; i < countof_list; i++){
		printf("%d", countof_list[i])
	}

	printf("\n");
}
		
void main(void){
	int i, len;
	int data_listBas[5] = {9, 6, 13, -5, 4};
	int data_listBst[5] = {9, 6, 13, -5, 4};
	int data_listM[5] = {9, 6, 13, -5, 4};

	/* - - - - - - - -*
	 * TEST FUNCTIONS *
	 * - - - - - - - -*/
	
	// Array length
	
	len = sizeof(data_listBas) / 4;
	
	/* - - - - - - *
	 * Bubble sort *
	 * - - - - - - */

	// From the Assembly code

	_assembly_bubble_sort(data_listBas, len);
	_show_Result(data_listBas, len);
	
	// Standard

	_standard_bubble_sort(data_listBst, len);
	_show_Result(data_listBst, len);

	/* - - - - - -*
	 * Merge sort *
	 * - - - - - -*/

	_merge_sort(data_listM, len);
	_show_Result(data_listM, len);
}