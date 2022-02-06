#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "ListNode.h"

namespace data_structures
{
	template <class T>
	class LinkedList final
	{
	public:
		LinkedList() = default;
		LinkedList(const LinkedList& copy);
		LinkedList(LinkedList&& copy) noexcept;
		~LinkedList();

		LinkedList& operator=(const LinkedList& rhs);
		LinkedList& operator=(LinkedList&& rhs) noexcept;

		explicit operator bool() const;

		void Append(const T& data);
		void Prepend(const T& data);
		void RemoveLast();
		void RemoveFirst();
		void Extract(const T& data);
		void InsertAfter(const T& data, const T& after);
		void InsertBefore(const T& data, const T& before);
		void Clear() noexcept;
		T& Last();
		T Last() const;
		T& First();
		T First() const;
		ListNode<T>* Head() const noexcept;
		ListNode<T>* Tail() const noexcept;
		bool Empty() const noexcept;
		size_t Size() const noexcept;

		T ListElement(int index);

		bool operator==(const LinkedList<T>& rhs) const noexcept;


	private:
		ListNode<T>* m_head = nullptr;
		ListNode<T>* m_tail = nullptr;
		size_t m_count = 0;
	};


	template <class T>
	LinkedList<T>::~LinkedList()
	{
		auto traverse = m_head;

		while (traverse != nullptr)
		{
			auto temp = traverse->Next();
			delete traverse;
			traverse = temp;
		}
		m_head = nullptr;
		m_tail = nullptr;
	}

	template <class T>
	LinkedList<T>::LinkedList(const LinkedList& copy)
	{
		*this = copy;
	}

	template <class T>
	LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs)
	{
		if (this != &rhs)
		{

			Clear();
			auto traverse = rhs.Head();
			for (traverse; traverse != nullptr; traverse = traverse->Next())
			{
				Append(traverse->Value());
			}

		}
		return *this;
	}

	template <class T>
	LinkedList<T>::LinkedList(LinkedList&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	LinkedList<T>& LinkedList<T>::operator=(LinkedList&& rhs) noexcept
	{
		if (this != &rhs)
		{
			Clear();
			m_count = rhs.m_count;
			m_head = rhs.m_head;
			m_tail = rhs.m_tail;

			rhs.m_head = nullptr;
			rhs.m_tail = nullptr;
		}
		return *this;
	}

	template <class T>
	LinkedList<T>::operator bool() const
	{
		return !Empty();
	}

	template <class T>
	void LinkedList<T>::Append(const T& data)
	{
		auto new_node = new ListNode<T>(data, nullptr, m_tail);
		if (m_head == nullptr)
		{
			m_head = new_node;
		}
		else
		{
			m_tail->Next(new_node);
		}
		m_tail = new_node;
		m_count++;
	}

	template <class T>
	void LinkedList<T>::Prepend(const T& data)
	{
		auto new_node = new ListNode<T>(data, m_head, nullptr);
		if (m_head == nullptr)
		{
			m_tail = new_node;
		}
		else
		{
			m_head->Previous(new_node);
		}
		m_head = new_node;
		m_count++;
	}

	template <class T>
	void LinkedList<T>::RemoveLast()
	{
		auto temp = m_tail;
		m_tail = m_tail->Previous();
		delete temp;
		m_tail->Next(nullptr);
		m_count--;
	}

	template <class T>
	void LinkedList<T>::RemoveFirst()
	{
		auto temp = m_head;
		m_head = m_head->Next();
		delete temp;
		m_count--;
	}

	template <class T>
	void LinkedList<T>::Extract(const T& data) //test
	{
		for (auto travel = m_head; travel != nullptr; travel = travel->Next()) {
			if (travel->Value() == data)
			{
				if (travel == m_head)
				{
					auto temp = m_head->Next();
					delete m_head;
					m_head = temp;
					m_count--;
					return;
				}
				if (travel == m_tail)
				{
					auto temp = m_tail->Previous();
					delete m_tail;
					m_tail = temp;
					m_count--;
					return;
				}
				auto temp = travel->Previous();
				temp->Next(travel->Next());
				delete travel;
				m_count--;
				return;
			}
		}
	}

	template <class T>
	void LinkedList<T>::InsertAfter(const T& data, const T& after)
	{
		auto current = m_head;
		while (current != nullptr) {
			if (current->Value() == after)
			{
				auto new_node = new ListNode<T>(data, current->Next(), current);
				current->Next(new_node);
				current->Next()->Previous(new_node);
				m_count++;
				break;
			}
			current = current->Next();
		}
	}

	template <class T>
	void LinkedList<T>::InsertBefore(const T& data, const T& before)
	{
		auto current = m_head;


		while (current != nullptr) {
			if (current->Value() == before)
			{
				auto new_node = new ListNode<T>(data, current, current->Previous());
				current->Previous()->Next(new_node);
				current->Previous(new_node);
				m_count++;
				break;
			}
			current = current->Next();
		}
	}

	template <class T>
	void LinkedList<T>::Clear() noexcept
	{
		while (m_head != nullptr)
		{
			auto temp = m_head;
			m_head = m_head->Next();
			delete temp;
		}
		m_count = 0;
	}

	template <class T>
	T& LinkedList<T>::Last()
	{
		return m_tail->Value();
	}

	template <class T>
	T LinkedList<T>::Last() const
	{
		return m_tail->Value();
	}

	template <class T>
	T& LinkedList<T>::First()
	{
		return m_head->Value();
	}

	template <class T>
	T LinkedList<T>::First() const
	{
		return m_head->Value();
	}

	template <class T>
	ListNode<T>* LinkedList<T>::Head() const noexcept
	{
		return m_head;
	}

	template <class T>
	ListNode<T>* LinkedList<T>::Tail() const noexcept
	{
		return m_tail;
	}

	template <class T>
	bool LinkedList<T>::Empty() const noexcept
	{
		return m_count == 0;
	}

	template <class T>
	size_t LinkedList<T>::Size() const noexcept
	{
		return m_count;
	}

	template <class T>
	bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const noexcept
	{
		auto travel = m_head;
		auto rhs_travel = rhs.m_head;
		if (m_count != rhs.m_count)
		{
			return false;
		}
		while (travel != nullptr || rhs_travel != nullptr)
		{
			if (travel->Value() != rhs_travel->Value() || m_count != rhs.m_count)
			{
				return false;
			}
			travel = travel->Next();
			rhs_travel = rhs_travel->Next();
		}
		return true;
	}

	template <class T>
	T LinkedList<T>::ListElement(int index)
	{
		auto current = m_head;
		int count = 0;

		while (current != nullptr) {
			if (count == index)
				return current->Value();
			count++;
			current = current->Next();
		}
		return 0;
	}
}
#endif