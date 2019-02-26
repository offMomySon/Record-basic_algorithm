#include <string>
#include <vector>
#include<iostream>


#define HASH_MAP_SIZE 200007

using namespace std;

typedef struct __list {
	struct __node *cur;
	struct __node *head;
	struct __node *tail;
} linkedList;

typedef struct __node * Nodeptr;
typedef struct __node {
	int data;
	Nodeptr  next;
} node;



void createNode(linkedList *L, int tdata) {
	node *newNode = (node *)malloc(sizeof(node));
	
	newNode->data = tdata;
	newNode->next = NULL;
	if (L->head == NULL && L->tail == NULL)
		L->head = L->tail = newNode;
	else {
		L->tail->next = newNode;
		L->tail = newNode;
	}
	node *nNode = (node *)malloc(sizeof(node));
	nNode->
	nNode->data = tdata;
	newNode->next = NULL;
}


int hash_map[HASH_MAP_SIZE];
int hash_map_count[HASH_MAP_SIZE];




void init_hash_table(void)
{
	for (register int i = 0; i < HASH_MAP_SIZE; i++)
	{
		hash_map[i] = -1;
	}
}


int get_hashkey(string str)
{
	int  hash = 5381;

	for(register int i = 0; i< str.size(); i++)
		hash = (((hash << 5) + hash) + str[i] ) % HASH_MAP_SIZE;


	return hash;
}

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	init_hash_table();

	for ( register int i = 0; i < participant.size(); i++)
	{
		int hash_key = get_hashkey(participant[i]);
		
		while (true)
		{
			if (hash_map[hash_key] == -1)
			{
				hash_map[hash_key] = i;
				hash_map_count[hash_key] ++;
				break;
			}
			
			hash_key = (hash_key+1) % HASH_MAP_SIZE;
		}
	}

	for (register int i = 0; i < completion.size(); i++)
	{
		int hash_key = get_hashkey(completion[i]);
		
		while (true)
		{
			if (hash_map[hash_key] != -1 && 
				hash_map_count[hash_key] >0 &&
				participant[hash_map[hash_key]].compare(completion[i]) ==0 )
			{
				hash_map_count[hash_key]--;
				break;
			}
			hash_key = (hash_key + 1) % HASH_MAP_SIZE;
		}
	}

	for (register int i = 0; i < HASH_MAP_SIZE; i++)
	{
		if (hash_map_count[i] > 0)
		{
			answer = participant[hash_map[i]];
			break;
		}
	}

	return answer;
}

int main(void)
{
	vector<string> p = { "leo", "kiki", "eden" };
	vector<string> c = { "eden","kiki" };
	string result = solution(p, c);

	cout << result;

}
