#ifndef LIST_H
#define LIST_H

#include <assert.h>
namespace Engine {
	template<typename T>
	class List
	{
	public:
		struct Node {
			T data;
			Node* next;
			Node* prev;

			Node() :prev(nullptr), next(nullptr) {}
			Node(T _data, Node* _next = nullptr, Node* _prev = nullptr) : data(_data), next(_next), prev(_prev) {

			}

			~Node() {}
		};

		class iterator {
		private:
			Node* cur;

			friend class List; // so that List can access cur

		public:
			iterator(Node* _cur) : cur(_cur) {}

			iterator& operator++(int) {
				assert(cur != nullptr);
				cur = cur->next;
				return *this;
			}

			iterator& operator--(int) {
				assert(cur != nullptr);
				cur = cur->prev;
				return *this;
			}

			bool operator!=(const iterator& value)
			{
				return cur != value.cur;
			}

			Node* operator->() {
				return cur;
			}
		};

		typedef bool Pred(const T&);

	private:
		Node* head;
		Node* tail;

		unsigned int _size;

	public:
		List() :_size(0) {
			head = new Node();
			tail = new Node();

			head->next = tail;
			tail->prev = head;
		}
		~List() {
			clear();
			delete head;
			delete tail;
		}

		unsigned int size() const { return _size; }

		iterator begin() const {
			return iterator(head->next);
		}

		iterator end() const {
			return iterator(tail);
		}

		// insert before
		iterator insert_before(iterator pos, const T& value)
		{
			Node* p = pos.cur;

			Node* node = new Node(value, p, p->prev);
			p->prev->next = node;
			p->prev = node;
			_size++;
			return iterator(node);
		}

		void push_back(const T& value)
		{
			insert_before(end(), value);
		}

		void push_back(T&& value)
		{
			insert_before(end(), value);
		}

		iterator remove(iterator pos)
		{
			Node* p = pos.cur;

			iterator ret(p->next);
			p->prev->next = p->next;
			p->next->prev = p->prev;

			delete p;
			_size--;
			return ret;
		}

		void remove(const T& value)
		{
			for (auto it = begin(); it != end(); )
			{
				if (it->data() == value)
					it = remove(it);
				else
					it++;
			}
		}

		void remove(Pred _pred)
		{
			for (auto it = begin(); it != end(); )
			{
				if (_pred(it->data))
					it = remove(it);
				else
					it++;
			}
		}

		bool empty() const {
			return _size == 0;
		}

		void clear() {
			for (auto it = begin(); it != end(); )
				it = remove(it);
		}
	};
}

#endif // LIST_H