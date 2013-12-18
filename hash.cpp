#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

template <typename K, typename V>
struct hash_node{
	K key;
	V value;
	hash_node * next;
	hash_node(K k, V v, hash_node * n){
		key=k;
		value=v;
		next=n;
	}
};

template <typename K, typename V>
class Hash_table{
	vector <hash_node<K, V> *> T;
	int m; //size of the hash table, kept constant
	int n; //no. of hashed keys in the table
	double load_factor;
	int hash_function(K key);
	
	void rehash(){
		vector <hash_node<K, V> *> temp;
		temp=T;
		T.resize(m, NULL);
		n=0;
		for(int i=0;i<temp.size();++i){
			hash_node<K, V> * t;
			t=temp[i];
			while(t!=NULL){
				hash_insert(t->key, t->value);
				t=t->next;
			}
		}
	}
	
	public:
		Hash_table(int capacity=3, double load_factor=0.75){
			this->load_factor=load_factor;
			m=capacity;
			n=0;
			T.resize(m, NULL);
		}
		int get_table_size(){
			return m;
		}
		void hash_insert(K key, V value){
			if((double)((n+1)/m)>load_factor){
				m=2*m;
				rehash();
			}
			hash_node<K, V> *new_node=new hash_node<K, V>(key, value, NULL);
			int slot = hash_function(key);
			new_node->next=T[slot];
			T[slot]=new_node;
			n++;
			//cout<<capacity<<endl;
		}
		V hash_search(K key);
};

template <>
int Hash_table<int, string>::hash_function(int key){
	return key%m;
}

template <>
string Hash_table<int, string>::hash_search(int key){
	int slot=hash_function(key);
	hash_node <int, string> * tmp;
	tmp=T[slot];
	while(tmp!=NULL){
		if(tmp->key==key)
			return tmp->value;
		tmp=tmp->next;
	}
	return "Not found";
}

int main(){
	Hash_table<int, string> h;
	for(int i=1;i<=5;++i){
		string s; int key;
		cin>>key>>s;
		h.hash_insert(key, s);
		cout<<h.get_table_size()<<endl;
	}
	cout<<h.hash_search(5)<<endl;
	return 0;
}

