#include "sll.h"

/*
	! size() - returns the number of data elements in the list
	! empty() - bool returns true if empty
	! value_at(index) - returns the value of the nth item (starting at 0 for first)
	! push_front(value) - adds an item to the front of the list
	! pop_front() - remove the front item and return its value
	! push_back(value) - adds an item at the end
	! pop_back() - removes end item and returns its value
	! front() - get the value of the front item
	! back() - get the value of the end item
	! insert(index, value) - insert value at index, so the current item at that index is pointed to by the new item at the index
	! erase(index) - removes node at given index
	! value_n_from_end(n) - returns the value of the node at the nth position from the end of the list
	! reverse() - reverses the list
*/

//-------------Constructor and deconstructor---------------------
Node * node_init(int element)
{
	Node * temp = (Node*)malloc(sizeof(Node));

	if(!temp)
	{
		//Handle failed allocation
		fprintf(stderr, "Allocation Error");
		exit(EXIT_FAILURE);
	}

	temp->next = NULL;
	temp->data = element;

	return temp;
}

void sll_deinit(Node ** head)
{
	Node * cur = *head;

	while(cur != NULL)
	{
		Node * temp = cur;
		cur = cur->next;
		free(temp);
	}

	*head = NULL;
}

//------size() - returns the number of data elements in the list------
int sll_size(Node * head)
{
	//Store head as a temp variable
	Node * cur = head;

	//Set counter variable to count items in list
	int counter = 0;

	//Lopp until u reach end node
	while(cur != NULL)
	{
		//Update position of ptr
		cur = cur->next;
		
		//Update counter each iteration
		counter += 1;
	}

	//Return size
	return counter;
}

