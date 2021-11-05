#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include <vector>
#include <stdexcept>
#include <string>

namespace circular_buffer {
	template <class T>
	class circular_buffer
	{
	public:
		circular_buffer(int _size)
		{
			maxSize = _size;
		};

		T read()
		{
			if(buff.empty())
			{
				throw std::domain_error("Buffer is empty");
			}
			else
			{
				T data = buff.front();
				buff.erase(buff.begin());
				buff.shrink_to_fit();
				actualSize--;
				return data;
			}
		};

		void write(T _data)
		{
			if(maxSize > actualSize)
			{
				actualSize++;
				buff.push_back(_data);
			}
			else
			{
				throw std::domain_error("Buffer is full");
			}
		};

		void overwrite(T _data)
		{
			if(maxSize > actualSize)
			{
				write(_data);
			}
			else
			{
				std::vector<T> tmp;

				for(std::size_t i = 1; i < buff.size(); i++)
				{
					tmp.push_back(buff[i]);
				}

				actualSize--;
				buff = tmp;
				write(_data);
			}
		};

		void clear()
		{
			actualSize = 0;
			buff = std::vector<T>();
		};

	private:
		std::size_t maxSize;
		std::size_t currIndex = 0;
		std::size_t actualSize = 0;
		std::vector<T> buff;
	};
}  // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H
