#include "vector.h"

int main(int argc, char ** argv)
{
	Vector * my_vect = vect_init();

	vect_delete_at(0, my_vect);

	vect_insert_at(12, 12, my_vect);

	vect_insert_at(0, 3, my_vect);

	vect_insert_at(0, 69, my_vect);

	vect_insert_at(2, 420, my_vect);

	vect_insert_at(4, 6969, my_vect);

	vect_update_at(123, 123, my_vect);

	vect_update_at(2, 765, my_vect);

	vect_at(123123, my_vect);

	vect_at(3, my_vect);

	vect_at(2, my_vect);

	vect_delete_at(1, my_vect);

	vect_delete_at(1, my_vect);

	vect_delete_at(0, my_vect);

	vect_insert_at(0, 3, my_vect);

	vect_fin(my_vect);

	return 0;
}