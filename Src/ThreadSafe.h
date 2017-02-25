#pragma once

//Standard includes
#include <mutex>

namespace util
{
	//ThreadSafe<T> - Combines a mutex and its object. Useful so a given thread-safe class wouldn't be riddled with mutices
	template<typename T>
	class ThreadSafe
	{
	public:
		T val;

		//Locks the mutex. Blocks until unlocked. Use tryLock() for a non-blocking function
		void lock();

		//Tries to lock the mutex, returns a bool of whether or not it was successfull
		bool tryLock();

		//Unlocks the mutex
		void unlock();

	private:
		std::mutex valueLock;
	};

	//Locks the mutex. Blocks until unlocked. Use tryLock() for a non-blocking function
	template<typename T>
	inline void ThreadSafe<T>::lock()
	{
		this->valueLock.lock();
	}

	//Tries to lock the mutex, returns a bool of whether or not it was successfull
	template<typename T>
	inline bool ThreadSafe<T>::tryLock()
	{
		return this->valueLock.try_lock();
	}

	//Unlocks the mutex
	template<typename T>
	inline void ThreadSafe<T>::unlock()
	{
		this->valueLock.unlock();
	}


} //util