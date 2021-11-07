#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>

namespace binary_search_tree {
	template <class T>
	class binary_tree
	{
	public:
		struct binary_tree_iterator
		{
			binary_tree* current_node;

			binary_tree_iterator(binary_tree<T>* _root)
			{
				this->current_node = _root;
			}

			bool operator !=(binary_tree_iterator& _iterator)
			{
				return _iterator.current_node != this->current_node;
			}

			T& operator*() const
			{
				return current_node->t_data;
			}

			binary_tree_iterator& operator++()
			{
				if(current_node->right_node != nullptr)
				{
					current_node = current_node->right_node.get();

					while(current_node->left_node.get() != nullptr)
					{
						current_node = current_node->left_node.get();
					}
				}
				else
				{
					binary_tree<T> *parent = current_node->parent_node;

					while(parent != nullptr && current_node == parent->right_node.get())
					{
						current_node = parent;
						parent = parent->parent_node;
					}
					current_node = parent;
				}
				return *this;
			}
		};

		binary_tree(const T& _data) {
			root_node = this;
			parent_node = nullptr;
			left_node = nullptr;
			right_node = nullptr;
			t_data = _data;
		}

		binary_tree(const T& _data, binary_tree<T>* _parent) {
			root_node = this;
			parent_node = _parent;
			left_node = nullptr;
			right_node = nullptr;
			t_data = _data;
		}

		void insert(const T& _data)
		{
			if(_data <= t_data)
			{
				if(left_node == nullptr)
				{
					left_node = std::make_unique<binary_tree<T>>(_data, this);
				}
				else
				{
					left_node->insert(_data);
				}
			}
			else
			{
				if(right_node == nullptr)
				{
					right_node = std::make_unique<binary_tree<T>>(_data, this);
				}
				else
				{
					right_node->insert(_data);
				}
			}
		}

		T data() const
		{
			return root_node->t_data;
		}

		std::unique_ptr<binary_tree<T>>& left()
		{
			return root_node->left_node;
		}

		std::unique_ptr<binary_tree<T>>& right()
		{
			return root_node->right_node;
		}

		const binary_tree_iterator begin()
		{
			if(this->left_node)
			{
				return this->left_node->begin();
			}
			else
			{
				return binary_tree_iterator(this);
			}
		}

		const binary_tree_iterator end()
		{
			return binary_tree_iterator(nullptr);
		}

	private:
		T t_data;
		binary_tree<T>* root_node;
		binary_tree<T>* parent_node;
		std::unique_ptr<binary_tree<T>> left_node;
		std::unique_ptr<binary_tree<T>> right_node;
	};
}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H