//------empty() - bool returns true if empty-----------
bool sll_empty(Node * head)
{
	//Check if head is empty or not if it is return true else false
	if(head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//------value_at(index) - returns the value of the nth item (starting at 0 for first)
bool sll_at(int index, int * ret, Node * head)
{
    // Set temp cur variable
    Node * cur = head;

    // Set counter variable to track where at in list
    int counter = 0;

    // Continue iterating while you're not at end of list
    // and have not found the index yet
    while(cur != NULL && counter != index)
    {
        cur = cur->next;
        counter += 1;
    }

    // If we exited because we found the correct index
    // Return value, else return false
    if(counter == index && cur != NULL) // Check if cur is not NULL
    {
        *ret = cur->data;
        return true;
    }
    else
    {
        return false;
    }
}

//-----push_front(value) - adds an item to the front of the list-----
void sll_push_front(int element, Node ** head)
{
	//Create a new node for insertion
	Node * new_node = node_init(element);

	//If list is empty place at start
	if (*head == NULL)
	{
		*head = new_node ;
		return;
	}

	//set new node next pointer to the head
	new_node->next = *head;

	//Set head to new node
	*head = new_node;
}

//-----pop_front() - remove the front item and return its value
bool sll_pop_front(int * ret, Node ** head)
{
	//Check if list is empty
	if (*head == NULL)
	{
		return false;
	}

	//Set head into temp variable
	*ret = (*head)->data;

	//Set head to cur varible
	Node * cur = *head;

	//Remove first node by pointing head to its next pointer
	*head = cur->next;

	//Free head we stored in temp
	free(cur);

	return true;
}

//-----push_back(value) - adds an item at the end-----
void sll_push_back(int element, Node ** head)
{
	//Create a new node
	Node * new_node = node_init(element);

	//Check if list is empty
	if (*head == NULL)
	{
		//Place node in when empty
		*head = new_node;
		return;
	}

	//Create a cur and previous pointer compared to head
	Node * cur = *head;
	Node * prev = NULL;

	//Iterate through until at the end opf the list
	while (cur != NULL)
	{
		//Update prev and cur variables as we go though
		prev = cur;
		cur = cur->next;
	}
	//At the end prev should be last Node

	//Set last nodes next to the new_node
	prev->next = new_node;
}

//-----pop_back() - removes end item and returns its value-----
bool sll_pop_back(int * ret, Node ** head)
{
	//Check if list is empty
	if (*head == NULL)
	{
		return false;
	}

	//Set Cur and prev ptrs in relation to head
	Node * cur = *head;
	Node * prev = NULL;

	//Check if only one node in list
	if (cur->next == NULL)
	{
		*ret = (*head)->data;

		//Set head to NULL
		*head = NULL;

		//free the head
		free(*head);

		//return success
		return true;
	}

	//Iterate through list until at end
	while (cur->next != NULL)
	{
		//Update prev and cur
		prev = cur;
		cur = cur->next;
	}
	//At end prev should be 2nd last Node

	//Set return
	*ret = prev->next->data;

	//set 2nd last node next ptr to NULL
	prev->next = NULL;

	//free last node
	free(cur);

	return true;
}

//-----front() - get the value of the front item-----
bool sll_front(int * ret, Node * head)
{
	//Check if list is empty
	if (head == NULL)
	{
		//Return Failure
		return false;
	}

	//Store return value
	*ret = head->data;

	//Return success
	return true;
}

//-----back() - get the value of the end item-----
bool sll_back(int * ret, Node * head)
{
	//Check if list is empty
	if (head == NULL)
	{
		//Return Failure
		return false;
	}

	//Set cur and prev in relation to head
	Node * cur = head;
	Node * prev = NULL;

	//Iterate until end of list
	while(cur != NULL)
	{
		//Update as head is iterated
		prev = cur;
		cur = cur->next;
	}
	//Prev shpuld be last Node

	//Store return value
	*ret = prev->data;

	//Return success
	return true;	
}

//-----insert(index, value) - insert value at index, so the current item at that index is pointed to by the new item at the index
bool sll_insert(int index, int element, Node ** head) 
{
    int counter = 0;
    Node * new_node = node_init(element);

    if (index < 0) 
    {
        return false;
    }

    if (*head == NULL) 
    {
        if (index == 0) 
        {
            *head = new_node;
            return true;
        } else 
        {
            return false;
        }
    }

    Node * cur = *head;
    Node * prev = NULL;

    while (cur != NULL && counter < index) 
    {
        prev = cur;
        cur = cur->next;
        counter++;
    }

    if (counter == index) 
    {
        if (prev != NULL) 
        { // Check if prev is not NULL
            prev->next = new_node;
        } else 
        { // Inserting at the beginning
            new_node->next = *head;
            *head = new_node; // Update head pointer
        }
        new_node->next = cur;
        return true;
    } else 
    {
        return false; // Index out of bounds
    }
}

// Function to remove node at given index
bool sll_erase(int index, Node **head) 
{
    // Create counter variable
    int counter = 0;

    // Set cur and prev pointers in relation to head
    Node *cur = *head;
    Node *prev = NULL;

    // Check if index is out of bounds
    if (index < 0)
    {
        return false;
    }

    // If list is empty
    if (*head == NULL)
    {
        return false;
    }

    // If index is 0 delete from start
    if (index == 0) 
    {
        Node *temp = *head; // Store head in temp
        *head = (*head)->next; // Move head to next node
        free(temp); // Free memory of removed node
        return true;
    }

    // Iterate until end of list or counter equals index
    while (cur != NULL && counter < index) 
    {
        prev = cur;
        cur = cur->next;
        counter++;
    }

    // If counter equals index, node is found
    if (counter == index) 
    {
        // Remove node
        prev->next = cur->next;
        free(cur); // Free memory of removed node
        return true;
    } else 
    {
        // Index out of bounds
        return false;
    }
}

//---print() - prints readable versions of linked list
void sll_print(Node * head)
{
	Node * temp = head;

	while(temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n\n");
}

//-----value_n_from_end(n) - returns the value of the node at the nth position from the end of the list
bool sll_value_n_from_end(int val, int * ret, Node * head)
{
	//Check if list is empty or invalid value
	if (head == NULL || val < 0)
	{
		return false;
	}

	//Get size of list
	int size = sll_size(head);

	//Check to make sure val is correct compared to size
	if(val > size)
	{
		return false;
	}

	//Check if val is 0 to return end
	if (val == 0)
	{
		if(sll_pop_back(ret, &head) == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Check if val is size to return start
	if (val == size)
	{
		if(sll_pop_front(ret, &head) == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Set cur node to head
	Node * cur = head;

	//Update same number as 
	for (int i = 0; i < size - val; i++)
	{
		cur = cur->next;
	}
	//Should be desrired node as cur after

	//Set return value
	*ret = cur->data;

	return true;
}

//-----reverse() - reverses the list-----
void sll_reverse(Node ** head)
{
	Node * cur = *head;
	Node * prev = NULL;

	while (cur != NULL)
	{
		Node * temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
}